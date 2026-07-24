#!/usr/bin/env python3
"""Read-only smoke checks for the Flask HMI v2 API."""
from __future__ import annotations
import argparse, json
from urllib.request import urlopen


def get_json(url: str):
    with urlopen(url, timeout=5) as response:
        return json.loads(response.read().decode("utf-8"), parse_constant=lambda value: (_ for _ in ()).throw(ValueError(f"invalid JSON constant {value}")))


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--url", default="http://127.0.0.1:5000")
    args = parser.parse_args()
    health = get_json(args.url.rstrip("/") + "/healthz")
    dashboard = get_json(args.url.rstrip("/") + "/api/dashboard")
    checks = {
        "health": bool(health.get("ok")),
        "mqtt": bool(dashboard.get("server", {}).get("mqtt_connected")),
        "rox_online": bool(dashboard.get("devices", {}).get("rox", {}).get("online")),
        "waypoints": len(dashboard.get("waypoints", [])),
        "command_chain": bool(dashboard.get("command_chain")),
        "map_mode": "image" if dashboard.get("map", {}).get("available") else "coordinate-fallback",
        "experiment_api": bool(dashboard.get("experiment") is not None),
    }
    print(json.dumps(checks, indent=2))
    return 0 if checks["health"] and checks["command_chain"] else 1


if __name__ == "__main__":
    raise SystemExit(main())
