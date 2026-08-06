#!/usr/bin/env python3
"""Static audit for the sequential crane–ROX pickup/delivery scenario."""
from __future__ import annotations

from pathlib import Path
from typing import Any, Mapping

import yaml

ROOT = Path(__file__).resolve().parents[1]
EXPECTED_IDS = [
    "crane_home_start",
    "rox_home_start",
    "rox_to_handover",
    "crane_to_source",
    "crane_lower_source",
    "confirm_source_pickup",
    "crane_raise_source",
    "crane_to_handover",
    "crane_lower_handover",
    "confirm_handover_release",
    "crane_raise_handover",
    "rox_to_warehouse",
    "confirm_human_unload",
    "rox_home_finish",
    "crane_home_finish",
]


def require(condition: bool, message: str) -> None:
    if not condition:
        raise AssertionError(message)
    print(f"PASS {message}")


def load_yaml(path: Path) -> Mapping[str, Any]:
    data = yaml.safe_load(path.read_text(encoding="utf-8")) or {}
    if not isinstance(data, Mapping):
        raise AssertionError(f"{path} root must be a mapping")
    return data


def main() -> int:
    scenarios = load_yaml(ROOT / "configs/dashboard_scenarios.yaml")
    scenario = (scenarios.get("scenarios") or {}).get("sequential_pickup_delivery") or {}
    steps = scenario.get("steps") or []
    require(scenario.get("target") == "sequential_cell", "scenario uses sequential_cell engine")
    require([str(step.get("id")) for step in steps] == EXPECTED_IDS, "scenario step order is exact")
    require(len({str(step.get("id")) for step in steps}) == len(steps), "scenario step IDs are unique")

    rox = load_yaml(ROOT / "configs/rox_waypoints.yaml")
    crane = load_yaml(ROOT / "configs/crane_waypoints.yaml")
    rox_names = set((rox.get("waypoints") or {}).keys())
    crane_names = set((crane.get("waypoints") or {}).keys())
    hoist_names = set((crane.get("hoist_positions") or {}).keys())

    for step in steps:
        command = str(step.get("command"))
        if command == "rox_waypoint":
            require(str(step.get("waypoint")) in rox_names, f"ROX waypoint exists: {step.get('waypoint')}")
        elif command == "crane_waypoint":
            require(str(step.get("waypoint")) in crane_names, f"crane waypoint exists: {step.get('waypoint')}")
        elif command == "crane_hoist":
            require(str(step.get("position")) in hoist_names, f"crane hoist position exists: {step.get('position')}")

    require(
        sum(str(step.get("command")) == "operator_confirm" for step in steps) == 3,
        "three operator confirmation gates protect unsensed load-transfer steps",
    )
    confirmation = scenario.get("operator_confirmation") or {}
    require(
        confirmation.get("default_mode") == "manual",
        "manual confirmation remains the fail-safe default",
    )
    require(
        float(confirmation.get("timeout_s", 0)) == 5.0,
        "optional timed confirmation uses a five-second delay",
    )
    require(
        (ROOT / "fleet_control/sequential_cell_scenario.py").exists(),
        "sequential scenario engine is installed",
    )
    dashboard = (ROOT / "fleet_control/dashboard_v3.py").read_text(encoding="utf-8")
    engine = (ROOT / "fleet_control/sequential_cell_scenario.py").read_text(encoding="utf-8")
    template = (ROOT / "fleet_control/templates/index.html").read_text(encoding="utf-8")
    require('target_type == "sequential_cell"' in dashboard, "dashboard starts sequential cell scenarios")
    require('payload.get("confirmation_mode")' in dashboard, "scenario start API accepts confirmation mode")
    require('/api/scenarios/active/confirm' in dashboard, "operator confirmation API is registered")
    require('id="confirmScenarioStepBtn"' in template, "dashboard confirmation button is present")
    require('name="scenarioConfirmationMode"' in template, "dashboard start modal offers confirmation modes")
    require(
        "expected_run_id" in dashboard
        and "requires a non-empty run_id" in dashboard
        and "requires a non-empty step_id" in dashboard
        and "run_id:runId,step_id:stepId" in template,
        "manual confirmation is bound to the displayed run and step",
    )
    require('SEQUENTIAL_OPERATOR_AUTO_CONFIRMED' in engine, "timed confirmations are explicitly audited")
    print("Sequential pickup/delivery scenario audit passed.")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
