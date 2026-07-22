#!/usr/bin/env python3
"""Capture the current map->base_link pose and update a waypoint YAML file."""

from __future__ import annotations

import argparse
import math
import time
from pathlib import Path
from typing import Any, Mapping

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

    def capture(self, timeout_s: float) -> dict[str, float]:
        deadline = time.monotonic() + timeout_s
        last_error: Exception | None = None
        while rclpy.ok() and time.monotonic() < deadline:
            rclpy.spin_once(self, timeout_sec=0.1)
            try:
                transform = self.buffer.lookup_transform(
                    self.map_frame, self.base_frame, rclpy.time.Time()
                )
                q = transform.transform.rotation
                theta = math.atan2(
                    2.0 * (q.w * q.z + q.x * q.y),
                    1.0 - 2.0 * (q.y * q.y + q.z * q.z),
                )
                return {
                    "x": round(float(transform.transform.translation.x), 4),
                    "y": round(float(transform.transform.translation.y), 4),
                    "theta": round(float(theta), 4),
                }
            except TransformException as exc:
                last_error = exc
        raise RuntimeError(
            f"No transform {self.map_frame}->{self.base_frame} within "
            f"{timeout_s:.1f} s: {last_error}"
        )


def _load_document(output: Path, requested_map_id: str, force: bool) -> dict[str, Any]:
    if not output.exists():
        return {"map_id": requested_map_id, "configured": False, "waypoints": {}}

    try:
        loaded = yaml.safe_load(output.read_text(encoding="utf-8")) or {}
    except yaml.YAMLError as exc:
        raise ValueError(f"Invalid YAML in {output}: {exc}") from exc
    if not isinstance(loaded, Mapping):
        raise ValueError(f"Waypoint YAML root must be a mapping: {output}")

    document = dict(loaded)
    existing_map_id = str(document.get("map_id", "")).strip()
    if existing_map_id and existing_map_id != requested_map_id and not force:
        raise ValueError(
            f"map_id mismatch: file contains '{existing_map_id}', requested "
            f"'{requested_map_id}'. Use the correct --map-id or pass "
            "--force-map-id only after confirming the coordinates belong to that map."
        )
    document["map_id"] = requested_map_id
    document.setdefault("configured", False)
    if not isinstance(document.get("waypoints"), Mapping):
        raise ValueError("Waypoint YAML must contain a 'waypoints' mapping")
    document["waypoints"] = dict(document["waypoints"])
    return document


def main(args: Any = None) -> None:
    parser = argparse.ArgumentParser(
        description="Capture the current localized robot pose into rox_waypoints.yaml"
    )
    parser.add_argument("--name", required=True, help="Waypoint key, e.g. crane_handover")
    parser.add_argument("--output", required=True, help="Waypoint YAML file to create/update")
    parser.add_argument("--map-id", default="df_map")
    parser.add_argument("--map-frame", default="map")
    parser.add_argument("--base-frame", default="base_link")
    parser.add_argument("--timeout", type=float, default=10.0)
    parser.add_argument(
        "--force-map-id",
        action="store_true",
        help="Replace a different existing map_id after explicit operator verification",
    )
    known, ros_args = parser.parse_known_args(args=args)

    output = Path(known.output).expanduser().resolve()
    try:
        document = _load_document(output, known.map_id, known.force_map_id)
    except ValueError as exc:
        parser.error(str(exc))

    rclpy.init(args=ros_args)
    node = WaypointCapture(known.map_frame, known.base_frame)
    try:
        pose = node.capture(max(0.1, known.timeout))
    finally:
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()

    waypoints = document["waypoints"]
    existing = waypoints.get(known.name, {})
    if not isinstance(existing, Mapping):
        existing = {}
    updated = dict(existing)
    updated.update(pose)
    updated.setdefault("allowed_deviation_xy", 0.20)
    updated.setdefault("allowed_deviation_theta", 0.20)
    waypoints[known.name] = updated

    # Any recapture invalidates the previous commissioning sign-off.
    document["configured"] = False
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text(yaml.safe_dump(document, sort_keys=False), encoding="utf-8")
    print(f"Captured {known.name}: {pose}")
    print(f"Updated {output}")
    print("Set configured: true only after repeated exact Nav2 verification.")


if __name__ == "__main__":
    main()
