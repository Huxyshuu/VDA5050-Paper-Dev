"""Dedicated OPC UA watchdog session and fail-closed feed permission gate."""
from __future__ import annotations

import threading
import time
from typing import Any, Callable, Dict, Optional

from asyncua import ua
from asyncua.sync import Client


WATCHDOG_NODE_ID = "ns=5;s=DX_Custom_V.Controls.Watchdog"


def classify_watchdog_exception(
    session: "DedicatedWatchdogSession", exc: BaseException
) -> Dict[str, str]:
    """Classify a heartbeat failure without guessing that every error is transport loss."""
    session_lost = session.snapshot().get("status") == "LOST"
    return {
        "event_type": (
            "OPCUA_WATCHDOG_SESSION_LOST" if session_lost else "WATCHDOG_INTERNAL_ERROR"
        ),
        "category": "opcua_session_transport" if session_lost else "watchdog_internal",
        "exception_type": type(exc).__name__,
        "error": f"{type(exc).__name__}: {exc}",
    }


class WatchdogFeedGate:
    """Latch watchdog feeding off when the control application is not healthy."""

    def __init__(self, guard_timeout_s: float = 1.0) -> None:
        self.guard_timeout_s = max(0.25, float(guard_timeout_s))
        self._lock = threading.RLock()
        self._control_connected = False
        self._guard_last_monotonic: Optional[float] = None
        self._guard_source = ""
        self._phase = "preflight"
        self._runtime_ready = False
        self._fatal_reason = ""
        self._shutting_down = False

    def mark_control_connected(self) -> None:
        with self._lock:
            if not self._fatal_reason:
                self._control_connected = True

    def mark_control_lost(self, reason: str) -> None:
        with self._lock:
            self._control_connected = False
            self._fatal_reason = self._fatal_reason or str(reason or "control OPC UA session lost")

    def note_guard_heartbeat(self, source: str) -> None:
        with self._lock:
            self._guard_last_monotonic = time.monotonic()
            self._guard_source = str(source)

    def activate_runtime(self) -> None:
        with self._lock:
            self._phase = "runtime"
            self._runtime_ready = True

    def inhibit(self, reason: str) -> None:
        with self._lock:
            self._fatal_reason = self._fatal_reason or str(reason or "watchdog feed inhibited")

    def shutdown(self) -> None:
        with self._lock:
            self._shutting_down = True

    def snapshot(self) -> Dict[str, Any]:
        now = time.monotonic()
        with self._lock:
            guard_age = (
                None
                if self._guard_last_monotonic is None
                else max(0.0, now - self._guard_last_monotonic)
            )
            if (
                not self._fatal_reason
                and not self._shutting_down
                and (guard_age is None or guard_age > self.guard_timeout_s)
            ):
                self._fatal_reason = "automatic-mode/controller guard heartbeat expired"
            reasons = []
            if self._shutting_down:
                reasons.append("application shutdown")
            if not self._control_connected:
                reasons.append("control OPC UA session unavailable")
            if self._phase == "runtime" and not self._runtime_ready:
                reasons.append("adapter runtime unavailable")
            if self._fatal_reason:
                reasons.append(self._fatal_reason)
            feed_enabled = not reasons
            return {
                "feed_enabled": feed_enabled,
                "reason": "; ".join(dict.fromkeys(reasons)),
                "phase": self._phase,
                "control_session_healthy": self._control_connected,
                "guard_source": self._guard_source,
                "guard_age_ms": None if guard_age is None else guard_age * 1000.0,
                "guard_timeout_ms": self.guard_timeout_s * 1000.0,
                "runtime_ready": self._runtime_ready,
                "fatal_reason": self._fatal_reason,
                "shutting_down": self._shutting_down,
            }

    def can_feed(self) -> bool:
        return bool(self.snapshot()["feed_enabled"])


