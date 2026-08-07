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


def load_watchdog_classes():
    """Load watchdog_session.py with asyncua stubs for static CI hosts."""
    saved = {name: sys.modules.get(name) for name in ("asyncua", "asyncua.sync")}
    asyncua = types.ModuleType("asyncua")
    asyncua_sync = types.ModuleType("asyncua.sync")
    asyncua_sync.Client = object

    class VariantType:
        Int16 = "Int16"

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
    sys.modules.update({"asyncua": asyncua, "asyncua.sync": asyncua_sync})
    try:
        path = Path(__file__).resolve().parents[1] / "crane_edge" / "watchdog_session.py"
        spec = importlib.util.spec_from_file_location("_watchdog_session_test", path)
        module = importlib.util.module_from_spec(spec)
        assert spec and spec.loader
        spec.loader.exec_module(module)
        return module.DedicatedWatchdogSession, module.WatchdogFeedGate
    finally:
        for name, previous in saved.items():
            if previous is None:
                sys.modules.pop(name, None)
            else:
                sys.modules[name] = previous


class FakeNode:
    def __init__(self, write_delay_s: float = 0.0, fail_write: bool = False) -> None:
        self.write_delay_s = write_delay_s
        self.fail_write = fail_write
        self.nodeid = "ns=5;s=test"

    def read_value(self) -> int:
        return 7

    def write_value(self, _value) -> None:
        time.sleep(self.write_delay_s)
        if self.fail_write:
            raise RuntimeError("write failed")


class FakeClient:
    def __init__(self, _endpoint: str, node: FakeNode | None = None) -> None:
        self.node = node or FakeNode()
        self.connected = False

    def connect(self) -> None:
        self.connected = True

    def disconnect(self) -> None:
        self.connected = False

    def get_node(self, _node_id: str) -> FakeNode:
        return self.node


class CraneIoTimingTests(unittest.TestCase):
    @staticmethod
    def make_crane():
        Crane = load_crane_class()
        crane = Crane.__new__(Crane)
        crane._io_lock = threading.RLock()
        crane._io_meta_lock = threading.RLock()
        crane._io_owner = None
        crane._io_owner_thread = None
        crane._io_owner_since_monotonic = None
        crane._io_reason_local = threading.local()
        crane._io_event_callback = None
        crane._session_connected = True
        crane._session_healthy = True
        crane._session_last_error = ""
        crane._latest_io_timing = {}
        crane._latest_slow_io = {}
        crane._latest_critical_io = {}
        crane._max_transaction_duration_ms = 0.0
        crane._max_total_duration_ms = 0.0
        crane._slow_warn_ms = 5.0
        crane._slow_critical_ms = 20.0
        crane._node_logical_names = {}
        crane.client = object()
        return crane

    def test_control_transaction_splits_lock_wait_from_operation(self) -> None:
        crane = self.make_crane()
        node = FakeNode(write_delay_s=0.008)
        crane._node_logical_names[id(node)] = "trolley_forward"

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
        timing = crane._write_node(
            node,
            object(),
            reason="stop_all",
        )
        holder.join(timeout=1.0)
        releaser.join(timeout=1.0)

        self.assertFalse(holder.is_alive())
        self.assertGreaterEqual(timing["lock_wait_ms"], 15.0)
        self.assertGreaterEqual(timing["transaction_duration_ms"], 5.0)
        self.assertEqual("stop_all", timing["owner"])
        self.assertEqual("write", timing["operation"])
        self.assertEqual("trolley_forward", timing["logical_node"])
        self.assertEqual("move_xy", timing["lock_owner_at_request"])
        self.assertGreater(
            timing["total_duration_ms"],
            timing["transaction_duration_ms"],
        )

    def test_stop_all_control_lock_cannot_block_dedicated_watchdog(self) -> None:
        DedicatedWatchdogSession, _ = load_watchdog_classes()
        crane = self.make_crane()
        holder_started = threading.Event()
        release_holder = threading.Event()

        def hold_control() -> None:
            crane._run_io(
                "stop_all",
                "write",
                lambda: (holder_started.set(), release_holder.wait(timeout=1.0)),
                logical_name="hoist_down",
            )

        holder = threading.Thread(target=hold_control)
        holder.start()
        self.assertTrue(holder_started.wait(timeout=1.0))
        watchdog_client = FakeClient("opc.tcp://test", FakeNode(write_delay_s=0.006))
        watchdog = DedicatedWatchdogSession(
            "opc.tcp://test",
            client_factory=lambda _endpoint: watchdog_client,
        )
        watchdog.connect()
        started = time.monotonic()
        timing = watchdog.write_next(started, started)
        elapsed = time.monotonic() - started
        release_holder.set()
        holder.join(timeout=1.0)
        self.assertLess(elapsed, 0.1)
        self.assertIsNone(timing["watchdog_lock_wait_ms"])
        self.assertEqual(0.0, timing["control_lock_wait_ms"])
        self.assertEqual("dedicated_watchdog", timing["session_architecture"])

    def test_control_transaction_diagnostics_never_include_written_value(self) -> None:
        crane = self.make_crane()
        node = FakeNode()
        crane._node_logical_names[id(node)] = "access_code"
        secret = "credential-should-never-be-logged"
        timing = crane._write_node(node, secret, reason="configuration")
        encoded = json.dumps(timing)
        self.assertNotIn(secret, encoded)
        self.assertEqual("access_code", timing["logical_node"])

    def test_control_transaction_exception_marks_session_lost(self) -> None:
        crane = self.make_crane()
        node = FakeNode(fail_write=True)
        crane._node_logical_names[id(node)] = "bridge_speed"
        observed = []
        crane.set_io_event_callback(observed.append)
        with self.assertRaises(RuntimeError):
            crane._write_node(node, object(), reason="move_xy")
        self.assertEqual("LOST", crane.io_snapshot()["session_status"])
        self.assertEqual("RuntimeError", observed[-1]["exception_type"])
        self.assertEqual("bridge_speed", observed[-1]["logical_node"])


