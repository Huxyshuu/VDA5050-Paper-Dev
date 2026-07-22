#!/usr/bin/env python3
"""Persist and restore the ROX-Diff AMCL initial pose across Nav2 restarts."""

from __future__ import annotations

import argparse
import hashlib
import math
import os
import signal
import sys
import tempfile
import time
from datetime import datetime, timezone
from pathlib import Path
from typing import Any, Mapping

import rclpy
import yaml
from geometry_msgs.msg import PoseWithCovarianceStamped
from nav_msgs.msg import OccupancyGrid
from rclpy.node import Node
from rclpy.qos import DurabilityPolicy, QoSProfile, ReliabilityPolicy
from tf2_ros import Buffer, TransformException, TransformListener


def normalize_angle(angle: float) -> float:
    return math.atan2(math.sin(angle), math.cos(angle))


def quaternion_to_yaw(q: Any) -> float:
    return math.atan2(
        2.0 * (q.w * q.z + q.x * q.y),
        1.0 - 2.0 * (q.y * q.y + q.z * q.z),
    )


def yaw_to_quaternion(yaw: float) -> tuple[float, float, float, float]:
    return (0.0, 0.0, math.sin(yaw / 2.0), math.cos(yaw / 2.0))


def parse_bool(value: str) -> bool:
    lowered = value.strip().lower()
    if lowered in {"1", "true", "yes", "on"}:
        return True
    if lowered in {"0", "false", "no", "off"}:
        return False
    raise argparse.ArgumentTypeError(f"Expected true/false, got {value!r}")


def boot_id() -> str:
    path = Path("/proc/sys/kernel/random/boot_id")
    try:
        return path.read_text(encoding="utf-8").strip()
    except OSError:
        return ""


def _sha256_file(path: Path, digest: "hashlib._Hash") -> None:
    with path.open("rb") as stream:
        for chunk in iter(lambda: stream.read(1024 * 1024), b""):
            digest.update(chunk)


def map_fingerprint(map_yaml: Path) -> str:
    """Hash the map YAML and referenced image so stale poses are not reused."""
    map_yaml = map_yaml.expanduser().resolve()
    digest = hashlib.sha256()
    _sha256_file(map_yaml, digest)

    try:
        document = yaml.safe_load(map_yaml.read_text(encoding="utf-8")) or {}
    except yaml.YAMLError as exc:
        raise ValueError(f"Invalid map YAML {map_yaml}: {exc}") from exc

    if not isinstance(document, Mapping):
        raise ValueError(f"Map YAML root must be a mapping: {map_yaml}")

    image_value = document.get("image")
    if image_value:
        image_path = Path(str(image_value)).expanduser()
        if not image_path.is_absolute():
            image_path = map_yaml.parent / image_path
        image_path = image_path.resolve()
        if not image_path.is_file():
            raise ValueError(
                f"Map image referenced by {map_yaml} was not found: {image_path}"
            )
        _sha256_file(image_path, digest)

    return digest.hexdigest()


def atomic_write_yaml(path: Path, document: Mapping[str, Any]) -> None:
    path = path.expanduser().resolve()
    path.parent.mkdir(parents=True, exist_ok=True)
    payload = yaml.safe_dump(dict(document), sort_keys=False)

    fd, temporary_name = tempfile.mkstemp(
        prefix=f".{path.name}.", suffix=".tmp", dir=str(path.parent)
    )
    temporary = Path(temporary_name)
    try:
        with os.fdopen(fd, "w", encoding="utf-8") as stream:
            stream.write(payload)
            stream.flush()
            os.fsync(stream.fileno())
        os.replace(temporary, path)
    finally:
        try:
            temporary.unlink(missing_ok=True)
        except OSError:
            pass


