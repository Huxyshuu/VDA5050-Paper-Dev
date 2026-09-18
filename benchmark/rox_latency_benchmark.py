#!/usr/bin/env python3
"""Prepare, check and run the entire ROX campaign from the Raspberry Pi."""
from __future__ import annotations

import argparse
import csv
import fcntl
import hashlib
import json
import math
import os
import socket
import sys
import tarfile
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT))
from benchmark.common import load_config, normalize_angle
from benchmark.experiment_logger import config_identifier, git_commit, utc_now
from benchmark.generate_schedule import build_rows
from benchmark.pi_measurement import PROTOCOL


def validate_config(cfg):
    if cfg.get("schema_version") != 2 or cfg.get("measurement_protocol") != PROTOCOL:
        raise ValueError("Use the Pi schema_version: 2 configuration; old ROX-clock configs are retired")
    if cfg.get("device") != "rox" or not cfg.get("runner_hostname"):
        raise ValueError("Set device: rox and runner_hostname to the Pi hostname")
    if cfg["mqtt"]["host"] not in {"127.0.0.1", "localhost", "::1"}:
        raise ValueError("Use the Pi's LOCAL broker: mqtt.host: 127.0.0.1")
    if cfg["mqtt"]["qos"] != 0:
        raise ValueError("This adapter uses order QoS 0 and feedback QoS 1")
    for group in ("position", "headings", "tolerances", "timeouts", "readiness"):
        for key, value in cfg[group].items():
            if isinstance(value, bool) or not isinstance(value, (int, float)) or not math.isfinite(value):
                raise ValueError(f"{group}.{key} must be a finite number")
            if group in {"tolerances", "timeouts", "readiness"} and value <= 0:
                raise ValueError(f"{group}.{key} must be positive")
    a, b = cfg["headings"]["theta_a"], cfg["headings"]["theta_b"]
    if abs(normalize_angle(b-a-math.pi/2)) > 1e-6:
        raise ValueError("theta_b must equal theta_a + pi/2 (modulo 2*pi)")


def source_fingerprint():
    files = sorted(p for directory in (ROOT/"benchmark", ROOT/"analysis",
                   ROOT/"ros2_ws/src/rox_vda5050_adapter", ROOT/"schemas")
                   for p in directory.rglob("*") if p.is_file() and p.suffix in {".py", ".json", ".schema", ".yaml", ".xml"})
    files += [ROOT/"scripts/pi_benchmark.sh", ROOT/"deploy/pi-benchmark.Dockerfile"]
    return {str(p.relative_to(ROOT)): hashlib.sha256(p.read_bytes()).hexdigest() for p in files}


def client_environment():
    return {key: os.getenv(key, "") for key in
            ("ROS_DISTRO", "ROS_DOMAIN_ID", "RMW_IMPLEMENTATION", "ROS_AUTOMATIC_DISCOVERY_RANGE",
             "ROS_LOCALHOST_ONLY", "ROS_STATIC_PEERS", "CYCLONEDDS_URI")}


def read_schedule(path):
    with path.open(newline="") as stream:
        rows = list(csv.DictReader(stream))
    ids = [r["trial_id"] for r in rows]
    if not rows or len(ids) != len(set(ids)):
        raise ValueError("Schedule is empty or has duplicate trial IDs")
    return rows


def prepare(args):
    cfg = load_config(args.config)
    validate_config(cfg)
    name = args.run_dir.name
    if not name or any(c not in "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_-" for c in name):
        raise ValueError("Run directory name must contain only letters, digits, underscore or hyphen")
    rows = build_rows("rox", args.pairs, args.seed, run_id=name, start_at=args.start_at)
    args.run_dir.mkdir(parents=True, exist_ok=False)
    (args.run_dir / "config.yaml").write_bytes(args.config.read_bytes())
    with (args.run_dir / "schedule.csv").open("x", newline="") as stream:
        writer = csv.DictWriter(stream, fieldnames=list(rows[0]))
        writer.writeheader()
        writer.writerows(rows)
    (args.run_dir / "manifest.json").write_text(json.dumps({
        "protocol": PROTOCOL, "created_utc": utc_now(), "git_commit": git_commit(ROOT),
        "pairs": args.pairs, "seed": args.seed,
        "config_id": config_identifier(args.run_dir / "config.yaml"),
        "schedule_id": config_identifier(args.run_dir / "schedule.csv"),
        "source_files": source_fingerprint(),
        "client_environment": client_environment(),
    }, indent=2) + "\n")
    with tarfile.open(args.run_dir / "source.tar.gz", "w:gz") as archive:
        for directory in ("benchmark", "analysis", "ros2_ws/src/rox_vda5050_adapter", "schemas",
                          "scripts/pi_benchmark.sh", "deploy/pi-benchmark.Dockerfile"):
            archive.add(ROOT/directory, arcname=directory,
                        filter=lambda t: None if "__pycache__" in t.name or t.name.endswith(".pyc") else t)
    print(f"Prepared {args.run_dir}: {args.pairs*2} measured trials + {args.pairs} excluded resets")


