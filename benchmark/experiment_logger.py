"""Shared, low-overhead JSONL event logger for physical benchmarks.

The timestamp is captured in the caller before any serialization, disk I/O, or
MQTT publishing.  A background writer then persists and optionally broadcasts
the immutable event.  ``monotonic_ns`` is the duration clock; ``timestamp_utc``
is only for human-readable alignment between machines.
"""

from __future__ import annotations

import atexit
import hashlib
import json
import os
import queue
import socket
import subprocess
import threading
import time
from datetime import datetime, timezone
from pathlib import Path
from typing import Any, Callable, Dict, Mapping, Optional

try:  # Linux deployment; tests remain portable without it.
    import fcntl
except ImportError:  # pragma: no cover - Windows fallback
    fcntl = None


SCHEMA_VERSION = "1.0"
EVENT_TYPES = {
    "COMMAND_ISSUED",
    "MQTT_RECEIVED",
    "VDA_ACCEPTED",
    "NATIVE_DISPATCH",
    "NATIVE_ACK",
    "MOTION_STARTED",
    "MOTION_COMPLETED",
    "RESULT_OBSERVED",
}
ARCHITECTURES = {"native", "vda", "setup"}
DEVICES = {"rox", "crane", "cell"}


def utc_now() -> str:
    return datetime.now(timezone.utc).isoformat(timespec="microseconds").replace(
        "+00:00", "Z"
    )


def git_commit(repo_root: Path | str) -> str:
    """Return the exact checked-out commit, or ``unknown`` outside Git."""
    try:
        result = subprocess.run(
            ["git", "-C", str(repo_root), "rev-parse", "HEAD"],
            check=True,
            capture_output=True,
            text=True,
            timeout=2.0,
        )
        return result.stdout.strip() or "unknown"
    except (OSError, subprocess.SubprocessError):
        return "unknown"


def config_identifier(path: Path | str) -> str:
    """Return a stable SHA-256 identifier for a frozen configuration file."""
    source = Path(path).expanduser().resolve()
    digest = hashlib.sha256(source.read_bytes()).hexdigest()
    return f"sha256:{digest}"


def system_boot_id() -> str:
    """Identify the monotonic-clock epoch used by Linux processes."""
    try:
        return Path("/proc/sys/kernel/random/boot_id").read_text(
            encoding="utf-8"
        ).strip()
    except OSError:
        return "unknown"


class ExperimentLogger:
    """Capture benchmark events and write them asynchronously as JSON Lines."""

    def __init__(
        self,
        path: Path | str,
        *,
        repo_root: Path | str,
        source: str,
        config_id: str = "unknown",
        publisher: Optional[Callable[[Mapping[str, Any]], None]] = None,
        enabled: bool = True,
    ) -> None:
        self.path = Path(path).expanduser().resolve()
        self.enabled = bool(enabled)
        self.source = str(source)
        self.config_id = str(config_id or "unknown")
        self.publisher = publisher
        self.software_commit = git_commit(repo_root)
        self.hostname = socket.gethostname()
        self.boot_id = system_boot_id()
        self._queue: "queue.Queue[object]" = queue.Queue()
        self._stop_token = object()
        self._closed = False
        self._error: Optional[str] = None
        self._thread: Optional[threading.Thread] = None
        if self.enabled:
            self.path.parent.mkdir(parents=True, exist_ok=True)
            self._thread = threading.Thread(
                target=self._writer,
                name=f"benchmark-jsonl-{self.source}",
                daemon=True,
            )
            self._thread.start()
            atexit.register(self.close)

    @property
    def error(self) -> Optional[str]:
        return self._error

    def emit(
        self,
        event_type: str,
        *,
        trial_id: str,
        architecture: str,
        device: str,
        operation: str,
        command_id: str,
        order_id: str = "",
        pair_id: str = "",
        result: str = "",
        success: Optional[bool] = None,
        details: Optional[Mapping[str, Any]] = None,
    ) -> Dict[str, Any]:
        """Capture one event at the call site and queue it for persistence."""
        captured_ns = time.monotonic_ns()
        captured_utc = utc_now()
        event_type = str(event_type).upper()
        architecture = str(architecture).lower()
        device = str(device).lower()
        if event_type not in EVENT_TYPES:
            raise ValueError(f"Unsupported benchmark event_type {event_type!r}")
        if architecture not in ARCHITECTURES:
            raise ValueError(f"Unsupported architecture {architecture!r}")
        if device not in DEVICES:
            raise ValueError(f"Unsupported device {device!r}")
        if not trial_id or not command_id:
            raise ValueError("trial_id and command_id must be non-empty")

        record: Dict[str, Any] = {
            "schema_version": SCHEMA_VERSION,
            "timestamp_utc": captured_utc,
            "monotonic_ns": captured_ns,
            "trial_id": str(trial_id),
            "pair_id": str(pair_id),
            "architecture": architecture,
            "device": device,
            "operation": str(operation),
            "command_id": str(command_id),
            "order_id": str(order_id),
            "event_type": event_type,
            "result": str(result),
            "success": success,
            "git_commit": self.software_commit,
            "config_id": self.config_id,
            "source": self.source,
            "host": self.hostname,
            "boot_id": self.boot_id,
            "pid": os.getpid(),
        }
        if details:
            record["details"] = dict(details)
        if self.enabled and not self._closed:
            self._queue.put(record)
        return record

    def flush(self, timeout: float = 5.0) -> bool:
        if not self.enabled or self._closed:
            return True
        marker = threading.Event()
        self._queue.put(marker)
        return marker.wait(timeout=max(0.0, timeout))

    def close(self) -> None:
        if not self.enabled or self._closed:
            return
        self._closed = True
        self._queue.put(self._stop_token)
        if self._thread and self._thread is not threading.current_thread():
            self._thread.join(timeout=5.0)

    def _writer(self) -> None:
        try:
            with self.path.open("a", encoding="utf-8", buffering=1) as stream:
                while True:
                    item = self._queue.get()
                    if item is self._stop_token:
                        stream.flush()
                        return
                    if isinstance(item, threading.Event):
                        stream.flush()
                        item.set()
                        continue
                    record = item
                    line = json.dumps(
                        record, separators=(",", ":"), sort_keys=True, allow_nan=False
                    )
                    if fcntl is not None:
                        fcntl.flock(stream.fileno(), fcntl.LOCK_EX)
                    try:
                        stream.write(line + "\n")
                        stream.flush()
                    finally:
                        if fcntl is not None:
                            fcntl.flock(stream.fileno(), fcntl.LOCK_UN)
                    if self.publisher is not None:
                        try:
                            self.publisher(record)
                        except Exception as exc:  # instrumentation never stops motion
                            self._error = f"publisher: {type(exc).__name__}: {exc}"
        except Exception as exc:  # instrumentation never stops motion
            self._error = f"writer: {type(exc).__name__}: {exc}"


def publish_json_event(mqtt_client: Any, topic: str) -> Callable[[Mapping[str, Any]], None]:
    """Build a non-blocking Paho publisher callback for ``ExperimentLogger``."""
    def publish(record: Mapping[str, Any]) -> None:
        mqtt_client.publish(
            topic,
            json.dumps(record, separators=(",", ":"), allow_nan=False),
            qos=0,
            retain=False,
        )

    return publish
