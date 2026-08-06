#!/usr/bin/env python3
"""Static audit for crane watchdog hardening and dashboard diagnostics."""
from pathlib import Path
import re

ROOT = Path(__file__).resolve().parents[1]


def check(condition: bool, message: str) -> None:
    if not condition:
        raise AssertionError(message)
    print(f"PASS {message}")


def main() -> int:
    crane = (ROOT / "crane_edge/crane.py").read_text(encoding="utf-8")
    adapter = (ROOT / "crane_edge/crane_vda5050_adapter_v3.py").read_text(encoding="utf-8")
    dashboard = (ROOT / "fleet_control/dashboard_v3.py").read_text(encoding="utf-8")
    scenario = (ROOT / "fleet_control/sequential_cell_scenario.py").read_text(encoding="utf-8")
    html = (ROOT / "fleet_control/templates/index.html").read_text(encoding="utf-8")
    env_example = (ROOT / "configs/fleet_control.env.example").read_text(encoding="utf-8")

    check("self._io_lock = threading.RLock()" in crane, "OPC UA session access is serialized")
    check("self._watchdog_priority" in crane, "watchdog writes receive I/O priority")
    check("class WatchdogHealth" in adapter, "watchdog timing health is recorded")
    check("next_deadline += WATCHDOG_INTERVAL_S" in adapter, "watchdog uses monotonic deadline scheduling")
    check("WATCHDOG_HEALTH" in adapter, "watchdog health is published in VDA information")
    check("CRANE_MOTION_HEALTH" in adapter, "motion health is published in VDA information")
    check("CRANE_MOTION_STALLED" in adapter, "true motion stalls fail closed")
    check("active_timeout_s" in scenario and "SEQUENTIAL_STEP_FAILED" in scenario, "sequential steps expose timing and failure transitions")
    check("execution_monitor" in dashboard, "dashboard API projects execution diagnostics")
    check("renderExecutionMonitor" in html and 'id="executionTimeline"' in html, "dashboard renders watchdog, motion, and step timeline")
    for key in (
        "CRANE_WATCHDOG_INTERVAL_S",
        "CRANE_WATCHDOG_WARN_GAP_S",
        "CRANE_WATCHDOG_CRITICAL_GAP_S",
        "CRANE_WATCHDOG_FAILURE_LIMIT",
        "CRANE_MOTION_STALL_WARN_S",
        "CRANE_MOTION_STALL_FAIL_S",
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