def verify_run(run_dir):
    manifest = json.loads((run_dir / "manifest.json").read_text())
    for file, key in (("config.yaml", "config_id"), ("schedule.csv", "schedule_id")):
        if config_identifier(run_dir/file) != manifest[key]:
            raise ValueError(f"Frozen {file} changed; create a new campaign")
    if source_fingerprint() != manifest["source_files"]:
        raise ValueError("Source changed since prepare; use a new campaign")
    if client_environment() != manifest["client_environment"]:
        raise ValueError("Pi ROS environment changed since prepare; restore it or create a new campaign")
    cfg = load_config(run_dir / "config.yaml")
    validate_config(cfg)
    if socket.gethostname() != cfg["runner_hostname"]:
        raise ValueError(f"Run on Pi {cfg['runner_hostname']!r}; this host is {socket.gethostname()!r}")
    return cfg


def select_rows(rows, events, start, end):
    from analysis.derive_latency import derive
    if any(r["outcome"] != "ok" for r in derive(events)):
        raise ValueError("Existing attempt is failed, incomplete or invalid; preserve and review it")
    finished = {e["trial_id"]: e for e in events if e.get("event_type") == "TRIAL_FINISHED"}
    attempted = {e["trial_id"] for e in events}
    known = {r["trial_id"] for r in rows}
    if attempted - known:
        raise ValueError("Log includes trials outside this frozen schedule")
    bad = [t for t in attempted if t not in finished or finished[t].get("success") is not True]
    if bad:
        raise ValueError("Campaign has failed/interrupted attempts; preserve and review: " + ", ".join(sorted(bad)))
    next_row = next((i for i, r in enumerate(rows, 1) if r["trial_id"] not in attempted), len(rows)+1)
    start = start if start is not None else next_row
    end = end if end is not None else len(rows)
    if start != next_row:
        raise ValueError(f"Next unattempted row is {next_row}; cannot skip or repeat rows")
    if not 1 <= start <= end <= len(rows):
        raise ValueError("Campaign complete, or invalid row range")
    if any(r["trial_id"] in attempted for r in rows[start-1:end]):
        raise ValueError("Requested rows include an already attempted ID")
    return rows[start-1:end]


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    commands = parser.add_subparsers(dest="command", required=True)
    create = commands.add_parser("prepare", help="Freeze config and schedule; no motion")
    create.add_argument("--config", type=Path, default=ROOT/"benchmark/config/rox_benchmark.yaml")
    create.add_argument("--run-dir", type=Path, required=True)
    create.add_argument("--pairs", type=int, default=30)
    create.add_argument("--seed", type=int, required=True)
    create.add_argument("--start-at", choices=("A", "B"), default="A", help="Current verified heading; frozen into schedule")
    check = commands.add_parser("check", help="Pi DDS/MQTT and start-pose checks; no motion")
    check.add_argument("--run-dir", type=Path, required=True)
    run = commands.add_parser("run", help="Run next rows under operator supervision")
    run.add_argument("--run-dir", type=Path, required=True)
    run.add_argument("--start-row", type=int)
    run.add_argument("--end-row", type=int)
    args = parser.parse_args()
    args.run_dir = args.run_dir.expanduser().resolve()
    if args.command == "prepare":
        if args.pairs < 1:
            parser.error("--pairs must be positive")
        prepare(args)
        return
    (ROOT / "runtime").mkdir(exist_ok=True)
    with (ROOT / "runtime/pi_benchmark.lock").open("a") as lock:
        fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
        cfg = verify_run(args.run_dir)
        rows = read_schedule(args.run_dir / "schedule.csv")
        from analysis.derive_latency import read_events
        path = args.run_dir / "events.jsonl"
        events = read_events([path]) if path.exists() else []
        selected = select_rows(rows, events, getattr(args, "start_row", None), getattr(args, "end_row", None))
        try:
            import rclpy
            from benchmark.pi_ros import PiRunner
        except ImportError as exc:
            raise SystemExit(f"Pi needs ROS Jazzy: {exc}. See docs/PI_BENCHMARK.md")
        rclpy.init()
        node = None
        try:
            node = PiRunner(cfg, args.run_dir)
            if args.command == "check":
                ready = node.preflight()
                node.wait_pose(selected[0]["start"])
                print("PASS: Pi DDS, local MQTT, adapter feedback, fresh pose and stationary ROX")
                print(json.dumps(ready, indent=2))
                (args.run_dir / "adapter_readiness.json").write_text(json.dumps(ready, indent=2)+"\n")
            else:
                for row in selected:
                    if not node.run_trial(row):
                        raise RuntimeError("Trial failed; campaign stopped")
        except BaseException:
            print("STOPPED. Preserve events.jsonl. Verify ROX has stopped before further commands.", file=sys.stderr)
            raise
        finally:
            if node is not None:
                node.close()
            rclpy.shutdown()


if __name__ == "__main__":
    main()
