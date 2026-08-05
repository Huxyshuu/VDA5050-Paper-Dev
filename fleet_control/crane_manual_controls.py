"""Flask API for supervised manual Ilmatar crane positioning.

The module deliberately publishes normal VDA 5050 orders and instant actions;
it never talks to OPC UA directly.  All coordinates come from the same
configs/crane_waypoints.yaml used to generate the coordinated crane order.
"""
from __future__ import annotations

import copy
import math
import os
import re
import time
from pathlib import Path
from typing import Any, Dict, List, Mapping, MutableMapping, Optional, Tuple
from uuid import uuid4

import yaml
from flask import abort, jsonify

ACTIVE_ACTION_STATES = {"WAITING", "INITIALIZING", "RUNNING", "PAUSED"}
TRUE_VALUES = {"1", "true", "yes", "on"}
HOIST_KEYS = (
    "travel_safe_m",
    "source_lower_m",
    "source_safe_lift_m",
    "handover_lower_m",
    "handover_safe_lift_m",
    "home_hoist_m",
)


def _bool_env(name: str, default: bool = False) -> bool:
    raw = os.getenv(name)
    return default if raw is None else raw.strip().lower() in TRUE_VALUES


def _finite(value: Any, label: str) -> float:
    try:
        result = float(value)
    except (TypeError, ValueError) as exc:
        raise ValueError(f"{label} must be numeric") from exc
    if not math.isfinite(result):
        raise ValueError(f"{label} must be finite")
    return result


def _load_config(path: Path) -> Dict[str, Any]:
    if not path.exists():
        raise FileNotFoundError(path)
    data = yaml.safe_load(path.read_text(encoding="utf-8")) or {}
    if not isinstance(data, Mapping):
        raise ValueError("Crane waypoint YAML root must be an object")
    waypoints = data.get("waypoints")
    hoist = data.get("hoist_positions")
    home = data.get("home")
    if not isinstance(waypoints, Mapping):
        raise ValueError("Crane waypoint YAML must contain a waypoints mapping")
    if not isinstance(hoist, Mapping):
        raise ValueError("Crane waypoint YAML must contain a hoist_positions mapping")
    if not isinstance(home, Mapping):
        raise ValueError("Crane waypoint YAML must contain a home mapping")

    result: Dict[str, Any] = {
        "map_id": str(data.get("map_id") or "map"),
        "configured": bool(data.get("configured", False)),
        "coordinate_system": str(data.get("coordinate_system") or "crane-local"),
        "waypoints": {},
        "hoist_positions": {},
        "home": {
            "bridge_m": _finite(home.get("bridge_m"), "home.bridge_m"),
            "trolley_m": _finite(home.get("trolley_m"), "home.trolley_m"),
            "hoist_m": _finite(home.get("hoist_m"), "home.hoist_m"),
        },
    }
    for name, raw in waypoints.items():
        if not isinstance(raw, Mapping):
            continue
        result["waypoints"][str(name)] = {
            "name": str(name),
            "label": str(raw.get("label") or str(name).replace("_", " ").title()),
            "description": str(raw.get("description") or "Crane bridge/trolley destination"),
            "bridge_m": _finite(raw.get("bridge_m"), f"waypoints.{name}.bridge_m"),
            "trolley_m": _finite(raw.get("trolley_m"), f"waypoints.{name}.trolley_m"),
        }
    for key, value in hoist.items():
        result["hoist_positions"][str(key)] = _finite(value, f"hoist_positions.{key}")
    result["hoist_positions"]["home_hoist_m"] = result["home"]["hoist_m"]
    return result


def _extract_hoist_m(state: Mapping[str, Any]) -> Optional[float]:
    for item in state.get("information") or []:
        if not isinstance(item, Mapping) or str(item.get("infoType")) != "HOIST_POSITION":
            continue
        descriptor = str(item.get("infoDescriptor") or item.get("infoDescription") or "")
        match = re.search(r"(-?\d+(?:\.\d+)?)\s*m\b", descriptor)
        if match:
            return float(match.group(1))
    return None


