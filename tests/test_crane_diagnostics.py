from __future__ import annotations

import importlib.util
import json
import sys
import tempfile
import threading
import time
import types
import unittest
from pathlib import Path
from unittest import mock

from crane_edge.network_diagnostics import CraneDiagnostics, NetworkDiagnosticsCollector


def load_crane_class():
    """Load crane.py with lightweight dependency stubs; no OPC UA connection."""
    saved = {name: sys.modules.get(name) for name in (
        "asyncua", "asyncua.sync", "numpy", "scipy", "scipy.interpolate"
    )}
    asyncua = types.ModuleType("asyncua")
    asyncua_sync = types.ModuleType("asyncua.sync")
    asyncua_sync.Client = object

    class VariantType:
        Int16 = "Int16"
        Int32 = "Int32"

    class Variant:
        def __init__(self, value, _kind):
            self.value = value

    class DataValue:
        def __init__(self, value):
            self.value = value

    asyncua.ua = types.SimpleNamespace(
        VariantType=VariantType,
        Variant=Variant,
        DataValue=DataValue,
    )
    numpy = types.ModuleType("numpy")
    scipy = types.ModuleType("scipy")
    scipy_interpolate = types.ModuleType("scipy.interpolate")
    scipy_interpolate.interp1d = lambda *args, **kwargs: None
    scipy.interpolate = scipy_interpolate
    sys.modules.update(
        {
            "asyncua": asyncua,
            "asyncua.sync": asyncua_sync,
            "numpy": numpy,
            "scipy": scipy,
            "scipy.interpolate": scipy_interpolate,
        }
    )
    try:
        path = Path(__file__).resolve().parents[1] / "crane_edge" / "crane.py"
        spec = importlib.util.spec_from_file_location("_crane_diagnostics_test", path)
        module = importlib.util.module_from_spec(spec)
        assert spec and spec.loader
        spec.loader.exec_module(module)
        return module.Crane
    finally:
        for name, previous in saved.items():
            if previous is None:
                sys.modules.pop(name, None)
            else:
                sys.modules[name] = previous


class FakeNode:
    def __init__(self, write_delay_s: float = 0.0) -> None:
        self.write_delay_s = write_delay_s

    def write_value(self, _value) -> None:
        time.sleep(self.write_delay_s)


class CraneIoTimingTests(unittest.TestCase):
    def test_watchdog_splits_lock_wait_from_actual_write(self) -> None:
        Crane = load_crane_class()
        crane = Crane.__new__(Crane)
        crane._io_lock = threading.RLock()
        crane._io_meta_lock = threading.RLock()
        crane._io_owner = None
        crane._io_owner_thread = None
        crane._io_owner_since_monotonic = None
        crane._io_reason_local = threading.local()
        crane._io_event_callback = None
        crane._last_watchdog_timing = {}
        crane._watchdog_priority = threading.Event()
        node = FakeNode(write_delay_s=0.008)
        crane._node_watchdog = node

        holder_started = threading.Event()
        release_holder = threading.Event()

        def hold_session() -> None:
            def transaction() -> None:
                holder_started.set()
                release_holder.wait(timeout=1.0)

            crane._run_io("move_xy", "write", transaction)

        holder = threading.Thread(target=hold_session, name="motion-holder")
        holder.start()
        self.assertTrue(holder_started.wait(timeout=1.0))
        releaser = threading.Timer(0.03, release_holder.set)
        releaser.start()
        attempt = time.monotonic()
        timing = crane._write_node(
            node,
            object(),
            scheduled_deadline_monotonic=attempt - 0.012,
            attempt_started_monotonic=attempt,
        )
        holder.join(timeout=1.0)
        releaser.join(timeout=1.0)

        self.assertFalse(holder.is_alive())
        self.assertGreaterEqual(timing["watchdog_lock_wait_ms"], 15.0)
        self.assertGreaterEqual(timing["watchdog_write_duration_ms"], 5.0)
        self.assertGreaterEqual(timing["watchdog_schedule_lateness_ms"], 8.0)
        self.assertEqual("move_xy", timing["lock_owner_at_request"])
        self.assertGreater(
            timing["watchdog_total_cycle_ms"],
            timing["watchdog_write_duration_ms"],
        )


class NetworkDiagnosticsTests(unittest.TestCase):
    def test_iw_and_ping_parsers_preserve_raw_evidence(self) -> None:
        iw = """Connected to aa:bb:cc:dd:ee:ff (on wlan0)\n\tsignal: -71 dBm\n\ttx bitrate: 54.0 MBit/s MCS 5\n\trx bitrate: 36.0 MBit/s MCS 3\n"""
        parsed = NetworkDiagnosticsCollector.parse_iw_link(iw)
        self.assertEqual("aa:bb:cc:dd:ee:ff", parsed["bssid"])
        self.assertEqual(-71.0, parsed["signal_dbm"])
        self.assertEqual("54.0 MBit/s MCS 5", parsed["tx_bitrate"])
        self.assertEqual("36.0 MBit/s MCS 3", parsed["rx_bitrate"])
        self.assertEqual("Marginal", NetworkDiagnosticsCollector.wifi_quality(-71))
        self.assertEqual(12.4, NetworkDiagnosticsCollector.parse_ping("time=12.4 ms"))

    def test_missing_linux_tools_degrade_gracefully(self) -> None:
        collector = NetworkDiagnosticsCollector(
            "10.210.1.12",
            sample_s=1.0,
            history_s=30.0,
            ping_timeout_s=0.1,
        )
        with mock.patch("crane_edge.network_diagnostics.shutil.which", return_value=None):
            sample = collector.collect_once()
        self.assertEqual("UNAVAILABLE", sample["status"])
        self.assertFalse(sample["route"]["available"])
        self.assertFalse(sample["ping"]["available"])
        self.assertEqual(1, len(collector.history()))
        self.assertGreaterEqual(collector.sample_s, 1.0)

    def test_critical_record_contains_prefailure_history(self) -> None:
        with tempfile.TemporaryDirectory() as temp_dir:
            diagnostics = CraneDiagnostics(
                "10.210.1.12",
                Path(temp_dir),
                enabled=False,
            )
            diagnostics.collector._history.append(
                {"timestamp": "before", "status": "HEALTHY", "ping": {"rtt_ms": 2.0}}
            )
            diagnostics.record_event(
                "WATCHDOG_CRITICAL",
                watchdog={"lock_wait_ms": 4.0, "write_duration_ms": 993.8},
                include_history=True,
            )
            diagnostics.stop()
            lines = diagnostics.recorder.path.read_text(encoding="utf-8").splitlines()
        self.assertEqual(1, len(lines))
        record = json.loads(lines[0])
        self.assertEqual("WATCHDOG_CRITICAL", record["event_type"])
        self.assertEqual("before", record["pre_failure_history"][0]["timestamp"])


if __name__ == "__main__":
    unittest.main()
