#!/usr/bin/env python3
"""Frozen descriptive and paired analysis for the latency paper."""

from __future__ import annotations

import argparse
import csv
import math
import random
from collections import defaultdict
from pathlib import Path
from typing import Dict, Iterable, List, Tuple


METRICS = (
    "dispatch_latency_ms",
    "ack_latency_ms",
    "motion_start_latency_ms",
    "completion_latency_ms",
    "result_latency_ms",
)


def median(values: Iterable[float]) -> float:
    ordered = sorted(values)
    size = len(ordered)
    if size == 0:
        raise ValueError("median requires at least one value")
    middle = size // 2
    if size % 2:
        return ordered[middle]
    return (ordered[middle - 1] + ordered[middle]) / 2.0


def percentile(values: Iterable[float], probability: float) -> float:
    ordered = sorted(values)
    if not ordered:
        return math.nan
    position = (len(ordered) - 1) * probability
    lower = math.floor(position)
    upper = math.ceil(position)
    if lower == upper:
        return ordered[lower]
    fraction = position - lower
    return ordered[lower] * (1.0 - fraction) + ordered[upper] * fraction


def describe(values: List[float]) -> Dict[str, float]:
    return {
        "n": len(values),
        "median": median(values),
        "q1": percentile(values, 0.25),
        "q3": percentile(values, 0.75),
        "iqr": percentile(values, 0.75) - percentile(values, 0.25),
        "p95": percentile(values, 0.95),
        "p99": percentile(values, 0.99),
    }


def bootstrap_median_ci(
    values: List[float], *, samples: int, seed: int
) -> Tuple[float, float]:
    if not values:
        return math.nan, math.nan
    rng = random.Random(seed)
    estimates = []
    for _ in range(samples):
        resample = [values[rng.randrange(len(values))] for _ in values]
        estimates.append(median(resample))
    return percentile(estimates, 0.025), percentile(estimates, 0.975)


def read_rows(path: Path, *, successful_only: bool = True) -> List[Dict[str, str]]:
    with path.open(newline="", encoding="utf-8") as stream:
        rows = list(csv.DictReader(stream))
    rows = [row for row in rows if row.get("architecture") in {"native", "vda"}]
    if not successful_only:
        return rows
    return [row for row in rows if str(row.get("complete", "")).lower() == "true"
            and str(row.get("success", "")).lower() == "true"]


def analyze(rows: List[Dict[str, str]], bootstrap_samples: int, seed: int):
    summary = []
    paired = []
    for device in sorted({row["device"] for row in rows}):
        device_rows = [row for row in rows if row["device"] == device]
        for metric in METRICS:
            for architecture in ("native", "vda"):
                values = [
                    float(row[metric])
                    for row in device_rows
                    if row["architecture"] == architecture and row.get(metric)
                ]
                if values:
                    summary.append(
                        {
                            "device": device,
                            "metric": metric,
                            "architecture": architecture,
                            **describe(values),
                        }
                    )
            by_pair: Dict[str, Dict[str, float]] = defaultdict(dict)
            for row in device_rows:
                if row.get("pair_id") and row.get(metric):
                    by_pair[row["pair_id"]][row["architecture"]] = float(row[metric])
            differences = []
            percentages = []
            for pair_id, values in sorted(by_pair.items()):
                if set(values) != {"native", "vda"}:
                    continue
                difference = values["vda"] - values["native"]
                percentage = (
                    difference / values["native"] * 100.0
                    if values["native"] != 0.0
                    else math.nan
                )
                differences.append(difference)
                if math.isfinite(percentage):
                    percentages.append(percentage)
                paired.append(
                    {
                        "device": device,
                        "metric": metric,
                        "pair_id": pair_id,
                        "native_ms": values["native"],
                        "vda_ms": values["vda"],
                        "difference_ms": difference,
                        "percentage_overhead": percentage,
                    }
                )
            if differences:
                low, high = bootstrap_median_ci(
                    differences,
                    samples=bootstrap_samples,
                    seed=seed + sum(ord(char) for char in device + metric),
                )
                summary.append(
                    {
                        "device": device,
                        "metric": metric,
                        "architecture": "vda-minus-native",
                        "n": len(differences),
                        "median": median(differences),
                        "q1": percentile(differences, 0.25),
                        "q3": percentile(differences, 0.75),
                        "iqr": percentile(differences, 0.75)
                        - percentile(differences, 0.25),
                        "p95": percentile(differences, 0.95),
                        "p99": percentile(differences, 0.99),
                        "bootstrap_ci_low": low,
                        "bootstrap_ci_high": high,
                        "median_percentage_overhead": (
                            median(percentages) if percentages else math.nan
                        ),
                    }
                )
    return summary, paired