def _extract_watchdog_fault(state: Mapping[str, Any]) -> Optional[bool]:
    for item in state.get("information") or []:
        if not isinstance(item, Mapping) or str(item.get("infoType")) != "WATCHDOG_FAULT":
            continue
        for ref in item.get("infoReferences") or []:
            if not isinstance(ref, Mapping):
                continue
            if str(ref.get("referenceKey")) == "value":
                value = str(ref.get("referenceValue", "")).strip().lower()
                if value in {"true", "1", "yes", "on"}:
                    return True
                if value in {"false", "0", "no", "off"}:
                    return False
    mode = str(state.get("operatingMode", ""))
    if mode:
        return mode != "AUTOMATIC"
    return None


def _active_order(state: Mapping[str, Any]) -> bool:
    if state.get("nodeStates") or state.get("edgeStates"):
        return True
    return any(
        str(item.get("actionStatus")) in ACTIVE_ACTION_STATES
        for item in state.get("actionStates") or []
        if isinstance(item, Mapping)
    )


def _copy_crane_cache(ctx: MutableMapping[str, Any]) -> Dict[str, Any]:
    lock = ctx["STATE_LOCK"]
    with lock:
        return copy.deepcopy(ctx["STATE"].get("crane", {}))


def _state_age(cache: Mapping[str, Any]) -> Optional[float]:
    received = cache.get("last_state_received_at")
    if isinstance(received, (float, int)):
        return max(0.0, time.time() - float(received))
    return None


def _readiness(ctx: MutableMapping[str, Any], cfg: Mapping[str, Any]) -> Tuple[List[str], Dict[str, Any]]:
    cache = _copy_crane_cache(ctx)
    state = cache.get("last_state") or {}
    connection = cache.get("connection") or {}
    reasons: List[str] = []
    if not _bool_env("CRANE_ENABLED", False):
        reasons.append("CRANE_ENABLED is not true")
    if str(connection.get("connectionState", "")) != "ONLINE":
        reasons.append("Crane VDA connection is not ONLINE")
    if not state:
        reasons.append("No crane VDA state has been received")
    else:
        age = _state_age(cache)
        max_age = float(os.getenv("FLEET_UI_STATE_STALE_S", "35"))
        if age is not None and age > max_age:
            reasons.append(f"Crane state is stale ({age:.1f} s)")
        if str(state.get("operatingMode", "")) != "AUTOMATIC":
            reasons.append(
                f"Crane operating mode {state.get('operatingMode') or 'UNKNOWN'} is not AUTOMATIC"
            )
        safety = state.get("safetyState") or {}
        if str(safety.get("activeEmergencyStop", "NONE")) != "NONE":
            reasons.append("Crane emergency stop is active")
        if bool(safety.get("fieldViolation", False)):
            reasons.append("Crane safety field violation is active")
        if _active_order(state):
            reasons.append("Another crane VDA order is active")
    if not cfg.get("configured") and not _bool_env("CRANE_ALLOW_UNVERIFIED_MANUAL", False):
        reasons.append(
            "Crane waypoint file is not verified; set configured: true after no-load testing, "
            "or temporarily set CRANE_ALLOW_UNVERIFIED_MANUAL=true for supervised commissioning"
        )
    return reasons, {"cache": cache, "state": state, "connection": connection}


def _action(action_type: str, key: str, value: float) -> Dict[str, Any]:
    return {
        "actionId": f"manual-{action_type}-{uuid4()}",
        "actionType": action_type,
        "blockingType": "HARD",
        "actionParameters": [{"key": key, "value": value}],
    }


