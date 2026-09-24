#!/usr/bin/env python3
"""Generate a frozen randomized paired benchmark schedule.

Each pair measures the same A->B or B->A movement twice.  A supervised native
setup movement returns the device to the pair's start state between treatments;
setup rows are excluded from analysis.  Pair direction alternates to avoid a
manual reset between pairs and treatment order is randomized within each pair.
"""

from __future__ import annotations

import argparse
import csv
import random
from pathlib import Path


def build_rows(device: str, pairs: int, seed: int, run_id: str = "", start_at: str = "A"):
    if start_at not in {"A", "B"}:
        raise ValueError("start_at must be A or B")
    rng = random.Random(seed)
    rows = []
    for number in range(1, pairs + 1):
        start, target = ("A", "B") if number % 2 else ("B", "A")
        if start_at == "B":
            start, target = target, start
        order = ["native", "vda"]
        rng.shuffle(order)
        pair_id = f"{run_id + '-' if run_id else ''}{device}-p{number:03d}"
        for sequence, mode in enumerate(order, start=1):
            if sequence == 2:
                rows.append(
                    {
                        "row_type": "setup",
                        "measure": "false",
                        "device": device,
                        "pair_id": pair_id,
                        "trial_id": f"{pair_id}-setup",
                        "mode": "native",
                        "start": target,
                        "target": start,
                        "sequence_in_pair": "2",
                    }
                )
            rows.append(
                {
                    "row_type": "measurement",
                    "measure": "true",
                    "device": device,
                    "pair_id": pair_id,
                    "trial_id": f"{pair_id}-{mode}",
                    "mode": mode,
                    "start": start,
                    "target": target,
                    "sequence_in_pair": "1" if sequence == 1 else "3",
                }
            )
    return rows


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--device", choices=("rox", "crane"), default="rox")
    parser.add_argument("--pairs", type=int, default=30)
    parser.add_argument("--seed", type=int, required=True)
    parser.add_argument("--output", type=Path, required=True)
    parser.add_argument("--run-id", required=True, help="Unique campaign ID")
    args = parser.parse_args()
    if args.pairs < 1:
        parser.error("--pairs must be at least 1")
    rows = build_rows(args.device, args.pairs, args.seed, args.run_id)
    args.output.parent.mkdir(parents=True, exist_ok=True)
    with args.output.open("x", newline="", encoding="utf-8") as stream:
        writer = csv.DictWriter(stream, fieldnames=list(rows[0]))
        writer.writeheader()
        writer.writerows(rows)
    print(f"Wrote {len(rows)} schedule rows ({args.pairs * 2} measurements) to {args.output}")


if __name__ == "__main__":
    main()
