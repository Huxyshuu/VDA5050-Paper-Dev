#!/usr/bin/env python3
"""Publish named ROX waypoints from YAML as persistent RViz MarkerArray markers."""

from __future__ import annotations

import math
import os
from pathlib import Path
from typing import Any, Dict, Iterable, Mapping, Tuple

import rclpy
from geometry_msgs.msg import Point
from rclpy.node import Node
from rclpy.qos import DurabilityPolicy, HistoryPolicy, QoSProfile, ReliabilityPolicy
from visualization_msgs.msg import Marker, MarkerArray
import yaml


Color = Tuple[float, float, float]

# A small, high-contrast palette. Alpha is assigned per marker type.
PALETTE: Tuple[Color, ...] = (
    (0.15, 0.55, 0.95),
    (0.95, 0.45, 0.15),
    (0.20, 0.75, 0.35),
    (0.75, 0.35, 0.90),
    (0.95, 0.75, 0.10),
    (0.10, 0.75, 0.75),
)


def _require_number(value: Any, field: str, waypoint_name: str) -> float:
    if isinstance(value, bool) or not isinstance(value, (int, float)):
        raise ValueError(
            f"Waypoint '{waypoint_name}' field '{field}' must be numeric, got {value!r}"
        )
    result = float(value)
    if not math.isfinite(result):
        raise ValueError(
            f"Waypoint '{waypoint_name}' field '{field}' must be finite, got {value!r}"
        )
    return result


def load_waypoints(path: Path) -> Tuple[str, bool, Dict[str, Dict[str, float]]]:
    """Load and validate the project waypoint YAML structure."""
    with path.open("r", encoding="utf-8") as stream:
        document = yaml.safe_load(stream)

    if not isinstance(document, Mapping):
        raise ValueError("Waypoint YAML root must be a mapping")

    map_id = str(document.get("map_id", ""))
    configured = bool(document.get("configured", False))
    raw_waypoints = document.get("waypoints")
    if not isinstance(raw_waypoints, Mapping):
        raise ValueError("Waypoint YAML must contain a 'waypoints' mapping")

    parsed: Dict[str, Dict[str, float]] = {}
    for raw_name, raw_pose in raw_waypoints.items():
        name = str(raw_name).strip()
        if not name:
            raise ValueError("Waypoint names must not be empty")
        if not isinstance(raw_pose, Mapping):
            raise ValueError(f"Waypoint '{name}' must be a mapping")

        x = _require_number(raw_pose.get("x"), "x", name)
        y = _require_number(raw_pose.get("y"), "y", name)
        theta = _require_number(raw_pose.get("theta"), "theta", name)
        allowed_xy = _require_number(
            raw_pose.get("allowed_deviation_xy", 0.0),
            "allowed_deviation_xy",
            name,
        )
        allowed_theta = _require_number(
            raw_pose.get("allowed_deviation_theta", 0.0),
            "allowed_deviation_theta",
            name,
        )
        if allowed_xy < 0.0:
            raise ValueError(
                f"Waypoint '{name}' allowed_deviation_xy must be non-negative"
            )
        if allowed_theta < 0.0:
            raise ValueError(
                f"Waypoint '{name}' allowed_deviation_theta must be non-negative"
            )

        parsed[name] = {
            "x": x,
            "y": y,
            "theta": theta,
            "allowed_deviation_xy": allowed_xy,
            "allowed_deviation_theta": allowed_theta,
        }

    return map_id, configured, parsed


