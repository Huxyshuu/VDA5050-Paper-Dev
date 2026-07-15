"""Small VDA 5050 v3.0 JSON/MQTT helpers shared by the ROX-Diff adapter."""

from __future__ import annotations

import json
from datetime import datetime, timezone
from pathlib import Path
from typing import Any, Dict, Iterable, Optional

import jsonschema


def utc_timestamp() -> str:
    return datetime.now(timezone.utc).isoformat(timespec="milliseconds").replace(
        "+00:00", "Z"
    )


def action_parameters(action: Dict[str, Any]) -> Dict[str, Any]:
    result: Dict[str, Any] = {}
    for item in action.get("actionParameters", []) or []:
        if isinstance(item, dict) and "key" in item:
            result[str(item["key"])] = item.get("value")
    return result


class SchemaSet:
    """Load and validate the official standalone VDA 5050 schemas."""

    def __init__(self, schema_directory: Path, enabled: bool = True) -> None:
        self.schema_directory = Path(schema_directory)
        self.enabled = enabled
        self._schemas: Dict[str, Dict[str, Any]] = {}

    def load(self, names: Iterable[str]) -> None:
        if not self.enabled:
            return
        for name in names:
            path = self.schema_directory / name
            with path.open("r", encoding="utf-8") as handle:
                self._schemas[name] = json.load(handle)

    def validate(self, schema_name: str, payload: Dict[str, Any]) -> None:
        if not self.enabled:
            return
        schema = self._schemas.get(schema_name)
        if schema is None:
            raise RuntimeError(f"Schema {schema_name!r} was not loaded")
        jsonschema.validate(payload, schema)


class HeaderCounter:
    def __init__(self) -> None:
        self._values: Dict[str, int] = {}

    def next(self, topic: str) -> int:
        self._values[topic] = self._values.get(topic, 0) + 1
        return self._values[topic]


def build_header(
    counter: HeaderCounter,
    topic: str,
    version: str,
    manufacturer: str,
    serial_number: str,
) -> Dict[str, Any]:
    return {
        "headerId": counter.next(topic),
        "timestamp": utc_timestamp(),
        "version": version,
        "manufacturer": manufacturer,
        "serialNumber": serial_number,
    }


def normalize_angle(theta: float) -> float:
    import math

    return math.atan2(math.sin(theta), math.cos(theta))


def nested_value(message: Any, names: Iterable[str], default: Optional[Any] = None) -> Any:
    """Return the first matching attribute from an arbitrary ROS message."""
    for name in names:
        if hasattr(message, name):
            return getattr(message, name)
    return default