def load_pose_file(path: Path) -> dict[str, Any]:
    path = path.expanduser().resolve()
    try:
        document = yaml.safe_load(path.read_text(encoding="utf-8"))
    except FileNotFoundError as exc:
        raise ValueError(f"No saved pose exists: {path}") from exc
    except yaml.YAMLError as exc:
        raise ValueError(f"Invalid saved-pose YAML {path}: {exc}") from exc

    if not isinstance(document, Mapping):
        raise ValueError(f"Saved-pose YAML root must be a mapping: {path}")
    if int(document.get("version", 0)) != 1:
        raise ValueError(f"Unsupported saved-pose version in {path}")

    pose = document.get("pose")
    if not isinstance(pose, Mapping):
        raise ValueError(f"Saved-pose file has no valid 'pose' mapping: {path}")

    for field in ("x", "y", "theta"):
        value = pose.get(field)
        if isinstance(value, bool) or not isinstance(value, (int, float)):
            raise ValueError(f"Saved pose field '{field}' must be numeric")
        if not math.isfinite(float(value)):
            raise ValueError(f"Saved pose field '{field}' must be finite")

    return dict(document)


def pose_from_document(document: Mapping[str, Any]) -> tuple[float, float, float]:
    pose = document["pose"]
    return float(pose["x"]), float(pose["y"]), float(pose["theta"])


def age_hours(document: Mapping[str, Any]) -> float | None:
    raw = str(document.get("saved_at", "")).strip()
    if not raw:
        return None
    try:
        timestamp = datetime.fromisoformat(raw.replace("Z", "+00:00"))
    except ValueError:
        return None
    if timestamp.tzinfo is None:
        timestamp = timestamp.replace(tzinfo=timezone.utc)
    return max(0.0, (datetime.now(timezone.utc) - timestamp).total_seconds() / 3600.0)


class PosePersistence(Node):
    def __init__(
        self,
        map_frame: str,
        base_frame: str,
        odom_frame: str,
        initialpose_topic: str,
        map_topic: str,
    ) -> None:
        super().__init__("rox_pose_persistence")
        self.map_frame = map_frame
        self.base_frame = base_frame
        self.odom_frame = odom_frame
        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)
        self.map_received = False

        initialpose_qos = QoSProfile(depth=1)
        initialpose_qos.reliability = ReliabilityPolicy.RELIABLE
        initialpose_qos.durability = DurabilityPolicy.VOLATILE
        self.initialpose_publisher = self.create_publisher(
            PoseWithCovarianceStamped, initialpose_topic, initialpose_qos
        )

        map_qos = QoSProfile(depth=1)
        map_qos.reliability = ReliabilityPolicy.RELIABLE
        map_qos.durability = DurabilityPolicy.TRANSIENT_LOCAL
        self.map_subscription = self.create_subscription(
            OccupancyGrid, map_topic, self._map_callback, map_qos
        )

    def _map_callback(self, _message: OccupancyGrid) -> None:
        self.map_received = True

    def lookup_pose(
        self, parent_frame: str, child_frame: str, timeout_s: float
    ) -> tuple[float, float, float, tuple[float, float, float, float]]:
        deadline = time.monotonic() + max(0.1, timeout_s)
        last_error: Exception | None = None
        while rclpy.ok() and time.monotonic() < deadline:
            rclpy.spin_once(self, timeout_sec=0.1)
            try:
                transform = self.tf_buffer.lookup_transform(
                    parent_frame, child_frame, rclpy.time.Time()
                )
                q = transform.transform.rotation
                return (
                    float(transform.transform.translation.x),
                    float(transform.transform.translation.y),
                    float(quaternion_to_yaw(q)),
                    (float(q.x), float(q.y), float(q.z), float(q.w)),
                )
            except TransformException as exc:
                last_error = exc
        raise RuntimeError(
            f"No transform {parent_frame}->{child_frame} within "
            f"{timeout_s:.1f} s: {last_error}"
        )

    def wait_until_restore_ready(self, timeout_s: float) -> bool:
        deadline = time.monotonic() + max(0.1, timeout_s)
        while rclpy.ok() and time.monotonic() < deadline:
            rclpy.spin_once(self, timeout_sec=0.1)
            if self.map_received and self.initialpose_publisher.get_subscription_count() > 0:
                return True
        return False

    def publish_initial_pose(
        self,
        x: float,
        y: float,
        theta: float,
        xy_stddev: float,
        yaw_stddev: float,
        count: int,
        period_s: float,
    ) -> None:
        message = PoseWithCovarianceStamped()
        message.header.frame_id = self.map_frame
        message.pose.pose.position.x = x
        message.pose.pose.position.y = y
        message.pose.pose.position.z = 0.0
        qx, qy, qz, qw = yaw_to_quaternion(theta)
        message.pose.pose.orientation.x = qx
        message.pose.pose.orientation.y = qy
        message.pose.pose.orientation.z = qz
        message.pose.pose.orientation.w = qw
        message.pose.covariance[0] = xy_stddev * xy_stddev
        message.pose.covariance[7] = xy_stddev * xy_stddev
        message.pose.covariance[35] = yaw_stddev * yaw_stddev

        for index in range(max(1, count)):
            message.header.stamp = self.get_clock().now().to_msg()
            self.initialpose_publisher.publish(message)
            self.get_logger().info(
                f"Published saved initial pose {index + 1}/{max(1, count)}: "
                f"x={x:.4f}, y={y:.4f}, theta={theta:.4f} rad"
            )
            if index + 1 < max(1, count):
                deadline = time.monotonic() + max(0.0, period_s)
                while rclpy.ok() and time.monotonic() < deadline:
                    remaining = max(0.0, deadline - time.monotonic())
                    rclpy.spin_once(self, timeout_sec=min(0.1, remaining))


