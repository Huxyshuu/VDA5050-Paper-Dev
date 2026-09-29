#!/usr/bin/env python3
"""Explicit, audited continuation after a terminated crane benchmark failure.

No recovery movement is sent. The operator restores the next scheduled start
endpoint first. Frozen motion/timing sources, config and schedule stay intact;
recoveries.jsonl is separate from the authoritative measurement events.
"""
from __future__ import annotations

import argparse
import fcntl
import hashlib
import json
import os
import socket
import sys
import time
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT))
from analysis.derive_latency import derive, read_events
from benchmark.experiment_logger import git_commit, system_boot_id, utc_now
from benchmark.latency_benchmark import read_schedule, verify_run


def digest(data):
    return hashlib.sha256(data).hexdigest()


def reviewed_failures(run_dir, events_bytes, manifest_bytes):
    """Validate the append-only history before accepting a previous recovery."""
    path = run_dir / 'recoveries.jsonl'
    reviewed = set()
    if not path.exists():
        return reviewed
    previous_size = 0
    for line in path.read_text().splitlines():
        entry = json.loads(line)
        size = entry['events_prefix_bytes']
        trial = entry['failed_trial_id']
        if (entry.get('event') != 'RECOVERY_VERIFIED'
                or entry.get('schema_version') != 1
                or type(size) is not int or not previous_size <= size <= len(events_bytes)
                or entry['events_prefix_sha256'] != digest(events_bytes[:size])
                or entry['manifest_sha256'] != digest(manifest_bytes)
                or entry['recovery_launcher_sha256'] != digest(Path(__file__).read_bytes())
                or trial in reviewed):
            raise ValueError('Recovery audit does not match retained events/manifest/launcher')
        reviewed.add(trial)
        previous_size = size
    return reviewed


def select_continuation(rows, events, reviewed, recover_trial=None, end_row=None):
    """Only terminated failures may be acknowledged; never skip/replay an ID."""
    audited = derive(events, rows)
    attempted = {e['trial_id'] for e in events}
    prefix = 0
    while prefix < len(rows) and rows[prefix]['trial_id'] in attempted:
        prefix += 1
    if attempted != {r['trial_id'] for r in rows[:prefix]}:
        raise ValueError('Attempted rows are not a contiguous schedule prefix')
    previous = audited[:prefix]
    if any(r['outcome'] not in {'ok', 'failed'} for r in previous):
        raise ValueError('Invalid/incomplete attempt requires review; cannot resume automatically')
    failed = {r['trial_id']: r for r in previous if r['outcome'] == 'failed'}
    if not failed:
        raise ValueError('No terminated failure; use the ordinary benchmark runner')
    if not reviewed <= failed.keys():
        raise ValueError('Recovery references a trial that is not a retained failure')
    pending = failed.keys() - reviewed
    if recover_trial is not None:
        if pending != {recover_trial}:
            raise ValueError('Specify exactly the unreviewed failed trial: ' + ', '.join(sorted(pending)))
    elif pending:
        raise ValueError('Explicit --recover-trial and --note required for: ' + ', '.join(sorted(pending)))
    if prefix == len(rows):
        raise ValueError('No unattempted rows remain; retain failure and analyze the campaign')
    end_row = len(rows) if end_row is None else end_row
    if not prefix+1 <= end_row <= len(rows):
        raise ValueError(f'--end-row must be between {prefix+1} and {len(rows)}')
    return prefix+1, rows[prefix:end_row], failed.get(recover_trial)


