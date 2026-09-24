"""ROS 2 and MQTT clients on the laptop. ROX runs only Nav2 and its normal adapter."""
from __future__ import annotations

import json
import hashlib
import math
import threading
import time
import uuid
from pathlib import Path

import jsonschema
import rclpy
from action_msgs.srv import CancelGoal
from nav2_msgs.action import NavigateToPose
from nav_msgs.msg import Odometry
from rclpy.action import ActionClient
from rclpy.node import Node
from rclpy.qos import qos_profile_sensor_data
from tf2_msgs.msg import TFMessage
from tf2_ros import Buffer, TransformListener
from unique_identifier_msgs.msg import UUID

from benchmark.common import MqttSession, normalize_angle, utc_now
from benchmark.experiment_logger import ExperimentLogger, config_identifier, publish_json_event
from benchmark.measurement import EVENT_TOPIC, PROTOCOL, Measurement, feedback_topic

ROOT = Path(__file__).resolve().parents[1]


class RoxRunner(Node):
    def __init__(self, cfg, run_dir):
        super().__init__("laptop_rox_benchmark")
        self.cfg, self.run_dir = cfg, run_dir
        self.measurement = None
        self.handle = None
        self.probe_id, self.ready = "", None
        self.ready_event = threading.Event()
        self.odom_received = 0
        self.tf_received = {}
        self.velocity = (float("inf"), float("inf"))
        ros = cfg["ros"]
        self.tf = Buffer()
        self.listener = TransformListener(self.tf, self)
        self.odom = self.create_subscription(Odometry, ros["odom_topic"], self._odom, qos_profile_sensor_data)
        # These are local receive times for freshness checks, not timing metrics.
        self.tf_watch = self.create_subscription(TFMessage, "/tf", self._tf, qos_profile_sensor_data)
        self.nav = ActionClient(self, NavigateToPose, ros["navigate_to_pose_action"])
        self.cancel = self.create_client(CancelGoal, ros["navigate_to_pose_action"] + "/_action/cancel_goal")
        self.topic_root = "/".join(str(cfg["vda"][k]) for k in
                                   ("interface_name", "major_version", "manufacturer", "serial_number"))
        self.feedback = feedback_topic(cfg["vda"]["manufacturer"], cfg["vda"]["serial_number"])
        mqtt = cfg["mqtt"]
        self.mqtt = MqttSession(mqtt["host"], int(mqtt["port"]), "laptop-benchmark-" + uuid.uuid4().hex[:12])
        self.mqtt.client.on_message = self._feedback
        self.logger = ExperimentLogger(
            run_dir / "events.jsonl", repo_root=ROOT, source="laptop_runner",
            config_id=config_identifier(run_dir / "config.yaml"),
            publisher=publish_json_event(self.mqtt.client, EVENT_TOPIC),
        )
        try:
            self.mqtt.start()
            self.mqtt.subscribe(self.feedback, qos=1)
        except BaseException:
            self.logger.close()
            self.mqtt.stop()
            self.destroy_node()
            raise

    def close(self):
        self.logger.close()
        self.mqtt.stop()
        self.destroy_node()

    def _odom(self, msg):
        self.odom_received = time.monotonic()
        self.velocity = (math.hypot(msg.twist.twist.linear.x, msg.twist.twist.linear.y),
                         abs(msg.twist.twist.angular.z))

    def _tf(self, msg):
        now = time.monotonic()
        for transform in msg.transforms:
            self.tf_received[transform.child_frame_id.lstrip("/")] = now

    def _feedback(self, client, userdata, message):
        received_ns = time.monotonic_ns()  # FIRST action in the Laptop MQTT callback
        if message.retain:
            return
        try:
            payload = json.loads(message.payload)
        except (ValueError, UnicodeDecodeError):
            return
        if not isinstance(payload, dict) or payload.get("protocol") != PROTOCOL:
            return
        if payload.get("event") == "READY" and payload.get("request_id") == self.probe_id:
            self.ready = payload
            self.ready_event.set()
            return
        m = self.measurement
        if m is None or payload.get("order_id") != m.row["trial_id"]:
            return
        event = payload.get("event")
        if event == "ERROR":
            m.fail(str(payload.get("error", "Adapter rejected the command")))
            return
        if payload.get("node_id") != m.row["trial_id"] + "-target":
            m.fail("Adapter response identifies an unexpected node")
            return
        if event == "ACK":
            m.ack(received_ns, payload.get("accepted"), payload.get("goal_id"))
        elif event == "RESULT":
            m.result(received_ns, payload.get("status"), payload.get("goal_id"),
                     payload.get("error_code", 0), str(payload.get("error_msg", "")))

    def spin_until(self, predicate, timeout):
        deadline = time.monotonic() + timeout
        while rclpy.ok() and not predicate() and time.monotonic() < deadline:
            if self.mqtt.error:
                raise RuntimeError(self.mqtt.error)
            rclpy.spin_once(self, timeout_sec=min(0.02, max(0.0, deadline - time.monotonic())))
        return predicate()

    def preflight(self):
        if bool(self.get_parameter("use_sim_time").value):
            raise RuntimeError("Laptop runner must use real hardware, not use_sim_time")
        if not self.nav.wait_for_server(timeout_sec=self.cfg["timeouts"]["nav2_server_s"]):
            raise RuntimeError("Laptop cannot reach NavigateToPose over DDS. Check ROS_DOMAIN_ID, RMW and networking")
        self.probe_id = uuid.uuid4().hex
        self.ready, self.ready_event = None, threading.Event()
        self.mqtt.publish_json(self.feedback + "/probe",
                               {"protocol": PROTOCOL, "request_id": self.probe_id}, qos=1)
        if not self.spin_until(self.ready_event.is_set, 10.0):
            raise RuntimeError("No adapter handshake. Update/rebuild/start the ROX adapter and check MQTT")
        expected = {"dry_run": False, "use_sim_time": False, "busy": False, "server_ready": True,
                    "nav2_action": self.cfg["ros"]["navigate_to_pose_action"],
                    "map_frame": self.cfg["ros"]["map_frame"],
                    "base_frame": self.cfg["ros"]["base_frame"], "map_id": self.cfg["map_id"],
                    "order_qos": 0, "feedback_qos": 1,
                    "adapter_sha256": hashlib.sha256((ROOT/"ros2_ws/src/rox_vda5050_adapter/rox_vda5050_adapter/rox_vda5050_adapter.py").read_bytes()).hexdigest()}
        for key, value in expected.items():
            if self.ready.get(key) != value:
                raise RuntimeError(f"Adapter preflight {key}: expected {value!r}, got {self.ready.get(key)!r}")
        if not self.logger.flush() or self.logger.error:
            raise RuntimeError("Laptop logger is not writable: " + str(self.logger.error))
        return self.ready

    def pose(self):
        now = time.monotonic()
        ros, limits = self.cfg["ros"], self.cfg["readiness"]
        if now - self.odom_received > limits["freshness_s"]:
            raise RuntimeError("No fresh odometry received on laptop")
        for child in (ros["odom_frame"], ros["base_frame"]):
            if now - self.tf_received.get(child.lstrip("/"), 0) > limits["freshness_s"]:
                raise RuntimeError(f"No fresh /tf updates for {child} received on laptop")
        t = self.tf.lookup_transform(ros["map_frame"], ros["base_frame"], rclpy.time.Time())
        p, q = t.transform.translation, t.transform.rotation
        if not all(math.isfinite(v) for v in (p.x, p.y, q.x, q.y, q.z, q.w, *self.velocity)):
            raise RuntimeError("Non-finite TF or odometry sample")
        if abs(q.x*q.x + q.y*q.y + q.z*q.z + q.w*q.w - 1.0) > 0.01:
            raise RuntimeError("TF quaternion is not normalized")
        return {"x": float(p.x), "y": float(p.y),
                "theta": math.atan2(2*(q.w*q.z+q.x*q.y), 1-2*(q.y*q.y+q.z*q.z))}

    def check_pose(self, heading, *, endpoint=False):
        target = self.target(heading)
        p = self.pose()
        xy = math.hypot(p["x"] - target["x"], p["y"] - target["y"])
        theta = abs(normalize_angle(p["theta"] - target["theta"]))
        key = "target" if endpoint else "start"
        tol = self.cfg["tolerances"]
        if xy > tol[key + "_xy_m"] or theta > tol[key + "_theta_rad"]:
            raise RuntimeError(f"{key} pose error: XY={xy:.3f} m; heading={theta:.3f} rad")
        limits = self.cfg["readiness"]
        if self.velocity[0] > limits["stationary_linear_m_s"] or self.velocity[1] > limits["stationary_angular_rad_s"]:
            raise RuntimeError("ROX is not stationary")
        return {"xy_error_m": xy, "theta_error_rad": theta}

    def wait_pose(self, heading, *, endpoint=False):
        timeout = self.cfg["timeouts"]["endpoint_s" if endpoint else "nav2_server_s"]
        deadline = time.monotonic() + timeout
        settled = None
        error = "No pose sample"
        while time.monotonic() < deadline and rclpy.ok():
            rclpy.spin_once(self, timeout_sec=0.02)
            try:
                value = self.check_pose(heading, endpoint=endpoint)
                settled = settled if settled is not None else time.monotonic()
                if time.monotonic() - settled >= self.cfg["readiness"]["settle_s"]:
                    return value
            except Exception as exc:
                error, settled = str(exc), None
        raise RuntimeError(error)

    def target(self, heading):
        return {"x": self.cfg["position"]["x"], "y": self.cfg["position"]["y"],
                "theta": self.cfg["headings"]["theta_a" if heading == "A" else "theta_b"]}

    def vda_order(self, row):
        vda, tol = self.cfg["vda"], self.cfg["tolerances"]
        def node(which, sequence):
            return {"nodeId": row["trial_id"] + ("-start" if sequence == 0 else "-target"),
                    "sequenceId": sequence, "released": True, "actions": [],
                    "nodePosition": {**self.target(which), "mapId": self.cfg["map_id"],
                        "allowedDeviationXY": {"a": tol["start_xy_m"], "b": tol["start_xy_m"], "theta": 0.0},
                        "allowedDeviationTheta": tol["start_theta_rad"]}}
        return {"headerId": int(time.time_ns() % 2147483647), "timestamp": utc_now(),
                "version": vda["protocol_version"], "manufacturer": vda["manufacturer"],
                "serialNumber": vda["serial_number"], "orderId": row["trial_id"],
                "orderUpdateId": 0, "orderDescription": "laptop-timing-v1 benchmark",
                "nodes": [node(row["start"], 0), node(row["target"], 2)],
                "edges": [{"edgeId": row["trial_id"] + "-edge", "sequenceId": 1,
                           "released": True, "actions": []}]}

    def _native_ack(self, future, m):
        received_ns = time.monotonic_ns()  # FIRST action in the Laptop ROS callback
        try:
            handle = future.result()
            goal_id = bytes(handle.goal_id.uuid).hex()
            m.ack(received_ns, bool(handle.accepted), goal_id)
            if handle.accepted:
                self.handle = handle
                handle.get_result_async().add_done_callback(lambda f: self._native_result(f, m, goal_id))
                if m.error or m.finished:
                    handle.cancel_goal_async()
        except Exception as exc:
            m.fail(f"Native goal response failed: {exc}")

    def _native_result(self, future, m, goal_id):
        received_ns = time.monotonic_ns()  # FIRST action in the Laptop ROS callback
        try:
            wrapped = future.result()
            m.result(received_ns, int(wrapped.status), goal_id,
                     int(getattr(wrapped.result, "error_code", 0)),
                     str(getattr(wrapped.result, "error_msg", "")))
        except Exception as exc:
            m.fail(f"Native result failed: {exc}")

    def cancel_attempt(self, row, native_uuid):
        """Best-effort cancellation, outside timing. Never automatically retry."""
        if row["mode"] == "native":
            if self.cancel.wait_for_service(timeout_sec=1.0):
                request = CancelGoal.Request()
                request.goal_info.goal_id = native_uuid
                self.cancel.call_async(request)
        else:
            vda = self.cfg["vda"]
            self.mqtt.publish_json(self.topic_root + "/instantActions", {
                "headerId": int(time.time_ns() % 2147483647), "timestamp": utc_now(),
                "version": vda["protocol_version"], "manufacturer": vda["manufacturer"],
                "serialNumber": vda["serial_number"], "actions": [{
                    "actionId": row["trial_id"] + "-cancel", "actionType": "cancelOrder",
                    "blockingType": "HARD"}]}, qos=0)
        # Keep callbacks alive for late goal acceptance and cancellation replies.
        deadline = time.monotonic() + 2.0
        while rclpy.ok() and time.monotonic() < deadline:
            rclpy.spin_once(self, timeout_sec=0.05)

    def run_trial(self, row):
        self.measurement = m = Measurement(self.logger, row)
        endpoint = None
        native_uuid = UUID(uuid=list(uuid.uuid4().bytes))
        try:
            self.preflight()
            self.wait_pose(row["start"])
            target = self.target(row["target"])
            goal = NavigateToPose.Goal()
            goal.pose.header.frame_id = self.cfg["ros"]["map_frame"]
            # Zero stamp requests the latest transform; no laptop/ROX wall-clock offset.
            goal.pose.pose.position.x, goal.pose.pose.position.y = target["x"], target["y"]
            goal.pose.pose.orientation.z = math.sin(target["theta"] / 2)
            goal.pose.pose.orientation.w = math.cos(target["theta"] / 2)
            order = self.vda_order(row)
            jsonschema.validate(order, json.loads((ROOT / "schemas/vda5050_v3/order.schema").read_text()))
            # Build/validate both payloads before t0. JSON serialization at publish
            # and ROS serialization at send_goal_async are inside the boundary.
            print(f"{row['trial_id']}: {row['mode']} {row['start']} → {row['target']}", flush=True)
            m.issue(target)
            if row["mode"] == "native":
                self.nav.send_goal_async(goal, goal_uuid=native_uuid).add_done_callback(
                    lambda f: self._native_ack(f, m))
            else:
                self.mqtt.publish_json(self.topic_root + "/order", order, qos=0)
            if not self.spin_until(m.done.is_set, self.cfg["timeouts"]["command_s"]):
                raise TimeoutError("No terminal Nav2 result received on Laptop before command timeout")
            if m.error:
                raise RuntimeError(m.error)
            # This check is deliberately after COMMAND_RESULT_RECEIVED in BOTH modes.
            endpoint = self.wait_pose(row["target"], endpoint=True)
        except BaseException as exc:
            m.fail(f"{type(exc).__name__}: {exc}")
            if m.issued_ns is not None and m.result_ns is None:
                try:
                    self.cancel_attempt(row, native_uuid)
                except Exception as cancel_error:
                    print(f"Cancellation could not be confirmed: {cancel_error}", flush=True)
            m.finish()
            self.logger.flush()
            raise
        success = m.finish(endpoint)
        if not self.logger.flush() or self.logger.error:
            raise RuntimeError("Logger failure; preserve the attempt: " + str(self.logger.error))
        print(f"T_ack: {(m.ack_ns-m.issued_ns)/1e6:.3f} ms; "
              f"T_completion: {(m.result_ns-m.issued_ns)/1e6:.3f} ms", flush=True)
        return success
