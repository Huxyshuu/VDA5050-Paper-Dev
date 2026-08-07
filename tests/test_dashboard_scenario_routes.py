from __future__ import annotations

import copy
import sys
import threading
import types
import unittest


USING_FAKE_FLASK = False

try:
    from flask import Flask
except (ImportError, ModuleNotFoundError):
    USING_FAKE_FLASK = True

    class FakeHTTPException(Exception):
        def __init__(self, code: int, description: str = "") -> None:
            super().__init__(description)
            self.code = code
            self.description = description

    class FakeRequest:
        def __init__(self) -> None:
            self._local = threading.local()

        def set_json(self, payload) -> None:
            self._local.payload = payload

        def get_json(self, silent=False):
            return getattr(self._local, "payload", None)

    class FakeApp:
        def __init__(self, _name: str) -> None:
            self.routes = {}

        def _decorator(self, method: str, path: str):
            def register(callback):
                self.routes[(method, path)] = callback
                return callback

            return register

        def get(self, path: str):
            return self._decorator("GET", path)

        def post(self, path: str):
            return self._decorator("POST", path)

    fake_request = FakeRequest()
    fake_flask = types.ModuleType("flask")
    fake_flask.Response = object
    fake_flask.abort = lambda code, description="": (_ for _ in ()).throw(
        FakeHTTPException(code, description)
    )
    fake_flask.jsonify = (
        lambda value=None, **kwargs: value if value is not None else kwargs
    )
    fake_flask.request = fake_request
    sys.modules["flask"] = fake_flask

    fake_werkzeug = types.ModuleType("werkzeug")
    fake_werkzeug_exceptions = types.ModuleType("werkzeug.exceptions")
    fake_werkzeug_exceptions.HTTPException = FakeHTTPException
    fake_werkzeug.exceptions = fake_werkzeug_exceptions
    sys.modules["werkzeug"] = fake_werkzeug
    sys.modules["werkzeug.exceptions"] = fake_werkzeug_exceptions
    Flask = FakeApp

from fleet_control.dashboard_v3 import DashboardController


class ConfirmationEngineSpy:
    def __init__(self) -> None:
        self.calls = []

    def confirm(self, snapshot, *, expected_run_id, expected_step_id):
        self.calls.append((copy.deepcopy(snapshot), expected_run_id, expected_step_id))
        return dict(snapshot)


