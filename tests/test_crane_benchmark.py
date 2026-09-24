"""Matched crane primitive and laptop timing contract, using simulated I/O only."""
import copy
import json
import queue
import tempfile
import threading
import unittest
from pathlib import Path
from types import SimpleNamespace
from unittest.mock import patch
import yaml
import jsonschema
from crane_edge.hoist_benchmark import execute, motion_id, validate_motion
from crane_edge.benchmark_bridge import CraneBenchmark
from benchmark.generate_schedule import build_rows
from benchmark.measurement import Measurement, PROTOCOL
from analysis.derive_latency import derive
from test_benchmark_pipeline import MemoryLogger
from test_laptop_nav2_callbacks import methods

ROOT = Path(__file__).resolve().parents[1]


class Clock:
    def __init__(self): self.now = 100.
    def monotonic(self): return self.now
    def sleep(self, value): self.now += value


class Crane:
    endpoint_url = 'opc.tcp://example:4840'
    def __init__(self):
        self.z = 2500
        self.target = None
        self.log = []
        self.automatic = True
        self.fail_write = False
        self.stall = False
    def is_automatic_mode(self): return self.automatic
    def get_hoist_position_absolute(self): return self.z
    def get_speed_scale(self): return 1.
    def get_hoist_speed_feedback(self): return 0.
    def get_bridge_speed_feedback(self): return 0.
    def get_trolley_speed_feedback(self): return 0.
    def set_target_hoist(self, z): self.target=z; self.log.append('local_target')
    def move_hoist_to_target(self, threshold, fast):
        if self.fail_write: raise OSError('OPC UA write failed')
        if self.z == self.target: self.stop_hoist(); return 1
        self.log.append('writes_returned')
        if not self.stall: self.z = self.target
        return 0
    def stop_hoist(self): self.log.append('stop')
    def stop_all(self, **kwargs): self.stop_hoist()


