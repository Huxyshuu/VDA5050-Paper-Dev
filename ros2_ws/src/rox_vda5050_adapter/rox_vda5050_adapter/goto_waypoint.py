#!/usr/bin/env python3
"""Send an exact YAML waypoint to Nav2 and verify the final robot pose."""

from __future__ import annotations

import argparse
import math
import sys
import time
from pathlib import Path
from typing import Any, Mapping

import rclpy
import yaml
from action_msgs.msg import GoalStatus
from nav2_msgs.action import NavigateToPose
from rclpy.action import ActionClient
from rclpy.node import Node
from tf2_ros import Buffer, TransformException, TransformListener


def _number(value: Any, field: str, name: str) -> float:
    if isinstance(value, bool) or not isinstance(value, (int, float)):
        raise ValueError(f"Waypoint '{name}' field '{field}' must be numeric")
    result = float(value)
    if not math.isfinite(result):
        raise ValueError(f"Waypoint '{name}' field '{field}' must be finite")
    return result


def load_document(path: Path) -> tuple[str, bool, dict[str, dict[str, float]]]:
    try:
        document = yaml.safe_load(path.read_text(encoding="utf-8"))
    except FileNotFoundError as exc:
        raise ValueError(f"Waypoint file not found: {path}") from exc
    except yaml.YAMLError as exc:
        raise ValueError(f"Invalid YAML in {path}: {exc}") from exc

    if not isinstance(document, Mapping):
        raise ValueError("Waypoint YAML root must be a mapping")

    raw_waypoints = document.get("waypoints")
    if not isinstance(raw_waypoints, Mapping):
        raise ValueError("Waypoint YAML must contain a 'waypoints' mapping")

    parsed: dict[str, dict[str, float]] = {}
    for raw_name, raw_pose in raw_waypoints.items():
        name = str(raw_name).strip()
        if not name or not isinstance(raw_pose, Mapping):
            raise ValueError(f"Invalid waypoint entry: {raw_name!r}")
        allowed_xy = _number(
            raw_pose.get("allowed_deviation_xy", 0.0),
            "allowed_deviation_xy",
            name,
        )
        allowed_theta = _number(
            raw_pose.get("allowed_deviation_theta", 0.0),
            "allowed_deviation_theta",
            name,
        )
        if allowed_xy < 0.0 or allowed_theta < 0.0:
            raise ValueError(f"Waypoint '{name}' tolerances must be non-negative")
        parsed[name] = {
            "x": _number(raw_pose.get("x"), "x", name),
            "y": _number(raw_pose.get("y"), "y", name),
            "theta": _number(raw_pose.get("theta"), "theta", name),
            "allowed_deviation_xy": allowed_xy,
            "allowed_deviation_theta": allowed_theta,
        }

    return str(document.get("map_id", "")).strip(), bool(
        document.get("configured", False)
    ), parsed


def normalize_angle(angle: float) -> float:
    return math.atan2(math.sin(angle), math.cos(angle))


def duration_seconds(duration: Any) -> float | None:
    if duration is None:
        return None
    sec = getattr(duration, "sec", None)
    nanosec = getattr(duration, "nanosec", None)
    if sec is None or nanosec is None:
        return None
    return float(sec) + float(nanosec) / 1_000_000_000.0


