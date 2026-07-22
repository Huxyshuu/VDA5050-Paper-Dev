# master_control_panel_v3.py
"""VDA 5050 v3.0 master control panel for the Ilmatar crane + Neobotix ROX-Diff handover demo.

This is a migrated version of the legacy TEST controller. It keeps the
Flask UI, MQTT publishing/subscribing, order stamping, state cache, and
handover orchestration, but updates the protocol defaults and message
normalization for VDA 5050 v3.0.0.
"""

import json
import os
import re
import threading
import time
from collections import OrderedDict
from copy import deepcopy
from datetime import datetime, timezone
from pathlib import Path
from typing import Any, Dict, List, Optional
from uuid import uuid4

import jsonschema
import paho.mqtt.client as mqtt
from flask import Flask, abort, jsonify, render_template, request
from dotenv import load_dotenv

REPO_ROOT = Path(__file__).resolve().parents[1]
ENV_FILE = Path(os.getenv("FLEET_CONTROL_ENV", REPO_ROOT / "configs" / "fleet_control.env"))
load_dotenv(ENV_FILE, override=False)

app = Flask(__name__)

# ---------------- MQTT / VDA5050 v3.0 config ----------------
BROKER_HOST = os.getenv(
    "VDA_MQTT_HOST",
    "192.168.50.115",  # This is currently the raspberry pi ip (Jul 10 2026)
)
BROKER_PORT = int(os.getenv("VDA_MQTT_PORT", "1883"))

# VDA 5050 v3.0 uses protocol version "3.0.0" in message headers and
# suggested MQTT topic roots like: vda5050/v3/<manufacturer>/<serial>/<topic>.
VDA_PROTOCOL_VERSION = os.getenv("VDA_PROTOCOL_VERSION", "3.0.0")
VDA_INTERFACE_NAME = os.getenv("VDA_INTERFACE_NAME", "vda5050")
VDA_MAJOR_VERSION = os.getenv("VDA_MAJOR_VERSION", "v3")
VDA_MQTT_QOS = int(os.getenv("VDA_MQTT_QOS", "0"))

DEFAULT_MAP_ID = os.getenv("VDA_DEFAULT_MAP_ID", "df_map")

# Explicit action IDs from the order templates. Handover decisions are made from
# VDA action lifecycle states, never from free-text information[] telemetry.
CRANE_AUTO_RELEASE_ACTION_ID = os.getenv("CRANE_AUTO_RELEASE_ACTION_ID", "action4")
CRANE_MANUAL_RELEASE_ACTION_ID = os.getenv("CRANE_MANUAL_RELEASE_ACTION_ID", "action6")
CRANE_SAFE_LIFT_ACTION_ID = os.getenv("CRANE_SAFE_LIFT_ACTION_ID", "action7")
ROX_HOLD_ACTION_ID = os.getenv("ROX_HOLD_ACTION_ID", "rox_hold_at_crane")
MANUAL_RELEASE_TTL_S = float(os.getenv("MANUAL_RELEASE_TTL_S", "180"))

# Display-only crane telemetry parser. VDA information[] is not used for
# orchestration or safety decisions.
_HOIST_NUM_RE = re.compile(r"([-+]?\d+(?:\.\d+)?)")
# --------------------------------------------------------

SCHEMA_DIR = _schema_dir_raw = os.getenv(
    "VDA_SCHEMA_DIR", str(REPO_ROOT / "schemas" / "vda5050_v3")
)
_schema_dir_path = Path(_schema_dir_raw).expanduser()
if not _schema_dir_path.is_absolute():
    _schema_dir_path = REPO_ROOT / _schema_dir_path
SCHEMA_DIR = str(_schema_dir_path)


def _schema_path(env_name: str, filename: str) -> str:
    value = os.getenv(env_name, str(_schema_dir_path / filename))
    path = Path(value).expanduser()
    if not path.is_absolute():
        path = REPO_ROOT / path
    return str(path)


ORDER_SCHEMA_PATH = _schema_path("VDA_ORDER_SCHEMA_PATH", "order.schema")
IA_SCHEMA_PATH = _schema_path("VDA_INSTANT_ACTIONS_SCHEMA_PATH", "instantActions.schema")
STATE_SCHEMA_PATH = _schema_path("VDA_STATE_SCHEMA_PATH", "state.schema")
CONNECTION_SCHEMA_PATH = _schema_path("VDA_CONNECTION_SCHEMA_PATH", "connection.schema")
FACTSHEET_SCHEMA_PATH = _schema_path("VDA_FACTSHEET_SCHEMA_PATH", "factsheet.schema")

# Which crane node pairs with which ROX-Diff node for handover
# (add more pairs as needed)
RENDEZVOUS = [
    {
        "crane_node": os.getenv("CRANE_HANDOVER_NODE_ID", "node2"),
        "rox_node": os.getenv("ROX_HANDOVER_NODE_ID", "node2"),
        "tag": os.getenv("HANDOVER_TAG", "DROP_1"),
    },
]

# We index orders we publish, so we can resolve actionId -> nodeId later
ORDER_BOOK = {
    "crane": {"action2node": {}, "orderId": None},
    "rox": {"action2node": {}, "orderId": None},
}