def verify_recovery(node, run_dir, failed, next_row, row, note,
                    events_bytes, manifest_bytes):
    # Identical readiness and stationary checks to the normal check command.
    # run_trial will reserve the device and repeat its start check before motion.
    ready = node.preflight()
    endpoint = node.wait_pose(row['start'])
    if failed is None:
        return
    if (run_dir/'events.jsonl').read_bytes() != events_bytes:
        raise ValueError('Events changed during recovery verification')
    if (run_dir/'manifest.json').read_bytes() != manifest_bytes:
        raise ValueError('Manifest changed during recovery verification')
    record = {
        'schema_version': 1, 'event': 'RECOVERY_VERIFIED',
        'timestamp_utc': utc_now(), 'monotonic_ns': time.monotonic_ns(),
        'host': socket.gethostname(), 'boot_id': system_boot_id(),
        'git_commit': git_commit(ROOT), 'operator_note': note,
        'failed_trial_id': failed['trial_id'], 'failure_reason': failed['reason'],
        'next_row': next_row, 'next_trial_id': row['trial_id'],
        'verified_start': row['start'], 'endpoint': endpoint, 'adapter_readiness': ready,
        'events_prefix_bytes': len(events_bytes), 'events_prefix_sha256': digest(events_bytes),
        'manifest_sha256': digest(manifest_bytes),
        'recovery_launcher_sha256': digest(Path(__file__).read_bytes()),
    }
    with (run_dir/'recoveries.jsonl').open('a', encoding='utf-8') as stream:
        stream.write(json.dumps(record, sort_keys=True, allow_nan=False)+'\n')
        stream.flush()
        os.fsync(stream.fileno())  # recovery must be durable before any motion
    print('Recovery verified and recorded; failed measurement retained unchanged.', flush=True)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--run-dir', type=Path, required=True)
    parser.add_argument('--recover-trial', help='Exact failed trial ID; required for each new failure')
    parser.add_argument('--note', help='Operator recovery action and observations')
    parser.add_argument('--end-row', type=int, help='Inclusive original schedule row limit')
    parser.add_argument('--check-only', action='store_true', help='Check readiness; no motion or recovery record')
    args = parser.parse_args()
    if bool(args.recover_trial) != bool(args.note and args.note.strip()):
        parser.error('--recover-trial and a nonblank --note must be supplied together')
    run_dir = args.run_dir.expanduser().resolve()
    (ROOT/'runtime').mkdir(exist_ok=True)
    with (ROOT/'runtime/laptop_benchmark.lock').open('a') as lock:
        fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
        cfg = verify_run(run_dir)  # no exception to any original freeze check
        if cfg['device'] != 'crane':
            raise ValueError('This recovery launcher is for crane campaigns only')
        manifest_bytes = (run_dir/'manifest.json').read_bytes()
        events_bytes = (run_dir/'events.jsonl').read_bytes()
        events = read_events([run_dir/'events.jsonl'])
        if events_bytes != (run_dir/'events.jsonl').read_bytes():
            raise ValueError('Events changed while loading campaign')
        rows = read_schedule(run_dir/'schedule.csv')
        reviewed = reviewed_failures(run_dir, events_bytes, manifest_bytes)
        next_row, selected, failed = select_continuation(
            rows, events, reviewed, args.recover_trial, args.end_row)
        row = selected[0]
        print(f"Next original row {next_row}: {row['trial_id']}, "
              f"{row['mode']} {row['start']} -> {row['target']}. "
              f"Operator must first restore stationary endpoint {row['start']}.", flush=True)
        from benchmark.crane_client import CraneRunner
        node = None
        try:
            node = CraneRunner(cfg, run_dir)
            if args.check_only:
                node.preflight()
                endpoint = node.wait_pose(row['start'])
                print('PASS: readiness and start endpoint; no motion or recovery recorded.', endpoint)
                return
            verify_recovery(node, run_dir, failed, next_row, row, args.note,
                            events_bytes, manifest_bytes)
            for row in selected:
                if not node.run_trial(row):
                    raise RuntimeError('Trial failed; campaign stopped')
        except BaseException:
            print('STOPPED. Preserve events.jsonl and recoveries.jsonl. '
                  'Verify the crane has stopped before further commands.', file=sys.stderr)
            raise
        finally:
            if node is not None:
                node.close()


if __name__ == '__main__':
    main()
