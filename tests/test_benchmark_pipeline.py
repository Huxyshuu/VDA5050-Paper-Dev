"""Offline protocol and analysis tests; never send commands to hardware."""
import copy
import importlib.util
import json
import tempfile
import unittest
from pathlib import Path
from unittest.mock import patch

import jsonschema
from analysis.derive_latency import derive, read_events, write_csv
from benchmark.experiment_logger import ExperimentLogger
from benchmark.generate_schedule import build_rows
from benchmark.measurement import Measurement
from benchmark.latency_benchmark import select_rows, validate_config

ROOT = Path(__file__).resolve().parents[1]


class MemoryLogger:
    def __init__(self):
        self.events = []

    def emit(self, event_type, **kwargs):
        captured = kwargs.pop("captured_ns", None)
        value = {"schema_version": "3.0", "event_type": event_type,
                 "monotonic_ns": captured if captured is not None else max([e['monotonic_ns'] for e in self.events] or [0])+100,
                 "host": "raspberrypi", "boot_id": "boot-1", "pid": 123,
                 "source": "laptop_runner", "config_id": "sha256:frozen", "git_commit": "abc",
                 "timestamp_utc": "2026-09-15T00:00:00Z", **kwargs}
        self.events.append(value)
        return value


def trial_events(row, ack_ms=10, completion_ms=5000):
    logger = MemoryLogger()
    m = Measurement(logger, row)
    with patch("benchmark.measurement.time.monotonic_ns", return_value=1_000_000_000):
        m.issue({"x": 1., "y": 2., "theta": 0.5})
    m.ack(1_000_000_000 + int(ack_ms*1e6), True, "ab"*16)
    m.result(1_000_000_000 + int(completion_ms*1e6), 4, "ab"*16)
    m.finish({"xy_error_m": 0.001, "theta_error_rad": 0.002})
    return logger.events