# --- Runtime state cache (guarded by STATE_LOCK) ---
STATE_LOCK = threading.Lock()

STATE = {
    "crane": {
        "last_state": None,
        "connection": None,
        "factsheet": None,
        "buttonpress_running_aid": None,
        "buttonpress_node": None,
        "safe_lift_action_status": None,
        "hoist_height_m": None,  # display only; never used for orchestration
    },
    "rox": {
        "last_state": None,
        "connection": None,
        "factsheet": None,
        "holdpose_running_aid": None,
        "holdpose_node": None,
    },
}

ORCH = {
    "crane_release_sent_for_action": set(),
    "manual_release": {
        "ts": 0.0,
        "bp_aid": None,
        "ttl_s": MANUAL_RELEASE_TTL_S,
        "tag": None,  # NEW: which rendezvous this press belongs to
        "rox_hold_aid": None,  # NEW: which specific holdPose we're tying to
        "rox_node": None,
    },
    "rox_releasehold_sent_for_action": set(),
}


# ---------------- Multi-mobile-robot targets ----------------
def _default_topic_root(manufacturer: str, serial: str) -> str:
    """Return the suggested VDA 5050 v3 topic root for a local broker."""
    return f"{VDA_INTERFACE_NAME}/{VDA_MAJOR_VERSION}/{manufacturer}/{serial}"


def _resolve_repo_path(value: str) -> Path:
    path = Path(value).expanduser()
    return path if path.is_absolute() else REPO_ROOT / path


def _target_config(
    prefix: str, default_manufacturer: str, default_serial: str, default_order_tpl: str
) -> Dict[str, Any]:
    """Build one target config from env vars while keeping sane v3 defaults."""
    p = prefix.upper()
    manufacturer = os.getenv(f"{p}_MANUFACTURER", default_manufacturer)
    serial = os.getenv(f"{p}_SERIAL", default_serial)
    return {
        "topic_root": os.getenv(
            f"{p}_TOPIC_ROOT", _default_topic_root(manufacturer, serial)
        ),
        "manufacturer": manufacturer,
        "serial": serial,
        "version": os.getenv(f"{p}_VERSION", VDA_PROTOCOL_VERSION),
        "order_tpl": str(_resolve_repo_path(os.getenv(f"{p}_ORDER_JSON_PATH", default_order_tpl))),
    }


TARGETS = {
    "crane": _target_config(
        "crane", "konecranes", "ilmatar_1", "examples/orders/order_ilmatar_v3.json"
    ),
    "rox": _target_config("rox", "neobotix", "rox_diff_1", "examples/orders/order_rox_diff_v3.json"),
}

# HeaderId counters must be per-topic (order vs instantActions) and per-vehicle (topic root differs).
_HEADERS = {
    "crane": {"order": 0, "instantActions": 0},
    "rox": {"order": 0, "instantActions": 0},
}

# VDA 5050 v3.0 compatibility:
# - instantActions always use blockingType="NONE" in the official v3 schema.
# - legacy UI names are kept as routes, but mapped to v3 action types.
INSTANT_ACTION_ALIASES = {
    "pause": "startPause",
    "resume": "stopPause",
    "initPosition": "initializePosition",
}

# Project/manufacturer-specific actions that are still intentionally used:
# - release / buttonPress / resetAllHome / resetHoist / resetBridgeTrolley are crane-side actions.
# - holdPose / releaseHold are ROX-Diff handover actions.
# These must also appear in the corresponding mobile robot factsheet/action support.
# ---------------- Button counters for UI polling ----------------
BUTTONS = [
    "automatic",
    "release",
    "pause",
    "resume",
    "order",
    "cancel",
    "reset_all",
    "reset_hoist",
    "reset_xy",
    "release_hold",
]
press_seq = {b: 0 for b in BUTTONS}
consumed_seq = {b: 0 for b in BUTTONS}


# -------------------------------------------------------
def _match_rendezvous(
    crane_node: Optional[str], rox_node: Optional[str]
) -> Optional[str]:
    for r in RENDEZVOUS:
        if r["crane_node"] == crane_node and r["rox_node"] == rox_node:
            return r["tag"]
    return None


def _sub_topic_state_for(target: str) -> str:
    return f"{TARGETS[target]['topic_root']}/state"


def _sub_topic_connection_for(target: str) -> str:
    return f"{TARGETS[target]['topic_root']}/connection"


def _sub_topic_factsheet_for(target: str) -> str:
    return f"{TARGETS[target]['topic_root']}/factsheet"


def _on_connect(client, userdata, flags, rc, properties=None):
    _log(f"[MQTT] on_connect rc={rc}")
    # VDA 5050 v3.0: order/instantActions/state/factsheet/zoneSet/responses/visualization use QoS 0.
    # Only connection uses QoS 1. This controller only subscribes to state here.
    for target in TARGETS:
        client.subscribe(_sub_topic_state_for(target), qos=VDA_MQTT_QOS)
        client.subscribe(_sub_topic_connection_for(target), qos=1)
        client.subscribe(_sub_topic_factsheet_for(target), qos=VDA_MQTT_QOS)
    _log("[MQTT] Subscribed to state, connection, and factsheet topics for crane and ROX-Diff")


