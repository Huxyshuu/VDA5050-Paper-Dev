# crane_vda5050_adapter_v3.py

"""

VDA 5050 v3.0 ⇄ OPC UA adapter for the Ilmatar overhead crane, with rich logging.

What’s new vs your original:
- Structured, timestamped logs at every significant step (startup, MQTT connect/subscribe,
  message receipt/validation, order+node execution, action start/finish, hoist/axes movement).
- Periodic progress logs in movement loops (no spam).
- Clear banners around long waits (e.g., “waiting for button...” with heartbeat).
- Robust schema loading with environment override + fallbacks.
- Environment-driven log level (LOG_LEVEL, default INFO) & concise formatting.

Keeps the crane behavior: XY moves first, optional Z-down, then node actions
(typical sequence: lowerHoist → buttonPress → raiseHoist to 'zu'), while
using v3.0 MQTT topics/messages compatible with master_control_panel_v3.py.

"""

from __future__ import annotations

import json
import logging
import os
import queue
import signal
import threading
import time
import traceback
import uuid
from datetime import datetime, timezone
from pathlib import Path
from typing import Any, Callable, Dict, List, Optional, Tuple

import jsonschema
import paho.mqtt.client as mqtt
import requests
from crane import Crane  # local project import – ensure PYTHONPATH is set

# ───────────────────────────────────────────────────────── configuration ──

BUTTON_STATUS_URL = os.getenv("BUTTON_STATUS_URL", "http://127.0.0.1:5000/status")
# The Flask status endpoint is used only for the supervised handover release
# buttonPress action. Crane automatic mode comes from OPC UA WatchDogFault.
BUTTON_NAME_RELEASE = os.getenv("BUTTON_RELEASE_NAME", "release")

BROKER_HOST = os.getenv(
    "VDA_MQTT_HOST",
    "192.168.50.115",  # Current Raspberry Pi MQTT address on DTLabOpen
)
BROKER_PORT = int(os.getenv("VDA_MQTT_PORT", "1883"))

# Keep the same environment names as master_control_panel_v3.py where possible.
# VDA 5050 v3.0 suggested MQTT root:
#   vda5050/v3/<manufacturer>/<serialNumber>/<topic>
VDA_INTERFACE_NAME = os.getenv("VDA_INTERFACE_NAME", "vda5050")
VDA_MAJOR_VERSION = os.getenv("VDA_MAJOR_VERSION", "v3")
PROTOCOL_VERSION = os.getenv(
    "VDA_PROTOCOL_VERSION", os.getenv("CRANE_VERSION", "3.0.0")
)
MANUFACTURER = os.getenv(
    "VDA_MANUFACTURER", os.getenv("CRANE_MANUFACTURER", "konecranes")
)
SERIAL_NUMBER = os.getenv("VDA_SERIAL_NUMBER", os.getenv("CRANE_SERIAL", "ilmatar_1"))
TOPIC_ROOT = os.getenv(
    "VDA_TOPIC_ROOT",
    os.getenv(
        "CRANE_TOPIC_ROOT",
        f"{VDA_INTERFACE_NAME}/{VDA_MAJOR_VERSION}/{MANUFACTURER}/{SERIAL_NUMBER}",
    ),
)
VDA_MQTT_QOS = int(os.getenv("VDA_MQTT_QOS", "0"))
DEFAULT_MAP_ID = os.getenv("CRANE_MAP_ID", "map")
LOG_LEVEL = os.getenv("LOG_LEVEL", "INFO").upper()

# Resolve files from the repository rather than the process working directory.
REPO_ROOT = Path(__file__).resolve().parents[1]
ENV_SCHEMA_DIR = os.getenv("VDA_SCHEMA_DIR")
LOCAL_SCHEMA_DIR = REPO_ROOT / "schemas" / "vda5050_v3"
CRANE_ACCESS_FILE = Path(
    os.getenv("CRANE_ACCESS_FILE", str(Path(__file__).with_name("access.txt")))
).expanduser()
CRANE_FACTSHEET_FILE = Path(
    os.getenv(
        "CRANE_FACTSHEET_FILE",
        str(Path(__file__).parent / "factsheets" / "ilmatar_crane_factsheet.template.json"),
    )
).expanduser()
ALLOW_UNHOMED_START = os.getenv("ALLOW_UNHOMED_START", "false").strip().lower() in {
    "1", "true", "yes", "on"
}

WATCHDOG_INTERVAL_S = max(0.01, float(os.getenv("CRANE_WATCHDOG_INTERVAL_S", "0.049")))
CRANE_WATCHDOG_WARN_GAP_S = max(
    WATCHDOG_INTERVAL_S * 1.5, float(os.getenv("CRANE_WATCHDOG_WARN_GAP_S", "0.15"))
)
CRANE_WATCHDOG_CRITICAL_GAP_S = max(
    CRANE_WATCHDOG_WARN_GAP_S, float(os.getenv("CRANE_WATCHDOG_CRITICAL_GAP_S", "0.50"))
)
CRANE_WATCHDOG_FAILURE_LIMIT = max(1, int(os.getenv("CRANE_WATCHDOG_FAILURE_LIMIT", "3")))
CRANE_MOTION_STALL_WARN_S = max(1.0, float(os.getenv("CRANE_MOTION_STALL_WARN_S", "6.0")))
CRANE_MOTION_STALL_FAIL_S = max(
    CRANE_MOTION_STALL_WARN_S, float(os.getenv("CRANE_MOTION_STALL_FAIL_S", "15.0"))
)
# Give the PLC a quiet re-arm window between independent crane commands.  The
# barrier stops all axes, lets the watchdog recover, and verifies that automatic
# mode remains available before the next command is sent.
CRANE_ACTION_SETTLE_S = max(0.0, float(os.getenv("CRANE_ACTION_SETTLE_S", "1.5")))
CRANE_PRE_MOTION_SETTLE_S = max(0.0, float(os.getenv("CRANE_PRE_MOTION_SETTLE_S", "0.75")))
CRANE_WATCHDOG_RECOVERY_TIMEOUT_S = max(
    1.0, float(os.getenv("CRANE_WATCHDOG_RECOVERY_TIMEOUT_S", "5.0"))
)
CRANE_WATCHDOG_RECOVERY_STABLE_S = max(
    WATCHDOG_INTERVAL_S * 2.0,
    float(os.getenv("CRANE_WATCHDOG_RECOVERY_STABLE_S", "0.75")),
)
CRANE_WATCHDOG_CRITICAL_LATCH_S = max(
    CRANE_WATCHDOG_RECOVERY_STABLE_S,
    float(os.getenv("CRANE_WATCHDOG_CRITICAL_LATCH_S", "1.5")),
)
STATE_INTERVAL_S = 3.0  # periodic /state publish
VISU_INTERVAL_S = 3.0  # periodic /visualization publish
CRANE_AUTO_WAIT_TIMEOUT_S = float(
    os.getenv("CRANE_AUTO_WAIT_TIMEOUT_S", os.getenv("AUTO_WAIT_TIMEOUT_S", "60"))
)
CRANE_AUTO_STABLE_S = max(0.0, float(os.getenv("CRANE_AUTO_STABLE_S", "1.0")))
CRANE_AUTO_MODE_POLL_S = max(0.05, float(os.getenv("CRANE_AUTO_MODE_POLL_S", "0.20")))
CRANE_MQTT_CONNECT_TIMEOUT_S = max(1.0, float(os.getenv("CRANE_MQTT_CONNECT_TIMEOUT_S", "15.0")))
CRANE_HOME_ON_START = os.getenv("CRANE_HOME_ON_START", "false").strip().lower() in {
    "1", "true", "yes", "on"
}

def _metres_env_to_mm(name: str, default_m: float) -> int:
    try:
        return int(round(float(os.getenv(name, str(default_m))) * 1000.0))
    except (TypeError, ValueError):
        raise ValueError(f"{name} must be a finite numeric value in metres")


HOME_BRIDGE_MM = _metres_env_to_mm("CRANE_HOME_BRIDGE_M", 17.534)
HOME_TROLLEY_MM = _metres_env_to_mm("CRANE_HOME_TROLLEY_M", 6.664)
HOME_HOIST_MM = _metres_env_to_mm("CRANE_HOME_HOIST_M", 3.071)


# ───────────────────────────────────────────────────────── utilities ──


class WatchdogHealth:
    """Thread-safe timing and failure telemetry for the PLC watchdog writer."""

    def __init__(self) -> None:
        self._lock = threading.RLock()
        self.started_monotonic = time.monotonic()
        self.last_attempt_monotonic: Optional[float] = None
        self.last_success_monotonic: Optional[float] = None
        self.last_duration_ms = 0.0
        self.max_duration_ms = 0.0
        self.last_gap_ms = 0.0
        self.max_gap_ms = 0.0
        self.consecutive_failures = 0
        self.total_failures = 0
        self.overruns = 0
        self.ticks = 0
        self.last_value: Optional[int] = None
        self.last_error = ""
        self.critical_until_monotonic = 0.0
        self.last_critical_gap_ms = 0.0

    def note_attempt(self, started: float) -> None:
        with self._lock:
            self.last_attempt_monotonic = started

    def note_success(self, value: Optional[int], started: float, finished: float) -> None:
        with self._lock:
            if self.last_success_monotonic is not None:
                self.last_gap_ms = (finished - self.last_success_monotonic) * 1000.0
                self.max_gap_ms = max(self.max_gap_ms, self.last_gap_ms)
                if self.last_gap_ms >= CRANE_WATCHDOG_CRITICAL_GAP_S * 1000.0:
                    self.last_critical_gap_ms = self.last_gap_ms
                    self.critical_until_monotonic = max(
                        self.critical_until_monotonic,
                        finished + CRANE_WATCHDOG_CRITICAL_LATCH_S,
                    )
            duration_ms = max(0.0, (finished - started) * 1000.0)
            self.last_duration_ms = duration_ms
            self.max_duration_ms = max(self.max_duration_ms, duration_ms)
            self.last_success_monotonic = finished
            self.consecutive_failures = 0
            self.ticks += 1
            self.last_value = value
            self.last_error = ""

    def note_failure(self, exc: BaseException) -> int:
        with self._lock:
            self.consecutive_failures += 1
            self.total_failures += 1
            self.last_error = f"{type(exc).__name__}: {exc}"
            return self.consecutive_failures

    def note_overrun(self) -> None:
        with self._lock:
            self.overruns += 1

    def snapshot(self) -> Dict[str, Any]:
        now = time.monotonic()
        with self._lock:
            age = None if self.last_success_monotonic is None else max(0.0, now - self.last_success_monotonic)
            if (
                self.consecutive_failures >= CRANE_WATCHDOG_FAILURE_LIMIT
                or age is None
                or age > CRANE_WATCHDOG_CRITICAL_GAP_S
                or now < self.critical_until_monotonic
            ):
                status = "CRITICAL"
            elif (
                self.consecutive_failures > 0
                or age > CRANE_WATCHDOG_WARN_GAP_S
                or self.last_gap_ms > CRANE_WATCHDOG_WARN_GAP_S * 1000.0
            ):
                status = "DEGRADED"
            else:
                status = "HEALTHY"
            return {
                "status": status,
                "interval_s": WATCHDOG_INTERVAL_S,
                "last_success_age_s": age,
                "last_write_duration_ms": self.last_duration_ms,
                "max_write_duration_ms": self.max_duration_ms,
                "last_success_gap_ms": self.last_gap_ms,
                "max_success_gap_ms": self.max_gap_ms,
                "consecutive_failures": self.consecutive_failures,
                "total_failures": self.total_failures,
                "overruns": self.overruns,
                "ticks": self.ticks,
                "last_value": self.last_value,
                "last_error": self.last_error,
                "last_critical_gap_ms": self.last_critical_gap_ms,
                "critical_latch_remaining_s": max(0.0, self.critical_until_monotonic - now),
            }


def wait_for_panel_button(
    btn: str,
    log: logging.Logger,
    stop_event: Optional[threading.Event] = None,
    timeout: Optional[float] = None,
) -> bool:
    """
    Polls BUTTON_STATUS_URL for a specific button and only accepts presses that
    happen AFTER we started waiting. Supports both response shapes:

      1) Single-button:
         {"pressed": true, "seq": 5}  or {"btn":"automatic","pressed":true,"seq":5}

      2) All-buttons:
         {"automatic":{"pressed":true,"seq":5}, "release":{"pressed":false,"seq":4}, ...}

    When a new press is seen, it is consumed so it can't be re-used.
    """

    def _extract(data: dict, button: str) -> Tuple[bool, int]:
        # shape 1: single-button at top-level
        if "seq" in data and "pressed" in data:
            try:
                return bool(data["pressed"]), int(data["seq"])
            except Exception:
                return False, 0
        # shape 1b: includes explicit btn key
        if data.get("btn") == button and "seq" in data and "pressed" in data:
            try:
                return bool(data["pressed"]), int(data["seq"])
            except Exception:
                return False, 0
        # shape 2: all-buttons nested dict
        sub = data.get(button)
        if isinstance(sub, dict) and "seq" in sub and "pressed" in sub:
            try:
                return bool(sub["pressed"]), int(sub["seq"])
            except Exception:
                return False, 0
        # unknown shape
        return False, 0

    log.info(
        "Waiting for panel button '%s' at %s (timeout=%s) ...",
        btn,
        BUTTON_STATUS_URL,
        timeout,
    )
    t0 = time.time()
    last_heartbeat = 0.0

    # Baseline sequence at start
    try:
        r0 = requests.get(BUTTON_STATUS_URL, params={"btn": btn}, timeout=1.5)
        data0 = r0.json() if r0.ok else {}
        _, baseline = _extract(data0, btn)
        if baseline == 0 and isinstance(data0, dict) and btn not in data0:
            log.debug(
                "Panel status baseline shape=%s keys=%s",
                type(data0).__name__,
                list(data0.keys())[:6],
            )
    except Exception:
        baseline = 0

    while not (stop_event and stop_event.is_set()):
        try:
            r = requests.get(BUTTON_STATUS_URL, params={"btn": btn}, timeout=1.5)
            if r.ok:
                data = r.json()
                pressed, seq = _extract(data, btn)
                if pressed and seq > baseline:
                    # consume press (prefer per-button consume; fall back to consume-all)
                    consumed = False
                    try:
                        rc = requests.get(
                            BUTTON_STATUS_URL,
                            params={"btn": btn, "consume": 1},
                            timeout=1.5,
                        )
                        if rc.ok:
                            consumed = True
                    except Exception:
                        pass
                    if not consumed:
                        try:
                            requests.get(
                                BUTTON_STATUS_URL, params={"consume": 1}, timeout=1.5
                            )
                        except Exception:
                            pass
                    log.info(
                        "Panel button '%s' detected (seq=%d > baseline=%d).",
                        btn,
                        seq,
                        baseline,
                    )
                    return True
        except requests.RequestException as e:
            log.debug("Panel poll error for '%s': %s", btn, e)

        if timeout is not None and (time.time() - t0) >= timeout:
            log.warning(
                "Panel wait for '%s' timed out after %.1fs.", btn, time.time() - t0
            )
            return False

        now = time.time()
        if now - last_heartbeat > 2.0:
            log.info("...still waiting for '%s' (%.1fs elapsed)", btn, now - t0)
            last_heartbeat = now

        time.sleep(0.2)

    log.info("Panel wait for '%s' aborted by stop signal.", btn)
    return False


