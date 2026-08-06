from __future__ import annotations

import copy
import sys
import threading
import time
import types
import unittest

try:
    import flask  # noqa: F401
except ModuleNotFoundError:
    fake_flask = types.ModuleType("flask")
    fake_flask.abort = lambda *args, **kwargs: None
    fake_flask.jsonify = lambda value=None, **kwargs: value if value is not None else kwargs
    sys.modules["flask"] = fake_flask

from fleet_control.sequential_cell_scenario import SequentialCellScenarioEngine


OPERATOR_STEPS = [
    {
        "id": "confirm_source_pickup",
        "target": "operator",
        "command": "operator_confirm",
        "label": "Confirm item attached",
        "prompt": "Attach the item and clear the source area.",
    },
    {
        "id": "confirm_handover_release",
        "target": "operator",
        "command": "operator_confirm",
        "label": "Confirm item released",
        "prompt": "Release the item and clear the hook.",
    },
    {
        "id": "confirm_human_unload",
        "target": "operator",
        "command": "operator_confirm",
        "label": "Confirm item removed",
        "prompt": "Remove the item and clear the robot path.",
    },
]


class FakeController:
    def __init__(self) -> None:
        self.lock = threading.RLock()
        self.active_scenario = None
        self.events = []
        self.dispatch_calls = 0

    def _add_event(self, level, source, message, *, code="", details=None) -> None:
        self.events.append(
            {
                "level": level,
                "source": source,
                "message": message,
                "code": code,
                "details": dict(details or {}),
            }
        )

    def _dispatch_waypoint(self, waypoint, *, source, scenario_id):
        self.dispatch_calls += 1
        return {
            "order_id": f"order-{waypoint}",
            "nodes": [{"sequenceId": 0}, {"sequenceId": 2}],
        }


def waiting_scenario(mode: str, step_index: int = 0):
    controller = FakeController()
    engine = SequentialCellScenarioEngine(controller)
    steps = engine.normalize_steps({"steps": OPERATOR_STEPS})
    active = {
        "id": "sequential_pickup_delivery",
        "run_id": f"run-{step_index}",
        "label": "Sequential pickup and warehouse delivery",
        "target": "sequential_cell",
        "steps": steps,
        "status": "RUNNING",
        "state_revision": 0,
        "completed_steps": step_index,
        "step_runs": [None for _ in steps],
        "active_step_id": None,
        "active_target": None,
        "active_kind": None,
        "active_order_id": None,
        "active_action_id": None,
        "active_final_node_sequence_id": 0,
        "operator_prompt": None,
        "operator_confirmation_mode": mode,
        "operator_confirmation_timeout_s": 5.0,
        "confirmations": [],
        "step_history": [],
        "active_step_started_at": None,
        "active_step_started_epoch": None,
        "active_step_started_monotonic": None,
        "active_timeout_s": None,
        "stop_requested": False,
        "cancel_sent": False,
    }
    engine._dispatch_step(active, steps[step_index])
    controller.active_scenario = copy.deepcopy(active)
    return controller, engine, copy.deepcopy(active)


