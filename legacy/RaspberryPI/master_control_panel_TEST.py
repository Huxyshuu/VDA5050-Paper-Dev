# master_control_panel.py
from flask import Flask, render_template, jsonify, request, abort
import os, json, time
from datetime import datetime, timezone
from uuid import uuid4
from collections import OrderedDict
import paho.mqtt.client as mqtt
from typing import Any, Dict, Optional, List
import jsonschema
import threading
import re

app = Flask(__name__)

# ---------------- MQTT / VDA5050 config ----------------
BROKER_HOST = os.getenv("VDA_MQTT_HOST", "192.168.1.115")
BROKER_PORT = int(os.getenv("VDA_MQTT_PORT", "1883"))
HOIST_CLEARANCE_M = float(os.getenv("HOIST_CLEARANCE_M", "1.0"))
_HOIST_NUM_RE = re.compile(r"([-+]?\d+(?:\.\d+)?)")
#--------------------------------------------------------

SCHEMA_DIR = os.getenv("VDA_SCHEMA_DIR", "schemas")
ORDER_SCHEMA_PATH = os.path.join(SCHEMA_DIR, "order.schema")
IA_SCHEMA_PATH = os.path.join(SCHEMA_DIR, "instantActions.schema")

# Which crane node pairs with which DBot node for handover
# (add more pairs as needed)
RENDEZVOUS = [
    {"crane_node": "node2", "dbot_node": "node2", "tag": "DROP_1"},
]

# We index orders we publish, so we can resolve actionId -> nodeId later
ORDER_BOOK = {
    "crane": {"action2node": {}, "orderId": None},
    "dbot":  {"action2node": {}, "orderId": None},
}

# --- Runtime state cache (guarded by STATE_LOCK) ---
STATE_LOCK = threading.Lock()

STATE = {
    "crane": {
        "last_state": None,
        "buttonpress_running_aid": None,
        "buttonpress_node": None,   # NEW
        "hoist_height_m": None,
    },
    "dbot": {
        "last_state": None,
        "holdpose_running_aid": None,
        "holdpose_node": None,      # NEW
    },
}

ORCH = {
    "crane_release_sent_for_action": set(),
    "manual_release": {
        "ts": 0.0,
        "bp_aid": None,
        "hoist_m_at_press": None,
        "ttl_s": 60.0,
        "tag": None,             # NEW: which rendezvous this press belongs to
        "dbot_hold_aid": None,   # NEW: which specific holdPose we're tying to
        "dbot_node": None,
    },
    "dbot_releasehold_sent_for_action": set(),
}


# ---------------- Multi-AGV targets ----------------
TARGETS = {
    "crane": {
        "topic_root": os.getenv("CRANE_TOPIC_ROOT", "uagv/v2/konecranes/ilmatar_1"),
        "manufacturer": os.getenv("CRANE_MANUFACTURER", "konecranes"),
        "serial": os.getenv("CRANE_SERIAL", "ilmatar_1"),
        "version": os.getenv("CRANE_VERSION", "2.1.0"),
        "order_tpl": os.getenv("CRANE_ORDER_JSON_PATH", "order_ilmatar_TEST.json"), # Ilmatar Order JSON
    },
    "dbot": {
        "topic_root": os.getenv("DBOT_TOPIC_ROOT", "uagv/v2/aaltoUniversity/dbot_1"),
        "manufacturer": os.getenv("DBOT_MANUFACTURER", "aaltoUniversity"),
        "serial": os.getenv("DBOT_SERIAL", "dbot_1"),
        "version": os.getenv("DBOT_VERSION", "2.1.0"),
        "order_tpl": os.getenv("DBOT_ORDER_JSON_PATH", "order_dbot_TEST.json"), # Dbot Order JSON
    },
}

# HeaderId counters must be per-topic (order vs instantActions) and per-vehicle (topic root differs).
_HEADERS = {
    "crane": {"order": 0, "instantActions": 0},
    "dbot":  {"order": 0, "instantActions": 0},
}

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