def validate_restore_document(
    document: Mapping[str, Any],
    expected_map_id: str,
    expected_fingerprint: str,
    max_age_hours: float,
    force: bool,
) -> list[str]:
    warnings: list[str] = []
    saved_map_id = str(document.get("map_id", "")).strip()
    saved_fingerprint = str(document.get("map_fingerprint", "")).strip()

    problems: list[str] = []
    if expected_map_id and saved_map_id != expected_map_id:
        problems.append(
            f"map_id mismatch: saved '{saved_map_id}', expected '{expected_map_id}'"
        )
    if expected_fingerprint and saved_fingerprint != expected_fingerprint:
        problems.append("map fingerprint mismatch: map YAML/image changed")

    pose_age = age_hours(document)
    if max_age_hours > 0.0 and pose_age is not None and pose_age > max_age_hours:
        problems.append(
            f"saved pose is {pose_age:.1f} h old; limit is {max_age_hours:.1f} h"
        )

    if problems and not force:
        raise ValueError("; ".join(problems))
    if problems:
        warnings.extend(f"FORCED RESTORE: {problem}" for problem in problems)
    return warnings


def build_pose_document(
    map_id: str,
    map_yaml: Path,
    fingerprint: str,
    map_frame: str,
    base_frame: str,
    odom_frame: str,
    map_pose: tuple[float, float, float, tuple[float, float, float, float]],
    odom_pose: tuple[float, float, float, tuple[float, float, float, float]] | None,
    xy_stddev: float,
    yaw_stddev: float,
) -> dict[str, Any]:
    x, y, theta, quaternion = map_pose
    document: dict[str, Any] = {
        "version": 1,
        "saved_at": datetime.now(timezone.utc).isoformat().replace("+00:00", "Z"),
        "boot_id": boot_id(),
        "map_id": map_id,
        "map_yaml": str(map_yaml.expanduser().resolve()),
        "map_fingerprint": fingerprint,
        "frame_id": map_frame,
        "base_frame": base_frame,
        "pose": {
            "x": round(x, 6),
            "y": round(y, 6),
            "theta": round(theta, 6),
            "quaternion": {
                "x": round(quaternion[0], 8),
                "y": round(quaternion[1], 8),
                "z": round(quaternion[2], 8),
                "w": round(quaternion[3], 8),
            },
        },
        "initial_pose_uncertainty": {
            "xy_stddev": xy_stddev,
            "yaw_stddev": yaw_stddev,
        },
    }
    if odom_pose is not None:
        ox, oy, otheta, _ = odom_pose
        document["odom_reference"] = {
            "frame_id": odom_frame,
            "x": round(ox, 6),
            "y": round(oy, 6),
            "theta": round(otheta, 6),
        }
    return document


