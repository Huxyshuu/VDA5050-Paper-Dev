"""Sequential ROX-Diff + Ilmatar pickup/delivery scenario engine.

The engine dispatches one VDA command at a time and advances only after the
previous command reaches a terminal success state. Operator confirmations are
explicit scenario steps because the current cell has no authoritative payload
attached/released/removed sensor.
"""
from __future__ import annotations

import copy
import time
from datetime import datetime, timezone
from typing import Any, Dict, List, Mapping, MutableMapping, Optional
from uuid import uuid4

try:
    from crane_manual_controls import (
        build_crane_hoist_order,
        build_crane_xy_order,
        crane_readiness,
        load_crane_waypoint_config,
    )
except ImportError:  # package import during tests/tools
    from fleet_control.crane_manual_controls import (
        build_crane_hoist_order,
        build_crane_xy_order,
        crane_readiness,
        load_crane_waypoint_config,
    )


def _utc_now() -> str:
    return datetime.now(timezone.utc).isoformat(timespec="milliseconds").replace("+00:00", "Z")


SUPPORTED_COMMANDS = {
    "crane_home_all",
    "crane_waypoint",
    "crane_hoist",
    "rox_waypoint",
    "operator_confirm",
}
TERMINAL_FAILURES = {"FAILED", "REJECTED", "CANCELLED"}
ACTIVE_INSTANT_STATES = {"WAITING", "INITIALIZING", "RUNNING", "PAUSED", "RETRIABLE"}
DEFAULT_TIMEOUTS_S = {
    "crane_home_all": 300.0,
    "crane_waypoint": 180.0,
    "crane_hoist": 120.0,
    "rox_waypoint": 300.0,
    "operator_confirm": 900.0,
}