# ---------------- Button counters for UI polling ----------------
BUTTONS = ["automatic", "release", "pause", "resume", "order", "cancel","reset_all", "reset_hoist", "reset_xy", "release_hold"]
press_seq = {b: 0 for b in BUTTONS}
consumed_seq = {b: 0 for b in BUTTONS}

#-------------------------------------------------------
def _match_rendezvous(crane_node: Optional[str], dbot_node: Optional[str]) -> Optional[str]:
    for r in RENDEZVOUS:
        if r["crane_node"] == crane_node and r["dbot_node"] == dbot_node:
            return r["tag"]
    return None

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
    for a in reversed(action_states):
        try:
            if a.get("actionType") == action_type and a.get("actionStatus") == "RUNNING":
                return a.get("actionId")
        except Exception:
            pass
    return None

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
    with STATE_LOCK:
        c_btn_aid  = STATE["crane"]["buttonpress_running_aid"]
        c_node     = STATE["crane"]["buttonpress_node"]
        c_hoist_m  = STATE["crane"]["hoist_height_m"]
        d_hold_aid = STATE["dbot"]["holdpose_running_aid"]
        d_node     = STATE["dbot"]["holdpose_node"]

    manual = ORCH["manual_release"]
    manual_armed = manual["ts"] > 0.0

    # Are the robots at the same logical handover?
    tag = _match_rendezvous(c_node, d_node)

    # (1) Auto-release to Crane at the start of the DROP rendezvous (no timer window)
    if c_btn_aid and d_hold_aid and tag and not manual_armed and (c_hoist_m is not None):
        if (c_btn_aid not in ORCH["crane_release_sent_for_action"]) and (c_hoist_m >= HOIST_CLEARANCE_M):
            _log(f"[ORCH] Auto-release '{tag}': hoist={c_hoist_m:.3f} >= {HOIST_CLEARANCE_M:.3f}")
            _publish_instant_action("release", target="crane")
            ORCH["crane_release_sent_for_action"].add(c_btn_aid)

    # (2) Manual releaseHold to DBot after safe lift at the SAME rendezvous/tag
    if manual_armed:
        expected_tag  = manual.get("tag")
        expected_dbot = manual.get("dbot_node")
        expected_aid  = manual.get("dbot_hold_aid")

        # DBot is still on the same holdPose action AND at the same rendezvous node we armed on
        if expected_tag and d_hold_aid == expected_aid and d_node == expected_dbot:
            if (c_hoist_m is not None) and (c_hoist_m >= HOIST_CLEARANCE_M):
                if d_hold_aid not in ORCH["dbot_releasehold_sent_for_action"]:  # <--- duplicate guard
                    _log(f"[ORCH] Manual releaseHold '{expected_tag}': hoist={c_hoist_m:.3f} >= {HOIST_CLEARANCE_M:.3f}")
                    _publish_instant_action("releaseHold", target="dbot")
                    ORCH["dbot_releasehold_sent_for_action"].add(d_hold_aid)
                # clear arming either way
                manual.update({"ts": 0.0, "bp_aid": None, "hoist_m_at_press": None,
                            "tag": None, "dbot_hold_aid": None, "dbot_node": None})


    # Expire stale arming
    if manual_armed and (time.time() - manual["ts"] > manual["ttl_s"]):
        _log("[ORCH] Manual-release arming expired.")
        manual.update({"ts": 0.0, "bp_aid": None, "hoist_m_at_press": None, "tag": None, "dbot_hold_aid": None, "dbot_node": None})

def _handle_state_msg(target: str, payload: Dict[str, Any]):
    action_states = payload.get("actionStates") or []
    information   = payload.get("information") or []

    with STATE_LOCK:
        STATE[target]["last_state"] = payload
        if target == "crane":
            STATE["crane"]["buttonpress_running_aid"] = _extract_running_action(action_states, "buttonPress")
            STATE["crane"]["hoist_height_m"] = _extract_hoist_height(information)
            # NEW: which node is this buttonPress on?
            aid = STATE["crane"]["buttonpress_running_aid"]
            STATE["crane"]["buttonpress_node"] = ORDER_BOOK["crane"]["action2node"].get(aid)
        elif target == "dbot":
            new_aid = _extract_running_action(action_states, "holdPose")
            STATE["dbot"]["holdpose_running_aid"] = new_aid
            # NEW: which node is this holdPose on?
            STATE["dbot"]["holdpose_node"] = ORDER_BOOK["dbot"]["action2node"].get(new_aid)

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

