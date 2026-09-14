#!/usr/bin/env python3
"""Measure call-site overhead of enqueueing one benchmark event.

This is a software sanity check, not a substitute for the physical pilot.  It
quantifies only the time spent in ``ExperimentLogger.emit`` before returning to
the control path; disk and MQTT work happen on the background writer.
"""

from __future__ import annotations

import argparse
import json
import tempfile
import time
from pathlib import Path

from experiment_logger import ExperimentLogger


ROOT = Path(__file__).resolve().parents[1]


def percentile(values, probability):
    ordered = sorted(values)
    index = min(len(ordered) - 1, int(round((len(ordered) - 1) * probability)))
    return ordered[index]


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--events", type=int, default=10_000)
    parser.add_argument("--max-p95-us", type=float, default=250.0)
    parser.add_argument("--output", type=Path)
    args = parser.parse_args()
    if args.events < 100:
        parser.error("--events must be at least 100")
    with tempfile.TemporaryDirectory(prefix="vda-benchmark-logger-") as directory:
        logger = ExperimentLogger(
            Path(directory) / "events.jsonl",
            repo_root=ROOT,
            source="logger_overhead_check",
        )
        durations = []
        for number in range(args.events):
            start = time.perf_counter_ns()
            logger.emit(
                "COMMAND_ISSUED",
                trial_id=f"overhead-{number}",
                architecture="native",
                device="rox",
                operation="logger_check",
                command_id=f"overhead-{number}",
                success=True,
            )
            durations.append((time.perf_counter_ns() - start) / 1_000.0)
        logger.close()
    p50 = percentile(durations, 0.50)
    p95 = percentile(durations, 0.95)
    p99 = percentile(durations, 0.99)
    print(f"emit call overhead: p50={p50:.2f} us p95={p95:.2f} us p99={p99:.2f} us")
    if args.output:
        args.output.parent.mkdir(parents=True, exist_ok=True)
        args.output.write_text(
            json.dumps(
                {
                    "events": args.events,
                    "p50_us": p50,
                    "p95_us": p95,
                    "p99_us": p99,
                    "acceptance_limit_p95_us": args.max_p95_us,
                    "passed": p95 <= args.max_p95_us,
                },
                indent=2,
            )
            + "\n",
            encoding="utf-8",
        )
    if p95 > args.max_p95_us:
        raise SystemExit(
            f"p95 {p95:.2f} us exceeds --max-p95-us {args.max_p95_us:.2f} us"
        )


if __name__ == "__main__":
    main()
