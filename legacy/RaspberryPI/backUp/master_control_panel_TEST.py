# master_control_panel.py
from flask import Flask, render_template, jsonify, request, abort
import os, json, time
from datetime import datetime, timezone
from uuid import uuid4
from collections import OrderedDict
import paho.mqtt.client as mqtt
from typing import Any, Dict, Optional, List
import jsonschema
from dataclasses import dataclass
import threading
import re

app = Flask(__name__)

# ---------------- MQTT / VDA5050 config ----------------
BROKER_HOST = os.getenv("VDA_MQTT_HOST", "192.168.1.115")
BROKER_PORT = int(os.getenv("VDA_MQTT_PORT", "1883"))
HOIST_CLEARANCE_M = float(os.getenv("HOIST_CLEARANCE_M", "1.0"))
#--------------------------------------------------------
# --- Runtime state cache (guarded by STATE_LOCK) ---
STATE_LOCK = threading.Lock()
STATE = {
    "crane": {
        "last_state": None,
        "buttonpress_running_aid": None,
        "hoist_height_m": None,
    },
    "dbot": {
        "last_state": None,
        "holdpose_running_aid": None,
    },
}

# --- Orchestration one-shot guards ---
ORCH = {
    # To avoid re-sending release for the same buttonPress:
    "crane_release_sent_for_action": set(),   # set[str actionId]
    # Set when the human presses /release in the UI (manual release):
    "manual_release_ts": 0.0,
    # Avoid re-sending releaseHold for the same Dbot holdPose action:
    "dbot_releasehold_sent_for_action": set(),  # set[str actionId]
}
#-------------------------------------------------------
def _sub_topic_state_for(target: str) -> str:
    return f"{TARGETS[target]['topic_root']}/state"

def _on_connect(client, userdata, flags, rc):
    _log(f"[MQTT] on_connect rc={rc}")
    # Subscribe to both state topics
    client.subscribe(_sub_topic_state_for("crane"), qos=1)
    client.subscribe(_sub_topic_state_for("dbot"), qos=1)
    _log(f"[MQTT] Subscribed to {_sub_topic_state_for('crane')} and {_sub_topic_state_for('dbot')}")

def _extract_running_action(action_states, action_type: str) -> Optional[str]:
    """
    Return actionId of first actionStates entry matching action_type with RUNNING status.
    """
    if not isinstance(action_states, list):
        return None
    for a in action_states:
        try:
            if a.get("actionType") == action_type and a.get("actionStatus") == "RUNNING":
                return a.get("actionId")
        except Exception:
            pass
    return None

_HOIST_NUM_RE = re.compile(r"([-+]?\d+(?:\.\d+)?)")

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

def _evaluate_orchestration():
    """
    1) If Crane is waiting on buttonPress (RUNNING) AND Dbot holdPose is RUNNING -> auto 'release' to Crane (once per action).
    2) After the human presses Release in UI, when Crane hoist > HOIST_CLEARANCE_M AND Dbot holdPose is RUNNING -> 'releaseHold' to Dbot (once per holdPose action).
    """
    with STATE_LOCK:
        c_btn_aid = STATE["crane"]["buttonpress_running_aid"]
        c_hoist_m = STATE["crane"]["hoist_height_m"]
        d_hold_aid = STATE["dbot"]["holdpose_running_aid"]
        manual_ts = ORCH["manual_release_ts"]

    # --- (1) Auto release to Crane only when hoist is HIGH and before any manual-release cycle ---
    if (
        c_btn_aid
        and d_hold_aid
        and c_btn_aid not in ORCH["crane_release_sent_for_action"]
        and manual_ts == 0.0                       # haven't started the manual-release phase yet
        and (c_hoist_m is not None)                # we know the hoist height
        and (c_hoist_m >= HOIST_CLEARANCE_M)       # only auto-release before lowering
    ):
        _log(f"[ORCH] Auto-release: hoist={c_hoist_m:.3f}={HOIST_CLEARANCE_M:.3f}, DBot holdPose RUNNING, "
            f"buttonPress RUNNING (aid={c_btn_aid}) -> release to Crane")
        _publish_instant_action("release", target="crane")
        ORCH["crane_release_sent_for_action"].add(c_btn_aid)

    # --- (2) After manual release, when hoist clears and Dbot still holding -> releaseHold to Dbot ---
    if manual_ts and d_hold_aid and (d_hold_aid not in ORCH["dbot_releasehold_sent_for_action"]):
        if (c_hoist_m is not None) and (c_hoist_m >= HOIST_CLEARANCE_M):
            _log(f"[ORCH] Hoist {c_hoist_m:.3f} m >= {HOIST_CLEARANCE_M:.3f} m and Dbot holdPose RUNNING "
                 f"(aid={d_hold_aid}) -> sending releaseHold to Dbot")
            _publish_instant_action("releaseHold", target="dbot")
            ORCH["dbot_releasehold_sent_for_action"].add(d_hold_aid)
            # one-shot for this manual release cycle
            ORCH["manual_release_ts"] = 0.0

