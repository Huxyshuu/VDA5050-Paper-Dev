"""Capture the current map->base_link pose and update a waypoint YAML file."""

from __future__ import annotations

import argparse
import math
import time
from pathlib import Path

import rclpy
import yaml
from rclpy.node import Node
from tf2_ros import Buffer, TransformException, TransformListener


class WaypointCapture(Node):
    def __init__(self, map_frame: str, base_frame: str) -> None:
        super().__init__("capture_rox_waypoint")
        self.buffer = Buffer()
        self.listener = TransformListener(self.buffer, self)
        self.map_frame = map_frame
        self.base_frame = base_frame

    def capture(self, timeout_s: float):
        deadline = time.monotonic() + timeout_s
        while rclpy.ok() and time.monotonic() < deadline:
            rclpy.spin_once(self, timeout_sec=0.1)
            try:
                t = self.buffer.lookup_transform(
                    self.map_frame, self.base_frame, rclpy.time.Time()
                )
                q = t.transform.rotation
                theta = math.atan2(
                    2.0 * (q.w * q.z + q.x * q.y),
                    1.0 - 2.0 * (q.y * q.y + q.z * q.z),
                )
                return {
                    "x": round(float(t.transform.translation.x), 4),
                    "y": round(float(t.transform.translation.y), 4),
                    "theta": round(float(theta), 4),
                }
            except TransformException:
                continue
        raise RuntimeError(
            f"No transform {self.map_frame}->{self.base_frame} within {timeout_s}s"
        )


def main(args=None) -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--name", required=True, help="Waypoint key, e.g. crane_handover")
    parser.add_argument("--output", required=True, help="Waypoint YAML file to create/update")
    parser.add_argument("--map-id", default="warehouse_case_study")
    parser.add_argument("--map-frame", default="map")
    parser.add_argument("--base-frame", default="base_link")
    parser.add_argument("--timeout", type=float, default=10.0)
    known, ros_args = parser.parse_known_args(args=args)

    rclpy.init(args=ros_args)
    node = WaypointCapture(known.map_frame, known.base_frame)
    try:
        pose = node.capture(known.timeout)
    finally:
        node.destroy_node()
        rclpy.shutdown()

    output = Path(known.output).expanduser()
    if output.exists():
        document = yaml.safe_load(output.read_text(encoding="utf-8")) or {}
    else:
        document = {"map_id": known.map_id, "configured": False, "waypoints": {}}
    document.setdefault("map_id", known.map_id)
    document.setdefault("configured", False)
    waypoints = document.setdefault("waypoints", {})
    existing = waypoints.get(known.name, {})
    if not isinstance(existing, dict):
        existing = {}
    existing.update(pose)
    waypoints[known.name] = existing
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text(yaml.safe_dump(document, sort_keys=False), encoding="utf-8")
    print(f"Captured {known.name}: {pose}")
    print(f"Updated {output}. Keep configured=false until all required waypoints are captured and checked.")


if __name__ == "__main__":
    main()
