#!/usr/bin/env python3
"""Read-only smoke test for the Flask VDA 5050 mission-control dashboard."""
from __future__ import annotations

import argparse
import json
import sys
from urllib.error import HTTPError, URLError
from urllib.request import Request, urlopen


def get_json(base_url: str, path: str) -> tuple[int, dict]:
    request = Request(base_url.rstrip("/") + path, headers={"Accept": "application/json"})
    try:
        with urlopen(request, timeout=5) as response:  # nosec B310: operator-provided URL
            return response.status, json.loads(response.read().decode("utf-8"))
    except HTTPError as exc:
        body = exc.read().decode("utf-8", errors="replace")
        try:
            payload = json.loads(body)
        except json.JSONDecodeError:
            payload = {"body": body}
        return exc.code, payload


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--url", default="http://127.0.0.1:5000")
    args = parser.parse_args()

    try:
        health_status, health = get_json(args.url, "/healthz")
        dashboard_status, dashboard = get_json(args.url, "/api/dashboard")
        waypoint_status, waypoints = get_json(args.url, "/api/waypoints")
    except (URLError, TimeoutError, json.JSONDecodeError) as exc:
        print(f"FAIL: cannot reach dashboard: {exc}", file=sys.stderr)
        return 2

    failures: list[str] = []
    if health_status not in {200, 503}:
        failures.append(f"/healthz returned {health_status}")
    if dashboard_status != 200:
        failures.append(f"/api/dashboard returned {dashboard_status}")
    if waypoint_status != 200:
        failures.append(f"/api/waypoints returned {waypoint_status}")
    if not str(dashboard.get("server", {}).get("protocol", "")).startswith("VDA 5050 3"):
        failures.append("dashboard protocol is not VDA 5050 v3")
    if "rox" not in dashboard.get("devices", {}):
        failures.append("ROX device projection missing")
    if "crane" not in dashboard.get("devices", {}):
        failures.append("crane device projection missing")
    if not isinstance(waypoints.get("waypoints"), dict):
        failures.append("waypoint mapping missing")

    print(f"Dashboard: {args.url}")
    print(f"Health HTTP: {health_status}; MQTT connected: {health.get('mqtt_connected')}")
    print(f"Protocol: {dashboard.get('server', {}).get('protocol')}")
    print(f"Map: {dashboard.get('server', {}).get('map_id')}")
    print(f"Waypoints: {len(waypoints.get('waypoints', {}))}")
    print(f"ROX connection: {dashboard.get('devices', {}).get('rox', {}).get('connection')}")
    print(f"Crane availability: {dashboard.get('devices', {}).get('crane', {}).get('availability')}")

    if failures:
        for failure in failures:
            print(f"FAIL: {failure}", file=sys.stderr)
        return 1
    print("PASS: dashboard read-only smoke test")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