def _base_position(state: Mapping[str, Any], map_id: str) -> Tuple[float, float]:
    position = state.get("mobileRobotPosition") or {}
    try:
        x = _finite(position.get("x"), "current bridge position")
        y = _finite(position.get("y"), "current trolley position")
    except ValueError as exc:
        raise RuntimeError("Crane state does not contain a usable bridge/trolley position") from exc
    state_map = str(position.get("mapId") or map_id)
    if state_map != map_id:
        raise RuntimeError(f"Crane state mapId={state_map!r}, configured mapId={map_id!r}")
    return x, y


def _build_xy_order(
    cfg: Mapping[str, Any], state: Mapping[str, Any], destination_name: str
) -> Dict[str, Any]:
    map_id = str(cfg["map_id"])
    current_x, current_y = _base_position(state, map_id)
    if destination_name == "home":
        destination = {
            "label": "Crane home XY",
            "bridge_m": cfg["home"]["bridge_m"],
            "trolley_m": cfg["home"]["trolley_m"],
        }
    else:
        destination = cfg["waypoints"].get(destination_name)
        if destination is None:
            raise KeyError(destination_name)

    current_hoist = _extract_hoist_m(state)
    travel_safe = cfg["hoist_positions"].get("travel_safe_m")
    start_actions: List[Dict[str, Any]] = []
    if travel_safe is not None:
        if current_hoist is None:
            raise RuntimeError("Crane state does not contain HOIST_POSITION telemetry")
        # In this installation, a larger absolute hoist value is higher.  Do not
        # lower an already-higher hook merely to match the minimum safe height.
        if current_hoist + 0.005 < float(travel_safe):
            start_actions.append(_action("raiseHoist", "zu", float(travel_safe)))

    order_id = str(uuid4())
    short_id = order_id.split("-")[0]
    return {
        "orderId": order_id,
        "orderUpdateId": 0,
        "orderDescription": f"Manual crane move to {destination_name}",
        "nodes": [
            {
                "nodeId": f"manual-current-{short_id}",
                "sequenceId": 0,
                "released": True,
                "nodeDescriptor": "Current crane bridge/trolley position",
                "nodePosition": {"x": current_x, "y": current_y, "mapId": map_id},
                "actions": start_actions,
            },
            {
                "nodeId": f"manual-{destination_name}-{short_id}",
                "sequenceId": 2,
                "released": True,
                "nodeDescriptor": str(destination["label"]),
                "nodePosition": {
                    "x": float(destination["bridge_m"]),
                    "y": float(destination["trolley_m"]),
                    "mapId": map_id,
                },
                "actions": [],
            },
        ],
        "edges": [
            {
                "edgeId": f"manual-edge-{short_id}",
                "sequenceId": 1,
                "released": True,
                "edgeDescriptor": f"Move crane to {destination['label']}",
                "actions": [],
            }
        ],
    }


def _build_hoist_order(
    cfg: Mapping[str, Any], state: Mapping[str, Any], height_name: str
) -> Dict[str, Any]:
    map_id = str(cfg["map_id"])
    current_x, current_y = _base_position(state, map_id)
    positions = cfg["hoist_positions"]
    if height_name not in positions:
        raise KeyError(height_name)
    current = _extract_hoist_m(state)
    if current is None:
        raise RuntimeError("Crane state does not contain HOIST_POSITION telemetry")
    target = float(positions[height_name])
    action_type, key = ("raiseHoist", "zu") if target >= current else ("lowerHoist", "zd")
    order_id = str(uuid4())
    short_id = order_id.split("-")[0]
    return {
        "orderId": order_id,
        "orderUpdateId": 0,
        "orderDescription": f"Manual crane hoist move to {height_name}",
        "nodes": [
            {
                "nodeId": f"manual-hoist-{short_id}",
                "sequenceId": 0,
                "released": True,
                "nodeDescriptor": f"Move hoist to {height_name}",
                "nodePosition": {"x": current_x, "y": current_y, "mapId": map_id},
                "actions": [_action(action_type, key, target)],
            }
        ],
        "edges": [],
    }