class DashboardScenarioRouteTests(unittest.TestCase):
    @staticmethod
    def bare_controller(name: str):
        app = Flask(name)
        controller = DashboardController.__new__(DashboardController)
        controller.app = app
        controller.lock = threading.RLock()
        controller.scenario_lifecycle_lock = threading.Lock()
        controller.active_scenario = None
        controller.sequential_engine = ConfirmationEngineSpy()
        controller._register_routes()
        return app, controller

    @staticmethod
    def post(app, registered_path: str, request_path: str, payload, *route_args):
        if not USING_FAKE_FLASK:
            with app.test_client() as client:
                response = client.post(request_path, json=payload)
            return response.status_code, response.get_json(silent=True)

        fake_request.set_json(payload)
        callback = app.routes[("POST", registered_path)]
        try:
            result = callback(*route_args)
        except FakeHTTPException as exc:
            return exc.code, {"error": exc.description}
        if isinstance(result, tuple):
            body, status = result[0], result[1]
            return status, body
        return 200, result

    def test_confirm_endpoint_requires_run_and_step_binding(self) -> None:
        app, controller = self.bare_controller("confirm_binding")
        controller.active_scenario = {
            "id": "sequential_pickup_delivery",
            "run_id": "run-current",
            "active_step_id": "confirm_source_pickup",
            "status": "WAITING_OPERATOR",
            "target": "sequential_cell",
        }

        invalid_payloads = [
            {},
            {"run_id": "run-current"},
            {"step_id": "confirm_source_pickup"},
            {"run_id": "", "step_id": "confirm_source_pickup"},
            {"run_id": "run-current", "step_id": ""},
        ]
        for payload in invalid_payloads:
            with self.subTest(payload=payload):
                status, _ = self.post(
                    app,
                    "/api/scenarios/active/confirm",
                    "/api/scenarios/active/confirm",
                    payload,
                )
                self.assertEqual(400, status)

        status, _ = self.post(
            app,
            "/api/scenarios/active/confirm",
            "/api/scenarios/active/confirm",
            {
                "run_id": "run-current",
                "step_id": "confirm_source_pickup",
            },
        )

        self.assertEqual(200, status)
        self.assertEqual(1, len(controller.sequential_engine.calls))
        _, run_id, step_id = controller.sequential_engine.calls[0]
        self.assertEqual("run-current", run_id)
        self.assertEqual("confirm_source_pickup", step_id)

    def test_dashboard_parses_split_watchdog_and_network_metrics(self) -> None:
        state = {
            "information": [
                {
                    "infoType": "WATCHDOG_HEALTH",
                    "infoLevel": "INFO",
                    "infoReferences": [
                        {"referenceKey": "status", "referenceValue": "CRITICAL"},
                        {"referenceKey": "lock_wait_ms", "referenceValue": "7.5"},
                        {"referenceKey": "write_duration_ms", "referenceValue": "993.8"},
                        {"referenceKey": "schedule_lateness_ms", "referenceValue": "2.0"},
                    ],
                },
                {
                    "infoType": "CRANE_NETWORK_HEALTH",
                    "infoLevel": "INFO",
                    "infoReferences": [
                        {"referenceKey": "status", "referenceValue": "DEGRADED"},
                        {"referenceKey": "interface", "referenceValue": "wlan0"},
                        {"referenceKey": "wireless", "referenceValue": "True"},
                        {"referenceKey": "wifi_signal_dbm", "referenceValue": "-76"},
                        {"referenceKey": "ping_rtt_ms", "referenceValue": "182.4"},
                    ],
                },
            ]
        }
        diagnostics = DashboardController._information_diagnostics(state)
        self.assertEqual(7.5, diagnostics["watchdog_health"]["lock_wait_ms"])
        self.assertEqual(993.8, diagnostics["watchdog_health"]["write_duration_ms"])
        self.assertEqual("wlan0", diagnostics["crane_network_health"]["interface"])
        self.assertTrue(diagnostics["crane_network_health"]["wireless"])
        self.assertEqual(-76.0, diagnostics["crane_network_health"]["wifi_signal_dbm"])

    def test_concurrent_starts_claim_the_scenario_slot_once(self) -> None:
        app, controller = self.bare_controller("concurrent_starts")
        first_inside = threading.Event()
        release_first = threading.Event()
        second_started = threading.Event()
        config_calls = 0
        dispatch_calls = 0
        calls_lock = threading.Lock()
        scenario = {
            "id": "test_rox",
            "label": "Concurrent start test",
            "description": "Test scenario",
            "target": "rox",
            "enabled": True,
            "waypoints": ["home"],
        }
        controller._load_waypoints = lambda: {
            "configured": True,
            "waypoints": {"home": {}},
        }

        def load_scenarios(_waypoints):
            nonlocal config_calls
            with calls_lock:
                config_calls += 1
                call_number = config_calls
            if call_number == 1:
                first_inside.set()
                if not release_first.wait(timeout=2.0):
                    raise RuntimeError("test did not release the first start")
            return {"test_rox": scenario}

        def dispatch_reasons(*_args, **_kwargs):
            nonlocal dispatch_calls
            with calls_lock:
                dispatch_calls += 1
            return []

        controller._load_scenarios = load_scenarios
        controller._dispatch_reasons = dispatch_reasons
        controller._copy_target_state = lambda _target: {}
        controller._add_event = lambda *_args, **_kwargs: None

        statuses = []
        status_lock = threading.Lock()

        def start_request(started=None) -> None:
            if started is not None:
                started.set()
            status, _ = self.post(
                app,
                "/api/scenarios/<scenario_id>/start",
                "/api/scenarios/test_rox/start",
                {},
                "test_rox",
            )
            with status_lock:
                statuses.append(status)

        threads = [
            threading.Thread(target=start_request),
            threading.Thread(target=start_request, args=(second_started,)),
        ]
        threads[0].start()
        self.assertTrue(first_inside.wait(timeout=1.0))
        threads[1].start()
        self.assertTrue(second_started.wait(timeout=1.0))
        release_first.set()
        for thread in threads:
            thread.join(timeout=3.0)

        self.assertTrue(all(not thread.is_alive() for thread in threads))
        self.assertEqual([202, 409], sorted(statuses))
        self.assertEqual(1, dispatch_calls)
        self.assertEqual("RUNNING", controller.active_scenario["status"])
        self.assertEqual("test_rox", controller.active_scenario["id"])


if __name__ == "__main__":
    unittest.main()