class DedicatedWatchdogSessionTests(unittest.TestCase):
    def test_watchdog_uses_a_distinct_client_and_has_independent_state(self) -> None:
        DedicatedWatchdogSession, _ = load_watchdog_classes()
        crane = CraneIoTimingTests.make_crane()
        control_client = crane.client
        watchdog_client = FakeClient("opc.tcp://test")
        watchdog = DedicatedWatchdogSession(
            "opc.tcp://test",
            client_factory=lambda _endpoint: watchdog_client,
        )
        watchdog.connect()
        self.assertIsNot(control_client, watchdog.client)
        self.assertEqual("CONNECTED", watchdog.snapshot()["status"])
        crane._session_healthy = False
        self.assertEqual("LOST", crane.io_snapshot()["session_status"])
        self.assertEqual("CONNECTED", watchdog.snapshot()["status"])
        watchdog.disconnect()
        self.assertEqual("LOST", watchdog.snapshot()["status"])

    def test_control_loss_permanently_disables_watchdog_feed(self) -> None:
        _, WatchdogFeedGate = load_watchdog_classes()
        gate = WatchdogFeedGate(guard_timeout_s=1.0)
        gate.mark_control_connected()
        gate.note_guard_heartbeat("test_guard")
        self.assertTrue(gate.can_feed())
        gate.mark_control_lost("control transport failed")
        self.assertFalse(gate.can_feed())
        gate.mark_control_connected()
        gate.note_guard_heartbeat("test_guard")
        self.assertFalse(gate.can_feed())

    def test_expired_controller_guard_disables_feed(self) -> None:
        _, WatchdogFeedGate = load_watchdog_classes()
        gate = WatchdogFeedGate(guard_timeout_s=0.25)
        gate.mark_control_connected()
        gate.note_guard_heartbeat("test_guard")
        gate._guard_last_monotonic = time.monotonic() - 1.0
        self.assertFalse(gate.can_feed())
        self.assertIn("guard heartbeat expired", gate.snapshot()["fatal_reason"])

    def test_watchdog_write_loss_is_independently_observable(self) -> None:
        DedicatedWatchdogSession, _ = load_watchdog_classes()
        node = FakeNode(fail_write=True)
        watchdog = DedicatedWatchdogSession(
            "opc.tcp://test",
            client_factory=lambda endpoint: FakeClient(endpoint, node),
        )
        watchdog.connect()
        now = time.monotonic()
        with self.assertRaises(RuntimeError):
            watchdog.write_next(now, now)
        self.assertEqual("LOST", watchdog.snapshot()["status"])


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
            diagnostics.set_context_provider(
                lambda: {"order_id": "order-1", "action_id": "action-7"}
            )
            diagnostics.collector._history.append(
                {"timestamp": "before", "status": "HEALTHY", "ping": {"rtt_ms": 2.0}}
            )
            diagnostics.record_event(
                "OPCUA_CRITICAL_TRANSACTION",
                watchdog={"write_duration_ms": 12.0},
                extra={
                    "owner": "stop_all",
                    "operation": "write",
                    "logical_node": "hoist_down",
                    "transaction_duration_ms": 938.2,
                },
                include_history=True,
            )
            diagnostics.stop()
            lines = diagnostics.recorder.path.read_text(encoding="utf-8").splitlines()
        self.assertEqual(1, len(lines))
        record = json.loads(lines[0])
        self.assertEqual("OPCUA_CRITICAL_TRANSACTION", record["event_type"])
        self.assertEqual("before", record["pre_failure_history"][0]["timestamp"])
        self.assertEqual("stop_all", record["details"]["owner"])
        self.assertEqual("order-1", record["context"]["order_id"])
        self.assertEqual("action-7", record["context"]["action_id"])
        self.assertNotIn("access_code_value", json.dumps(record))


if __name__ == "__main__":
    unittest.main()