def _handle_state_msg(target: str, payload: Dict[str, Any]):
    """
    Update cached state for 'crane' or 'dbot', then re-evaluate orchestration.
    """
    action_states = payload.get("actionStates") or []
    information   = payload.get("information") or []

    with STATE_LOCK:
        STATE[target]["last_state"] = payload
        if target == "crane":
            STATE["crane"]["buttonpress_running_aid"] = _extract_running_action(action_states, "buttonPress")
            STATE["crane"]["hoist_height_m"] = _extract_hoist_height(information)
        elif target == "dbot":
            STATE["dbot"]["holdpose_running_aid"] = _extract_running_action(action_states, "holdPose")

    _evaluate_orchestration()

def _on_message(client, userdata, msg):
    try:
        data = json.loads(msg.payload.decode("utf-8"))
    except Exception as e:
        _log(f"[MQTT] Drop malformed JSON on {msg.topic}: {e}")
        return

    if msg.topic == _sub_topic_state_for("crane"):
        _handle_state_msg("crane", data)
    elif msg.topic == _sub_topic_state_for("dbot"):
        _handle_state_msg("dbot", data)

# ---------------- Multi-AGV targets ----------------
TARGETS = {
    "crane": {
        "topic_root": os.getenv("CRANE_TOPIC_ROOT", "uagv/v2/konecranes/ilmatar_1"),
        "manufacturer": os.getenv("CRANE_MANUFACTURER", "konecranes"),
        "serial": os.getenv("CRANE_SERIAL", "ilmatar_1"),
        "version": os.getenv("CRANE_VERSION", "2.1.0"),
        "order_tpl": os.getenv("CRANE_ORDER_JSON_PATH", "order_ilmatar_TEST.json"),
    },
    "dbot": {
        "topic_root": os.getenv("DBOT_TOPIC_ROOT", "uagv/v2/OSRF/TB3_1"),
        "manufacturer": os.getenv("DBOT_MANUFACTURER", "OSRF"),
        "serial": os.getenv("DBOT_SERIAL", "TB3_1"),
        "version": os.getenv("DBOT_VERSION", "2.1.0"),
        "order_tpl": os.getenv("DBOT_ORDER_JSON_PATH", "order_dbot_TEST.json"),
    },
}

# HeaderId counters must be per-topic (order vs instantActions) and per-vehicle (topic root differs).
_HEADERS = {
    "crane": {"order": 0, "instantActions": 0},
    "dbot":  {"order": 0, "instantActions": 0},
}


mqtt_client = mqtt.Client(client_id="FLASK_BUTTONS", clean_session=True)
mqtt_client.on_connect = _on_connect
mqtt_client.on_message = _on_message
mqtt_client.connect_async(BROKER_HOST, BROKER_PORT, keepalive=20)
mqtt_client.loop_start()


SCHEMA_DIR = os.getenv("VDA_SCHEMA_DIR", "schemas")
ORDER_SCHEMA_PATH = os.path.join(SCHEMA_DIR, "order.schema")
IA_SCHEMA_PATH = os.path.join(SCHEMA_DIR, "instantActions.schema")

