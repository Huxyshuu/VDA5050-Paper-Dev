#!/usr/bin/env python3
"""Run one controlled ROX-Diff 90-degree native or VDA latency trial."""

from __future__ import annotations

import argparse
import json
import math
import threading
import time
from pathlib import Path
from typing import Any, Dict, Optional

import jsonschema
import rclpy
from action_msgs.msg import GoalStatus
from nav2_msgs.action import NavigateToPose
from nav_msgs.msg import Odometry
from rclpy.action import ActionClient
from rclpy.node import Node
from tf2_ros import Buffer, TransformException, TransformListener

from common import (
    MqttSession,
    finite_number,
    load_config,
    load_schedule_row,
    normalize_angle,
    utc_now,
)
from experiment_logger import ExperimentLogger, config_identifier, publish_json_event


ROOT = Path(__file__).resolve().parents[1]
DEFAULT_CONFIG = ROOT / "benchmark/config/rox_benchmark.yaml"
DEFAULT_LOG = ROOT / "results/benchmark/rox_events.jsonl"
EVENT_TOPIC = "vda5050/benchmark/events"


class RoxBenchmark(Node):
    def __init__(self, cfg: Dict[str, Any], args: argparse.Namespace) -> None:
        super().__init__("rox_latency_benchmark")
        self.cfg = cfg
        self.args = args
        self.architecture = "setup" if args.setup else args.mode
        self.trial_id = args.trial_id
        self.pair_id = args.pair_id
        self.command_id = args.trial_id
        self.order_id = args.trial_id if args.mode == "vda" else ""
        self.operation = "rotate_90deg"
        self.motion_started = False
        self._active_native = False
        self._latest_omega = 0.0
        self._vda_result = threading.Event()
        self._vda_success: Optional[bool] = None
        self._vda_result_text = ""

        mqtt_cfg = cfg["mqtt"]
        self.mqtt = MqttSession(
            str(mqtt_cfg["host"]),
            int(mqtt_cfg["port"]),
            f"rox-benchmark-{args.trial_id[-18:]}",
        )
        self.mqtt.start()
        self.logger = ExperimentLogger(
            args.log,
            repo_root=ROOT,
            source="rox_benchmark",
            config_id=config_identifier(args.config),
            publisher=publish_json_event(self.mqtt.client, EVENT_TOPIC),
        )

        ros_cfg = cfg["ros"]
        self._odom_sub = self.create_subscription(
            Odometry, str(ros_cfg["odom_topic"]), self._on_odom, 20
        )
        self._tf_buffer = Buffer()
        self._tf_listener = TransformListener(self._tf_buffer, self)
        self._nav_client = ActionClient(
            self, NavigateToPose, str(ros_cfg["navigate_to_pose_action"])
        )
        if args.mode == "vda":
            root = self._topic_root()
            self.mqtt.client.message_callback_add(f"{root}/state", self._on_vda_state)
            self.mqtt.client.subscribe(f"{root}/state", qos=int(mqtt_cfg.get("qos", 0)))

    def close(self) -> None:
        self.logger.close()
        self.mqtt.stop()
        self.destroy_node()

    def _emit(self, event_type: str, **kwargs: Any) -> None:
        self.logger.emit(
            event_type,
            trial_id=self.trial_id,
            pair_id=self.pair_id,
            architecture=self.architecture,
            device="rox",
            operation=self.operation,
            command_id=self.command_id,
            order_id=self.order_id,
            **kwargs,
        )

    def _topic_root(self) -> str:
        vda = self.cfg["vda"]
        return (
            f"{vda['interface_name']}/{vda['major_version']}/"
            f"{vda['manufacturer']}/{vda['serial_number']}"
        )

    def _on_odom(self, message: Odometry) -> None:
        omega = float(message.twist.twist.angular.z)
        self._latest_omega = omega
        threshold = finite_number(
            self.cfg["motion_start_angular_velocity_rad_s"],
            "motion_start_angular_velocity_rad_s",
        )
        if self._active_native and not self.motion_started and abs(omega) >= threshold:
            self.motion_started = True
            self._emit(
                "MOTION_STARTED",
                result=f"abs(omega)={abs(omega):.6f} rad/s",
                success=True,
                details={"angular_velocity_rad_s": omega, "threshold_rad_s": threshold},
            )

    def _on_vda_state(self, client, userdata, message) -> None:
        try:
            state = json.loads(message.payload.decode("utf-8"))
        except Exception:
            return
        if str(state.get("orderId", "")) != self.order_id:
            return
        target_node = f"{self.trial_id}-target"
        errors = state.get("errors") or []
        if errors:
            self._vda_success = False
            self._vda_result_text = "; ".join(
                str(item.get("errorDescription") or item.get("errorType"))
                for item in errors
                if isinstance(item, dict)
            )
            self._vda_result.set()
            return
        if (
            str(state.get("lastNodeId", "")) == target_node
            and not state.get("nodeStates")
            and not bool(state.get("driving", False))
        ):
            self._vda_success = True
            self._vda_result_text = "VDA state reports target node complete"
            self._vda_result.set()

    def _target(self) -> Dict[str, float]:
        point = self.cfg["position"]
        headings = self.cfg["headings"]
        theta_a = finite_number(headings["theta_a"], "headings.theta_a")
        theta_b = finite_number(headings["theta_b"], "headings.theta_b")
        expected_b = normalize_angle(theta_a + math.pi / 2.0)
        if abs(normalize_angle(theta_b - expected_b)) > 1e-6:
            raise ValueError("headings.theta_b must equal normalize(theta_a + pi/2)")
        target_key = "theta_b" if self.args.direction == "a-to-b" else "theta_a"
        return {
            "x": finite_number(point["x"], "position.x"),
            "y": finite_number(point["y"], "position.y"),
            "theta": finite_number(headings[target_key], f"headings.{target_key}"),
        }

    def wait_for_start_pose(self, timeout: float = 10.0) -> None:
        expected_key = "theta_a" if self.args.direction == "a-to-b" else "theta_b"
        target = self._target()
        expected_theta = finite_number(self.cfg["headings"][expected_key], expected_key)
        deadline = time.monotonic() + timeout
        transform = None
        while time.monotonic() < deadline:
            rclpy.spin_once(self, timeout_sec=0.1)
            try:
                transform = self._tf_buffer.lookup_transform(
                    str(self.cfg["ros"]["map_frame"]),
                    str(self.cfg["ros"]["base_frame"]),
                    rclpy.time.Time(),
                )
                break
            except TransformException:
                continue
        if transform is None:
            raise RuntimeError("No map->base_link transform; localize ROX before benchmarking")
        q = transform.transform.rotation
        theta = math.atan2(
            2.0 * (q.w * q.z + q.x * q.y),
            1.0 - 2.0 * (q.y * q.y + q.z * q.z),
        )
        dx = float(transform.transform.translation.x) - target["x"]
        dy = float(transform.transform.translation.y) - target["y"]
        xy_error = math.hypot(dx, dy)
        theta_error = abs(normalize_angle(theta - expected_theta))
        tolerances = self.cfg["tolerances"]
        if xy_error > finite_number(tolerances["start_xy_m"], "start_xy_m"):
            raise RuntimeError(f"ROX start XY error {xy_error:.3f} m exceeds frozen tolerance")
        if theta_error > finite_number(tolerances["start_theta_rad"], "start_theta_rad"):
            raise RuntimeError(f"ROX start heading error {theta_error:.3f} rad exceeds frozen tolerance")

    def verify_target_pose(self) -> None:
        target = self._target()
        transform = self._tf_buffer.lookup_transform(
            str(self.cfg["ros"]["map_frame"]),
            str(self.cfg["ros"]["base_frame"]),
            rclpy.time.Time(),
        )
        q = transform.transform.rotation
        theta = math.atan2(
            2.0 * (q.w * q.z + q.x * q.y),
            1.0 - 2.0 * (q.y * q.y + q.z * q.z),
        )
        xy_error = math.hypot(
            float(transform.transform.translation.x) - target["x"],
            float(transform.transform.translation.y) - target["y"],
        )
        theta_error = abs(normalize_angle(theta - target["theta"]))
        if xy_error > finite_number(self.cfg["tolerances"]["target_xy_m"], "target_xy_m"):
            raise RuntimeError(f"ROX final XY error {xy_error:.3f} m exceeds tolerance")
        if theta_error > finite_number(
            self.cfg["tolerances"]["target_theta_rad"], "target_theta_rad"
        ):
            raise RuntimeError(f"ROX final heading error {theta_error:.3f} rad exceeds tolerance")

    def run_native(self) -> None:
        timeout = finite_number(self.cfg["timeouts"]["nav2_server_s"], "nav2_server_s")
        if not self._nav_client.wait_for_server(timeout_sec=timeout):
            raise RuntimeError("NavigateToPose action server is unavailable")
        target = self._target()
        goal = NavigateToPose.Goal()
        goal.pose.header.frame_id = str(self.cfg["ros"]["map_frame"])
        goal.pose.header.stamp = self.get_clock().now().to_msg()
        goal.pose.pose.position.x = target["x"]
        goal.pose.pose.position.y = target["y"]
        goal.pose.pose.orientation.z = math.sin(target["theta"] / 2.0)
        goal.pose.pose.orientation.w = math.cos(target["theta"] / 2.0)

        self._active_native = True
        self._emit("COMMAND_ISSUED", result="Native NavigateToPose prepared", success=True)
        self._emit("NATIVE_DISPATCH", result="Calling send_goal_async", success=True)
        future = self._nav_client.send_goal_async(goal)
        rclpy.spin_until_future_complete(self, future, timeout_sec=timeout)
        handle = future.result() if future.done() else None
        if handle is None or not handle.accepted:
            self._emit("NATIVE_ACK", result="Nav2 rejected or did not acknowledge goal", success=False)
            raise RuntimeError("Nav2 rejected or did not acknowledge the native goal")
        self._emit("NATIVE_ACK", result="Nav2 accepted goal", success=True)
        result_future = handle.get_result_async()
        command_timeout = finite_number(self.cfg["timeouts"]["command_s"], "command_s")
        rclpy.spin_until_future_complete(self, result_future, timeout_sec=command_timeout)
        if not result_future.done():
            handle.cancel_goal_async()
            raise TimeoutError("Native NavigateToPose trial timed out")
        wrapped = result_future.result()
        success = bool(wrapped and wrapped.status == GoalStatus.STATUS_SUCCEEDED)
        self._active_native = False
        target_error = ""
        if success:
            try:
                self.verify_target_pose()
            except Exception as exc:
                success = False
                target_error = str(exc)
        self._emit(
            "MOTION_COMPLETED",
            result=(
                target_error
                or f"Nav2 terminal status={getattr(wrapped, 'status', 'unknown')}; target verified"
            ),
            success=success,
        )
        self._emit("RESULT_OBSERVED", result="Native result received", success=success)
        if not success:
            raise RuntimeError(f"Native Nav2 trial failed with status {getattr(wrapped, 'status', None)}")

    def _vda_order(self) -> Dict[str, Any]:
        target = self._target()
        start_theta = finite_number(
            self.cfg["headings"]["theta_a" if self.args.direction == "a-to-b" else "theta_b"],
            "start heading",
        )
        vda = self.cfg["vda"]
        tolerance = finite_number(self.cfg["tolerances"]["start_xy_m"], "start_xy_m")
        position = self.cfg["position"]
        def node(node_id: str, sequence: int, theta: float) -> Dict[str, Any]:
            return {
                "nodeId": node_id,
                "sequenceId": sequence,
                "released": True,
                "nodePosition": {
                    "x": finite_number(position["x"], "position.x"),
                    "y": finite_number(position["y"], "position.y"),
                    "theta": theta,
                    "mapId": str(self.cfg["map_id"]),
                    "allowedDeviationXY": {"a": tolerance, "b": tolerance, "theta": 0.0},
                    "allowedDeviationTheta": finite_number(
                        self.cfg["tolerances"]["start_theta_rad"], "start_theta_rad"
                    ),
                },
                "actions": [],
            }
        return {
            "headerId": int(time.time_ns() % 2_147_483_647),
            "timestamp": utc_now(),
            "version": str(vda["protocol_version"]),
            "manufacturer": str(vda["manufacturer"]),
            "serialNumber": str(vda["serial_number"]),
            "orderId": self.order_id,
            "orderUpdateId": 0,
            "orderDescription": "Controlled 90-degree ROX benchmark rotation",
            "nodes": [
                node(f"{self.trial_id}-start", 0, start_theta),
                node(f"{self.trial_id}-target", 2, target["theta"]),
            ],
            "edges": [
                {
                    "edgeId": f"{self.trial_id}-edge",
                    "sequenceId": 1,
                    "released": True,
                    "actions": [],
                }
            ],
        }

    def run_vda(self) -> None:
        order = self._vda_order()
        schema = json.loads((ROOT / "schemas/vda5050_v3/order.schema").read_text(encoding="utf-8"))
        jsonschema.validate(order, schema)
        self._emit("COMMAND_ISSUED", result="Publishing VDA order", success=True)
        self.mqtt.publish_json(
            f"{self._topic_root()}/order",
            order,
            qos=int(self.cfg["mqtt"].get("qos", 0)),
        )
        timeout = finite_number(self.cfg["timeouts"]["command_s"], "command_s")
        if not self._vda_result.wait(timeout):
            self._emit("RESULT_OBSERVED", result="Timed out waiting for VDA completion", success=False)
            raise TimeoutError("VDA ROX trial timed out")
        if self._vda_success:
            try:
                self.verify_target_pose()
            except Exception as exc:
                self._vda_success = False
                self._vda_result_text = str(exc)
        self._emit(
            "RESULT_OBSERVED",
            result=self._vda_result_text,
            success=self._vda_success,
        )
        if not self._vda_success:
            raise RuntimeError(self._vda_result_text or "VDA ROX trial failed")


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser()
    parser.add_argument("--mode", choices=("native", "vda"))
    parser.add_argument("--direction", choices=("a-to-b", "b-to-a"))
    parser.add_argument("--trial-id")
    parser.add_argument("--pair-id", default="")
    parser.add_argument("--config", type=Path, default=DEFAULT_CONFIG)
    parser.add_argument("--log", type=Path, default=DEFAULT_LOG)
    parser.add_argument("--schedule", type=Path)
    parser.add_argument("--row", type=int)
    parser.add_argument("--setup", action="store_true", help="Mark this supervised reset trial as excluded")
    args = parser.parse_args()
    if args.schedule:
        if args.row is None:
            parser.error("--schedule requires --row")
        row = load_schedule_row(args.schedule, args.row)
        if row.get("device") != "rox":
            parser.error(f"Schedule row {args.row} is for {row.get('device')!r}, not rox")
        args.mode = row["mode"]
        args.direction = "a-to-b" if row["start"] == "A" else "b-to-a"
        args.trial_id = row["trial_id"]
        args.pair_id = row["pair_id"]
        args.setup = row.get("measure", "true").lower() != "true"
    if not args.direction or not args.trial_id:
        parser.error("Provide --direction and --trial-id, or --schedule and --row")
    if not args.mode:
        parser.error("Provide --mode, or load it from --schedule and --row")
    return args


def main() -> None:
    args = parse_args()
    cfg = load_config(args.config)
    rclpy.init()
    node = RoxBenchmark(cfg, args)
    try:
        node.wait_for_start_pose()
        print(
            f"Verified start pose. Running {node.architecture} {args.direction} "
            f"trial {args.trial_id}. Keep the E-stop available."
        )
        if args.mode == "native":
            node.run_native()
        else:
            node.run_vda()
        print("Trial completed successfully")
    finally:
        node.close()
        rclpy.shutdown()


if __name__ == "__main__":
    main()
