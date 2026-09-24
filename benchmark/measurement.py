"""Laptop-only timing contract. No ROS imports and no remote timestamp arithmetic."""
from __future__ import annotations

import threading
import time

PROTOCOL = "laptop-timing-v1"
EVENT_TOPIC = "vda5050/benchmark/events"
TIMING_EVENTS = ("COMMAND_ISSUED", "COMMAND_ACK_RECEIVED", "COMMAND_RESULT_RECEIVED")


def feedback_topic(manufacturer, serial):
    return f"vda5050/benchmark/nav2/{manufacturer}/{serial}"


class Measurement:
    """One attempt; responses refer to one command UUID.

    Terminal status is normalized as 4=success, 5=canceled, 6=aborted.
    For ROX these are the ROS action statuses; crane uses the same outcome codes.

    The caller supplies locally captured callback-entry times. A response has
    no remote time field. Duplicate delivery is ignored; conflicting delivery
    is a protocol failure. Outcome checks are outside the two measured times.
    """
    def __init__(self, logger, row):
        self.logger = logger
        self.row = row
        self.lock = threading.RLock()
        self.issued_ns = None
        self.ack_ns = None
        self.result_ns = None
        self.goal_id = ""
        self.accepted = None
        self.status = None
        self.error = ""
        self.finished = False
        self.done = threading.Event()

    def emit(self, event, *, captured_ns=None, success=None, result="", **details):
        return self.logger.emit(
            event, captured_ns=captured_ns, trial_id=self.row["trial_id"],
            pair_id=self.row["pair_id"],
            architecture=self.row["mode"] if self.row["measure"] == "true" else "setup",
            device=self.row["device"], operation="rotate_90deg" if self.row["device"] == "rox" else "hoist_move", command_id=self.row["trial_id"],
            order_id=self.row["trial_id"] if self.row["mode"] == "vda" else "",
            success=success, result=result,
            details={"protocol": PROTOCOL, "mode": self.row["mode"],
                     "start": self.row["start"], "target": self.row["target"], "ack_kind": "nav2_goal_response" if self.row["device"] == "rox" else "opcua_motion_write_batch", **details},
        )

    def issue(self, target):
        with self.lock:
            if self.issued_ns is not None:
                raise RuntimeError("This trial has already issued a command")
            self.issued_ns = time.monotonic_ns()
            self.emit("COMMAND_ISSUED", captured_ns=self.issued_ns, success=True,
                      result="Laptop submits prepared command", target_pose=target)

    def ack(self, captured_ns, accepted, goal_id):
        with self.lock:
            if self.finished:
                return
            if self.issued_ns is None or captured_ns < self.issued_ns:
                self.fail("Acknowledgement arrived before this command")
                return
            if (type(accepted) is not bool or not isinstance(goal_id, str)
                    or len(goal_id) != 32 or any(c not in "0123456789abcdef" for c in goal_id)):
                self.fail("Malformed device acknowledgement")
                return
            if self.ack_ns is not None:
                if (accepted, goal_id) != (self.accepted, self.goal_id):
                    self.fail("Conflicting device acknowledgements")
                return
            self.ack_ns, self.accepted, self.goal_id = captured_ns, accepted, goal_id
            self.emit("COMMAND_ACK_RECEIVED", captured_ns=captured_ns, success=accepted,
                      result=("OPC UA motion writes returned successfully" if self.row["device"] == "crane"
                              else "Nav2 accepted goal") if accepted else "Command rejected",
                      goal_id=goal_id, accepted=accepted)
            if not accepted:
                self.fail("Device rejected the goal")

    def result(self, captured_ns, status, goal_id, error_code=0, error_msg=""):
        with self.lock:
            if self.finished:
                return
            if self.result_ns is not None:
                if (status, goal_id) != (self.status, self.goal_id):
                    self.fail("Conflicting device results")
                return
            if self.ack_ns is None or not self.accepted:
                self.fail("Result arrived without an accepted device acknowledgement")
                return
            if goal_id != self.goal_id or captured_ns < self.ack_ns:
                self.fail("Result UUID or event order does not match acknowledgement")
                return
            if type(status) is not int or status not in {4, 5, 6}:
                self.fail("Response is not a terminal device action result")
                return
            self.result_ns, self.status = captured_ns, status
            self.emit("COMMAND_RESULT_RECEIVED", captured_ns=captured_ns, success=status == 4 and not error_code,
                      result=f"{self.row['device']} terminal status {status}", goal_id=goal_id,
                      terminal_status=status, error_code=error_code, error_msg=error_msg)
            if status != 4 or error_code:
                self.error = f"Device ended with status {status}: {error_msg}"
            self.done.set()

    def fail(self, message):
        with self.lock:
            if not self.finished:
                self.error = self.error or str(message)
                self.done.set()

    def finish(self, endpoint=None):
        with self.lock:
            if self.finished:
                return
            success = not self.error and self.accepted is True and self.status == 4 and endpoint is not None
            self.emit("TRIAL_FINISHED", success=success,
                      result=self.error or ("Endpoint verified" if success else "Incomplete attempt"),
                      endpoint=endpoint or {}, goal_id=self.goal_id)
            self.finished = True
            return success