class CraneBenchmarkTests(unittest.TestCase):
    def setUp(self):
        self.cfg = yaml.safe_load((ROOT/'benchmark/config/crane_benchmark.yaml').read_text())
        self.cfg.update(configured=True, opcua_url=Crane.endpoint_url)
        self.motion = self.cfg['hoist']
        self.clock = Clock()
        self.crane = Crane()

    def run_motion(self, ack=None, canceled=lambda: False):
        with patch('crane_edge.hoist_benchmark.time', self.clock):
            return execute(self.crane, self.motion, 'A', 'B', ack or (lambda: self.crane.log.append('ack')), canceled=canceled)

    def test_ack_follows_motion_writes_not_local_assignment(self):
        endpoint = self.run_motion()
        self.assertEqual(['local_target', 'writes_returned', 'ack', 'stop'], self.crane.log)
        self.assertEqual(0, endpoint['height_error_mm'])
        self.assertGreaterEqual(self.clock.now, 101)

    def test_write_failure_never_fabricates_ack_and_attempts_stop(self):
        self.crane.fail_write=True
        with self.assertRaises(OSError): self.run_motion()
        self.assertNotIn('ack', self.crane.log)
        self.assertEqual('stop', self.crane.log[-1])

    def test_stall_timeout_stops_and_has_no_completion(self):
        self.crane.stall=True
        with self.assertRaises(TimeoutError): self.run_motion()
        self.assertEqual(1, self.crane.log.count('ack'))
        self.assertEqual('stop', self.crane.log[-1])

    def test_cancel_before_dispatch_never_acknowledges(self):
        with self.assertRaisesRegex(RuntimeError, 'canceled'): self.run_motion(canceled=lambda: True)
        self.assertNotIn('ack', self.crane.log)
        self.assertEqual('stop', self.crane.log[-1])

    def test_automatic_loss_after_ack_stops(self):
        def ack(): self.crane.automatic=False
        with self.assertRaisesRegex(RuntimeError, 'automatic'): self.run_motion(ack)
        self.assertEqual('stop', self.crane.log[-1])

    def test_invalid_envelope_and_zero_motion_are_rejected(self):
        cfg=copy.deepcopy(self.motion); cfg['height_b_mm']=cfg['max_height_mm']+1
        with self.assertRaises(ValueError): validate_motion(cfg)
        with self.assertRaises(ValueError): execute(self.crane,self.motion,'A','A',lambda:None)
        self.assertEqual([],self.crane.log)

    def runner_order(self):
        cls=methods('benchmark/crane_client.py','CraneRunner',{'order'})
        cls.order.__globals__.update(height=lambda cfg,key:cfg['height_a_mm' if key=='A' else 'height_b_mm'], motion_id=motion_id, utc_now=lambda:'2026-09-24T00:00:00Z')
        runner=cls(); runner.cfg=self.cfg; runner.token='ab'*16
        return runner.order({'trial_id':'crane-test','start':'A','target':'B'})

    def bridge(self):
        self.messages=[]
        adapter=SimpleNamespace(crane=self.crane, _order_active=False, _instant_motion_active=False,
           _order_queue=queue.Queue(), _ia_queue=queue.Queue(), _cancel=threading.Event(),
           _stop=threading.Event(), _stop_or_cancel=threading.Event(), _mqtt_connected=True)
        adapter.mqtt=SimpleNamespace(publish=lambda topic,body,**kw: (self.messages.append(json.loads(body)) or SimpleNamespace(rc=0)))
        adapter._action_begin=lambda *a:'move'
        adapter._action_update=lambda *a,**k:None
        adapter._action_finish=lambda *a,**k:None
        with tempfile.TemporaryDirectory() as d:
            p=Path(d)/'config.yaml';p.write_text(yaml.safe_dump(self.cfg))
            bridge=CraneBenchmark(adapter,p,'konecranes','ilmatar_1')
        bridge.probe({'protocol':PROTOCOL,'op':'reserve','token':'ab'*16,'request_id':'r','trial_id':'crane-test','mode':'vda','motion_id':motion_id(self.motion)})
        return bridge

    def test_vda_order_is_schema_valid_and_has_no_xy_command(self):
        order=self.runner_order()
        jsonschema.validate(order,json.loads((ROOT/'schemas/vda5050_v3/order.schema').read_text()))
        self.assertNotIn('nodePosition',order['nodes'][0])
        bridge=self.bridge()
        bridge.validate_order(order)
        with patch('crane_edge.hoist_benchmark.time', self.clock), patch('crane_edge.benchmark_bridge.time', self.clock):
            bridge.run(order)
        events=[p['event'] for p in self.messages]
        self.assertEqual(['READY','ACK','RESULT'],events)
        self.assertEqual(4,self.messages[-1]['status'])
        self.assertNotIn('monotonic_ns',self.messages[-1])
        self.assertEqual(['local_target','writes_returned','stop'],self.crane.log)

    def test_bridge_rejects_duplicate_and_altered_motion(self):
        bridge=self.bridge();order=self.runner_order()
        changed=copy.deepcopy(order);changed['nodes'][0]['nodePosition']={'x':0,'y':0}
        with self.assertRaises(ValueError):bridge.validate_order(changed)
        bridge.validate_order(order)
        with self.assertRaises(ValueError):bridge.validate_order(order)

    def test_exclusive_native_reservation_cannot_execute_vda_motion(self):
        bridge=self.bridge();bridge.owner['mode']='native'
        with self.assertRaises(ValueError):bridge.validate_order(self.runner_order())
        bridge.probe({'protocol':PROTOCOL,'op':'reserve','token':'cd'*16,'mode':'native','motion_id':motion_id(self.motion)})
        self.assertTrue(self.messages[-1]['error'])

    def test_expired_owner_stops_motion_and_cannot_replay_an_order(self):
        bridge=self.bridge()
        bridge.deadline=0
        with self.assertRaises(ValueError):bridge.validate_order(self.runner_order())
        calls=iter([False, True])
        bridge.adapter._stop=SimpleNamespace(wait=lambda _:next(calls))
        bridge.guard()
        self.assertTrue(bridge.adapter._cancel.is_set())
        self.assertIsNone(bridge.owner)
        self.assertEqual('stop',self.crane.log[-1])

    def test_invalid_reservation_token_is_rejected_without_claiming(self):
        bridge=self.bridge();bridge.owner=None
        bridge.probe({'protocol':PROTOCOL,'op':'reserve','token':42,'mode':'native','motion_id':motion_id(self.motion)})
        self.assertIsNone(bridge.owner)
        self.assertTrue(self.messages[-1]['error'])

    def test_operator_cancel_propagates_to_native_laptop_loop(self):
        bridge=self.bridge();bridge.owner['mode']='native'
        bridge.adapter._stop_or_cancel.set()
        bridge.probe({'protocol':PROTOCOL,'op':'heartbeat','token':'ab'*16})
        payload=self.messages[-1]
        self.assertEqual('ERROR',payload['event'])
        cls=methods('benchmark/crane_client.py','CraneRunner',{'_feedback','canceled'})
        runner=cls();runner.probe_id='p';runner.token='ab'*16
        row=build_rows('crane',1,1,'test')[0];row.update(mode='native',trial_id='crane-test')
        runner.measurement=Measurement(MemoryLogger(),row)
        runner.stop=threading.Event();runner.mqtt=SimpleNamespace(error='');runner.lease_seen=0
        runner._feedback(None,None,SimpleNamespace(retain=False,payload=json.dumps(payload)))
        self.assertIn('latched',runner.measurement.error)
        self.assertTrue(runner.canceled())
        with self.assertRaises(ValueError):bridge.validate_order(self.runner_order())

    def test_feedback_uses_laptop_callback_entry_and_ignores_stale_token(self):
        cls=methods('benchmark/crane_client.py','CraneRunner',{'_feedback'})
        runner=cls(); runner.probe_id='p';runner.token='ab'*16
        row=build_rows('crane',1,1,'test')[0];row['mode']='vda'
        m=Measurement(MemoryLogger(),row);runner.measurement=m;m.issue({})
        payload={'protocol':PROTOCOL,'event':'ACK','order_id':row['trial_id'],'goal_id':'cd'*16,'accepted':True}
        stamp=m.issued_ns+123
        with patch('time.monotonic_ns',return_value=stamp):
            runner._feedback(None,None,SimpleNamespace(retain=False,payload=json.dumps(payload)))
            self.assertIsNone(m.ack_ns)
            payload['goal_id']=runner.token
            runner._feedback(None,None,SimpleNamespace(retain=False,payload=json.dumps(payload)))
        self.assertEqual(stamp,m.ack_ns)

    def test_crane_csv_uses_distinct_endpoint_and_ack_semantics(self):
        row=build_rows('crane',1,1,'test')[0];logger=MemoryLogger();m=Measurement(logger,row)
        m.issue({});m.ack(m.issued_ns+100,True,'ab'*16);m.result(m.issued_ns+200,4,'ab'*16)
        m.finish({'height_error_mm':1})
        csv=derive(logger.events,[row])[0]
        self.assertEqual('ok',csv['outcome'])
        self.assertEqual('opcua_motion_write_batch',csv['ack_kind'])
        self.assertEqual(.0001,csv['ack_round_trip_ms'])
        self.assertEqual(1,csv['endpoint_height_error_mm'])


if __name__=='__main__': unittest.main()