def _projection(ctx: MutableMapping[str, Any], cfg: Mapping[str, Any]) -> Dict[str, Any]:
    reasons, live = _readiness(ctx, cfg)
    state = live["state"]
    handover = ctx["_handover_release_snapshot"]()
    position = state.get("mobileRobotPosition") or {}
    hoist_m = _extract_hoist_m(state)
    waypoints = [
        {
            **dict(item),
            "dispatch_ready": not reasons,
            "disabled_reasons": reasons,
        }
        for item in cfg["waypoints"].values()
    ]
    waypoints.append(
        {
            "name": "home",
            "label": "Crane home XY",
            "description": "Configured bridge/trolley home position",
            "bridge_m": cfg["home"]["bridge_m"],
            "trolley_m": cfg["home"]["trolley_m"],
            "dispatch_ready": not reasons,
            "disabled_reasons": reasons,
        }
    )
    labels = {
        "travel_safe_m": "Safe travel height",
        "source_lower_m": "Source pickup height",
        "source_safe_lift_m": "Source clear height",
        "handover_lower_m": "ROX handover height",
        "handover_safe_lift_m": "Handover clear height",
        "home_hoist_m": "Home hoist",
    }
    heights = [
        {
            "name": key,
            "label": labels.get(key, key.replace("_", " ").title()),
            "height_m": value,
            "dispatch_ready": not reasons,
            "disabled_reasons": reasons,
        }
        for key, value in cfg["hoist_positions"].items()
        if key in labels
    ]
    return {
        "map_id": cfg["map_id"],
        "configured": cfg["configured"],
        "allow_unverified_manual": _bool_env("CRANE_ALLOW_UNVERIFIED_MANUAL", False),
        "ready": not reasons,
        "reasons": reasons,
        "connection": str(live["connection"].get("connectionState", "UNKNOWN")),
        "operating_mode": str(state.get("operatingMode", "UNKNOWN")),
        "active_order": _active_order(state),
        "position": {
            "bridge_m": position.get("x"),
            "trolley_m": position.get("y"),
            "hoist_m": hoist_m,
        },
        "watchdog_fault": _extract_watchdog_fault(state),
        "handover": handover,
        "waypoints": waypoints,
        "hoist_positions": heights,
        "controls": {
            "home_all": not reasons,
            "home_xy": not reasons,
            "home_hoist": not reasons,
            "pause": bool(state) and _active_order(state) and not bool(state.get("paused")),
            "resume": bool(state) and bool(state.get("paused")),
            "cancel": bool(state) and _active_order(state),
            "factsheet": str(live["connection"].get("connectionState", "")) == "ONLINE",
            "release_handover": bool(handover.get("ready")),
        },
    }


