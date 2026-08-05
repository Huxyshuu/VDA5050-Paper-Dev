#!/usr/bin/env python3
"""Read the live Ilmatar crane position without issuing movement commands.

The Crane constructor connects to OPC UA and initializes its local targets to the
current position. This tool only samples position getters, then optionally updates
one named entry in configs/crane_waypoints.yaml. It never calls a motion method.
"""
from __future__ import annotations

import argparse
import os
import statistics
import sys
import time
from pathlib import Path
from typing import Dict, Tuple

import yaml

REPO_ROOT = Path(__file__).resolve().parents[1]
CRANE_EDGE = REPO_ROOT / "crane_edge"
if str(CRANE_EDGE) not in sys.path:
    sys.path.insert(0, str(CRANE_EDGE))

from crane import Crane  # type: ignore  # noqa: E402


def _credentials() -> Tuple[str, int]:
    url = os.getenv("CRANE_OPCUA_URL", "").strip()
    code = os.getenv("CRANE_ACCESS_CODE", "").strip()
    if url and code:
        return url, int(code)

    path = Path(os.getenv("CRANE_ACCESS_FILE", str(CRANE_EDGE / "access.txt"))).expanduser()
    if not path.exists():
        raise RuntimeError(
            "Set CRANE_OPCUA_URL and CRANE_ACCESS_CODE, or create the ignored "
            f"credential file {path}."
        )
    lines = [line.strip() for line in path.read_text(encoding="utf-8").splitlines() if line.strip()]
    if len(lines) < 2:
        raise RuntimeError(f"Credential file {path} must contain URL then numeric access code.")
    return lines[0], int(lines[1])


def _sample(crane: Crane, count: int, interval: float) -> Dict[str, float]:
    bridge, trolley, hoist = [], [], []
    for index in range(count):
        bridge.append(float(crane.get_bridge_position_absolute()) / 1000.0)
        trolley.append(float(crane.get_trolley_position_absolute()) / 1000.0)
        hoist.append(float(crane.get_hoist_position_absolute()) / 1000.0)
        if index + 1 < count:
            time.sleep(interval)
    return {
        "bridge_m": statistics.median(bridge),
        "trolley_m": statistics.median(trolley),
        "hoist_m": statistics.median(hoist),
        "bridge_span_m": max(bridge) - min(bridge),
        "trolley_span_m": max(trolley) - min(trolley),
        "hoist_span_m": max(hoist) - min(hoist),
    }


def _update_yaml(path: Path, name: str | None, values: Dict[str, float], update_hoist: str | None) -> None:
    data = yaml.safe_load(path.read_text(encoding="utf-8")) or {}
    if name == "home":
        target = data.setdefault("home", {})
        target["bridge_m"] = round(values["bridge_m"], 4)
        target["trolley_m"] = round(values["trolley_m"], 4)
        target["hoist_m"] = round(values["hoist_m"], 4)
    elif name:
        waypoints = data.setdefault("waypoints", {})
        if name not in waypoints:
            raise KeyError(f"Unknown crane waypoint {name!r}; expected one of {sorted(waypoints)} or 'home'.")
        waypoints[name]["bridge_m"] = round(values["bridge_m"], 4)
        waypoints[name]["trolley_m"] = round(values["trolley_m"], 4)
    if update_hoist:
        hoist_cfg = data.setdefault("hoist_positions", {})
        if update_hoist not in hoist_cfg:
            raise KeyError(f"Unknown hoist key {update_hoist!r}; expected one of {sorted(hoist_cfg)}.")
        hoist_cfg[update_hoist] = round(values["hoist_m"], 4)
    data["configured"] = False
    path.write_text(yaml.safe_dump(data, sort_keys=False), encoding="utf-8")


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--samples", type=int, default=7)
    parser.add_argument("--interval", type=float, default=0.2)
    parser.add_argument("--max-span-mm", type=float, default=5.0, help="Refuse to save if any sampled axis changes by more than this")
    parser.add_argument("--update", choices=["source_station", "rox_handover", "home"])
    parser.add_argument(
        "--update-hoist",
        choices=["source_lower_m", "source_safe_lift_m", "handover_lower_m", "handover_safe_lift_m"],
    )
    parser.add_argument(
        "--waypoints",
        type=Path,
        default=REPO_ROOT / "configs" / "crane_waypoints.yaml",
    )
    args = parser.parse_args()
    if args.samples < 3:
        parser.error("--samples must be at least 3")

    url, access_code = _credentials()
    crane = Crane(url)
    try:
        crane.set_accesscode(access_code)
        values = _sample(crane, args.samples, args.interval)
    finally:
        try:
            crane.disconnect()
        except Exception:
            pass

    print("Live crane position (median):")
    print(f"  bridge_m: {values['bridge_m']:.4f}")
    print(f"  trolley_m: {values['trolley_m']:.4f}")
    print(f"  hoist_m: {values['hoist_m']:.4f}")
    print("Sample spans (stationary readings should be small):")
    print(f"  bridge: {values['bridge_span_m']:.6f} m")
    print(f"  trolley: {values['trolley_span_m']:.6f} m")
    print(f"  hoist: {values['hoist_span_m']:.6f} m")

    max_span_m = args.max_span_mm / 1000.0
    moving_axes = [
        name for name in ("bridge", "trolley", "hoist")
        if values[f"{name}_span_m"] > max_span_m
    ]
    if moving_axes:
        print(
            "Refusing to save: sampled position changed too much on "
            + ", ".join(moving_axes)
            + f" (limit {args.max_span_mm:.1f} mm). Stop the crane and sample again.",
            file=sys.stderr,
        )
        return 2

    if args.update or args.update_hoist:
        if not args.waypoints.exists():
            raise FileNotFoundError(args.waypoints)
        _update_yaml(args.waypoints, args.update, values, args.update_hoist)
        print(f"Updated {args.waypoints}; configured was reset to false for re-verification.")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
