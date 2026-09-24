"""Matched, supervised hoist primitive for laptop-native and Pi-VDA trials.

Uses the existing crane API and existing PLC watchdog. Never feeds a watchdog,
sets an access code, homes an axis, or changes a safety function.
"""
from __future__ import annotations

import hashlib
import json
import math
import time


def validate_motion(cfg):
    required = {"height_a_mm", "height_b_mm", "min_height_mm", "max_height_mm",
                "tolerance_mm", "poll_s", "settle_s", "timeout_s", "stationary_feedback"}
    if set(cfg) != required:
        raise ValueError(f"Hoist settings must contain exactly {sorted(required)}")
    if any(isinstance(v, bool) or not isinstance(v, (int, float)) or not math.isfinite(v) for v in cfg.values()):
        raise ValueError("Hoist settings must be finite numbers")
    for k in ("height_a_mm", "height_b_mm", "min_height_mm", "max_height_mm", "tolerance_mm"):
        if int(cfg[k]) != cfg[k]:
            raise ValueError(k + " must be whole millimetres")
    if not cfg["min_height_mm"] < min(cfg["height_a_mm"], cfg["height_b_mm"]) < max(cfg["height_a_mm"], cfg["height_b_mm"]) < cfg["max_height_mm"]:
        raise ValueError("Distinct A/B heights must be strictly inside the verified travel envelope")
    if any(cfg[k] <= 0 for k in ("tolerance_mm", "poll_s", "settle_s", "timeout_s", "stationary_feedback")):
        raise ValueError("Hoist tolerances and time intervals must be positive")
    if abs(cfg["height_a_mm"]-cfg["height_b_mm"]) <= 4*cfg["tolerance_mm"]:
        raise ValueError("A/B separation must exceed four position tolerances")
    if cfg["timeout_s"] <= cfg["settle_s"] + cfg["poll_s"]:
        raise ValueError("Hoist timeout must exceed settling and polling intervals")


def motion_id(cfg):
    validate_motion(cfg)
    return hashlib.sha256(json.dumps(cfg, sort_keys=True, separators=(",", ":")).encode()).hexdigest()


def height(cfg, endpoint):
    if endpoint not in {"A", "B"}:
        raise ValueError("Hoist endpoint must be A or B")
    return int(cfg["height_a_mm" if endpoint == "A" else "height_b_mm"])


def check_position(crane, cfg, endpoint, *, stationary=True):
    if not crane.is_automatic_mode():
        raise RuntimeError("Crane automatic mode/watchdog is not healthy")
    z = float(crane.get_hoist_position_absolute())
    if not math.isfinite(z) or not cfg["min_height_mm"] <= z <= cfg["max_height_mm"]:
        raise RuntimeError("Hoist outside verified benchmark envelope")
    if abs(z-height(cfg, endpoint)) > cfg["tolerance_mm"]:
        raise RuntimeError(f"Hoist is not at {endpoint}: {z} mm")
    if stationary:
        speeds = [crane.get_hoist_speed_feedback(), crane.get_bridge_speed_feedback(), crane.get_trolley_speed_feedback()]
        if any(not math.isfinite(float(v)) or abs(float(v)) > cfg["stationary_feedback"] for v in speeds):
            raise RuntimeError("Crane axes are not stationary")
    return {"height_error_mm": abs(z-height(cfg, endpoint))}


def execute(crane, cfg, start, target, ack, *, canceled=lambda: False):
    """ACK immediately after first successful existing API motion-write batch.

    Return only after the same API reports target reached and feedback settles.
    Exceptions always attempt STOP; the independent PLC watchdog stays in charge.
    """
    validate_motion(cfg)
    if start == target:
        raise ValueError("A motion trial must change endpoint")
    check_position(crane, cfg, start)
    if abs(crane.get_speed_scale()-1.0) > 1e-9:
        raise RuntimeError("Benchmark requires unchanged speed scale 1.0")
    deadline = time.monotonic() + cfg["timeout_s"]
    acknowledged = False
    stopped = False
    settled = None
    try:
        crane.set_target_hoist(height(cfg, target))  # local assignment, NOT an ACK
        while True:
            if canceled():
                raise RuntimeError("Hoist command canceled or communication lost")
            if time.monotonic() >= deadline:
                raise TimeoutError("Hoist command deadline exceeded")
            if not crane.is_automatic_mode():
                raise RuntimeError("Crane automatic mode lost")
            z = float(crane.get_hoist_position_absolute())
            if not math.isfinite(z) or not cfg["min_height_mm"] <= z <= cfg["max_height_mm"]:
                raise RuntimeError("Hoist left verified envelope")
            if not stopped:
                done = crane.move_hoist_to_target(threshold=int(cfg["tolerance_mm"]), fast=True)
                if not acknowledged:
                    if done:
                        raise RuntimeError("No movement dispatched: target already reached")
                    ack()  # captures local native receipt / publishes VDA relay
                    acknowledged = True
                stopped = bool(done)
            if stopped:
                check_position(crane, cfg, target, stationary=False)
                try:
                    endpoint = check_position(crane, cfg, target)
                    settled = settled if settled is not None else time.monotonic()
                    if time.monotonic()-settled >= cfg["settle_s"]:
                        return endpoint
                except RuntimeError:
                    settled = None
            time.sleep(cfg["poll_s"])
    except BaseException:
        crane.stop_hoist()
        raise