class WaypointNavigator(Node):
    def __init__(self, action_name: str, frame_id: str, base_frame: str) -> None:
        super().__init__("goto_rox_waypoint")
        self.action_name = action_name
        self.frame_id = frame_id
        self.base_frame = base_frame
        self.client = ActionClient(self, NavigateToPose, action_name)
        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)
        self._last_feedback_print = 0.0
        self.goal_handle = None

    def feedback_callback(self, message: Any) -> None:
        now = time.monotonic()
        if now - self._last_feedback_print < 1.0:
            return
        self._last_feedback_print = now
        feedback = message.feedback
        distance = getattr(feedback, "distance_remaining", None)
        recoveries = getattr(feedback, "number_of_recoveries", None)
        eta = duration_seconds(getattr(feedback, "estimated_time_remaining", None))
        parts = []
        if distance is not None:
            parts.append(f"remaining={float(distance):.2f} m")
        if eta is not None:
            parts.append(f"eta={eta:.1f} s")
        if recoveries is not None:
            parts.append(f"recoveries={int(recoveries)}")
        if parts:
            self.get_logger().info("Nav2 feedback: " + ", ".join(parts))

    def send_goal(
        self,
        waypoint_name: str,
        pose: Mapping[str, float],
        server_timeout: float,
        result_timeout: float,
    ) -> tuple[int, Any]:
        if not self.client.wait_for_server(timeout_sec=server_timeout):
            self.get_logger().error(
                f"Nav2 action server '{self.action_name}' was not available within "
                f"{server_timeout:.1f} s"
            )
            return 2, None

        goal = NavigateToPose.Goal()
        goal.pose.header.frame_id = self.frame_id
        goal.pose.header.stamp = self.get_clock().now().to_msg()
        goal.pose.pose.position.x = pose["x"]
        goal.pose.pose.position.y = pose["y"]
        goal.pose.pose.position.z = 0.0
        goal.pose.pose.orientation.z = math.sin(pose["theta"] / 2.0)
        goal.pose.pose.orientation.w = math.cos(pose["theta"] / 2.0)

        self.get_logger().info(
            f"Sending '{waypoint_name}' to {self.action_name}: "
            f"x={pose['x']:.4f}, y={pose['y']:.4f}, "
            f"theta={pose['theta']:.4f} rad "
            f"({math.degrees(pose['theta']):.1f} deg), frame={self.frame_id}"
        )

        send_future = self.client.send_goal_async(
            goal, feedback_callback=self.feedback_callback
        )
        rclpy.spin_until_future_complete(self, send_future, timeout_sec=server_timeout)
        if not send_future.done():
            self.get_logger().error("Timed out while sending the Nav2 goal")
            return 2, None

        self.goal_handle = send_future.result()
        if self.goal_handle is None or not self.goal_handle.accepted:
            self.get_logger().error("Nav2 rejected the waypoint goal")
            return 3, None

        self.get_logger().info("Goal accepted by Nav2")
        result_future = self.goal_handle.get_result_async()
        rclpy.spin_until_future_complete(self, result_future, timeout_sec=result_timeout)
        if not result_future.done():
            self.get_logger().error(
                f"Navigation did not finish within {result_timeout:.1f} s; cancelling"
            )
            cancel_future = self.goal_handle.cancel_goal_async()
            rclpy.spin_until_future_complete(self, cancel_future, timeout_sec=5.0)
            return 4, None

        wrapped = result_future.result()
        if wrapped is None:
            self.get_logger().error("Nav2 returned no result")
            return 4, None

        status = int(wrapped.status)
        if status != GoalStatus.STATUS_SUCCEEDED:
            names = {
                GoalStatus.STATUS_CANCELED: "CANCELED",
                GoalStatus.STATUS_ABORTED: "ABORTED",
            }
            label = names.get(status, f"status={status}")
            result = wrapped.result
            error_code = getattr(result, "error_code", None)
            error_msg = getattr(result, "error_msg", "")
            details = ""
            if error_code not in (None, 0):
                details += f", error_code={error_code}"
            if error_msg:
                details += f", error_msg={error_msg}"
            self.get_logger().error(f"Navigation finished as {label}{details}")
            return 5, wrapped

        self.get_logger().info("Nav2 reported SUCCEEDED")
        return 0, wrapped

    def final_pose(self, timeout_s: float) -> tuple[float, float, float]:
        deadline = time.monotonic() + timeout_s
        last_error: Exception | None = None
        while rclpy.ok() and time.monotonic() < deadline:
            rclpy.spin_once(self, timeout_sec=0.1)
            try:
                transform = self.tf_buffer.lookup_transform(
                    self.frame_id, self.base_frame, rclpy.time.Time()
                )
                q = transform.transform.rotation
                theta = math.atan2(
                    2.0 * (q.w * q.z + q.x * q.y),
                    1.0 - 2.0 * (q.y * q.y + q.z * q.z),
                )
                return (
                    float(transform.transform.translation.x),
                    float(transform.transform.translation.y),
                    float(theta),
                )
            except TransformException as exc:
                last_error = exc
        raise RuntimeError(
            f"No transform {self.frame_id}->{self.base_frame} within "
            f"{timeout_s:.1f} s: {last_error}"
        )

    def cancel_active_goal(self) -> None:
        if self.goal_handle is None:
            return
        try:
            future = self.goal_handle.cancel_goal_async()
            rclpy.spin_until_future_complete(self, future, timeout_sec=5.0)
        except Exception as exc:  # best effort during interruption
            self.get_logger().warning(f"Could not cancel the active goal cleanly: {exc}")


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(
        description=(
            "Read a named pose from rox_waypoints.yaml, send the exact pose to "
            "Nav2 NavigateToPose, and compare the final TF pose with the YAML "
            "tolerances."
        )
    )
    selection = parser.add_mutually_exclusive_group(required=True)
    selection.add_argument("--name", help="Waypoint name, e.g. crane_handover")
    selection.add_argument(
        "--list", action="store_true", help="List available waypoints and exit"
    )
    parser.add_argument("--waypoint-file", required=True)
    parser.add_argument("--action-name", default="/navigate_to_pose")
    parser.add_argument("--frame-id", default="map")
    parser.add_argument("--base-frame", default="base_link")
    parser.add_argument("--expected-map-id", default="")
    parser.add_argument("--server-timeout", type=float, default=10.0)
    parser.add_argument("--result-timeout", type=float, default=300.0)
    parser.add_argument("--tf-timeout", type=float, default=5.0)
    parser.add_argument(
        "--require-configured",
        action="store_true",
        help="Refuse to move when the YAML has configured: false",
    )
    parser.add_argument(
        "--skip-final-check",
        action="store_true",
        help="Do not compare the final map->base_link TF pose with YAML tolerances",
    )
    parser.add_argument(
        "--dry-run",
        action="store_true",
        help="Validate and print the exact goal without sending robot motion",
    )
    return parser


