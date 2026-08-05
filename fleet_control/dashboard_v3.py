"""Dynamic VDA 5050 v3.0 mission-control dashboard extension.

This module is deliberately kept separate from ``master_control.py``.  The existing
MQTT, schema validation, order stamping and handover orchestration remain
authoritative.  The extension adds a live dashboard API, dynamic waypoint orders,
ROX-first scenarios and a compact event history.

The module uses VDA state fields for control decisions.  ``information[]`` is never
used for dispatch, completion, safety or scenario progression.
"""
from __future__ import annotations

import copy
import csv
import io
import json
import math
import os
import sqlite3
import struct
import threading
import time
import zlib
from collections import deque
from datetime import datetime, timezone
from pathlib import Path
from typing import Any, Dict, Iterable, List, Mapping, MutableMapping, Optional, Tuple
from uuid import uuid4

import yaml
from flask import Response, abort, jsonify, request
from werkzeug.exceptions import HTTPException

FINAL_ACTION_STATES = {"FINISHED", "FAILED"}
TERMINAL_MISSION_STATES = {"FINISHED", "FAILED", "REJECTED", "CANCELLED"}
# VDA 5050 v3 errors that represent rejection/non-acceptance of an order.
# Execution-time errors are not classified as REJECTED merely because they
# reference the order; they are evaluated separately as failures.
ORDER_REJECTION_ERROR_TYPES = {
    "VALIDATION_FAILURE",
    "UNSUPPORTED_PARAMETER",
    "INVALID_ORDER_ACTION",
    "OUTDATED_ORDER_UPDATE",
    "SAME_ORDER_UPDATE_ID",
    "ORDER_UPDATE_FOLLOWING_CANCEL",
    "OTHER_ORDER_ACTIVE",
    "START_NODE_OUT_OF_RANGE",
    "NO_ROUTE_TO_TARGET",
    "MOBILE_ROBOT_NOT_AVAILABLE",
    "UNKNOWN_MAP_ID",
    "INSUFFICIENT_MEMORY",
}
ACTIVE_ACTION_STATES = {
    "WAITING",
    "INITIALIZING",
    "RUNNING",
    "PAUSED",
    "RETRIABLE",
}
ACTIVE_MISSION_STATES = {
    "SENT",
    "ACCEPTED",
    "RUNNING",
    "PAUSED",
    "RETRIABLE",
    "CANCELLING",
}


def _bool_env(name: str, default: bool) -> bool:
    raw = os.getenv(name)
    if raw is None:
        return default
    return raw.strip().lower() in {"1", "true", "yes", "on"}


def _float_env(name: str, default: float) -> float:
    try:
        return float(os.getenv(name, str(default)))
    except (TypeError, ValueError):
        return default


def _int_env(name: str, default: int) -> int:
    try:
        return int(os.getenv(name, str(default)))
    except (TypeError, ValueError):
        return default


def _utc_now() -> str:
    return (
        datetime.now(timezone.utc)
        .isoformat(timespec="milliseconds")
        .replace("+00:00", "Z")
    )


def _parse_timestamp(value: Any) -> Optional[float]:
    if not isinstance(value, str) or not value:
        return None
    try:
        return datetime.fromisoformat(value.replace("Z", "+00:00")).timestamp()
    except ValueError:
        return None


def _age_seconds(payload: Optional[Mapping[str, Any]]) -> Optional[float]:
    if not payload:
        return None
    stamp = _parse_timestamp(payload.get("timestamp"))
    return None if stamp is None else max(0.0, time.time() - stamp)

def _json_safe(value: Any) -> Any:
    """Recursively convert non-finite floats into JSON null values."""
    if isinstance(value, float):
        return value if math.isfinite(value) else None

    if isinstance(value, Mapping):
        return {
            str(key): _json_safe(item)
            for key, item in value.items()
        }

    if isinstance(value, (list, tuple)):
        return [_json_safe(item) for item in value]

    return value

def _safe_float(value: Any, default: float = 0.0) -> float:
    try:
        return float(value)
    except (TypeError, ValueError):
        return default


def _safe_int(value: Any, default: int = 0) -> int:
    try:
        return int(value)
    except (TypeError, ValueError):
        return default


def _error_references(error: Mapping[str, Any]) -> Dict[str, str]:
    refs: Dict[str, str] = {}
    for item in error.get("errorReferences") or []:
        if isinstance(item, Mapping):
            key = str(item.get("referenceKey", ""))
            value = str(item.get("referenceValue", ""))
            if key:
                refs[key] = value
    return refs


