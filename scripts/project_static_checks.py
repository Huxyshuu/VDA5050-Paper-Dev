#!/usr/bin/env python3
"""Fast static/schema audit for the active VDA 5050 v3 source tree."""
from __future__ import annotations

import ast
import importlib.util
import json
import re
import py_compile
import subprocess
import sys
import tempfile
import types
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
        ROOT / "fleet_control" / "dashboard_v3.py",
        ROOT / "fleet_control" / "crane_manual_controls.py",
        ROOT / "crane_edge" / "crane.py",
        ROOT / "crane_edge" / "crane_vda5050_adapter_v3.py",
        *sorted((ROOT / "scripts").glob("*.py")),
        *sorted((ROOT / "ros2_ws/src/rox_vda5050_adapter/launch").glob("*.py")),
        *sorted((ROOT / "ros2_ws/src/rox_vda5050_adapter/rox_vda5050_adapter").glob("*.py")),
    ]
    for path in python_files:
        py_compile.compile(str(path), doraise=True)
    print(f"PASS Python syntax ({len(python_files)} files)")

    # Installer regressions previously left duplicate class methods that silently
    # overrode earlier implementations. Treat those as a static failure.
    duplicate_defs = []
    for path in python_files:
        tree = ast.parse(path.read_text(encoding="utf-8"), filename=str(path))
        scopes = [("module", tree.body)]
        scopes.extend(
            (node.name, node.body)
            for node in ast.walk(tree)
            if isinstance(node, ast.ClassDef)
        )
        for scope_name, body in scopes:
            seen = {}
            for node in body:
                if isinstance(node, (ast.FunctionDef, ast.AsyncFunctionDef, ast.ClassDef)):
                    seen.setdefault(node.name, []).append(node.lineno)
            for name, lines in seen.items():
                if len(lines) > 1:
                    duplicate_defs.append(
                        f"{path.relative_to(ROOT)}:{scope_name}.{name}@{lines}"
                    )
    check(not duplicate_defs, f"no duplicate Python definitions ({duplicate_defs})")

    # Flask previously crashed because patch installers registered the same
    # endpoint twice. Detect duplicate literal method/path pairs across the
    # three route-registration modules before runtime.
    route_pattern = re.compile(
        r"@app\.(?P<kind>get|post|put|delete|route)\(\s*[\"'](?P<path>[^\"']+)[\"'](?P<tail>[^)]*)\)"
    )
    route_owners = {}
    for path in (
        ROOT / "fleet_control/master_control.py",
        ROOT / "fleet_control/dashboard_v3.py",
        ROOT / "fleet_control/crane_manual_controls.py",
    ):
        lines = path.read_text(encoding="utf-8").splitlines()
        for line_no, line in enumerate(lines, 1):
            match = route_pattern.search(line)
            if not match:
                continue
            method = match.group("kind").upper()
            if method == "ROUTE":
                methods_match = re.search(r"methods\s*=\s*\[([^]]+)\]", match.group("tail"))
                methods = re.findall(r"[\"']([A-Za-z]+)[\"']", methods_match.group(1)) if methods_match else ["GET"]
            else:
                methods = [method]
            for http_method in methods:
                key = (http_method.upper(), match.group("path"))
                route_owners.setdefault(key, []).append(
                    f"{path.relative_to(ROOT)}:{line_no}"
                )
    duplicate_routes = {key: owners for key, owners in route_owners.items() if len(owners) > 1}
    check(not duplicate_routes, f"no duplicate Flask routes ({duplicate_routes})")

    adapter_text = (ROOT / "crane_edge/crane_vda5050_adapter_v3.py").read_text(encoding="utf-8")
    check("int(rc)" not in adapter_text, "Paho ReasonCode is not coerced with int(rc)")
    check(
        "DX_Custom_V.Status.WatchDogFault" in adapter_text,
        "crane adapter uses the authoritative OPC UA automatic-mode signal",
    )
    check(
        "CRANE_MQTT_CONNECT_TIMEOUT_S" in adapter_text and "_mqtt_ready.wait" in adapter_text,
        "crane adapter fails startup when MQTT setup does not complete",
    )
    check(
        "_instant_motion_active" in adapter_text and "cancelOrder received; STOP latched immediately" in adapter_text,
        "crane reset/home motion is interruptible by cancel and automatic-mode loss",
    )

    for path in sorted((ROOT / "scripts").glob("*.sh")):
        subprocess.run(["bash", "-n", str(path)], check=True)
    print("PASS shell syntax")

    for path in sorted((ROOT / "ros2_ws/src").glob("*/package.xml")):
        ET.parse(path)
    print("PASS ROS package XML")

    validate("order.schema", ROOT / "examples/orders/order_ilmatar_v3.json")
    validate("order.schema", ROOT / "examples/orders/order_rox_diff_v3.json")
    validate("state.schema", ROOT / "examples/states/rox_diff_idle_state.example.json")
    validate("factsheet.schema", ROOT / "examples/factsheets/rox_diff_factsheet.template.json")
    validate("factsheet.schema", ROOT / "examples/factsheets/ilmatar_crane_factsheet.template.json")

    # Validate the actual orders created by the new crane dashboard buttons.
    # Stub Flask only when it is not installed in the static-check interpreter;
    # the order builders themselves are pure and do not need a running app.
    restore_flask = "flask" not in sys.modules
    if restore_flask:
        fake_flask = types.ModuleType("flask")
        fake_flask.abort = lambda *args, **kwargs: None
        fake_flask.jsonify = lambda value=None, **kwargs: value if value is not None else kwargs
        sys.modules["flask"] = fake_flask
    try:
        spec = importlib.util.spec_from_file_location(
            "_crane_manual_controls_static",
            ROOT / "fleet_control/crane_manual_controls.py",
        )
        module = importlib.util.module_from_spec(spec)
        assert spec and spec.loader
        spec.loader.exec_module(module)
        manual_cfg = module._load_config(ROOT / "tests/fixtures/crane_waypoints_configured.yaml")
        manual_state = {
            "mobileRobotPosition": {"x": 17.0, "y": 6.0, "theta": 0.0, "mapId": "map", "localized": True},
            "information": [
                {
                    "infoType": "HOIST_POSITION",
                    "infoDescriptor": "Hoist height: 1.000 m",
                    "infoLevel": "INFO",
                }
            ],
        }
        manual_orders = [
            module._build_xy_order(manual_cfg, manual_state, "source_station"),
            module._build_hoist_order(manual_cfg, manual_state, "source_safe_lift_m"),
        ]
        order_schema = json.loads((SCHEMA_DIR / "order.schema").read_text(encoding="utf-8"))
        for order in manual_orders:
            stamped = {
                "headerId": 1,
                "timestamp": "2026-08-05T00:00:00.000Z",
                "version": "3.0.0",
                "manufacturer": "konecranes",
                "serialNumber": "ilmatar_1",
                **order,
            }
            jsonschema.validate(stamped, order_schema)
        print("PASS schema crane dashboard manual orders")
    finally:
        if restore_flask:
            sys.modules.pop("flask", None)

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

        crane_output = Path(tmp) / "order_ilmatar_v3.json"
        from generate_crane_order import main as generate_crane_main
        old_argv = sys.argv[:]
        sys.argv = [
            "generate_crane_order.py",
            "--waypoints", str(ROOT / "tests/fixtures/crane_waypoints_configured.yaml"),
            "--schema", str(SCHEMA_DIR / "order.schema"),
            "--output", str(crane_output),
        ]
        try:
            crane_rc = generate_crane_main()
        finally:
            sys.argv = old_argv
        check(crane_rc == 0 and crane_output.exists(), "generate crane v3 test order")
        validate("order.schema", crane_output)

    unconfigured = yaml.safe_load((ROOT / "configs/rox_waypoints.yaml.example").read_text())
    check(unconfigured.get("configured") is False, "ROX example waypoints remain fail-closed")
    crane_unconfigured = yaml.safe_load((ROOT / "configs/crane_waypoints.yaml.example").read_text())
    check(crane_unconfigured.get("configured") is False, "crane example waypoints remain fail-closed")

    env_example = (ROOT / "configs/fleet_control.env.example").read_text(encoding="utf-8")
    for key in (
        "CRANE_AUTO_WAIT_TIMEOUT_S",
        "CRANE_AUTO_STABLE_S",
        "CRANE_AUTO_MODE_POLL_S",
        "CRANE_MQTT_CONNECT_TIMEOUT_S",
        "CRANE_HOME_ON_START",
        "CRANE_ALLOW_UNVERIFIED_MANUAL",
    ):
        check(re.search(rf"^{key}=", env_example, re.MULTILINE) is not None, f"env example documents {key}")

    # Local credential files may exist, but must never be tracked by Git.
    tracked = subprocess.run(
        ["git", "-C", str(ROOT), "ls-files", "--", "crane_edge/access.txt", "access.txt", "accesscode_url.txt"],
        check=True,
        capture_output=True,
        text=True,
    ).stdout.splitlines()
    check(not tracked, f"no crane credential files tracked by Git ({tracked})")

    active_env = {}
    for raw_line in (ROOT / "configs/fleet_control.env").read_text(encoding="utf-8").splitlines():
        line = raw_line.strip()
        if line and not line.startswith("#") and "=" in line:
            key, value = line.split("=", 1)
            active_env[key.strip()] = value.strip()
    active_rox = yaml.safe_load((ROOT / "configs/rox_waypoints.yaml").read_text()) or {}
    rox_home = (active_rox.get("waypoints") or {}).get("home") or {}
    expected_rox_init = {
        "ROX_INIT_X": str(rox_home.get("x")),
        "ROX_INIT_Y": str(rox_home.get("y")),
        "ROX_INIT_THETA": str(rox_home.get("theta")),
        "ROX_INIT_MAP_ID": str(active_rox.get("map_id", "df_map")),
        "ROX_INIT_LAST_NODE_ID": "node1",
        "ROX_INIT_LAST_NODE_SEQUENCE_ID": "0",
    }
    check(
        all(active_env.get(key) == value for key, value in expected_rox_init.items()),
        f"ROX initializePosition matches the verified home waypoint ({expected_rox_init})",
    )

    active_crane = yaml.safe_load((ROOT / "configs/crane_waypoints.yaml").read_text()) or {}
    legacy_descriptions = [
        str(item.get("description", ""))
        for item in (active_crane.get("waypoints") or {}).values()
        if isinstance(item, dict) and "legacy starting value only" in str(item.get("description", "")).lower()
    ]
    check(
        not (active_crane.get("configured") is True and legacy_descriptions),
        "legacy crane coordinates cannot be marked configured",
    )

    subprocess.run(
        [
            sys.executable,
            str(ROOT / "scripts/check_crane_rox_integration.py"),
            "--allow-unconfigured",
        ],
        check=True,
    )
    print("PASS structural crane/ROX integration check")

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