def register_crane_manual_controls(app: Any, ctx: MutableMapping[str, Any]) -> None:
    """Register routes once. Safe to call repeatedly."""
    if app.extensions.get("crane_manual_controls"):
        return
    repo_root = Path(ctx.get("REPO_ROOT") or Path(__file__).resolve().parents[1])
    waypoint_path = Path(
        os.getenv("CRANE_WAYPOINT_FILE", "configs/crane_waypoints.yaml")
    ).expanduser()
    if not waypoint_path.is_absolute():
        waypoint_path = repo_root / waypoint_path

    publish_order = ctx["_publish_order"]
    publish_instant = ctx["_publish_instant_action"]
    release_handover = ctx["_release_crane_handover"]
    kv_params = ctx["_kv_params"]

    @app.get("/api/crane/manual")
    def crane_manual_snapshot():
        try:
            cfg = _load_config(waypoint_path)
            return jsonify(_projection(ctx, cfg))
        except (FileNotFoundError, ValueError) as exc:
            abort(409, str(exc))

    @app.post("/api/crane/manual/waypoints/<destination_name>/dispatch")
    def crane_manual_waypoint_dispatch(destination_name: str):
        try:
            cfg = _load_config(waypoint_path)
            reasons, live = _readiness(ctx, cfg)
            if reasons:
                abort(409, "; ".join(reasons))
            order = _build_xy_order(cfg, live["state"], destination_name)
            publish_order(order, target="crane")
            return jsonify(
                {
                    "ok": True,
                    "target": "crane",
                    "kind": "waypoint",
                    "name": destination_name,
                    "orderId": order["orderId"],
                }
            ), 202
        except KeyError:
            abort(404, f"Unknown crane destination {destination_name!r}")
        except (FileNotFoundError, ValueError, RuntimeError) as exc:
            abort(409, str(exc))

    @app.post("/api/crane/manual/hoist/<height_name>/dispatch")
    def crane_manual_hoist_dispatch(height_name: str):
        try:
            cfg = _load_config(waypoint_path)
            reasons, live = _readiness(ctx, cfg)
            if reasons:
                abort(409, "; ".join(reasons))
            order = _build_hoist_order(cfg, live["state"], height_name)
            publish_order(order, target="crane")
            return jsonify(
                {
                    "ok": True,
                    "target": "crane",
                    "kind": "hoist",
                    "name": height_name,
                    "orderId": order["orderId"],
                }
            ), 202
        except KeyError:
            abort(404, f"Unknown crane hoist position {height_name!r}")
        except (FileNotFoundError, ValueError, RuntimeError) as exc:
            abort(409, str(exc))

    @app.post("/api/crane/manual/control/<control_name>")
    def crane_manual_control(control_name: str):
        mapping = {
            "home-all": "resetAllHome",
            "home-xy": "resetBridgeTrolley",
            "home-hoist": "resetHoist",
            "pause": "startPause",
            "resume": "stopPause",
            "cancel": "cancelOrder",
            "factsheet": "factsheetRequest",
        }
        if control_name == "release-handover":
            result = release_handover()
            if not result.get("ok"):
                abort(409, "; ".join(result.get("handover", {}).get("reasons") or ["Handover release is not ready"]))
            return jsonify(result)

        action_type = mapping.get(control_name)
        if action_type is None:
            abort(404, f"Unknown crane control {control_name!r}")

        # Cancellation and status requests must remain available even when the
        # waypoint file is temporarily invalid. They depend only on live VDA
        # state, not on calibrated coordinates.
        live_cache = _copy_crane_cache(ctx)
        state = live_cache.get("last_state") or {}
        connection = live_cache.get("connection") or {}
        if str(connection.get("connectionState", "")) != "ONLINE":
            abort(409, "Crane VDA connection is not ONLINE")
        if not state and control_name != "factsheet":
            abort(409, "No crane VDA state has been received")

        if control_name in {"home-all", "home-xy", "home-hoist"}:
            try:
                cfg = _load_config(waypoint_path)
                reasons, _ = _readiness(ctx, cfg)
            except (FileNotFoundError, ValueError) as exc:
                abort(409, str(exc))
            if reasons:
                abort(409, "; ".join(reasons))
        if control_name == "pause" and not _active_order(state):
            abort(409, "No active crane order to pause")
        if control_name == "resume" and not bool(state.get("paused", False)):
            abort(409, "Crane order is not paused")
        if control_name == "cancel" and not _active_order(state):
            abort(409, "No active crane order to cancel")
        params = None
        if control_name == "cancel":
            order_id = str(state.get("orderId", ""))
            params = kv_params({"orderId": order_id}) if order_id else None
        action_id = publish_instant(action_type, target="crane", params=params)
        return jsonify(
            {
                "ok": True,
                "target": "crane",
                "control": control_name,
                "actionId": action_id,
            }
        )

    app.extensions["crane_manual_controls"] = {
        "waypoint_path": str(waypoint_path),
    }
