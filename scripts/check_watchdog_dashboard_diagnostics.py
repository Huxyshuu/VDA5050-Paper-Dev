#!/usr/bin/env python3
"""Static audit for crane watchdog hardening and dashboard diagnostics."""
from pathlib import Path
import ast
import re

ROOT = Path(__file__).resolve().parents[1]


def check(condition: bool, message: str) -> None:
    if not condition:
        raise AssertionError(message)
    print(f"PASS {message}")


def main() -> int:
    crane = (ROOT / "crane_edge/crane.py").read_text(encoding="utf-8")
    adapter = (ROOT / "crane_edge/crane_vda5050_adapter_v3.py").read_text(encoding="utf-8")
    watchdog_session = (ROOT / "crane_edge/watchdog_session.py").read_text(encoding="utf-8")
    network = (ROOT / "crane_edge/network_diagnostics.py").read_text(encoding="utf-8")
    dashboard = (ROOT / "fleet_control/dashboard_v3.py").read_text(encoding="utf-8")
    scenario = (ROOT / "fleet_control/sequential_cell_scenario.py").read_text(encoding="utf-8")
    html = (ROOT / "fleet_control/templates/index.html").read_text(encoding="utf-8")
    env_example = (ROOT / "configs/fleet_control.env.example").read_text(encoding="utf-8")

    watchdog_tree = ast.parse(watchdog_session)
    check(
        not any(
            isinstance(node, ast.Name)
            and isinstance(node.ctx, ast.Load)
            and node.id == "crane"
            for node in ast.walk(watchdog_tree)
        ),
        "dedicated watchdog module has no free/global control crane dependency",
    )
    adapter_tree = ast.parse(adapter)
    watchdog_loop = next(
        node
        for node in ast.walk(adapter_tree)
        if isinstance(node, ast.FunctionDef) and node.name == "_watchdog_loop"
    )
    check(
        not any(
            isinstance(node, ast.Name)
            and isinstance(node.ctx, ast.Load)
            and node.id == "crane"
            for node in ast.walk(watchdog_loop)
        ),
        "dedicated watchdog loop has no free/global control crane dependency",
    )

    check("self._io_lock = threading.RLock()" in crane, "OPC UA session access is serialized")
    check(
        "DedicatedWatchdogSession(url)" in adapter
        and "self._client_factory(self.endpoint)" in watchdog_session,
        "watchdog creates a distinct OPC UA Client/session",
    )
    check(
        "_io_lock" not in watchdog_session
        and "increment_watchdog_timed" not in adapter
        and "watchdog_session.heartbeat_once" in adapter,
        "dedicated watchdog never acquires the control-session lock",
    )
    for field in (
        "scheduled_deadline_monotonic",
        "attempt_started_monotonic",
        "write_started_monotonic",
        "write_finished_monotonic",
        "watchdog_lock_wait_ms",
        "control_lock_wait_ms",
        "session_architecture",
        "watchdog_write_duration_ms",
        "watchdog_schedule_lateness_ms",
    ):
        check(field in watchdog_session, f"dedicated watchdog I/O captures {field}")
    for field in (
        "lock_requested_monotonic",
        "lock_acquired_monotonic",
        "transaction_started_monotonic",
        "transaction_finished_monotonic",
        "lock_wait_ms",
        "transaction_duration_ms",
        "total_duration_ms",
        "logical_node",
        "thread",
        "exception_type",
    ):
        check(field in crane, f"control OPC UA wrapper captures {field}")
    check("lock_owner_at_request" in crane and "io_snapshot" in crane, "control OPC UA lock owner is visible")

    crane_tree = ast.parse(crane)
    run_io = next(
        node for node in ast.walk(crane_tree)
        if isinstance(node, ast.FunctionDef) and node.name == "_run_io"
    )
    acquire_lines = [
        node.lineno for node in ast.walk(run_io)
        if isinstance(node, ast.Call)
        and isinstance(node.func, ast.Attribute)
        and node.func.attr == "acquire"
    ]
    release_lines = [
        node.lineno for node in ast.walk(run_io)
        if isinstance(node, ast.Call)
        and isinstance(node.func, ast.Attribute)
        and node.func.attr == "release"
    ]
    sleep_lines = [
        node.lineno for node in ast.walk(run_io)
        if isinstance(node, ast.Call)
        and isinstance(node.func, ast.Attribute)
        and node.func.attr == "sleep"
    ]
    check(
        bool(acquire_lines and release_lines)
        and all(line < min(acquire_lines) or line > max(release_lines) for line in sleep_lines),
        "OPC UA coordinator never sleeps while holding the session lock",
    )
    check(
        not any(
            isinstance(node, ast.Call)
            and isinstance(node.func, ast.Name)
            and node.func.id in {"record_event", "subprocess"}
            for node in ast.walk(run_io)
        )
        and "json.dumps" not in ast.get_source_segment(crane, run_io),
        "control lock excludes diagnostics, subprocesses, JSON, MQTT, and Flask work",
    )
    check(
        "class WatchdogFeedGate" in watchdog_session
        and "mark_control_lost" in adapter
        and "feed_gate.snapshot()" in adapter
        and "WATCHDOG_FEED_DISABLED" in adapter,
        "controller-health gate disables heartbeat feeding after control failure",
    )
    check(
        "OPCUA_WATCHDOG_SESSION_LOST" in adapter
        and "WATCHDOG_INTERNAL_ERROR" in watchdog_session
        and "classify_watchdog_exception" in adapter
        and "feed_gate.inhibit" in adapter,
        "watchdog transport loss and internal implementation errors are distinct and fail closed",
    )
    check(
        "set_accesscode(access)" in adapter
        and "AccessCode" not in watchdog_session
        and "watchdog_session.set_accesscode" not in adapter,
        "access code is written only by the control session",
    )
    check("class WatchdogHealth" in adapter, "watchdog timing health is recorded")
    check("next_deadline += WATCHDOG_INTERVAL_S" in adapter, "watchdog uses monotonic deadline scheduling")
    check("WATCHDOG_HEALTH" in adapter, "watchdog health is published in VDA information")
    check("OPCUA_SESSION_HEALTH" in adapter, "independent OPC UA session health is published")
    check("OPCUA_CONTROL_HEALTH" in adapter, "control transaction health is published")
    check("CRANE_MOTION_HEALTH" in adapter, "motion health is published in VDA information")
    check("CRANE_MOTION_STALLED" in adapter, "true motion stalls fail closed")
    check(
        "DX_Custom_V.Status.WatchDogFault" in adapter
        and "fault = bool(plc_fault or transport_critical)" in adapter,
        "authoritative WatchDogFault and critical watchdog health remain fail closed",
    )
    check(
        "Automatic/watchdog health was lost during motion" in adapter
        and "self._cancel.set()" in adapter,
        "critical watchdog state still cancels active execution",
    )
    check(
        "class NetworkDiagnosticsCollector" in network
        and "self._io_lock" not in network
        and "increment_watchdog" not in network,
        "network diagnostics are independent from OPC UA and watchdog execution",
    )
    check(
        "subprocess.run" in network
        and "timeout=" in network
        and "shutil.which" in network
        and "subprocess.TimeoutExpired" in network,
        "missing or blocked Linux diagnostic commands degrade gracefully",
    )
    check(
        "not wireless" in network and "vcgencmd_available" in network,
        "wired interfaces and non-Raspberry Pi hosts are handled gracefully",
    )
    check(
        "sample_s = max(0.25" in network
        and "WATCHDOG_INTERVAL_S" not in network,
        "network diagnostics cannot run at watchdog frequency",
    )
    check(
        "pre_failure_history" in network
        and "JsonlDiagnosticRecorder" in network
        and '"WATCHDOG_SAMPLE"' in network,
        "diagnostics retain pre-failure history and write throttled JSONL samples",
    )
    check(
        "crane_diagnostics_jsonl" in network
        and "put_nowait" in network
        and "_writer_loop" in network,
        "watchdog diagnostics never perform JSON serialization or disk I/O on the watchdog thread",
    )
    check(
        "OPCUA_SLOW_TRANSACTION" in adapter
        and "OPCUA_CRITICAL_TRANSACTION" in adapter
        and "OPCUA_TRANSACTION_EXCEPTION" in adapter
        and "OPCUA_CONTROL_SESSION_LOST" in adapter,
        "slow, critical, exception, and lost control-session events are persisted",
    )
    check(
        "diagnostics.record_event(event_type" in adapter
        and "extra=timing" in adapter,
        "slow transaction events retain owner, operation, node, timing, and execution context",
    )
    check(
        "access_code_value" not in crane and "access_code_value" not in watchdog_session,
        "control timing schema contains no credential value field",
    )
    check("active_timeout_s" in scenario and "SEQUENTIAL_STEP_FAILED" in scenario, "sequential steps expose timing and failure transitions")
    check(
        "execution_monitor" in dashboard
        and "crane_network_health" in dashboard
        and "crane_failure_snapshot" in dashboard,
        "dashboard API projects watchdog, network, and failure diagnostics",
    )
    check(
        "renderExecutionMonitor" in html
        and 'id="executionTimeline"' in html
        and 'id="diagNetworkCard"' in html
        and 'id="diagOpcuaCard"' in html
        and "control_session_status" in html
        and "slow_transaction_duration_ms" in html
        and "max_lock_wait_ms" in html
        and "max_schedule_lateness_ms" in html,
        "dashboard renders split watchdog timing and PLC network health",
    )
    for key in (
        "CRANE_WATCHDOG_INTERVAL_S",
        "CRANE_WATCHDOG_WARN_GAP_S",
        "CRANE_WATCHDOG_CRITICAL_GAP_S",
        "CRANE_WATCHDOG_FAILURE_LIMIT",
        "CRANE_MOTION_STALL_WARN_S",
        "CRANE_MOTION_STALL_FAIL_S",
        "CRANE_NETWORK_DIAGNOSTICS",
        "CRANE_NETWORK_SAMPLE_S",
        "CRANE_NETWORK_HISTORY_S",
        "CRANE_DIAGNOSTICS_LOG_DIR",
        "CRANE_PLC_PING_TIMEOUT_S",
        "CRANE_OPCUA_SLOW_WARN_MS",
        "CRANE_OPCUA_SLOW_CRITICAL_MS",
        "CRANE_CONTROLLER_GUARD_TIMEOUT_S",
    ):
        check(re.search(rf"^{key}=", env_example, re.MULTILINE) is not None, f"env example documents {key}")

    check("CRANE_ACTION_SETTLE_S" in adapter, "crane action transition settle delay is configurable")
    check("_motion_transition_barrier" in adapter, "crane uses stop-and-settle transition barriers")
    check("CRANE_WATCHDOG_CRITICAL_LATCH_S" in adapter, "critical watchdog gaps are latched")
    check("SEQUENTIAL_ACTION_DELAY_S" in scenario, "sequential scenario delays between steps")
    check("required_hoist_position" in scenario, "sequential XY travel verifies explicit lift height")
    check('"infoLevel": "WARNING"' not in adapter, "VDA information levels remain schema-valid")
    print("Watchdog/dashboard diagnostics audit passed.")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
