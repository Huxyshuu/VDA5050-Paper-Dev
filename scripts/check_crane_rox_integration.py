#!/usr/bin/env python3
"""Fail-closed consistency check for the crane + ROX-Diff handover."""
from __future__ import annotations

import argparse
import json
import os
import re
from pathlib import Path
from typing import Any, Dict, Iterable, Tuple

import jsonschema
import yaml

REPO_ROOT = Path(__file__).resolve().parents[1]


def load_env(path: Path) -> Dict[str, str]:
    result: Dict[str, str] = {}
    for raw in path.read_text(encoding="utf-8").splitlines():
        line = raw.strip()
        if not line or line.startswith("#") or "=" not in line:
            continue
        key, value = line.split("=", 1)
        result[key.strip()] = value.strip()
    return result


def actions(order: Dict[str, Any]) -> Iterable[Tuple[str, str, str]]:
    for node in order.get("nodes", []):
        for item in node.get("actions", []):
            yield str(node.get("nodeId")), str(item.get("actionId")), str(item.get("actionType"))


def fail(errors: list[str], message: str) -> None:
    errors.append(message)


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--env", type=Path, default=REPO_ROOT / "configs" / "fleet_control.env")
    parser.add_argument("--crane-waypoints", type=Path, default=REPO_ROOT / "configs" / "crane_waypoints.yaml")
    parser.add_argument("--crane-order", type=Path, default=REPO_ROOT / "examples" / "orders" / "order_ilmatar_v3.json")
    parser.add_argument("--rox-order", type=Path, default=REPO_ROOT / "examples" / "orders" / "order_rox_diff_v3.json")
    parser.add_argument("--schema", type=Path, default=REPO_ROOT / "schemas" / "vda5050_v3" / "order.schema")
    parser.add_argument("--allow-disabled", action="store_true")
    parser.add_argument(
        "--allow-unconfigured",
        action="store_true",
        help="Check structural order consistency without requiring physical crane verification",
    )
    args = parser.parse_args()

    env = load_env(args.env)
    cfg = yaml.safe_load(args.crane_waypoints.read_text(encoding="utf-8")) or {}
    crane = json.loads(args.crane_order.read_text(encoding="utf-8"))
    rox = json.loads(args.rox_order.read_text(encoding="utf-8"))
    schema = json.loads(args.schema.read_text(encoding="utf-8"))
    validator = jsonschema.Draft202012Validator(schema, format_checker=jsonschema.FormatChecker())
    errors: list[str] = []
    for label, order in (("crane", crane), ("rox", rox)):
        for err in validator.iter_errors(order):
            fail(errors, f"{label} order schema: {err.message}")

    if not bool(cfg.get("configured", False)) and not args.allow_unconfigured:
        fail(errors, "configs/crane_waypoints.yaml is not verified (configured: false)")
    if not args.allow_disabled and env.get("CRANE_ENABLED", "false").lower() not in {"1", "true", "yes", "on"}:
        fail(errors, "CRANE_ENABLED is not true")

    expected_crane_map = env.get("CRANE_MAP_ID", str(cfg.get("map_id", "map")))
    for node in crane.get("nodes", []):
        actual = str((node.get("nodePosition") or {}).get("mapId", ""))
        if actual != expected_crane_map:
            fail(errors, f"Crane node {node.get('nodeId')} mapId={actual!r}, expected {expected_crane_map!r}")
    expected_rox_map = env.get("VDA_DEFAULT_MAP_ID", "df_map")
    for node in rox.get("nodes", []):
        actual = str((node.get("nodePosition") or {}).get("mapId", ""))
        if actual != expected_rox_map:
            fail(errors, f"ROX node {node.get('nodeId')} mapId={actual!r}, expected {expected_rox_map!r}")

    crane_actions = {(node, aid): atype for node, aid, atype in actions(crane)}
    rox_actions = {(node, aid): atype for node, aid, atype in actions(rox)}
    crane_node = env.get("CRANE_HANDOVER_NODE_ID", "node2")
    rox_node = env.get("ROX_HANDOVER_NODE_ID", "node2")
    expected = [
        (crane_node, env.get("CRANE_AUTO_RELEASE_ACTION_ID", "action4"), "buttonPress"),
        (crane_node, env.get("CRANE_MANUAL_RELEASE_ACTION_ID", "action6"), "buttonPress"),
        (crane_node, env.get("CRANE_SAFE_LIFT_ACTION_ID", "action7"), "raiseHoist"),
    ]
    for node, aid, atype in expected:
        if crane_actions.get((node, aid)) != atype:
            fail(errors, f"Crane order missing {atype} {aid!r} on {node!r}")
    hold_id = env.get("ROX_HOLD_ACTION_ID", "rox_hold_at_crane")
    if rox_actions.get((rox_node, hold_id)) != "holdPose":
        fail(errors, f"ROX order missing holdPose {hold_id!r} on {rox_node!r}")

    if len(rox.get("nodes", [])) < 4 or str(rox.get("nodes", [{}])[-1].get("nodeId")) != "node4":
        fail(errors, "ROX order is not the full crane-case-study route ending at node4")
    if len(crane.get("edges", [])) != max(len(crane.get("nodes", [])) - 1, 0):
        fail(errors, "Crane node/edge count is inconsistent")
    if len(rox.get("edges", [])) != max(len(rox.get("nodes", [])) - 1, 0):
        fail(errors, "ROX node/edge count is inconsistent")

    wp = cfg.get("waypoints", {})
    by_id = {str(n.get("nodeId")): n for n in crane.get("nodes", [])}
    comparisons = {
        str(cfg.get("coordination", {}).get("source_node_id", "node1")): wp.get("source_station", {}),
        str(cfg.get("coordination", {}).get("handover_node_id", "node2")): wp.get("rox_handover", {}),
    }
    for node_id, expected_wp in comparisons.items():
        node = by_id.get(node_id, {})
        pos = node.get("nodePosition", {})
        for axis, key in (("x", "bridge_m"), ("y", "trolley_m")):
            try:
                if abs(float(pos[axis]) - float(expected_wp[key])) > 0.0005:
                    fail(errors, f"Crane order {node_id} {axis} does not match crane waypoint {key}")
            except (KeyError, TypeError, ValueError):
                fail(errors, f"Cannot compare crane order {node_id} with waypoint field {key}")

    if errors:
        print("INTEGRATION CHECK FAILED")
        for item in errors:
            print(f"  - {item}")
        return 1
    print("INTEGRATION CHECK PASSED")
    print(f"  crane map={expected_crane_map}; ROX map={expected_rox_map}")
    print(f"  rendezvous: crane {crane_node} ↔ ROX {rox_node}")
    print(f"  release chain: {expected[0][1]} → {expected[1][1]} → {expected[2][1]} → {hold_id}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