class WaypointVisualizer(Node):
    """Read a waypoint file and publish persistent labelled markers for RViz."""

    def __init__(self) -> None:
        super().__init__("waypoint_visualizer")

        self.declare_parameter("waypoint_file", "")
        self.declare_parameter("frame_id", "map")
        self.declare_parameter("marker_topic", "/rox_waypoints/markers")
        self.declare_parameter("reload_period", 1.0)
        self.declare_parameter("show_tolerances", True)
        self.declare_parameter("marker_diameter", 0.18)
        self.declare_parameter("arrow_length", 0.55)
        self.declare_parameter("label_height", 0.42)
        self.declare_parameter("text_size", 0.16)

        raw_path = str(self.get_parameter("waypoint_file").value).strip()
        if not raw_path:
            raise ValueError(
                "Parameter 'waypoint_file' is required. Pass the absolute path to "
                "configs/rox_waypoints.yaml."
            )
        self._waypoint_file = Path(os.path.expandvars(os.path.expanduser(raw_path)))
        self._frame_id = str(self.get_parameter("frame_id").value).strip() or "map"
        self._topic = str(self.get_parameter("marker_topic").value).strip()
        self._show_tolerances = bool(self.get_parameter("show_tolerances").value)
        self._marker_diameter = max(
            0.02, float(self.get_parameter("marker_diameter").value)
        )
        self._arrow_length = max(0.05, float(self.get_parameter("arrow_length").value))
        self._label_height = max(0.05, float(self.get_parameter("label_height").value))
        self._text_size = max(0.05, float(self.get_parameter("text_size").value))
        reload_period = max(0.2, float(self.get_parameter("reload_period").value))

        qos = QoSProfile(
            history=HistoryPolicy.KEEP_LAST,
            depth=1,
            reliability=ReliabilityPolicy.RELIABLE,
            durability=DurabilityPolicy.TRANSIENT_LOCAL,
        )
        self._publisher = self.create_publisher(MarkerArray, self._topic, qos)
        self._last_mtime_ns: int | None = None
        self._last_success_signature: Tuple[Any, ...] | None = None
        self._timer = self.create_timer(reload_period, self._reload_if_needed)

        self.get_logger().info(
            f"Visualizing waypoints from {self._waypoint_file} in frame "
            f"'{self._frame_id}' on {self._topic}"
        )
        self._reload_if_needed(force=True)

    def _reload_if_needed(self, force: bool = False) -> None:
        try:
            stat = self._waypoint_file.stat()
        except FileNotFoundError:
            self.get_logger().error(
                f"Waypoint file not found: {self._waypoint_file}",
                throttle_duration_sec=5.0,
            )
            return
        except OSError as exc:
            self.get_logger().error(
                f"Cannot stat waypoint file {self._waypoint_file}: {exc}",
                throttle_duration_sec=5.0,
            )
            return

        if not force and self._last_mtime_ns == stat.st_mtime_ns:
            return

        try:
            map_id, configured, waypoints = load_waypoints(self._waypoint_file)
        except (OSError, yaml.YAMLError, ValueError) as exc:
            self.get_logger().error(
                f"Could not load {self._waypoint_file}: {exc}. "
                "Keeping the last successfully published markers."
            )
            self._last_mtime_ns = stat.st_mtime_ns
            return

        signature = (
            map_id,
            configured,
            tuple((name, tuple(sorted(values.items()))) for name, values in waypoints.items()),
        )
        self._last_mtime_ns = stat.st_mtime_ns
        if not force and signature == self._last_success_signature:
            return

        self._warn_about_duplicate_poses(waypoints)
        self._publish_markers(map_id, configured, waypoints)
        self._last_success_signature = signature
        state = "configured" if configured else "NOT configured"
        self.get_logger().info(
            f"Published {len(waypoints)} waypoint(s) for map_id='{map_id}' ({state})"
        )

    def _warn_about_duplicate_poses(
        self, waypoints: Mapping[str, Mapping[str, float]]
    ) -> None:
        items = list(waypoints.items())
        for index, (name_a, pose_a) in enumerate(items):
            for name_b, pose_b in items[index + 1 :]:
                distance = math.hypot(
                    pose_a["x"] - pose_b["x"], pose_a["y"] - pose_b["y"]
                )
                angle = abs(_normalize_angle(pose_a["theta"] - pose_b["theta"]))
                if distance < 1e-4 and angle < 1e-4:
                    self.get_logger().warning(
                        f"Waypoints '{name_a}' and '{name_b}' have the same pose. "
                        "They may still contain placeholder values."
                    )

    def _publish_markers(
        self,
        map_id: str,
        configured: bool,
        waypoints: Mapping[str, Mapping[str, float]],
    ) -> None:
        # Clear markers that belonged to removed or renamed waypoints.
        delete_all = Marker()
        delete_all.action = Marker.DELETEALL
        self._publisher.publish(MarkerArray(markers=[delete_all]))

        now = self.get_clock().now().to_msg()
        markers = []
        for index, (name, pose) in enumerate(waypoints.items()):
            color = PALETTE[index % len(PALETTE)]
            base_id = index * 10
            x = pose["x"]
            y = pose["y"]
            theta = pose["theta"]
            allowed_xy = pose["allowed_deviation_xy"]
            allowed_theta = pose["allowed_deviation_theta"]

            point = self._base_marker(now, "waypoint_point", base_id, color)
            point.type = Marker.CYLINDER
            point.pose.position.x = x
            point.pose.position.y = y
            point.pose.position.z = 0.035
            point.pose.orientation.w = 1.0
            point.scale.x = self._marker_diameter
            point.scale.y = self._marker_diameter
            point.scale.z = 0.07
            point.color.a = 0.95
            markers.append(point)

            arrow = self._base_marker(now, "waypoint_heading", base_id + 1, color)
            arrow.type = Marker.ARROW
            arrow.pose.position.x = x
            arrow.pose.position.y = y
            arrow.pose.position.z = 0.09
            arrow.pose.orientation.z = math.sin(theta / 2.0)
            arrow.pose.orientation.w = math.cos(theta / 2.0)
            arrow.scale.x = self._arrow_length
            arrow.scale.y = 0.10
            arrow.scale.z = 0.10
            arrow.color.a = 1.0
            markers.append(arrow)

            label = self._base_marker(now, "waypoint_label", base_id + 2, color)
            label.type = Marker.TEXT_VIEW_FACING
            label.pose.position.x = x
            label.pose.position.y = y
            label.pose.position.z = self._label_height
            label.pose.orientation.w = 1.0
            label.scale.z = self._text_size
            label.color.r = 1.0
            label.color.g = 1.0
            label.color.b = 1.0
            label.color.a = 1.0
            status = "" if configured else " [UNCONFIGURED]"
            label.text = (
                f"{name}{status}\n"
                f"x={x:.3f}  y={y:.3f}  yaw={math.degrees(theta):.1f}°\n"
                f"tol: {allowed_xy:.2f} m / {math.degrees(allowed_theta):.1f}°"
            )
            markers.append(label)

            if self._show_tolerances and allowed_xy > 0.0:
                circle = self._base_marker(
                    now, "waypoint_xy_tolerance", base_id + 3, color
                )
                circle.type = Marker.LINE_STRIP
                circle.pose.orientation.w = 1.0
                circle.scale.x = 0.025
                circle.color.a = 0.75
                circle.points = list(_circle_points(x, y, allowed_xy, 64, 0.025))
                markers.append(circle)

            if self._show_tolerances and allowed_theta > 0.0:
                rays = self._base_marker(
                    now, "waypoint_yaw_tolerance", base_id + 4, color
                )
                rays.type = Marker.LINE_LIST
                rays.pose.orientation.w = 1.0
                rays.scale.x = 0.025
                rays.color.a = 0.75
                ray_length = max(self._arrow_length * 0.85, allowed_xy)
                centre = Point(x=x, y=y, z=0.03)
                for ray_angle in (theta - allowed_theta, theta + allowed_theta):
                    endpoint = Point(
                        x=x + ray_length * math.cos(ray_angle),
                        y=y + ray_length * math.sin(ray_angle),
                        z=0.03,
                    )
                    rays.points.extend((centre, endpoint))
                markers.append(rays)

        # Add a small map/status label near the first waypoint, if present.
        if waypoints:
            first_pose = next(iter(waypoints.values()))
            status_marker = self._base_marker(
                now, "waypoint_file_status", len(waypoints) * 10 + 1, (0.8, 0.8, 0.8)
            )
            status_marker.type = Marker.TEXT_VIEW_FACING
            status_marker.pose.position.x = first_pose["x"]
            status_marker.pose.position.y = first_pose["y"]
            status_marker.pose.position.z = self._label_height + 0.38
            status_marker.pose.orientation.w = 1.0
            status_marker.scale.z = max(0.10, self._text_size * 0.85)
            status_marker.color.r = 0.85 if configured else 1.0
            status_marker.color.g = 0.85 if configured else 0.45
            status_marker.color.b = 0.85 if configured else 0.10
            status_marker.color.a = 1.0
            status_marker.text = (
                f"map_id: {map_id or '<empty>'} | configured: "
                f"{'true' if configured else 'false'}"
            )
            markers.append(status_marker)

        self._publisher.publish(MarkerArray(markers=markers))

    def _base_marker(
        self, stamp: Any, namespace: str, marker_id: int, color: Color
    ) -> Marker:
        marker = Marker()
        marker.header.frame_id = self._frame_id
        marker.header.stamp = stamp
        marker.ns = namespace
        marker.id = marker_id
        marker.action = Marker.ADD
        marker.frame_locked = True
        marker.color.r, marker.color.g, marker.color.b = color
        return marker


def _circle_points(
    centre_x: float,
    centre_y: float,
    radius: float,
    segments: int,
    z: float,
) -> Iterable[Point]:
    for index in range(segments + 1):
        angle = 2.0 * math.pi * index / segments
        yield Point(
            x=centre_x + radius * math.cos(angle),
            y=centre_y + radius * math.sin(angle),
            z=z,
        )


def _normalize_angle(angle: float) -> float:
    return math.atan2(math.sin(angle), math.cos(angle))


def main(args: Any = None) -> None:
    rclpy.init(args=args)
    node: WaypointVisualizer | None = None
    try:
        node = WaypointVisualizer()
        rclpy.spin(node)
    except (KeyboardInterrupt, ExternalShutdownException):
        pass
    except Exception as exc:  # startup/configuration error
        if node is not None:
            node.get_logger().fatal(str(exc))
        else:
            print(f"waypoint_visualizer: {exc}")
        raise
    finally:
        if node is not None:
            node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()


# Imported late to keep the normal imports visually focused on message/runtime types.
from rclpy.executors import ExternalShutdownException  # noqa: E402


if __name__ == "__main__":
    main()
