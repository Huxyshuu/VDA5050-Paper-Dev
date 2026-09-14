from __future__ import annotations

import importlib.util
import json
import tempfile
import unittest
from pathlib import Path

from analysis.derive_latency import derive, write_csv
from benchmark.experiment_logger import ExperimentLogger
from benchmark.generate_schedule import build_rows


ROOT = Path(__file__).resolve().parents[1]


def load_analysis_statistics():
    spec = importlib.util.spec_from_file_location(
        "benchmark_analysis_statistics", ROOT / "analysis/statistics.py"
    )
    module = importlib.util.module_from_spec(spec)
    assert spec.loader is not None
    spec.loader.exec_module(module)
    return module


class BenchmarkPipelineTests(unittest.TestCase):
    def test_logger_emits_schema_valid_monotonic_jsonl(self) -> None:
        schema = json.loads(
            (ROOT / "benchmark/event_schema.json").read_text(encoding="utf-8")
        )
        with tempfile.TemporaryDirectory() as directory:
            path = Path(directory) / "events.jsonl"
            logger = ExperimentLogger(path, repo_root=ROOT, source="unit_test")
            first = logger.emit(
                "COMMAND_ISSUED",
                trial_id="rox-p001-native",
                pair_id="rox-p001",
                architecture="native",
                device="rox",
                operation="rotate_90deg",
                command_id="rox-p001-native",
                success=True,
            )
            second = logger.emit(
                "NATIVE_DISPATCH",
                trial_id="rox-p001-native",
                pair_id="rox-p001",
                architecture="native",
                device="rox",
                operation="rotate_90deg",
                command_id="rox-p001-native",
                success=True,
            )
            logger.close()
            records = [json.loads(line) for line in path.read_text().splitlines()]
        self.assertEqual(2, len(records))
        self.assertLessEqual(first["monotonic_ns"], second["monotonic_ns"])
        for record in records:
            self.assertTrue(set(schema["required"]).issubset(record))
            self.assertIn(
                record["event_type"], schema["properties"]["event_type"]["enum"]
            )
            self.assertIn(
                record["architecture"],
                schema["properties"]["architecture"]["enum"],
            )

    def test_schedule_has_two_matched_measurements_per_pair(self) -> None:
        rows = build_rows("rox", pairs=30, seed=5050)
        measured = [row for row in rows if row["measure"] == "true"]
        setup = [row for row in rows if row["measure"] == "false"]
        self.assertEqual(60, len(measured))
        self.assertEqual(30, len(setup))
        for number in range(1, 31):
            pair_id = f"rox-p{number:03d}"
            pair = [row for row in measured if row["pair_id"] == pair_id]
            self.assertEqual({"native", "vda"}, {row["mode"] for row in pair})
            self.assertEqual(1, len({(row["start"], row["target"]) for row in pair}))

    def test_derive_and_statistics_preserve_paired_effect(self) -> None:
        events = []
        sequence = {
            "COMMAND_ISSUED": 0,
            "MQTT_RECEIVED": 1_000_000,
            "VDA_ACCEPTED": 2_000_000,
            "NATIVE_DISPATCH": 3_000_000,
            "NATIVE_ACK": 4_000_000,
            "MOTION_STARTED": 8_000_000,
            "MOTION_COMPLETED": 20_000_000,
            "RESULT_OBSERVED": 21_000_000,
        }
        for architecture, offset in (("native", 0), ("vda", 5_000_000)):
            trial = f"rox-p001-{architecture}"
            for event_type, delta in sequence.items():
                if architecture == "native" and event_type in {"MQTT_RECEIVED", "VDA_ACCEPTED"}:
                    continue
                events.append(
                    {
                        "trial_id": trial,
                        "pair_id": "rox-p001",
                        "architecture": architecture,
                        "device": "rox",
                        "operation": "rotate_90deg",
                        "command_id": trial,
                        "order_id": trial if architecture == "vda" else "",
                        "timestamp_utc": "2026-09-14T00:00:00Z",
                        "monotonic_ns": 1_000_000_000 + delta + offset,
                        "event_type": event_type,
                        "success": True,
                        "host": "rox",
                        "boot_id": "boot-1",
                        "git_commit": "abc",
                        "config_id": "sha256:test",
                        "source": "test",
                    }
                )
        rows = derive(events)
        self.assertEqual(2, len(rows))
        self.assertTrue(all(row["complete"] for row in rows))
        with tempfile.TemporaryDirectory() as directory:
            csv_path = Path(directory) / "derived.csv"
            write_csv(rows, csv_path)
            module = load_analysis_statistics()
            loaded = module.read_rows(csv_path)
            summary, paired = module.analyze(loaded, bootstrap_samples=100, seed=5050)
        dispatch_effect = next(
            row for row in summary
            if row["metric"] == "dispatch_latency_ms"
            and row["architecture"] == "vda-minus-native"
        )
        self.assertEqual(0.0, dispatch_effect["median"])
        completion_effect = next(
            row for row in paired if row["metric"] == "completion_latency_ms"
        )
        self.assertEqual(0.0, completion_effect["difference_ms"])

    def test_ui_contains_dedicated_monotonic_timeline(self) -> None:
        html = (ROOT / "fleet_control/templates/index.html").read_text(encoding="utf-8")
        dashboard = (ROOT / "fleet_control/dashboard_v3.py").read_text(encoding="utf-8")
        self.assertIn("Monotonic action timeline", html)
        self.assertIn("elapsed_from_command_ms", html)
        self.assertIn("benchmark_events_export_endpoint", dashboard)
        self.assertIn("current - origin", dashboard)


if __name__ == "__main__":
    unittest.main()