def _extract_running_action(action_states, action_type: str) -> Optional[str]:
    """
    Return actionId of first actionStates entry matching action_type with RUNNING status.
    """
    if not isinstance(action_states, list):
        return None
    for a in reversed(action_states):
        try:
            if (
                a.get("actionType") == action_type
                and a.get("actionStatus") == "RUNNING"
            ):
                return a.get("actionId")
        except Exception:
            pass
    return None


def _action_status(action_states, action_id: str) -> Optional[str]:
    """Return the current status for an exact actionId, if present."""
    if not isinstance(action_states, list) or not action_id:
        return None
    for action in reversed(action_states):
        if str(action.get("actionId", "")) == action_id:
            return action.get("actionStatus")
    return None


def _header_matches_target(target: str, payload: Dict[str, Any]) -> bool:
    """Reject state/connection/factsheet messages for another participant/version."""
    cfg = TARGETS[target]
    return (
        str(payload.get("manufacturer", "")) == cfg["manufacturer"]
        and str(payload.get("serialNumber", "")) == cfg["serial"]
        and str(payload.get("version", "")) == cfg["version"]
    )


def _extract_hoist_height(info_list) -> Optional[float]:
    """
    Expect an information entry like:
      {"infoType":"HOIST_POSITION","infoDescription":"Hoist height: 3.070 m", ...}
    Returns float meters if found.
    """
    if not isinstance(info_list, list):
        return None
    for info in info_list:
        try:
            if info.get("infoType") == "HOIST_POSITION":
                desc = info.get("infoDescription", "")
                m = _HOIST_NUM_RE.search(desc or "")
                if m:
                    return float(m.group(1))
        except Exception:
            pass
    return None


def _clear_manual_release() -> None:
    ORCH["manual_release"].update(
        {
            "ts": 0.0,
            "bp_aid": None,
            "tag": None,
            "rox_hold_aid": None,
            "rox_node": None,
        }
    )


def _evaluate_orchestration():
    """Coordinate the two-stage handover from exact action-state milestones.

    Stage 1: action4/buttonPress is automatically released when the ROX-Diff is
    running the configured holdPose action at the matching rendezvous.

    Stage 2: the operator releases action6/buttonPress. The ROX-Diff remains held
    until action7/raiseHoist reports FINISHED, then releaseHold is sent once.
    """
    with STATE_LOCK:
        c_btn_aid = STATE["crane"]["buttonpress_running_aid"]
        c_node = STATE["crane"]["buttonpress_node"]
        safe_lift_status = STATE["crane"]["safe_lift_action_status"]
        d_hold_aid = STATE["rox"]["holdpose_running_aid"]
        d_node = STATE["rox"]["holdpose_node"]

    manual = ORCH["manual_release"]
    manual_armed = manual["ts"] > 0.0
    tag = _match_rendezvous(c_node, d_node)

    # First buttonPress at the crane rendezvous: release only the explicitly
    # configured action, not whichever buttonPress happens to be RUNNING.
    if (
        c_btn_aid == CRANE_AUTO_RELEASE_ACTION_ID
        and d_hold_aid == ROX_HOLD_ACTION_ID
        and tag
        and not manual_armed
        and c_btn_aid not in ORCH["crane_release_sent_for_action"]
    ):
        _log(
            f"[ORCH] Auto-release '{tag}' for crane action {c_btn_aid}; "
            f"ROX hold {d_hold_aid} is RUNNING"
        )
        _publish_instant_action("release", target="crane")
        ORCH["crane_release_sent_for_action"].add(c_btn_aid)

    if manual_armed:
        expected_tag = manual.get("tag")
        expected_rox_node = manual.get("rox_node")
        expected_hold_aid = manual.get("rox_hold_aid")
        same_hold = (
            expected_tag
            and d_hold_aid == expected_hold_aid == ROX_HOLD_ACTION_ID
            and d_node == expected_rox_node
        )

        if safe_lift_status == "FAILED":
            _log(
                f"[ORCH] Safe-lift action {CRANE_SAFE_LIFT_ACTION_ID} FAILED; "
                "ROX hold is intentionally not released."
            )
            _clear_manual_release()
        elif same_hold and safe_lift_status == "FINISHED":
            if d_hold_aid not in ORCH["rox_releasehold_sent_for_action"]:
                _log(
                    f"[ORCH] Release ROX hold '{expected_tag}': crane safe-lift "
                    f"action {CRANE_SAFE_LIFT_ACTION_ID} is FINISHED"
                )
                _publish_instant_action("releaseHold", target="rox")
                ORCH["rox_releasehold_sent_for_action"].add(d_hold_aid)
            _clear_manual_release()

    if manual_armed and (time.time() - manual["ts"] > manual["ttl_s"]):
        _log("[ORCH] Manual-release arming expired; ROX hold remains active.")
        _clear_manual_release()


