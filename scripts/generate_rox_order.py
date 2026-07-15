#!/usr/bin/env python3
"""Generate a schema-valid VDA 5050 v3 ROX-Diff order from named waypoints."""

from __future__ import annotations

import argparse
import json
import re
from datetime import datetime, timezone
from pathlib import Path
from typing import Any, Dict
from uuid import uuid4

import jsonschema
import yaml


def utc_timestamp() -> str:
    return datetime.now(timezone.utc).isoformat(timespec="milliseconds").replace("+00:00", "Z")


def load_yaml(path: Path) -> Dict[str, Any]:
    value = yaml.safe_load(path.read_text(encoding="utf-8"))
    if not isinstance(value, dict):
        raise ValueError(f"{path} must contain a YAML object")
    return value


def update_env(path: Path, values: Dict[str, Any]) -> None:
    text = path.read_text(encoding="utf-8") if path.exists() else ""
    for key, value in values.items():
        line = f"{key}={value}"
        pattern = re.compile(rf"^{re.escape(key)}=.*$", re.MULTILINE)
        if pattern.search(text):
            text = pattern.sub(line, text)
        else:
            text += ("\n" if text and not text.endswith("\n") else "") + line + "\n"
    path.write_text(text, encoding="utf-8")


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--waypoints", type=Path, default=Path("configs/rox_waypoints.yaml"))
    parser.add_argument("--route", type=Path, default=Path("examples/routes/rox_crane_case_study.yaml"))
    parser.add_argument("--schema", type=Path, default=Path("schemas/vda5050_v3/order.schema"))
    parser.add_argument("--output", type=Path, default=Path("examples/orders/order_rox_diff_v3.json"))
    parser.add_argument("--manufacturer", default="neobotix")
    parser.add_argument("--serial-number", default="rox_diff_1")
    parser.add_argument("--version", default="3.0.0")
    parser.add_argument("--allow-unconfigured", action="store_true")
    parser.add_argument("--update-fleet-env", type=Path)
    args = parser.parse_args()

    waypoint_doc = load_yaml(args.waypoints)
    if not waypoint_doc.get("configured", False) and not args.allow_unconfigured:
        raise SystemExit(
            f"{args.waypoints} still has configured: false. Capture and verify the ROX-Diff poses first."
        )
    map_id = str(waypoint_doc.get("map_id", "map"))
    waypoints = waypoint_doc.get("waypoints", {})
    route = load_yaml(args.route)
    route_nodes = route.get("nodes", [])
    route_edges = route.get("edges", [])
    if len(route_edges) != max(0, len(route_nodes) - 1):
        raise ValueError("Route must contain exactly one fewer edge than nodes")

    nodes = []
    for index, spec in enumerate(route_nodes):
        name = spec["waypoint"]
        if name not in waypoints:
            raise KeyError(f"Waypoint {name!r} used by route is missing from {args.waypoints}")
        pose = waypoints[name]
        xy_tolerance = float(
            pose.get(
                "allowed_deviation_xy",
                spec.get("allowed_deviation_xy", 0.20),
            )
        )
        theta_tolerance = float(
            pose.get(
                "allowed_deviation_theta",
                spec.get("allowed_deviation_theta", 0.20),
            )
        )
        if xy_tolerance <= 0.0 or theta_tolerance <= 0.0:
            raise ValueError(
                f"Waypoint {name!r} tolerances must be positive; "
                f"got xy={xy_tolerance}, theta={theta_tolerance}"
            )
        node = {
            "nodeId": str(spec["node_id"]),
            "sequenceId": index * 2,
            "nodeDescriptor": str(spec.get("descriptor", name)),
            "released": True,
            "nodePosition": {
                "x": float(pose["x"]),
                "y": float(pose["y"]),
                "theta": float(pose["theta"]),
                "mapId": map_id,
                "allowedDeviationXY": {
                    "a": xy_tolerance,
                    "b": xy_tolerance,
                    "theta": 0.0,
                },
                "allowedDeviationTheta": theta_tolerance,
            },
            "actions": [],
        }
        for action_index, action_spec in enumerate(spec.get("actions", []) or []):
            action = {
                "actionType": str(action_spec["action_type"]),
                "actionId": str(action_spec.get("action_id") or f"{node['nodeId']}_action_{action_index + 1}"),
                "blockingType": str(action_spec.get("blocking_type", "HARD")),
            }
            if "retriable" in action_spec:
                action["retriable"] = bool(action_spec["retriable"])
            params = action_spec.get("parameters", {}) or {}
            if params:
                action["actionParameters"] = [
                    {"key": str(key), "value": value} for key, value in params.items()
                ]
            node["actions"].append(action)
        nodes.append(node)

    edges = []
    for index, spec in enumerate(route_edges):
        edges.append(
            {
                "edgeId": str(spec["edge_id"]),
                "sequenceId": index * 2 + 1,
                "edgeDescriptor": str(spec.get("descriptor", spec["edge_id"])),
                "released": True,
                "actions": [],
            }
        )

    payload = {
        "headerId": 0,
        "timestamp": utc_timestamp(),
        "version": args.version,
        "manufacturer": args.manufacturer,
        "serialNumber": args.serial_number,
        "orderId": f"template-{uuid4()}",
        "orderUpdateId": 0,
        "orderDescription": str(route.get("order_description", "ROX-Diff route")),
        "nodes": nodes,
        "edges": edges,
    }
    schema = json.loads(args.schema.read_text(encoding="utf-8"))
    jsonschema.validate(payload, schema)
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(payload, indent=2) + "\n", encoding="utf-8")
    print(f"Generated and validated {args.output}")

    if args.update_fleet_env:
        home = waypoints[route_nodes[0]["waypoint"]]
        update_env(
            args.update_fleet_env,
            {
                "ROX_INIT_X": home["x"],
                "ROX_INIT_Y": home["y"],
                "ROX_INIT_THETA": home["theta"],
                "ROX_INIT_MAP_ID": map_id,
                "ROX_INIT_LAST_NODE_ID": route_nodes[0]["node_id"],
                "ROX_INIT_LAST_NODE_SEQUENCE_ID": 0,
            },
        )
        print(f"Updated ROX initial pose in {args.update_fleet_env}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