# Choose sensible defaults per action
BT_DEFAULT = {
    "cancelOrder": "HARD",
    "resetAllHome": "HARD",
    "resetHoist": "HARD",
    "resetBridgeTrolley": "HARD",
    "pause": "NONE",
    "resume": "NONE",
    "release": "NONE",
    "initPosition": "NONE",
    "releaseHold": "NONE",  # project-specific;
}

def _kv_params(d: Dict[str, Any]) -> List[Dict[str, Any]]:
    """Convert {'x':1, 'y':2} -> [{'key':'x','value':1}, {'key':'y','value':2}]"""
    return [{"key": k, "value": v} for k, v in d.items()]

def _load_schema(path: str) -> Optional[Dict[str, Any]]:
    try:
        with open(path, "r", encoding="utf-8") as f:
            return json.load(f)
    except Exception:
        _log(f"Schema not found/unreadable at '{path}'. Publishing without local validation.")
        return None

ORDER_SCHEMA = _load_schema(ORDER_SCHEMA_PATH)
IA_SCHEMA = _load_schema(IA_SCHEMA_PATH)

# ---------------- Helpers ----------------
def _validate_local(schema: Optional[Dict[str, Any]], payload: Dict[str, Any], title: str):
    """If a schema is loaded, validate payload; abort(400) on failure."""
    if schema is None:
        return
    try:
        jsonschema.validate(payload, schema)
    except Exception as e:
        abort(400, f"{title} fails schema validation: {e}")

def _utc_ts() -> str:
    return datetime.now(timezone.utc).isoformat(timespec="milliseconds").replace("+00:00", "Z")

def _log(msg: str):
    print(f"[UI] {msg}", flush=True)

def _publish(topic: str, payload: Dict[str, Any], qos: int = 1):
    # json preserves insertion order in Python 3.7+
    mqtt_client.publish(topic, json.dumps(payload), qos=qos, retain=False)
    _log(f"[MQTT] published -> {topic}")