def _handle_state_msg(target: str, payload: Dict[str, Any]):
    if STATE_SCHEMA is not None:
        try:
            jsonschema.validate(payload, STATE_SCHEMA)
        except Exception as exc:
            _log(f"[{target}] Ignoring invalid VDA state message: {exc}")
            return
    if not _header_matches_target(target, payload):
        _log(f"[{target}] Ignoring state with mismatched participant/version header")
        return

    action_states = payload.get("actionStates") or []
    information = payload.get("information") or []

    with STATE_LOCK:
        STATE[target]["last_state"] = payload
        STATE[target]["last_state_received_at"] = time.time()
        if target == "crane":
            running_button = _extract_running_action(action_states, "buttonPress")
            STATE["crane"]["buttonpress_running_aid"] = running_button
            STATE["crane"]["buttonpress_node"] = ORDER_BOOK["crane"]["action2node"].get(
                running_button
            )
            STATE["crane"]["safe_lift_action_status"] = _action_status(
                action_states, CRANE_SAFE_LIFT_ACTION_ID
            )
            # Telemetry is exposed to /runtime for diagnostics only.
            STATE["crane"]["hoist_height_m"] = _extract_hoist_height(information)
        elif target == "rox":
            hold_status = _action_status(action_states, ROX_HOLD_ACTION_ID)
            running_hold = ROX_HOLD_ACTION_ID if hold_status == "RUNNING" else None
            STATE["rox"]["holdpose_running_aid"] = running_hold
            STATE["rox"]["holdpose_node"] = ORDER_BOOK["rox"]["action2node"].get(
                running_hold
            )

    _evaluate_orchestration()


def _on_message(client, userdata, msg):
    try:
        data = json.loads(msg.payload.decode("utf-8"))
    except Exception as e:
        _log(f"[MQTT] Drop malformed JSON on {msg.topic}: {e}")
        return

    if msg.topic == _sub_topic_state_for("crane"):
        _handle_state_msg("crane", data)
    elif msg.topic == _sub_topic_state_for("rox"):
        _handle_state_msg("rox", data)
    else:
        for target in TARGETS:
            if msg.topic == _sub_topic_connection_for(target):
                if CONNECTION_SCHEMA is not None:
                    try:
                        jsonschema.validate(data, CONNECTION_SCHEMA)
                    except Exception as exc:
                        _log(f"[{target}] Ignoring invalid connection message: {exc}")
                        break
                if not _header_matches_target(target, data):
                    _log(f"[{target}] Ignoring connection with mismatched participant/version header")
                    break
                with STATE_LOCK:
                    STATE[target]["connection"] = data
                    STATE[target]["connection_received_at"] = time.time()
                break
            if msg.topic == _sub_topic_factsheet_for(target):
                if FACTSHEET_SCHEMA is not None:
                    try:
                        jsonschema.validate(data, FACTSHEET_SCHEMA)
                    except Exception as exc:
                        _log(f"[{target}] Ignoring invalid factsheet message: {exc}")
                        break
                if not _header_matches_target(target, data):
                    _log(f"[{target}] Ignoring factsheet with mismatched participant/version header")
                    break
                with STATE_LOCK:
                    STATE[target]["factsheet"] = data
                    STATE[target]["factsheet_received_at"] = time.time()
                break


def _kv_params(d: Dict[str, Any]) -> List[Dict[str, Any]]:
    """Convert {'x':1, 'y':2} -> [{'key':'x','value':1}, {'key':'y','value':2}]"""
    return [{"key": k, "value": v} for k, v in d.items()]


def _load_schema(path: str) -> Dict[str, Any]:
    try:
        with open(path, "r", encoding="utf-8") as f:
            return json.load(f)
    except Exception as exc:
        raise RuntimeError(
            f"Required VDA 5050 schema is missing or unreadable: {path}: {exc}"
        ) from exc


# Load schemas before starting the MQTT callback thread so an early retained
# connection/state/factsheet message cannot race uninitialized validators.
ORDER_SCHEMA = _load_schema(ORDER_SCHEMA_PATH)
IA_SCHEMA = _load_schema(IA_SCHEMA_PATH)
STATE_SCHEMA = _load_schema(STATE_SCHEMA_PATH)
CONNECTION_SCHEMA = _load_schema(CONNECTION_SCHEMA_PATH)
FACTSHEET_SCHEMA = _load_schema(FACTSHEET_SCHEMA_PATH)

def _new_mqtt_client(client_id: str) -> mqtt.Client:
    """Use the current Paho callback API while remaining compatible with 1.x."""
    try:
        return mqtt.Client(
            mqtt.CallbackAPIVersion.VERSION2,
            client_id=client_id,
            clean_session=True,
        )
    except (AttributeError, TypeError):
        return mqtt.Client(client_id=client_id, clean_session=True)


mqtt_client = _new_mqtt_client("FLASK_BUTTONS")
mqtt_client.on_connect = _on_connect
mqtt_client.on_message = _on_message
mqtt_client.connect_async(BROKER_HOST, BROKER_PORT, keepalive=20)
mqtt_client.loop_start()


# ---------------- Helpers ----------------
def _validate_local(
    schema: Optional[Dict[str, Any]], payload: Dict[str, Any], title: str
):
    """If a schema is loaded, validate payload; abort(400) on failure."""
    if schema is None:
        return
    try:
        jsonschema.validate(payload, schema)
    except Exception as e:
        abort(400, f"{title} fails schema validation: {e}")


def _utc_ts() -> str:
    return (
        datetime.now(timezone.utc)
        .isoformat(timespec="milliseconds")
        .replace("+00:00", "Z")
    )