def odom_movement_check(
    node: PosePersistence,
    document: Mapping[str, Any],
    timeout_s: float,
    translation_limit: float,
    rotation_limit: float,
) -> None:
    saved_boot = str(document.get("boot_id", "")).strip()
    current_boot = boot_id()
    reference = document.get("odom_reference")
    if not saved_boot or saved_boot != current_boot or not isinstance(reference, Mapping):
        node.get_logger().warning(
            "Cannot verify whether the robot moved while Nav2 was off "
            "(different boot or no saved odom reference)."
        )
        return

    try:
        current = node.lookup_pose(node.odom_frame, node.base_frame, timeout_s)
    except RuntimeError as exc:
        node.get_logger().warning(f"Odom movement guard unavailable: {exc}")
        return

    dx = current[0] - float(reference.get("x", 0.0))
    dy = current[1] - float(reference.get("y", 0.0))
    dtheta = abs(normalize_angle(current[2] - float(reference.get("theta", 0.0))))
    distance = math.hypot(dx, dy)
    if distance > translation_limit or dtheta > rotation_limit:
        raise ValueError(
            "Robot appears to have moved while Nav2 was off: "
            f"odom delta={distance:.3f} m, yaw delta={dtheta:.3f} rad. "
            "Clear the saved pose and use RViz 2D Pose Estimate."
        )
    node.get_logger().info(
        f"Odom movement guard passed: delta={distance:.3f} m, "
        f"yaw={dtheta:.3f} rad"
    )


def save_once(
    node: PosePersistence,
    pose_file: Path,
    map_id: str,
    map_yaml: Path,
    fingerprint: str,
    tf_timeout: float,
    xy_stddev: float,
    yaw_stddev: float,
) -> dict[str, Any]:
    map_pose = node.lookup_pose(node.map_frame, node.base_frame, tf_timeout)
    try:
        odom_pose = node.lookup_pose(node.odom_frame, node.base_frame, min(tf_timeout, 1.0))
    except RuntimeError:
        odom_pose = None
    document = build_pose_document(
        map_id,
        map_yaml,
        fingerprint,
        node.map_frame,
        node.base_frame,
        node.odom_frame,
        map_pose,
        odom_pose,
        xy_stddev,
        yaw_stddev,
    )
    atomic_write_yaml(pose_file, document)
    return document


