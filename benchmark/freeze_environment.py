#!/usr/bin/env python3
"""Record the non-secret software and experiment configuration freeze."""

from __future__ import annotations

import argparse
import json
import os
import platform
import shutil
import subprocess
import sys
from pathlib import Path

from experiment_logger import config_identifier, git_commit, utc_now


ROOT = Path(__file__).resolve().parents[1]


def command_output(command):
    try:
        result = subprocess.run(
            command, capture_output=True, text=True, timeout=5.0, check=False
        )
        text = (result.stdout or result.stderr).strip()
        return {"command": command, "exit_code": result.returncode, "output": text}
    except (OSError, subprocess.SubprocessError) as exc:
        return {"command": command, "error": f"{type(exc).__name__}: {exc}"}


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--config", type=Path, action="append", default=[])
    parser.add_argument("--output", type=Path, required=True)
    parser.add_argument("--network-note", default="", help="Physical topology description")
    parser.add_argument("--crane-software", default="", help="PLC/crane software version")
    args = parser.parse_args()

    public_env = {
        key: os.getenv(key, "")
        for key in (
            "ROS_DISTRO",
            "ROS_DOMAIN_ID",
            "RMW_IMPLEMENTATION",
            "VDA_PROTOCOL_VERSION",
            "VDA_MAJOR_VERSION",
            "VDA_MQTT_QOS",
            "VDA_MQTT_HOST",
            "VDA_MQTT_PORT",
            "CRANE_MAP_ID",
        )
    }
    commands = []
    for command in (
        ["ros2", "pkg", "xml", "nav2_bringup"],
        ["ros2", "doctor", "--report"],
        ["ros2", "param", "dump", "/controller_server"],
        ["ros2", "param", "dump", "/planner_server"],
        ["ros2", "param", "dump", "/bt_navigator"],
        ["ros2", "param", "dump", "/amcl"],
        ["ros2", "param", "dump", "/map_server"],
        ["mosquitto", "-h"],
        ["ip", "-brief", "address"],
        ["ip", "route"],
    ):
        if shutil.which(command[0]):
            commands.append(command_output(command))

    configs = []
    for value in args.config:
        path = value.expanduser().resolve()
        configs.append(
            {
                "path": str(path),
                "config_id": config_identifier(path),
            }
        )
    payload = {
        "frozen_at_utc": utc_now(),
        "git_commit": git_commit(ROOT),
        "python": sys.version,
        "platform": platform.platform(),
        "public_environment": public_env,
        "crane_software": args.crane_software,
        "network_topology_note": args.network_note,
        "configs": configs,
        "command_evidence": commands,
        "notes": [
            "No credentials or access codes are recorded.",
            "UTC is human-readable context; only Pi monotonic_ns differences are measured.",
        ],
    }
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(payload, indent=2) + "\n", encoding="utf-8")
    print(f"Wrote environment freeze to {args.output}")


if __name__ == "__main__":
    main()
