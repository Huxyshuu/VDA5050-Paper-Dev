"""Independent PLC-network, Raspberry Pi, and JSONL diagnostic collection.

This module deliberately has no dependency on :mod:`crane` and never receives
the OPC UA client or its I/O lock.  Potentially slow Linux commands run only in
the collector thread, at the configured low sampling rate, with hard timeouts.
"""
from __future__ import annotations

import copy
import json
import logging
import os
import queue
import re
import shutil
import subprocess
import threading
import time
from collections import deque
from datetime import datetime, timezone
from pathlib import Path
from typing import Any, Callable, Deque, Dict, List, Mapping, Optional, Sequence


def utc_now() -> str:
    return (
        datetime.now(timezone.utc)
        .isoformat(timespec="milliseconds")
        .replace("+00:00", "Z")
    )


def _safe_float(value: Any) -> Optional[float]:
    try:
        return float(value)
    except (TypeError, ValueError):
        return None


class NetworkDiagnosticsCollector:
    """Collect low-rate network and host metrics without touching OPC UA."""

    def __init__(
        self,
        plc_host: str,
        *,
        enabled: bool = True,
        sample_s: float = 1.0,
        history_s: float = 60.0,
        ping_timeout_s: float = 0.5,
        log: Optional[logging.Logger] = None,
        on_sample: Optional[Callable[[Mapping[str, Any]], None]] = None,
    ) -> None:
        self.plc_host = str(plc_host)
        self.enabled = bool(enabled)
        self.sample_s = max(0.25, float(sample_s))
        self.history_s = max(self.sample_s, float(history_s))
        self.ping_timeout_s = max(0.1, float(ping_timeout_s))
        self.log = log or logging.getLogger(__name__)
        self.on_sample = on_sample
        capacity = max(2, int(self.history_s / self.sample_s) + 2)
        self._history: Deque[Dict[str, Any]] = deque(maxlen=capacity)
        self._lock = threading.RLock()
        self._stop = threading.Event()
        self._thread: Optional[threading.Thread] = None
        self._latest: Dict[str, Any] = {
            "status": "DISABLED" if not self.enabled else "STARTING",
            "plc_host": self.plc_host,
        }
        self._route_cache: Dict[str, Any] = {}
        self._route_checked_monotonic = 0.0
        self._cpu_previous: Optional[tuple[int, int]] = None
        self._previous_interface_stats: Dict[str, int] = {}
        self._previous_tcp_counters: Dict[str, int] = {}

    @staticmethod
    def parse_route(output: str) -> Dict[str, Any]:
        tokens = str(output or "").split()
        result: Dict[str, Any] = {}
        for key, target in (("dev", "interface"), ("src", "source_ip"), ("via", "gateway")):
            try:
                result[target] = tokens[tokens.index(key) + 1]
            except (ValueError, IndexError):
                pass
        return result

    @staticmethod
    def parse_iw_link(output: str) -> Dict[str, Any]:
        text = str(output or "")
        result: Dict[str, Any] = {}
        connected = re.search(r"Connected to\s+([0-9a-f:]{17})", text, re.IGNORECASE)
        signal = re.search(r"signal:\s*(-?[0-9.]+)\s*dBm", text, re.IGNORECASE)
        tx = re.search(r"tx bitrate:\s*([^\r\n]+)", text, re.IGNORECASE)
        rx = re.search(r"rx bitrate:\s*([^\r\n]+)", text, re.IGNORECASE)
        if connected:
            result["bssid"] = connected.group(1).lower()
            result["connected"] = True
        elif "Not connected" in text:
            result["connected"] = False
        if signal:
            result["signal_dbm"] = float(signal.group(1))
        if tx:
            result["tx_bitrate"] = tx.group(1).strip()
        if rx:
            result["rx_bitrate"] = rx.group(1).strip()
        return result

    @staticmethod
    def parse_power_save(output: str) -> Optional[str]:
        match = re.search(r"Power save:\s*(on|off)", str(output or ""), re.IGNORECASE)
        return match.group(1).lower() if match else None

    @staticmethod
    def parse_ping(output: str) -> Optional[float]:
        match = re.search(r"time[=<]([0-9.]+)\s*ms", str(output or ""))
        return float(match.group(1)) if match else None

    @staticmethod
    def wifi_quality(signal_dbm: Any) -> str:
        value = _safe_float(signal_dbm)
        if value is None:
            return "Unavailable"
        if value >= -55:
            return "Strong"
        if value >= -67:
            return "Good"
        if value >= -75:
            return "Marginal"
        return "Poor"

    def _run(self, args: Sequence[str], timeout_s: float) -> Dict[str, Any]:
        executable = str(args[0]) if args else ""
        if not executable or shutil.which(executable) is None:
            return {"available": False, "error": f"{executable or 'command'} not installed"}
        try:
            result = subprocess.run(
                list(args),
                capture_output=True,
                text=True,
                timeout=max(0.1, timeout_s),
                check=False,
            )
        except subprocess.TimeoutExpired:
            return {"available": True, "timed_out": True, "error": "command timed out"}
        except (OSError, ValueError) as exc:
            return {"available": False, "error": f"{type(exc).__name__}: {exc}"}
        return {
            "available": True,
            "returncode": int(result.returncode),
            "stdout": result.stdout or "",
            "stderr": result.stderr or "",
        }

    @staticmethod
    def _read_text(path: Path) -> Optional[str]:
        try:
            return path.read_text(encoding="utf-8").strip()
        except (OSError, UnicodeError):
            return None

    def _route(self, now: float) -> Dict[str, Any]:
        if self._route_cache and now - self._route_checked_monotonic < 10.0:
            return dict(self._route_cache)
        command = self._run(["ip", "route", "get", self.plc_host], 0.75)
        route = self.parse_route(command.get("stdout", ""))
        route["available"] = bool(command.get("available") and command.get("returncode") == 0)
        if command.get("error"):
            route["error"] = command["error"]
        elif command.get("returncode") not in {None, 0}:
            route["error"] = str(command.get("stderr") or "route lookup failed").strip()
        self._route_cache = route
        self._route_checked_monotonic = now
        return dict(route)

    def _interface_stats(self, interface: str) -> Dict[str, Any]:
        result: Dict[str, Any] = {}
        for name in ("rx_errors", "tx_errors", "rx_dropped", "tx_dropped"):
            raw = self._read_text(Path("/sys/class/net") / interface / "statistics" / name)
            try:
                result[name] = int(raw) if raw is not None else None
            except ValueError:
                result[name] = None
        previous = self._previous_interface_stats
        for name in ("rx_errors", "tx_errors", "rx_dropped", "tx_dropped"):
            value = result.get(name)
            old_value = previous.get(name)
            result[f"{name}_delta"] = (
                max(0, int(value) - old_value)
                if value is not None and old_value is not None
                else 0
            )
        self._previous_interface_stats = {
            key: int(value)
            for key, value in result.items()
            if key in {"rx_errors", "tx_errors", "rx_dropped", "tx_dropped"}
            and value is not None
        }
        return result

    def _wifi(self, interface: str) -> Dict[str, Any]:
        wireless_path = Path("/sys/class/net") / interface / "wireless"
        if not wireless_path.exists():
            return {"wireless": False, "status": "not wireless"}
        result: Dict[str, Any] = {"wireless": True}
        link = self._run(["iw", "dev", interface, "link"], 0.75)
        if not link.get("available"):
            result.update({"status": "unavailable", "error": link.get("error", "iw unavailable")})
            return result
        result.update(self.parse_iw_link(link.get("stdout", "")))
        station = self._run(["iw", "dev", interface, "station", "dump"], 0.75)
        if station.get("returncode") == 0:
            parsed_station = self.parse_iw_link(station.get("stdout", ""))
            for key in ("signal_dbm", "tx_bitrate", "rx_bitrate"):
                if key in parsed_station:
                    result[key] = parsed_station[key]
        power = self._run(["iw", "dev", interface, "get", "power_save"], 0.75)
        if power.get("returncode") == 0:
            result["power_save"] = self.parse_power_save(power.get("stdout", ""))
        result["quality"] = self.wifi_quality(result.get("signal_dbm"))
        result["status"] = "connected" if result.get("connected") else "not connected"
        return result

    def _ping(self) -> Dict[str, Any]:
        command = self._run(
            ["ping", "-n", "-c", "1", "-W", "1", self.plc_host],
            self.ping_timeout_s + 0.3,
        )
        rtt = self.parse_ping(command.get("stdout", ""))
        return {
            "available": bool(command.get("available")),
            "success": bool(command.get("returncode") == 0 and rtt is not None),
            "rtt_ms": rtt,
            "timed_out": bool(command.get("timed_out")),
            "error": command.get("error") or (
                str(command.get("stderr") or "").strip()
                if command.get("returncode") not in {None, 0}
                else ""
            ),
        }

    def _cpu_utilisation(self) -> Optional[float]:
        raw = self._read_text(Path("/proc/stat"))
        if not raw:
            return None
        first = raw.splitlines()[0].split()
        if not first or first[0] != "cpu":
            return None
        try:
            values = [int(value) for value in first[1:]]
        except ValueError:
            return None
        total = sum(values)
        idle = values[3] + (values[4] if len(values) > 4 else 0)
        previous = self._cpu_previous
        self._cpu_previous = (total, idle)
        if previous is None or total <= previous[0]:
            return None
        total_delta = total - previous[0]
        idle_delta = idle - previous[1]
        return round(max(0.0, min(100.0, (1.0 - idle_delta / total_delta) * 100.0)), 1)

    def _tcp_counters(self) -> Dict[str, Any]:
        raw = self._read_text(Path("/proc/net/snmp"))
        if not raw:
            return {"available": False}
        lines = raw.splitlines()
        for index in range(len(lines) - 1):
            if lines[index].startswith("Tcp:") and lines[index + 1].startswith("Tcp:"):
                keys = lines[index].split()[1:]
                values = lines[index + 1].split()[1:]
                mapping = dict(zip(keys, values))
                try:
                    result = {
                        "available": True,
                        "retrans_segs": int(mapping.get("RetransSegs", "0")),
                        "out_segs": int(mapping.get("OutSegs", "0")),
                        "in_errors": int(mapping.get("InErrs", "0")),
                    }
                    for key in ("retrans_segs", "out_segs", "in_errors"):
                        previous = self._previous_tcp_counters.get(key)
                        result[f"{key}_delta"] = (
                            max(0, int(result[key]) - previous)
                            if previous is not None
                            else 0
                        )
                    self._previous_tcp_counters = {
                        key: int(result[key])
                        for key in ("retrans_segs", "out_segs", "in_errors")
                    }
                    return result
                except ValueError:
                    break
        return {"available": False}

    def _system(self) -> Dict[str, Any]:
        try:
            load = [round(float(item), 3) for item in os.getloadavg()]
        except (AttributeError, OSError):
            load = []
        temp_raw = self._read_text(Path("/sys/class/thermal/thermal_zone0/temp"))
        temp_c = _safe_float(temp_raw)
        if temp_c is not None and temp_c > 1000.0:
            temp_c /= 1000.0
        throttle = self._run(["vcgencmd", "get_throttled"], 0.5)
        throttle_text = str(throttle.get("stdout") or "").strip()
        throttle_match = re.search(r"0x([0-9a-fA-F]+)", throttle_text)
        throttle_value = int(throttle_match.group(1), 16) if throttle_match else None
        return {
            "load_1m": load[0] if len(load) > 0 else None,
            "load_5m": load[1] if len(load) > 1 else None,
            "load_15m": load[2] if len(load) > 2 else None,
            "cpu_utilisation_percent": self._cpu_utilisation(),
            "cpu_temp_c": round(temp_c, 1) if temp_c is not None else None,
            "throttled_raw": f"0x{throttle_value:x}" if throttle_value is not None else None,
            "under_voltage_now": bool(throttle_value & 0x1) if throttle_value is not None else None,
            "throttled_now": bool(throttle_value & 0x4) if throttle_value is not None else None,
            "vcgencmd_available": bool(throttle.get("available")),
        }

    @staticmethod
    def _status(sample: Mapping[str, Any]) -> str:
        route = sample.get("route") or {}
        ping = sample.get("ping") or {}
        wifi = sample.get("wifi") or {}
        stats = sample.get("interface_stats") or {}
        if not route.get("available"):
            return "UNAVAILABLE"
        if ping.get("available") and not ping.get("success"):
            return "DEGRADED"
        if wifi.get("wireless") and wifi.get("quality") in {"Marginal", "Poor"}:
            return "DEGRADED"
        if any(
            int(stats.get(f"{key}_delta") or 0) > 0
            for key in ("rx_errors", "tx_errors", "rx_dropped", "tx_dropped")
        ):
            return "DEGRADED"
        return "HEALTHY"

    def collect_once(self) -> Dict[str, Any]:
        now = time.monotonic()
        route = self._route(now)
        interface = str(route.get("interface") or "")
        sample: Dict[str, Any] = {
            "timestamp": utc_now(),
            "monotonic": now,
            "plc_host": self.plc_host,
            "route": route,
            "interface_stats": self._interface_stats(interface) if interface else {},
            "wifi": self._wifi(interface) if interface else {"wireless": False, "status": "route unavailable"},
            "ping": self._ping(),
            "tcp": self._tcp_counters(),
            "system": self._system(),
        }
        sample["status"] = self._status(sample)
        with self._lock:
            self._latest = copy.deepcopy(sample)
            self._history.append(copy.deepcopy(sample))
        if self.on_sample is not None:
            try:
                self.on_sample(copy.deepcopy(sample))
            except Exception as exc:
                self.log.warning("Network diagnostic sample callback failed: %s", exc)
        return sample

    def _loop(self) -> None:
        self.log.info(
            "PLC network diagnostics started for %s at %.2fs intervals",
            self.plc_host,
            self.sample_s,
        )
        while not self._stop.is_set():
            started = time.monotonic()
            try:
                self.collect_once()
            except Exception as exc:
                with self._lock:
                    self._latest = {
                        "timestamp": utc_now(),
                        "monotonic": time.monotonic(),
                        "plc_host": self.plc_host,
                        "status": "UNAVAILABLE",
                        "error": f"{type(exc).__name__}: {exc}",
                    }
                self.log.warning("Network diagnostic collection failed: %s", exc)
            self._stop.wait(max(0.0, self.sample_s - (time.monotonic() - started)))

    def start(self) -> None:
        if not self.enabled or (self._thread and self._thread.is_alive()):
            return
        self._stop.clear()
        self._thread = threading.Thread(
            target=self._loop,
            name="crane_network_diagnostics",
            daemon=True,
        )
        self._thread.start()

    def stop(self) -> None:
        self._stop.set()
        if self._thread and self._thread.is_alive():
            self._thread.join(timeout=max(1.0, self.sample_s + 0.5))

    def latest(self) -> Dict[str, Any]:
        with self._lock:
            return copy.deepcopy(self._latest)

    def history(self) -> List[Dict[str, Any]]:
        with self._lock:
            return copy.deepcopy(list(self._history))