def restore_once(
    node: PosePersistence,
    document: Mapping[str, Any],
    restore_timeout: float,
    restore_delay: float,
    publish_count: int,
    publish_period: float,
    xy_stddev: float,
    yaw_stddev: float,
) -> None:
    if not node.wait_until_restore_ready(restore_timeout):
        raise RuntimeError(
            "Timed out waiting for both the map and an /initialpose subscriber. "
            "AMCL may not be active."
        )
    settle_deadline = time.monotonic() + max(0.0, restore_delay)
    while rclpy.ok() and time.monotonic() < settle_deadline:
        remaining = max(0.0, settle_deadline - time.monotonic())
        rclpy.spin_once(node, timeout_sec=min(0.1, remaining))
    x, y, theta = pose_from_document(document)
    node.publish_initial_pose(
        x,
        y,
        theta,
        xy_stddev,
        yaw_stddev,
        publish_count,
        publish_period,
    )


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(
        description="Save map->base_link and restore it through AMCL /initialpose."
    )
    subparsers = parser.add_subparsers(dest="command", required=True)

    def common(subparser: argparse.ArgumentParser) -> None:
        subparser.add_argument("--pose-file", required=True)
        subparser.add_argument("--map-id", default="df_map")
        subparser.add_argument("--map-yaml", required=True)
        subparser.add_argument("--map-frame", default="map")
        subparser.add_argument("--base-frame", default="base_link")
        subparser.add_argument("--odom-frame", default="odom")
        subparser.add_argument("--initialpose-topic", default="/initialpose")
        subparser.add_argument("--map-topic", default="/map")
        subparser.add_argument("--tf-timeout", type=float, default=5.0)
        subparser.add_argument("--xy-stddev", type=float, default=0.10)
        subparser.add_argument(
            "--yaw-stddev", type=float, default=math.radians(10.0)
        )

    run = subparsers.add_parser("run", help="Auto-restore once and continuously save")
    common(run)
    run.add_argument("--auto-restore", type=parse_bool, default=True)
    run.add_argument("--restore-timeout", type=float, default=60.0)
    run.add_argument("--restore-delay", type=float, default=1.0)
    run.add_argument("--publish-count", type=int, default=3)
    run.add_argument("--publish-period", type=float, default=0.5)
    run.add_argument("--save-period", type=float, default=2.0)
    run.add_argument("--max-age-hours", type=float, default=0.0)
    run.add_argument("--force-restore", action="store_true")
    run.add_argument("--odom-translation-limit", type=float, default=0.05)
    run.add_argument("--odom-rotation-limit", type=float, default=0.10)

    save = subparsers.add_parser("save", help="Save the current pose once")
    common(save)

    restore = subparsers.add_parser("restore", help="Publish the saved pose once")
    common(restore)
    restore.add_argument("--restore-timeout", type=float, default=60.0)
    restore.add_argument("--restore-delay", type=float, default=1.0)
    restore.add_argument("--publish-count", type=int, default=3)
    restore.add_argument("--publish-period", type=float, default=0.5)
    restore.add_argument("--max-age-hours", type=float, default=0.0)
    restore.add_argument("--force-restore", action="store_true")
    restore.add_argument("--odom-translation-limit", type=float, default=0.05)
    restore.add_argument("--odom-rotation-limit", type=float, default=0.10)

    status = subparsers.add_parser("status", help="Show the saved pose without ROS")
    status.add_argument("--pose-file", required=True)
    status.add_argument("--map-id", default="df_map")
    status.add_argument("--map-yaml", required=True)

    clear = subparsers.add_parser("clear", help="Delete the saved pose")
    clear.add_argument("--pose-file", required=True)
    return parser


def print_status(path: Path, map_id: str, map_yaml: Path) -> int:
    try:
        document = load_pose_file(path)
        fingerprint = map_fingerprint(map_yaml)
    except ValueError as exc:
        print(f"pose status: unavailable: {exc}", file=sys.stderr)
        return 1
    x, y, theta = pose_from_document(document)
    pose_age = age_hours(document)
    print(f"pose_file: {path.expanduser().resolve()}")
    print(f"saved_at: {document.get('saved_at', '')}")
    if pose_age is not None:
        print(f"age_hours: {pose_age:.2f}")
    print(f"map_id: {document.get('map_id', '')}")
    print(f"map_id_match: {str(document.get('map_id', '')) == map_id}")
    print(
        "map_fingerprint_match: "
        f"{str(document.get('map_fingerprint', '')) == fingerprint}"
    )
    print(
        f"pose: x={x:.4f}, y={y:.4f}, theta={theta:.4f} rad "
        f"({math.degrees(theta):.1f} deg)"
    )
    print(f"same_boot: {str(document.get('boot_id', '')) == boot_id()}")
    return 0


