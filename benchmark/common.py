"""Common configuration, MQTT, and schedule helpers for benchmark runners."""

from __future__ import annotations

import csv
import json
import math
import threading
from datetime import datetime, timezone
from pathlib import Path
from typing import Any, Dict, Mapping

import paho.mqtt.client as mqtt
import yaml


def load_config(path: Path) -> Dict[str, Any]:
    data = yaml.safe_load(path.read_text(encoding="utf-8"))
    if not isinstance(data, dict):
        raise ValueError(f"Benchmark config {path} must contain a YAML object")
    if not data.get("configured", False):
        raise ValueError(
            f"Benchmark config {path} is not frozen: set configured: true only "
            "after verifying all physical coordinates"
        )
    return data


def finite_number(value: Any, name: str) -> float:
    try:
        result = float(value)
    except (TypeError, ValueError) as exc:
        raise ValueError(f"{name} must be a finite number") from exc
    if not math.isfinite(result):
        raise ValueError(f"{name} must be a finite number")
    return result


def normalize_angle(value: float) -> float:
    return math.atan2(math.sin(value), math.cos(value))


def utc_now() -> str:
    return datetime.now(timezone.utc).isoformat(timespec="milliseconds").replace(
        "+00:00", "Z"
    )


def load_schedule_row(path: Path, row_number: int) -> Dict[str, str]:
    with path.open(newline="", encoding="utf-8") as stream:
        rows = list(csv.DictReader(stream))
    if row_number < 1 or row_number > len(rows):
        raise ValueError(f"Schedule row must be 1..{len(rows)}, got {row_number}")
    return dict(rows[row_number - 1])


class MqttSession:
    """Small Paho lifecycle wrapper shared by both physical runners."""

    def __init__(self, host: str, port: int, client_id: str) -> None:
        try:
            self.client = mqtt.Client(
                mqtt.CallbackAPIVersion.VERSION2,
                client_id=client_id,
                clean_session=True,
            )
        except (AttributeError, TypeError):
            self.client = mqtt.Client(client_id=client_id, clean_session=True)
        self.host = host
        self.port = port
        self.connected = threading.Event()
        self.error = ""
        self.client.on_connect = self._on_connect

    def _on_connect(self, client, userdata, flags, rc, properties=None) -> None:
        # Paho 1.x passes an integer while Paho 2.x passes a ReasonCode.
        # ``is_failure`` is the stable 2.x API and avoids depending on whether
        # the installed ReasonCode implements ``int()``.
        failed = bool(getattr(rc, "is_failure", False))
        if not failed and (getattr(rc, "value", rc) == 0):
            self.connected.set()
        else:
            self.error = f"MQTT connection rejected: {rc}"
            self.connected.set()

    def start(self, timeout: float = 10.0) -> None:
        self.client.connect_async(self.host, self.port, keepalive=20)
        self.client.loop_start()
        if not self.connected.wait(timeout):
            self.client.loop_stop()
            raise TimeoutError(f"MQTT connection to {self.host}:{self.port} timed out")
        if self.error:
            self.client.loop_stop()
            raise RuntimeError(self.error)

    def stop(self) -> None:
        try:
            self.client.disconnect()
        finally:
            self.client.loop_stop()

    def publish_json(self, topic: str, payload: Mapping[str, Any], qos: int = 0) -> None:
        info = self.client.publish(
            topic,
            json.dumps(payload, separators=(",", ":"), allow_nan=False),
            qos=qos,
            retain=False,
        )
        if getattr(info, "rc", mqtt.MQTT_ERR_SUCCESS) != mqtt.MQTT_ERR_SUCCESS:
            raise RuntimeError(f"MQTT publish failed rc={info.rc} topic={topic}")