def _log(msg: str):
    print(f"[UI] {msg}", flush=True)


def _publish(topic: str, payload: Dict[str, Any], qos: int = VDA_MQTT_QOS):
    # json preserves insertion order in Python 3.7+
    mqtt_client.publish(topic, json.dumps(payload), qos=qos, retain=False)
    _log(f"[MQTT] published -> {topic}")


def _canonical_instant_action_type(action_type: str) -> str:
    """Map legacy/local UI action names to VDA 5050 v3.0 action types."""
    return INSTANT_ACTION_ALIASES.get(action_type, action_type)


def _publish_instant_action(
    action_type: str,
    *,
    target: str = "crane",
    params: Optional[List[Dict[str, Any]]] = None,
) -> str:
    """
    Publish a VDA 5050 v3.0 instantAction to one target and return its actionId.

    In v3.0, the official instantActions schema only allows blockingType="NONE".
    The blocking behavior for normal order actions still belongs inside order nodes/edges.
    """
    if target not in TARGETS:
        abort(
            400, f"Unknown target '{target}'. Use one of: {', '.join(TARGETS.keys())}"
        )

    _HEADERS[target]["instantActions"] += 1
    cfg = TARGETS[target]
    action_type = _canonical_instant_action_type(action_type)

    action: Dict[str, Any] = {
        "actionId": str(uuid4()),
        "actionType": action_type,
        "blockingType": "NONE",
    }
    if params:
        action["actionParameters"] = params

    payload = {
        "headerId": _HEADERS[target]["instantActions"],
        "timestamp": _utc_ts(),
        "version": cfg["version"],
        "manufacturer": cfg["manufacturer"],
        "serialNumber": cfg["serial"],
        "actions": [action],
    }
    _validate_local(IA_SCHEMA, payload, "instantActions")
    _publish(f"{cfg['topic_root']}/instantActions", payload)
    return action["actionId"]


def _publish_instant_action_to_targets(
    action_type: str,
    targets: Optional[List[str]] = None,
    params: Optional[List[Dict[str, Any]]] = None,
) -> Dict[str, str]:
    """Publish the same instant action to multiple targets and return target->actionId."""
    result: Dict[str, str] = {}
    for target in targets or list(TARGETS.keys()):
        result[target] = _publish_instant_action(
            action_type, target=target, params=params
        )
    return result


def _load_order_template(path: str) -> Dict[str, Any]:
    if not os.path.exists(path):
        raise FileNotFoundError(f"order.json not found at '{path}'")
    with open(path, "r", encoding="utf-8") as f:
        return json.load(f)


def _normalize_order_for_v3(order: Dict[str, Any]) -> Dict[str, Any]:
    """Best-effort migration/cleanup for v2-ish order templates before v3 publishing.

    This keeps templates convenient while preventing common v2->v3 schema problems:
    - protocol header fields are restamped elsewhere
    - numeric nodePosition.allowedDeviationXY becomes the v3 ellipse object
    - missing nodePosition.mapId is filled from DEFAULT_MAP_ID
    - removed edge startNodeId/endNodeId are dropped
    - common old edge names are mapped to v3 names
    """
    order.pop("headerId", None)
    order.pop("timestamp", None)

    for node in order.get("nodes", []) or []:
        node.setdefault("actions", [])
        node_position = node.get("nodePosition")
        if isinstance(node_position, dict):
            node_position.setdefault("mapId", DEFAULT_MAP_ID)

            allowed_deviation_xy = node_position.get("allowedDeviationXY")
            if isinstance(allowed_deviation_xy, (int, float)):
                radius = float(allowed_deviation_xy)
                node_position["allowedDeviationXY"] = {
                    "a": radius,
                    "b": radius,
                    "theta": 0.0,
                }

    for edge in order.get("edges", []) or []:
        edge.setdefault("actions", [])

        # v2.x templates commonly contain these; v3 removed them from the order edge model.
        edge.pop("startNodeId", None)
        edge.pop("endNodeId", None)

        legacy_name_map = {
            "maxSpeed": "maximumSpeed",
            "maxHeight": "maximumMobileRobotHeight",
            "minHeight": "minimumLoadHandlingDeviceHeight",
        }
        for old_name, new_name in legacy_name_map.items():
            if old_name in edge:
                if new_name not in edge:
                    edge[new_name] = edge[old_name]
                edge.pop(old_name, None)

        # v3 uses reachOrientationBeforeEntering instead of the old rotationAllowed style.
        if "rotationAllowed" in edge:
            if "reachOrientationBeforeEntering" not in edge:
                edge["reachOrientationBeforeEntering"] = not bool(
                    edge["rotationAllowed"]
                )
            edge.pop("rotationAllowed", None)

    return order


