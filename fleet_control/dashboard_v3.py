"""Dynamic VDA 5050 v3.0 mission-control dashboard extension.

This module is deliberately kept separate from ``master_control.py``.  The existing
MQTT, schema validation, order stamping and handover orchestration remain
authoritative.  The extension adds a live dashboard API, dynamic waypoint orders,
ROX-first scenarios and a compact event history.

The module uses VDA state fields for control decisions.  ``information[]`` is never
used for dispatch, completion, safety or scenario progression.
"""
from __future__ import annotations

import copy
import os
import threading
import time
import math
from collections import deque
from datetime import datetime, timezone
from pathlib import Path
from typing import Any, Dict, Iterable, List, Mapping, MutableMapping, Optional, Tuple
from uuid import uuid4

import yaml
from flask import abort, jsonify, request
from werkzeug.exceptions import HTTPException

FINAL_ACTION_STATES = {"FINISHED", "FAILED"}
ACTIVE_ACTION_STATES = {
    "WAITING",
    "INITIALIZING",
    "RUNNING",
    "PAUSED",
    "RETRIABLE",
}
ACTIVE_MISSION_STATES = {
    "SENT",
    "ACCEPTED",
    "RUNNING",
    "PAUSED",
    "RETRIABLE",
    "CANCELLING",
}


def _bool_env(name: str, default: bool) -> bool:
    raw = os.getenv(name)
    if raw is None:
        return default
    return raw.strip().lower() in {"1", "true", "yes", "on"}


def _float_env(name: str, default: float) -> float:
    try:
        return float(os.getenv(name, str(default)))
    except (TypeError, ValueError):
        return default


def _int_env(name: str, default: int) -> int:
    try:
        return int(os.getenv(name, str(default)))
    except (TypeError, ValueError):
        return default


def _utc_now() -> str:
    return (
        datetime.now(timezone.utc)
        .isoformat(timespec="milliseconds")
        .replace("+00:00", "Z")
    )


def _parse_timestamp(value: Any) -> Optional[float]:
    if not isinstance(value, str) or not value:
        return None
    try:
        return datetime.fromisoformat(value.replace("Z", "+00:00")).timestamp()
    except ValueError:
        return None


def _age_seconds(payload: Optional[Mapping[str, Any]]) -> Optional[float]:
    if not payload:
        return None
    stamp = _parse_timestamp(payload.get("timestamp"))
    return None if stamp is None else max(0.0, time.time() - stamp)

def _json_safe(value: Any) -> Any:
    """Recursively convert non-finite floats into JSON null values."""
    if isinstance(value, float):
        return value if math.isfinite(value) else None

    if isinstance(value, Mapping):
        return {
            str(key): _json_safe(item)
            for key, item in value.items()
        }

    if isinstance(value, (list, tuple)):
        return [_json_safe(item) for item in value]

    return value

def _safe_float(value: Any, default: float = 0.0) -> float:
    try:
        return float(value)
    except (TypeError, ValueError):
        return default


def _safe_int(value: Any, default: int = 0) -> int:
    try:
        return int(value)
    except (TypeError, ValueError):
        return default


def _error_references(error: Mapping[str, Any]) -> Dict[str, str]:
    refs: Dict[str, str] = {}
    for item in error.get("errorReferences") or []:
        if isinstance(item, Mapping):
            key = str(item.get("referenceKey", ""))
            value = str(item.get("referenceValue", ""))
            if key:
                refs[key] = value
    return refs