class SequentialConfirmationTests(unittest.TestCase):
    def test_manual_is_default_and_does_not_advance_on_elapsed_time(self) -> None:
        selected, settings = SequentialCellScenarioEngine.resolve_confirmation_mode(
            {"operator_confirmation": {"timeout_s": 5}},
            None,
        )
        self.assertEqual("manual", selected)
        self.assertEqual(5.0, settings["timeout_s"])

        controller, engine, snapshot = waiting_scenario("manual")
        snapshot["active_step_started_epoch"] = time.time() - 60.0
        controller.active_scenario = copy.deepcopy(snapshot)
        engine.advance(snapshot)
        self.assertEqual("WAITING_OPERATOR", controller.active_scenario["status"])
        self.assertEqual(0, controller.active_scenario["completed_steps"])
        self.assertEqual([], controller.active_scenario["confirmations"])

    def test_each_gate_gets_a_fresh_five_second_timeout(self) -> None:
        for step_index, expected_step in enumerate(OPERATOR_STEPS):
            with self.subTest(step=expected_step["id"]):
                controller, engine, snapshot = waiting_scenario("timeout", step_index)
                deadline = snapshot["operator_prompt"]["auto_confirm_deadline_epoch"]
                self.assertGreaterEqual(deadline - time.time(), 4.8)
                self.assertLessEqual(deadline - time.time(), 5.1)

                engine.advance(snapshot)
                self.assertEqual(
                    "WAITING_OPERATOR",
                    controller.active_scenario["status"],
                )
                self.assertEqual(
                    step_index,
                    controller.active_scenario["completed_steps"],
                )

                expired = copy.deepcopy(controller.active_scenario)
                expired["operator_prompt"]["auto_confirm_deadline_epoch"] = time.time() - 0.01
                expired["operator_prompt"]["auto_confirm_deadline_monotonic"] = (
                    time.monotonic() - 0.01
                )
                controller.active_scenario = copy.deepcopy(expired)
                engine.advance(expired)

                current = controller.active_scenario
                self.assertEqual("RUNNING", current["status"])
                self.assertEqual(step_index + 1, current["completed_steps"])
                self.assertEqual("timeout", current["confirmations"][-1]["method"])
                self.assertEqual(expected_step["id"], current["confirmations"][-1]["step_id"])
                self.assertEqual(
                    1,
                    sum(
                        event["code"] == "SEQUENTIAL_OPERATOR_AUTO_CONFIRMED"
                        for event in controller.events
                    ),
                )

    def test_manual_click_wins_timeout_race_exactly_once(self) -> None:
        controller, engine, stale_snapshot = waiting_scenario("timeout")
        stale_snapshot["operator_prompt"]["auto_confirm_deadline_epoch"] = time.time() - 0.01
        stale_snapshot["operator_prompt"]["auto_confirm_deadline_monotonic"] = (
            time.monotonic() - 0.01
        )
        controller.active_scenario = copy.deepcopy(stale_snapshot)

        confirmed = engine.confirm(
            stale_snapshot,
            expected_run_id=str(stale_snapshot["run_id"]),
            expected_step_id=str(stale_snapshot["active_step_id"]),
        )
        self.assertEqual("manual", confirmed["confirmations"][0]["method"])
        engine.advance(stale_snapshot)

        current = controller.active_scenario
        self.assertEqual(1, current["completed_steps"])
        self.assertEqual(1, len(current["confirmations"]))
        confirmation_events = [
            event
            for event in controller.events
            if event["code"]
            in {
                "SEQUENTIAL_OPERATOR_CONFIRMED",
                "SEQUENTIAL_OPERATOR_AUTO_CONFIRMED",
            }
        ]
        self.assertEqual(1, len(confirmation_events))
        self.assertEqual("SEQUENTIAL_OPERATOR_CONFIRMED", confirmation_events[0]["code"])

    def test_stale_dialog_cannot_confirm_a_later_gate(self) -> None:
        controller, engine, current = waiting_scenario("manual", step_index=1)
        with self.assertRaisesRegex(RuntimeError, "no longer active"):
            engine.confirm(
                current,
                expected_run_id=str(current["run_id"]),
                expected_step_id="confirm_source_pickup",
            )
        self.assertEqual("WAITING_OPERATOR", controller.active_scenario["status"])
        self.assertEqual(1, controller.active_scenario["completed_steps"])
        self.assertEqual([], controller.active_scenario["confirmations"])

    def test_stop_during_countdown_never_advances(self) -> None:
        controller, engine, stale_snapshot = waiting_scenario("timeout")
        engine.request_stop(stale_snapshot)
        self.assertEqual("CANCELLED", controller.active_scenario["status"])

        stale_snapshot["operator_prompt"]["auto_confirm_deadline_epoch"] = time.time() - 0.01
        stale_snapshot["operator_prompt"]["auto_confirm_deadline_monotonic"] = (
            time.monotonic() - 0.01
        )
        engine.advance(stale_snapshot)
        self.assertEqual("CANCELLED", controller.active_scenario["status"])
        self.assertEqual(0, controller.active_scenario["completed_steps"])
        self.assertEqual([], controller.active_scenario["confirmations"])

    def test_stop_invalidates_stale_running_snapshot_before_dispatch(self) -> None:
        controller = FakeController()
        engine = SequentialCellScenarioEngine(controller)
        steps = engine.normalize_steps(
            {
                "steps": [
                    {
                        "id": "rox_home",
                        "target": "rox",
                        "command": "rox_waypoint",
                        "waypoint": "home",
                    }
                ]
            }
        )
        running = {
            "id": "scenario",
            "run_id": "run-stop-race",
            "label": "Scenario",
            "target": "sequential_cell",
            "steps": steps,
            "status": "RUNNING",
            "state_revision": 0,
            "completed_steps": 0,
            "step_runs": [None],
            "active_kind": None,
            "active_step_id": None,
            "active_target": None,
            "stop_requested": False,
            "confirmations": [],
            "step_history": [],
        }
        controller.active_scenario = copy.deepcopy(running)
        stale_running = copy.deepcopy(running)

        engine.request_stop(running)
        self.assertEqual("CANCELLED", controller.active_scenario["status"])
        self.assertTrue(controller.active_scenario["stop_requested"])
        self.assertGreater(controller.active_scenario["state_revision"], 0)

        engine.advance(stale_running)
        self.assertFalse(engine._commit(stale_running))
        self.assertEqual(0, controller.dispatch_calls)
        self.assertEqual("CANCELLED", controller.active_scenario["status"])
        self.assertTrue(controller.active_scenario["stop_requested"])

    def test_invalid_modes_and_timeout_values_are_rejected(self) -> None:
        with self.assertRaises(ValueError):
            SequentialCellScenarioEngine.resolve_confirmation_mode({}, "automatic")
        with self.assertRaises(ValueError):
            SequentialCellScenarioEngine.confirmation_settings(
                {"operator_confirmation": {"default_mode": "automatic"}}
            )
        with self.assertRaises(ValueError):
            SequentialCellScenarioEngine.confirmation_settings(
                {"operator_confirmation": {"timeout_s": 0}}
            )


if __name__ == "__main__":
    unittest.main()