def _prepare_order_from_template(
    tpl: Dict[str, Any], *, target: str = "crane"
) -> Dict[str, Any]:
    """
    Stamp order with fresh IDs and target-specific header fields.
    """
    if target not in TARGETS:
        abort(
            400, f"Unknown target '{target}'. Use one of: {', '.join(TARGETS.keys())}"
        )
    cfg = TARGETS[target]

    order = deepcopy(tpl)
    _normalize_order_for_v3(order)

    order["orderId"] = str(uuid4())
    order.setdefault("orderUpdateId", 0)
    order["version"] = cfg["version"]
    order["manufacturer"] = cfg["manufacturer"]
    order["serialNumber"] = cfg["serial"]

    nodes = order.get("nodes")
    edges = order.get("edges")
    if not isinstance(nodes, list) or len(nodes) == 0:
        raise ValueError("order.json must contain a non-empty 'nodes' array.")
    if not isinstance(edges, list):
        raise ValueError(
            "order.json must contain an 'edges' array; use [] for a one-node order."
        )
    if len(edges) != max(len(nodes) - 1, 0):
        _log(
            f"[{target}] WARNING: VDA 5050 expects len(edges) == len(nodes)-1; got nodes={len(nodes)}, edges={len(edges)}"
        )
    return order


def _index_actions(order: Dict[str, Any]) -> Dict[str, str]:
    m: Dict[str, str] = {}
    for n in order.get("nodes", []):
        nid = n.get("nodeId")
        for a in n.get("actions", []):
            aid = a.get("actionId")
            if aid:
                m[str(aid)] = str(nid)
    for e in order.get("edges", []):
        for a in e.get("actions", []):
            aid = a.get("actionId")
            if aid:
                m[str(aid)] = f"edge:{e.get('edgeId')}"
    return m


def _publish_order(order_payload: Dict[str, Any], *, target: str = "crane"):
    """Stamp header + timestamp and publish to the target's /order topic."""
    if target not in TARGETS:
        abort(
            400, f"Unknown target '{target}'. Use one of: {', '.join(TARGETS.keys())}"
        )
    cfg = TARGETS[target]
    _HEADERS[target]["order"] += 1
    ts = _utc_ts()

    payload = OrderedDict()
    payload["headerId"] = _HEADERS[target]["order"]
    payload["timestamp"] = ts
    payload["orderId"] = order_payload.get("orderId")
    payload["orderUpdateId"] = order_payload.get("orderUpdateId", 0)
    payload["version"] = cfg["version"]
    payload["manufacturer"] = cfg["manufacturer"]
    payload["serialNumber"] = cfg["serial"]

    payload["nodes"] = order_payload.get("nodes", [])
    payload["edges"] = order_payload.get("edges", [])

    for k, v in order_payload.items():
        if k not in payload and k not in ("headerId", "timestamp"):
            payload[k] = v

    _validate_local(ORDER_SCHEMA, payload, "order")
    _publish(f"{cfg['topic_root']}/order", payload)
    _log(f"[{target}] orderId={payload.get('orderId')} sent")

    # NEW: remember this order so we can resolve actionId -> nodeId during orchestration
    ORDER_BOOK[target]["action2node"] = _index_actions(order_payload)
    ORDER_BOOK[target]["orderId"] = payload["orderId"]

    # NEW: reset guards per target on new order
    if target == "crane":
        ORCH["crane_release_sent_for_action"].clear()
        ORCH["manual_release"].update(
            {
                "ts": 0.0,
                "bp_aid": None,
                    "tag": None,
                "rox_hold_aid": None,
                "rox_node": None,
            }
        )
    elif target == "rox":
        ORCH["rox_releasehold_sent_for_action"].clear()


def _as_bool(val: str) -> bool:
    return str(val).lower() in ("1", "true", "yes", "y", "on")


def _ensure_btn(name: str) -> str:
    name = (name or "").lower()
    if name not in BUTTONS:
        abort(400, f"Unknown button '{name}'. Use one of: {', '.join(BUTTONS)}")
    return name


def _record_press(btn: str):
    press_seq[btn] += 1
    _log(f"[{btn.upper()}] pressed (seq={press_seq[btn]})")


def _required_float_env(name: str) -> float:
    value = os.getenv(name, "").strip()
    if not value:
        abort(400, f"{name} is not configured. Capture the ROX-Diff initial pose and update configs/fleet_control.env.")
    try:
        return float(value)
    except ValueError:
        abort(400, f"{name} must be a number, got {value!r}.")


# ---------------- Routes ----------------
@app.route("/")
def index():
    return render_template("index.html")


# POST: basic buttons
@app.route("/automatic", methods=["POST"])
def press_automatic():
    _record_press("automatic")
    # VDA 5050 v3 predefined action: initializePosition
    _publish_instant_action(
        "initializePosition",
        target="rox",
        params=_kv_params(
            {
                "x": _required_float_env("ROX_INIT_X"),
                "y": _required_float_env("ROX_INIT_Y"),
                "theta": _required_float_env("ROX_INIT_THETA"),
                "mapId": os.getenv("ROX_INIT_MAP_ID", DEFAULT_MAP_ID),
                "lastNodeId": os.getenv("ROX_INIT_LAST_NODE_ID", ""),
                "lastNodeSequenceId": int(os.getenv("ROX_INIT_LAST_NODE_SEQUENCE_ID", "0")),
            }
        ),
    )
    return jsonify({"ok": True})