def _publish_instant_action(action_type: str, *, target: str = "crane",
                            params: Optional[list[Dict[str, Any]]] = None):
    """
    Publish VDA5050 instantAction (with or without actionParameters) to a specific target.
    """
    if target not in TARGETS:
        abort(400, f"Unknown target '{target}'. Use one of: {', '.join(TARGETS.keys())}")

    _HEADERS[target]["instantActions"] += 1
    cfg = TARGETS[target]

    action: Dict[str, Any] = {
        "actionId": str(uuid4()),
        "actionType": action_type,
        "blockingType": BT_DEFAULT.get(action_type, "NONE"),
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

def _load_order_template(path: str) -> Dict[str, Any]:
    if not os.path.exists(path):
        raise FileNotFoundError(f"order.json not found at '{path}'")
    with open(path, "r", encoding="utf-8") as f:
        return json.load(f)

def _prepare_order_from_template(tpl: Dict[str, Any], *, target: str = "crane") -> Dict[str, Any]:
    """
    Stamp order with fresh IDs and target-specific header fields.
    """
    if target not in TARGETS:
        abort(400, f"Unknown target '{target}'. Use one of: {', '.join(TARGETS.keys())}")
    cfg = TARGETS[target]

    order = dict(tpl)  # shallow copy
    order.pop("headerId", None)
    order.pop("timestamp", None)

    order["orderId"] = str(uuid4())
    order.setdefault("orderUpdateId", 0)
    order["version"] = cfg["version"]
    order["manufacturer"] = cfg["manufacturer"]
    order["serialNumber"] = cfg["serial"]

    nodes = order.get("nodes")
    if not isinstance(nodes, list) or len(nodes) == 0:
        raise ValueError("order.json must contain a non-empty 'nodes' array.")
    return order

def _publish_order(order_payload: Dict[str, Any], *, target: str = "crane"):
    """Stamp header + timestamp and publish to the target's /order topic."""
    if target not in TARGETS:
        abort(400, f"Unknown target '{target}'. Use one of: {', '.join(TARGETS.keys())}")
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


# ---------------- Button counters for UI polling ----------------
BUTTONS = ["automatic", "release", "pause", "resume", "order", "cancel","reset_all", "reset_hoist", "reset_xy"]
press_seq = {b: 0 for b in BUTTONS}
consumed_seq = {b: 0 for b in BUTTONS}

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

# ---------------- Routes ----------------
@app.route("/")
def index():
    return render_template("index_TEST.html")

# POST: basic buttons
@app.route("/automatic", methods=["POST"])
def press_automatic():
    _record_press("automatic")
    # Send initPosition to DBOT with your requested values
    _publish_instant_action(
        "initPosition",
        target="dbot",
        params=_kv_params({
            "x": -2.688,
            "y": -5.463,
            "theta": -0.234,
            "mapId": "map",
        }),
    )
    return jsonify({"ok": True})

@app.route("/release", methods=["POST"])
def press_release():
    _record_press("release")
    _publish_instant_action("release") # instantAction - RELEASE (Hoist)
    ORCH["manual_release_ts"] = time.time()   # <-- add this line
    return jsonify({"ok": True})

@app.route("/pause", methods=["POST"])
def press_pause():
    _record_press("pause")
    _publish_instant_action("pause")   # instantAction - PAUSE
    return jsonify({"ok": True})

@app.route("/resume", methods=["POST"])
def press_resume():
    _record_press("resume")
    _publish_instant_action("resume") # instantAction - RESUME
    return jsonify({"ok": True})
    
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

# POST: ORDER (reads order.json every time, stamps fields, publishes)
@app.route("/order", methods=["POST"])
def press_order():
    _record_press("order")
    result = {"ok": True, "orders": {}}
    try:
        # Crane order
        crane_tpl = _load_order_template(TARGETS["crane"]["order_tpl"])
        crane_order = _prepare_order_from_template(crane_tpl, target="crane")
        _publish_order(crane_order, target="crane")
        result["orders"]["crane"] = crane_order["orderId"]
    except Exception as e:
        _log(f"[crane] ERROR preparing/sending order: {e}")
        result.setdefault("errors", {})["crane"] = str(e)
        result["ok"] = False

    try:
        # DBot order
        dbot_tpl = _load_order_template(TARGETS["dbot"]["order_tpl"])
        dbot_order = _prepare_order_from_template(dbot_tpl, target="dbot")
        _publish_order(dbot_order, target="dbot")
        result["orders"]["dbot"] = dbot_order["orderId"]
    except Exception as e:
        _log(f"[dbot] ERROR preparing/sending order: {e}")
        result.setdefault("errors", {})["dbot"] = str(e)
        result["ok"] = False

    status_code = 200 if result["ok"] else 400
    return jsonify(result), status_code

# POST: CANCEL (instantAction cancelOrder; NO orderId parameter)
@app.route("/cancel", methods=["POST"])
def press_cancel():
    _record_press("cancel")
    _publish_instant_action("cancelOrder")
    return jsonify({"ok": True})

# GET: status
@app.route("/status", methods=["GET"])
def status():
    btn_param = request.args.get("btn")
    consume = _as_bool(request.args.get("consume", "0"))

    # Allow "consume all" when no btn is given (or btn=all) — matches adapter fallback.
    if consume and (btn_param is None or btn_param.lower() == "all"):
        payload = {b: {"pressed": press_seq[b] > consumed_seq[b], "seq": press_seq[b]} for b in BUTTONS}
        for b in BUTTONS:
            consumed_seq[b] = press_seq[b]
        return jsonify(payload)

    btn = _ensure_btn(btn_param or "release")
    payload = {"btn": btn, "pressed": press_seq[btn] > consumed_seq[btn], "seq": press_seq[btn]}
    if consume:
        consumed_seq[btn] = press_seq[btn]
    return jsonify(payload)

@app.route("/status_all", methods=["GET"])
def status_all():
    consume = _as_bool(request.args.get("consume", "0"))
    payload = {b: {"pressed": press_seq[b] > consumed_seq[b], "seq": press_seq[b]} for b in BUTTONS}
    if consume:
        for b in BUTTONS:
            consumed_seq[b] = press_seq[b]
    return jsonify(payload)

# ---------------- Main ----------------
if __name__ == "__main__":
    app.run(host="0.0.0.0", port=5000)
