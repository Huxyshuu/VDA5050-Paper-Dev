"""Exercise actual adapter/Pi callback methods without ROS hardware imports."""
import ast
import copy
import json
import threading
import time
import unittest
from pathlib import Path
from types import SimpleNamespace
from unittest.mock import patch

from benchmark.pi_measurement import Measurement, PROTOCOL
from test_benchmark_pipeline import MemoryLogger

ROOT = Path(__file__).resolve().parents[1]


def methods(path, class_name, names):
    tree = ast.parse((ROOT/path).read_text())
    cls = next(n for n in tree.body if isinstance(n,ast.ClassDef) and n.name==class_name)
    body = [n for n in cls.body if isinstance(n,ast.FunctionDef) and n.name in names]
    ns = {'json':json, 'time':time, 'copy':copy, 'threading':threading,
          'PROTOCOL':PROTOCOL, 'GoalStatus':SimpleNamespace(STATUS_SUCCEEDED=4)}
    for node in body:
        node.returns = None
        for arg in node.args.args + node.args.kwonlyargs: arg.annotation = None
    exec(compile(ast.Module(body=body, type_ignores=[]), str(path),'exec'),ns)
    return type(class_name,(),{n:ns[n] for n in names})


class Future:
    def __init__(self, value): self.value=value; self.callback=None
    def result(self): return self.value
    def add_done_callback(self, callback): self.callback=callback


class Nav2CallbacksTests(unittest.TestCase):
    def setUp(self):
        self.messages=[]
        cls=methods('ros2_ws/src/rox_vda5050_adapter/rox_vda5050_adapter/rox_vda5050_adapter.py',
                    'RoxVda5050Adapter', {'_nav2_feedback','_on_goal_response','_on_nav_result'})
        self.adapter=cls()
        a=self.adapter
        a._feedback_topic='response'
        a._mqtt=SimpleNamespace(publish=lambda topic,body,**kw:self.messages.append((json.loads(body),kw)))
        a._order={'orderId':'trial-1','orderDescription':'pi-nav2-v1 benchmark'}
        a._nodes=[{}, {'nodeId':'trial-1-target'}]
        a._paused=a._cancelled=False
        a._add_error=lambda *args:None
        a._on_node_reached=lambda index:None
        self.context={'order':a._order,'node':a._nodes[1]}

    def test_vda_feedback_only_follows_actual_nav2_responses(self):
        a=self.adapter
        result=Future(SimpleNamespace(status=4,result=SimpleNamespace(error_code=0,error_msg='')))
        handle=SimpleNamespace(accepted=True,goal_id=SimpleNamespace(uuid=list(range(16))),
                               get_result_async=lambda:result)
        a._on_goal_response(Future(handle),1,self.context)
        self.assertEqual(['ACK'],[m[0]['event'] for m in self.messages])
        result.callback(result)
        self.assertEqual(['ACK','RESULT'],[m[0]['event'] for m in self.messages])
        for payload, kwargs in self.messages:
            self.assertNotIn('monotonic_ns',payload)
            self.assertNotIn('timestamp',payload)
            self.assertEqual(1,kwargs['qos'])
            self.assertFalse(kwargs['retain'])

    def test_rejected_nav2_goal_is_not_reported_as_accepted(self):
        handle=SimpleNamespace(accepted=False,goal_id=SimpleNamespace(uuid=[1]*16))
        self.adapter._on_goal_response(Future(handle),1,self.context)
        self.assertFalse(self.messages[0][0]['accepted'])
        self.assertEqual(1,len(self.messages))

    def test_pi_timestamps_mqtt_callback_entry_and_ignores_old_order(self):
        cls=methods('benchmark/pi_ros.py','PiRunner',{'_feedback'})
        pi=cls(); pi.probe_id='probe'; pi.ready_event=threading.Event()
        row={'trial_id':'trial-1','pair_id':'pair-1','mode':'vda','measure':'true','start':'A','target':'B'}
        logger=MemoryLogger(); m=Measurement(logger,row); pi.measurement=m
        m.issue({}); stamp=m.issued_ns+50_000
        payload={'protocol':PROTOCOL,'event':'ACK','order_id':'old',
                 'node_id':'trial-1-target','goal_id':'ab'*16,'accepted':True}
        with patch('time.monotonic_ns',return_value=stamp):
            pi._feedback(None,None,SimpleNamespace(retain=False,payload=json.dumps(payload).encode()))
            self.assertIsNone(m.ack_ns)
            payload['order_id']='trial-1'
            pi._feedback(None,None,SimpleNamespace(retain=False,payload=json.dumps(payload).encode()))
        self.assertEqual(stamp,m.ack_ns)

    def test_pi_native_callbacks_record_same_milestones(self):
        cls=methods('benchmark/pi_ros.py','PiRunner',{'_native_ack','_native_result'})
        pi=cls(); logger=MemoryLogger()
        row={'trial_id':'n','pair_id':'p','mode':'native','measure':'true','start':'A','target':'B'}
        m=Measurement(logger,row); m.issue({})
        result=Future(SimpleNamespace(status=4,result=SimpleNamespace()))
        handle=SimpleNamespace(accepted=True,goal_id=SimpleNamespace(uuid=[2]*16),get_result_async=lambda:result)
        pi._native_ack(Future(handle),m)
        self.assertIsNotNone(m.ack_ns)
        self.assertIsNone(m.result_ns)
        result.callback(result)
        self.assertEqual(['COMMAND_ISSUED','NAV2_ACK_RECEIVED','NAV2_RESULT_RECEIVED'],
                         [e['event_type'] for e in logger.events])

    def test_vda_goal_has_the_same_frozen_target_as_native(self):
        import yaml, jsonschema
        cls=methods('benchmark/pi_ros.py','PiRunner',{'target','vda_order'})
        cls.vda_order.__globals__['utc_now']=lambda:'2026-09-15T00:00:00Z'
        pi=cls(); pi.cfg=yaml.safe_load((ROOT/'benchmark/config/rox_benchmark.yaml').read_text())
        row={'trial_id':'trial-1','start':'A','target':'B'}
        order=pi.vda_order(row)
        jsonschema.validate(order,json.loads((ROOT/'schemas/vda5050_v3/order.schema').read_text()))
        target=order['nodes'][1]['nodePosition']
        self.assertEqual(pi.target('B'),{k:target[k] for k in ('x','y','theta')})

    def test_ui_uses_the_two_pi_durations_and_preserves_ns_as_text(self):
        from test_benchmark_pipeline import trial_events
        path='fleet_control/dashboard_v3.py'
        tree=ast.parse((ROOT/path).read_text())
        name=next(n.name for n in tree.body if isinstance(n,ast.ClassDef)
                  and any(isinstance(x,ast.FunctionDef) and x.name=='_benchmark_projection' for x in n.body))
        cls=methods(path,name,{'_benchmark_projection'}); panel=cls()
        row={'trial_id':'v','pair_id':'p','mode':'vda','measure':'true','start':'A','target':'B'}
        events=trial_events(row,40,5040)
        for e in events:e['monotonic_ns']+=10**17
        panel.ctx={'BENCHMARK_EVENTS':events}
        data=panel._benchmark_projection()
        self.assertEqual(40,data['trials'][0]['ack_ms'])
        self.assertEqual(5040,data['trials'][0]['completion_ms'])
        self.assertIsInstance(data['events'][0]['monotonic_ns'],str)


if __name__=='__main__': unittest.main()
