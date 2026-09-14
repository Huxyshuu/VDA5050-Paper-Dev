#!/usr/bin/env python3
"""Run one controlled Ilmatar hoist native or VDA latency trial.

Only one process may own the crane control session.  Stop the crane VDA adapter
for native rows; run it for VDA rows.  Both paths call the same
``set_target_hoist`` and ``move_hoist_to_target(fast=True)`` primitives.
"""

from __future__ import annotations

import argparse
import json
import logging
import re
import sys
import threading
import time
from pathlib import Path
from typing import Any, Dict, Optional

import jsonschema

from common import MqttSession, finite_number, load_config, load_schedule_row, utc_now
from experiment_logger import ExperimentLogger, config_identifier, publish_json_event


ROOT = Path(__file__).resolve().parents[1]
DEFAULT_CONFIG = ROOT / "benchmark/config/crane_benchmark.yaml"
DEFAULT_LOG = ROOT / "results/benchmark/crane_events.jsonl"
EVENT_TOPIC = "vda5050/benchmark/events"
_NUMBER = re.compile(r"([-+]?\d+(?:\.\d+)?)")


class CraneBenchmark:
    def __init__(self, cfg: Dict[str, Any], args: argparse.Namespace) -> None:
        self.cfg = cfg
        self.args = args
        self.architecture = "setup" if args.setup else args.mode
        self.trial_id = args.trial_id
        self.pair_id = args.pair_id
        self.command_id = args.trial_id
        self.order_id = args.trial_id if args.mode == "vda" else ""
        self.operation = self._action_type()
        mqtt_cfg = cfg["mqtt"]
        self.mqtt = MqttSession(
            str(mqtt_cfg["host"]),
            int(mqtt_cfg["port"]),
            f"crane-benchmark-{args.trial_id[-16:]}",
        )
        self.mqtt.start()
        self.logger = ExperimentLogger(
            args.log,
            repo_root=ROOT,
            source="crane_benchmark",
            config_id=config_identifier(args.config),
            publisher=publish_json_event(self.mqtt.client, EVENT_TOPIC),
        )
        self._vda_result = threading.Event()
        self._vda_success: Optional[bool] = None
        self._vda_result_text = ""
        self._latest_hoist_m: Optional[float] = None
        self._latest_bridge_m: Optional[float] = None
        self._latest_trolley_m: Optional[float] = None
        if args.mode == "vda":
            topic = f"{self._topic_root()}/state"
            self.mqtt.client.message_callback_add(topic, self._on_vda_state)
            self.mqtt.client.subscribe(topic, qos=int(mqtt_cfg.get("qos", 0)))

    def close(self) -> None:
        self.logger.close()
        self.mqtt.stop()

    def _emit(self, event_type: str, **kwargs: Any) -> None:
        self.logger.emit(
            event_type,
            trial_id=self.trial_id,
            pair_id=self.pair_id,
            architecture=self.architecture,
            device="crane",
            operation=self.operation,
            command_id=self.command_id,
            order_id=self.order_id,
            **kwargs,
        )

    def _topic_root(self) -> str:
        vda = self.cfg["vda"]
        return (
            f"{vda['interface_name']}/{vda['major_version']}/"
            f"{vda['manufacturer']}/{vda['serial_number']}"
        )

    def _endpoints(self) -> tuple[float, float]:
        hoist = self.cfg["hoist"]
        return (
            finite_number(hoist["z_a_m"], "hoist.z_a_m"),
            finite_number(hoist["z_b_m"], "hoist.z_b_m"),
        )

    def _target_m(self) -> float:
        z_a, z_b = self._endpoints()
        return z_b if self.args.direction == "a-to-b" else z_a

    def _start_m(self) -> float:
        z_a, z_b = self._endpoints()
        return z_a if self.args.direction == "a-to-b" else z_b

    def _action_type(self) -> str:
        return "raiseHoist" if self._target_m() > self._start_m() else "lowerHoist"

    def _on_vda_state(self, client, userdata, message) -> None:
        try:
            state = json.loads(message.payload.decode("utf-8"))
        except Exception:
            return
        position = state.get("mobileRobotPosition") or {}
        try:
            self._latest_bridge_m = float(position["x"])
            self._latest_trolley_m = float(position["y"])
        except (KeyError, TypeError, ValueError):
            pass
        for info in state.get("information") or []:
            if isinstance(info, dict) and info.get("infoType") == "HOIST_POSITION":
                match = _NUMBER.search(str(info.get("infoDescription", "")))
                if match:
                    self._latest_hoist_m = float(match.group(1))
        if str(state.get("orderId", "")) != self.order_id:
            return
        action_id = f"{self.trial_id}-action"
        action_state = next(
            (
                item
                for item in state.get("actionStates") or []
                if isinstance(item, dict) and str(item.get("actionId", "")) == action_id
            ),
            None,
        )
        if action_state and action_state.get("actionStatus") in {"FINISHED", "FAILED"}:
            self._vda_success = action_state.get("actionStatus") == "FINISHED"
            self._vda_result_text = str(
                action_state.get("actionResult") or action_state.get("actionStatus")
            )
            self._vda_result.set()
            return
        errors = state.get("errors") or []
        if errors:
            self._vda_success = False
            self._vda_result_text = "; ".join(
                str(item.get("errorDescription") or item.get("errorType"))
                for item in errors
                if isinstance(item, dict)
            )
            self._vda_result.set()

    def wait_for_vda_start_height(self) -> None:
        timeout = min(15.0, finite_number(self.cfg["timeouts"]["command_s"], "command_s"))
        deadline = time.monotonic() + timeout
        while (
            self._latest_hoist_m is None
            or self._latest_bridge_m is None
            or self._latest_trolley_m is None
        ) and time.monotonic() < deadline:
            time.sleep(0.05)
        if (
            self._latest_hoist_m is None
            or self._latest_bridge_m is None
            or self._latest_trolley_m is None
        ):
            raise RuntimeError("No complete crane XYZ position in VDA state; adapter must be online")
        error_mm = abs(self._latest_hoist_m - self._start_m()) * 1000.0
        tolerance = finite_number(self.cfg["tolerances"]["start_z_mm"], "start_z_mm")
        if error_mm > tolerance:
            raise RuntimeError(
                f"Crane start height error {error_mm:.1f} mm exceeds frozen tolerance"
            )
        xy_tolerance = finite_number(
            self.cfg["tolerances"]["start_xy_mm"], "start_xy_mm"
        )
        bridge_error = abs(
            self._latest_bridge_m - finite_number(self.cfg["bridge_m"], "bridge_m")
        ) * 1000.0
        trolley_error = abs(
            self._latest_trolley_m - finite_number(self.cfg["trolley_m"], "trolley_m")
        ) * 1000.0
        if max(bridge_error, trolley_error) > xy_tolerance:
            raise RuntimeError(
                "Crane start XY differs from the frozen position: "
                f"bridge={bridge_error:.1f} mm trolley={trolley_error:.1f} mm"
            )

    def run_native(self) -> None:
        crane_dir = ROOT / "crane_edge"
        sys.path.insert(0, str(crane_dir))
        from crane import Crane
        from crane_vda5050_adapter_v3 import (
            DedicatedWatchdogSession,
            WatchdogFeedGate,
            WatchdogHealth,
            _load_crane_credentials,
            _watchdog_loop,
            wait_for_crane_automatic_mode,
        )

        log = logging.getLogger("crane_native_benchmark")
        logging.basicConfig(
            level=logging.INFO,
            format="%(asctime)s.%(msecs)03d | %(levelname)s | %(message)s",
            datefmt="%H:%M:%S",
        )
        url, access = _load_crane_credentials()
        crane = Crane(url)
        watchdog = DedicatedWatchdogSession(url)
        gate = WatchdogFeedGate(5.0)
        stop = threading.Event()
        thread: Optional[threading.Thread] = None
        try:
            gate.mark_control_connected()
            crane.set_accesscode(access)
            crane.stop_all(reason="native_benchmark_preflight")
            watchdog.connect()
            health = WatchdogHealth(watchdog.snapshot)
            gate.note_guard_heartbeat("native_benchmark")
            gate.activate_runtime()
            thread = threading.Thread(
                target=_watchdog_loop,
                args=(watchdog, gate, stop, log, health, None),
                daemon=True,
                name="native-benchmark-watchdog",
            )
            thread.start()
            automatic_timeout = finite_number(
                self.cfg["timeouts"]["automatic_mode_s"], "automatic_mode_s"
            )
            if not wait_for_crane_automatic_mode(
                crane,
                log,
                feed_gate=gate,
                stop_event=stop,
                timeout=automatic_timeout,
                stable_s=1.0,
            ):
                raise RuntimeError("Crane did not enter stable automatic mode")

            start_mm = int(round(self._start_m() * 1000.0))
            current_mm = int(crane.get_hoist_position_absolute())
            start_tolerance = int(self.cfg["tolerances"]["start_z_mm"])
            if abs(current_mm - start_mm) > start_tolerance:
                raise RuntimeError(
                    f"Crane start height {current_mm} mm differs from frozen "
                    f"{start_mm} mm by more than {start_tolerance} mm"
                )
            bridge_mm = int(crane.get_bridge_position_absolute())
            trolley_mm = int(crane.get_trolley_position_absolute())
            expected_bridge_mm = int(
                round(finite_number(self.cfg["bridge_m"], "bridge_m") * 1000.0)
            )
            expected_trolley_mm = int(
                round(finite_number(self.cfg["trolley_m"], "trolley_m") * 1000.0)
            )
            xy_tolerance = int(self.cfg["tolerances"]["start_xy_mm"])
            if max(
                abs(bridge_mm - expected_bridge_mm),
                abs(trolley_mm - expected_trolley_mm),
            ) > xy_tolerance:
                raise RuntimeError(
                    "Crane native start XY differs from the frozen benchmark position"
                )
            target_mm = int(round(self._target_m() * 1000.0))
            self._emit(
                "COMMAND_ISSUED",
                result=f"Native hoist command issued for {target_mm} mm",
                success=True,
            )
            self._emit(
                "NATIVE_DISPATCH",
                result="Calling the crane target interface",
                success=True,
                details={"target_mm": target_mm},
            )
            if self.operation == "raiseHoist":
                crane.stop_hoist()
            crane.set_target_hoist(target_mm)
            self._emit(
                "NATIVE_ACK",
                result="Crane target interface returned",
                success=True,
            )
            motion_started = False
            initial_mm = current_mm
            deadline = time.monotonic() + finite_number(
                self.cfg["timeouts"]["command_s"], "command_s"
            )
            while time.monotonic() < deadline:
                gate.note_guard_heartbeat("native_benchmark")
                done = bool(crane.move_hoist_to_target(fast=True))
                current_mm = int(crane.get_hoist_position_absolute())
                if (
                    not motion_started
                    and abs(current_mm - initial_mm)
                    >= int(self.cfg["tolerances"]["motion_start_mm"])
                ):
                    motion_started = True
                    self._emit(
                        "MOTION_STARTED",
                        result=f"Hoist moved from {initial_mm} to {current_mm} mm",
                        success=True,
                    )
                if done:
                    crane.stop_hoist()
                    target_error_mm = abs(current_mm - target_mm)
                    target_tolerance = int(self.cfg["tolerances"]["target_z_mm"])
                    success = target_error_mm <= target_tolerance
                    self._emit(
                        "MOTION_COMPLETED",
                        result=(
                            f"Hoist reached {current_mm} mm; error={target_error_mm} mm"
                        ),
                        success=success,
                    )
                    self._emit(
                        "RESULT_OBSERVED",
                        result="Native hoist completion observed and endpoint checked",
                        success=success,
                    )
                    if not success:
                        raise RuntimeError(
                            f"Crane final height error {target_error_mm} mm exceeds "
                            f"{target_tolerance} mm"
                        )
                    return
                time.sleep(0.1)
            crane.stop_hoist()
            self._emit("RESULT_OBSERVED", result="Native hoist trial timed out", success=False)
            raise TimeoutError("Native crane trial timed out")
        finally:
            try:
                crane.stop_all(reason="native_benchmark_shutdown")
            except Exception:
                pass
            gate.shutdown()
            stop.set()
            if thread is not None:
                thread.join(timeout=2.0)
            try:
                watchdog.disconnect()
            finally:
                crane.disconnect()

    def _vda_order(self) -> Dict[str, Any]:
        vda = self.cfg["vda"]
        target_m = self._target_m()
        action_type = self._action_type()
        parameter = "zu" if action_type == "raiseHoist" else "zd"
        x = finite_number(self.cfg["bridge_m"], "bridge_m")
        y = finite_number(self.cfg["trolley_m"], "trolley_m")
        position = {"x": x, "y": y, "mapId": str(self.cfg["map_id"])}
        return {
            "headerId": int(time.time_ns() % 2_147_483_647),
            "timestamp": utc_now(),
            "version": str(vda["protocol_version"]),
            "manufacturer": str(vda["manufacturer"]),
            "serialNumber": str(vda["serial_number"]),
            "orderId": self.order_id,
            "orderUpdateId": 0,
            "orderDescription": "Controlled Ilmatar hoist benchmark",
            "nodes": [
                {
                    "nodeId": f"{self.trial_id}-start",
                    "sequenceId": 0,
                    "released": True,
                    "nodePosition": dict(position),
                    "actions": [],
                },
                {
                    "nodeId": f"{self.trial_id}-target",
                    "sequenceId": 2,
                    "released": True,
                    "nodePosition": dict(position),
                    "actions": [
                        {
                            "actionId": f"{self.trial_id}-action",
                            "actionType": action_type,
                            "blockingType": "HARD",
                            "actionParameters": [{"key": parameter, "value": target_m}],
                        }
                    ],
                },
            ],
            "edges": [
                {
                    "edgeId": f"{self.trial_id}-edge",
                    "sequenceId": 1,
                    "released": True,
                    "actions": [],
                }
            ],
        }

    def run_vda(self) -> None:
        order = self._vda_order()
        schema = json.loads(
            (ROOT / "schemas/vda5050_v3/order.schema").read_text(encoding="utf-8")
        )
        jsonschema.validate(order, schema)
        self._emit("COMMAND_ISSUED", result="Publishing VDA crane order", success=True)
        self.mqtt.publish_json(
            f"{self._topic_root()}/order",
            order,
            qos=int(self.cfg["mqtt"].get("qos", 0)),
        )
        timeout = finite_number(self.cfg["timeouts"]["command_s"], "command_s")
        if not self._vda_result.wait(timeout):
            self._emit(
                "RESULT_OBSERVED",
                result="Timed out waiting for VDA action",
                success=False,
            )
            raise TimeoutError("VDA crane trial timed out")
        if self._vda_success:
            if self._latest_hoist_m is None:
                self._vda_success = False
                self._vda_result_text = "No final hoist telemetry was available"
            else:
                error_mm = abs(self._latest_hoist_m - self._target_m()) * 1000.0
                tolerance = finite_number(
                    self.cfg["tolerances"]["target_z_mm"], "target_z_mm"
                )
                if error_mm > tolerance:
                    self._vda_success = False
                    self._vda_result_text = (
                        f"Final hoist error {error_mm:.1f} mm exceeds {tolerance:.1f} mm"
                    )
        self._emit(
            "RESULT_OBSERVED",
            result=self._vda_result_text,
            success=self._vda_success,
        )
        if not self._vda_success:
            raise RuntimeError(self._vda_result_text or "VDA crane trial failed")


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser()
    parser.add_argument("--mode", choices=("native", "vda"))
    parser.add_argument("--direction", choices=("a-to-b", "b-to-a"))
    parser.add_argument("--trial-id")
    parser.add_argument("--pair-id", default="")
    parser.add_argument("--config", type=Path, default=DEFAULT_CONFIG)
    parser.add_argument("--log", type=Path, default=DEFAULT_LOG)
    parser.add_argument("--schedule", type=Path)
    parser.add_argument("--row", type=int)
    parser.add_argument("--setup", action="store_true", help="Mark supervised reset as excluded")
    args = parser.parse_args()
    if args.schedule:
        if args.row is None:
            parser.error("--schedule requires --row")
        row = load_schedule_row(args.schedule, args.row)
        if row.get("device") != "crane":
            parser.error(f"Schedule row {args.row} is for {row.get('device')!r}, not crane")
        args.mode = row["mode"]
        args.direction = "a-to-b" if row["start"] == "A" else "b-to-a"
        args.trial_id = row["trial_id"]
        args.pair_id = row["pair_id"]
        args.setup = row.get("measure", "true").lower() != "true"
    if not args.direction or not args.trial_id:
        parser.error("Provide --direction and --trial-id, or --schedule and --row")
    if not args.mode:
        parser.error("Provide --mode, or load it from --schedule and --row")
    return args


def main() -> None:
    args = parse_args()
    cfg = load_config(args.config)
    runner = CraneBenchmark(cfg, args)
    try:
        if args.mode == "vda":
            runner.wait_for_vda_start_height()
        print(
            f"Running {runner.architecture} {args.direction} trial {args.trial_id}. "
            "Keep the E-stop available."
        )
        if args.mode == "native":
            runner.run_native()
        else:
            runner.run_vda()
        print("Trial completed successfully")
    finally:
        runner.close()


if __name__ == "__main__":
    main()