@app.route("/release", methods=["POST"])
def press_release():
    _record_press("release")
    _publish_instant_action("release", target="crane")

    with STATE_LOCK:
        cur_bp_aid = STATE["crane"]["buttonpress_running_aid"]
        cur_bp_node = STATE["crane"]["buttonpress_node"]
        cur_hold_aid = STATE["rox"]["holdpose_running_aid"]
        cur_hold_node = STATE["rox"]["holdpose_node"]

    tag = _match_rendezvous(cur_bp_node, cur_hold_node)
    can_arm = (
        cur_bp_aid == CRANE_MANUAL_RELEASE_ACTION_ID
        and cur_hold_aid == ROX_HOLD_ACTION_ID
        and tag is not None
    )
    if can_arm:
        ORCH["manual_release"].update(
            {
                "ts": time.time(),
                "bp_aid": cur_bp_aid,
                "tag": tag,
                "rox_hold_aid": cur_hold_aid,
                "rox_node": cur_hold_node,
            }
        )
        _log(
            f"[ORCH] Manual release armed at {tag}; waiting for crane action "
            f"{CRANE_SAFE_LIFT_ACTION_ID} to FINISH before releasing ROX hold"
        )
        _evaluate_orchestration()
    else:
        _clear_manual_release()
        _log(
            "[ORCH] Crane release sent, but ROX release was not armed: "
            f"expected crane action {CRANE_MANUAL_RELEASE_ACTION_ID} and "
            f"ROX hold {ROX_HOLD_ACTION_ID}."
        )

    return jsonify({"ok": True, "rox_release_armed": bool(can_arm)})


@app.route("/pause", methods=["POST"])
def press_pause():
    _record_press("pause")
    actions = _publish_instant_action_to_targets(
        "startPause"
    )  # v3 name for legacy "pause"
    return jsonify({"ok": True, "actions": actions})


@app.route("/resume", methods=["POST"])
def press_resume():
    _record_press("resume")
    actions = _publish_instant_action_to_targets(
        "stopPause"
    )  # v3 name for legacy "resume"
    return jsonify({"ok": True, "actions": actions})


# POST: RESET ALL HOME (instantAction: resetAllHome)
@app.route("/reset_all", methods=["POST"])
def press_reset_all():
    _record_press("reset_all")
    _publish_instant_action("resetAllHome")
    return jsonify({"ok": True})


# POST: RESET HOIST ONLY (instantAction: resetHoist)
@app.route("/reset_hoist", methods=["POST"])
def press_reset_hoist():
    _record_press("reset_hoist")
    _publish_instant_action("resetHoist")
    return jsonify({"ok": True})


# POST: RESET BRIDGE/TROLLEY ONLY (instantAction: resetBridgeTrolley)
@app.route("/reset_xy", methods=["POST"])
def press_reset_xy():
    _record_press("reset_xy")
    _publish_instant_action("resetBridgeTrolley")
    return jsonify({"ok": True})


def _send_configured_orders(targets: List[str]) -> Dict[str, Any]:
    result: Dict[str, Any] = {"ok": True, "orders": {}}
    ORCH["crane_release_sent_for_action"].clear()
    ORCH["rox_releasehold_sent_for_action"].clear()
    ORCH["manual_release"].update(
        {
            "ts": 0.0,
            "bp_aid": None,
            "ttl_s": 60.0,
            "tag": None,
            "rox_hold_aid": None,
            "rox_node": None,
        }
    )
    for target in targets:
        try:
            template = _load_order_template(TARGETS[target]["order_tpl"])
            order = _prepare_order_from_template(template, target=target)
            _publish_order(order, target=target)
            result["orders"][target] = order["orderId"]
        except Exception as exc:
            _log(f"[{target}] ERROR preparing/sending order: {exc}")
            result.setdefault("errors", {})[target] = str(exc)
            result["ok"] = False
    return result


# POST: both configured orders
@app.route("/order", methods=["POST"])
def press_order():
    _record_press("order")
    result = _send_configured_orders(["crane", "rox"])
    return jsonify(result), (200 if result["ok"] else 400)


# POST: one target only, useful while bringing up the ROX-Diff or crane independently.
@app.route("/order/<target>", methods=["POST"])
def press_order_target(target: str):
    if target not in TARGETS:
        abort(404, f"Unknown target {target!r}")
    _record_press("order")
    result = _send_configured_orders([target])
    return jsonify(result), (200 if result["ok"] else 400)


# POST: CANCEL (v3 cancelOrder with the active orderId when known)
@app.route("/cancel", methods=["POST"])
def press_cancel():
    _record_press("cancel")
    # after successfully publishing orders (or right at the start of the route)
    ORCH["crane_release_sent_for_action"].clear()
    ORCH["rox_releasehold_sent_for_action"].clear()
    ORCH["manual_release"].update(
        {
            "ts": 0.0,
            "bp_aid": None,
            "ttl_s": 60.0,
            "tag": None,
            "rox_hold_aid": None,
            "rox_node": None,
        }
    )
    actions: Dict[str, str] = {}
    for target in TARGETS:
        order_id = ORDER_BOOK[target].get("orderId")
        params = _kv_params({"orderId": order_id}) if order_id else None
        actions[target] = _publish_instant_action(
            "cancelOrder", target=target, params=params
        )
    return jsonify({"ok": True, "actions": actions})