mqtt_client = mqtt.Client(client_id="FLASK_BUTTONS", clean_session=True)
mqtt_client.on_connect = _on_connect
mqtt_client.on_message = _on_message
mqtt_client.connect_async(BROKER_HOST, BROKER_PORT, keepalive=20)
mqtt_client.loop_start()

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
                            params: Optional[List[Dict[str, Any]]] = None):
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

    # NEW: remember this order so we can resolve actionId -> nodeId during orchestration
    ORDER_BOOK[target]["action2node"] = _index_actions(order_payload)
    ORDER_BOOK[target]["orderId"] = payload["orderId"]

    # NEW: reset guards per target on new order
    if target == "crane":
        ORCH["crane_release_sent_for_action"].clear()
        ORCH["manual_release"].update({"ts": 0.0, "bp_aid": None, "hoist_m_at_press": None, "tag": None, "dbot_hold_aid": None, "dbot_node": None})
    elif target == "dbot":
        ORCH["dbot_releasehold_sent_for_action"].clear()

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
    _publish_instant_action("release", target="crane")  # always unlock current crane buttonPress

    # Arm DBot releaseHold ONLY if the current press matches a rendezvous with DBot's *current* holdPose node
    with STATE_LOCK:
        cur_bp_aid   = STATE["crane"]["buttonpress_running_aid"]
        cur_bp_node  = STATE["crane"]["buttonpress_node"]
        cur_hoist    = STATE["crane"]["hoist_height_m"]
        cur_hold_aid = STATE["dbot"]["holdpose_running_aid"]
        cur_hold_node= STATE["dbot"]["holdpose_node"]

    tag = _match_rendezvous(cur_bp_node, cur_hold_node)
    if tag and cur_hold_aid:
        ORCH["manual_release"].update({
            "ts": time.time(),
            "bp_aid": cur_bp_aid,
            "hoist_m_at_press": cur_hoist,
            "tag": tag,
            "dbot_hold_aid": cur_hold_aid,
            "dbot_node": cur_hold_node,
        })
        _evaluate_orchestration()
        _log(f"[ORCH] Manual /release armed for tag={tag}, bp_aid={cur_bp_aid}, hoist={cur_hoist}")
    else:
        ORCH["manual_release"].update({"ts": 0.0, "bp_aid": None, "hoist_m_at_press": None, "tag": None, "dbot_hold_aid": None, "dbot_node": None})
        _log("[ORCH] Evaluating immediately after manual /release.")
        _evaluate_orchestration()
        _log("[ORCH] /release pressed, but not at a rendezvous with DBot holdPose -> Crane only.")

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
    # after successfully publishing orders (or right at the start of the route)
    ORCH["crane_release_sent_for_action"].clear()
    ORCH["dbot_releasehold_sent_for_action"].clear()
    ORCH["manual_release"].update({
    "ts": 0.0, "bp_aid": None, "hoist_m_at_press": None, "ttl_s": 60.0,
    "tag": None, "dbot_hold_aid": None, "dbot_node": None})
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
    # after successfully publishing orders (or right at the start of the route)
    ORCH["crane_release_sent_for_action"].clear()
    ORCH["dbot_releasehold_sent_for_action"].clear()
    ORCH["manual_release"].update({
    "ts": 0.0, "bp_aid": None, "hoist_m_at_press": None, "ttl_s": 60.0,
    "tag": None, "dbot_hold_aid": None, "dbot_node": None})
    _publish_instant_action("cancelOrder")
    return jsonify({"ok": True})

@app.route("/release_hold", methods=["POST"])
def press_release_hold():
    _record_press("release_hold")
    _publish_instant_action("releaseHold", target="dbot")
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
