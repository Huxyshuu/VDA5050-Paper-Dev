#!/usr/bin/env python3
"""One Laptop log → one row per scheduled trial, with two response-time metrics."""
from __future__ import annotations

import argparse
import csv
import json
import math
from collections import Counter, defaultdict
from pathlib import Path

EVENT_COLUMNS = {"COMMAND_ACK_RECEIVED": "ack_round_trip_ms",
                 "COMMAND_RESULT_RECEIVED": "completion_round_trip_ms"}
REQUIRED = {"COMMAND_ISSUED", *EVENT_COLUMNS, "TRIAL_FINISHED"}


def read_events(paths):
    events = []
    for path in paths:
        with path.open(encoding="utf-8") as stream:
            for line_number, line in enumerate(stream, 1):
                if not line.strip():
                    continue
                try:
                    event = json.loads(line)
                    if not isinstance(event, dict) or event.get("schema_version") != "3.0":
                        raise ValueError("Expected schema 3.0 Laptop events; keep old pilot logs separate")
                    if event.get("event_type") not in REQUIRED:
                        raise ValueError("Unknown event type")
                    if event.get("source") != "laptop_runner" or event.get("details", {}).get("protocol") != "laptop-timing-v1":
                        raise ValueError("Expected locally recorded laptop_runner event")
                    if type(event.get("monotonic_ns")) is not int or event["monotonic_ns"] <= 0:
                        raise ValueError("Invalid monotonic_ns")
                    for key in ("trial_id", "host", "boot_id", "config_id"):
                        if not event.get(key) or event[key] == "unknown":
                            raise ValueError("Missing " + key)
                except (ValueError, TypeError) as exc:
                    raise ValueError(f"{path}:{line_number}: {exc}") from exc
                events.append(event)
    return events


