"""Recovery launcher regression tests; fake readiness and no hardware imports."""
import copy
import json
import tempfile
import unittest
from pathlib import Path
from types import SimpleNamespace
from unittest.mock import patch

from analysis.derive_latency import derive
from benchmark.generate_schedule import build_rows
from benchmark.latency_benchmark import source_fingerprint
from scripts.resume_crane_campaign import (
    reviewed_failures, select_continuation, verify_recovery,
)
from test_benchmark_pipeline import trial_events


def events_for(row, failed=False):
    events = trial_events(row)
    events[-1]['details']['endpoint'] = {'height_error_mm': 0.0}
    if failed:
        events.pop(2)  # no completion on overshoot
        events[-1]['success'] = False
        events[-1]['result'] = 'Hoist is not at A: 2508 mm'
        events[-1]['details']['endpoint'] = {}
    return events


class RecoveryTests(unittest.TestCase):
    def setUp(self):
        self.rows = build_rows('crane', 3, 6061, 'test', start_at='B')
        self.events = events_for(self.rows[0], failed=True)
        self.failed_id = self.rows[0]['trial_id']
        self.failed = derive(self.events, self.rows)[0]
        self.tmp = tempfile.TemporaryDirectory()
        self.addCleanup(self.tmp.cleanup)
        self.run_dir = Path(self.tmp.name)
        self.raw = ''.join(json.dumps(e)+'\n' for e in self.events).encode()
        self.manifest = b'{"protocol":"laptop-timing-v1"}\n'
        (self.run_dir/'events.jsonl').write_bytes(self.raw)
        (self.run_dir/'manifest.json').write_bytes(self.manifest)
        self.calls = []
        self.node = SimpleNamespace(
            preflight=lambda: self.calls.append('preflight') or {'busy': False},
            wait_pose=lambda endpoint: self.calls.append(endpoint) or {'height_error_mm': 0.0})

    def record(self):
        verify_recovery(self.node, self.run_dir, self.failed, 2, self.rows[1],
                        'Restored stationary A with supervised controls', self.raw, self.manifest)

    def test_requires_exact_failure_and_never_replays_it(self):
        with self.assertRaisesRegex(ValueError, 'Explicit'):
            select_continuation(self.rows, self.events, set())
        with self.assertRaisesRegex(ValueError, 'exactly'):
            select_continuation(self.rows, self.events, set(), 'wrong-id')
        number, selected, failed = select_continuation(
            self.rows, self.events, set(), self.failed_id, 3)
        self.assertEqual(2, number)
        self.assertEqual(self.rows[1:3], selected)
        self.assertEqual('failed', failed['outcome'])
        with self.assertRaises(ValueError):
            select_continuation(self.rows, self.events, set(), self.failed_id, 1)

    def test_incomplete_duplicate_and_noncontiguous_attempts_are_rejected(self):
        for events in (self.events[:-1], self.events+self.events,
                       self.events+events_for(self.rows[2])):
            with self.subTest(events=len(events)), self.assertRaises(ValueError):
                select_continuation(self.rows, events, set(), self.failed_id)

    def test_failure_with_wrong_schedule_identity_is_rejected(self):
        events = copy.deepcopy(self.events)
        events[0]['details']['target'] = 'wrong'
        with self.assertRaisesRegex(ValueError, 'Invalid'):
            select_continuation(self.rows, events, set(), self.failed_id)

    def test_recovery_is_logged_after_checks_without_rewriting_events(self):
        self.record()
        self.assertEqual(['preflight', self.rows[1]['start']], self.calls)
        self.assertEqual(self.raw, (self.run_dir/'events.jsonl').read_bytes())
        self.assertEqual(self.manifest, (self.run_dir/'manifest.json').read_bytes())
        entry = json.loads((self.run_dir/'recoveries.jsonl').read_text())
        self.assertEqual(self.failed_id, entry['failed_trial_id'])
        self.assertEqual(2, entry['next_row'])
        self.assertEqual(self.rows[1]['trial_id'], entry['next_trial_id'])
        self.assertTrue(entry['operator_note'])
        self.assertEqual({self.failed_id}, reviewed_failures(self.run_dir, self.raw, self.manifest))
        self.assertEqual('failed', derive(self.events)[0]['outcome'])

    def test_failed_readiness_or_position_does_not_record_recovery(self):
        for method in ('preflight', 'wait_pose'):
            def fail(*args): raise RuntimeError('not ready')
            with patch.object(self.node, method, fail), self.assertRaises(RuntimeError):
                self.record()
            self.assertFalse((self.run_dir/'recoveries.jsonl').exists())

    def test_record_write_failure_aborts(self):
        (self.run_dir/'recoveries.jsonl').mkdir()
        with self.assertRaises(OSError):
            self.record()
        self.assertEqual(self.raw, (self.run_dir/'events.jsonl').read_bytes())

    def test_audit_rejects_rewritten_events_or_manifest(self):
        self.record()
        for raw, manifest in ((self.raw.replace(b'2508', b'2509'), self.manifest),
                              (self.raw, self.manifest+b' ')):
            with self.assertRaises(ValueError):
                reviewed_failures(self.run_dir, raw, manifest)

    def test_later_blocks_accept_reviewed_failure_but_not_new_failure(self):
        self.record()
        more = self.events+events_for(self.rows[1])+events_for(self.rows[2])
        raw = self.raw+''.join(json.dumps(e)+'\n' for e in more[len(self.events):]).encode()
        reviewed = reviewed_failures(self.run_dir, raw, self.manifest)
        number, selected, failed = select_continuation(self.rows, more, reviewed)
        self.assertEqual(4, number)
        self.assertEqual(self.rows[3:], selected)
        self.assertIsNone(failed)
        more += events_for(self.rows[3], failed=True)
        with self.assertRaisesRegex(ValueError, 'Explicit'):
            select_continuation(self.rows, more, reviewed)
        self.assertEqual(5, select_continuation(
            self.rows, more, reviewed, self.rows[3]['trial_id'])[0])

    def test_changed_events_during_verification_are_rejected(self):
        def change(endpoint):
            (self.run_dir/'events.jsonl').write_bytes(self.raw+b'\n')
            return {'height_error_mm': 0.0}
        self.node.wait_pose = change
        with self.assertRaisesRegex(ValueError, 'Events changed'):
            self.record()
        self.assertFalse((self.run_dir/'recoveries.jsonl').exists())

    def test_launcher_and_tests_do_not_change_frozen_source_set(self):
        files = source_fingerprint()
        self.assertNotIn('scripts/resume_crane_campaign.py', files)
        self.assertNotIn('tests/test_crane_recovery.py', files)
        self.assertIn('benchmark/latency_benchmark.py', files)
        self.assertIn('crane_edge/hoist_benchmark.py', files)


if __name__ == '__main__':
    unittest.main()