class DedicatedWatchdogSession:
    """A minimal OPC UA client used exclusively for the PLC heartbeat write."""

    def __init__(
        self,
        endpoint: str,
        *,
        client_factory: Callable[[str], Any] = Client,
    ) -> None:
        self.endpoint = str(endpoint)
        self._client_factory = client_factory
        self.client: Optional[Any] = None
        self._watchdog_node: Optional[Any] = None
        self._watchdog_value = 0
        self._state_lock = threading.RLock()
        self._connected = False
        self._node_ready = False
        self._last_error = ""
        self._last_timing: Dict[str, Any] = {}

    def connect(self) -> None:
        client = self._client_factory(self.endpoint)
        try:
            client.connect()
            node = client.get_node(WATCHDOG_NODE_ID)
            initial_value = int(node.read_value())
        except BaseException as exc:
            try:
                client.disconnect()
            except Exception:
                pass
            with self._state_lock:
                self._last_error = f"{type(exc).__name__}: {exc}"
                self._connected = False
                self._node_ready = False
            raise
        with self._state_lock:
            self.client = client
            self._watchdog_node = node
            self._watchdog_value = initial_value
            self._connected = True
            self._node_ready = True
            self._last_error = ""

    def write_next(
        self,
        scheduled_deadline_monotonic: float,
        attempt_started_monotonic: float,
    ) -> Dict[str, Any]:
        with self._state_lock:
            node = self._watchdog_node
            connected = self._connected and self._node_ready
            current = self._watchdog_value
        if not connected or node is None:
            raise RuntimeError("dedicated watchdog OPC UA session is not connected")

        value = (current % 30000) + 1
        write_started = time.monotonic()
        error: Optional[BaseException] = None
        try:
            node.write_value(ua.DataValue(ua.Variant(value, ua.VariantType.Int16)))
        except BaseException as exc:
            error = exc
        write_finished = time.monotonic()
        timing = {
            "reason": "watchdog",
            "operation": "write",
            "logical_node": "watchdog_heartbeat",
            "session_architecture": "dedicated_watchdog",
            "scheduled_deadline_monotonic": float(scheduled_deadline_monotonic),
            "attempt_started_monotonic": float(attempt_started_monotonic),
            "write_started_monotonic": write_started,
            "write_finished_monotonic": write_finished,
            "watchdog_schedule_lateness_ms": max(
                0.0,
                (float(attempt_started_monotonic) - float(scheduled_deadline_monotonic))
                * 1000.0,
            ),
            "watchdog_lock_wait_ms": None,
            "control_lock_wait_ms": 0.0,
            "watchdog_lock_wait_applicable": False,
            "watchdog_write_duration_ms": max(0.0, (write_finished - write_started) * 1000.0),
            "watchdog_total_cycle_ms": max(
                0.0, (write_finished - float(attempt_started_monotonic)) * 1000.0
            ),
            "lock_owner_at_request": None,
            "lock_owner_thread_at_request": None,
            "success": error is None,
            "watchdog_value": value,
            "error": "" if error is None else f"{type(error).__name__}: {error}",
        }
        with self._state_lock:
            self._last_timing = dict(timing)
            if error is None:
                self._watchdog_value = value
                self._last_error = ""
            else:
                self._connected = False
                self._node_ready = False
                self._last_error = timing["error"]
        if error is not None:
            raise error
        return timing

    def heartbeat_once(
        self,
        scheduled_deadline_monotonic: float,
        attempt_started_monotonic: float,
        on_success: Optional[Callable[[int, Dict[str, Any]], None]] = None,
    ) -> Dict[str, Any]:
        """Perform one complete dedicated-session heartbeat iteration."""
        timing = self.write_next(
            scheduled_deadline_monotonic,
            attempt_started_monotonic,
        )
        if on_success is not None:
            on_success(int(timing["watchdog_value"]), timing)
        return timing

    def disconnect(self) -> None:
        with self._state_lock:
            client = self.client
            self._connected = False
            self._node_ready = False
        if client is not None:
            try:
                client.disconnect()
            except Exception as exc:
                with self._state_lock:
                    self._last_error = f"{type(exc).__name__}: {exc}"

    def snapshot(self) -> Dict[str, Any]:
        with self._state_lock:
            return {
                "status": "CONNECTED" if self._connected and self._node_ready else "LOST",
                "connected": self._connected,
                "node_ready": self._node_ready,
                "architecture": "dedicated_watchdog",
                "client_identity": id(self.client) if self.client is not None else None,
                "last_error": self._last_error,
            }

    def last_timing(self) -> Dict[str, Any]:
        with self._state_lock:
            return dict(self._last_timing)