def derive(events, schedule=None, include_setup=True):
    groups = defaultdict(list)
    for event in events:
        groups[event["trial_id"]].append(event)
    schedule_by_id = {row["trial_id"]: row for row in schedule or []}
    if schedule is not None and len(schedule_by_id) != len(schedule):
        raise ValueError("Duplicate trial IDs in schedule")
    if schedule is not None and set(groups)-set(schedule_by_id):
        raise ValueError("Log contains trial IDs absent from schedule")
    rows = []
    for trial_id in (schedule_by_id if schedule is not None else sorted(groups)):
        items = groups.get(trial_id, [])
        expected = schedule_by_id.get(trial_id, {})
        first = items[0] if items else {}
        details = first.get("details", {})
        device = expected.get("device", first.get("device", ""))
        mode = expected.get("mode", details.get("mode", first.get("architecture", "")))
        measured = expected.get("measure", "false" if first.get("architecture") == "setup" else "true")
        architecture = mode if measured == "true" else "setup"
        if architecture == "setup" and not include_setup:
            continue
        counts = Counter(e["event_type"] for e in items)
        errors = []
        if device not in {"rox", "crane"}:
            errors.append("unknown_device")
        if any(v > 1 for v in counts.values()):
            errors.append("repeated_event_or_trial_id")
        by_type = {e["event_type"]: e for e in items}
        origin = by_type.get("COMMAND_ISSUED")
        ack = by_type.get("COMMAND_ACK_RECEIVED")
        result = by_type.get("COMMAND_RESULT_RECEIVED")
        finish = by_type.get("TRIAL_FINISHED")
        for key in ("host", "boot_id", "config_id", "pid", "source"):
            if len({str(e.get(key, "")) for e in items}) > 1:
                errors.append("mixed_" + key)
        for e in items:
            if e.get("architecture") != architecture or e.get("device") != device:
                errors.append("identity_mismatch")
            d = e.get("details", {})
            for key in ("start", "target", "mode"):
                if key in expected and d.get(key) != expected[key]:
                    errors.append("schedule_" + key + "_mismatch")
            if expected.get("pair_id") and e.get("pair_id") != expected["pair_id"]:
                errors.append("pair_id_mismatch")
            if e.get("command_id") != trial_id or e.get("order_id") != (trial_id if mode == "vda" else ""):
                errors.append("command_id_mismatch")
        sequence = [by_type[k]["monotonic_ns"] for k in
                    ("COMMAND_ISSUED", "COMMAND_ACK_RECEIVED", "COMMAND_RESULT_RECEIVED", "TRIAL_FINISHED") if k in by_type]
        if sequence != sorted(sequence):
            errors.append("noncausal_timestamps")
        if ack and not origin:
            errors.append("ack_without_command")
        if result:
            a, r = (ack or {}).get("details", {}), result.get("details", {})
            if not ack or a.get("accepted") is not True or not a.get("goal_id") or a.get("goal_id") != r.get("goal_id"):
                errors.append("goal_response_mismatch")
            if r.get("terminal_status") not in {4, 5, 6}:
                errors.append("nonterminal_result")
        complete = REQUIRED.issubset(counts) and not errors
        successful = bool(complete and finish.get("success") is True
                          and ack.get("details", {}).get("accepted") is True
                          and result.get("details", {}).get("terminal_status") == 4
                          and not result.get("details", {}).get("error_code"))
        outcome = ("invalid" if errors else "missing" if not items else "ok" if successful
                   else "failed" if finish and finish.get("success") is False else "incomplete")
        endpoint = (finish or {}).get("details", {}).get("endpoint", {})
        endpoint_fields = {"xy_error_m", "theta_error_rad"} if device == "rox" else {"height_error_mm"}
        valid_endpoint = all(isinstance(endpoint.get(k), (int, float)) and not isinstance(endpoint[k], bool)
                             and math.isfinite(endpoint[k]) and endpoint[k] >= 0 for k in endpoint_fields)
        if finish and finish.get("success") is True and not valid_endpoint:
            errors.append("missing_endpoint_verification")
            complete, successful, outcome = False, False, "invalid"
        row = {"trial_id": trial_id, "pair_id": expected.get("pair_id", first.get("pair_id", "")),
               "architecture": architecture, "mode": mode, "device": device, "measure": measured,
               "start": expected.get("start", details.get("start", "")),
               "target": expected.get("target", details.get("target", "")),
               "complete": complete, "success": successful, "outcome": outcome,
               "missing_events": ";".join(sorted(REQUIRED-set(counts))),
               "errors": ";".join(sorted(set(errors))),
               "reason": (finish or {}).get("result", ""),
               "host": first.get("host", ""), "boot_id": first.get("boot_id", ""),
               "config_id": first.get("config_id", ""), "git_commit": first.get("git_commit", ""),
               "timestamp_utc": first.get("timestamp_utc", ""),
               "command_issued_ns": (origin or {}).get("monotonic_ns", ""),
               "ack_received_ns": (ack or {}).get("monotonic_ns", ""),
               "completion_received_ns": (result or {}).get("monotonic_ns", ""),
               "ack_kind": (ack or {}).get("details", {}).get("ack_kind", ""),
               "endpoint_height_error_mm": endpoint.get("height_error_mm", ""),
               "endpoint_xy_error_m": endpoint.get("xy_error_m", ""),
               "endpoint_theta_error_rad": endpoint.get("theta_error_rad", "")}
        for event, column in EVENT_COLUMNS.items():
            e = by_type.get(event)
            row[column] = round((e["monotonic_ns"]-origin["monotonic_ns"])/1e6, 6) if e and origin and not errors else ""
        rows.append(row)
    configs = {r["config_id"] for r in rows if r["config_id"]}
    hosts = {r["host"] for r in rows if r["host"]}
    if len(configs) > 1 or len(hosts) > 1:
        raise ValueError("A campaign must use one frozen config and one Laptop host")
    return rows


def write_csv(rows, path):
    path.parent.mkdir(parents=True, exist_ok=True)
    with path.open("w", newline="", encoding="utf-8") as stream:
        writer = csv.DictWriter(stream, fieldnames=list(rows[0]) if rows else ["trial_id"])
        writer.writeheader()
        writer.writerows(rows)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("input", type=Path, help="Authoritative Laptop events.jsonl")
    parser.add_argument("--schedule", type=Path, required=True)
    parser.add_argument("--output", type=Path, required=True)
    parser.add_argument("--through-row", type=int, help="Audit only a completed schedule prefix")
    args = parser.parse_args()
    with args.schedule.open(newline="") as stream:
        schedule = list(csv.DictReader(stream))
    if args.through_row is not None:
        if not 1 <= args.through_row <= len(schedule):
            parser.error("Invalid --through-row")
        schedule = schedule[:args.through_row]
    rows = derive(read_events([args.input]), schedule)
    write_csv(rows, args.output)
    bad = [r for r in rows if r["outcome"] != "ok"]
    print(f"Wrote {len(rows)} scheduled rows, including resets, to {args.output}")
    if bad:
        raise SystemExit(f"REVIEW: {len(bad)} failed, missing or invalid rows retained in CSV. Do not delete attempts.")
    print("PASS: every scheduled attempt has matching Laptop timestamps, device responses and verified endpoint")


if __name__ == "__main__":
    main()
