#!/usr/bin/env python3
"""Derive one immutable CSV row per benchmark trial from raw JSONL events."""

from __future__ import annotations

import argparse
import csv
import json
from collections import defaultdict
from pathlib import Path
from typing import Any, Dict, Iterable, List


EVENT_COLUMNS = {
    "NATIVE_DISPATCH": "dispatch_latency_ms",
    "NATIVE_ACK": "ack_latency_ms",
    "MOTION_STARTED": "motion_start_latency_ms",
    "MOTION_COMPLETED": "completion_latency_ms",
    "RESULT_OBSERVED": "result_latency_ms",
}
REQUIRED_NATIVE = {
    "COMMAND_ISSUED",
    "NATIVE_DISPATCH",
    "NATIVE_ACK",
    "MOTION_STARTED",
    "MOTION_COMPLETED",
    "RESULT_OBSERVED",
}
REQUIRED_VDA = REQUIRED_NATIVE | {"MQTT_RECEIVED", "VDA_ACCEPTED"}


def read_events(paths: Iterable[Path]) -> List[Dict[str, Any]]:
    events = []
    seen = set()
    for path in paths:
        with path.open(encoding="utf-8") as stream:
            for line_number, line in enumerate(stream, start=1):
                if not line.strip():
                    continue
                try:
                    event = json.loads(line)
                except json.JSONDecodeError as exc:
                    raise ValueError(f"{path}:{line_number}: invalid JSON: {exc}") from exc
                key = (
                    event.get("host"),
                    event.get("boot_id"),
                    event.get("source"),
                    event.get("trial_id"),
                    event.get("event_type"),
                    event.get("monotonic_ns"),
                )
                if key not in seen:
                    seen.add(key)
                    events.append(event)
    return events


def derive(events: Iterable[Dict[str, Any]], include_setup: bool = False) -> List[Dict[str, Any]]:
    groups: Dict[str, List[Dict[str, Any]]] = defaultdict(list)
    for event in events:
        trial_id = str(event.get("trial_id", ""))
        if trial_id:
            groups[trial_id].append(event)

    rows = []
    for trial_id, trial_events in sorted(groups.items()):
        trial_events.sort(key=lambda item: int(item.get("monotonic_ns", 0) or 0))
        issued_candidates = [
            item for item in trial_events if item.get("event_type") == "COMMAND_ISSUED"
        ]
        issued = issued_candidates[0] if issued_candidates else trial_events[0]
        architecture = str(issued.get("architecture", trial_events[0].get("architecture", "")))
        if architecture == "setup" and not include_setup:
            continue
        host = str(issued.get("host", ""))
        boot_id = str(issued.get("boot_id", ""))
        comparable = [
            item
            for item in trial_events
            if str(item.get("host", "")) == host
            and str(item.get("boot_id", "")) == boot_id
        ]
        observed = {str(item.get("event_type", "")) for item in comparable}
        required = REQUIRED_VDA if architecture == "vda" else REQUIRED_NATIVE
        origin = int(issued.get("monotonic_ns", 0) or 0)
        first_by_type: Dict[str, Dict[str, Any]] = {}
        for event in comparable:
            first_by_type.setdefault(str(event.get("event_type", "")), event)
        pair_id = next(
            (str(item.get("pair_id")) for item in trial_events if item.get("pair_id")), ""
        )
        row: Dict[str, Any] = {
            "trial_id": trial_id,
            "pair_id": pair_id,
            "architecture": architecture,
            "device": str(issued.get("device", "")),
            "operation": str(issued.get("operation", "")),
            "command_id": str(issued.get("command_id", "")),
            "order_id": next(
                (str(item.get("order_id")) for item in trial_events if item.get("order_id")),
                "",
            ),
            "timestamp_utc": str(issued.get("timestamp_utc", "")),
            "host": host,
            "boot_id": boot_id,
            "git_commit": str(issued.get("git_commit", "")),
            "config_id": str(issued.get("config_id", "")),
            "complete": required.issubset(observed),
            "missing_events": ";".join(sorted(required - observed)),
            "success": next(
                (
                    item.get("success")
                    for item in reversed(trial_events)
                    if item.get("event_type") == "RESULT_OBSERVED"
                ),
                None,
            ),
        }
        for event_type, column in EVENT_COLUMNS.items():
            event = first_by_type.get(event_type)
            row[column] = (
                round((int(event["monotonic_ns"]) - origin) / 1_000_000.0, 6)
                if event is not None and origin
                else ""
            )
        mqtt = first_by_type.get("MQTT_RECEIVED")
        accepted = first_by_type.get("VDA_ACCEPTED")
        dispatch = first_by_type.get("NATIVE_DISPATCH")
        row["mqtt_transport_latency_ms"] = (
            round((int(mqtt["monotonic_ns"]) - origin) / 1_000_000.0, 6)
            if mqtt is not None and origin
            else ""
        )
        row["vda_acceptance_latency_ms"] = (
            round((int(accepted["monotonic_ns"]) - origin) / 1_000_000.0, 6)
            if accepted is not None and origin
            else ""
        )
        row["adapter_latency_ms"] = (
            round(
                (int(dispatch["monotonic_ns"]) - int(mqtt["monotonic_ns"]))
                / 1_000_000.0,
                6,
            )
            if mqtt is not None and dispatch is not None
            else ""
        )
        rows.append(row)
    return rows


def write_csv(rows: List[Dict[str, Any]], path: Path) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    fieldnames = list(rows[0]) if rows else [
        "trial_id", "pair_id", "architecture", "device", "complete"
    ]
    with path.open("w", newline="", encoding="utf-8") as stream:
        writer = csv.DictWriter(stream, fieldnames=fieldnames)
        writer.writeheader()
        writer.writerows(rows)


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("inputs", type=Path, nargs="+")
    parser.add_argument("--output", type=Path, required=True)
    parser.add_argument("--include-setup", action="store_true")
    parser.add_argument(
        "--allow-incomplete",
        action="store_true",
        help="Write incomplete rows instead of failing the protocol-integrity gate",
    )
    args = parser.parse_args()
    rows = derive(read_events(args.inputs), include_setup=args.include_setup)
    incomplete = [row for row in rows if not row["complete"]]
    write_csv(rows, args.output)
    if incomplete and not args.allow_incomplete:
        details = ", ".join(
            f"{row['trial_id']}({row['missing_events']})" for row in incomplete[:10]
        )
        raise SystemExit(f"Derived CSV written, but {len(incomplete)} trials are incomplete: {details}")
    print(f"Wrote {len(rows)} trial rows to {args.output}")


if __name__ == "__main__":
    main()
