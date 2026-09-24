"""Laptop direct OPC UA and VDA clients; all measurement timestamps are local."""
from __future__ import annotations
import json
import hashlib
import threading
import time
import uuid
from pathlib import Path
import jsonschema
from benchmark.common import MqttSession, utc_now
from benchmark.experiment_logger import ExperimentLogger, config_identifier, publish_json_event
from benchmark.measurement import EVENT_TOPIC, PROTOCOL, Measurement
from crane_edge.crane import Crane
from crane_edge.hoist_benchmark import check_position, execute, height, motion_id

ROOT = Path(__file__).resolve().parents[1]


class CraneRunner:
    def __init__(self, cfg, run_dir):
        self.cfg, self.run_dir = cfg, run_dir
        self.measurement = None
        self.ready, self.probe_id = None, ""
        self.ready_event = threading.Event()
        self.stop = threading.Event()
        self.token = None
        self.lease_seen = 0.0
        self.crane = None
        self.heartbeat = None
        vda, mqtt = cfg['vda'], cfg['mqtt']
        self.root = '/'.join(vda[k] for k in ('interface_name', 'major_version', 'manufacturer', 'serial_number'))
        self.feedback = f"vda5050/benchmark/crane/{vda['manufacturer']}/{vda['serial_number']}"
        self.mqtt = MqttSession(mqtt['host'], int(mqtt['port']), 'laptop-crane-'+uuid.uuid4().hex[:12])
        self.mqtt.client.on_message = self._feedback
        self.logger = ExperimentLogger(run_dir/'events.jsonl', repo_root=ROOT, source='laptop_runner',
            config_id=config_identifier(run_dir/'config.yaml'), publisher=publish_json_event(self.mqtt.client, EVENT_TOPIC))
        try:
            self.mqtt.start()
            self.mqtt.subscribe(self.feedback, qos=1)
            self.crane = Crane(cfg['opcua_url'])  # connect outside timing; no watchdog/access-code writes
            self.heartbeat = threading.Thread(target=self._heartbeat, daemon=True)
            self.heartbeat.start()
        except BaseException:
            self.close()
            raise

    def close(self):
        self.stop.set()
        if self.heartbeat:
            self.heartbeat.join(timeout=1)
        if self.crane:
            self.crane.disconnect()
        self.logger.close()
        self.mqtt.stop()

    def _feedback(self, client, userdata, message):
        received_ns = time.monotonic_ns()  # first operation: laptop callback entry
        if message.retain:
            return
        try:
            p = json.loads(message.payload)
        except (ValueError, UnicodeDecodeError):
            return
        if not isinstance(p, dict) or p.get('protocol') != PROTOCOL:
            return
        if p.get('event') == 'LEASE' and p.get('token') == self.token:
            self.lease_seen = time.monotonic()
            return
        if p.get('event') == 'READY' and p.get('request_id') == self.probe_id:
            self.ready = p
            self.ready_event.set()
            return
        m = self.measurement
        if m is None or p.get('order_id') != m.row['trial_id']:
            return
        if p.get('event') == 'ERROR':
            if m.row['mode'] == 'vda' or p.get('goal_id') == self.token:
                m.fail(str(p.get('error', 'Crane adapter rejected command')))
        elif m.row['mode'] == 'vda' and p.get('goal_id') == self.token:
            if p.get('event') == 'ACK':
                m.ack(received_ns, p.get('accepted'), p.get('goal_id'))
            elif p.get('event') == 'RESULT':
                m.result(received_ns, p.get('status'), p.get('goal_id'))

    def _heartbeat(self):
        while not self.stop.wait(0.25):
            if self.token:
                try:
                    self.mqtt.publish_json(self.feedback+'/probe', {'protocol': PROTOCOL, 'op': 'heartbeat', 'token': self.token}, qos=1)
                except Exception as exc:
                    self.mqtt.error = str(exc)

    def probe(self, *, allow_busy=False, **fields):
        self.probe_id = uuid.uuid4().hex
        self.ready_event.clear()
        self.mqtt.publish_json(self.feedback+'/probe', {'protocol': PROTOCOL, 'request_id': self.probe_id, **fields}, qos=1)
        if not self.ready_event.wait(5):
            raise TimeoutError('No crane benchmark handshake; enable CRANE_BENCHMARK_CONFIG on Pi')
        p = self.ready
        if p.get('error'):
            raise RuntimeError(p['error'])
        expected = {'motion_id': motion_id(self.cfg['hoist']), 'opcua_url': self.cfg['opcua_url'],
                    'automatic': True, 'busy': False, 'order_qos': 0, 'feedback_qos': 1,
                    'source_hashes': {name: hashlib.sha256((ROOT/'crane_edge'/name).read_bytes()).hexdigest()
                                      for name in ('benchmark_bridge.py', 'hoist_benchmark.py', 'crane.py', 'crane_vda5050_adapter_v3.py')}}
        if allow_busy:
            expected.pop("busy")
        for k, v in expected.items():
            if p.get(k) != v:
                raise RuntimeError(f'Crane handshake {k}: expected {v!r}, got {p.get(k)!r}')
        return p

    def preflight(self):
        p = self.probe()
        if p.get('reserved'):
            raise RuntimeError('Crane already reserved by another attempt')
        if self.mqtt.error or self.logger.error or not self.logger.flush():
            raise RuntimeError(self.mqtt.error or self.logger.error or 'Logger is not writable')
        return p

    def wait_pose(self, endpoint, **_):
        deadline = time.monotonic()+5
        settled = None
        while time.monotonic() < deadline:
            result = check_position(self.crane, self.cfg['hoist'], endpoint)
            settled = settled if settled is not None else time.monotonic()
            if time.monotonic()-settled >= self.cfg['hoist']['settle_s']:
                return result
            time.sleep(self.cfg['hoist']['poll_s'])
        raise TimeoutError('Crane start/end point did not settle')

    def order(self, row):
        v = self.cfg['vda']
        action = 'lowerHoist' if height(self.cfg['hoist'], row['target']) < height(self.cfg['hoist'], row['start']) else 'raiseHoist'
        params = {'start': row['start'], 'target': row['target'], 'motionId': motion_id(self.cfg['hoist']), 'token': self.token}
        return {'headerId': time.time_ns()%2147483647, 'timestamp': utc_now(), 'version': v['protocol_version'],
            'manufacturer': v['manufacturer'], 'serialNumber': v['serial_number'], 'orderId': row['trial_id'],
            'orderUpdateId': 0, 'orderDescription': PROTOCOL+' benchmark', 'edges': [],
            'nodes': [{'nodeId': row['trial_id']+'-hoist', 'sequenceId': 0, 'released': True, 'actions': [
                {'actionId': row['trial_id']+'-move', 'actionType': action, 'blockingType': 'HARD',
                 'actionParameters': [{'key': k, 'value': val} for k, val in params.items()]}]}]}

    def canceled(self):
        return bool(self.stop.is_set() or self.mqtt.error or (self.measurement and self.measurement.error)
                    or time.monotonic()-self.lease_seen > 1.5)

    def run_trial(self, row):
        self.measurement = m = Measurement(self.logger, row)
        endpoint = None
        try:
            self.preflight()
            self.token = uuid.uuid4().hex
            self.probe(op='reserve', token=self.token, trial_id=row['trial_id'], mode=row['mode'], motion_id=motion_id(self.cfg['hoist']))
            self.lease_seen = time.monotonic()
            self.wait_pose(row['start'])
            order = self.order(row)
            jsonschema.validate(order, json.loads((ROOT/'schemas/vda5050_v3/order.schema').read_text()))
            print(f"{row['trial_id']}: {row['mode']} hoist {row['start']} → {row['target']}", flush=True)
            m.issue({'height_mm': height(self.cfg['hoist'], row['target'])})
            if row['mode'] == 'native':
                endpoint = execute(self.crane, self.cfg['hoist'], row['start'], row['target'],
                    lambda: m.ack(time.monotonic_ns(), True, self.token), canceled=self.canceled)
                received_ns = time.monotonic_ns()  # native terminal primitive returned on laptop
                m.result(received_ns, 4, self.token)
            else:
                self.mqtt.publish_json(self.root+'/order', order, qos=0)
                deadline = time.monotonic()+self.cfg['hoist']['timeout_s']+5
                while not m.done.wait(0.02):
                    if self.canceled() or time.monotonic() >= deadline:
                        raise TimeoutError('Crane response/lease timeout')
                if m.error:
                    raise RuntimeError(m.error)
            endpoint = self.wait_pose(row['target'])  # independent verification outside timing
            for _ in range(30):
                self.mqtt.publish_json(self.feedback+'/probe', {'protocol': PROTOCOL, 'op': 'release', 'token': self.token}, qos=1)
                time.sleep(0.1)
                if not self.probe(allow_busy=True).get('reserved'):
                    self.token = None
                    break
            else:
                raise RuntimeError('Crane reservation was not released')
        except BaseException as exc:
            m.fail(f'{type(exc).__name__}: {exc}')
            if m.issued_ns is not None:
                # Immediate direct STOP also works if MQTT is unavailable. Lease expiry
                # makes the adapter cancel its loop, so it cannot keep reissuing motion.
                self.stop.set()
                try:
                    self.mqtt.publish_json(self.feedback+'/probe', {'protocol': PROTOCOL, 'op': 'abort', 'token': self.token}, qos=1)
                except Exception:
                    pass
                try:
                    self.crane.stop_all(reason='benchmark_abort')
                except Exception:
                    pass
            m.finish()
            self.logger.flush()
            raise
        success = m.finish(endpoint)
        if not self.logger.flush() or self.logger.error or not success:
            raise RuntimeError(m.error or self.logger.error or 'Crane attempt failed')
        print(f'T_ack={(m.ack_ns-m.issued_ns)/1e6:.3f} ms; T_completion={(m.result_ns-m.issued_ns)/1e6:.3f} ms')
        return success
