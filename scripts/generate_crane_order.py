#!/usr/bin/env python3
"""Generate the Ilmatar VDA 5050 v3 order from verified crane-local waypoints."""
from __future__ import annotations

import argparse
import json
import math
import re
from datetime import datetime, timezone
from pathlib import Path
from typing import Any, Dict

import jsonschema
import yaml

REPO_ROOT = Path(__file__).resolve().parents[1]


def utc_now() -> str:
    return datetime.now(timezone.utc).isoformat(timespec="milliseconds").replace("+00:00", "Z")


def load_config(path: Path) -> Dict[str, Any]:
    data = yaml.safe_load(path.read_text(encoding="utf-8")) or {}
    if not isinstance(data, dict):
        raise ValueError("Crane waypoint YAML root must be an object")
    if not data.get("configured", False):
        raise ValueError(
            f"{path} is not verified (configured: false). Capture, physically check, and independently test every position first."
        )
    for section in ("waypoints", "hoist_positions", "home", "coordination"):
        if not isinstance(data.get(section), dict):
            raise ValueError(f"Missing mapping: {section}")
    return data


def finite_number(mapping: Dict[str, Any], key: str) -> float:
    try:
        value = float(mapping[key])
    except (KeyError, TypeError, ValueError) as exc:
        raise ValueError(f"Missing or invalid numeric value {key!r}") from exc
    if not math.isfinite(value):
        raise ValueError(f"Non-finite value {key!r}")
    return value


def action(action_id: str, action_type: str, blocking: str, key: str | None = None, value: float | None = None) -> Dict[str, Any]:
    item: Dict[str, Any] = {
        "actionId": action_id,
        "actionType": action_type,
        "blockingType": blocking,
        "actionParameters": [],
    }
    if key is not None:
        item["actionParameters"] = [{"key": key, "value": value}]
    return item


def build_order(cfg: Dict[str, Any]) -> Dict[str, Any]:
    wp = cfg["waypoints"]
    hoist = cfg["hoist_positions"]
    ids = cfg["coordination"]
    source = wp["source_station"]
    handover = wp["rox_handover"]
    map_id = str(cfg.get("map_id", "map"))

    nodes = [
        {
            "nodeId": str(ids["source_node_id"]),
            "sequenceId": 0,
            "released": True,
            "nodeDescriptor": "Crane source / pickup station",
            "nodePosition": {
                "x": finite_number(source, "bridge_m"),
                "y": finite_number(source, "trolley_m"),
                "mapId": map_id,
            },
            "actions": [
                action(str(ids["source_lower_action_id"]), "lowerHoist", "SOFT", "zd", finite_number(hoist, "source_lower_m")),
                action(str(ids["source_wait_action_id"]), "buttonPress", "HARD"),
                action(str(ids["source_raise_action_id"]), "raiseHoist", "SOFT", "zu", finite_number(hoist, "source_safe_lift_m")),
            ],
        },
        {
            "nodeId": str(ids["handover_node_id"]),
            "sequenceId": 2,
            "released": True,
            "nodeDescriptor": "Crane and ROX-Diff handover rendezvous",
            "nodePosition": {
                "x": finite_number(handover, "bridge_m"),
                "y": finite_number(handover, "trolley_m"),
                "mapId": map_id,
            },
            "actions": [
                action(str(ids["automatic_release_action_id"]), "buttonPress", "HARD"),
                action(str(ids["handover_lower_action_id"]), "lowerHoist", "SOFT", "zd", finite_number(hoist, "handover_lower_m")),
                action(str(ids["manual_release_action_id"]), "buttonPress", "HARD"),
                action(str(ids["safe_lift_action_id"]), "raiseHoist", "SOFT", "zu", finite_number(hoist, "handover_safe_lift_m")),
            ],
        },
        {
            "nodeId": str(ids["return_node_id"]),
            "sequenceId": 4,
            "released": True,
            "nodeDescriptor": "Return to crane source station",
            "nodePosition": {
                "x": finite_number(source, "bridge_m"),
                "y": finite_number(source, "trolley_m"),
                "mapId": map_id,
            },
            "actions": [],
        },
    ]
    return {
        "headerId": 0,
        "timestamp": utc_now(),
        "version": "3.0.0",
        "manufacturer": "konecranes",
        "serialNumber": "ilmatar_1",
        "orderId": "template-ilmatar-crane-calibrated",
        "orderUpdateId": 0,
        "orderDescription": "Ilmatar source-to-ROX handover order generated from verified crane-local coordinates",
        "nodes": nodes,
        "edges": [
            {"edgeId": "edge1", "sequenceId": 1, "released": True, "edgeDescriptor": "Source to handover", "actions": []},
            {"edgeId": "edge2", "sequenceId": 3, "released": True, "edgeDescriptor": "Handover to source", "actions": []},
        ],
    }


def update_env(path: Path, values: Dict[str, str]) -> None:
    text = path.read_text(encoding="utf-8") if path.exists() else ""
    for key, value in values.items():
        pattern = re.compile(rf"(?m)^{re.escape(key)}=.*$")
        line = f"{key}={value}"
        if pattern.search(text):
            text = pattern.sub(line, text)
        else:
            if text and not text.endswith("\n"):
                text += "\n"
            text += line + "\n"
    path.write_text(text, encoding="utf-8")


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--waypoints", type=Path, default=REPO_ROOT / "configs" / "crane_waypoints.yaml")
    parser.add_argument("--output", type=Path, default=REPO_ROOT / "examples" / "orders" / "order_ilmatar_v3.json")
    parser.add_argument("--schema", type=Path, default=REPO_ROOT / "schemas" / "vda5050_v3" / "order.schema")
    parser.add_argument("--update-fleet-env", type=Path)
    parser.add_argument("--enable-crane", action="store_true", help="Set CRANE_ENABLED=true in the selected fleet env after successful generation")
    args = parser.parse_args()

    cfg = load_config(args.waypoints)
    order = build_order(cfg)
    schema = json.loads(args.schema.read_text(encoding="utf-8"))
    jsonschema.Draft202012Validator(schema, format_checker=jsonschema.FormatChecker()).validate(order)
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(order, indent=2) + "\n", encoding="utf-8")

    if args.update_fleet_env:
        home = cfg["home"]
        values = {
            "CRANE_MAP_ID": str(cfg.get("map_id", "map")),
            "CRANE_WAYPOINT_FILE": str(args.waypoints.relative_to(REPO_ROOT)) if args.waypoints.is_relative_to(REPO_ROOT) else str(args.waypoints),
            "CRANE_HOME_BRIDGE_M": str(finite_number(home, "bridge_m")),
            "CRANE_HOME_TROLLEY_M": str(finite_number(home, "trolley_m")),
            "CRANE_HOME_HOIST_M": str(finite_number(home, "hoist_m")),
        }
        if args.enable_crane:
            values["CRANE_ENABLED"] = "true"
        update_env(args.update_fleet_env, values)

    print(f"Wrote schema-valid crane order: {args.output}")
    print(f"Map: {cfg.get('map_id', 'map')} | source={cfg['waypoints']['source_station']} | handover={cfg['waypoints']['rox_handover']}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