class JsonlDiagnosticRecorder:
    """Queue structured events for a process-local JSONL writer thread."""

    def __init__(self, directory: Path, log: Optional[logging.Logger] = None) -> None:
        self.directory = Path(directory)
        self.log = log or logging.getLogger(__name__)
        self._lock = threading.Lock()
        self._queue: "queue.Queue[Dict[str, Any]]" = queue.Queue(maxsize=2000)
        self._stop = threading.Event()
        self._thread: Optional[threading.Thread] = None
        self.dropped_records = 0
        self.error = ""
        stamp = datetime.now(timezone.utc).strftime("%Y%m%dT%H%M%SZ")
        self.path = self.directory / f"crane-diagnostics-{stamp}-{os.getpid()}.jsonl"
        try:
            self.directory.mkdir(parents=True, exist_ok=True)
        except OSError as exc:
            self.error = f"{type(exc).__name__}: {exc}"
            self.log.warning("Cannot create crane diagnostics directory %s: %s", self.directory, exc)
        if not self.error:
            self._thread = threading.Thread(
                target=self._writer_loop,
                name="crane_diagnostics_jsonl",
                daemon=True,
            )
            self._thread.start()

    def _writer_loop(self) -> None:
        try:
            with self.path.open("a", encoding="utf-8", buffering=1) as handle:
                while not self._stop.is_set() or not self._queue.empty():
                    try:
                        record = self._queue.get(timeout=0.2)
                    except queue.Empty:
                        continue
                    try:
                        handle.write(
                            json.dumps(
                                record,
                                sort_keys=True,
                                separators=(",", ":"),
                                default=str,
                            )
                            + "\n"
                        )
                        handle.flush()
                    finally:
                        self._queue.task_done()
        except OSError as exc:
            with self._lock:
                self.error = f"{type(exc).__name__}: {exc}"
            self.log.warning("Cannot write crane diagnostic records to %s: %s", self.path, exc)
            while True:
                try:
                    self._queue.get_nowait()
                    self._queue.task_done()
                except queue.Empty:
                    break

    def record(self, event_type: str, payload: Mapping[str, Any]) -> None:
        if self.error:
            return
        record = {
            "timestamp": utc_now(),
            "monotonic": time.monotonic(),
            "event_type": str(event_type),
            **copy.deepcopy(dict(payload)),
        }
        try:
            self._queue.put_nowait(record)
        except queue.Full:
            with self._lock:
                self.dropped_records += 1
            if event_type != "WATCHDOG_SAMPLE":
                try:
                    self._queue.get_nowait()
                    self._queue.task_done()
                    self._queue.put_nowait(record)
                except queue.Empty:
                    pass

    def stop(self) -> None:
        self._stop.set()
        if self._thread and self._thread.is_alive():
            self._thread.join(timeout=3.0)


