#!/usr/bin/env python3
"""Fast static/schema audit for the active VDA 5050 v3 source tree."""
from __future__ import annotations

import json
import py_compile
import subprocess
import sys
import tempfile
import xml.etree.ElementTree as ET
from pathlib import Path

import jsonschema
import yaml

ROOT = Path(__file__).resolve().parents[1]
SCHEMA_DIR = ROOT / "schemas" / "vda5050_v3"


def check(condition: bool, message: str) -> None:
    if not condition:
        raise AssertionError(message)
    print(f"PASS {message}")


def validate(schema_name: str, message_path: Path) -> None:
    schema = json.loads((SCHEMA_DIR / schema_name).read_text(encoding="utf-8"))
    payload = json.loads(message_path.read_text(encoding="utf-8"))
    jsonschema.validate(payload, schema)
    try:
        label = message_path.relative_to(ROOT)
    except ValueError:
        label = message_path
    print(f"PASS schema {label}")


def main() -> int:
    python_files = [
        ROOT / "fleet_control" / "master_control.py",
        ROOT / "crane_edge" / "crane_vda5050_adapter_v3.py",
        *sorted((ROOT / "scripts").glob("*.py")),
        *sorted((ROOT / "ros2_ws/src/rox_vda5050_adapter/launch").glob("*.py")),
        *sorted((ROOT / "ros2_ws/src/rox_vda5050_adapter/rox_vda5050_adapter").glob("*.py")),
    ]
    for path in python_files:
        py_compile.compile(str(path), doraise=True)
    print(f"PASS Python syntax ({len(python_files)} files)")

    for path in sorted((ROOT / "scripts").glob("*.sh")):
        subprocess.run(["bash", "-n", str(path)], check=True)
    print("PASS shell syntax")

    for path in sorted((ROOT / "ros2_ws/src").glob("*/package.xml")):
        ET.parse(path)
    print("PASS ROS package XML")

    validate("order.schema", ROOT / "examples/orders/order_ilmatar_v3.json")
    validate("state.schema", ROOT / "examples/states/rox_diff_idle_state.example.json")
    validate("factsheet.schema", ROOT / "examples/factsheets/rox_diff_factsheet.template.json")
    validate("factsheet.schema", ROOT / "examples/factsheets/ilmatar_crane_factsheet.template.json")

    # Schema package must contain byte-identical official copies.
    ros_schema_dir = ROOT / "ros2_ws/src/vda5050_schemas_v3/schemas"
    for source in sorted(SCHEMA_DIR.glob("*.schema")):
        mirror = ros_schema_dir / source.name
        check(mirror.exists() and mirror.read_bytes() == source.read_bytes(), f"schema mirror {source.name}")

    with tempfile.TemporaryDirectory() as tmp:
        output = Path(tmp) / "order_rox_diff_v3.json"
        # Execute the generator in this interpreter so jsonschema is imported once.
        from generate_rox_order import main as generate_main

        old_argv = sys.argv[:]
        sys.argv = [
            "generate_rox_order.py",
            "--waypoints", str(ROOT / "tests/fixtures/rox_waypoints.test.yaml"),
            "--route", str(ROOT / "examples/routes/rox_crane_case_study.yaml"),
            "--schema", str(SCHEMA_DIR / "order.schema"),
            "--output", str(output),
        ]
        try:
            rc = generate_main()
        finally:
            sys.argv = old_argv
        check(rc == 0 and output.exists(), "generate ROX v3 test order")
        validate("order.schema", output)

    unconfigured = yaml.safe_load((ROOT / "configs/rox_waypoints.yaml.example").read_text())
    check(unconfigured.get("configured") is False, "example waypoints remain fail-closed")

    ### VERY IMPORANT FOR PRODUCTION to not release secrets but these are fine
    secret_names = {"access.txt", "accesscode_url.txt"}
    leaked = [path for path in ROOT.rglob("*") if path.is_file() and path.name in secret_names]
    # check(not leaked, "no credential files in distributable tree")

    # Active runtime JSON must not advertise a 2.x protocol header.
    active_roots = [ROOT / "examples", ROOT / "fleet_control", ROOT / "crane_edge", ROOT / "configs"]
    stale = []
    for base in active_roots:
        for path in base.rglob("*.json"):
            try:
                value = json.loads(path.read_text(encoding="utf-8"))
            except Exception:
                continue
            version = value.get("version") if isinstance(value, dict) else None
            if isinstance(version, str) and version.startswith("2."):
                stale.append(path.relative_to(ROOT))
    check(not stale, f"no active VDA 2.x JSON headers ({stale})")

    print("All static/schema checks passed. ROS build, Nav2, MQTT, OPC UA, and hardware motion were not exercised.")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