def main(args: Any = None) -> None:
    parser = build_parser()
    known, ros_args = parser.parse_known_args(args=args)
    pose_file = Path(known.pose_file).expanduser().resolve()

    if known.command == "clear":
        existed = pose_file.exists()
        pose_file.unlink(missing_ok=True)
        print(f"{'Deleted' if existed else 'No saved pose at'} {pose_file}")
        return

    map_yaml = Path(known.map_yaml).expanduser().resolve()
    if known.command == "status":
        raise SystemExit(print_status(pose_file, known.map_id, map_yaml))

    if not map_yaml.is_file():
        parser.error(f"Map YAML not found: {map_yaml}")
    try:
        fingerprint = map_fingerprint(map_yaml)
    except ValueError as exc:
        parser.error(str(exc))

    if known.xy_stddev <= 0.0 or known.yaw_stddev <= 0.0:
        parser.error("Initial-pose standard deviations must be positive")

    rclpy.init(args=ros_args)
    node = PosePersistence(
        known.map_frame,
        known.base_frame,
        known.odom_frame,
        known.initialpose_topic,
        known.map_topic,
    )
    exit_code = 0
    stopping = False

    def request_stop(_signum: int, _frame: Any) -> None:
        nonlocal stopping
        stopping = True

    signal.signal(signal.SIGTERM, request_stop)
    signal.signal(signal.SIGINT, request_stop)

    try:
        if known.command in {"run", "restore"}:
            if known.command == "run" and not known.auto_restore:
                node.get_logger().warning(
                    "Automatic restore disabled; use RViz 2D Pose Estimate if needed."
                )
            elif not pose_file.exists():
                if known.command == "restore":
                    raise ValueError(f"No saved pose exists: {pose_file}")
                node.get_logger().warning(
                    f"No saved pose exists at {pose_file}. Set the initial pose "
                    "manually once; it will then be persisted automatically."
                )
            else:
                document = load_pose_file(pose_file)
                warnings = validate_restore_document(
                    document,
                    known.map_id,
                    fingerprint,
                    known.max_age_hours,
                    known.force_restore,
                )
                for warning in warnings:
                    node.get_logger().warning(warning)
                odom_movement_check(
                    node,
                    document,
                    known.tf_timeout,
                    known.odom_translation_limit,
                    known.odom_rotation_limit,
                )
                restore_once(
                    node,
                    document,
                    known.restore_timeout,
                    known.restore_delay,
                    known.publish_count,
                    known.publish_period,
                    known.xy_stddev,
                    known.yaw_stddev,
                )
                node.get_logger().info(
                    "Saved pose sent to AMCL. Verify scan/map alignment before motion."
                )

        if known.command == "restore":
            return

        if known.command == "save":
            document = save_once(
                node,
                pose_file,
                known.map_id,
                map_yaml,
                fingerprint,
                known.tf_timeout,
                known.xy_stddev,
                known.yaw_stddev,
            )
            x, y, theta = pose_from_document(document)
            print(
                f"Saved pose to {pose_file}: x={x:.4f}, y={y:.4f}, "
                f"theta={theta:.4f} rad"
            )
            return

        # run mode: update the file while Nav2 is active. This also survives an
        # unclean Nav2 exit because a recent atomic snapshot is already on disk.
        node.get_logger().info(
            f"Persisting {node.map_frame}->{node.base_frame} to {pose_file} "
            f"every {known.save_period:.1f} s"
        )
        last_save = 0.0
        while rclpy.ok() and not stopping:
            rclpy.spin_once(node, timeout_sec=0.1)
            now = time.monotonic()
            if now - last_save < max(0.2, known.save_period):
                continue
            try:
                save_once(
                    node,
                    pose_file,
                    known.map_id,
                    map_yaml,
                    fingerprint,
                    min(known.tf_timeout, 0.5),
                    known.xy_stddev,
                    known.yaw_stddev,
                )
                last_save = now
            except RuntimeError:
                # Expected before the first manual/automatic localization.
                pass

        try:
            save_once(
                node,
                pose_file,
                known.map_id,
                map_yaml,
                fingerprint,
                min(known.tf_timeout, 2.0),
                known.xy_stddev,
                known.yaw_stddev,
            )
            node.get_logger().info("Final pose snapshot saved during shutdown")
        except RuntimeError as exc:
            node.get_logger().warning(f"Could not save final pose snapshot: {exc}")

    except (ValueError, RuntimeError) as exc:
        node.get_logger().error(str(exc))
        exit_code = 2
    finally:
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()

    raise SystemExit(exit_code)


if __name__ == "__main__":
    main()