def wait_for_crane_automatic_mode(
    crane: Crane,
    log: logging.Logger,
    stop_event: Optional[threading.Event] = None,
    timeout: Optional[float] = None,
    stable_s: float = 1.0,
) -> bool:
    """Wait until WatchDogFault is continuously false for ``stable_s``.

    DX_Custom_V.Status.WatchDogFault is the authoritative PLC signal for this
    installation: False means automatic/remote mode is active; True means it is
    not. Read failures fail closed and reset the stability timer.
    """
    log.info(
        "Waiting for OPC UA automatic mode: "
        "DX_Custom_V.Status.WatchDogFault must remain false for %.2fs "
        "(timeout=%s) ...",
        stable_s,
        timeout,
    )
    started = time.monotonic()
    automatic_since: Optional[float] = None
    last_fault: Optional[bool] = None
    last_heartbeat = 0.0
    while not (stop_event and stop_event.is_set()):
        now = time.monotonic()
        try:
            fault = bool(crane.get_watchdog_fault())
            if fault != last_fault:
                log.info(
                    "OPC UA WatchDogFault=%s -> operating mode %s",
                    fault,
                    "NOT AUTOMATIC" if fault else "AUTOMATIC candidate",
                )
                last_fault = fault
            if not fault:
                automatic_since = automatic_since or now
                if now - automatic_since >= stable_s:
                    log.info(
                        "Automatic mode confirmed from OPC UA "
                        "(WatchDogFault=false for %.2fs).",
                        now - automatic_since,
                    )
                    return True
            else:
                automatic_since = None
        except Exception as exc:
            automatic_since = None
            if now - last_heartbeat >= 2.0:
                log.warning("Cannot read WatchDogFault yet: %s", exc)
                last_heartbeat = now
        if timeout is not None and now - started >= timeout:
            log.error(
                "Automatic-mode wait timed out after %.1fs; "
                "WatchDogFault never remained false long enough.",
                now - started,
            )
            return False
        if now - last_heartbeat >= 2.0:
            log.info(
                "...still waiting for WatchDogFault=false (%.1fs elapsed)",
                now - started,
            )
            last_heartbeat = now
        time.sleep(CRANE_AUTO_MODE_POLL_S)
    log.info("Automatic-mode wait aborted by stop signal.")
    return False


def _watchdog_loop(
    crane: Crane,
    stop_event: threading.Event,
    log: logging.Logger,
    health: WatchdogHealth,
):
    """Deadline-scheduled process watchdog with visible health telemetry."""
    log.info(
        "Global watchdog loop started (interval=%.3fs, warning gap=%.3fs, critical gap=%.3fs)",
        WATCHDOG_INTERVAL_S,
        CRANE_WATCHDOG_WARN_GAP_S,
        CRANE_WATCHDOG_CRITICAL_GAP_S,
    )
    next_deadline = time.monotonic()
    last_gap_warning = 0.0
    while not stop_event.is_set():
        next_deadline += WATCHDOG_INTERVAL_S
        started = time.monotonic()
        health.note_attempt(started)
        try:
            crane.increment_watchdog()
            finished = time.monotonic()
            health.note_success(getattr(crane, "_watchdog_value", None), started, finished)
            snap = health.snapshot()
            if (
                snap["last_success_gap_ms"] > CRANE_WATCHDOG_WARN_GAP_S * 1000.0
                and finished - last_gap_warning > 5.0
            ):
                log.warning(
                    "Watchdog timing degraded: latest successful gap %.1f ms, last write %.1f ms",
                    snap["last_success_gap_ms"],
                    snap["last_write_duration_ms"],
                )
                last_gap_warning = finished
        except Exception as exc:
            failures = health.note_failure(exc)
            if failures == 1:
                log.warning("Watchdog write failed: %s", exc)
            elif failures >= CRANE_WATCHDOG_FAILURE_LIMIT:
                log.error(
                    "Watchdog write failed %d consecutive times; PLC automatic mode may be lost: %s",
                    failures,
                    exc,
                )
        delay = next_deadline - time.monotonic()
        if delay <= 0:
            health.note_overrun()
            next_deadline = time.monotonic()
            delay = 0.0
        stop_event.wait(delay)
    try:
        crane.stop_all()
    except Exception:
        pass
    log.info("Global watchdog loop stopped. Final health=%s", health.snapshot())


def _move_xy_to(
    crane: Crane,
    log: logging.Logger,
    bx_target: int,
    ty_target: int,
    timeout_s: float = 300.0,
    stop_event: Optional[Any] = None,
    abort_check: Optional[Callable[[], bool]] = None,
) -> bool:
    # Clear any latched motion before setting new targets
    for f in (crane.stop_bridge, crane.stop_trolley):
        try:
            f()
        except Exception:
            pass

    crane.set_target_bridge(bx_target)
    crane.set_target_trolley(ty_target)
    log.info("Homing XY → bridge=%d mm, trolley=%d mm", bx_target, ty_target)

    done_b = done_t = False
    start = time.time()

    # Progress sampling + warning gating
    MOVE_EPS_MM = 1  # consider ≥1 mm as progress
    NEAR_EPS_MM = 25  # suppress stall warnings when within 25 mm of target
    last_pos_sample = 0.0
    last_warn = 0.0
    last_progress = time.time()

    # Previous positions for progress detection
    try:
        prev_b = int(crane.get_bridge_position_absolute())
        prev_t = int(crane.get_trolley_position_absolute())
    except Exception:
        prev_b = prev_t = None

    while True:
        try:
            abort_requested = bool(stop_event and stop_event.is_set()) or bool(
                abort_check and abort_check()
            )
        except Exception as exc:
            log.error("Homing XY abort check failed closed: %s", exc)
            abort_requested = True
        if abort_requested:
            log.error("Homing XY aborted — issuing stop_all.")
            try:
                crane.stop_all()
            except Exception:
                pass
            return False

        # Drive each axis until it reports done; stop that axis immediately
        if not done_b:
            if crane.move_bridge_to_target_p():
                done_b = True
                try:
                    crane.stop_bridge()
                except Exception:
                    pass

        if not done_t:
            if crane.move_trolley_to_target_p():
                done_t = True
                try:
                    crane.stop_trolley()
                except Exception:
                    pass

        if done_b and done_t:
            # Belt-and-suspenders final stop
            try:
                crane.stop_bridge()
            except Exception:
                pass
            try:
                crane.stop_trolley()
            except Exception:
                pass
            log.info("Homing XY: on target.")
            return True

        now = time.time()
        if now - start > timeout_s:
            log.error("Homing XY timeout after %.1fs — issuing stop_all.", now - start)
            try:
                crane.stop_all()
            except Exception:
                pass
            return False

        # Sample/log progress at ~2 Hz and warn only on true stalls far from target
        if now - last_pos_sample > 0.5:
            try:
                cur_b = int(crane.get_bridge_position_absolute())
                cur_t = int(crane.get_trolley_position_absolute())

                # progress
                if (
                    prev_b is None
                    or abs(cur_b - prev_b) >= MOVE_EPS_MM
                    or abs(cur_t - prev_t) >= MOVE_EPS_MM
                ):
                    last_progress = now
                prev_b, prev_t = cur_b, cur_t

                rem_b = abs(bx_target - cur_b)
                rem_t = abs(ty_target - cur_t)
                log.debug(
                    "...homing XY: bridge=%d → %d (rem=%d), trolley=%d → %d (rem=%d)",
                    cur_b,
                    bx_target,
                    rem_b,
                    cur_t,
                    ty_target,
                    rem_t,
                )

                if (
                    (now - last_warn > 6.0)
                    and (now - last_progress > 6.0)
                    and (rem_b > NEAR_EPS_MM or rem_t > NEAR_EPS_MM)
                ):
                    log.warning("Homing XY: no progress — still trying.")
                    last_warn = now
            except Exception:
                pass
            last_pos_sample = now

        time.sleep(0.1)


def _move_hoist_to(
    crane: Crane,
    log: logging.Logger,
    hz_target: int,
    timeout_s: float = 300.0,
    stop_event: Optional[Any] = None,
    abort_check: Optional[Callable[[], bool]] = None,
) -> bool:
    crane.set_target_hoist(hz_target)
    log.info("Homing Z → hoist=%d mm", hz_target)

    start = time.time()

    # progress tracking
    try:
        prev_pos = int(crane.get_hoist_position_absolute())
    except Exception:
        prev_pos = None
    last_progress = time.time()
    last_pos_sample = 0.0
    last_warn = 0.0

    NEAR_EPS_MM = 25  # within this of target, don’t warn
    MOVE_EPS_MM = 1  # movement considered "progress"

    while True:
        try:
            abort_requested = bool(stop_event and stop_event.is_set()) or bool(
                abort_check and abort_check()
            )
        except Exception as exc:
            log.error("Homing Z abort check failed closed: %s", exc)
            abort_requested = True
        if abort_requested:
            log.error("Homing Z aborted — issuing stop_all.")
            try:
                crane.stop_all()
            except Exception:
                pass
            return False

        now = time.time()

        if crane.move_hoist_to_target(fast=True):
            log.info("Homing Z: on target.")
            try:
                crane.stop_hoist()
            except Exception:
                pass
            return True

        if now - start > timeout_s:
            log.error("Homing Z timeout after %.1fs — issuing stop_all.", now - start)
            try:
                crane.stop_all()
            except Exception:
                pass
            return False

        # sample/log progress ~2 Hz
        if now - last_pos_sample > 0.5:
            try:
                pos = int(crane.get_hoist_position_absolute())
                if prev_pos is None or abs(pos - prev_pos) >= MOVE_EPS_MM:
                    last_progress = now
                prev_pos = pos
                rem = abs(hz_target - pos)
                log.debug("...homing Z: hoist=%d → %d (rem=%d mm)", pos, hz_target, rem)

                # only warn on true stall AND not already near target
                if (
                    (now - last_warn > 6.0)
                    and (now - last_progress > 6.0)
                    and (rem > NEAR_EPS_MM)
                ):
                    log.warning("Homing Z: no progress — still trying.")
                    last_warn = now
            except Exception:
                pass
            last_pos_sample = now

        time.sleep(0.1)


def configure_logging() -> logging.Logger:
    fmt = "%(asctime)s | %(levelname)5s | %(name)s | %(message)s"
    datefmt = "%H:%M:%S"
    logging.basicConfig(
        level=getattr(logging, LOG_LEVEL, logging.INFO), format=fmt, datefmt=datefmt
    )
    log = logging.getLogger("crane_vda5050")
    log.info("Logging configured (level=%s)", LOG_LEVEL)
    return log


def utc_ts() -> str:
    """Return current time as ISO-8601 Z string (UTC)."""
    return (
        datetime.now(timezone.utc)
        .isoformat(timespec="milliseconds")
        .replace("+00:00", "Z")
    )


def _resolve_schema_dir() -> Path:
    """Return the official v3 schema directory or fail with an actionable error."""
    candidates = []
    if ENV_SCHEMA_DIR:
        env_path = Path(ENV_SCHEMA_DIR).expanduser()
        if not env_path.is_absolute():
            env_path = REPO_ROOT / env_path
        candidates.append(env_path)
    candidates.append(LOCAL_SCHEMA_DIR)
    for candidate in candidates:
        if candidate.is_dir():
            return candidate
    searched = ", ".join(str(item) for item in candidates)
    raise FileNotFoundError(f"VDA 5050 schema directory not found; checked: {searched}")


def load_schema(name: str, log: logging.Logger) -> Dict[str, Any]:
    """Load a JSON schema with robust fallbacks and clear logging."""
    base = _resolve_schema_dir()
    candidate = base / f"{name}.schema"
    if not candidate.exists():
        # Try bare filenames in working dir as a last resort
        candidate = Path(f"{name}.schema")
    try:
        with open(candidate, "r", encoding="utf-8") as fh:
            schema = json.load(fh)
            log.info("Loaded schema %s from %s", name, candidate)
            return schema
    except Exception as e:
        log.error("Failed to load schema %s from %s: %s", name, candidate, e)
        raise


class HeaderCounter:
    """Maintain monotonically increasing headerId per topic."""

    def __init__(self):
        self._lock = threading.Lock()
        self._counters: Dict[str, int] = {}

    def next(self, topic: str) -> int:
        with self._lock:
            self._counters[topic] = self._counters.get(topic, 0) + 1
            return self._counters[topic]


class _MultiEvent:
    """Event-like: is_set() if any of the wrapped events are set."""

    def __init__(self, *events):
        self._events = events

    def is_set(self) -> bool:
        return any(e.is_set() for e in self._events)


def _mqtt_reason_is_failure(reason_code: Any) -> bool:
    """Handle Paho v1 integer codes and v2 ReasonCode objects."""
    is_failure = getattr(reason_code, "is_failure", None)
    if isinstance(is_failure, bool):
        return is_failure
    try:
        return reason_code != 0
    except Exception:
        return True


def _internal_action_type(action_type: Optional[str]) -> str:
    """Map VDA 5050 v3 action names and legacy aliases to internal handlers."""
    aliases = {
        "startPause": "pause",  # v3 predefined action
        "stopPause": "resume",  # v3 predefined action
        "pause": "pause",  # legacy/local fallback
        "resume": "resume",  # legacy/local fallback
        "initPosition": "initializePosition",
    }
    return aliases.get(str(action_type or ""), str(action_type or ""))


# ───────────────────────────────────────────────────────── adapter ──