class SequentialCellScenarioEngine:
    """Run configuration-defined cross-device steps through DashboardController."""

    def __init__(self, controller: Any) -> None:
        self.controller = controller

    def normalize_steps(self, cfg: Mapping[str, Any]) -> List[Dict[str, Any]]:
        raw_steps = cfg.get("steps") or []
        if not isinstance(raw_steps, list) or not raw_steps:
            raise ValueError("Sequential cell scenario must contain a non-empty steps list")
        result: List[Dict[str, Any]] = []
        seen: set[str] = set()
        for index, raw in enumerate(raw_steps):
            if not isinstance(raw, Mapping):
                raise ValueError(f"Scenario step {index + 1} must be an object")
            command = str(raw.get("command") or "")
            if command not in SUPPORTED_COMMANDS:
                raise ValueError(f"Scenario step {index + 1} has unsupported command {command!r}")
            step_id = str(raw.get("id") or f"step_{index + 1}")
            if step_id in seen:
                raise ValueError(f"Duplicate scenario step id {step_id!r}")
            seen.add(step_id)
            target = str(raw.get("target") or ("operator" if command == "operator_confirm" else ""))
            expected_target = (
                "rox" if command == "rox_waypoint" else
                "operator" if command == "operator_confirm" else
                "crane"
            )
            if target != expected_target:
                raise ValueError(
                    f"Scenario step {step_id!r} command {command!r} requires target {expected_target!r}"
                )
            item = dict(raw)
            item.update(
                {
                    "id": step_id,
                    "command": command,
                    "target": target,
                    "label": str(raw.get("label") or step_id.replace("_", " ").title()),
                    "description": str(raw.get("description") or ""),
                    "timeout_s": max(1.0, float(raw.get("timeout_s", DEFAULT_TIMEOUTS_S[command]))),
                }
            )
            result.append(item)
        return result

    def configuration_reasons(
        self,
        cfg: Mapping[str, Any],
        rox_waypoints: Mapping[str, Any],
    ) -> List[str]:
        reasons: List[str] = []
        try:
            steps = self.normalize_steps(cfg)
        except ValueError as exc:
            return [str(exc)]
        try:
            crane_cfg = load_crane_waypoint_config(self.controller.crane_waypoint_path)
        except Exception as exc:
            reasons.append(str(exc))
            crane_cfg = None
        if not self.controller.rox_enabled:
            reasons.append("ROX-Diff is disabled in fleet-control configuration")
        if not self.controller.crane_enabled:
            reasons.append("Crane is disabled in fleet-control configuration")
        if self.controller.require_configured and not bool(rox_waypoints.get("configured", False)):
            reasons.append("ROX-Diff waypoints are not marked configured")
        if crane_cfg is not None and not bool(crane_cfg.get("configured", False)):
            reasons.append("Crane waypoints and hook heights are not physically verified")
        available_rox = set((rox_waypoints.get("waypoints") or {}).keys())
        available_crane = set((crane_cfg or {}).get("waypoints", {}).keys())
        available_hoist = set((crane_cfg or {}).get("hoist_positions", {}).keys())
        for step in steps:
            command = step["command"]
            if command == "rox_waypoint" and str(step.get("waypoint")) not in available_rox:
                reasons.append(f"Missing ROX waypoint {step.get('waypoint')!r}")
            elif command == "crane_waypoint" and str(step.get("waypoint")) not in available_crane:
                reasons.append(f"Missing crane waypoint {step.get('waypoint')!r}")
            elif command == "crane_hoist" and str(step.get("position")) not in available_hoist:
                reasons.append(f"Missing crane hoist position {step.get('position')!r}")
        return list(dict.fromkeys(reasons))

    def start(
        self,
        scenario_id: str,
        cfg: Mapping[str, Any],
        rox_waypoints: Mapping[str, Any],
    ) -> Dict[str, Any]:
        reasons = self.configuration_reasons(cfg, rox_waypoints)
        if reasons:
            raise RuntimeError("; ".join(reasons))
        crane_cfg = load_crane_waypoint_config(self.controller.crane_waypoint_path)
        rox_reasons = self.controller._dispatch_reasons(
            "rox", self.controller._copy_target_state("rox"), rox_waypoints
        )
        crane_reasons, _ = crane_readiness(self.controller.ctx, crane_cfg)
        all_reasons = [f"rox: {reason}" for reason in rox_reasons]
        all_reasons.extend(f"crane: {reason}" for reason in crane_reasons)
        if all_reasons:
            raise RuntimeError("; ".join(all_reasons))
        steps = self.normalize_steps(cfg)
        return {
            "id": scenario_id,
            "run_id": str(uuid4()),
            "label": str(cfg.get("label") or scenario_id),
            "description": str(cfg.get("description") or "Sequential cell scenario"),
            "target": "sequential_cell",
            "steps": steps,
            "waypoints": [step["id"] for step in steps],
            "status": "RUNNING",
            "completed_steps": 0,
            "step_runs": [None for _ in steps],
            "active_step_id": None,
            "active_target": None,
            "active_kind": None,
            "active_order_id": None,
            "active_action_id": None,
            "active_final_node_sequence_id": 0,
            "operator_prompt": None,
            "confirmations": [],
            "step_history": [],
            "active_step_started_at": None,
            "active_step_started_epoch": None,
            "active_timeout_s": None,
            "last_transition": "Scenario created",
            "stop_requested": False,
            "cancel_sent": False,
            "started_at": _utc_now(),
            "updated_at": _utc_now(),
        }

    @staticmethod
    def _final_sequence(order: Mapping[str, Any]) -> int:
        return max((int(node.get("sequenceId", 0)) for node in order.get("nodes") or []), default=0)

    def _instant_status(self, target: str, action_id: str) -> str:
        state = self.controller._copy_target_state(target).get("last_state") or {}
        for item in state.get("instantActionStates") or []:
            if not isinstance(item, Mapping) or str(item.get("actionId", "")) != action_id:
                continue
            return str(item.get("actionStatus") or "SENT")
        return "SENT"

    def _clear_active(self, active: MutableMapping[str, Any]) -> None:
        active.update(
            {
                "active_step_id": None,
                "active_target": None,
                "active_kind": None,
                "active_order_id": None,
                "active_action_id": None,
                "active_final_node_sequence_id": 0,
                "operator_prompt": None,
                "active_step_started_at": None,
                "active_step_started_epoch": None,
                "active_timeout_s": None,
            }
        )

    def _finish_step(self, active: MutableMapping[str, Any], result_id: Optional[str]) -> None:
        index = int(active.get("completed_steps", 0))
        steps = active.get("steps") or []
        step = steps[index] if index < len(steps) else {}
        started_epoch = active.get("active_step_started_epoch")
        duration = max(0.0, time.time() - float(started_epoch)) if started_epoch else 0.0
        step_runs = active.setdefault("step_runs", [None for _ in steps])
        if index < len(step_runs):
            step_runs[index] = result_id
        active.setdefault("step_history", []).append({
            "step_id": step.get("id"),
            "label": step.get("label"),
            "target": step.get("target"),
            "command": step.get("command"),
            "status": "FINISHED",
            "started_at": active.get("active_step_started_at"),
            "finished_at": _utc_now(),
            "duration_s": round(duration, 3),
            "result_id": result_id,
        })
        active["completed_steps"] = index + 1
        active["updated_at"] = _utc_now()
        active["last_transition"] = f"Finished: {step.get('label', step.get('id', 'step'))}"
        self.controller._add_event(
            "INFO",
            str(step.get("target") or "scenario"),
            f"Sequential step finished: {step.get('label', step.get('id', 'step'))} ({duration:.1f}s)",
            code="SEQUENTIAL_STEP_FINISHED",
            details={
                "scenario_id": active.get("id"),
                "step_id": step.get("id"),
                "duration_s": round(duration, 3),
                "result_id": result_id,
            },
        )
        self._clear_active(active)

    def _fail_step(self, active: MutableMapping[str, Any], status: str, detail: str) -> None:
        index = int(active.get("completed_steps", 0))
        steps = active.get("steps") or []
        step = steps[index] if index < len(steps) else {}
        started_epoch = active.get("active_step_started_epoch")
        duration = max(0.0, time.time() - float(started_epoch)) if started_epoch else 0.0
        active.setdefault("step_history", []).append({
            "step_id": step.get("id"),
            "label": step.get("label"),
            "target": step.get("target"),
            "command": step.get("command"),
            "status": status,
            "started_at": active.get("active_step_started_at"),
            "finished_at": _utc_now(),
            "duration_s": round(duration, 3),
            "error": detail,
        })
        active["status"] = status
        active["error"] = detail
        active["updated_at"] = _utc_now()
        active["finished_at"] = _utc_now()
        active["last_transition"] = f"Failed: {step.get('label', step.get('id', 'step'))}"
        self.controller._add_event(
            "ERROR",
            str(step.get("target") or "scenario"),
            f"Sequential step failed: {step.get('label', step.get('id', 'step'))}: {detail}",
            code="SEQUENTIAL_STEP_FAILED",
            details={
                "scenario_id": active.get("id"),
                "step_id": step.get("id"),
                "duration_s": round(duration, 3),
                "status": status,
            },
        )

    def _dispatch_step(self, active: MutableMapping[str, Any], step: Mapping[str, Any]) -> None:
        command = str(step["command"])
        active["active_step_id"] = str(step["id"])
        active["active_target"] = str(step["target"])
        active["active_step_started_at"] = _utc_now()
        active["active_step_started_epoch"] = time.time()
        active["active_timeout_s"] = float(step.get("timeout_s", DEFAULT_TIMEOUTS_S[command]))
        active["last_transition"] = f"Started: {step['label']}"
        active["updated_at"] = _utc_now()

        if command == "operator_confirm":
            active["active_kind"] = "operator"
            active["status"] = "WAITING_OPERATOR"
            active["operator_prompt"] = {
                "step_id": step["id"],
                "label": step["label"],
                "prompt": str(step.get("prompt") or step.get("description") or "Confirm the manual step is complete."),
                "confirm_label": str(step.get("confirm_label") or "Continue scenario"),
            }
            self.controller._add_event(
                "WARNING", "operator", f"Scenario waiting for operator: {step['label']}",
                code="SEQUENTIAL_OPERATOR_WAIT",
                details={"scenario_id": active.get("id"), "step_id": step.get("id")},
            )
            return

        if command == "rox_waypoint":
            mission = self.controller._dispatch_waypoint(
                str(step["waypoint"]),
                source="scenario",
                scenario_id=str(active["id"]),
            )
            order_id = str(mission["order_id"])
            final_sequence = max(
                (int(node.get("sequenceId", 0)) for node in mission.get("nodes") or []),
                default=0,
            )
            active.update(
                {
                    "active_kind": "order",
                    "active_order_id": order_id,
                    "active_final_node_sequence_id": final_sequence,
                }
            )
            return

        crane_cfg = load_crane_waypoint_config(self.controller.crane_waypoint_path)
        reasons, live = crane_readiness(self.controller.ctx, crane_cfg)
        if reasons:
            raise RuntimeError("; ".join(reasons))

        if command == "crane_home_all":
            action_id = self.controller.publish_instant("resetAllHome", target="crane")
            active.update({"active_kind": "instant", "active_action_id": action_id})
            return
        if command == "crane_waypoint":
            order = build_crane_xy_order(crane_cfg, live["state"], str(step["waypoint"]))
        elif command == "crane_hoist":
            order = build_crane_hoist_order(crane_cfg, live["state"], str(step["position"]))
        else:  # pragma: no cover - normalize_steps prevents this
            raise RuntimeError(f"Unsupported sequential command {command!r}")
        self.controller.publish_order(order, target="crane")
        active.update(
            {
                "active_kind": "order",
                "active_order_id": str(order["orderId"]),
                "active_final_node_sequence_id": self._final_sequence(order),
            }
        )

    def advance(self, snapshot: Mapping[str, Any]) -> None:
        active = copy.deepcopy(snapshot)
        if active.get("status") == "WAITING_OPERATOR":
            return
        if active.get("status") not in {"RUNNING", "CANCELLING"}:
            return

        started_epoch = active.get("active_step_started_epoch")
        timeout_s = active.get("active_timeout_s")
        if (
            active.get("active_kind")
            and started_epoch
            and timeout_s
            and time.time() - float(started_epoch) > float(timeout_s)
        ):
            target = str(active.get("active_target") or "")
            kind = active.get("active_kind")
            try:
                if kind == "order" and target:
                    self.controller._cancel_target_order(target, str(active.get("active_order_id") or ""))
                elif kind == "instant" and target:
                    self.controller.publish_instant("cancelOrder", target=target)
            except Exception as exc:
                self.controller._add_event(
                    "ERROR", target or "scenario", f"Timeout cancellation failed: {exc}",
                    code="SEQUENTIAL_TIMEOUT_CANCEL_FAILED",
                )
            self._fail_step(
                active,
                "FAILED",
                f"Step {active.get('active_step_id')} exceeded its {float(timeout_s):.0f}s timeout",
            )
            self._commit(active)
            return

        if active.get("stop_requested"):
            kind = active.get("active_kind")
            target = str(active.get("active_target") or "")
            still_active = False
            if kind == "order" and target:
                state = self.controller._copy_target_state(target).get("last_state") or {}
                still_active = self.controller._active_order(state)
            elif kind == "instant" and target:
                status = self._instant_status(target, str(active.get("active_action_id") or ""))
                still_active = status in ACTIVE_INSTANT_STATES or status == "SENT"
            if not still_active:
                active["status"] = "CANCELLED"
                active["finished_at"] = _utc_now()
                active["updated_at"] = _utc_now()
            self._commit(active)
            return

        kind = active.get("active_kind")
        if kind == "order":
            target = str(active.get("active_target") or "")
            status = self.controller._coordinated_target_status(
                target,
                str(active.get("active_order_id") or ""),
                int(active.get("active_final_node_sequence_id") or 0),
            )
            if status == "FINISHED":
                self._finish_step(active, str(active.get("active_order_id") or ""))
            elif status in TERMINAL_FAILURES:
                self._fail_step(
                    active,
                    status,
                    f"Step {active.get('active_step_id')} ended as {status}",
                )
            self._commit(active)
            return
        if kind == "instant":
            status = self._instant_status(
                str(active.get("active_target") or "crane"),
                str(active.get("active_action_id") or ""),
            )
            if status == "FINISHED":
                self._finish_step(active, str(active.get("active_action_id") or ""))
            elif status == "FAILED":
                self._fail_step(active, "FAILED", f"Step {active.get('active_step_id')} failed")
            self._commit(active)
            return

        index = int(active.get("completed_steps", 0))
        steps = active.get("steps") or []
        if index >= len(steps):
            active["status"] = "FINISHED"
            active["finished_at"] = _utc_now()
            active["updated_at"] = _utc_now()
            self._commit(active)
            self.controller._add_event(
                "INFO", "scenario", f"Scenario {active['label']} finished", code="SCENARIO_FINISHED"
            )
            return
        step = steps[index]
        try:
            self._dispatch_step(active, step)
        except RuntimeError as exc:
            text = str(exc)
            # State messages can briefly continue reporting the preceding order.
            if "Another" in text and "order is active" in text:
                return
            self._fail_step(active, "FAILED", f"Could not dispatch {step['label']}: {text}")
        else:
            self.controller._add_event(
                "INFO",
                str(step["target"]),
                f"Sequential step started: {step['label']}",
                code="SEQUENTIAL_STEP_STARTED",
                details={"scenario_id": active["id"], "step_id": step["id"]},
            )
        self._commit(active)

    def confirm(self, snapshot: Mapping[str, Any]) -> Dict[str, Any]:
        active = copy.deepcopy(snapshot)
        if active.get("target") != "sequential_cell" or active.get("status") != "WAITING_OPERATOR":
            raise RuntimeError("The active scenario is not waiting for operator confirmation")
        step_id = str(active.get("active_step_id") or "")
        active.setdefault("confirmations", []).append(
            {"step_id": step_id, "confirmed_at": _utc_now()}
        )
        self.controller._add_event(
            "INFO", "operator", f"Operator confirmed scenario step {step_id}",
            code="SEQUENTIAL_OPERATOR_CONFIRMED",
            details={"scenario_id": active.get("id"), "step_id": step_id},
        )
        self._finish_step(active, f"operator:{step_id}")
        active["status"] = "RUNNING"
        self._commit(active)
        return active

    def request_stop(self, snapshot: Mapping[str, Any]) -> bool:
        active = copy.deepcopy(snapshot)
        active["stop_requested"] = True
        active["status"] = "CANCELLING"
        active["updated_at"] = _utc_now()
        sent = False
        target = str(active.get("active_target") or "")
        kind = active.get("active_kind")
        if kind == "order" and target:
            self.controller._cancel_target_order(target, str(active.get("active_order_id") or ""))
            sent = True
        elif kind == "instant" and target:
            self.controller.publish_instant("cancelOrder", target=target)
            sent = True
        else:
            active["status"] = "CANCELLED"
            active["finished_at"] = _utc_now()
        active["cancel_sent"] = sent
        self._commit(active)
        return sent

    def project_steps(self, active: Mapping[str, Any]) -> List[Dict[str, Any]]:
        completed = int(active.get("completed_steps", 0))
        status = str(active.get("status") or "")
        result: List[Dict[str, Any]] = []
        step_runs = active.get("step_runs") or []
        for index, step in enumerate(active.get("steps") or []):
            if index < completed or status == "FINISHED":
                phase, step_status = "completed", "FINISHED"
            elif index == completed and status in {"RUNNING", "WAITING_OPERATOR", "PAUSED", "CANCELLING"}:
                phase = "active"
                step_status = "WAITING_OPERATOR" if status == "WAITING_OPERATOR" else status
            elif index == completed and status in TERMINAL_FAILURES:
                phase, step_status = "failed", status
            else:
                phase, step_status = "upcoming", "UPCOMING"
            result.append(
                {
                    "index": index,
                    "id": step["id"],
                    "waypoint": step.get("waypoint") or step.get("position") or step["id"],
                    "label": step["label"],
                    "description": step.get("description", ""),
                    "target": step["target"],
                    "command": step["command"],
                    "phase": phase,
                    "status": step_status,
                    "run_id": step_runs[index] if index < len(step_runs) else None,
                    "timeout_s": float(step.get("timeout_s", DEFAULT_TIMEOUTS_S[step["command"]])),
                    "history": next((item for item in reversed(active.get("step_history") or []) if item.get("step_id") == step["id"]), None),
                    "elapsed_s": (
                        round(max(0.0, time.time() - float(active.get("active_step_started_epoch"))), 1)
                        if index == completed and active.get("active_step_started_epoch")
                        else None
                    ),
                }
            )
        return result

    def _commit(self, active: Mapping[str, Any]) -> None:
        with self.controller.lock:
            current = self.controller.active_scenario
            if current and current.get("run_id") == active.get("run_id"):
                self.controller.active_scenario = dict(active)