@app.route("/cancel/<target>", methods=["POST"])
def press_cancel_target(target: str):
    if target not in TARGETS:
        abort(404, f"Unknown target {target!r}")
    _record_press("cancel")
    order_id = ORDER_BOOK[target].get("orderId")
    params = _kv_params({"orderId": order_id}) if order_id else None
    action_id = _publish_instant_action("cancelOrder", target=target, params=params)
    return jsonify(
        {"ok": True, "target": target, "actionId": action_id, "orderId": order_id}
    )


@app.route("/pause/<target>", methods=["POST"])
def press_pause_target(target: str):
    if target not in TARGETS:
        abort(404, f"Unknown target {target!r}")
    _record_press("pause")
    action_id = _publish_instant_action("startPause", target=target)
    return jsonify({"ok": True, "target": target, "actionId": action_id})


@app.route("/resume/<target>", methods=["POST"])
def press_resume_target(target: str):
    if target not in TARGETS:
        abort(404, f"Unknown target {target!r}")
    _record_press("resume")
    action_id = _publish_instant_action("stopPause", target=target)
    return jsonify({"ok": True, "target": target, "actionId": action_id})


@app.route("/factsheet/<target>", methods=["POST"])
def request_factsheet(target: str):
    if target not in TARGETS:
        abort(404, f"Unknown target {target!r}")
    action_id = _publish_instant_action("factsheetRequest", target=target)
    return jsonify({"ok": True, "target": target, "actionId": action_id})


@app.route("/instant/<target>/<action_type>", methods=["POST"])
def publish_custom_instant_action(target: str, action_type: str):
    """Development endpoint for supported standard or project-specific instant actions.

    Request JSON can be either {"parameters": {"key": value}} or
    {"parameters": [{"key": "...", "value": ...}]}.
    """
    if target not in TARGETS:
        abort(404, f"Unknown target {target!r}")
    body = request.get_json(silent=True) or {}
    raw_params = body.get("parameters")
    params: Optional[List[Dict[str, Any]]] = None
    if isinstance(raw_params, dict):
        params = _kv_params(raw_params)
    elif isinstance(raw_params, list):
        params = raw_params
    elif raw_params is not None:
        abort(400, "parameters must be an object or an actionParameters array")
    action_id = _publish_instant_action(action_type, target=target, params=params)
    return jsonify({"ok": True, "target": target, "actionId": action_id})


@app.route("/release_hold", methods=["POST"])
def press_release_hold():
    _record_press("release_hold")
    _publish_instant_action("releaseHold", target="rox")
    return jsonify({"ok": True})


# GET: status
@app.route("/status", methods=["GET"])
def status():
    btn_param = request.args.get("btn")
    consume = _as_bool(request.args.get("consume", "0"))

    # Allow "consume all" when no btn is given (or btn=all) — matches adapter fallback.
    if consume and (btn_param is None or btn_param.lower() == "all"):
        payload = {
            b: {"pressed": press_seq[b] > consumed_seq[b], "seq": press_seq[b]}
            for b in BUTTONS
        }
        for b in BUTTONS:
            consumed_seq[b] = press_seq[b]
        return jsonify(payload)

    btn = _ensure_btn(btn_param or "release")
    payload = {
        "btn": btn,
        "pressed": press_seq[btn] > consumed_seq[btn],
        "seq": press_seq[btn],
    }
    if consume:
        consumed_seq[btn] = press_seq[btn]
    return jsonify(payload)


@app.route("/status_all", methods=["GET"])
def status_all():
    consume = _as_bool(request.args.get("consume", "0"))
    payload = {
        b: {"pressed": press_seq[b] > consumed_seq[b], "seq": press_seq[b]}
        for b in BUTTONS
    }
    if consume:
        for b in BUTTONS:
            consumed_seq[b] = press_seq[b]
    return jsonify(payload)


@app.route("/runtime", methods=["GET"])
def runtime_status():
    """Return the latest integration state for debugging on the Raspberry Pi."""
    with STATE_LOCK:
        state_copy = deepcopy(STATE)
    return jsonify(
        {
            "mqtt": {"host": BROKER_HOST, "port": BROKER_PORT},
            "targets": TARGETS,
            "rendezvous": RENDEZVOUS,
            "orchestration": {
                "crane_auto_release_action_id": CRANE_AUTO_RELEASE_ACTION_ID,
                "crane_manual_release_action_id": CRANE_MANUAL_RELEASE_ACTION_ID,
                "crane_safe_lift_action_id": CRANE_SAFE_LIFT_ACTION_ID,
                "rox_hold_action_id": ROX_HOLD_ACTION_ID,
                "manual_release_ttl_s": MANUAL_RELEASE_TTL_S,
            },
            "state": state_copy,
            "orders": deepcopy(ORDER_BOOK),
        }
    )

# VDA5050_DASHBOARD_V3_BEGIN
# Register the live VDA 5050 v3 dashboard after the legacy routes and MQTT
# helpers exist, but before the Flask development server is started.
try:
    from dashboard_v3 import register_dashboard as _register_dashboard_v3
except ImportError:  # Allows importing fleet_control.master_control as a module.
    from fleet_control.dashboard_v3 import register_dashboard as _register_dashboard_v3

_register_dashboard_v3(app, globals())
# VDA5050_DASHBOARD_V3_END

# ---------------- Main ----------------
if __name__ == "__main__":
    app.run(host="0.0.0.0", port=5000)