class VDA5050Adapter:
    """Main adapter class bridging MQTT ‹-› crane."""

    def __init__(self, crane: Crane, log: logging.Logger, watchdog_health: WatchdogHealth):
        self._paused = False
        self._hold_mode = False  # True if we don’t have speed scaling API
        self._speed_scale_backup = None  # remembers scale at pause

        self.log = log.getChild("adapter")
        self.crane = crane
        self.watchdog_health = watchdog_health
        self.header = HeaderCounter()
        self._motion_diag_lock = threading.RLock()
        self._motion_last_positions: Optional[Tuple[int, int, int]] = None
        self._motion_started_monotonic: Optional[float] = None
        self._motion_last_progress_monotonic: Optional[float] = None
        self._motion_stall_latched = False
        self._motion_last_error = ""

        # --- VDA state book-keeping (matches state.schema required fields) ---
        self.current_order_id: str = ""
        self.current_order_update_id: int = 0
        self.last_node_id: str = ""
        self.last_node_seq: int = 0
        self.node_states: List[Dict[str, Any]] = []
        self.edge_states: List[Dict[str, Any]] = []
        self.action_states: List[
            Dict[str, Any]
        ] = []  # lifecycle of current/unfinished actions
        try:
            self.watchdog_fault: bool = bool(self.crane.get_watchdog_fault())
        except Exception:
            self.watchdog_fault = True
        self.operating_mode: str = "MANUAL" if self.watchdog_fault else "AUTOMATIC"
        self.errors: List[Dict[str, Any]] = []  # keep active errors here
        # VDA 5050 v3 renamed batteryState -> powerSupply and eStop -> activeEmergencyStop.
        self.power_supply: Dict[str, Any] = {"stateOfCharge": 100.0, "charging": False}
        self.safety_state: Dict[str, Any] = {
            "activeEmergencyStop": "NONE",
            "fieldViolation": False,
        }
        self.instant_action_states: List[Dict[str, Any]] = []
        self._action_state_scope: str = (
            "order"  # "order" -> actionStates, "instant" -> instantActionStates
        )
        self._last_state_header_id: int = 0
        self.information_messages: List[
            Dict[str, Any]
        ] = []  # we’ll keep HOIST_POSITION here
        self._driving: bool = False  # True only while XY axes are moving

        self._resume_nudge = threading.Event()
        self._release_ctr = 0
        self._release_lock = threading.Lock()

        self._active_targets = {"bridge": None, "trolley": None, "hoist": None}

        # schemas
        self.schemas = {}
        for name in (
            "order",
            "instantActions",
            "connection",
            "state",
            "visualization",
            "factsheet",
        ):
            self.schemas[name] = load_schema(name, self.log)

        self._order_active = False
        self._instant_motion_active = False

        # paho mqtt client
        try:
            self.mqtt = mqtt.Client(
                mqtt.CallbackAPIVersion.VERSION2,
                client_id=SERIAL_NUMBER,
                clean_session=True,
            )
        except (AttributeError, TypeError):
            self.mqtt = mqtt.Client(client_id=SERIAL_NUMBER, clean_session=True)
        self.log.info("MQTT client created (client_id=%s)", SERIAL_NUMBER)

        # last-will = CONNECTION_BROKEN in VDA 5050 v3.0
        last_will = self._connection_msg("CONNECTION_BROKEN")
        if not self._validate("connection", last_will):
            self.log.warning("LWT connection msg failed validation (continuing).")
        self.mqtt.will_set(
            f"{TOPIC_ROOT}/connection", json.dumps(last_will), qos=1, retain=True
        )
        self.log.info("MQTT last-will configured on %s/connection", TOPIC_ROOT)

        # queues & control
        self._order_queue: "queue.Queue[Dict[str, Any]]" = queue.Queue()
        self._ia_queue: "queue.Queue[Dict[str, Any]]" = queue.Queue()
        self._stop = threading.Event()
        self._cancel = threading.Event()  # cancel current order (not global stop)
        self._stop_or_cancel = _MultiEvent(self._stop, self._cancel)

        self._node_ctx: Dict[str, Any] = {}

        # thread bookkeeping for nicer shutdown logs
        self._threads: List[threading.Thread] = []
        # MQTT startup synchronization. The adapter must not claim to be
        # running until the broker accepted the connection and ONLINE was sent.
        self._mqtt_ready = threading.Event()
        self._mqtt_connected = False
        self._mqtt_connect_error: Optional[str] = None


    # ─────────────────────────────── MQTT callbacks ──────────────────────────

    def _on_connect(self, client, userdata, flags, rc, properties=None):  # noqa: N802
        if _mqtt_reason_is_failure(rc):
            self._mqtt_connected = False
            self._mqtt_connect_error = f"MQTT connection rejected: {rc}"
            self.log.error(self._mqtt_connect_error)
            self._mqtt_ready.set()
            return
        try:
            self.log.info("MQTT connected to %s:%s (rc=%s)", BROKER_HOST, BROKER_PORT, rc)
            result, _mid = client.subscribe(
                [
                    (f"{TOPIC_ROOT}/order", VDA_MQTT_QOS),
                    (f"{TOPIC_ROOT}/instantActions", VDA_MQTT_QOS),
                ]
            )
            if result != mqtt.MQTT_ERR_SUCCESS:
                raise RuntimeError(f"MQTT subscribe failed rc={result}")
            self.log.info("Subscribed to %s/{order,instantActions}", TOPIC_ROOT)
            online = self._connection_msg("ONLINE")
            if not self._validate("connection", online):
                raise RuntimeError("ONLINE connection message failed schema validation")
            publish_info = client.publish(
                f"{TOPIC_ROOT}/connection", json.dumps(online), qos=1, retain=True
            )
            if publish_info.rc != mqtt.MQTT_ERR_SUCCESS:
                raise RuntimeError(f"ONLINE publish failed rc={publish_info.rc}")
            self.log.info("Published ONLINE connection state (retained).")
            try:
                self._publish_factsheet()
            except Exception as exc:
                self.log.warning("Factsheet not published at connect: %s", exc)
            self._mqtt_connected = True
            self._mqtt_connect_error = None
        except Exception as exc:
            self._mqtt_connected = False
            self._mqtt_connect_error = str(exc)
            self.log.exception("MQTT post-connect setup failed")
        finally:
            self._mqtt_ready.set()

    def _on_disconnect(self, client, userdata, *args):  # noqa: N802
        # Paho v1: (rc); Paho v2: (disconnect_flags, reason_code, properties).
        reason_code = args[1] if len(args) >= 2 else (args[0] if args else 0)
        was_connected = self._mqtt_connected
        self._mqtt_connected = False
        if not self._stop.is_set() and (was_connected or _mqtt_reason_is_failure(reason_code)):
            self.log.warning("MQTT disconnected unexpectedly (reason=%s)", reason_code)

    def _header_matches_identity(self, payload: Dict[str, Any]) -> bool:
        return (
            str(payload.get("version", "")) == PROTOCOL_VERSION
            and str(payload.get("manufacturer", "")) == MANUFACTURER
            and str(payload.get("serialNumber", "")) == SERIAL_NUMBER
        )

    def _refresh_automatic_mode(self) -> bool:
        """Read the PLC signal synchronously before accepting motion."""
        try:
            fault = bool(self.crane.get_watchdog_fault())
        except Exception as exc:
            self.log.warning("Cannot read WatchDogFault before motion: %s", exc)
            fault = True
        self.watchdog_fault = fault
        self.operating_mode = "MANUAL" if fault else "AUTOMATIC"
        return not fault

    def _set_order_error(self, payload: Dict[str, Any], error_type: str, reason: str) -> None:
        order_id = str(payload.get("orderId", ""))
        refs = []
        if order_id:
            refs.append({"referenceKey": "orderId", "referenceValue": order_id})
        refs.append(
            {
                "referenceKey": "orderUpdateId",
                "referenceValue": str(payload.get("orderUpdateId", 0)),
            }
        )
        self.errors = [
            item
            for item in self.errors
            if not (
                item.get("errorType") == error_type
                and any(
                    ref.get("referenceKey") == "orderId"
                    and ref.get("referenceValue") == order_id
                    for ref in item.get("errorReferences") or []
                )
            )
        ]
        self.errors.append(
            {
                "errorType": error_type,
                "errorLevel": "WARNING",
                "errorDescription": reason,
                "errorReferences": refs,
            }
        )
        self._publish_state()

    def _clear_order_errors(self, order_id: str) -> None:
        self.errors = [
            item
            for item in self.errors
            if not any(
                ref.get("referenceKey") == "orderId"
                and ref.get("referenceValue") == order_id
                for ref in item.get("errorReferences") or []
            )
        ]

    def _validate_order_semantics(self, payload: Dict[str, Any]) -> Optional[str]:
        if not self._refresh_automatic_mode():
            return (
                "Crane motion is unavailable because "
                "DX_Custom_V.Status.WatchDogFault is true or unreadable"
            )
        if int(payload.get("orderUpdateId", -1)) != 0:
            return "Only new orders with orderUpdateId=0 are supported by this adapter"
        nodes = payload.get("nodes") or []
        edges = payload.get("edges") or []
        if not nodes:
            return "Order contains no nodes"
        if self._order_active or not self._order_queue.empty():
            return "Crane is already executing or has a queued order; cancel it first"
        for node in nodes:
            position = node.get("nodePosition") or {}
            if str(position.get("mapId", "")) != DEFAULT_MAP_ID:
                return (
                    f"Node {node.get('nodeId')} uses mapId={position.get('mapId')!r}; "
                    f"configured crane map is {DEFAULT_MAP_ID!r}"
                )
        for edge in edges:
            if edge.get("actions"):
                return f"Edge actions are not supported (edgeId={edge.get('edgeId')})"
        node_sequences = [int(node.get("sequenceId", -1)) for node in nodes]
        edge_sequences = [int(edge.get("sequenceId", -1)) for edge in edges]
        expected_nodes = list(range(0, 2 * len(nodes), 2))
        expected_edges = list(range(1, 2 * len(nodes) - 1, 2))
        if node_sequences != expected_nodes or edge_sequences != expected_edges:
            return (
                f"Expected node sequenceIds {expected_nodes} and edge sequenceIds "
                f"{expected_edges}; got {node_sequences} and {edge_sequences}"
            )
        return None

    def _on_message(self, client, userdata, msg):  # noqa: N802
        topic = msg.topic
        try:
            payload = json.loads(msg.payload)
        except json.JSONDecodeError:
            self.log.error("Malformed JSON on %s: %r", topic, msg.payload[:200])
            return

        self.log.info("MQTT rx on %s (bytes=%d)", topic, len(msg.payload))
        if not self._header_matches_identity(payload):
            self.log.error("Rejected message with mismatched version/manufacturer/serialNumber")
            return
        if topic.endswith("/order"):
            if self._validate("order", payload):
                reason = self._validate_order_semantics(payload)
                if reason:
                    error_type = (
                        "MOBILE_ROBOT_NOT_AVAILABLE"
                        if "WatchDogFault" in reason
                        else "VALIDATION_FAILURE"
                    )
                    self.log.error("Order rejected: %s", reason)
                    self._set_order_error(payload, error_type, reason)
                    return
                self._clear_order_errors(str(payload.get("orderId", "")))
                self._order_queue.put(payload)
                self.log.info(
                    "Order enqueued: orderId=%s, updateId=%s, nodes=%d",
                    payload.get("orderId"),
                    payload.get("orderUpdateId"),
                    len(payload.get("nodes", [])),
                )
        elif topic.endswith("/instantActions"):
            if self._validate("instantActions", payload):
                actions = payload.get("actions", []) or []
                n = len(actions)
                # cancelOrder is a safety interrupt. Latch cancellation and STOP
                # immediately even when the executor is inside a long reset/home
                # instant action; lifecycle processing still occurs from the queue.
                if any(
                    _internal_action_type(str(action.get("actionType", ""))) == "cancelOrder"
                    for action in actions
                    if isinstance(action, dict)
                ):
                    self._cancel.set()
                    try:
                        self.crane.stop_all()
                    except Exception:
                        pass
                    self.log.warning("cancelOrder received; STOP latched immediately")
                self._ia_queue.put(payload)
                self.log.info("InstantActions enqueued: actions=%d", n)

    # ─────────────────────────────── public API ───────────────────────────────

    def start(self):
        # Keep the PLC-mode guard active while MQTT is being established.
        self._start_thread(self._automatic_mode_guard_task, name="auto_mode_guard")

        self.mqtt.on_connect = self._on_connect
        self.mqtt.on_disconnect = self._on_disconnect
        self.mqtt.on_message = self._on_message
        self._mqtt_ready.clear()
        self._mqtt_connect_error = None
        self.log.info("Connecting MQTT to %s:%s ...", BROKER_HOST, BROKER_PORT)
        self.mqtt.connect_async(BROKER_HOST, BROKER_PORT, keepalive=20)
        self.mqtt.loop_start()
        if not self._mqtt_ready.wait(CRANE_MQTT_CONNECT_TIMEOUT_S):
            self._stop.set()
            self.mqtt.loop_stop()
            raise RuntimeError(
                f"MQTT did not connect within {CRANE_MQTT_CONNECT_TIMEOUT_S:.1f}s"
            )
        if not self._mqtt_connected:
            self._stop.set()
            self.mqtt.loop_stop()
            raise RuntimeError(self._mqtt_connect_error or "MQTT connection failed")

        # Start publishers/executor only after subscriptions and ONLINE are ready.
        self._start_thread(self._publish_state_task, name="state_pub")
        self._start_thread(self._publish_visualization_task, name="visu_pub")
        self._start_thread(self._order_executor_task, name="executor")

    def stop(self):
        self.log.info("Stop requested. Signaling threads ...")
        self._stop.set()
        try:
            if not self._mqtt_connected:
                raise RuntimeError("MQTT is not connected")
            offline = self._connection_msg("OFFLINE")
            if not self._validate("connection", offline):
                self.log.warning(
                    "OFFLINE connection msg failed validation (continuing)."
                )
            self.mqtt.publish(
                f"{TOPIC_ROOT}/connection", json.dumps(offline), qos=1, retain=True
            )
            self.log.info("Published OFFLINE connection state (retained).")
        except Exception:
            self.log.exception("Failed to publish OFFLINE state during stop.")
        try:
            self.mqtt.loop_stop()
            self.mqtt.disconnect()
            self.log.info("MQTT disconnected.")
        except Exception:
            self.log.exception("Error on MQTT disconnect.")

        for t in self._threads:
            if t.is_alive():
                self.log.debug("Joining thread %s ...", t.name)
                t.join(timeout=2.0)

    def _start_thread(self, target, name: str):
        th = threading.Thread(
            target=self._thread_wrapper, args=(target, name), daemon=True, name=name
        )
        th.start()
        self._threads.append(th)
        self.log.info("Started thread: %s", name)

    def _thread_wrapper(self, target, name: str):
        try:
            target()
        except Exception:
            self.log.error(
                "Unhandled exception in thread '%s':\n%s", name, traceback.format_exc()
            )

    # ───────────────────────────── background jobs ────────────────────────────

    def _note_release(self) -> int:
        with self._release_lock:
            self._release_ctr += 1
            return self._release_ctr

    def _publish_state_task(self):
        self.log.info("State publisher running at %.2fs", STATE_INTERVAL_S)
        while not self._stop.is_set():
            self._publish_state()
            time.sleep(STATE_INTERVAL_S)

    def _automatic_mode_guard_task(self):
        """Continuously enforce PLC mode and watchdog transport health."""
        self.log.info(
            "Automatic-mode guard running at %.2fs using DX_Custom_V.Status.WatchDogFault",
            CRANE_AUTO_MODE_POLL_S,
        )
        last_fault: Optional[bool] = None
        last_health_status: Optional[str] = None
        fault_stop_latched = False
        while not self._stop.is_set():
            try:
                plc_fault = bool(self.crane.get_watchdog_fault())
            except Exception as exc:
                plc_fault = True
                self.log.warning("Automatic-mode guard read failed: %s", exc)
            health = self.watchdog_health.snapshot()
            transport_critical = health["status"] == "CRITICAL"
            fault = bool(plc_fault or transport_critical)
            self.watchdog_fault = plc_fault
            self.operating_mode = "MANUAL" if fault else "AUTOMATIC"
            if health["status"] != last_health_status:
                level = self.log.error if transport_critical else (self.log.warning if health["status"] == "DEGRADED" else self.log.info)
                level("Watchdog transport health changed to %s: %s", health["status"], health)
                last_health_status = health["status"]
            if transport_critical:
                self._set_runtime_error(
                    "WATCHDOG_COMMUNICATION_FAILURE",
                    f"Watchdog transport is CRITICAL: {health.get('last_error') or 'successful write gap exceeded'}",
                )
            else:
                self._clear_runtime_error("WATCHDOG_COMMUNICATION_FAILURE")
            changed = fault != last_fault
            if changed:
                if fault:
                    self.log.error(
                        "Crane automatic availability lost: WatchDogFault=%s, watchdogHealth=%s",
                        plc_fault,
                        health["status"],
                    )
                else:
                    self.log.info("WatchDogFault cleared and watchdog transport is healthy; operatingMode=AUTOMATIC")
                last_fault = fault
            if not fault:
                fault_stop_latched = False
            elif not fault_stop_latched:
                try:
                    self.crane.stop_all()
                except Exception as exc:
                    self.log.warning("Fail-closed STOP could not be written: %s", exc)
                fault_stop_latched = True
            if fault and (self._order_active or self._driving or self._instant_motion_active) and not self._cancel.is_set():
                self._cancel.set()
                self._force_hold_pose()
                self.log.error(
                    "Automatic/watchdog health was lost during motion; motion stopped and current order was canceled."
                )
            self._stop.wait(CRANE_AUTO_MODE_POLL_S)

    def _publish_visualization_task(self):
        self.log.info("Visualization publisher running at %.2fs", VISU_INTERVAL_S)
        while not self._stop.is_set():
            self._publish_visualization()
            time.sleep(VISU_INTERVAL_S)

    def _order_executor_task(self):
        """Handle orders and instant actions sequentially."""
        self.log.info("Executor task running.")
        while not self._stop.is_set():
            # Normal path - orders
            try:
                order = self._order_queue.get(timeout=0.1)
                self._order_active = True
                try:
                    self._execute_order(order)
                finally:
                    self._order_active = False
            except queue.Empty:
                pass
            # instant actions
            try:
                ia = self._ia_queue.get_nowait()
                self._execute_instant_actions(ia)
            except queue.Empty:
                pass

    # ─────────────────────────── execution helpers ───────────────────────────

    def _temporarily_enable_motion_for_reset(self) -> bool:
        """
        If pause used global speed-scale (scale is ~0), temporarily lift it so the reset
        can move. Returns True if we changed scale and should restore afterwards.
        """
        scale_now = self._try_get_speed_scale()
        if scale_now is not None and scale_now <= 0.001:
            target = (
                self._speed_scale_backup
                if (self._speed_scale_backup and self._speed_scale_backup > 0)
                else 1.0
            )
            if self._try_set_speed_scale(float(target)):
                self.log.debug(
                    "Reset: temporarily enabled global speed to %.3f", target
                )
                return True
        return False

    def _restore_motion_after_reset_if_needed(self, changed: bool, was_paused: bool):
        """
        If we temporarily enabled motion for reset while the system was paused via
        global speed-scale, ramp it back to 0 so we respect the paused state.
        """
        if changed and was_paused:
            cur = self._try_get_speed_scale()
            cur = float(cur) if cur is not None else 1.0
            self._ramp_speed_scale(cur, 0.0, duration_s=1.5, steps=15)
            self.log.debug(
                "Reset: restored global speed back to 0 due to paused state."
            )

    def _force_hold_pose(self):
        """Stop all axes and retarget to current pose to prevent further drifting."""
        try:
            cb = int(self.crane.get_bridge_position_absolute())
            ct = int(self.crane.get_trolley_position_absolute())
            ch = int(self.crane.get_hoist_position_absolute())
        except Exception:
            cb = ct = ch = None

        # Drop motion commands
        try:
            self.crane.stop_bridge()
        except Exception:
            pass
        try:
            self.crane.stop_trolley()
        except Exception:
            pass
        try:
            self.crane.stop_hoist()
        except Exception:
            pass

        # Retarget to current pose so PLC won’t resume chasing old targets
        try:
            if cb is not None:
                self.crane.set_target_bridge(cb)
            if ct is not None:
                self.crane.set_target_trolley(ct)
            if ch is not None:
                self.crane.set_target_hoist(ch)
            self._active_targets.update({"bridge": cb, "trolley": ct, "hoist": ch})
        except Exception:
            pass

    def _motion_transition_barrier(
        self,
        context: str,
        *,
        settle_s: float = CRANE_ACTION_SETTLE_S,
        stop_all: bool = True,
    ) -> bool:
        """Stop, settle and require a stable watchdog before another command.

        Ilmatar appears to need a short command re-arm period between axis modes.
        This barrier also gives the high-priority watchdog writer a quiet window
        after motion-related OPC UA traffic.  It fails closed if automatic mode
        disappears or watchdog transport health does not recover in time.
        """
        started = time.monotonic()
        if stop_all:
            try:
                self.crane.stop_all()
            except Exception as exc:
                self.log.error("Transition barrier %s could not stop all axes: %s", context, exc)
                return False

        minimum_until = started + max(0.0, settle_s)
        deadline = started + max(
            max(0.0, settle_s),
            CRANE_WATCHDOG_RECOVERY_TIMEOUT_S,
        )
        healthy_since: Optional[float] = None
        last_snapshot: Dict[str, Any] = {}
        self.log.info(
            "Transition barrier: %s (settle %.2fs, watchdog recovery timeout %.2fs)",
            context,
            settle_s,
            CRANE_WATCHDOG_RECOVERY_TIMEOUT_S,
        )

        while time.monotonic() <= deadline:
            if self._stop_or_cancel.is_set():
                self.log.warning("Transition barrier %s interrupted by stop/cancel", context)
                return False
            try:
                plc_fault = bool(self.crane.get_watchdog_fault())
            except Exception as exc:
                self.log.error("Transition barrier %s cannot read WatchDogFault: %s", context, exc)
                return False

            last_snapshot = self.watchdog_health.snapshot()
            healthy_now = (
                not plc_fault
                and last_snapshot.get("status") == "HEALTHY"
                and int(last_snapshot.get("consecutive_failures", 0)) == 0
                and last_snapshot.get("last_success_age_s") is not None
                and float(last_snapshot["last_success_age_s"]) <= CRANE_WATCHDOG_WARN_GAP_S
            )
            now = time.monotonic()
            if healthy_now:
                healthy_since = healthy_since or now
                if (
                    now >= minimum_until
                    and now - healthy_since >= CRANE_WATCHDOG_RECOVERY_STABLE_S
                ):
                    self.watchdog_fault = False
                    self.operating_mode = "AUTOMATIC"
                    self.log.info(
                        "Transition barrier complete: %s; watchdog stable for %.2fs",
                        context,
                        now - healthy_since,
                    )
                    return True
            else:
                healthy_since = None
                if plc_fault:
                    self.watchdog_fault = True
                    self.operating_mode = "MANUAL"
                    self.log.error(
                        "Transition barrier %s failed: WatchDogFault=true",
                        context,
                    )
                    return False
            time.sleep(0.05)

        self.log.error(
            "Transition barrier %s timed out waiting for watchdog recovery: %s",
            context,
            last_snapshot,
        )
        return False

    def _retarget_prevent_drifting(self):
        """Stop all axes and retarget to current pose to prevent further drifting."""
        try:
            cb = int(self.crane.get_bridge_position_absolute())
            ct = int(self.crane.get_trolley_position_absolute())
            ch = int(self.crane.get_hoist_position_absolute())
        except Exception:
            cb = ct = ch = None

        # Drop motion commands (already done with stop_all() so dont need to write again.)

        # Retarget to current pose so PLC won’t resume chasing old targets
        try:
            if cb is not None:
                self.crane.set_target_bridge(cb)
            if ct is not None:
                self.crane.set_target_trolley(ct)
            if ch is not None:
                self.crane.set_target_hoist(ch)
            self._active_targets.update({"bridge": cb, "trolley": ct, "hoist": ch})
        except Exception:
            pass

    def _drain_instant_actions_nonblocking(self):
        """Allow pause/resume to preempt movement loops."""
        drained = 0
        while True:
            try:
                ia = self._ia_queue.get_nowait()
            except queue.Empty:
                break
            self._execute_instant_actions(ia)
            drained += 1
        if drained:
            self.log.debug("Drained %d instantActions in-loop.", drained)

    def _try_get_speed_scale(self) -> Optional[float]:
        for name in (
            "get_speed_scaling",
            "get_speed_scale",
            "get_speed_factor",
            "get_global_speed",
        ):
            if hasattr(self.crane, name):
                try:
                    return float(getattr(self.crane, name)())
                except Exception:
                    pass
        return None

    def _try_set_speed_scale(self, val: float) -> bool:
        for name in (
            "set_speed_scaling",
            "set_speed_scale",
            "set_speed_factor",
            "set_global_speed",
        ):
            if hasattr(self.crane, name):
                try:
                    getattr(self.crane, name)(float(val))
                    return True
                except Exception:
                    pass
        return False

    def _ramp_speed_scale(
        self, start: float, end: float, duration_s: float = 1.5, steps: int = 15
    ):
        if duration_s <= 0 or steps <= 1:
            self._try_set_speed_scale(end)
            return
        for i in range(steps):
            if self._stop.is_set():
                return
            # if someone already paused/resumed again, just follow new state
            t = (i + 1) / steps
            val = start + (end - start) * t
            if not self._try_set_speed_scale(val):
                return
            time.sleep(duration_s / steps)

    def _get_action_param(self, action: Dict[str, Any], key: str, default=None):
        for p in action.get("actionParameters", []):
            if p.get("key") == key:
                return p.get("value", default)
        return default

    # ---------- action lifecycle helpers ----------
    def _ensure_action_id(self, action: Dict[str, Any]) -> str:
        aid = action.get("actionId")
        return str(aid) if aid else str(uuid.uuid4())

    def _action_begin(
        self, action: Dict[str, Any], default_type: str, description: str = ""
    ) -> str:
        """Insert/replace an actionState with INITIALIZING and publish."""
        aid = self._ensure_action_id(action)
        atype = action.get("actionType", default_type)
        desc = (
            action.get("actionDescriptor")
            or action.get("actionDescription")
            or description
            or atype
        )
        states = (
            self.instant_action_states
            if self._action_state_scope == "instant"
            else self.action_states
        )
        # replace any previous entry with same id in the selected v3 state bucket
        states[:] = [a for a in states if a.get("actionId") != aid]
        states.append(
            {
                "actionId": aid,
                "actionType": atype,
                "actionDescriptor": desc,
                "actionStatus": "INITIALIZING",
                "actionResult": "",
                # Compatibility aliases for older local tools; v3 schemas allow extra fields.
                "actionDescription": desc,
                "resultDescription": "",
            }
        )
        self._publish_state()
        return aid

    def _action_update(
        self,
        action_id: str,
        status: Optional[str] = None,
        result: Optional[str] = None,
        description: Optional[str] = None,
    ):
        """Update fields of an existing actionState and publish."""
        states = (
            self.instant_action_states
            if self._action_state_scope == "instant"
            else self.action_states
        )
        for a in states:
            if a.get("actionId") == action_id:
                if status is not None:
                    a["actionStatus"] = status
                if description is not None:
                    a["actionDescriptor"] = description
                    a["actionDescription"] = description
                if result is not None:
                    a["actionResult"] = result
                    a["resultDescription"] = result
                break
        self._publish_state()

    def _action_finish(
        self, action_id: str, ok: bool = True, result: Optional[str] = None
    ):
        """Mark FINISHED/FAILED and publish."""
        self._action_update(
            action_id, status=("FINISHED" if ok else "FAILED"), result=result
        )

    def _actions_mark_paused(self):
        """Set RUNNING/INITIALIZING actions to PAUSED and publish once."""
        changed = False
        for a in self.action_states:
            if a.get("actionStatus") in ("RUNNING", "INITIALIZING"):
                a["actionStatus"] = "PAUSED"
                changed = True
        if changed:
            self._publish_state()

    def _actions_mark_running(self):
        """Set PAUSED actions back to RUNNING and publish once."""
        changed = False
        for a in self.action_states:
            if a.get("actionStatus") == "PAUSED":
                a["actionStatus"] = "RUNNING"
                changed = True
        if changed:
            self._publish_state()

    # ---------- end helpers ----------

    # ---------- motion detection helpers ----------
    def _is_xy_moving(self, eps_mm: int = 1) -> bool:
        # Prefer our own runtime flag; fall back to target vs. actual
        if getattr(self, "_driving", False):
            return True
        try:
            cur_b = int(self.crane.get_bridge_position_absolute())
            cur_t = int(self.crane.get_trolley_position_absolute())
            tgt_b = self._active_targets.get("bridge")
            tgt_t = self._active_targets.get("trolley")
            if tgt_b is None or tgt_t is None:
                return False
            return abs(cur_b - int(tgt_b)) > eps_mm or abs(cur_t - int(tgt_t)) > eps_mm
        except Exception:
            return False

    def _is_hoist_moving(self, eps_mm: int = 1) -> bool:
        try:
            cur_h = int(self.crane.get_hoist_position_absolute())
            tgt_h = self._active_targets.get("hoist")
            if tgt_h is None:
                return False
            return abs(cur_h - int(tgt_h)) > eps_mm
        except Exception:
            return False

    def _is_any_motion(self) -> bool:
        return self._is_xy_moving() or self._is_hoist_moving()

    # ---------- end helpers ----------

    def _wait_for_button(self, timeout: Optional[float] = None) -> bool:
        # For in-order 'buttonPress' actions we wait for the "release" button.
        return wait_for_panel_button(
            BUTTON_NAME_RELEASE, self.log, self._stop_or_cancel, timeout
        )

    def _execute_order(self, order_msg: Dict[str, Any]):
        """Execute nodes sequentially (edges ignored)."""
        self._cancel.clear()
        order_id = order_msg.get("orderId")
        update_id = order_msg.get("orderUpdateId")
        nodes: List[Dict[str, Any]] = order_msg.get("nodes", [])
        edges: List[Dict[str, Any]] = order_msg.get("edges", [])

        if edges:
            act_on_edges = sum(
                1
                for e in edges
                if isinstance(e.get("actions"), list) and len(e["actions"]) > 0
            )
            self.log.info(
                "Order contains %d edge(s); crane path movement is node-position based (edge actions=%d).",
                len(edges),
                act_on_edges,
            )

        # keep state schema fields up-to-date
        self.current_order_id = order_id or ""
        self.current_order_update_id = int(update_id or 0)
        self.action_states = []  # per spec: keep until a new order arrives, then clear

        # snapshot remaining nodes/edges for /state.*States (minimal fields per schema)
        try:
            self.node_states = [
                {
                    "nodeId": n["nodeId"],
                    "sequenceId": int(n["sequenceId"]),
                    "released": bool(n.get("released", True)),
                    **(
                        {
                            "nodePosition": {
                                "x": float(n["nodePosition"]["x"]),
                                "y": float(n["nodePosition"]["y"]),
                                "mapId": str(n["nodePosition"]["mapId"]),
                            }
                        }
                        if "nodePosition" in n
                        else {}
                    ),
                }
                for n in nodes
            ]
        except Exception:
            self.node_states = []

        try:
            edges_in = order_msg.get("edges", [])
            self.edge_states = [
                {
                    "edgeId": e["edgeId"],
                    "sequenceId": int(e["sequenceId"]),
                    "released": bool(e.get("released", True)),
                }
                for e in edges_in
            ]
        except Exception:
            self.edge_states = []

        self.log.info(
            "Begin order execution: orderId=%s updateId=%s nodes=%d",
            order_id,
            update_id,
            len(nodes),
        )
        if not self._motion_transition_barrier(
            "order start",
            settle_s=CRANE_PRE_MOTION_SETTLE_S,
        ):
            self._set_runtime_error(
                "CRANE_TRANSITION_BARRIER_FAILED",
                "Crane could not establish a stable automatic/watchdog state before order start",
            )
            self._cancel.set()
            return

        for idx, node in enumerate(nodes):
            if self._stop_or_cancel.is_set():
                self.log.info("Stop/Cancel signal received; aborting order execution.")
                return

            node_id = node.get("nodeId")
            self.log.info("-> Node %d/%d: nodeId=%s", idx + 1, len(nodes), node_id)

            # --- 1) XY movement ---
            try:
                pos = node["nodePosition"]
                x_m = float(pos["x"])
                y_m = float(pos["y"])
                self.log.info("Move to XY: x=%.3f m, y=%.3f m", x_m, y_m)
            except (KeyError, TypeError, ValueError) as e:
                self.log.error("Invalid nodePosition in node %s: %s", node_id, e)
                continue

            # Set targets (metres → mm)
            bx_target = int(x_m * 1000)
            ty_target = int(y_m * 1000)
            self.crane.set_target_bridge(bx_target)
            self.crane.set_target_trolley(ty_target)
            self._active_targets["bridge"] = bx_target
            self._active_targets["trolley"] = ty_target
            self.log.debug(
                "XY targets: bridge=%d mm, trolley=%d mm", bx_target, ty_target
            )

            # reflect motion in /state.driving
            self._driving = True
            self._publish_state()  # heartbeat with driving=True

            # Move both axes, stop commanding an axis once it's done
            done_b = False
            done_t = False
            last_log = 0.0
            start = time.time()
            MAX_XY_S = 300.0  # hard timeout
            # progress tracking
            try:
                prev_b = int(self.crane.get_bridge_position_absolute())
                prev_t = int(self.crane.get_trolley_position_absolute())
            except Exception:
                prev_b = prev_t = None
            last_progress = time.time()

            while not self._stop_or_cancel.is_set():
                # Let pause/resume preempt immediately
                self._drain_instant_actions_nonblocking()
                if self._stop_or_cancel.is_set():
                    # cancelOrder may have just been processed above
                    self._force_hold_pose()
                    self.log.info("Order canceled; exiting XY loop immediately.")
                    return

                # 2) One-shot nudge after resume so bridge/trolley "wake up"
                if self._resume_nudge.is_set():
                    self._resume_nudge.clear()
                    try:
                        # Mark axes as NOT done so the loop will call move_* again
                        done_b = False
                        done_t = False

                        # Briefly stop axes to generate a fresh edge for the PLC
                        self.crane.stop_bridge()
                        self.crane.stop_trolley()

                        # Re-assert last targets (even if they "didn't change") to wake controller
                        if self._active_targets.get("bridge") is not None:
                            self.crane.set_target_bridge(self._active_targets["bridge"])
                        if self._active_targets.get("trolley") is not None:
                            self.crane.set_target_trolley(
                                self._active_targets["trolley"]
                            )
                        self.log.debug(
                            "resume-nudge: reasserted XY targets (bridge=%s, trolley=%s)",
                            self._active_targets.get("bridge"),
                            self._active_targets.get("trolley"),
                        )
                    except Exception:
                        pass
                    time.sleep(0.05)  # give the PLC a scan to notice the drop/re-apply

                # If paused, freeze XY at current pose until resume (works for both modes)
                if self._paused:
                    try:
                        cur_b = int(self.crane.get_bridge_position_absolute())
                        cur_t = int(self.crane.get_trolley_position_absolute())
                        self.crane.set_target_bridge(cur_b)
                        self.crane.set_target_trolley(cur_t)
                        self.crane.stop_bridge()
                        self.crane.stop_trolley()
                    except Exception:
                        pass
                    time.sleep(0.05)
                    continue

                if not done_b:
                    done_b = self.crane.move_bridge_to_target_p()
                if not done_t:
                    done_t = self.crane.move_trolley_to_target_p()

                if done_b and done_t:
                    # Hard stop both axes to avoid residual servo drive noise / hold motion
                    try:
                        self.crane.stop_bridge()
                    except Exception:
                        pass
                    try:
                        self.crane.stop_trolley()
                    except Exception:
                        pass
                    self.log.info("XY on target.")
                    self._driving = False
                    if not self._motion_transition_barrier(
                        f"after XY node {node_id}",
                        settle_s=CRANE_ACTION_SETTLE_S,
                    ):
                        self._set_runtime_error(
                            "CRANE_TRANSITION_BARRIER_FAILED",
                            f"Automatic/watchdog state did not recover after XY node {node_id}",
                        )
                        self._cancel.set()
                        self._publish_state()
                        return
                    self._publish_state()
                    break

                now = time.time()
                if now - start > MAX_XY_S:
                    self.log.error(
                        "XY move timeout after %.1fs — stopping motion.", now - start
                    )
                    try:
                        self.crane.stop_all()
                    except Exception:
                        pass

                    self._force_hold_pose()
                    self._driving = False
                    self._publish_state()
                    return

                if now - last_log > 0.5:
                    try:
                        cur_b = int(self.crane.get_bridge_position_absolute())
                        cur_t = int(self.crane.get_trolley_position_absolute())
                        self.log.debug(
                            "...moving XY: bridge=%d → %d mm, trolley=%d → %d mm",
                            cur_b,
                            bx_target,
                            cur_t,
                            ty_target,
                        )
                        if prev_b is not None and (
                            abs(cur_b - prev_b) > 1 or abs(cur_t - prev_t) > 1
                        ):
                            last_progress = now
                        prev_b, prev_t = cur_b, cur_t
                    except Exception:
                        pass
                    last_log = now

                if (now - last_progress > 6.0) and not (
                    self._paused or self._hold_mode
                ):
                    self.log.warning("No XY progress — still trying to reach targets.")
                    last_progress = now
                time.sleep(0.1)

            if self._stop_or_cancel.is_set():
                self.log.info(
                    "Order canceled/stopped before actions; aborting current order."
                )
                self._force_hold_pose()
                self._driving = False
                self._publish_state()

                return

            # --- 2) Reset per-node context (no zu/zd from nodePosition) ---
            # Hoist targets come ONLY from actions (lowerHoist / buttonPress / raiseHoist).
            self._node_ctx = {}

            # --- 3) Execute node actions ---
            actions = node.get("actions", [])
            self.log.info("Node actions: %d", len(actions))
            for a_idx, action in enumerate(actions):
                if not isinstance(action, dict) or "actionType" not in action:
                    self.log.error(
                        "Skipping malformed action on node %s: %r", node_id, action
                    )
                    continue
                if self._stop_or_cancel.is_set():
                    self.log.info("Stop/Cancel during actions; aborting current order.")
                    return

                self.log.info(
                    "-> Action %d/%d: %s",
                    a_idx + 1,
                    len(actions),
                    action.get("actionType"),
                )
                # announce action as WAITING before execution
                aid_wait = self._action_begin(
                    action,
                    default_type=action.get("actionType", ""),
                    description="Queued for execution",
                )
                self._action_update(aid_wait, status="WAITING")
                # ensure the same actionId is used inside _execute_action()
                action["actionId"] = aid_wait
                self._execute_action(action)

                # if cancel/stop happened in the last action, do not mark node complete
                if self._stop_or_cancel.is_set():
                    self.log.info(
                        "Stop/Cancel after actions; skipping node completion."
                    )
                    return

            # --- 4) Publish state after completing this node ---
            # update "last node reached" fields required by your schema
            self.last_node_id = node_id or ""
            self.last_node_seq = int(node.get("sequenceId", self.last_node_seq or 0))

            # Remove every released base item already traversed/reached. This keeps
            # state.nodeStates and state.edgeStates aligned with VDA order progress.
            self.node_states = [
                item
                for item in self.node_states
                if int(item.get("sequenceId", -1)) > self.last_node_seq
            ]
            self.edge_states = [
                item
                for item in self.edge_states
                if int(item.get("sequenceId", -1)) > self.last_node_seq
            ]

            self._publish_state()
            try:
                self.crane.stop_all()
                self._retarget_prevent_drifting()
            except Exception:
                pass
            self.log.info("Node %s complete.", node_id)

        self.log.info(
            "Order execution finished: orderId=%s updateId=%s", order_id, update_id
        )
        self.log.info("Waiting for next order OR instantAction ...")

    def _execute_instant_actions(self, ia_msg: Dict[str, Any]):
        # re-validation for safety; will no-op if schema not loaded
        try:
            if not self._validate("instantActions", ia_msg):
                self.log.error(
                    "instantActions failed validation at execute-time; dropping."
                )
                return
        except Exception:
            pass

        actions = ia_msg.get("actions", [])
        self.log.info("Executing %d instantAction(s) ...", len(actions))
        for action in actions:
            bt = (action.get("blockingType") or "NONE").upper()
            raw_at = action.get("actionType")
            at = _internal_action_type(raw_at)
            if raw_at != at:
                self.log.info(
                    "InstantAction alias: %s -> internal handler %s", raw_at, at
                )
            self.log.info("InstantAction: type=%s blockingType=%s", raw_at, bt)

            # VDA 5050 v3 instantActions are always blockingType=NONE. If an older
            # message gets this far, ignore HARD/SOFT pre-stop semantics and execute
            # the action handler explicitly.
            previous_scope = self._action_state_scope
            self._action_state_scope = "instant"
            try:
                if at == "factsheetRequest":
                    aid = self._action_begin(
                        action,
                        default_type="factsheetRequest",
                        description="Publish retained crane factsheet",
                    )
                    self._action_update(aid, status="RUNNING")
                    try:
                        self._publish_factsheet()
                    except Exception as exc:
                        self._action_finish(aid, ok=False, result=str(exc))
                    else:
                        self._action_finish(aid, ok=True, result="factsheet published")
                    continue

                if at == "release":
                    aid = self._action_begin(
                        action,
                        default_type=str(raw_at or "release"),
                        description="Release current buttonPress",
                    )
                    self._action_update(aid, status="RUNNING")
                    ctr = self._note_release()
                    self.log.info("InstantAction: release (ctr=%d).", ctr)
                    self._action_finish(aid, ok=True, result="release accepted")
                    continue

                # v3 keeps instant action lifecycles in instantActionStates. Some
                # project-specific handlers already create more detailed action states;
                # using the same actionId here lets those handlers replace/update this entry.
                aid = self._action_begin(
                    action,
                    default_type=str(raw_at or at),
                    description=f"Instant action {raw_at}",
                )
                self._action_update(aid, status="RUNNING")
                self._execute_action(action)
                final_status = next(
                    (
                        a.get("actionStatus")
                        for a in self.instant_action_states
                        if a.get("actionId") == aid
                    ),
                    None,
                )
                if final_status not in ("FINISHED", "FAILED", "RETRIABLE"):
                    self._action_finish(aid, ok=True, result="instant action accepted")
            finally:
                self._action_state_scope = previous_scope

    def _execute_action(self, action: Dict[str, Any]):
        """
        Supported actions:
        - lowerHoist: move to 'zd' (m). Source: actionParameters.zd ? fallback 445 mm.
        - buttonPress: block until UI reports pressed=true (optional 'timeout' param).
        - raiseHoist: raise to 'zu' (m). Source: actionParameters.zu ? default 3.071 m. (No button wait here.)
        - startPause / stopPause (v3 names; legacy pause/resume aliases also accepted)
        """

        raw_atype = action.get("actionType")
        atype = _internal_action_type(raw_atype)
        t0 = time.time()
        if raw_atype != atype:
            self.log.info("[action alias] %s -> %s", raw_atype, atype)
        self.log.info("[action start] %s", raw_atype)

        motion_actions = {
            "lowerHoist",
            "raiseHoist",
            "resetHoist",
            "resetBridgeTrolley",
            "resetAllHome",
            "resume",
        }
        if atype in motion_actions and not self._refresh_automatic_mode():
            aid = self._action_begin(
                action,
                default_type=str(raw_atype or atype),
                description="Motion blocked because crane automatic mode is unavailable",
            )
            self._action_finish(
                aid,
                ok=False,
                result="WatchDogFault=true or unreadable; motion refused",
            )
            self.log.error("Refused %s because WatchDogFault is true/unreadable", atype)
            return

        try:
            if atype == "lowerHoist":
                zd_m = self._get_action_param(action, "zd", None)
                if zd_m is None:
                    target_mm = 445  # fallback legacy value
                    self.log.warning(
                        "lowerHoist: no zd provided; using fallback %d mm", target_mm
                    )
                else:
                    try:
                        target_mm = int(float(zd_m) * 1000)
                    except (TypeError, ValueError):
                        self.log.warning(
                            "lowerHoist: invalid zd=%r; using fallback 445 mm", zd_m
                        )
                        target_mm = 445

                self._active_targets["hoist"] = target_mm
                self.crane.set_target_hoist(target_mm)
                aid = self._action_begin(
                    action,
                    default_type="lowerHoist",
                    description=f"Lowering hoist to {target_mm / 1000.0:.3f} m",
                )
                self._action_update(aid, status="RUNNING")

                # progress tracking
                try:
                    prev_pos = int(self.crane.get_hoist_position_absolute())
                except Exception:
                    prev_pos = None
                last_progress = time.time()
                last_pos_log = 0.0
                last_warn = 0.0
                MOVE_EPS_MM = 1
                NEAR_EPS_MM = 25

                while not self._stop_or_cancel.is_set():
                    self._drain_instant_actions_nonblocking()
                    if self._stop_or_cancel.is_set():
                        self.log.info("Order canceled; exiting Z loop immediately.")
                        try:
                            self.crane.stop_hoist()
                        except Exception:
                            pass
                        self._action_finish(aid, ok=False, result="canceled")
                        return

                    # resume nudge for hoist
                    if self._resume_nudge.is_set():
                        self._resume_nudge.clear()
                        try:
                            self.crane.stop_hoist()
                            hz = self._active_targets.get("hoist")
                            self.crane.set_target_hoist(
                                int(hz) if hz is not None else int(target_mm)
                            )
                            self.log.debug(
                                "resume-nudge: reasserted Z target (%s)",
                                hz if hz is not None else target_mm,
                            )
                        except Exception:
                            pass
                        time.sleep(0.1)

                    # paused → freeze at current pos
                    if self._paused:
                        try:
                            pos_now = int(self.crane.get_hoist_position_absolute())
                            self.crane.set_target_hoist(pos_now)
                            self.crane.stop_hoist()
                        except Exception:
                            pass
                        time.sleep(0.1)
                        continue

                    done = self.crane.move_hoist_to_target(fast=True)
                    if done:
                        break

                    now = time.time()
                    # sample/log progress ~2 Hz
                    if now - last_pos_log > 0.5:
                        try:
                            pos = int(self.crane.get_hoist_position_absolute())
                            if prev_pos is None or abs(pos - prev_pos) >= MOVE_EPS_MM:
                                last_progress = now
                            prev_pos = pos
                            rem = abs(target_mm - pos)
                            self.log.debug(
                                "... lowering: hoist=%d mm → %d mm (rem=%d mm)",
                                pos,
                                target_mm,
                                rem,
                            )
                            self._action_update(
                                aid,
                                result=f"Hoist height: {pos / 1000.0:.3f} m (rem={rem / 1000.0:.3f} m)",
                            )

                            if (
                                (now - last_warn > 6.0)
                                and (now - last_progress > 6.0)
                                and not (self._paused or self._hold_mode)
                                and (rem > NEAR_EPS_MM)
                            ):
                                self.log.warning(
                                    "No Z progress — still trying to reach target."
                                )
                                last_warn = now
                        except Exception:
                            pass
                        last_pos_log = now

                    time.sleep(0.1)

                self.log.info("lowerHoist reached target=%d mm", target_mm)
                try:
                    self.crane.stop_hoist()
                except Exception:
                    pass
                settled = self._motion_transition_barrier(
                    f"after lowerHoist {target_mm} mm",
                    settle_s=CRANE_ACTION_SETTLE_S,
                )
                self._action_finish(
                    aid,
                    ok=settled,
                    result=(
                        f"Reached {target_mm / 1000.0:.3f} m and settled"
                        if settled
                        else "Target reached but automatic/watchdog recovery failed"
                    ),
                )
                if not settled:
                    self._cancel.set()
                return

            elif atype == "buttonPress":
                # Per-action timeout (seconds). If provided, set in actionParameters.timeout on this action.
                timeout = self._get_action_param(action, "timeout", None)
                try:
                    to = float(timeout) if timeout is not None else None
                except (TypeError, ValueError):
                    to = None
                aid = self._action_begin(
                    action,
                    default_type="buttonPress",
                    description=f"Waiting for '{BUTTON_NAME_RELEASE}'",
                )
                self._action_update(aid, status="RUNNING")

                btn = BUTTON_NAME_RELEASE
                self.log.info(
                    "buttonPress: waiting for '%s' instantAction OR POST from %s (timeout=%s) ...",
                    btn,
                    BUTTON_STATUS_URL,
                    to,
                )

                # Local extractor mirrors wait_for_panel_button() logic
                def _extract(data: dict, button: str) -> Tuple[bool, int]:
                    if "seq" in data and "pressed" in data:
                        try:
                            return bool(data["pressed"]), int(data["seq"])
                        except Exception:
                            return False, 0
                    if (
                        data.get("btn") == button
                        and "seq" in data
                        and "pressed" in data
                    ):
                        try:
                            return bool(data["pressed"]), int(data["seq"])
                        except Exception:
                            return False, 0
                    sub = data.get(button)
                    if isinstance(sub, dict) and "seq" in sub and "pressed" in sub:
                        try:
                            return bool(sub["pressed"]), int(sub["seq"])
                        except Exception:
                            return False, 0
                    return False, 0

                # Establish baseline sequence once (so only newer presses count)
                try:
                    r0 = requests.get(
                        BUTTON_STATUS_URL, params={"btn": btn}, timeout=1.5
                    )
                    data0 = r0.json() if r0.ok else {}
                    _, baseline = _extract(data0, btn)
                except Exception:
                    baseline = 0

                with self._release_lock:
                    baseline_release = self._release_ctr

                t0 = time.time()
                last_heartbeat = -1e9  # log an immediate heartbeat on entry
                while not self._stop_or_cancel.is_set():
                    # Allow cancelOrder / pause / resume / release IA to preempt the wait
                    self._drain_instant_actions_nonblocking()
                    if self._stop_or_cancel.is_set():
                        self.log.info(
                            "buttonPress: canceled/stopped; exiting wait immediately."
                        )
                        self._action_finish(aid, ok=False, result="canceled")
                        return

                    # release instantAction satisfies buttonPress
                    with self._release_lock:
                        if self._release_ctr > baseline_release:
                            self.log.info(
                                "buttonPress: saw release instantAction (ctr=%d > %d).",
                                self._release_ctr,
                                baseline_release,
                            )
                            self._action_finish(
                                aid, ok=True, result="release instantAction received"
                            )
                            return

                    try:
                        r = requests.get(
                            BUTTON_STATUS_URL, params={"btn": btn}, timeout=1.5
                        )
                        if r.ok:
                            data = r.json()
                            pressed, seq = _extract(data, btn)
                            if pressed and seq > baseline:
                                # Consume this press (prefer per-button; fallback to consume-all)
                                consumed = False
                                try:
                                    rc = requests.get(
                                        BUTTON_STATUS_URL,
                                        params={"btn": btn, "consume": 1},
                                        timeout=1.5,
                                    )
                                    if rc.ok:
                                        consumed = True
                                except Exception:
                                    pass
                                if not consumed:
                                    try:
                                        requests.get(
                                            BUTTON_STATUS_URL,
                                            params={"consume": 1},
                                            timeout=1.5,
                                        )
                                    except Exception:
                                        pass
                                self.log.info(
                                    "buttonPress: detected press (seq=%d > baseline=%d).",
                                    seq,
                                    baseline,
                                )
                                self._action_finish(
                                    aid, ok=True, result="panel button pressed"
                                )
                                return
                    except requests.RequestException as e:
                        self.log.debug("buttonPress: poll error: %s", e)

                    if to is not None and (time.time() - t0) >= to:
                        self.log.info("buttonPress: wait ended (timeout).")
                        self._action_finish(aid, ok=False, result="timeout")
                        return

                    now = time.time()
                    if now - last_heartbeat > 2.0:
                        self.log.info(
                            "buttonPress: ...still waiting (%.1fs elapsed)", now - t0
                        )
                        last_heartbeat = now
                    time.sleep(0.2)

                self.log.info("buttonPress: wait aborted by stop/cancel signal.")
                return

            elif atype == "raiseHoist":
                zu_m = self._get_action_param(action, "zu", 3.071)
                try:
                    target_mm = int(float(zu_m) * 1000)
                except (TypeError, ValueError):
                    self.log.warning("raiseHoist: invalid zu=%r; using 3071 mm", zu_m)
                    target_mm = 3071

                self._active_targets["hoist"] = target_mm
                self.crane.stop_hoist()  # clear any latched direction/speed
                self.crane.set_target_hoist(target_mm)
                self.log.info(
                    "raiseHoist: raising to zu=%.3f m (%d mm)",
                    float(zu_m) if zu_m is not None else 3.071,
                    target_mm,
                )

                aid = self._action_begin(
                    action,
                    default_type="raiseHoist",
                    description=f"Raising hoist to {target_mm / 1000.0:.3f} m",
                )
                self._action_update(aid, status="RUNNING")

                # progress tracking
                try:
                    prev_pos = int(self.crane.get_hoist_position_absolute())
                except Exception:
                    prev_pos = None
                last_progress = time.time()
                last_pos_log = 0.0
                last_warn = 0.0
                MOVE_EPS_MM = 1
                NEAR_EPS_MM = 25

                while not self._stop_or_cancel.is_set():
                    self._drain_instant_actions_nonblocking()
                    if self._stop_or_cancel.is_set():
                        self.log.info("Order canceled; exiting Z loop immediately.")
                        try:
                            self.crane.stop_hoist()
                        except Exception:
                            pass
                        self._action_finish(aid, ok=False, result="canceled")
                        return

                    # resume nudge for hoist
                    if self._resume_nudge.is_set():
                        self._resume_nudge.clear()
                        try:
                            self.crane.stop_hoist()
                            hz = self._active_targets.get("hoist")
                            self.crane.set_target_hoist(
                                int(hz) if hz is not None else int(target_mm)
                            )
                            self.log.debug(
                                "resume-nudge: reasserted Z target (%s)",
                                hz if hz is not None else target_mm,
                            )
                        except Exception:
                            pass
                        time.sleep(0.1)

                    # paused → freeze at current pos
                    if self._paused:
                        try:
                            pos_now = int(self.crane.get_hoist_position_absolute())
                            self.crane.set_target_hoist(pos_now)
                            self.crane.stop_hoist()
                        except Exception:
                            pass
                        time.sleep(0.1)
                        continue

                    done = self.crane.move_hoist_to_target(fast=True)
                    if done:
                        self.log.info("raiseHoist reached target=%d mm", target_mm)
                        try:
                            self.crane.stop_hoist()
                        except Exception:
                            pass
                        settled = self._motion_transition_barrier(
                            f"after raiseHoist {target_mm} mm",
                            settle_s=CRANE_ACTION_SETTLE_S,
                        )
                        self._action_finish(
                            aid,
                            ok=settled,
                            result=(
                                f"Reached {target_mm / 1000.0:.3f} m and settled"
                                if settled
                                else "Target reached but automatic/watchdog recovery failed"
                            ),
                        )
                        if not settled:
                            self._cancel.set()
                        break

                    now = time.time()
                    # sample/log progress ~2 Hz
                    if now - last_pos_log > 0.5:
                        try:
                            pos = int(self.crane.get_hoist_position_absolute())
                            if prev_pos is None or abs(pos - prev_pos) >= MOVE_EPS_MM:
                                last_progress = now
                            prev_pos = pos
                            rem = abs(target_mm - pos)
                            self.log.debug(
                                "... raising: hoist=%d mm → %d mm (rem=%d mm)",
                                pos,
                                target_mm,
                                rem,
                            )
                            self._action_update(
                                aid,
                                result=f"Hoist height: {pos / 1000.0:.3f} m (rem={rem / 1000.0:.3f} m)",
                            )

                            if (
                                (now - last_warn > 6.0)
                                and (now - last_progress > 6.0)
                                and not (self._paused or self._hold_mode)
                                and (rem > NEAR_EPS_MM)
                            ):
                                self.log.warning(
                                    "No Z progress — still trying to reach target."
                                )
                                last_warn = now
                        except Exception:
                            pass
                        last_pos_log = now

                    time.sleep(0.1)
                return

            elif atype == "pause":
                if self._paused:
                    self.log.info("pause: already paused.")
                    return
                # Try smooth ramp to zero using global speed scale if available
                scale_now = self._try_get_speed_scale()
                if scale_now is not None and self._try_set_speed_scale(scale_now):
                    self._speed_scale_backup = scale_now if scale_now > 0 else 1.0
                    self._hold_mode = False
                    self.log.info(
                        "pause: ramping speed scale %.3f → 0.0",
                        self._speed_scale_backup,
                    )
                    self._ramp_speed_scale(
                        self._speed_scale_backup, 0.0, duration_s=1.5, steps=15
                    )

                    # hard halt after ramp -- does NOT change targets
                    try:
                        self.crane.stop_all()
                    except Exception:
                        pass

                else:
                    # Fallback: hold-mode (no STOP), loops will retarget to current pose while paused
                    self._hold_mode = True
                    self.log.info(
                        "pause: entering hold-mode (no speed scale API detected)."
                    )

                self._actions_mark_paused()
                self._paused = True
                return

            elif atype == "resume":
                if not self._paused:
                    self.log.info("resume: not paused; nothing to do.")
                    return

                if not self._hold_mode:
                    # Smoothly restore saved scale
                    start = 0.0
                    end = (
                        self._speed_scale_backup
                        if (self._speed_scale_backup and self._speed_scale_backup > 0)
                        else 1.0
                    )
                    self.log.info("resume: ramping speed scale %.3f → %.3f", start, end)
                    self._ramp_speed_scale(start, end, duration_s=1.5, steps=15)
                    self._speed_scale_backup = None
                else:
                    # In hold-mode, loops will see _paused=False and re-use self._active_targets to continue
                    self.log.info(
                        "resume: leaving hold-mode; loops will continue toward active targets."
                    )
                    self._hold_mode = False

                # Re-apply last targets so bridge/trolley "wake up"
                try:
                    bx = self._active_targets.get("bridge")
                    ty = self._active_targets.get("trolley")
                    hz = self._active_targets.get("hoist")
                    if bx is not None:
                        self.crane.set_target_bridge(int(bx))
                    if ty is not None:
                        self.crane.set_target_trolley(int(ty))
                    if hz is not None:
                        self.crane.set_target_hoist(int(hz))
                    self.log.debug(
                        "resume: re-applied targets (bridge=%s, trolley=%s, hoist=%s).",
                        bx,
                        ty,
                        hz,
                    )
                except Exception as e:
                    self.log.debug(
                        "resume: re-applying targets failed (non-fatal): %s", e
                    )

                self._actions_mark_running()
                self._paused = False
                self._resume_nudge.set()
                return

            elif atype == "cancelOrder":
                # Set cancel flag so all loops (XY/Z/button wait) break quickly
                self._cancel.set()
                self.log.warning(
                    "cancelOrder: cancel flag set. Stopping motion and aborting current order."
                )
                try:
                    self.crane.stop_all()
                except Exception:
                    pass

                # force axes to hold current pose so XY doesn't keep chasing old setpoints
                self._force_hold_pose()
                if self._paused and not self._hold_mode:
                    end_scale = (
                        self._speed_scale_backup
                        if (self._speed_scale_backup and self._speed_scale_backup > 0)
                        else 1.0
                    )
                    self._try_set_speed_scale(float(end_scale))
                self._paused = False
                self._hold_mode = False

                # Drop any queued *future* orders so we don't start another by mistake
                dropped = 0
                while True:
                    try:
                        self._order_queue.get_nowait()
                        dropped += 1
                    except queue.Empty:
                        break
                if dropped:
                    self.log.info("cancelOrder: cleared %d queued order(s).", dropped)

                # clear any queued instant actions except pause/resume/cancelOrder (keeps UI responsive)
                tmp = []
                cleared = 0
                while True:
                    try:
                        ia = self._ia_queue.get_nowait()
                    except queue.Empty:
                        break
                    try:
                        t = ia.get("actions", [{}])[0].get("actionType", "")
                    except Exception:
                        t = ""
                    if _internal_action_type(t) in ("pause", "resume", "cancelOrder"):
                        tmp.append(ia)
                    else:
                        cleared += 1
                # requeue the kept items on the same queue to avoid races
                for ia in tmp:
                    self._ia_queue.put(ia)
                if cleared:
                    self.log.info(
                        "cancelOrder: dropped %d pending instant action(s).", cleared
                    )

                return

            elif atype == "resetHoist":
                if self._order_active or self._driving:
                    aid = str(action.get("actionId"))
                    self._action_finish(
                        aid,
                        ok=False,
                        result="An order is active; cancel it and wait for idle before homing",
                    )
                    return
                self._cancel.clear()
                was_paused = self._paused
                changed = self._temporarily_enable_motion_for_reset()
                self._active_targets["hoist"] = HOME_HOIST_MM
                self.log.info("resetHoist: homing hoist to %d mm ...", HOME_HOIST_MM)
                self._instant_motion_active = True
                try:
                    ok = _move_hoist_to(
                        self.crane,
                        self.log,
                        HOME_HOIST_MM,
                        timeout_s=300.0,
                        stop_event=self._stop_or_cancel,
                        abort_check=lambda: not self._refresh_automatic_mode(),
                    )
                finally:
                    self._instant_motion_active = False
                    try:
                        self.crane.stop_hoist()
                    except Exception:
                        pass
                    self._restore_motion_after_reset_if_needed(changed, was_paused)
                if ok:
                    ok = self._motion_transition_barrier(
                        "after resetHoist",
                        settle_s=CRANE_ACTION_SETTLE_S,
                    )
                self._action_finish(
                    str(action.get("actionId")),
                    ok=ok,
                    result=(
                        "Hoist home reached and settled"
                        if ok
                        else "Hoist homing or transition settling failed"
                    ),
                )
                self.log.info("resetHoist: %s.", "done" if ok else "failed")
                return

            elif atype == "resetBridgeTrolley":
                if self._order_active or self._driving:
                    aid = str(action.get("actionId"))
                    self._action_finish(
                        aid,
                        ok=False,
                        result="An order is active; cancel it and wait for idle before homing",
                    )
                    return
                self._cancel.clear()
                was_paused = self._paused
                changed = self._temporarily_enable_motion_for_reset()
                self._active_targets["bridge"] = HOME_BRIDGE_MM
                self._active_targets["trolley"] = HOME_TROLLEY_MM
                self.log.info(
                    "resetBridgeTrolley: homing XY to bridge=%d, trolley=%d ...",
                    HOME_BRIDGE_MM,
                    HOME_TROLLEY_MM,
                )
                self._instant_motion_active = True
                try:
                    ok = _move_xy_to(
                        self.crane,
                        self.log,
                        HOME_BRIDGE_MM,
                        HOME_TROLLEY_MM,
                        timeout_s=300.0,
                        stop_event=self._stop_or_cancel,
                        abort_check=lambda: not self._refresh_automatic_mode(),
                    )
                finally:
                    self._instant_motion_active = False
                    try:
                        self.crane.stop_bridge()
                    except Exception:
                        pass
                    try:
                        self.crane.stop_trolley()
                    except Exception:
                        pass
                    self._restore_motion_after_reset_if_needed(changed, was_paused)
                if ok:
                    ok = self._motion_transition_barrier(
                        "after resetBridgeTrolley",
                        settle_s=CRANE_ACTION_SETTLE_S,
                    )
                self._action_finish(
                    str(action.get("actionId")),
                    ok=ok,
                    result=(
                        "Bridge/trolley home reached and settled"
                        if ok
                        else "XY homing or transition settling failed"
                    ),
                )
                self.log.info("resetBridgeTrolley: %s.", "done" if ok else "failed")
                return

            elif atype == "resetAllHome":
                if self._order_active or self._driving:
                    aid = str(action.get("actionId"))
                    self._action_finish(
                        aid,
                        ok=False,
                        result="An order is active; cancel it and wait for idle before homing",
                    )
                    return
                self._cancel.clear()
                was_paused = self._paused
                changed = self._temporarily_enable_motion_for_reset()
                self._active_targets.update(
                    {
                        "hoist": HOME_HOIST_MM,
                        "bridge": HOME_BRIDGE_MM,
                        "trolley": HOME_TROLLEY_MM,
                    }
                )
                self.log.info("resetAllHome: homing Z then XY ...")
                self._instant_motion_active = True
                try:
                    ok_z = _move_hoist_to(
                        self.crane,
                        self.log,
                        HOME_HOIST_MM,
                        timeout_s=300.0,
                        stop_event=self._stop_or_cancel,
                        abort_check=lambda: not self._refresh_automatic_mode(),
                    )
                    if ok_z and self._motion_transition_barrier(
                        "resetAllHome Z-to-XY transition",
                        settle_s=CRANE_ACTION_SETTLE_S,
                    ):
                        ok_xy = _move_xy_to(
                            self.crane,
                            self.log,
                            HOME_BRIDGE_MM,
                            HOME_TROLLEY_MM,
                            timeout_s=300.0,
                            stop_event=self._stop_or_cancel,
                            abort_check=lambda: not self._refresh_automatic_mode(),
                        )
                    else:
                        ok_xy = False
                        self.log.error(
                            "resetAllHome: skipping XY because hoist homing or the Z-to-XY transition barrier failed"
                        )
                finally:
                    self._instant_motion_active = False
                    try:
                        self.crane.stop_all()
                    except Exception:
                        pass
                    self._restore_motion_after_reset_if_needed(changed, was_paused)
                ok = ok_z and ok_xy
                if ok:
                    ok = self._motion_transition_barrier(
                        "after resetAllHome",
                        settle_s=CRANE_ACTION_SETTLE_S,
                    )
                self._action_finish(
                    str(action.get("actionId")),
                    ok=ok,
                    result=("All home positions reached" if ok else "Home-all aborted, failed, or timed out"),
                )
                self.log.info("resetAllHome: %s.", "done" if ok else "failed")
                return

        except Exception as exc:
            self.log.error("Exception in action %s:\n%s", atype, traceback.format_exc())
            action_id = str(action.get("actionId") or "")
            if action_id:
                self._action_finish(action_id, ok=False, result=str(exc))
        finally:
            self.log.info("[action end] %s (%.2fs)", atype, time.time() - t0)

    def _set_runtime_error(self, error_type: str, description: str) -> None:
        self.errors = [item for item in self.errors if item.get("errorType") != error_type]
        refs = []
        if self.current_order_id:
            refs.append({"referenceKey": "orderId", "referenceValue": self.current_order_id})
        self.errors.append({
            "errorType": error_type,
            "errorLevel": "WARNING",
            "errorDescription": description,
            "errorReferences": refs,
        })

    def _clear_runtime_error(self, error_type: str) -> None:
        self.errors = [item for item in self.errors if item.get("errorType") != error_type]

    def _update_motion_diagnostics(self, bridge_mm: int, trolley_mm: int, hoist_mm: int) -> Dict[str, Any]:
        now = time.monotonic()
        active_actions = [
            item for item in (self.action_states + self.instant_action_states)
            if item.get("actionStatus") in {"INITIALIZING", "WAITING", "RUNNING", "PAUSED"}
        ]
        active_action = active_actions[0] if active_actions else {}
        moving = bool(self._driving or self._instant_motion_active) or (
            active_action.get("actionType") in {
                "lowerHoist", "raiseHoist", "resetHoist", "resetBridgeTrolley", "resetAllHome"
            } and active_action.get("actionStatus") == "RUNNING"
        )
        positions = (bridge_mm, trolley_mm, hoist_mm)
        with self._motion_diag_lock:
            if moving and self._motion_started_monotonic is None:
                self._motion_started_monotonic = now
                self._motion_last_progress_monotonic = now
                self._motion_stall_latched = False
                self._motion_last_error = ""
            if moving and self._motion_last_positions is not None and any(
                abs(a - b) >= 1 for a, b in zip(positions, self._motion_last_positions)
            ):
                self._motion_last_progress_monotonic = now
                self._motion_stall_latched = False
            self._motion_last_positions = positions
            if not moving:
                self._motion_started_monotonic = None
                self._motion_last_progress_monotonic = now
                self._motion_stall_latched = False
            progress_age = 0.0 if self._motion_last_progress_monotonic is None else max(0.0, now - self._motion_last_progress_monotonic)
            elapsed = 0.0 if self._motion_started_monotonic is None else max(0.0, now - self._motion_started_monotonic)
            stalled = bool(moving and not self._paused and not self._hold_mode and progress_age >= CRANE_MOTION_STALL_WARN_S)
            if (
                moving and not self._paused and not self._hold_mode
                and progress_age >= CRANE_MOTION_STALL_FAIL_S
                and not self._motion_stall_latched
            ):
                self._motion_stall_latched = True
                self._motion_last_error = (
                    f"No crane position progress for {progress_age:.1f}s during "
                    f"{active_action.get('actionType') or ('XY movement' if self._driving else 'motion')}"
                )
                self.log.error(self._motion_last_error)
                self._set_runtime_error("CRANE_MOTION_STALLED", self._motion_last_error)
                self._cancel.set()
                try:
                    self.crane.stop_all()
                except Exception as exc:
                    self.log.warning("STOP after motion stall failed: %s", exc)
            elif not stalled:
                self._clear_runtime_error("CRANE_MOTION_STALLED")
            return {
                "status": "STALLED" if stalled else ("MOVING" if moving else "IDLE"),
                "phase": active_action.get("actionType") or ("XY_MOVE" if self._driving else "IDLE"),
                "action_id": active_action.get("actionId", ""),
                "action_status": active_action.get("actionStatus", ""),
                "elapsed_s": elapsed,
                "last_progress_age_s": progress_age,
                "stall_warn_s": CRANE_MOTION_STALL_WARN_S,
                "stall_fail_s": CRANE_MOTION_STALL_FAIL_S,
                "targets": dict(self._active_targets),
                "positions_mm": {"bridge": bridge_mm, "trolley": trolley_mm, "hoist": hoist_mm},
                "last_error": self._motion_last_error,
            }

    # ───────────────────────────── message builders ──────────────────────────

    def _connection_msg(self, state: str) -> Dict[str, Any]:
        return {
            "headerId": self.header.next("connection"),
            "timestamp": utc_ts(),
            "version": PROTOCOL_VERSION,
            "manufacturer": MANUFACTURER,
            "serialNumber": SERIAL_NUMBER,
            "connectionState": state,
        }

    def _publish_factsheet(self) -> None:
        path = CRANE_FACTSHEET_FILE
        if not path.is_absolute():
            path = REPO_ROOT / path
        with path.open("r", encoding="utf-8") as handle:
            payload = json.load(handle)
        payload.update(
            {
                "headerId": self.header.next("factsheet"),
                "timestamp": utc_ts(),
                "version": PROTOCOL_VERSION,
                "manufacturer": MANUFACTURER,
                "serialNumber": SERIAL_NUMBER,
            }
        )
        if not self._validate("factsheet", payload):
            raise ValueError(f"Invalid crane factsheet: {path}")
        self.mqtt.publish(
            f"{TOPIC_ROOT}/factsheet", json.dumps(payload), qos=0, retain=True
        )
        self.log.info("Published retained factsheet from %s", path)

    def _publish_state(self):
        try:
            # positions (mm)
            bridge_mm = int(self.crane.get_bridge_position_absolute())
            trolley_mm = int(self.crane.get_trolley_position_absolute())

            # --- hoist telemetry into information[] with required infoLevel ---
            motion_diag: Dict[str, Any] = {
                "status": "UNKNOWN", "phase": "UNKNOWN", "last_error": "hoist telemetry unavailable"
            }
            try:
                hoist_mm = int(self.crane.get_hoist_position_absolute())
                hoist_m = hoist_mm / 1000.0
                motion_diag = self._update_motion_diagnostics(bridge_mm, trolley_mm, hoist_mm)
                info_item = {
                    "infoType": "HOIST_POSITION",
                    "infoLevel": "INFO",
                    # v3 canonical field is infoDescriptor. Keep infoDescription too so
                    # master_control_panel_v3.py can still parse the crane hoist height.
                    "infoDescriptor": f"Hoist height: {hoist_m:.3f} m",
                    "infoDescription": f"Hoist height: {hoist_m:.3f} m",
                    "infoReferences": [
                        {"referenceKey": "deviceId", "referenceValue": "HOIST_1"},
                        {"referenceKey": "unit", "referenceValue": "m"},
                    ],
                }
                # keep only the latest HOIST_POSITION entry
                self.information_messages = [
                    i
                    for i in self.information_messages
                    if i.get("infoType") != "HOIST_POSITION"
                ]
                self.information_messages.append(info_item)
            except Exception:
                # hoist read failed → just leave information_messages as-is
                pass
            # ---------------------------------------------------------------------------

            watchdog_item = {
                "infoType": "WATCHDOG_FAULT",
                "infoLevel": "INFO",
                "infoDescriptor": (
                    "WatchDogFault=true; crane is not in automatic mode"
                    if self.watchdog_fault
                    else "WatchDogFault=false; crane automatic mode active"
                ),
                "infoDescription": (
                    "WatchDogFault=true; crane is not in automatic mode"
                    if self.watchdog_fault
                    else "WatchDogFault=false; crane automatic mode active"
                ),
                "infoReferences": [
                    {
                        "referenceKey": "opcUaNode",
                        "referenceValue": "DX_Custom_V.Status.WatchDogFault",
                    },
                    {
                        "referenceKey": "value",
                        "referenceValue": str(self.watchdog_fault).lower(),
                    },
                ],
            }
            self.information_messages = [
                item
                for item in self.information_messages
                if item.get("infoType") != "WATCHDOG_FAULT"
            ]
            self.information_messages.append(watchdog_item)

            watchdog_health = self.watchdog_health.snapshot()
            watchdog_health_item = {
                "infoType": "WATCHDOG_HEALTH",
                "infoLevel": "INFO",
                "infoDescriptor": (
                    f"Watchdog {watchdog_health['status']}: "
                    f"last success age={watchdog_health['last_success_age_s'] if watchdog_health['last_success_age_s'] is not None else -1:.3f}s, "
                    f"failures={watchdog_health['consecutive_failures']}"
                ),
                "infoDescription": (
                    f"Deadline-scheduled OPC UA watchdog health is {watchdog_health['status']}"
                ),
                "infoReferences": [
                    {"referenceKey": key, "referenceValue": str(value)}
                    for key, value in watchdog_health.items()
                ],
            }
            motion_health_item = {
                "infoType": "CRANE_MOTION_HEALTH",
                "infoLevel": "INFO",
                "infoDescriptor": (
                    f"Motion {motion_diag.get('status')}: {motion_diag.get('phase')} "
                    f"progress age={float(motion_diag.get('last_progress_age_s', 0.0)):.1f}s"
                ),
                "infoDescription": str(motion_diag.get("last_error") or "Crane motion telemetry"),
                "infoReferences": [
                    {"referenceKey": "status", "referenceValue": str(motion_diag.get("status", "UNKNOWN"))},
                    {"referenceKey": "phase", "referenceValue": str(motion_diag.get("phase", "UNKNOWN"))},
                    {"referenceKey": "actionId", "referenceValue": str(motion_diag.get("action_id", ""))},
                    {"referenceKey": "actionStatus", "referenceValue": str(motion_diag.get("action_status", ""))},
                    {"referenceKey": "elapsed_s", "referenceValue": f"{float(motion_diag.get('elapsed_s', 0.0)):.3f}"},
                    {"referenceKey": "last_progress_age_s", "referenceValue": f"{float(motion_diag.get('last_progress_age_s', 0.0)):.3f}"},
                    {"referenceKey": "targets", "referenceValue": json.dumps(motion_diag.get("targets", {}), sort_keys=True)},
                    {"referenceKey": "positions_mm", "referenceValue": json.dumps(motion_diag.get("positions_mm", {}), sort_keys=True)},
                    {"referenceKey": "last_error", "referenceValue": str(motion_diag.get("last_error", ""))},
                ],
            }
            self.information_messages = [
                item for item in self.information_messages
                if item.get("infoType") not in {"WATCHDOG_HEALTH", "CRANE_MOTION_HEALTH"}
            ]
            self.information_messages.extend([watchdog_health_item, motion_health_item])
            state_header_id = self.header.next("state")
            self._last_state_header_id = state_header_id

            mobile_robot_position = {
                "x": bridge_mm / 1000.0,
                "y": trolley_mm / 1000.0,
                "theta": 0.0,
                "mapId": DEFAULT_MAP_ID,
                "localized": True,
            }

            payload = {
                "headerId": state_header_id,
                "timestamp": utc_ts(),
                "version": PROTOCOL_VERSION,
                "manufacturer": MANUFACTURER,
                "serialNumber": SERIAL_NUMBER,
                # --- VDA 5050 v3.0 state.schema required fields ---
                "orderId": self.current_order_id,
                "orderUpdateId": self.current_order_update_id,
                "lastNodeId": self.last_node_id,
                "lastNodeSequenceId": self.last_node_seq,
                "nodeStates": self.node_states,
                "edgeStates": self.edge_states,
                "driving": self._driving,
                "actionStates": self.action_states,
                "instantActionStates": self.instant_action_states,
                "powerSupply": self.power_supply,
                "operatingMode": self.operating_mode,
                "errors": self.errors,
                "safetyState": self.safety_state,
                # --- useful optional v3 fields ---
                "mobileRobotPosition": mobile_robot_position,
                "velocity": {"vx": 0.0, "vy": 0.0, "omega": 0.0},
                "paused": self._paused,
                "information": self.information_messages,
            }

            # validate before publish
            try:
                if not self._validate("state", payload):
                    self.log.warning(
                        "State payload failed schema validation (continuing)."
                    )
            except Exception:
                pass

            payload_s = json.dumps(payload)
            self.mqtt.publish(f"{TOPIC_ROOT}/state", payload_s, qos=0, retain=False)
            self.log.debug("Published state (bytes=%d)", len(payload_s))
        except Exception:
            self.log.exception("Failed publishing state.")

    def _publish_visualization(self):
        try:
            bridge_mm = self.crane.get_bridge_position_absolute()
            trolley_mm = self.crane.get_trolley_position_absolute()
            mobile_robot_position = {
                "x": bridge_mm / 1000.0,
                "y": trolley_mm / 1000.0,
                "theta": 0.0,
                "mapId": DEFAULT_MAP_ID,
                "localized": True,
            }
            payload = {
                "headerId": self.header.next("visualization"),
                "timestamp": utc_ts(),
                "version": PROTOCOL_VERSION,
                "manufacturer": MANUFACTURER,
                "serialNumber": SERIAL_NUMBER,
                "referenceStateHeaderId": self._last_state_header_id,
                "mobileRobotPosition": mobile_robot_position,
                "velocity": {"vx": 0.0, "vy": 0.0, "omega": 0.0},
            }
            # validate before publish
            try:
                if not self._validate("visualization", payload):
                    self.log.warning(
                        "Visualization payload failed schema validation (continuing)."
                    )
            except Exception:
                # if visualization schema isn't loaded for some reason, just continue
                pass

            payload_s = json.dumps(payload)
            self.mqtt.publish(
                f"{TOPIC_ROOT}/visualization", payload_s, qos=0, retain=False
            )
            self.log.debug("Published visualization (bytes=%d)", len(payload_s))
        except Exception:
            self.log.exception("Failed publishing visualization.")

    # ───────────────────────────── validation ────────────────────────────────

    def _validate(self, schema_key: str, msg: Dict[str, Any]) -> bool:
        try:
            jsonschema.validate(msg, self.schemas[schema_key])
            self.log.debug("Validation OK for %s", schema_key)
            return True
        except jsonschema.ValidationError as e:
            self.log.error("Validation error for %s: %s", schema_key, e.message)
            return False
        except Exception as e:
            self.log.error("Validation exception for %s: %s", schema_key, e)
            return False