class DashboardController:
    """Stateful Flask/MQTT dashboard adapter around ``master_control`` globals."""

    def __init__(self, app: Any, ctx: MutableMapping[str, Any]) -> None:
        self.app = app
        self.ctx = ctx
        self.repo_root = Path(ctx["REPO_ROOT"])
        self.state = ctx["STATE"]
        self.state_lock = ctx["STATE_LOCK"]
        self.targets = ctx["TARGETS"]
        self.order_book = ctx["ORDER_BOOK"]
        self.publish_order = ctx["_publish_order"]
        self.publish_instant = ctx["_publish_instant_action"]
        self.kv_params = ctx["_kv_params"]
        self.mqtt_client = ctx["mqtt_client"]
        self.protocol_version = str(ctx.get("VDA_PROTOCOL_VERSION", "3.0.0"))
        self.broker_host = str(ctx.get("BROKER_HOST", ""))
        self.broker_port = int(ctx.get("BROKER_PORT", 1883))
        self.default_map_id = str(ctx.get("DEFAULT_MAP_ID", "df_map"))
        self.started_monotonic = time.monotonic()

        self.waypoint_path = self._repo_path(
            os.getenv("ROX_WAYPOINT_FILE", "configs/rox_waypoints.yaml")
        )
        self.scenario_path = self._repo_path(
            os.getenv("FLEET_UI_SCENARIO_FILE", "configs/dashboard_scenarios.yaml")
        )
        self.rox_enabled = _bool_env("ROX_ENABLED", True)
        self.crane_enabled = _bool_env("CRANE_ENABLED", False)
        self.require_localized = _bool_env("FLEET_UI_REQUIRE_LOCALIZED", True)
        self.require_configured = _bool_env("FLEET_UI_REQUIRE_CONFIGURED_WAYPOINTS", True)
        self.start_tolerance_m = _float_env("FLEET_UI_START_TOLERANCE_M", 0.35)
        # VDA 5050 requires a state publication at least every 30 seconds.
        self.state_stale_s = _float_env("FLEET_UI_STATE_STALE_S", 35.0)
        self.order_accept_timeout_s = _float_env("FLEET_UI_ORDER_ACCEPT_TIMEOUT_S", 12.0)
        self.event_limit = max(50, _int_env("FLEET_UI_EVENT_LIMIT", 300))
        self.mission_limit = max(10, _int_env("FLEET_UI_MISSION_LIMIT", 50))

        self.lock = threading.RLock()
        self.events: deque[Dict[str, Any]] = deque(maxlen=self.event_limit)
        self.missions: deque[Dict[str, Any]] = deque(maxlen=self.mission_limit)
        self.controls: deque[Dict[str, Any]] = deque(maxlen=100)
        self.active_scenario: Optional[Dict[str, Any]] = None
        self._last_signature: Dict[str, Any] = {}
        self._stop = threading.Event()

        self._add_event(
            "INFO",
            "server",
            "VDA 5050 v3 mission dashboard initialized",
            code="DASHBOARD_READY",
        )
        self._register_routes()
        self.worker = threading.Thread(
            target=self._scenario_worker,
            name="vda5050-dashboard-scenario",
            daemon=True,
        )
        self.worker.start()

    def _repo_path(self, value: str) -> Path:
        path = Path(value).expanduser()
        return path if path.is_absolute() else self.repo_root / path

    # ------------------------------------------------------------------
    # Configuration
    def _load_waypoints(self) -> Dict[str, Any]:
        if not self.waypoint_path.exists():
            raise FileNotFoundError(f"Waypoint file not found: {self.waypoint_path}")
        with self.waypoint_path.open("r", encoding="utf-8") as handle:
            data = yaml.safe_load(handle) or {}
        if not isinstance(data, Mapping):
            raise ValueError("Waypoint YAML root must be an object")
        waypoints = data.get("waypoints")
        if not isinstance(waypoints, Mapping):
            raise ValueError("Waypoint YAML must contain a 'waypoints' mapping")
        map_id = str(data.get("map_id") or self.default_map_id)
        configured = bool(data.get("configured", False))
        result: Dict[str, Any] = {
            "map_id": map_id,
            "configured": configured,
            "waypoints": {},
        }
        for name, raw in waypoints.items():
            if not isinstance(raw, Mapping):
                continue
            try:
                x = float(raw["x"])
                y = float(raw["y"])
                theta = float(raw.get("theta", 0.0))
            except (KeyError, TypeError, ValueError):
                continue
            result["waypoints"][str(name)] = {
                "name": str(name),
                "label": str(raw.get("label") or str(name).replace("_", " ").title()),
                "description": str(raw.get("description") or "Navigate ROX-Diff to this mapped pose."),
                "x": x,
                "y": y,
                "theta": theta,
                "allowed_deviation_xy": max(
                    0.01, _safe_float(raw.get("allowed_deviation_xy"), 0.20)
                ),
                "allowed_deviation_theta": max(
                    0.01, _safe_float(raw.get("allowed_deviation_theta"), 0.20)
                ),
            }
        return result

    def _default_scenarios(self, available: Iterable[str]) -> Dict[str, Any]:
        names = set(available)
        candidates = {
            "short_commissioning": {
                "label": "Short commissioning loop",
                "description": "Home → short test → home. Recommended first real-motion scenario.",
                "target": "rox",
                "waypoints": ["home", "short_test", "home"],
                "enabled": {"home", "short_test"}.issubset(names),
                "risk": "low",
            },
            "rox_case_study_route": {
                "label": "ROX case-study route",
                "description": "ROX-only traversal of the mapped handover and drop-off positions.",
                "target": "rox",
                "waypoints": [
                    "home",
                    "short_test",
                    "crane_handover",
                    "warehouse_dropoff",
                    "home",
                ],
                "enabled": {
                    "home",
                    "short_test",
                    "crane_handover",
                    "warehouse_dropoff",
                }.issubset(names),
                "risk": "supervised",
            },
            "crane_approach_only": {
                "label": "ROX crane approach",
                "description": "Navigate only the ROX-Diff to the crane handover waypoint; no crane command is sent.",
                "target": "rox",
                "waypoints": ["crane_handover"],
                "enabled": "crane_handover" in names,
                "risk": "supervised",
            },
            "coordinated_handover": {
                "label": "Coordinated crane handover",
                "description": "Reserved for the future commissioned crane + ROX sequence.",
                "target": "coordinated",
                "waypoints": ["crane_handover"],
                "enabled": False,
                "disabled_reason": "Crane is currently marked unavailable and cannot be tested.",
                "risk": "locked",
            },
        }
        return candidates

    def _load_scenarios(self, waypoints: Mapping[str, Any]) -> Dict[str, Any]:
        scenarios = self._default_scenarios(waypoints.keys())
        if self.scenario_path.exists():
            with self.scenario_path.open("r", encoding="utf-8") as handle:
                raw = yaml.safe_load(handle) or {}
            entries = raw.get("scenarios", raw) if isinstance(raw, Mapping) else {}
            if isinstance(entries, Mapping):
                for scenario_id, cfg in entries.items():
                    if not isinstance(cfg, Mapping):
                        continue
                    merged = dict(scenarios.get(str(scenario_id), {}))
                    merged.update(dict(cfg))
                    scenarios[str(scenario_id)] = merged
        for scenario_id, cfg in scenarios.items():
            cfg["id"] = scenario_id
            cfg.setdefault("target", "rox")
            cfg.setdefault("waypoints", [])
            cfg.setdefault("label", scenario_id.replace("_", " ").title())
            cfg.setdefault("description", "Configured mission sequence")
            cfg.setdefault("risk", "supervised")
            missing = [name for name in cfg["waypoints"] if name not in waypoints]
            if missing:
                cfg["enabled"] = False
                cfg["disabled_reason"] = f"Missing waypoint(s): {', '.join(missing)}"
            if cfg.get("target") == "coordinated" and not self.crane_enabled:
                cfg["enabled"] = False
                cfg["disabled_reason"] = "Crane is unavailable in the current configuration."
        return scenarios

    # ------------------------------------------------------------------
    # Events and state projection
    def _add_event(
        self,
        level: str,
        source: str,
        message: str,
        *,
        code: str = "",
        details: Optional[Mapping[str, Any]] = None,
    ) -> None:
        event = {
            "id": str(uuid4()),
            "timestamp": _utc_now(),
            "level": level.upper(),
            "source": source,
            "code": code,
            "message": message,
        }
        if details:
            event["details"] = dict(details)
        with self.lock:
            self.events.append(event)

    def _copy_target_state(self, target: str) -> Dict[str, Any]:
        with self.state_lock:
            return copy.deepcopy(self.state.get(target, {}))

    def _mqtt_connected(self) -> bool:
        try:
            return bool(self.mqtt_client.is_connected())
        except Exception:
            return False

    def _cache_age(self, target_cache: Mapping[str, Any], key: str) -> Optional[float]:
        """Return age from local receive time, falling back to protocol timestamp."""
        received_at = target_cache.get(f"{key}_received_at")
        if isinstance(received_at, (int, float)):
            return max(0.0, time.time() - float(received_at))
        payload = target_cache.get(key)
        return _age_seconds(payload if isinstance(payload, Mapping) else None)

    def _active_order(self, state: Optional[Mapping[str, Any]]) -> bool:
        if not state:
            return False
        if state.get("nodeStates") or state.get("edgeStates"):
            return True
        return any(
            str(item.get("actionStatus")) in ACTIVE_ACTION_STATES
            for item in state.get("actionStates") or []
            if isinstance(item, Mapping)
        )

    def _dispatch_reasons(
        self,
        target: str,
        target_cache: Mapping[str, Any],
        waypoint_cfg: Optional[Mapping[str, Any]] = None,
    ) -> List[str]:
        enabled = self.rox_enabled if target == "rox" else self.crane_enabled
        reasons: List[str] = []
        if not enabled:
            reasons.append("Device is disabled in fleet-control configuration")
        if not self._mqtt_connected():
            reasons.append("Master controller is not connected to MQTT")
        connection = target_cache.get("connection") or {}
        if str(connection.get("connectionState", "")) != "ONLINE":
            reasons.append("VDA connection state is not ONLINE")
        # Do not age-gate the retained VDA connection message. The v3
        # specification explicitly notes that its timestamp/headerId will be
        # outdated; liveness is represented by ONLINE/OFFLINE/CONNECTION_BROKEN.
        state = target_cache.get("last_state") or {}
        if not state:
            reasons.append("No schema-valid VDA state has been received")
            return reasons
        state_age = self._cache_age(target_cache, "last_state")
        if state_age is not None and state_age > self.state_stale_s:
            reasons.append(f"State message is stale ({state_age:.1f} s)")
        if self._active_order(state):
            reasons.append("Another VDA order is active")
        mode = str(state.get("operatingMode", ""))
        if target == "rox" and mode not in {"AUTOMATIC", "SEMIAUTOMATIC"}:
            reasons.append(f"Operating mode {mode or 'UNKNOWN'} does not permit normal dispatch")
        safety = state.get("safetyState") or {}
        if str(safety.get("activeEmergencyStop", "NONE")) != "NONE":
            reasons.append("Emergency stop is active")
        if bool(safety.get("fieldViolation", False)):
            reasons.append("Safety field violation is active")
        position = state.get("mobileRobotPosition") or {}
        if target == "rox" and self.require_localized:
            if not position:
                reasons.append("No mobileRobotPosition is available")
            elif not bool(position.get("localized", False)):
                reasons.append("ROX-Diff localization is not valid")
        if waypoint_cfg and self.require_configured and not waypoint_cfg.get("configured"):
            reasons.append("Waypoint file is not marked configured")
        return reasons

    def _device_projection(
        self, target: str, target_cache: Mapping[str, Any], waypoint_cfg: Mapping[str, Any]
    ) -> Dict[str, Any]:
        state = target_cache.get("last_state") or {}
        connection = target_cache.get("connection") or {}
        position = state.get("mobileRobotPosition") or {}
        power = state.get("powerSupply") or {}
        safety = state.get("safetyState") or {}
        errors = state.get("errors") or []
        reasons = self._dispatch_reasons(target, target_cache, waypoint_cfg)
        enabled = self.rox_enabled if target == "rox" else self.crane_enabled
        return {
            "target": target,
            "label": "Neobotix ROX-Diff" if target == "rox" else "Ilmatar overhead crane",
            "enabled": enabled,
            "availability": "AVAILABLE" if enabled else "UNAVAILABLE",
            "connection": str(connection.get("connectionState", "UNKNOWN")),
            "online": str(connection.get("connectionState", "")) == "ONLINE",
            "connection_age_s": self._cache_age(target_cache, "connection"),
            "state_age_s": self._cache_age(target_cache, "last_state"),
            "operating_mode": state.get("operatingMode", "UNKNOWN"),
            "driving": bool(state.get("driving", False)),
            "paused": bool(state.get("paused", False)),
            "order_id": str(state.get("orderId", "")),
            "order_update_id": _safe_int(state.get("orderUpdateId"), 0),
            "last_node_id": str(state.get("lastNodeId", "")),
            "last_node_sequence_id": _safe_int(state.get("lastNodeSequenceId"), 0),
            "position": {
                "x": position.get("x"),
                "y": position.get("y"),
                "theta": position.get("theta"),
                "map_id": position.get("mapId"),
                "localized": position.get("localized"),
                "localization_score": position.get("localizationScore"),
            },
            "battery": {
                "state_of_charge": power.get("stateOfCharge"),
                "charging": power.get("charging"),
                "voltage": power.get("batteryVoltage"),
                "range": power.get("range"),
            },
            "safety": {
                "active_emergency_stop": safety.get("activeEmergencyStop", "UNKNOWN"),
                "field_violation": bool(safety.get("fieldViolation", False)),
            },
            "active_order": self._active_order(state),
            "dispatch_ready": not reasons,
            "dispatch_reasons": reasons,
            "errors": [
                {
                    "type": item.get("errorType"),
                    "level": item.get("errorLevel"),
                    "description": item.get("errorDescription", ""),
                    "references": _error_references(item),
                }
                for item in errors
                if isinstance(item, Mapping)
            ],
            "factsheet_received": bool(target_cache.get("factsheet")),
            "raw_state": state,
            "instant_actions": state.get("instantActionStates") or [],
            "order_actions": state.get("actionStates") or [],
            "retriable_action_ids": [
                str(item.get("actionId"))
                for item in state.get("actionStates") or []
                if isinstance(item, Mapping)
                and str(item.get("actionStatus")) == "RETRIABLE"
                and item.get("actionId")
            ],
        }

    def _mission_status(
        self, mission: MutableMapping[str, Any], state: Mapping[str, Any]
    ) -> str:
        order_id = str(state.get("orderId", ""))
        referenced_errors = []
        for item in state.get("errors") or []:
            if not isinstance(item, Mapping):
                continue
            refs = _error_references(item)
            if refs.get("orderId") == mission["order_id"]:
                referenced_errors.append(item)

        if order_id != mission["order_id"]:
            if referenced_errors:
                return "REJECTED"
            age = time.time() - mission["created_epoch"]
            if age < self.order_accept_timeout_s:
                return "SENT"
            if state.get("nodeStates") or state.get("edgeStates"):
                return "REJECTED"
            # VDA 5050 has no separate orderStatus field. When the adapter has
            # neither acknowledged the orderId nor reported an order-referenced
            # error, retain SENT instead of inventing a protocol state.
            return mission.get("status", "SENT")

        node_states = state.get("nodeStates") or []
        edge_states = state.get("edgeStates") or []
        action_states = state.get("actionStates") or []
        if mission.get("cancel_requested"):
            if not node_states and not edge_states and all(
                str(item.get("actionStatus")) in FINAL_ACTION_STATES
                for item in action_states
                if isinstance(item, Mapping)
            ):
                return "CANCELLED"
            return "CANCELLING"
        if bool(state.get("paused", False)):
            return "PAUSED"
        if any(
            str(item.get("actionStatus")) == "RETRIABLE"
            for item in action_states
            if isinstance(item, Mapping)
        ):
            return "RETRIABLE"
        if any(
            str(item.get("actionStatus")) == "FAILED"
            for item in action_states
            if isinstance(item, Mapping)
        ):
            return "FAILED"
        if any(
            str(item.get("errorLevel")) in {"CRITICAL", "FATAL"}
            for item in referenced_errors
        ):
            return "FAILED"
        if not node_states and not edge_states:
            return "FINISHED"
        if bool(state.get("driving", False)):
            return "RUNNING"
        return "ACCEPTED"

    def _mission_projection(
        self, mission: MutableMapping[str, Any], state: Mapping[str, Any]
    ) -> Dict[str, Any]:
        status = self._mission_status(mission, state)
        old_status = mission.get("status")
        mission["status"] = status
        mission["updated_at"] = _utc_now()
        if old_status != status:
            self._add_event(
                "ERROR" if status in {"FAILED", "REJECTED"} else "INFO",
                mission["target"],
                f"Mission {mission['label']} changed from {old_status} to {status}",
                code="MISSION_STATUS",
                details={"order_id": mission["order_id"], "status": status},
            )

        state_matches = str(state.get("orderId", "")) == mission["order_id"]
        last_seq = _safe_int(state.get("lastNodeSequenceId"), -1) if state_matches else -1
        remaining_nodes = {
            _safe_int(item.get("sequenceId"), -1): item
            for item in state.get("nodeStates") or []
            if isinstance(item, Mapping)
        }
        remaining_edges = {
            _safe_int(item.get("sequenceId"), -1): item
            for item in state.get("edgeStates") or []
            if isinstance(item, Mapping)
        }
        next_node_seq = min(remaining_nodes.keys(), default=None)
        steps: List[Dict[str, Any]] = []
        for node in mission["nodes"]:
            seq = int(node["sequenceId"])
            if state_matches and seq <= last_seq:
                phase = "completed"
            elif seq == next_node_seq and status in {"RUNNING", "PAUSED", "ACCEPTED", "RETRIABLE"}:
                # While traversing the preceding edge, that edge is the active
                # element and the destination node remains upcoming.
                preceding_edge_pending = (seq - 1) in remaining_edges
                phase = (
                    "upcoming"
                    if preceding_edge_pending and status in {"RUNNING", "PAUSED"}
                    else "active"
                )
            elif status in {"FINISHED", "CANCELLED"}:
                phase = "completed" if status == "FINISHED" else "cancelled"
            else:
                phase = "upcoming"
            steps.append(
                {
                    "kind": "node",
                    "id": node["nodeId"],
                    "sequence_id": seq,
                    "label": node.get("nodeDescriptor") or node["nodeId"],
                    "phase": phase,
                }
            )
            edge_seq = seq + 1
            edge = next(
                (item for item in mission["edges"] if int(item["sequenceId"]) == edge_seq),
                None,
            )
            if edge:
                if state_matches and edge_seq <= last_seq:
                    edge_phase = "completed"
                elif edge_seq in remaining_edges and next_node_seq == edge_seq + 1:
                    edge_phase = "active" if status in {"RUNNING", "PAUSED"} else "upcoming"
                else:
                    edge_phase = "upcoming"
                steps.append(
                    {
                        "kind": "edge",
                        "id": edge["edgeId"],
                        "sequence_id": edge_seq,
                        "label": edge.get("edgeDescriptor") or "Travel",
                        "phase": edge_phase,
                    }
                )

        actions = []
        if state_matches:
            for item in state.get("actionStates") or []:
                if isinstance(item, Mapping):
                    actions.append(dict(item))
        return {
            **{key: value for key, value in mission.items() if key not in {"nodes", "edges"}},
            "steps": steps,
            "actions": actions,
            "last_node_sequence_id": last_seq,
        }

    def _refresh_events(self, devices: Mapping[str, Mapping[str, Any]]) -> None:
        for target, device in devices.items():
            signature = (
                device.get("connection"),
                device.get("operating_mode"),
                device.get("driving"),
                device.get("paused"),
                device.get("safety", {}).get("active_emergency_stop"),
                tuple((err.get("type"), err.get("level")) for err in device.get("errors", [])),
            )
            old = self._last_signature.get(target)
            if old is not None and old != signature:
                self._add_event(
                    "WARNING"
                    if device.get("safety", {}).get("active_emergency_stop") not in {None, "NONE"}
                    else "INFO",
                    target,
                    "Device state changed",
                    code="DEVICE_STATE_CHANGED",
                    details={
                        "connection": device.get("connection"),
                        "operating_mode": device.get("operating_mode"),
                        "driving": device.get("driving"),
                        "paused": device.get("paused"),
                    },
                )
            self._last_signature[target] = signature

    # ------------------------------------------------------------------
    # VDA orders
    def _make_waypoint_order(
        self, waypoint_name: str, waypoint_cfg: Mapping[str, Any], state: Mapping[str, Any]
    ) -> Dict[str, Any]:
        waypoint = waypoint_cfg["waypoints"].get(waypoint_name)
        if waypoint is None:
            raise KeyError(waypoint_name)
        position = state.get("mobileRobotPosition") or {}
        if self.require_localized and not position:
            raise ValueError("ROX-Diff has no mobileRobotPosition")
        if self.require_localized and not bool(position.get("localized", False)):
            raise ValueError("ROX-Diff is not localized")
        map_id = str(waypoint_cfg["map_id"])
        current_map = str(position.get("mapId") or map_id)
        if current_map != map_id:
            raise ValueError(
                f"ROX-Diff state mapId={current_map!r}, waypoint mapId={map_id!r}"
            )

        order_id = str(uuid4())
        short_id = order_id.split("-")[0]
        current_node_id = f"temporary-current-{short_id}"
        target_node_id = f"waypoint-{waypoint_name}"
        current_x = _safe_float(position.get("x"), waypoint["x"])
        current_y = _safe_float(position.get("y"), waypoint["y"])
        current_theta = _safe_float(position.get("theta"), waypoint["theta"])
        return {
            "orderId": order_id,
            "orderUpdateId": 0,
            "orderDescription": f"Navigate ROX-Diff to waypoint {waypoint_name}",
            "nodes": [
                {
                    "nodeId": current_node_id,
                    "sequenceId": 0,
                    "nodeDescriptor": "Current robot pose (temporary start node)",
                    "released": True,
                    "nodePosition": {
                        "x": current_x,
                        "y": current_y,
                        "theta": current_theta,
                        "mapId": map_id,
                        "allowedDeviationXY": {
                            "a": self.start_tolerance_m,
                            "b": self.start_tolerance_m,
                            "theta": 0.0,
                        },
                        "allowedDeviationTheta": 3.141592653589793,
                    },
                    "actions": [],
                },
                {
                    "nodeId": target_node_id,
                    "sequenceId": 2,
                    "nodeDescriptor": waypoint["label"],
                    "released": True,
                    "nodePosition": {
                        "x": waypoint["x"],
                        "y": waypoint["y"],
                        "theta": waypoint["theta"],
                        "mapId": map_id,
                        "allowedDeviationXY": {
                            "a": waypoint["allowed_deviation_xy"],
                            "b": waypoint["allowed_deviation_xy"],
                            "theta": 0.0,
                        },
                        "allowedDeviationTheta": waypoint[
                            "allowed_deviation_theta"
                        ],
                    },
                    "actions": [],
                },
            ],
            "edges": [
                {
                    "edgeId": f"edge-{short_id}-to-{waypoint_name}",
                    "sequenceId": 1,
                    "edgeDescriptor": f"Navigate to {waypoint['label']}",
                    "released": True,
                    "actions": [],
                }
            ],
        }

    def _dispatch_waypoint(
        self, waypoint_name: str, *, source: str = "waypoint", scenario_id: str = ""
    ) -> Dict[str, Any]:
        waypoint_cfg = self._load_waypoints()
        target_cache = self._copy_target_state("rox")
        reasons = self._dispatch_reasons("rox", target_cache, waypoint_cfg)
        if reasons:
            raise RuntimeError("; ".join(reasons))
        state = target_cache.get("last_state") or {}
        order = self._make_waypoint_order(waypoint_name, waypoint_cfg, state)
        waypoint = waypoint_cfg["waypoints"][waypoint_name]
        mission = {
            "mission_id": str(uuid4()),
            "order_id": order["orderId"],
            "target": "rox",
            "source": source,
            "scenario_id": scenario_id,
            "waypoint": waypoint_name,
            "label": waypoint["label"],
            "description": waypoint["description"],
            "created_at": _utc_now(),
            "created_epoch": time.time(),
            "updated_at": _utc_now(),
            "status": "SENT",
            "cancel_requested": False,
            "nodes": copy.deepcopy(order["nodes"]),
            "edges": copy.deepcopy(order["edges"]),
        }
        self.publish_order(order, target="rox")
        with self.lock:
            self.missions.append(mission)
        self._add_event(
            "INFO",
            "rox",
            f"Dispatched waypoint {waypoint['label']}",
            code="ORDER_SENT",
            details={"order_id": order["orderId"], "waypoint": waypoint_name},
        )
        return mission

    def _find_mission(self, order_id: str) -> Optional[Dict[str, Any]]:
        with self.lock:
            for mission in reversed(self.missions):
                if mission["order_id"] == order_id:
                    return mission
        return None

    def _mark_current_cancel_requested(self, target: str) -> None:
        target_cache = self._copy_target_state(target)
        state = target_cache.get("last_state") or {}
        order_id = str(state.get("orderId", ""))
        mission = self._find_mission(order_id)
        if mission:
            mission["cancel_requested"] = True
            mission["status"] = "CANCELLING"
        with self.lock:
            if self.active_scenario and self.active_scenario.get("status") in {
                "RUNNING",
                "PAUSED",
            }:
                self.active_scenario["status"] = "CANCELLING"
                self.active_scenario["stop_requested"] = True

    # ------------------------------------------------------------------
    # Scenarios
    def _scenario_worker(self) -> None:
        while not self._stop.wait(0.75):
            try:
                self._advance_scenario()
            except Exception as exc:  # keep UI alive after any scenario exception
                self._add_event(
                    "ERROR",
                    "scenario",
                    f"Scenario engine error: {exc}",
                    code="SCENARIO_ENGINE_ERROR",
                )
                with self.lock:
                    if self.active_scenario:
                        self.active_scenario["status"] = "FAILED"
                        self.active_scenario["error"] = str(exc)

    def _advance_scenario(self) -> None:
        with self.lock:
            scenario = copy.deepcopy(self.active_scenario)
        if not scenario or scenario.get("status") not in {"RUNNING", "CANCELLING"}:
            return
        if scenario.get("stop_requested"):
            if not scenario.get("active_order_id"):
                with self.lock:
                    if self.active_scenario:
                        self.active_scenario["status"] = "CANCELLED"
            return

        active_order_id = scenario.get("active_order_id")
        if active_order_id:
            mission = self._find_mission(active_order_id)
            if not mission:
                return
            state = (self._copy_target_state("rox").get("last_state") or {})
            status = self._mission_status(mission, state)
            mission["status"] = status
            if status == "FINISHED":
                with self.lock:
                    if self.active_scenario:
                        self.active_scenario["completed_steps"] += 1
                        self.active_scenario["active_order_id"] = None
                        self.active_scenario["active_waypoint"] = None
                        self.active_scenario["updated_at"] = _utc_now()
                return
            if status in {"FAILED", "REJECTED", "CANCELLED"}:
                with self.lock:
                    if self.active_scenario:
                        self.active_scenario["status"] = status
                        self.active_scenario["error"] = (
                            f"Step {scenario.get('active_waypoint')} ended as {status}"
                        )
                return
            return

        step_index = int(scenario.get("completed_steps", 0))
        steps = scenario.get("waypoints") or []
        if step_index >= len(steps):
            with self.lock:
                if self.active_scenario:
                    self.active_scenario["status"] = "FINISHED"
                    self.active_scenario["finished_at"] = _utc_now()
            self._add_event(
                "INFO",
                "scenario",
                f"Scenario {scenario['label']} finished",
                code="SCENARIO_FINISHED",
            )
            return

        waypoint_name = str(steps[step_index])
        try:
            mission = self._dispatch_waypoint(
                waypoint_name,
                source="scenario",
                scenario_id=str(scenario["id"]),
            )
        except RuntimeError as exc:
            # A transient active-order/state delay is normal between state messages.
            if "Another VDA order is active" in str(exc):
                return
            raise
        with self.lock:
            if self.active_scenario:
                self.active_scenario["active_order_id"] = mission["order_id"]
                self.active_scenario["active_waypoint"] = waypoint_name
                self.active_scenario["updated_at"] = _utc_now()

    # ------------------------------------------------------------------
    # API
    def _register_routes(self) -> None:
        app = self.app

        @app.get("/api/dashboard")
        def dashboard_snapshot():
            return jsonify(_json_safe(self.snapshot()))

        @app.get("/api/waypoints")
        def waypoints_endpoint():
            cfg = self._load_waypoints()
            return jsonify(cfg)

        @app.post("/api/waypoints/<waypoint_name>/dispatch")
        def waypoint_dispatch_endpoint(waypoint_name: str):
            try:
                mission = self._dispatch_waypoint(waypoint_name)
            except KeyError:
                abort(404, f"Unknown waypoint {waypoint_name!r}")
            except RuntimeError as exc:
                abort(409, str(exc))
            except ValueError as exc:
                abort(400, str(exc))
            return jsonify({"ok": True, "mission": mission}), 202

        @app.post("/api/controls/<target>/<action>")
        def controls_endpoint(target: str, action: str):
            if target not in self.targets:
                abort(404, f"Unknown target {target!r}")
            enabled = self.rox_enabled if target == "rox" else self.crane_enabled
            if not enabled:
                abort(409, f"{target} is marked unavailable")
            action_map = {
                "pause": "startPause",
                "resume": "stopPause",
                "cancel": "cancelOrder",
                "factsheet": "factsheetRequest",
                "retry": "retry",
                "skip-retry": "skipRetry",
            }
            action_type = action_map.get(action)
            if action_type is None:
                abort(404, f"Unsupported dashboard control {action!r}")
            params: Optional[List[Dict[str, Any]]] = None
            state = self._copy_target_state(target).get("last_state") or {}
            if action == "pause":
                if not self._active_order(state):
                    abort(409, "No active order to pause")
                if bool(state.get("paused", False)):
                    abort(409, "Order execution is already paused")
            elif action == "resume":
                if not bool(state.get("paused", False)):
                    abort(409, "Order execution is not paused")
            elif action == "cancel":
                order_id = str(state.get("orderId", ""))
                if not self._active_order(state):
                    abort(409, "No active order to cancel")
                self._mark_current_cancel_requested(target)
                if order_id:
                    params = self.kv_params({"orderId": order_id})
            elif action in {"retry", "skip-retry"}:
                retriable = [
                    str(item.get("actionId"))
                    for item in state.get("actionStates") or []
                    if isinstance(item, Mapping)
                    and str(item.get("actionStatus")) == "RETRIABLE"
                    and item.get("actionId")
                ]
                requested_id = str((request.get_json(silent=True) or {}).get("actionId", ""))
                action_id_to_use = requested_id or (retriable[0] if len(retriable) == 1 else "")
                if not action_id_to_use:
                    abort(409, "Select one RETRIABLE order action")
                if action_id_to_use not in retriable:
                    abort(409, f"Action {action_id_to_use!r} is not currently RETRIABLE")
                params = self.kv_params({"actionId": action_id_to_use})
            try:
                action_id = self.publish_instant(
                    action_type, target=target, params=params
                )
            except HTTPException:
                raise
            except Exception as exc:
                abort(500, str(exc))
            control = {
                "action_id": action_id,
                "action_type": action_type,
                "target": target,
                "created_at": _utc_now(),
                "status": "SENT",
            }
            with self.lock:
                self.controls.append(control)
                if self.active_scenario:
                    if action == "pause" and self.active_scenario.get("status") == "RUNNING":
                        self.active_scenario["status"] = "PAUSED"
                    elif action == "resume" and self.active_scenario.get("status") == "PAUSED":
                        self.active_scenario["status"] = "RUNNING"
                    self.active_scenario["updated_at"] = _utc_now()
            self._add_event(
                "WARNING" if action == "cancel" else "INFO",
                target,
                f"Sent {action_type} instant action",
                code="INSTANT_ACTION_SENT",
                details={"action_id": action_id},
            )
            return jsonify({"ok": True, "control": control}), 202

        @app.post("/api/scenarios/<scenario_id>/start")
        def scenario_start_endpoint(scenario_id: str):
            waypoint_cfg = self._load_waypoints()
            scenarios = self._load_scenarios(waypoint_cfg["waypoints"])
            cfg = scenarios.get(scenario_id)
            if cfg is None:
                abort(404, f"Unknown scenario {scenario_id!r}")
            if not bool(cfg.get("enabled", False)):
                abort(409, str(cfg.get("disabled_reason") or "Scenario is disabled"))
            if cfg.get("target") != "rox":
                abort(409, "Only ROX-only scenarios are enabled while the crane is unavailable")
            target_cache = self._copy_target_state("rox")
            reasons = self._dispatch_reasons("rox", target_cache, waypoint_cfg)
            if reasons:
                abort(409, "; ".join(reasons))
            with self.lock:
                if self.active_scenario and self.active_scenario.get("status") in {
                    "RUNNING",
                    "PAUSED",
                    "CANCELLING",
                }:
                    abort(409, "Another scenario is already active")
                self.active_scenario = {
                    "id": scenario_id,
                    "run_id": str(uuid4()),
                    "label": cfg["label"],
                    "description": cfg["description"],
                    "waypoints": list(cfg["waypoints"]),
                    "status": "RUNNING",
                    "completed_steps": 0,
                    "active_order_id": None,
                    "active_waypoint": None,
                    "stop_requested": False,
                    "started_at": _utc_now(),
                    "updated_at": _utc_now(),
                }
            self._add_event(
                "INFO",
                "scenario",
                f"Started scenario {cfg['label']}",
                code="SCENARIO_STARTED",
            )
            return jsonify({"ok": True, "scenario": self.active_scenario}), 202

        @app.post("/api/scenarios/active/stop")
        def scenario_stop_endpoint():
            with self.lock:
                if not self.active_scenario or self.active_scenario.get("status") not in {
                    "RUNNING",
                    "PAUSED",
                    "CANCELLING",
                }:
                    abort(409, "No active scenario")
                self.active_scenario["stop_requested"] = True
                self.active_scenario["status"] = "CANCELLING"
            state = self._copy_target_state("rox").get("last_state") or {}
            if self._active_order(state):
                self._mark_current_cancel_requested("rox")
                order_id = str(state.get("orderId", ""))
                params = self.kv_params({"orderId": order_id}) if order_id else None
                self.publish_instant("cancelOrder", target="rox", params=params)
            else:
                with self.lock:
                    if self.active_scenario:
                        self.active_scenario["status"] = "CANCELLED"
            self._add_event(
                "WARNING",
                "scenario",
                "Scenario stop requested",
                code="SCENARIO_STOP_REQUESTED",
            )
            return jsonify({"ok": True}), 202

        @app.post("/api/events/clear")
        def clear_events_endpoint():
            with self.lock:
                self.events.clear()
            self._add_event("INFO", "server", "Event log cleared", code="EVENTS_CLEARED")
            return jsonify({"ok": True})

        @app.get("/healthz")
        def health_endpoint():
            mqtt_ok = self._mqtt_connected()
            return (
                jsonify(
                    {
                        "ok": mqtt_ok,
                        "service": "vda5050-master-control",
                        "mqtt_connected": mqtt_ok,
                        "protocol_version": self.protocol_version,
                        "uptime_s": time.monotonic() - self.started_monotonic,
                    }
                ),
                200 if mqtt_ok else 503,
            )

    def _control_projection(self, rox_state: Mapping[str, Any]) -> List[Dict[str, Any]]:
        instant_states = {
            str(item.get("actionId")): item
            for item in rox_state.get("instantActionStates") or []
            if isinstance(item, Mapping)
        }
        result: List[Dict[str, Any]] = []
        with self.lock:
            controls = list(self.controls)
        for control in controls[-20:]:
            item = instant_states.get(control["action_id"])
            projected = dict(control)
            if item:
                projected["status"] = item.get("actionStatus", "UNKNOWN")
                projected["result"] = item.get("actionResult", "")
            result.append(projected)
        return result

    def snapshot(self) -> Dict[str, Any]:
        try:
            waypoint_cfg = self._load_waypoints()
            waypoint_error = None
        except Exception as exc:
            waypoint_cfg = {"map_id": self.default_map_id, "configured": False, "waypoints": {}}
            waypoint_error = str(exc)
        scenarios = self._load_scenarios(waypoint_cfg["waypoints"])
        caches = {target: self._copy_target_state(target) for target in self.targets}
        devices = {
            target: self._device_projection(target, cache, waypoint_cfg)
            for target, cache in caches.items()
        }
        self._refresh_events(devices)
        rox_state = caches.get("rox", {}).get("last_state") or {}
        with self.lock:
            missions_raw = list(self.missions)
        missions = [
            self._mission_projection(mission, rox_state)
            if mission["target"] == "rox"
            else dict(mission)
            for mission in missions_raw
        ]
        current = next(
            (mission for mission in reversed(missions) if mission["status"] in ACTIVE_MISSION_STATES),
            None,
        )
        recent = list(reversed(missions[-10:]))

        waypoint_rows = []
        for name, waypoint in waypoint_cfg["waypoints"].items():
            status = "IDLE"
            mission = next(
                (item for item in reversed(missions) if item.get("waypoint") == name),
                None,
            )
            if mission:
                status = mission["status"]
            waypoint_rows.append(
                {
                    **waypoint,
                    "map_id": waypoint_cfg["map_id"],
                    "configured": waypoint_cfg["configured"],
                    "status": status,
                    "dispatch_ready": devices.get("rox", {}).get("dispatch_ready", False),
                    "disabled_reasons": devices.get("rox", {}).get("dispatch_reasons", []),
                }
            )

        with self.lock:
            events = list(reversed(self.events))
            active_scenario = copy.deepcopy(self.active_scenario)
        if active_scenario:
            count = len(active_scenario.get("waypoints") or [])
            completed = int(active_scenario.get("completed_steps", 0))
            active_scenario["progress_percent"] = (
                round((completed / count) * 100.0, 1) if count else 0.0
            )
            active_scenario["steps"] = [
                {
                    "index": index,
                    "waypoint": name,
                    "phase": (
                        "completed"
                        if index < completed
                        else "active"
                        if index == completed and active_scenario.get("status") in {"RUNNING", "CANCELLING"}
                        else "upcoming"
                    ),
                }
                for index, name in enumerate(active_scenario.get("waypoints") or [])
            ]

        rox_device = devices.get("rox", {})
        retriable_ids = list(rox_device.get("retriable_action_ids") or [])
        control_availability = {
            "pause": bool(rox_device.get("enabled"))
            and bool(rox_device.get("online"))
            and bool(rox_device.get("active_order"))
            and not bool(rox_device.get("paused")),
            "resume": bool(rox_device.get("enabled"))
            and bool(rox_device.get("online"))
            and bool(rox_device.get("paused")),
            "cancel": bool(rox_device.get("enabled"))
            and bool(rox_device.get("online"))
            and bool(rox_device.get("active_order")),
            "factsheet": bool(rox_device.get("enabled")) and bool(rox_device.get("online")),
            "retry": bool(retriable_ids),
            "skip_retry": bool(retriable_ids),
            "retriable_action_ids": retriable_ids,
        }

        return {
            "generated_at": _utc_now(),
            "server": {
                "status": "ONLINE",
                "mqtt_connected": self._mqtt_connected(),
                "broker": f"{self.broker_host}:{self.broker_port}",
                "protocol": f"VDA 5050 {self.protocol_version}",
                "uptime_s": round(time.monotonic() - self.started_monotonic, 1),
                "waypoint_file": str(self.waypoint_path),
                "waypoint_error": waypoint_error,
                "map_id": waypoint_cfg["map_id"],
                "waypoints_configured": waypoint_cfg["configured"],
            },
            "devices": devices,
            "waypoints": waypoint_rows,
            "scenarios": list(scenarios.values()),
            "active_scenario": active_scenario,
            "mission": current,
            "missions": recent,
            "controls": self._control_projection(rox_state),
            "control_availability": control_availability,
            "events": events[: self.event_limit],
            "capabilities": {
                "pause": True,
                "resume": True,
                "cancel": True,
                "factsheet": True,
                "retry": True,
                "skip_retry": True,
                "dynamic_waypoint_orders": True,
                "scenario_queue": True,
                "crane_available": self.crane_enabled,
                "order_updates": False,
                "edge_actions": False,
                "zones": False,
            },
        }


def register_dashboard(app: Any, ctx: MutableMapping[str, Any]) -> DashboardController:
    """Register dashboard API routes once and return the controller instance."""
    existing = app.extensions.get("vda5050_dashboard")
    if existing is not None:
        return existing
    controller = DashboardController(app, ctx)
    app.extensions["vda5050_dashboard"] = controller
    return controller