class BenchmarkPipelineTests(unittest.TestCase):
    def setUp(self):
        self.schedule = build_rows("rox", 2, 5050, "pi-pilot")

    def test_logger_preserves_callback_entry_time_and_schema(self):
        with tempfile.TemporaryDirectory() as d:
            path = Path(d)/"events.jsonl"
            logger = ExperimentLogger(path, repo_root=ROOT, source="laptop_runner")
            m = Measurement(logger, self.schedule[0])
            m.issue({"x": 0, "y": 0, "theta": 0})
            m.ack(m.issued_ns+100, True, "ab"*16)
            m.result(m.issued_ns+200, 4, "ab"*16)
            m.finish({"xy_error_m": 0, "theta_error_rad": 0})
            self.assertTrue(logger.flush())
            logger.close()
            records = [json.loads(l) for l in path.read_text().splitlines()]
        schema = json.loads((ROOT/"benchmark/event_schema.json").read_text())
        for r in records:
            jsonschema.validate(r, schema)
        self.assertEqual(100, records[1]["monotonic_ns"]-records[0]["monotonic_ns"])

    def test_paired_analysis_recovers_injected_effect_and_mean_sd(self):
        events = []
        for row in self.schedule:
            events.extend(trial_events(row, ack_ms=10 if row['mode']=='native' else 40,
                                       completion_ms=5000 if row['mode']=='native' else 5040))
        rows = derive(events, self.schedule)
        self.assertTrue(all(r['outcome']=='ok' for r in rows))
        spec = importlib.util.spec_from_file_location("paper_stats", ROOT/"analysis/statistics.py")
        stats = importlib.util.module_from_spec(spec)
        spec.loader.exec_module(stats)
        with tempfile.TemporaryDirectory() as d:
            file = Path(d)/"trials.csv"
            write_csv(rows, file)
            summary, paired = stats.analyze(stats.read_rows(file), 100, 5050)
        effects = {r['metric']:r for r in summary if r['architecture']=='vda-minus-native'}
        self.assertEqual(30, effects['ack_round_trip_ms']['median'])
        self.assertEqual(40, effects['completion_round_trip_ms']['mean'])
        self.assertEqual(2, effects['ack_round_trip_ms']['n'])
        self.assertAlmostEqual(1., stats.describe([1,2,3])['std'])

    def test_schedule_pairs_same_direction_with_excluded_reset(self):
        for first, reset, second in zip(self.schedule[::3], self.schedule[1::3], self.schedule[2::3]):
            self.assertEqual({'native','vda'}, {first['mode'],second['mode']})
            self.assertEqual(first['start'], second['start'])
            self.assertEqual(first['target'], reset['start'])
            self.assertEqual(first['start'], reset['target'])
            self.assertEqual('false', reset['measure'])

    def test_other_clock_is_rejected_not_subtracted(self):
        events = trial_events(self.schedule[0])
        events[1]['host'] = 'rox'
        result = derive(events)[0]
        self.assertEqual('invalid', result['outcome'])
        self.assertEqual('', result['ack_round_trip_ms'])

    def test_duplicate_attempt_is_visible(self):
        events = trial_events(self.schedule[0])
        result = derive(events+copy.deepcopy(events))[0]
        self.assertIn('repeated_event', result['errors'])

    def test_missing_whole_trial_is_in_csv(self):
        rows = derive(trial_events(self.schedule[0]), self.schedule)
        self.assertEqual(len(self.schedule), len(rows))
        self.assertEqual(5, sum(r['outcome']=='missing' for r in rows))

    def test_rejection_has_ack_but_no_fabricated_completion(self):
        logger = MemoryLogger(); m = Measurement(logger, self.schedule[0]); m.issue({})
        m.ack(m.issued_ns+100, False, 'ab'*16); m.finish()
        row = derive(logger.events)[0]
        self.assertEqual('failed', row['outcome'])
        self.assertEqual('', row['completion_round_trip_ms'])
        self.assertFalse(m.accepted)

    def test_duplicate_delivery_is_ignored_and_conflicting_uuid_fails(self):
        logger = MemoryLogger(); m = Measurement(logger, self.schedule[0]); m.issue({})
        m.ack(m.issued_ns+100, True, 'ab'*16)
        m.ack(m.issued_ns+200, True, 'ab'*16)
        self.assertEqual(2, len(logger.events))
        m.result(m.issued_ns+300, 4, 'cd'*16)
        self.assertTrue(m.error)
        self.assertIsNone(m.result_ns)

    def test_endpoint_failure_does_not_move_completion_timestamp(self):
        logger = MemoryLogger(); m = Measurement(logger, self.schedule[0]); m.issue({})
        m.ack(m.issued_ns+100, True, 'ab'*16)
        m.result(m.issued_ns+200, 4, 'ab'*16)
        m.fail('endpoint outside tolerance'); m.finish()
        result = derive(logger.events)[0]
        self.assertEqual('failed', result['outcome'])
        self.assertEqual(.0002, result['completion_round_trip_ms'])

    def test_resume_cannot_repeat_skip_or_hide_failure(self):
        events = trial_events(self.schedule[0])
        self.assertEqual(self.schedule[1:], select_rows(self.schedule, events, None, None))
        with self.assertRaises(ValueError): select_rows(self.schedule, events, 1, 3)
        with self.assertRaises(ValueError): select_rows(self.schedule, events, 3, 3)
        events[-1]['success'] = False
        with self.assertRaises(ValueError): select_rows(self.schedule, events, None, None)

    def test_old_log_schema_is_not_silently_mixed(self):
        with tempfile.TemporaryDirectory() as d:
            p = Path(d)/'old.jsonl'; p.write_text('{"schema_version":"1.0"}\n')
            with self.assertRaises(ValueError): read_events([p])

    def test_nonzero_native_error_cannot_be_a_success(self):
        logger = MemoryLogger(); m = Measurement(logger, self.schedule[0]); m.issue({})
        m.ack(m.issued_ns+100, True, 'ab'*16)
        m.result(m.issued_ns+200, 4, 'ab'*16, error_code=1)
        self.assertFalse(m.finish({'xy_error_m':0, 'theta_error_rad':0}))
        self.assertEqual('failed', derive(logger.events)[0]['outcome'])

    def test_config_allows_remote_broker_and_rejects_old_protocol(self):
        import yaml
        cfg = yaml.safe_load((ROOT/'benchmark/config/rox_benchmark.yaml').read_text())
        validate_config(cfg)
        cfg['mqtt']['host'] = '192.168.50.115'
        validate_config(cfg)
        cfg['measurement_protocol'] = 'pi-nav2-v1'
        with self.assertRaises(ValueError): validate_config(cfg)


if __name__ == '__main__':
    unittest.main()
