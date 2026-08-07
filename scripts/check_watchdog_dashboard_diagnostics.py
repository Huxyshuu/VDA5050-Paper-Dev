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
    network = (ROOT / "crane_edge/network_diagnostics.py").read_text(encoding="utf-8")
    dashboard = (ROOT / "fleet_control/dashboard_v3.py").read_text(encoding="utf-8")
    scenario = (ROOT / "fleet_control/sequential_cell_scenario.py").read_text(encoding="utf-8")
    html = (ROOT / "fleet_control/templates/index.html").read_text(encoding="utf-8")
    env_example = (ROOT / "configs/fleet_control.env.example").read_text(encoding="utf-8")

    check("self._io_lock = threading.RLock()" in crane, "OPC UA session access is serialized")
    check("self._watchdog_priority" in crane, "watchdog writes receive I/O priority")
    for field in (
        "scheduled_deadline_monotonic",
        "attempt_started_monotonic",
        "lock_requested_monotonic",
        "lock_acquired_monotonic",
        "write_started_monotonic",
        "write_finished_monotonic",
        "watchdog_lock_wait_ms",
        "watchdog_write_duration_ms",
        "watchdog_schedule_lateness_ms",
    ):
        check(field in crane, f"watchdog I/O captures {field}")
    check("lock_owner_at_request" in crane and "io_snapshot" in crane, "OPC UA lock owner is visible")

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
    check("class WatchdogHealth" in adapter, "watchdog timing health is recorded")
    check("next_deadline += WATCHDOG_INTERVAL_S" in adapter, "watchdog uses monotonic deadline scheduling")
    check("WATCHDOG_HEALTH" in adapter, "watchdog health is published in VDA information")
    check("CRANE_MOTION_HEALTH" in adapter, "motion health is published in VDA information")
    check("CRANE_MOTION_STALLED" in adapter, "true motion stalls fail closed")
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