class DashboardController:
    """Stateful Flask/MQTT dashboard adapter around ``master_control`` globals."""

    def __init__(self, app: Any, ctx: MutableMapping[str, Any]) -> None:
        self.app = app
        self.ctx = ctx
        self.repo_root = Path(ctx["REPO_ROOT"])
        self.state = ctx["STATE"]
        self.state_lock = ctx["STATE_LOCK"]
        self.targets = ctx["TARGETS"]
        self.order_book = ctx["ORDER_BOOK"]
        self.publish_order = ctx["_publish_order"]
        self.publish_instant = ctx["_publish_instant_action"]
        self.kv_params = ctx["_kv_params"]
        self.mqtt_client = ctx["mqtt_client"]
        self.protocol_version = str(ctx.get("VDA_PROTOCOL_VERSION", "3.0.0"))
        self.broker_host = str(ctx.get("BROKER_HOST", ""))
        self.broker_port = int(ctx.get("BROKER_PORT", 1883))
        self.default_map_id = str(ctx.get("DEFAULT_MAP_ID", "df_map"))
        self.started_monotonic = time.monotonic()

        self.waypoint_path = self._repo_path(
            os.getenv("ROX_WAYPOINT_FILE", "configs/rox_waypoints.yaml")
        )
        self.scenario_path = self._repo_path(
            os.getenv("FLEET_UI_SCENARIO_FILE", "configs/dashboard_scenarios.yaml")
        )
        self.map_yaml_path = self._repo_path(
            os.getenv("FLEET_UI_MAP_YAML", "configs/maps/df_map.yaml")
        )
        self.experiment_db_path = self._repo_path(
            os.getenv(
                "FLEET_UI_EXPERIMENT_DB",
                "results/experiments/mission_control.sqlite3",
            )
        )
        self.rox_enabled = _bool_env("ROX_ENABLED", True)
        self.crane_enabled = _bool_env("CRANE_ENABLED", True)
        self.require_localized = _bool_env("FLEET_UI_REQUIRE_LOCALIZED", True)
        self.require_configured = _bool_env("FLEET_UI_REQUIRE_CONFIGURED_WAYPOINTS", True)
        self.start_tolerance_m = _float_env("FLEET_UI_START_TOLERANCE_M", 0.35)
        # VDA 5050 requires a state publication at least every 30 seconds.
        self.state_stale_s = _float_env("FLEET_UI_STATE_STALE_S", 35.0)
        self.order_accept_timeout_s = _float_env("FLEET_UI_ORDER_ACCEPT_TIMEOUT_S", 12.0)
        self.event_limit = max(50, _int_env("FLEET_UI_EVENT_LIMIT", 300))
        self.mission_limit = max(10, _int_env("FLEET_UI_MISSION_LIMIT", 50))
        self.experiment_enabled = _bool_env("FLEET_UI_EXPERIMENT_DEFAULT", False)
        self.experiment_sample_distance_m = max(
            0.001, _float_env("FLEET_UI_EXPERIMENT_SAMPLE_DISTANCE_M", 0.01)
        )

        self.lock = threading.RLock()
        self.events: deque[Dict[str, Any]] = deque(maxlen=self.event_limit)
        self.missions: deque[Dict[str, Any]] = deque(maxlen=self.mission_limit)
        self.controls: deque[Dict[str, Any]] = deque(maxlen=100)
        self.active_scenario: Optional[Dict[str, Any]] = None
        self._last_signature: Dict[str, Any] = {}
        self._stop = threading.Event()
        self._map_cache: Optional[Dict[str, Any]] = None
        self._map_cache_signature: Optional[Tuple[float, float]] = None
        self.experiment_session: Optional[Dict[str, Any]] = None
        self._init_experiment_db()
        if self.experiment_enabled:
            self._set_experiment_mode(True, label="Automatic startup session", notes="")

        self._add_event(
            "INFO",
            "server",
            "VDA 5050 v3 mission dashboard initialized",
            code="DASHBOARD_READY",
        )
        self._register_routes()
        self.worker = threading.Thread(
            target=self._scenario_worker,
            name="vda5050-dashboard-scenario",
            daemon=True,
        )
        self.worker.start()

    def _repo_path(self, value: str) -> Path:
        path = Path(value).expanduser()
        return path if path.is_absolute() else self.repo_root / path

    # ------------------------------------------------------------------
    # Map and experiment persistence
    def _candidate_map_yaml(self, map_id: Optional[str] = None) -> Path:
        candidates = [self.map_yaml_path]
        resolved_id = str(map_id or self.default_map_id)
        candidates.extend(
            [
                self.repo_root / "configs" / "maps" / f"{resolved_id}.yaml",
                self.repo_root / "configs" / f"{resolved_id}.yaml",
                Path.home() / "maps" / f"{resolved_id}.yaml",
            ]
        )
        for candidate in candidates:
            if candidate.exists():
                return candidate
        return candidates[0]

    @staticmethod
    def _read_pgm(path: Path) -> Tuple[int, int, bytes]:
        """Read P2/P5 PGM and return 8-bit grayscale pixels."""
        data = path.read_bytes()
        cursor = 0

        def token() -> bytes:
            nonlocal cursor
            while cursor < len(data):
                if data[cursor:cursor + 1] == b"#":
                    end = data.find(b"\n", cursor)
                    cursor = len(data) if end < 0 else end + 1
                    continue
                if data[cursor] in b" \t\r\n":
                    cursor += 1
                    continue
                break
            start = cursor
            while cursor < len(data) and data[cursor] not in b" \t\r\n#":
                cursor += 1
            if start == cursor:
                raise ValueError("Unexpected end of PGM header")
            return data[start:cursor]

        magic = token()
        width = int(token())
        height = int(token())
        max_value = int(token())
        if width <= 0 or height <= 0 or max_value <= 0:
            raise ValueError("Invalid PGM dimensions or max value")

        if magic == b"P2":
            values = [int(token()) for _ in range(width * height)]
        elif magic == b"P5":
            # The binary raster begins after the required whitespace separator.
            # Consume the header separator without accidentally discarding a
            # legitimate first pixel whose byte value happens to be whitespace.
            if cursor >= len(data) or data[cursor] not in b" \t\r\n":
                raise ValueError("Missing PGM raster separator")
            if data[cursor:cursor + 2] == b"\r\n":
                cursor += 2
            else:
                cursor += 1
            if max_value < 256:
                raw = data[cursor:cursor + width * height]
                if len(raw) != width * height:
                    raise ValueError("Truncated PGM pixel data")
                values = list(raw)
            else:
                raw = data[cursor:cursor + width * height * 2]
                if len(raw) != width * height * 2:
                    raise ValueError("Truncated 16-bit PGM pixel data")
                values = [
                    int.from_bytes(raw[index:index + 2], "big")
                    for index in range(0, len(raw), 2)
                ]
        else:
            raise ValueError(f"Unsupported PGM format {magic!r}")

        if max_value != 255:
            values = [round(max(0, min(max_value, value)) * 255 / max_value) for value in values]
        return width, height, bytes(values)

    @staticmethod
    def _png_chunk(kind: bytes, payload: bytes) -> bytes:
        return (
            struct.pack(">I", len(payload))
            + kind
            + payload
            + struct.pack(">I", zlib.crc32(kind + payload) & 0xFFFFFFFF)
        )

    @classmethod
    def _grayscale_png(cls, width: int, height: int, pixels: bytes) -> bytes:
        rows = b"".join(
            b"\x00" + pixels[row * width:(row + 1) * width]
            for row in range(height)
        )
        return (
            b"\x89PNG\r\n\x1a\n"
            + cls._png_chunk(b"IHDR", struct.pack(">IIBBBBB", width, height, 8, 0, 0, 0, 0))
            + cls._png_chunk(b"IDAT", zlib.compress(rows, 7))
            + cls._png_chunk(b"IEND", b"")
        )

    def _load_map(self, map_id: Optional[str] = None) -> Dict[str, Any]:
        yaml_path = self._candidate_map_yaml(map_id)
        if not yaml_path.exists():
            return {
                "available": False,
                "map_id": str(map_id or self.default_map_id),
                "yaml_path": str(yaml_path),
                "error": "Map YAML is not installed on the Raspberry Pi",
            }
        try:
            with yaml_path.open("r", encoding="utf-8") as handle:
                cfg = yaml.safe_load(handle) or {}
            image_value = cfg.get("image")
            if not image_value:
                raise ValueError("Map YAML does not contain an image field")
            image_path = Path(str(image_value)).expanduser()
            if not image_path.is_absolute():
                image_path = yaml_path.parent / image_path
            if not image_path.exists():
                raise FileNotFoundError(f"Map image not found: {image_path}")
            signature = (yaml_path.stat().st_mtime, image_path.stat().st_mtime)
            if self._map_cache and self._map_cache_signature == signature:
                return copy.deepcopy(self._map_cache)
            width, height, pixels = self._read_pgm(image_path)
            origin_raw = cfg.get("origin") or [0.0, 0.0, 0.0]
            origin = [
                _safe_float(origin_raw[index] if index < len(origin_raw) else 0.0)
                for index in range(3)
            ]
            result = {
                "available": True,
                "map_id": str(map_id or yaml_path.stem),
                "yaml_path": str(yaml_path),
                "image_path": str(image_path),
                "image_url": "/api/map/image",
                "revision": f"{signature[0]:.6f}-{signature[1]:.6f}",
                "width": width,
                "height": height,
                "resolution": _safe_float(cfg.get("resolution"), 0.05),
                "origin": origin,
                "negate": _safe_int(cfg.get("negate"), 0),
                "occupied_thresh": _safe_float(cfg.get("occupied_thresh"), 0.65),
                "free_thresh": _safe_float(cfg.get("free_thresh"), 0.196),
                "_png": self._grayscale_png(width, height, pixels),
            }
            self._map_cache = result
            self._map_cache_signature = signature
            return copy.deepcopy(result)
        except Exception as exc:
            return {
                "available": False,
                "map_id": str(map_id or self.default_map_id),
                "yaml_path": str(yaml_path),
                "error": str(exc),
            }

    def _db(self) -> sqlite3.Connection:
        self.experiment_db_path.parent.mkdir(parents=True, exist_ok=True)
        connection = sqlite3.connect(str(self.experiment_db_path), timeout=10.0)
        connection.row_factory = sqlite3.Row
        return connection

    def _init_experiment_db(self) -> None:
        with self._db() as db:
            db.executescript(
                """
                CREATE TABLE IF NOT EXISTS experiment_sessions (
                    session_id TEXT PRIMARY KEY,
                    label TEXT NOT NULL,
                    notes TEXT NOT NULL DEFAULT '',
                    started_at TEXT NOT NULL,
                    ended_at TEXT,
                    enabled INTEGER NOT NULL DEFAULT 1
                );
                CREATE TABLE IF NOT EXISTS experiment_runs (
                    run_id TEXT PRIMARY KEY,
                    session_id TEXT,
                    mission_id TEXT NOT NULL,
                    order_id TEXT NOT NULL UNIQUE,
                    scenario_id TEXT,
                    source TEXT NOT NULL,
                    waypoint TEXT NOT NULL,
                    label TEXT NOT NULL,
                    status TEXT NOT NULL,
                    started_at TEXT NOT NULL,
                    accepted_at TEXT,
                    running_at TEXT,
                    finished_at TEXT,
                    duration_s REAL,
                    distance_m REAL NOT NULL DEFAULT 0,
                    pause_count INTEGER NOT NULL DEFAULT 0,
                    cancel_requested INTEGER NOT NULL DEFAULT 0,
                    start_x REAL, start_y REAL, start_theta REAL,
                    end_x REAL, end_y REAL, end_theta REAL,
                    target_x REAL, target_y REAL, target_theta REAL,
                    final_xy_error_m REAL,
                    final_theta_error_rad REAL,
                    battery_start REAL,
                    battery_end REAL,
                    error_count INTEGER NOT NULL DEFAULT 0,
                    error_json TEXT NOT NULL DEFAULT '[]',
                    raw_json TEXT NOT NULL DEFAULT '{}'
                );
                CREATE INDEX IF NOT EXISTS idx_experiment_runs_started
                ON experiment_runs(started_at DESC);
                """
            )

    def _set_experiment_mode(self, enabled: bool, label: str = "", notes: str = "") -> None:
        now = _utc_now()
        with self.lock:
            if enabled:
                if self.experiment_session and self.experiment_session.get("enabled"):
                    self.experiment_enabled = True
                    return
                session = {
                    "session_id": str(uuid4()),
                    "label": label.strip() or f"Experiment {now[:19].replace('T', ' ')}",
                    "notes": notes.strip(),
                    "started_at": now,
                    "ended_at": None,
                    "enabled": True,
                }
                self.experiment_session = session
                self.experiment_enabled = True
                with self._db() as db:
                    db.execute(
                        "INSERT INTO experiment_sessions(session_id,label,notes,started_at,enabled) VALUES(?,?,?,?,1)",
                        (session["session_id"], session["label"], session["notes"], now),
                    )
            else:
                self.experiment_enabled = False
                if self.experiment_session and self.experiment_session.get("enabled"):
                    self.experiment_session["enabled"] = False
                    self.experiment_session["ended_at"] = now
                    with self._db() as db:
                        db.execute(
                            "UPDATE experiment_sessions SET enabled=0, ended_at=? WHERE session_id=?",
                            (now, self.experiment_session["session_id"]),
                        )
        self._add_event(
            "INFO",
            "experiment",
            "Experiment logging enabled" if enabled else "Experiment logging disabled",
            code="EXPERIMENT_MODE_CHANGED",
            details={"enabled": enabled, "label": label},
        )

    def _experiment_begin(self, mission: MutableMapping[str, Any], state: Mapping[str, Any], waypoint: Mapping[str, Any]) -> None:
        with self.lock:
            session = copy.deepcopy(self.experiment_session)
            enabled = self.experiment_enabled
        if not enabled or not session:
            mission["experiment_logged"] = False
            return
        position = state.get("mobileRobotPosition") or {}
        battery = (state.get("powerSupply") or {}).get("stateOfCharge")
        mission.update(
            {
                "experiment_logged": True,
                "experiment_session_id": session["session_id"],
                "distance_m": 0.0,
                "pause_count": 0,
                "last_sample_pose": None,
                "accepted_at": None,
                "running_at": None,
                "finished_at": None,
                "battery_start": battery,
                "target_pose": {
                    "x": waypoint.get("x"),
                    "y": waypoint.get("y"),
                    "theta": waypoint.get("theta"),
                },
            }
        )
        with self._db() as db:
            db.execute(
                """
                INSERT OR REPLACE INTO experiment_runs(
                    run_id,session_id,mission_id,order_id,scenario_id,source,waypoint,label,status,started_at,
                    start_x,start_y,start_theta,target_x,target_y,target_theta,battery_start,raw_json
                ) VALUES(?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)
                """,
                (
                    mission["mission_id"], session["session_id"], mission["mission_id"], mission["order_id"],
                    mission.get("scenario_id"), mission["source"], mission["waypoint"], mission["label"],
                    mission["status"], mission["created_at"], position.get("x"), position.get("y"),
                    position.get("theta"), waypoint.get("x"), waypoint.get("y"), waypoint.get("theta"),
                    battery, json.dumps({"description": mission.get("description", "")}),
                ),
            )

    @staticmethod
    def _angular_error(a: Any, b: Any) -> Optional[float]:
        if a is None or b is None:
            return None
        delta = _safe_float(a) - _safe_float(b)
        return abs(math.atan2(math.sin(delta), math.cos(delta)))

    def _experiment_update(self, mission: MutableMapping[str, Any], state: Mapping[str, Any], status: str, old_status: Optional[str]) -> None:
        if not mission.get("experiment_logged"):
            return
        now = _utc_now()
        position = state.get("mobileRobotPosition") or {}
        x, y, theta = position.get("x"), position.get("y"), position.get("theta")
        if x is not None and y is not None:
            current_pose = (_safe_float(x), _safe_float(y))
            previous = mission.get("last_sample_pose")
            if previous:
                step = math.hypot(current_pose[0] - previous[0], current_pose[1] - previous[1])
                if self.experiment_sample_distance_m <= step <= 5.0:
                    mission["distance_m"] = _safe_float(mission.get("distance_m")) + step
            mission["last_sample_pose"] = current_pose
        if status in {"ACCEPTED", "RUNNING", "PAUSED", "RETRIABLE"} and not mission.get("accepted_at"):
            mission["accepted_at"] = now
        if status == "RUNNING" and not mission.get("running_at"):
            mission["running_at"] = now
        if status == "PAUSED" and old_status != "PAUSED":
            mission["pause_count"] = _safe_int(mission.get("pause_count")) + 1
        if status in TERMINAL_MISSION_STATES and not mission.get("finished_at"):
            mission["finished_at"] = now
            mission["finished_epoch"] = time.time()
        finished_epoch = mission.get("finished_epoch")
        duration = (finished_epoch or time.time()) - mission["created_epoch"]
        target = mission.get("target_pose") or {}
        xy_error = None
        if x is not None and y is not None and target.get("x") is not None and target.get("y") is not None:
            xy_error = math.hypot(_safe_float(x) - _safe_float(target["x"]), _safe_float(y) - _safe_float(target["y"]))
        theta_error = self._angular_error(theta, target.get("theta"))
        errors = state.get("errors") or []
        battery_end = (state.get("powerSupply") or {}).get("stateOfCharge")
        with self._db() as db:
            db.execute(
                """
                UPDATE experiment_runs SET status=?,accepted_at=?,running_at=?,finished_at=?,duration_s=?,distance_m=?,
                    pause_count=?,cancel_requested=?,end_x=?,end_y=?,end_theta=?,final_xy_error_m=?,final_theta_error_rad=?,
                    battery_end=?,error_count=?,error_json=?,raw_json=? WHERE order_id=?
                """,
                (
                    status, mission.get("accepted_at"), mission.get("running_at"), mission.get("finished_at"),
                    round(max(0.0, duration), 3), round(_safe_float(mission.get("distance_m")), 4),
                    _safe_int(mission.get("pause_count")), 1 if mission.get("cancel_requested") else 0,
                    x, y, theta, xy_error, theta_error, battery_end, len(errors),
                    json.dumps(_json_safe(errors)),
                    json.dumps(_json_safe({"last_node_id": state.get("lastNodeId"), "last_node_sequence_id": state.get("lastNodeSequenceId")})),
                    mission["order_id"],
                ),
            )

    def _experiment_projection(self) -> Dict[str, Any]:
        with self._db() as db:
            rows = [
                dict(row)
                for row in db.execute(
                    "SELECT * FROM experiment_runs ORDER BY started_at DESC LIMIT 50"
                )
            ]
            sessions = [
                dict(row)
                for row in db.execute(
                    "SELECT * FROM experiment_sessions ORDER BY started_at DESC LIMIT 20"
                )
            ]
            aggregate = dict(
                db.execute(
                    """
                    SELECT
                        COUNT(*) AS runs,
                        SUM(CASE WHEN status='FINISHED' THEN 1 ELSE 0 END) AS finished,
                        AVG(CASE WHEN status='FINISHED' THEN duration_s END) AS average_duration_s,
                        COALESCE(SUM(distance_m), 0.0) AS distance_m
                    FROM experiment_runs
                    """
                ).fetchone()
            )
        total = _safe_int(aggregate.get("runs"), 0)
        finished = _safe_int(aggregate.get("finished"), 0)
        average_duration = aggregate.get("average_duration_s")
        return {
            "enabled": self.experiment_enabled,
            "session": copy.deepcopy(self.experiment_session),
            "sessions": sessions,
            "database": str(self.experiment_db_path),
            "runs": rows[:10],
            "statistics": {
                "runs": total,
                "finished": finished,
                "success_rate": round((finished / total) * 100.0, 1) if total else None,
                "average_duration_s": (
                    round(_safe_float(average_duration), 2)
                    if average_duration is not None
                    else None
                ),
                "distance_m": round(_safe_float(aggregate.get("distance_m")), 2),
            },
        }

    # ------------------------------------------------------------------
    # Configuration
    def _load_waypoints(self) -> Dict[str, Any]:
        if not self.waypoint_path.exists():
            raise FileNotFoundError(f"Waypoint file not found: {self.waypoint_path}")
        with self.waypoint_path.open("r", encoding="utf-8") as handle:
            data = yaml.safe_load(handle) or {}
        if not isinstance(data, Mapping):
            raise ValueError("Waypoint YAML root must be an object")
        waypoints = data.get("waypoints")
        if not isinstance(waypoints, Mapping):
            raise ValueError("Waypoint YAML must contain a 'waypoints' mapping")
        map_id = str(data.get("map_id") or self.default_map_id)
        configured = bool(data.get("configured", False))
        result: Dict[str, Any] = {
            "map_id": map_id,
            "configured": configured,
            "waypoints": {},
        }
        for name, raw in waypoints.items():
            if not isinstance(raw, Mapping):
                continue
            try:
                x = float(raw["x"])
                y = float(raw["y"])
                theta = float(raw.get("theta", 0.0))
            except (KeyError, TypeError, ValueError):
                continue
            result["waypoints"][str(name)] = {
                "name": str(name),
                "label": str(raw.get("label") or str(name).replace("_", " ").title()),
                "description": str(raw.get("description") or "Navigate ROX-Diff to this mapped pose."),
                "x": x,
                "y": y,
                "theta": theta,
                "allowed_deviation_xy": max(
                    0.01, _safe_float(raw.get("allowed_deviation_xy"), 0.20)
                ),
                "allowed_deviation_theta": max(
                    0.01, _safe_float(raw.get("allowed_deviation_theta"), 0.20)
                ),
            }
        return result

    def _default_scenarios(self, available: Iterable[str]) -> Dict[str, Any]:
        names = set(available)
        candidates = {
            "short_commissioning": {
                "label": "Short commissioning loop",
                "description": "Home → short test → home. Recommended first real-motion scenario.",
                "target": "rox",
                "waypoints": ["home", "short_test", "home"],
                "enabled": {"home", "short_test"}.issubset(names),
                "risk": "low",
            },
            "rox_case_study_route": {
                "label": "ROX case-study route",
                "description": "ROX-only traversal of the mapped handover and drop-off positions.",
                "target": "rox",
                "waypoints": [
                    "home",
                    "short_test",
                    "crane_handover",
                    "warehouse_dropoff",
                    "home",
                ],
                "enabled": {
                    "home",
                    "short_test",
                    "crane_handover",
                    "warehouse_dropoff",
                }.issubset(names),
                "risk": "supervised",
            },
            "crane_approach_only": {
                "label": "ROX crane approach",
                "description": "Navigate only the ROX-Diff to the crane handover waypoint; no crane command is sent.",
                "target": "rox",
                "waypoints": ["crane_handover"],
                "enabled": "crane_handover" in names,
                "risk": "supervised",
            },
            "coordinated_handover": {
                "label": "Coordinated crane handover",
                "description": "Reserved for the future commissioned crane + ROX sequence.",
                "target": "coordinated",
                "waypoints": ["crane_handover"],
                "enabled": False,
                "disabled_reason": "Crane is currently marked unavailable and cannot be tested.",
                "risk": "locked",
            },
        }
        return candidates

    def _load_scenarios(self, waypoints: Mapping[str, Any]) -> Dict[str, Any]:
        scenarios = self._default_scenarios(waypoints.keys())
        if self.scenario_path.exists():
            with self.scenario_path.open("r", encoding="utf-8") as handle:
                raw = yaml.safe_load(handle) or {}
            entries = raw.get("scenarios", raw) if isinstance(raw, Mapping) else {}
            if isinstance(entries, Mapping):
                for scenario_id, cfg in entries.items():
                    if not isinstance(cfg, Mapping):
                        continue
                    merged = dict(scenarios.get(str(scenario_id), {}))
                    merged.update(dict(cfg))
                    scenarios[str(scenario_id)] = merged
        for scenario_id, cfg in scenarios.items():
            cfg["id"] = scenario_id
            cfg.setdefault("target", "rox")
            cfg.setdefault("waypoints", [])
            cfg.setdefault("label", scenario_id.replace("_", " ").title())
            cfg.setdefault("description", "Configured mission sequence")
            cfg.setdefault("risk", "supervised")
            missing = [name for name in cfg["waypoints"] if name not in waypoints]
            if missing:
                cfg["enabled"] = False
                cfg["disabled_reason"] = f"Missing waypoint(s): {', '.join(missing)}"
            if cfg.get("target") == "coordinated" and not self.crane_enabled:
                cfg["enabled"] = False
                cfg["disabled_reason"] = "Crane is unavailable in the current configuration."
        return scenarios

    # ------------------------------------------------------------------
    # Events and state projection
    def _add_event(
        self,
        level: str,
        source: str,
        message: str,
        *,
        code: str = "",
        details: Optional[Mapping[str, Any]] = None,
    ) -> None:
        event = {
            "id": str(uuid4()),
            "timestamp": _utc_now(),
            "level": level.upper(),
            "source": source,
            "code": code,
            "message": message,
        }
        if details:
            event["details"] = dict(details)
        with self.lock:
            self.events.append(event)

    def _copy_target_state(self, target: str) -> Dict[str, Any]:
        with self.state_lock:
            return copy.deepcopy(self.state.get(target, {}))

    def _mqtt_connected(self) -> bool:
        try:
            return bool(self.mqtt_client.is_connected())
        except Exception:
            return False

    def _cache_age(self, target_cache: Mapping[str, Any], key: str) -> Optional[float]:
        """Return age from local receive time, falling back to protocol timestamp."""
        received_at = target_cache.get(f"{key}_received_at")
        if isinstance(received_at, (int, float)):
            return max(0.0, time.time() - float(received_at))
        payload = target_cache.get(key)
        return _age_seconds(payload if isinstance(payload, Mapping) else None)

    def _active_order(self, state: Optional[Mapping[str, Any]]) -> bool:
        if not state:
            return False
        if state.get("nodeStates") or state.get("edgeStates"):
            return True
        return any(
            str(item.get("actionStatus")) in ACTIVE_ACTION_STATES
            for item in state.get("actionStates") or []
            if isinstance(item, Mapping)
        )

    def _dispatch_reasons(
        self,
        target: str,
        target_cache: Mapping[str, Any],
        waypoint_cfg: Optional[Mapping[str, Any]] = None,
    ) -> List[str]:
        enabled = self.rox_enabled if target == "rox" else self.crane_enabled
        reasons: List[str] = []
        if not enabled:
            reasons.append("Device is disabled in fleet-control configuration")
        if not self._mqtt_connected():
            reasons.append("Master controller is not connected to MQTT")
        connection = target_cache.get("connection") or {}
        if str(connection.get("connectionState", "")) != "ONLINE":
            reasons.append("VDA connection state is not ONLINE")
        # Do not age-gate the retained VDA connection message. The v3
        # specification explicitly notes that its timestamp/headerId will be
        # outdated; liveness is represented by ONLINE/OFFLINE/CONNECTION_BROKEN.
        state = target_cache.get("last_state") or {}
        if not state:
            reasons.append("No schema-valid VDA state has been received")
            return reasons
        state_age = self._cache_age(target_cache, "last_state")
        if state_age is not None and state_age > self.state_stale_s:
            reasons.append(f"State message is stale ({state_age:.1f} s)")
        if self._active_order(state):
            reasons.append("Another VDA order is active")
        mode = str(state.get("operatingMode", ""))
        if target == "rox" and mode not in {"AUTOMATIC", "SEMIAUTOMATIC"}:
            reasons.append(f"Operating mode {mode or 'UNKNOWN'} does not permit normal dispatch")
        safety = state.get("safetyState") or {}
        if str(safety.get("activeEmergencyStop", "NONE")) != "NONE":
            reasons.append("Emergency stop is active")
        if bool(safety.get("fieldViolation", False)):
            reasons.append("Safety field violation is active")
        position = state.get("mobileRobotPosition") or {}
        if target == "rox" and self.require_localized:
            if not position:
                reasons.append("No mobileRobotPosition is available")
            elif not bool(position.get("localized", False)):
                reasons.append("ROX-Diff localization is not valid")
        if waypoint_cfg and self.require_configured and not waypoint_cfg.get("configured"):
            reasons.append("Waypoint file is not marked configured")
        return reasons

    def _device_projection(
        self, target: str, target_cache: Mapping[str, Any], waypoint_cfg: Mapping[str, Any]
    ) -> Dict[str, Any]:
        state = target_cache.get("last_state") or {}
        connection = target_cache.get("connection") or {}
        position = state.get("mobileRobotPosition") or {}
        power = state.get("powerSupply") or {}
        safety = state.get("safetyState") or {}
        errors = state.get("errors") or []
        reasons = self._dispatch_reasons(target, target_cache, waypoint_cfg)
        enabled = self.rox_enabled if target == "rox" else self.crane_enabled
        return {
            "target": target,
            "label": "Neobotix ROX-Diff" if target == "rox" else "Ilmatar overhead crane",
            "enabled": enabled,
            "availability": "AVAILABLE" if enabled else "UNAVAILABLE",
            "connection": str(connection.get("connectionState", "UNKNOWN")),
            "online": str(connection.get("connectionState", "")) == "ONLINE",
            "connection_age_s": self._cache_age(target_cache, "connection"),
            "state_age_s": self._cache_age(target_cache, "last_state"),
            "operating_mode": state.get("operatingMode", "UNKNOWN"),
            "driving": bool(state.get("driving", False)),
            "paused": bool(state.get("paused", False)),
            "order_id": str(state.get("orderId", "")),
            "order_update_id": _safe_int(state.get("orderUpdateId"), 0),
            "last_node_id": str(state.get("lastNodeId", "")),
            "last_node_sequence_id": _safe_int(state.get("lastNodeSequenceId"), 0),
            "position": {
                "x": position.get("x"),
                "y": position.get("y"),
                "theta": position.get("theta"),
                "map_id": position.get("mapId"),
                "localized": position.get("localized"),
                "localization_score": position.get("localizationScore"),
            },
            "battery": {
                "state_of_charge": power.get("stateOfCharge"),
                "charging": power.get("charging"),
                "voltage": power.get("batteryVoltage"),
                "range": power.get("range"),
            },
            "safety": {
                "active_emergency_stop": safety.get("activeEmergencyStop", "UNKNOWN"),
                "field_violation": bool(safety.get("fieldViolation", False)),
            },
            "active_order": self._active_order(state),
            "dispatch_ready": not reasons,
            "dispatch_reasons": reasons,
            "errors": [
                {
                    "type": item.get("errorType"),
                    "level": item.get("errorLevel"),
                    "description": item.get("errorDescription", ""),
                    "references": _error_references(item),
                }
                for item in errors
                if isinstance(item, Mapping)
            ],
            "factsheet_received": bool(target_cache.get("factsheet")),
            "raw_state": state,
            "instant_actions": state.get("instantActionStates") or [],
            "order_actions": state.get("actionStates") or [],
            "retriable_action_ids": [
                str(item.get("actionId"))
                for item in state.get("actionStates") or []
                if isinstance(item, Mapping)
                and str(item.get("actionStatus")) == "RETRIABLE"
                and item.get("actionId")
            ],
        }

    def _mission_status(
        self, mission: MutableMapping[str, Any], state: Mapping[str, Any]
    ) -> str:
        previous = str(mission.get("status", "SENT"))
        if previous in TERMINAL_MISSION_STATES:
            return previous

        current_order_id = str(state.get("orderId", ""))
        referenced_errors = []
        for item in state.get("errors") or []:
            if not isinstance(item, Mapping):
                continue
            refs = _error_references(item)
            if refs.get("orderId") == mission["order_id"]:
                referenced_errors.append(item)
        rejection_errors = [
            item
            for item in referenced_errors
            if str(item.get("errorType", "")) in ORDER_REJECTION_ERROR_TYPES
        ]
        if rejection_errors:
            mission["rejection_errors"] = copy.deepcopy(rejection_errors)
            first = rejection_errors[0]
            mission["terminal_reason"] = str(
                first.get("errorDescription")
                or first.get("errorType")
                or "Order rejected by the mobile robot"
            )
            mission["terminal_code"] = str(first.get("errorType") or "ORDER_REJECTED")
            return "REJECTED"

        if current_order_id != mission["order_id"]:
            # A later state for another order is not evidence that this mission was
            # rejected. VDA 5050 communicates rejection through order-referenced
            # errors. Keep the last known state and never rewrite a completed run.
            age = time.time() - mission["created_epoch"]
            if age >= self.order_accept_timeout_s and not mission.get("accept_timeout_reported"):
                mission["accept_timeout_reported"] = True
                self._add_event(
                    "WARNING",
                    mission["target"],
                    f"No acknowledgement yet for {mission['label']}",
                    code="ORDER_ACK_TIMEOUT",
                    details={"order_id": mission["order_id"]},
                )
            return previous

        mission["acknowledged"] = True
        node_states = state.get("nodeStates") or []
        edge_states = state.get("edgeStates") or []
        action_states = state.get("actionStates") or []
        last_seq = _safe_int(state.get("lastNodeSequenceId"), -1)
        final_node_seq = max((int(node["sequenceId"]) for node in mission.get("nodes") or []), default=-1)
        if node_states or edge_states or bool(state.get("driving", False)):
            mission["seen_execution"] = True

        if mission.get("cancel_requested"):
            if not node_states and not edge_states and all(
                str(item.get("actionStatus")) in FINAL_ACTION_STATES
                for item in action_states
                if isinstance(item, Mapping)
            ):
                mission["terminal_reason"] = "cancelOrder completed"
                mission["terminal_code"] = "CANCEL_ORDER_FINISHED"
                return "CANCELLED"
            return "CANCELLING"
        if bool(state.get("paused", False)):
            return "PAUSED"
        if any(
            str(item.get("actionStatus")) == "RETRIABLE"
            for item in action_states
            if isinstance(item, Mapping)
        ):
            return "RETRIABLE"
        failed_actions = [
            item
            for item in action_states
            if isinstance(item, Mapping)
            and str(item.get("actionStatus")) == "FAILED"
        ]
        if failed_actions:
            first = failed_actions[0]
            mission["terminal_reason"] = str(
                first.get("actionResult")
                or first.get("actionDescription")
                or first.get("actionType")
                or first.get("actionId")
                or "Order action failed"
            )
            mission["terminal_code"] = "ACTION_FAILED"
            return "FAILED"
        critical_errors = [
            item
            for item in state.get("errors") or []
            if isinstance(item, Mapping)
            and str(item.get("errorLevel")) in {"CRITICAL", "FATAL"}
        ]
        if critical_errors:
            # The state belongs to this mission at this point. Critical/fatal
            # execution or localization errors therefore fail the active run,
            # but are not mislabeled as an order rejection.
            first = critical_errors[0]
            mission["terminal_reason"] = str(
                first.get("errorDescription")
                or first.get("errorType")
                or "Critical VDA error during execution"
            )
            mission["terminal_code"] = str(first.get("errorType") or "CRITICAL_VDA_ERROR")
            return "FAILED"
        if last_seq >= final_node_seq >= 0:
            return "FINISHED"
        if not node_states and not edge_states:
            return "FINISHED" if mission.get("seen_execution") else "ACCEPTED"
        if bool(state.get("driving", False)):
            return "RUNNING"
        return "ACCEPTED"

    def _mission_projection(
        self, mission: MutableMapping[str, Any], state: Mapping[str, Any]
    ) -> Dict[str, Any]:
        # Flask polling and the scenario worker can project the same mission at
        # the same time. Serialize the transition so a terminal event is emitted
        # once and a completed mission cannot race with a later state message.
        with self.lock:
            return self._mission_projection_locked(mission, state)

    def _mission_projection_locked(
        self, mission: MutableMapping[str, Any], state: Mapping[str, Any]
    ) -> Dict[str, Any]:
        old_status = str(mission.get("status", "SENT"))
        status = self._mission_status(mission, state)
        mission["status"] = status
        mission["updated_at"] = _utc_now()
        if status in TERMINAL_MISSION_STATES and not mission.get("finished_at"):
            mission["finished_at"] = mission["updated_at"]
            mission["finished_epoch"] = time.time()
        if old_status != status:
            level = "ERROR" if status in {"FAILED", "REJECTED"} else "WARNING" if status == "CANCELLED" else "INFO"
            message = (
                f"Reached {mission['label']}"
                if status == "FINISHED"
                else f"Mission {mission['label']} changed from {old_status} to {status}"
            )
            self._add_event(
                level,
                mission["target"],
                message,
                code="MISSION_FINISHED" if status == "FINISHED" else "MISSION_STATUS",
                details={
                    "order_id": mission["order_id"],
                    "status": status,
                    "reason": mission.get("terminal_reason"),
                    "code": mission.get("terminal_code"),
                },
            )

        state_matches = str(state.get("orderId", "")) == mission["order_id"]
        if state_matches:
            mission["last_matching_state"] = copy.deepcopy(state)
        experiment_state = state if state_matches else mission.get("last_matching_state", {})
        self._experiment_update(mission, experiment_state, status, old_status)
        last_seq = _safe_int(state.get("lastNodeSequenceId"), -1) if state_matches else _safe_int(mission.get("last_node_sequence_id"), -1)
        if state_matches:
            mission["last_node_sequence_id"] = last_seq
        remaining_nodes = {
            _safe_int(item.get("sequenceId"), -1): item
            for item in state.get("nodeStates") or []
            if state_matches and isinstance(item, Mapping)
        }
        remaining_edges = {
            _safe_int(item.get("sequenceId"), -1): item
            for item in state.get("edgeStates") or []
            if state_matches and isinstance(item, Mapping)
        }
        next_node_seq = min(remaining_nodes.keys(), default=None)
        steps: List[Dict[str, Any]] = []
        for node in mission["nodes"]:
            seq = int(node["sequenceId"])
            if status == "FINISHED":
                phase = "completed"
            elif status == "CANCELLED":
                phase = "completed" if seq <= last_seq else "cancelled"
            elif state_matches and seq <= last_seq:
                phase = "completed"
            elif seq == next_node_seq and status in {"RUNNING", "PAUSED", "ACCEPTED", "RETRIABLE"}:
                preceding_edge_pending = (seq - 1) in remaining_edges
                phase = "upcoming" if preceding_edge_pending and status in {"RUNNING", "PAUSED"} else "active"
            else:
                phase = "upcoming"
            steps.append(
                {
                    "kind": "node",
                    "id": node["nodeId"],
                    "sequence_id": seq,
                    "label": node.get("nodeDescriptor") or node["nodeId"],
                    "phase": phase,
                }
            )
            edge_seq = seq + 1
            edge = next((item for item in mission["edges"] if int(item["sequenceId"]) == edge_seq), None)
            if edge:
                if status == "FINISHED" or (state_matches and edge_seq <= last_seq):
                    edge_phase = "completed"
                elif edge_seq in remaining_edges and next_node_seq == edge_seq + 1:
                    edge_phase = "active" if status in {"RUNNING", "PAUSED"} else "upcoming"
                elif status == "CANCELLED":
                    edge_phase = "cancelled"
                else:
                    edge_phase = "upcoming"
                steps.append(
                    {
                        "kind": "edge",
                        "id": edge["edgeId"],
                        "sequence_id": edge_seq,
                        "label": edge.get("edgeDescriptor") or "Travel",
                        "phase": edge_phase,
                    }
                )

        actions = []
        if state_matches:
            actions = [dict(item) for item in state.get("actionStates") or [] if isinstance(item, Mapping)]
        duration = (mission.get("finished_epoch") or time.time()) - mission["created_epoch"]
        return {
            **{
                key: value
                for key, value in mission.items()
                if key not in {"nodes", "edges", "last_sample_pose", "target_pose", "rejection_errors", "last_matching_state"}
            },
            "steps": steps,
            "actions": actions,
            "last_node_sequence_id": last_seq,
            "duration_s": round(max(0.0, duration), 1),
        }

    def _refresh_events(self, devices: Mapping[str, Mapping[str, Any]]) -> None:
        for target, device in devices.items():
            current = {
                "connection": device.get("connection"),
                "mode": device.get("operating_mode"),
                "driving": bool(device.get("driving")),
                "paused": bool(device.get("paused")),
                "emergency": device.get("safety", {}).get("active_emergency_stop"),
                "field": bool(device.get("safety", {}).get("field_violation")),
                "errors": tuple((err.get("type"), err.get("level")) for err in device.get("errors", [])),
            }
            old = self._last_signature.get(target)
            if old is not None:
                if old.get("connection") != current["connection"]:
                    self._add_event("INFO", target, f"Connection is {current['connection']}", code="CONNECTION_CHANGED")
                if old.get("mode") != current["mode"]:
                    self._add_event("INFO", target, f"Operating mode changed to {current['mode']}", code="OPERATING_MODE_CHANGED")
                if old.get("driving") != current["driving"]:
                    self._add_event("INFO", target, "Robot started moving" if current["driving"] else "Robot stopped moving", code="MOTION_CHANGED")
                if old.get("paused") != current["paused"]:
                    self._add_event("INFO", target, "Order paused" if current["paused"] else "Order resumed", code="PAUSE_CHANGED")
                if old.get("emergency") != current["emergency"]:
                    self._add_event("WARNING" if current["emergency"] not in {None, "NONE"} else "INFO", target, f"Emergency-stop state: {current['emergency']}", code="EMERGENCY_STATE_CHANGED")
                if old.get("field") != current["field"]:
                    self._add_event("WARNING" if current["field"] else "INFO", target, "Protective field is occupied" if current["field"] else "Protective field is clear", code="FIELD_VIOLATION_CHANGED")
                if old.get("errors") != current["errors"] and current["errors"]:
                    self._add_event("WARNING", target, f"{len(current['errors'])} VDA error(s) reported", code="ERROR_SET_CHANGED")
            self._last_signature[target] = current

    # ------------------------------------------------------------------
    # VDA orders
    def _make_waypoint_order(
        self, waypoint_name: str, waypoint_cfg: Mapping[str, Any], state: Mapping[str, Any]
    ) -> Dict[str, Any]:
        waypoint = waypoint_cfg["waypoints"].get(waypoint_name)
        if waypoint is None:
            raise KeyError(waypoint_name)
        position = state.get("mobileRobotPosition") or {}
        if self.require_localized and not position:
            raise ValueError("ROX-Diff has no mobileRobotPosition")
        if self.require_localized and not bool(position.get("localized", False)):
            raise ValueError("ROX-Diff is not localized")
        map_id = str(waypoint_cfg["map_id"])
        current_map = str(position.get("mapId") or map_id)
        if current_map != map_id:
            raise ValueError(
                f"ROX-Diff state mapId={current_map!r}, waypoint mapId={map_id!r}"
            )

        order_id = str(uuid4())
        short_id = order_id.split("-")[0]
        current_node_id = f"temporary-current-{short_id}"
        target_node_id = f"waypoint-{waypoint_name}"
        current_x = _safe_float(position.get("x"), waypoint["x"])
        current_y = _safe_float(position.get("y"), waypoint["y"])
        current_theta = _safe_float(position.get("theta"), waypoint["theta"])
        return {
            "orderId": order_id,
            "orderUpdateId": 0,
            "orderDescription": f"Navigate ROX-Diff to waypoint {waypoint_name}",
            "nodes": [
                {
                    "nodeId": current_node_id,
                    "sequenceId": 0,
                    "nodeDescriptor": "Current robot pose (temporary start node)",
                    "released": True,
                    "nodePosition": {
                        "x": current_x,
                        "y": current_y,
                        "theta": current_theta,
                        "mapId": map_id,
                        "allowedDeviationXY": {
                            "a": self.start_tolerance_m,
                            "b": self.start_tolerance_m,
                            "theta": 0.0,
                        },
                        "allowedDeviationTheta": 3.141592653589793,
                    },
                    "actions": [],
                },
                {
                    "nodeId": target_node_id,
                    "sequenceId": 2,
                    "nodeDescriptor": waypoint["label"],
                    "released": True,
                    "nodePosition": {
                        "x": waypoint["x"],
                        "y": waypoint["y"],
                        "theta": waypoint["theta"],
                        "mapId": map_id,
                        "allowedDeviationXY": {
                            "a": waypoint["allowed_deviation_xy"],
                            "b": waypoint["allowed_deviation_xy"],
                            "theta": 0.0,
                        },
                        "allowedDeviationTheta": waypoint[
                            "allowed_deviation_theta"
                        ],
                    },
                    "actions": [],
                },
            ],
            "edges": [
                {
                    "edgeId": f"edge-{short_id}-to-{waypoint_name}",
                    "sequenceId": 1,
                    "edgeDescriptor": f"Navigate to {waypoint['label']}",
                    "released": True,
                    "actions": [],
                }
            ],
        }

    def _dispatch_waypoint(
        self, waypoint_name: str, *, source: str = "waypoint", scenario_id: str = ""
    ) -> Dict[str, Any]:
        waypoint_cfg = self._load_waypoints()
        target_cache = self._copy_target_state("rox")
        reasons = self._dispatch_reasons("rox", target_cache, waypoint_cfg)
        if reasons:
            raise RuntimeError("; ".join(reasons))
        state = target_cache.get("last_state") or {}
        order = self._make_waypoint_order(waypoint_name, waypoint_cfg, state)
        waypoint = waypoint_cfg["waypoints"][waypoint_name]
        mission = {
            "mission_id": str(uuid4()),
            "order_id": order["orderId"],
            "target": "rox",
            "source": source,
            "scenario_id": scenario_id,
            "waypoint": waypoint_name,
            "label": waypoint["label"],
            "description": waypoint["description"],
            "created_at": _utc_now(),
            "created_epoch": time.time(),
            "updated_at": _utc_now(),
            "status": "SENT",
            "cancel_requested": False,
            "nodes": copy.deepcopy(order["nodes"]),
            "edges": copy.deepcopy(order["edges"]),
        }
        self.publish_order(order, target="rox")
        with self.lock:
            self.missions.append(mission)
        try:
            self._experiment_begin(mission, state, waypoint)
        except Exception as exc:
            mission["experiment_logged"] = False
            self._add_event(
                "ERROR",
                "experiment",
                f"Could not create experiment record: {exc}",
                code="EXPERIMENT_RECORD_ERROR",
            )
        self._add_event(
            "INFO",
            "rox",
            f"Dispatched waypoint {waypoint['label']}",
            code="ORDER_SENT",
            details={"order_id": order["orderId"], "waypoint": waypoint_name},
        )
        return mission

    def _find_mission(self, order_id: str) -> Optional[Dict[str, Any]]:
        with self.lock:
            for mission in reversed(self.missions):
                if mission["order_id"] == order_id:
                    return mission
        return None

    def _mark_current_cancel_requested(self, target: str) -> None:
        target_cache = self._copy_target_state(target)
        state = target_cache.get("last_state") or {}
        order_id = str(state.get("orderId", ""))
        mission = self._find_mission(order_id)
        if mission:
            mission["cancel_requested"] = True
            mission["status"] = "CANCELLING"
        with self.lock:
            if self.active_scenario and self.active_scenario.get("status") in {
                "RUNNING",
                "PAUSED",
            }:
                self.active_scenario["status"] = "CANCELLING"
                self.active_scenario["stop_requested"] = True

    # ------------------------------------------------------------------
    # Scenarios
    def _scenario_worker(self) -> None:
        while not self._stop.wait(0.75):
            try:
                self._advance_scenario()
            except Exception as exc:  # keep UI alive after any scenario exception
                self._add_event(
                    "ERROR",
                    "scenario",
                    f"Scenario engine error: {exc}",
                    code="SCENARIO_ENGINE_ERROR",
                )
                with self.lock:
                    if self.active_scenario:
                        self.active_scenario["status"] = "FAILED"
                        self.active_scenario["error"] = str(exc)

    def _advance_scenario(self) -> None:
        with self.lock:
            scenario = copy.deepcopy(self.active_scenario)
        if not scenario or scenario.get("status") not in {"RUNNING", "CANCELLING"}:
            return
        if scenario.get("stop_requested"):
            if not scenario.get("active_order_id"):
                with self.lock:
                    if self.active_scenario:
                        self.active_scenario["status"] = "CANCELLED"
            return

        active_order_id = scenario.get("active_order_id")
        if active_order_id:
            mission = self._find_mission(active_order_id)
            if not mission:
                return
            state = (self._copy_target_state("rox").get("last_state") or {})
            projected = self._mission_projection(mission, state)
            status = projected["status"]
            if status == "FINISHED":
                with self.lock:
                    if self.active_scenario:
                        self.active_scenario["completed_steps"] += 1
                        self.active_scenario["active_order_id"] = None
                        self.active_scenario["active_waypoint"] = None
                        self.active_scenario["updated_at"] = _utc_now()
                return
            if status in {"FAILED", "REJECTED", "CANCELLED"}:
                with self.lock:
                    if self.active_scenario:
                        self.active_scenario["status"] = status
                        self.active_scenario["error"] = (
                            f"Step {scenario.get('active_waypoint')} ended as {status}"
                        )
                return
            return

        step_index = int(scenario.get("completed_steps", 0))
        steps = scenario.get("waypoints") or []
        if step_index >= len(steps):
            with self.lock:
                if self.active_scenario:
                    self.active_scenario["status"] = "FINISHED"
                    self.active_scenario["finished_at"] = _utc_now()
            self._add_event(
                "INFO",
                "scenario",
                f"Scenario {scenario['label']} finished",
                code="SCENARIO_FINISHED",
            )
            return

        waypoint_name = str(steps[step_index])
        try:
            mission = self._dispatch_waypoint(
                waypoint_name,
                source="scenario",
                scenario_id=str(scenario["id"]),
            )
        except RuntimeError as exc:
            # A transient active-order/state delay is normal between state messages.
            if "Another VDA order is active" in str(exc):
                return
            raise
        with self.lock:
            if self.active_scenario:
                self.active_scenario["active_order_id"] = mission["order_id"]
                self.active_scenario["active_waypoint"] = waypoint_name
                step_runs = self.active_scenario.setdefault("step_runs", [None for _ in steps])
                if step_index < len(step_runs):
                    step_runs[step_index] = mission["order_id"]
                self.active_scenario["updated_at"] = _utc_now()

    # ------------------------------------------------------------------
    # API
    def _register_routes(self) -> None:
        app = self.app

        @app.get("/api/dashboard")
        def dashboard_snapshot():
            return jsonify(_json_safe(self.snapshot()))

        @app.get("/api/waypoints")
        def waypoints_endpoint():
            cfg = self._load_waypoints()
            return jsonify(cfg)

        @app.post("/api/waypoints/<waypoint_name>/dispatch")
        def waypoint_dispatch_endpoint(waypoint_name: str):
            try:
                mission = self._dispatch_waypoint(waypoint_name)
            except KeyError:
                abort(404, f"Unknown waypoint {waypoint_name!r}")
            except RuntimeError as exc:
                abort(409, str(exc))
            except ValueError as exc:
                abort(400, str(exc))
            return jsonify({"ok": True, "mission": mission}), 202

        @app.post("/api/controls/<target>/<action>")
        def controls_endpoint(target: str, action: str):
            if target not in self.targets:
                abort(404, f"Unknown target {target!r}")
            enabled = self.rox_enabled if target == "rox" else self.crane_enabled
            if not enabled:
                abort(409, f"{target} is marked unavailable")
            action_map = {
                "pause": "startPause",
                "resume": "stopPause",
                "cancel": "cancelOrder",
                "factsheet": "factsheetRequest",
                "retry": "retry",
                "skip-retry": "skipRetry",
            }
            action_type = action_map.get(action)
            if action_type is None:
                abort(404, f"Unsupported dashboard control {action!r}")
            params: Optional[List[Dict[str, Any]]] = None
            state = self._copy_target_state(target).get("last_state") or {}
            if action == "pause":
                if not self._active_order(state):
                    abort(409, "No active order to pause")
                if bool(state.get("paused", False)):
                    abort(409, "Order execution is already paused")
            elif action == "resume":
                if not bool(state.get("paused", False)):
                    abort(409, "Order execution is not paused")
            elif action == "cancel":
                order_id = str(state.get("orderId", ""))
                if not self._active_order(state):
                    abort(409, "No active order to cancel")
                self._mark_current_cancel_requested(target)
                if order_id:
                    params = self.kv_params({"orderId": order_id})
            elif action in {"retry", "skip-retry"}:
                retriable = [
                    str(item.get("actionId"))
                    for item in state.get("actionStates") or []
                    if isinstance(item, Mapping)
                    and str(item.get("actionStatus")) == "RETRIABLE"
                    and item.get("actionId")
                ]
                requested_id = str((request.get_json(silent=True) or {}).get("actionId", ""))
                action_id_to_use = requested_id or (retriable[0] if len(retriable) == 1 else "")
                if not action_id_to_use:
                    abort(409, "Select one RETRIABLE order action")
                if action_id_to_use not in retriable:
                    abort(409, f"Action {action_id_to_use!r} is not currently RETRIABLE")
                params = self.kv_params({"actionId": action_id_to_use})
            try:
                action_id = self.publish_instant(
                    action_type, target=target, params=params
                )
            except HTTPException:
                raise
            except Exception as exc:
                abort(500, str(exc))
            control = {
                "action_id": action_id,
                "action_type": action_type,
                "target": target,
                "created_at": _utc_now(),
                "status": "SENT",
            }
            with self.lock:
                self.controls.append(control)
                if self.active_scenario:
                    if action == "pause" and self.active_scenario.get("status") == "RUNNING":
                        self.active_scenario["status"] = "PAUSED"
                    elif action == "resume" and self.active_scenario.get("status") == "PAUSED":
                        self.active_scenario["status"] = "RUNNING"
                    self.active_scenario["updated_at"] = _utc_now()
            self._add_event(
                "WARNING" if action == "cancel" else "INFO",
                target,
                f"Sent {action_type} instant action",
                code="INSTANT_ACTION_SENT",
                details={"action_id": action_id},
            )
            return jsonify({"ok": True, "control": control}), 202

        @app.post("/api/scenarios/<scenario_id>/start")
        def scenario_start_endpoint(scenario_id: str):
            waypoint_cfg = self._load_waypoints()
            scenarios = self._load_scenarios(waypoint_cfg["waypoints"])
            cfg = scenarios.get(scenario_id)
            if cfg is None:
                abort(404, f"Unknown scenario {scenario_id!r}")
            if not bool(cfg.get("enabled", False)):
                abort(409, str(cfg.get("disabled_reason") or "Scenario is disabled"))
            if cfg.get("target") != "rox":
                abort(409, "Only ROX-only scenarios are enabled while the crane is unavailable")
            target_cache = self._copy_target_state("rox")
            reasons = self._dispatch_reasons("rox", target_cache, waypoint_cfg)
            if reasons:
                abort(409, "; ".join(reasons))
            with self.lock:
                if self.active_scenario and self.active_scenario.get("status") in {
                    "RUNNING",
                    "PAUSED",
                    "CANCELLING",
                }:
                    abort(409, "Another scenario is already active")
                self.active_scenario = {
                    "id": scenario_id,
                    "run_id": str(uuid4()),
                    "label": cfg["label"],
                    "description": cfg["description"],
                    "waypoints": list(cfg["waypoints"]),
                    "status": "RUNNING",
                    "completed_steps": 0,
                    "step_runs": [None for _ in cfg["waypoints"]],
                    "active_order_id": None,
                    "active_waypoint": None,
                    "stop_requested": False,
                    "started_at": _utc_now(),
                    "updated_at": _utc_now(),
                }
            self._add_event(
                "INFO",
                "scenario",
                f"Started scenario {cfg['label']}",
                code="SCENARIO_STARTED",
            )
            return jsonify({"ok": True, "scenario": self.active_scenario}), 202

        @app.post("/api/scenarios/active/stop")
        def scenario_stop_endpoint():
            with self.lock:
                if not self.active_scenario or self.active_scenario.get("status") not in {
                    "RUNNING",
                    "PAUSED",
                    "CANCELLING",
                }:
                    abort(409, "No active scenario")
                self.active_scenario["stop_requested"] = True
                self.active_scenario["status"] = "CANCELLING"
            state = self._copy_target_state("rox").get("last_state") or {}
            if self._active_order(state):
                self._mark_current_cancel_requested("rox")
                order_id = str(state.get("orderId", ""))
                params = self.kv_params({"orderId": order_id}) if order_id else None
                self.publish_instant("cancelOrder", target="rox", params=params)
            else:
                with self.lock:
                    if self.active_scenario:
                        self.active_scenario["status"] = "CANCELLED"
            self._add_event(
                "WARNING",
                "scenario",
                "Scenario stop requested",
                code="SCENARIO_STOP_REQUESTED",
            )
            return jsonify({"ok": True}), 202

        @app.post("/api/events/clear")
        def clear_events_endpoint():
            with self.lock:
                self.events.clear()
            self._add_event("INFO", "server", "Event log cleared", code="EVENTS_CLEARED")
            return jsonify({"ok": True})

        @app.get("/api/map/image")
        def map_image_endpoint():
            try:
                map_id = self._load_waypoints().get("map_id", self.default_map_id)
            except Exception:
                map_id = self.default_map_id
            map_cfg = self._load_map(map_id)
            payload = map_cfg.get("_png")
            if not payload:
                abort(404, str(map_cfg.get("error") or "Map image unavailable"))
            return Response(payload, mimetype="image/png", headers={"Cache-Control": "no-cache"})

        @app.post("/api/experiment-mode")
        def experiment_mode_endpoint():
            payload = request.get_json(silent=True) or {}
            enabled = bool(payload.get("enabled"))
            self._set_experiment_mode(
                enabled,
                label=str(payload.get("label", "")),
                notes=str(payload.get("notes", "")),
            )
            return jsonify({"ok": True, "experiment": self._experiment_projection()})

        @app.get("/api/experiments")
        def experiments_endpoint():
            return jsonify(_json_safe(self._experiment_projection()))

        @app.get("/api/experiments/export.csv")
        def experiments_csv_endpoint():
            with self._db() as db:
                rows = [dict(row) for row in db.execute("SELECT * FROM experiment_runs ORDER BY started_at")]
            output = io.StringIO()
            if rows:
                writer = csv.DictWriter(output, fieldnames=list(rows[0].keys()))
                writer.writeheader()
                writer.writerows(rows)
            return Response(
                output.getvalue(),
                mimetype="text/csv",
                headers={"Content-Disposition": "attachment; filename=vda5050_experiment_runs.csv"},
            )

        @app.get("/healthz")
        def health_endpoint():
            mqtt_ok = self._mqtt_connected()
            return (
                jsonify(
                    {
                        "ok": mqtt_ok,
                        "service": "vda5050-master-control",
                        "mqtt_connected": mqtt_ok,
                        "protocol_version": self.protocol_version,
                        "uptime_s": time.monotonic() - self.started_monotonic,
                    }
                ),
                200 if mqtt_ok else 503,
            )

    def _control_projection(self, rox_state: Mapping[str, Any]) -> List[Dict[str, Any]]:
        instant_states = {
            str(item.get("actionId")): item
            for item in rox_state.get("instantActionStates") or []
            if isinstance(item, Mapping)
        }
        result: List[Dict[str, Any]] = []
        with self.lock:
            controls = list(self.controls)
        for control in controls[-20:]:
            item = instant_states.get(control["action_id"])
            projected = dict(control)
            if item:
                projected["status"] = item.get("actionStatus", "UNKNOWN")
                projected["result"] = item.get("actionResult", "")
            result.append(projected)
        return result

    def snapshot(self) -> Dict[str, Any]:
        try:
            waypoint_cfg = self._load_waypoints()
            waypoint_error = None
        except Exception as exc:
            waypoint_cfg = {"map_id": self.default_map_id, "configured": False, "waypoints": {}}
            waypoint_error = str(exc)
        scenarios = self._load_scenarios(waypoint_cfg["waypoints"])
        caches = {target: self._copy_target_state(target) for target in self.targets}
        devices = {
            target: self._device_projection(target, cache, waypoint_cfg)
            for target, cache in caches.items()
        }
        self._refresh_events(devices)
        rox_state = caches.get("rox", {}).get("last_state") or {}
        with self.lock:
            missions_raw = list(self.missions)
        missions = [
            self._mission_projection(mission, rox_state)
            if mission["target"] == "rox"
            else dict(mission)
            for mission in missions_raw
        ]
        current = next(
            (mission for mission in reversed(missions) if mission["status"] in ACTIVE_MISSION_STATES),
            None,
        )
        recent = list(reversed(missions[-10:]))

        waypoint_rows = []
        for name, waypoint in waypoint_cfg["waypoints"].items():
            status = "IDLE"
            mission = next(
                (item for item in reversed(missions) if item.get("waypoint") == name),
                None,
            )
            if mission:
                status = mission["status"]
            waypoint_rows.append(
                {
                    **waypoint,
                    "map_id": waypoint_cfg["map_id"],
                    "configured": waypoint_cfg["configured"],
                    "status": status,
                    "dispatch_ready": devices.get("rox", {}).get("dispatch_ready", False),
                    "disabled_reasons": devices.get("rox", {}).get("dispatch_reasons", []),
                }
            )

        with self.lock:
            events = list(reversed(self.events))
            active_scenario = copy.deepcopy(self.active_scenario)
        command_chain: Dict[str, Any]
        latest_mission = missions[-1] if missions else None
        scenario_status = str((active_scenario or {}).get("status", ""))
        scenario_is_active = scenario_status in {"RUNNING", "PAUSED", "CANCELLING"}
        latest_belongs_to_scenario = bool(
            active_scenario
            and latest_mission
            and latest_mission.get("source") == "scenario"
            and latest_mission.get("scenario_id") == active_scenario.get("id")
        )
        show_scenario_chain = bool(
            active_scenario
            and (scenario_is_active or latest_belongs_to_scenario or not latest_mission)
        )
        if show_scenario_chain:
            count = len(active_scenario.get("waypoints") or [])
            completed = int(active_scenario.get("completed_steps", 0))
            step_runs = active_scenario.get("step_runs") or [None for _ in range(count)]
            active_scenario["progress_percent"] = (
                round((completed / count) * 100.0, 1) if count else 0.0
            )
            scenario_steps = []
            for index, name in enumerate(active_scenario.get("waypoints") or []):
                order_id = step_runs[index] if index < len(step_runs) else None
                run = next((item for item in missions if item.get("order_id") == order_id), None)
                if index < completed:
                    phase, step_status = "completed", "FINISHED"
                elif index == completed and active_scenario.get("status") in {"RUNNING", "PAUSED", "CANCELLING"}:
                    phase, step_status = "active", (run or {}).get("status", active_scenario.get("status"))
                elif active_scenario.get("status") == "FINISHED":
                    phase, step_status = "completed", "FINISHED"
                elif active_scenario.get("status") in {"FAILED", "REJECTED", "CANCELLED"} and index == completed:
                    phase, step_status = "failed", active_scenario.get("status")
                else:
                    phase, step_status = "upcoming", "UPCOMING"
                waypoint = waypoint_cfg["waypoints"].get(name, {})
                scenario_steps.append(
                    {
                        "index": index,
                        "waypoint": name,
                        "label": waypoint.get("label", name.replace("_", " ").title()),
                        "phase": phase,
                        "status": step_status,
                        "order_id": order_id,
                        "x": waypoint.get("x"),
                        "y": waypoint.get("y"),
                        "theta": waypoint.get("theta"),
                    }
                )
            active_scenario["steps"] = scenario_steps
            command_chain = {
                "kind": "scenario",
                "title": active_scenario.get("label"),
                "status": active_scenario.get("status"),
                "description": active_scenario.get("description"),
                "progress_percent": active_scenario.get("progress_percent"),
                "steps": scenario_steps,
            }
        elif current or missions:
            selected = current or missions[-1]
            command_chain = {
                "kind": "order",
                "title": selected.get("label"),
                "status": selected.get("status"),
                "description": selected.get("description"),
                "progress_percent": 100.0 if selected.get("status") == "FINISHED" else None,
                "steps": selected.get("steps") or [],
            }
        else:
            command_chain = {
                "kind": "idle",
                "title": "Waiting for a VDA order",
                "status": "IDLE",
                "description": "Select a mapped destination or repeatable scenario.",
                "steps": [],
            }

        rox_device = devices.get("rox", {})
        retriable_ids = list(rox_device.get("retriable_action_ids") or [])
        control_availability = {
            "pause": bool(rox_device.get("enabled"))
            and bool(rox_device.get("online"))
            and bool(rox_device.get("active_order"))
            and not bool(rox_device.get("paused")),
            "resume": bool(rox_device.get("enabled"))
            and bool(rox_device.get("online"))
            and bool(rox_device.get("paused")),
            "cancel": bool(rox_device.get("enabled"))
            and bool(rox_device.get("online"))
            and bool(rox_device.get("active_order")),
            "factsheet": bool(rox_device.get("enabled")) and bool(rox_device.get("online")),
            "retry": bool(retriable_ids),
            "skip_retry": bool(retriable_ids),
            "retriable_action_ids": retriable_ids,
        }

        map_projection = self._load_map(waypoint_cfg.get("map_id"))
        map_projection.pop("_png", None)
        experiment = self._experiment_projection()

        return {
            "generated_at": _utc_now(),
            "server": {
                "status": "ONLINE",
                "mqtt_connected": self._mqtt_connected(),
                "broker": f"{self.broker_host}:{self.broker_port}",
                "protocol": f"VDA 5050 {self.protocol_version}",
                "uptime_s": round(time.monotonic() - self.started_monotonic, 1),
                "waypoint_file": str(self.waypoint_path),
                "waypoint_error": waypoint_error,
                "map_id": waypoint_cfg["map_id"],
                "waypoints_configured": waypoint_cfg["configured"],
            },
            "devices": devices,
            "waypoints": waypoint_rows,
            "scenarios": list(scenarios.values()),
            "active_scenario": active_scenario,
            "mission": current,
            "command_chain": command_chain,
            "missions": recent,
            "map": map_projection,
            "experiment": experiment,
            "controls": self._control_projection(rox_state),
            "control_availability": control_availability,
            "events": events[: self.event_limit],
            "capabilities": {
                "pause": True,
                "resume": True,
                "cancel": True,
                "factsheet": True,
                "retry": True,
                "skip_retry": True,
                "dynamic_waypoint_orders": True,
                "scenario_queue": True,
                "live_map": True,
                "experiment_logging": True,
                "crane_available": self.crane_enabled,
                "order_updates": False,
                "edge_actions": False,
                "zones": False,
            },
        }


def register_dashboard(app: Any, ctx: MutableMapping[str, Any]) -> DashboardController:
    """Register dashboard API routes once and return the controller instance."""
    existing = app.extensions.get("vda5050_dashboard")
    if existing is not None:
        return existing
    controller = DashboardController(app, ctx)
    app.extensions["vda5050_dashboard"] = controller
    return controller