def main(args: Any = None) -> None:
    parser = build_parser()
    known, ros_args = parser.parse_known_args(args=args)
    path = Path(known.waypoint_file).expanduser().resolve()

    try:
        map_id, configured, waypoints = load_document(path)
    except ValueError as exc:
        parser.error(str(exc))

    if known.list:
        print(f"waypoint_file: {path}")
        print(f"map_id: {map_id or '<empty>'}")
        print(f"configured: {'true' if configured else 'false'}")
        for name, pose in waypoints.items():
            print(
                f"- {name}: x={pose['x']:.4f}, y={pose['y']:.4f}, "
                f"theta={pose['theta']:.4f} rad "
                f"({math.degrees(pose['theta']):.1f} deg), "
                f"tol_xy={pose['allowed_deviation_xy']:.3f} m, "
                f"tol_theta={pose['allowed_deviation_theta']:.3f} rad"
            )
        return

    if known.name not in waypoints:
        available = ", ".join(waypoints) or "<none>"
        parser.error(f"Unknown waypoint '{known.name}'. Available: {available}")

    if known.expected_map_id and map_id != known.expected_map_id:
        parser.error(
            f"map_id mismatch: file contains '{map_id}', expected "
            f"'{known.expected_map_id}'"
        )

    if known.require_configured and not configured:
        parser.error("Waypoint file has configured: false")

    pose = waypoints[known.name]
    print(f"waypoint_file: {path}")
    print(f"map_id: {map_id or '<empty>'}")
    print(f"configured: {'true' if configured else 'false'}")
    if not configured:
        print(
            "WARNING: configured is false. This is allowed for commissioning, "
            "but the pose has not yet been signed off.",
            file=sys.stderr,
        )
    print(
        f"target: {known.name} | x={pose['x']:.4f}, y={pose['y']:.4f}, "
        f"theta={pose['theta']:.4f} rad ({math.degrees(pose['theta']):.1f} deg)"
    )

    if known.dry_run:
        print(
            "dry-run: goal not sent; quaternion "
            f"z={math.sin(pose['theta'] / 2.0):.6f}, "
            f"w={math.cos(pose['theta'] / 2.0):.6f}"
        )
        return

    rclpy.init(args=ros_args)
    node = WaypointNavigator(known.action_name, known.frame_id, known.base_frame)
    exit_code = 1
    try:
        exit_code, _ = node.send_goal(
            known.name,
            pose,
            max(0.1, known.server_timeout),
            max(0.1, known.result_timeout),
        )
        if exit_code == 0 and not known.skip_final_check:
            actual_x, actual_y, actual_theta = node.final_pose(
                max(0.1, known.tf_timeout)
            )
            xy_error = math.hypot(actual_x - pose["x"], actual_y - pose["y"])
            yaw_error = abs(normalize_angle(actual_theta - pose["theta"]))
            xy_ok = xy_error <= pose["allowed_deviation_xy"]
            yaw_ok = yaw_error <= pose["allowed_deviation_theta"]
            print(
                f"final pose: x={actual_x:.4f}, y={actual_y:.4f}, "
                f"theta={actual_theta:.4f} rad "
                f"({math.degrees(actual_theta):.1f} deg)"
            )
            print(
                f"errors: xy={xy_error:.4f} m / "
                f"allowed {pose['allowed_deviation_xy']:.4f} m; "
                f"yaw={yaw_error:.4f} rad "
                f"({math.degrees(yaw_error):.1f} deg) / "
                f"allowed {pose['allowed_deviation_theta']:.4f} rad"
            )
            if xy_ok and yaw_ok:
                print("WAYPOINT CHECK: PASS")
            else:
                print("WAYPOINT CHECK: FAIL", file=sys.stderr)
                exit_code = 6
    except KeyboardInterrupt:
        print("Interrupted; requesting Nav2 goal cancellation", file=sys.stderr)
        node.cancel_active_goal()
        exit_code = 130
    except RuntimeError as exc:
        node.get_logger().error(str(exc))
        exit_code = 7
    finally:
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()

    raise SystemExit(exit_code)


if __name__ == "__main__":
    main()