class CraneDiagnostics:
    """Combine low-rate network history with watchdog and adapter events."""

    def __init__(
        self,
        plc_host: str,
        log_directory: Path,
        *,
        enabled: bool = True,
        sample_s: float = 1.0,
        history_s: float = 60.0,
        ping_timeout_s: float = 0.5,
        log: Optional[logging.Logger] = None,
    ) -> None:
        self.log = log or logging.getLogger(__name__)
        self.recorder = JsonlDiagnosticRecorder(log_directory, self.log)
        self.collector = NetworkDiagnosticsCollector(
            plc_host,
            enabled=enabled,
            sample_s=sample_s,
            history_s=history_s,
            ping_timeout_s=ping_timeout_s,
            log=self.log,
            on_sample=self._on_network_sample,
        )
        self._lock = threading.RLock()
        self._context_provider: Optional[Callable[[], Mapping[str, Any]]] = None
        self._last_watchdog_status: Optional[str] = None
        self._last_network_status: Optional[str] = None
        self._last_watchdog_sample_monotonic = 0.0
        self._latest_failure: Dict[str, Any] = {}
        self._latest_slow_transaction: Dict[str, Any] = {}
        self._latest_critical_transaction: Dict[str, Any] = {}
        self._recent_events: Deque[Dict[str, Any]] = deque(maxlen=40)

    def set_context_provider(self, provider: Callable[[], Mapping[str, Any]]) -> None:
        with self._lock:
            self._context_provider = provider

    def start(self) -> None:
        self.collector.start()

    def stop(self) -> None:
        self.collector.stop()
        self.recorder.stop()

    def _context(self) -> Dict[str, Any]:
        with self._lock:
            provider = self._context_provider
        if provider is None:
            return {}
        try:
            return copy.deepcopy(dict(provider()))
        except Exception as exc:
            return {"context_error": f"{type(exc).__name__}: {exc}"}

    @staticmethod
    def _compact_sample(sample: Mapping[str, Any]) -> Dict[str, Any]:
        route = sample.get("route") or {}
        wifi = sample.get("wifi") or {}
        ping = sample.get("ping") or {}
        stats = sample.get("interface_stats") or {}
        system = sample.get("system") or {}
        tcp = sample.get("tcp") or {}
        return {
            "status": sample.get("status"),
            "timestamp": sample.get("timestamp"),
            "plc_host": sample.get("plc_host"),
            "interface": route.get("interface"),
            "source_ip": route.get("source_ip"),
            "wireless": wifi.get("wireless"),
            "wifi_quality": wifi.get("quality"),
            "wifi_signal_dbm": wifi.get("signal_dbm"),
            "wifi_tx_bitrate": wifi.get("tx_bitrate"),
            "wifi_rx_bitrate": wifi.get("rx_bitrate"),
            "wifi_bssid": wifi.get("bssid"),
            "wifi_power_save": wifi.get("power_save"),
            "ping_success": ping.get("success"),
            "ping_rtt_ms": ping.get("rtt_ms"),
            "rx_errors": stats.get("rx_errors"),
            "tx_errors": stats.get("tx_errors"),
            "rx_dropped": stats.get("rx_dropped"),
            "tx_dropped": stats.get("tx_dropped"),
            "rx_errors_delta": stats.get("rx_errors_delta"),
            "tx_errors_delta": stats.get("tx_errors_delta"),
            "rx_dropped_delta": stats.get("rx_dropped_delta"),
            "tx_dropped_delta": stats.get("tx_dropped_delta"),
            "tcp_retrans_segs": tcp.get("retrans_segs"),
            "tcp_retrans_segs_delta": tcp.get("retrans_segs_delta"),
            "cpu_utilisation_percent": system.get("cpu_utilisation_percent"),
            "cpu_load_1m": system.get("load_1m"),
            "cpu_temp_c": system.get("cpu_temp_c"),
            "throttled": system.get("throttled_now"),
            "under_voltage": system.get("under_voltage_now"),
            "throttled_raw": system.get("throttled_raw"),
        }

    def record_event(
        self,
        event_type: str,
        *,
        watchdog: Optional[Mapping[str, Any]] = None,
        watchdog_fault: Optional[bool] = None,
        extra: Optional[Mapping[str, Any]] = None,
        include_history: bool = False,
    ) -> Dict[str, Any]:
        network = self._compact_sample(self.collector.latest())
        context = self._context()
        effective_watchdog_fault = (
            watchdog_fault
            if watchdog_fault is not None
            else context.get("watchdog_fault")
        )
        event: Dict[str, Any] = {
            "watchdog": copy.deepcopy(dict(watchdog or {})),
            "watchdog_fault": effective_watchdog_fault,
            "context": context,
            "network": network,
        }
        if extra:
            event["details"] = copy.deepcopy(dict(extra))
        if include_history:
            event["pre_failure_history"] = self.collector.history()
        self.recorder.record(event_type, event)
        compact_event = {
            "timestamp": utc_now(),
            "event_type": event_type,
            "watchdog": event["watchdog"],
            "watchdog_fault": effective_watchdog_fault,
            "context": event["context"],
            "network": network,
            "details": event.get("details", {}),
        }
        with self._lock:
            self._recent_events.appendleft(copy.deepcopy(compact_event))
            if event_type in {"WATCHDOG_CRITICAL", "WATCHDOG_FAULT_TRUE", "OPCUA_EXCEPTION", "MOTION_STALLED"}:
                self._latest_failure = copy.deepcopy(compact_event)
            if event_type in {"OPCUA_SLOW_TRANSACTION", "OPCUA_CRITICAL_TRANSACTION"}:
                self._latest_slow_transaction = copy.deepcopy(compact_event)
            if event_type == "OPCUA_CRITICAL_TRANSACTION":
                self._latest_critical_transaction = copy.deepcopy(compact_event)
                self._latest_failure = copy.deepcopy(compact_event)
            if event_type in {
                "OPCUA_TRANSACTION_EXCEPTION",
                "OPCUA_CONTROL_SESSION_LOST",
                "OPCUA_WATCHDOG_SESSION_LOST",
            }:
                self._latest_failure = copy.deepcopy(compact_event)
        return compact_event

    def record_watchdog(self, snapshot: Mapping[str, Any]) -> None:
        now = time.monotonic()
        status = str(snapshot.get("status") or "UNKNOWN")
        with self._lock:
            old_status = self._last_watchdog_status
            due_sample = now - self._last_watchdog_sample_monotonic >= 1.0
            if due_sample:
                self._last_watchdog_sample_monotonic = now
            self._last_watchdog_status = status
        if status != old_status:
            event_type = "WATCHDOG_RECOVERED" if status == "HEALTHY" and old_status else f"WATCHDOG_{status}"
            self.record_event(
                event_type,
                watchdog=snapshot,
                include_history=status == "CRITICAL",
            )
        elif due_sample:
            self.record_event("WATCHDOG_SAMPLE", watchdog=snapshot)

    def record_watchdog_fault(self, fault: bool, watchdog: Mapping[str, Any]) -> None:
        self.record_event(
            "WATCHDOG_FAULT_TRUE" if fault else "WATCHDOG_FAULT_FALSE",
            watchdog=watchdog,
            watchdog_fault=fault,
            include_history=fault,
        )

    def _on_network_sample(self, sample: Mapping[str, Any]) -> None:
        status = str(sample.get("status") or "UNAVAILABLE")
        with self._lock:
            previous = self._last_network_status
            self._last_network_status = status
        if previous is not None and status != previous:
            self.record_event(
                "NETWORK_DEGRADED" if status in {"DEGRADED", "UNAVAILABLE"} else "NETWORK_RECOVERED",
                extra={"previous_status": previous, "current_status": status},
            )

    def snapshot(self) -> Dict[str, Any]:
        with self._lock:
            failure = copy.deepcopy(self._latest_failure)
            slow_transaction = copy.deepcopy(self._latest_slow_transaction)
            critical_transaction = copy.deepcopy(self._latest_critical_transaction)
            events = copy.deepcopy(list(self._recent_events))
        return {
            "network": self._compact_sample(self.collector.latest()),
            "latest_failure": failure,
            "latest_slow_transaction": slow_transaction,
            "latest_critical_transaction": critical_transaction,
            "recent_events": events,
            "log_path": str(self.recorder.path),
            "log_error": self.recorder.error,
            "log_dropped_records": self.recorder.dropped_records,
        }