def write_dicts(path: Path, rows: List[Dict[str, object]]) -> None:
    if not rows:
        return
    fields = []
    for row in rows:
        for key in row:
            if key not in fields:
                fields.append(key)
    with path.open("w", newline="", encoding="utf-8") as stream:
        writer = csv.DictWriter(stream, fieldnames=fields)
        writer.writeheader()
        writer.writerows(rows)


def write_latex(path: Path, summary: List[Dict[str, object]]) -> None:
    effects = [row for row in summary if row["architecture"] == "vda-minus-native"]
    lines = [
        "% Generated by analysis/statistics.py; do not edit manually.",
        "\\begin{tabular}{llrrrr}",
        "\\toprule",
        "Device & Metric & $n$ & Median $\\Delta$ (ms) & 95\\% CI (ms) & Overhead (\\%) \\\\",
        "\\midrule",
    ]
    for row in effects:
        metric = str(row["metric"]).replace("_latency_ms", "").replace("_", " ")
        lines.append(
            f"{row['device'].upper()} & {metric} & {row['n']} & "
            f"{float(row['median']):.3f} & "
            f"[{float(row['bootstrap_ci_low']):.3f}, {float(row['bootstrap_ci_high']):.3f}] & "
            f"{float(row['median_percentage_overhead']):.1f} \\\\"
        )
    lines.extend(["\\bottomrule", "\\end{tabular}"])
    path.write_text("\n".join(lines) + "\n", encoding="utf-8")


def write_figure(path: Path, rows: List[Dict[str, str]]) -> None:
    import matplotlib.pyplot as plt

    devices = sorted({row["device"] for row in rows})
    metrics = ("dispatch_latency_ms", "ack_latency_ms", "completion_latency_ms")
    fig, axes = plt.subplots(len(devices), len(metrics), figsize=(10.5, 3.4 * len(devices)))
    if len(devices) == 1:
        axes = [axes]
    for row_axes, device in zip(axes, devices):
        for axis, metric in zip(row_axes, metrics):
            values = [
                [
                    float(row[metric])
                    for row in rows
                    if row["device"] == device
                    and row["architecture"] == architecture
                    and row.get(metric)
                ]
                for architecture in ("native", "vda")
            ]
            axis.boxplot(values, showfliers=True)
            axis.set_xticks([1, 2], ["Native", "VDA"])
            axis.set_title(metric.replace("_latency_ms", "").replace("_", " ").title())
            axis.set_ylabel("Latency (ms)")
            axis.grid(axis="y", alpha=0.25)
        row_axes[0].annotate(
            device.upper(), xy=(-0.38, 0.5), xycoords="axes fraction", rotation=90,
            ha="center", va="center", fontweight="bold"
        )
    fig.suptitle("Native versus VDA 5050 benchmark latency")
    fig.tight_layout()
    fig.savefig(path, bbox_inches="tight")
    plt.close(fig)


def trial_accounting(rows: List[Dict[str, str]]) -> List[Dict[str, object]]:
    accounting = []
    for device in sorted({row.get("device", "") for row in rows}):
        for architecture in ("native", "vda"):
            selected = [
                row for row in rows
                if row.get("device") == device and row.get("architecture") == architecture
            ]
            if not selected:
                continue
            complete = [
                row for row in selected
                if str(row.get("complete", "")).lower() == "true"
            ]
            successful = [
                row for row in complete
                if str(row.get("success", "")).lower() == "true"
            ]
            accounting.append(
                {
                    "device": device,
                    "architecture": architecture,
                    "scheduled_trials": len(selected),
                    "complete_event_sequences": len(complete),
                    "successful_trials": len(successful),
                    "failed_or_timed_out_trials": len(complete) - len(successful),
                    "incomplete_trials": len(selected) - len(complete),
                }
            )
    return accounting


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("input", type=Path)
    parser.add_argument("--output-dir", type=Path, required=True)
    parser.add_argument("--bootstrap-samples", type=int, default=10_000)
    parser.add_argument("--seed", type=int, default=5050)
    args = parser.parse_args()
    if args.bootstrap_samples < 100:
        parser.error("--bootstrap-samples must be at least 100")
    all_rows = read_rows(args.input, successful_only=False)
    rows = read_rows(args.input)
    if not rows:
        raise SystemExit("No complete successful native/VDA trials are available")
    args.output_dir.mkdir(parents=True, exist_ok=True)
    summary, paired = analyze(rows, args.bootstrap_samples, args.seed)
    write_dicts(args.output_dir / "latency_summary.csv", summary)
    write_dicts(args.output_dir / "paired_differences.csv", paired)
    write_dicts(args.output_dir / "trial_accounting.csv", trial_accounting(all_rows))
    write_latex(args.output_dir / "latency_summary_table.tex", summary)
    write_figure(args.output_dir / "latency_comparison.pdf", rows)
    write_figure(args.output_dir / "latency_comparison.png", rows)
    print(f"Analyzed {len(rows)} complete successful trials in {args.output_dir}")


if __name__ == "__main__":
    main()