# ───────────────────────────────────────────────────────────── CLI entry ──


def _load_crane_credentials() -> Tuple[str, int]:
    url_env = os.getenv("CRANE_OPCUA_URL", "").strip()
    access_env = os.getenv("CRANE_ACCESS_CODE", "").strip()
    if url_env and access_env:
        return url_env, int(access_env)
    if url_env or access_env:
        raise ValueError("Set both CRANE_OPCUA_URL and CRANE_ACCESS_CODE, or neither")

    path = CRANE_ACCESS_FILE
    if not path.is_absolute():
        path = REPO_ROOT / path
    if not path.exists():
        raise FileNotFoundError(
            f"Crane credentials not found at {path}. Copy access.txt.example to "
            "access.txt outside Git, or set CRANE_OPCUA_URL and CRANE_ACCESS_CODE."
        )
    lines = [line.strip() for line in path.read_text(encoding="utf-8").splitlines()]
    if len(lines) < 2 or not lines[0] or not lines[1]:
        raise ValueError(f"Expected OPC UA URL and numeric access code in {path}")
    return lines[0], int(lines[1])


def main():
    log = configure_logging()
    log.info("Starting VDA5050 adapter for crane.")
    log.info(
        "Config: broker=%s:%s, protocol=%s, manufacturer=%s, serial=%s, topic_root=%s, release_button_url=%s",
        BROKER_HOST,
        BROKER_PORT,
        PROTOCOL_VERSION,
        MANUFACTURER,
        SERIAL_NUMBER,
        TOPIC_ROOT,
        BUTTON_STATUS_URL,
    )

    # Read credentials from environment or a local ignored file.
    url, access = _load_crane_credentials()

    crane = Crane(url)
    crane.set_accesscode(access)
    crane.stop_all()  # ensure safe state at boot
    log.info("Crane connected to %s, accesscode set.", url)

    # --- Start GLOBAL watchdog BEFORE any waits/homing ---
    watchdog_stop = threading.Event()
    watchdog_health = WatchdogHealth()
    watchdog_thread = threading.Thread(
        target=_watchdog_loop,
        args=(crane, watchdog_stop, log, watchdog_health),
        daemon=True,
        name="watchdog",
    )
    watchdog_thread.start()

    # Global shutdown event so waits can exit on Ctrl-C
    shutdown_evt = threading.Event()

    # Late-bound adapter reference for the signal handler
    adapter_ref = {"obj": None}

    # One signal handler that works both before and after adapter exists
    def _sigterm(_sig, _frm):
        # prevent reentry if user presses Ctrl-C multiple times
        try:
            signal.signal(signal.SIGINT, signal.SIG_IGN)
            signal.signal(signal.SIGTERM, signal.SIG_IGN)
        except Exception:
            pass

        log.info("Signal received: shutting down.")
        shutdown_evt.set()  # abort any waits (e.g., AUTOMATIC)

        # 1) STOP crane first
        try:
            crane.stop_all()
            log.info("Emergency STOP sent to crane.")
        except Exception as e:
            log.warning("Emergency STOP failed (continuing): %s", e)

        # 2) Stop adapter if started
        try:
            if adapter_ref["obj"] is not None:
                adapter_ref["obj"].stop()
        except Exception:
            log.exception("Adapter stop failed (continuing).")

        # 3) Stop watchdog, disconnect, exit
        try:
            watchdog_stop.set()
            if watchdog_thread.is_alive():
                watchdog_thread.join(timeout=2.0)
        finally:
            try:
                crane.disconnect()
            finally:
                raise SystemExit(0)

    # Register handlers BEFORE any blocking waits
    signal.signal(signal.SIGINT, _sigterm)
    signal.signal(signal.SIGTERM, _sigterm)

    # --- Preflight ---
    try:
        crane.stop_all()  # belt-and-suspenders STOP to OPC UA
        log.info("Preflight: STOP written to OPC UA.")
    except Exception as e:
        log.warning("Preflight STOP failed (continuing): %s", e)

    # Wait for the real PLC automatic-mode indication. No Flask button is
    # required: WatchDogFault=false is the authoritative readiness signal.
    ok_auto = wait_for_crane_automatic_mode(
        crane,
        log,
        stop_event=shutdown_evt,
        timeout=CRANE_AUTO_WAIT_TIMEOUT_S,
        stable_s=CRANE_AUTO_STABLE_S,
    )
    if not ok_auto:
        if not ALLOW_UNHOMED_START:
            try:
                crane.stop_all()
            finally:
                watchdog_stop.set()
                crane.disconnect()
            raise SystemExit(
                "Refusing to accept crane orders because "
                "DX_Custom_V.Status.WatchDogFault did not become false. "
                "Check access code, watchdog loop, PLC mode, and OPC UA status."
            )
        log.warning(
            "ALLOW_UNHOMED_START=true: adapter will start for supervised telemetry; "
            "manual motion remains blocked while operatingMode is not AUTOMATIC."
        )
    elif CRANE_HOME_ON_START:
        log.warning(
            "CRANE_HOME_ON_START=true: automatic mode confirmed; beginning configured "
            "startup homing (Z then XY)."
        )
        ok_z = _move_hoist_to(
            crane,
            log,
            HOME_HOIST_MM,
            timeout_s=300.0,
            stop_event=shutdown_evt,
            abort_check=lambda: bool(crane.get_watchdog_fault()),
        )
        if ok_z:
            ok_xy = _move_xy_to(
                crane,
                log,
                HOME_BRIDGE_MM,
                HOME_TROLLEY_MM,
                timeout_s=300.0,
                stop_event=shutdown_evt,
                abort_check=lambda: bool(crane.get_watchdog_fault()),
            )
        else:
            ok_xy = False
            log.error("Skipping XY homing because hoist homing failed.")
        try:
            crane.stop_all()
        except Exception:
            pass
        if not (ok_z and ok_xy):
            log.error("Startup homing failed or timed out; crane remains stopped.")
            if not ALLOW_UNHOMED_START:
                watchdog_stop.set()
                crane.disconnect()
                raise SystemExit(
                    "Refusing to accept crane orders after failed startup homing."
                )
        else:
            log.info("Startup homing complete (Z then XY).")
    else:
        log.info(
            "Automatic mode confirmed. CRANE_HOME_ON_START=false, so no movement "
            "is performed at adapter startup; use the dashboard Home controls when ready."
        )
    # --- Start adapter threads/MQTT after successful or explicitly overridden preflight ---
    adapter = VDA5050Adapter(crane, log, watchdog_health)
    adapter_ref["obj"] = adapter
    try:
        adapter.start()
    except Exception as exc:
        log.error("Crane adapter startup failed: %s", exc)
        try:
            crane.stop_all()
        except Exception:
            pass
        watchdog_stop.set()
        try:
            crane.disconnect()
        finally:
            raise SystemExit(str(exc))

    log.info(
        "---------------- | VDA5050 adapter running – Press Ctrl-C to stop | ---------------"
    )
    try:
        while True:
            time.sleep(1)
    except KeyboardInterrupt:
        _sigterm(None, None)


if __name__ == "__main__":
    main()
