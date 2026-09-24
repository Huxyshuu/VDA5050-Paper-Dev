"""Opt-in crane benchmark feedback and exclusive supervised command ownership."""
from __future__ import annotations
import json
import hashlib
import threading
import time
from pathlib import Path
from benchmark.common import load_config
from benchmark.measurement import PROTOCOL
from crane_edge.hoist_benchmark import execute, motion_id


class CraneBenchmark:
    def __init__(self, adapter, path, manufacturer, serial):
        self.adapter = adapter
        self.cfg = load_config(Path(path))
        if self.cfg.get("schema_version") != 3 or self.cfg.get("measurement_protocol") != PROTOCOL or self.cfg.get("device") != "crane":
            raise ValueError("Crane benchmark requires laptop-timing-v1 crane config")
        if self.cfg.get("opcua_url") != adapter.crane.endpoint_url:
            raise ValueError("Benchmark OPC UA endpoint differs from the active crane client")
        self.motion_id = motion_id(self.cfg["hoist"])
        self.source_hashes = {name: hashlib.sha256(Path(__file__).with_name(name).read_bytes()).hexdigest()
                              for name in ("benchmark_bridge.py", "hoist_benchmark.py", "crane.py", "crane_vda5050_adapter_v3.py")}
        self.topic = f"vda5050/benchmark/crane/{manufacturer}/{serial}"
        self.lock = threading.RLock()
        self.owner = None
        self.claimed = False
        self.deadline = 0.0

    def send(self, event, **fields):
        info = self.adapter.mqtt.publish(self.topic, json.dumps({"protocol": PROTOCOL, "event": event, **fields}), qos=1, retain=False)
        if info.rc != 0:
            raise RuntimeError("Crane benchmark feedback publication failed")

    def busy(self):
        a = self.adapter
        return a._order_active or a._instant_motion_active or not a._order_queue.empty() or not a._ia_queue.empty()

    def probe(self, payload):
        if payload.get("protocol") != PROTOCOL:
            return
        request = payload.get("request_id", "")
        with self.lock:
            op = payload.get("op", "check")
            if op == "heartbeat":
                if self.owner and payload.get("token") == self.owner["token"]:
                    if self.adapter._stop_or_cancel.is_set():
                        self.send("ERROR", order_id=self.owner.get("trial_id", ""),
                                  goal_id=self.owner["token"], error="Crane cancel/stop is latched")
                    else:
                        self.deadline = time.monotonic()+3.0
                        self.send("LEASE", token=self.owner["token"])
                return
            if op == "abort":
                if self.owner and payload.get("token") == self.owner["token"]:
                    self.adapter._cancel.set()
                    self.adapter.crane.stop_all(reason="benchmark_abort")
                return
            if op == "release":
                if self.owner and payload.get("token") == self.owner["token"] and not self.busy():
                    self.owner = None
                return
            error = ""
            if op == "reserve":
                token = payload.get("token", "")
                if self.owner or self.busy():
                    error = "Crane benchmark already reserved or busy"
                elif payload.get("motion_id") != self.motion_id or payload.get("mode") not in {"native", "vda"} or not isinstance(token, str) or len(token) != 32 or any(c not in '0123456789abcdef' for c in token):
                    error = "Invalid benchmark reservation/configuration"
                else:
                    self.owner = dict(payload)
                    self.claimed = False
                    self.adapter._cancel.clear()
                    self.deadline = time.monotonic()+3.0
            self.send("READY", request_id=request, error=error,
                      reserved=bool(self.owner), busy=self.busy(), motion_id=self.motion_id,
                      opcua_url=self.cfg["opcua_url"], automatic=self.adapter.crane.is_automatic_mode(),
                      order_qos=0, feedback_qos=1, source_hashes=self.source_hashes)

    def validate_order(self, order):
        with self.lock:
            if self.adapter._stop_or_cancel.is_set():
                raise ValueError("Crane cancel/stop is latched")
            if not self.owner or self.owner["mode"] != "vda" or self.owner.get("trial_id") != order.get("orderId") or self.claimed or time.monotonic() >= self.deadline:
                raise ValueError("No matching unused VDA benchmark reservation")
            if order.get("orderDescription") != PROTOCOL+" benchmark" or order.get("orderUpdateId") != 0 or order.get("edges") != []:
                raise ValueError("Expected a single stationary benchmark node")
            nodes = order.get("nodes", [])
            if len(nodes) != 1 or nodes[0].get("sequenceId") != 0 or nodes[0].get("released") is not True or 'nodePosition' in nodes[0]:
                raise ValueError("Hoist benchmark cannot include XY movement")
            actions = nodes[0].get("actions", [])
            if len(actions) != 1:
                raise ValueError("Exactly one benchmark hoist action is required")
            action = actions[0]
            pairs = action.get("actionParameters", [])
            params = {p['key']: p['value'] for p in pairs}
            if len(pairs) != len(params) or set(params) != {"start", "target", "motionId", "token"} or params["motionId"] != self.motion_id or params["token"] != self.owner["token"]:
                raise ValueError("Hoist command does not match frozen settings/reservation")
            if {params["start"], params["target"]} != {"A", "B"}:
                raise ValueError("Invalid hoist endpoints")
            from crane_edge.hoist_benchmark import height
            expected = "lowerHoist" if height(self.cfg["hoist"], params["target"]) < height(self.cfg["hoist"], params["start"]) else "raiseHoist"
            if action.get("actionType") != expected or action.get("blockingType") != "HARD":
                raise ValueError("Hoist action type/direction mismatch")
            self.claimed = True
            return action, params

    def run(self, order):
        a = self.adapter
        # Validation/claim happened before queue insertion; cancellation remains latched.
        action = order["nodes"][0]["actions"][0]
        params = {p['key']: p['value'] for p in action['actionParameters']}
        token = params['token']
        fields = {"order_id": order['orderId'], "goal_id": token}
        a.current_order_id = order['orderId']
        a.current_order_update_id = 0
        a.node_states, a.edge_states, a.action_states = [], [], []
        aid = a._action_begin(action, action['actionType'])
        try:
            a._action_update(aid, status="RUNNING")
            endpoint = execute(a.crane, self.cfg['hoist'], params['start'], params['target'],
                               lambda: self.send("ACK", accepted=True, **fields),
                               canceled=lambda: a._stop_or_cancel.is_set() or not a._mqtt_connected or time.monotonic() >= self.deadline)
            # Relay before ordinary state publication; return contains no remote timestamp.
            self.send("RESULT", status=4, endpoint=endpoint, **fields)
            a.last_node_id = order["nodes"][0]["nodeId"]
            a.last_node_seq = 0
            a._action_finish(aid, ok=True, result="Benchmark endpoint verified")
        except Exception as exc:
            self.send("ERROR", error=str(exc), **fields)
            a._action_finish(aid, ok=False, result=str(exc))

    def guard(self):
        while not self.adapter._stop.wait(0.1):
            with self.lock:
                if self.owner and time.monotonic() >= self.deadline:
                    self.adapter._cancel.set()
                    self.adapter.crane.stop_all(reason="benchmark_lease_expired")
                    self.owner = None
