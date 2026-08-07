from asyncua.sync import Client
from asyncua import ua
from contextlib import contextmanager
import datetime 
import time
import threading

# TODO New imports. Could find a way to not use these
import numpy as np
from scipy.interpolate import interp1d

class Crane(object): 
    """Definition of Ilmatar Crane interface through OPC UA."""

    def __init__(self, clientaddress) -> None:
        self.x = 1
        # asyncua.sync uses one underlying OPC UA session. Serialize all node
        # operations so watchdog writes, telemetry reads, and motion commands do
        # not concurrently use the same socket from different Python threads.
        self._io_lock = threading.RLock()
        self._io_meta_lock = threading.RLock()
        self._io_owner = None
        self._io_owner_thread = None
        self._io_owner_since_monotonic = None
        self._io_reason_local = threading.local()
        self._io_event_callback = None
        self._last_watchdog_timing = {}
        self._watchdog_priority = threading.Event()
        self.client = Client(clientaddress)
        self._run_io("connect", "connect", self.client.connect)
        self._global_speed_scale = 1.0  # NEW: 0.0 ... 1.0 multiplier applied to all set_*_speed()
        #NS = "ns=" + str(self.client.get_namespace_index("AIIC"))
        NS = "ns=5"

        # Watchdog
        self._node_watchdog = self.client.get_node(
            NS + ";s=DX_Custom_V.Controls.Watchdog")
        

        # Authoritative automatic/remote-mode indicator. The PLC exposes
        # WatchDogFault=False while the external watchdog is healthy and
        # the crane is in automatic mode; True means automatic is lost.
        self._node_watchdog_fault = self.client.get_node(
            NS + ";s=DX_Custom_V.Status.WatchDogFault")
        # Accescode
        self._node_access_code = self.client.get_node(
            NS + ";s=DX_Custom_V.Controls.AccessCode")

        # Crane Direction booleans
        self._node_hoist_up = self.client.get_node(
            NS + ";s=DX_Custom_V.Controls.Hoist.Up")
        self._node_hoist_down = self.client.get_node(
            NS + ";s=DX_Custom_V.Controls.Hoist.Down")
        self._node_trolley_forward = self.client.get_node(
            NS + ";s=DX_Custom_V.Controls.Trolley.Forward")
        self._node_trolley_backward = self.client.get_node(
            NS + ";s=DX_Custom_V.Controls.Trolley.Backward")
        self._node_bridge_forward = self.client.get_node(
            NS + ";s=DX_Custom_V.Controls.Bridge.Forward")
        self._node_bridge_backward = self.client.get_node(
            NS + ";s=DX_Custom_V.Controls.Bridge.Backward")

        # Crane speed
        self._node_hoist_speed = self.client.get_node(
            NS + ";s=DX_Custom_V.Controls.Hoist.Speed")
        self._node_trolley_speed = self.client.get_node(
            NS + ";s=DX_Custom_V.Controls.Trolley.Speed")
        self._node_bridge_speed = self.client.get_node(
            NS + ";s=DX_Custom_V.Controls.Bridge.Speed")

        # Position
        self._node_hoist_position_mm = self.client.get_node(
            NS + ";s=DX_Custom_V.Status.Hoist.Position.Position_mm")
        self._node_trolley_position_mm = self.client.get_node(
            NS + ";s=DX_Custom_V.Status.Trolley.Position.Position_mm")
        self._node_bridge_position_mm = self.client.get_node(
            NS + ";s=DX_Custom_V.Status.Bridge.Position.Position_mm")
        self._node_hoist_position_m = self.client.get_node(
            NS + ";s=DX_Custom_V.Status.Hoist.Position.Position_m")
        self._node_trolley_position_m = self.client.get_node(
            NS + ";s=DX_Custom_V.Status.Trolley.Position.Position_m")
        self._node_bridge_position_m = self.client.get_node(
            NS + ";s=DX_Custom_V.Status.Bridge.Position.Position_m")
        
        # Loads
        self._node_hoist_current_load = self.client.get_node(
            NS + ";s=DX_Custom_V.Status.Hoist.Load.Load_t")
        self._node_hoist_current_tared_load = self.client.get_node(
            NS + ";s=DX_Custom_V.Status.Hoist.Load.TaredLoad_t")

        # Datetime
        self._node_datime_year = self.client.get_node(
            NS + ";s=DX_Custom_V.Datetime.Year")
        self._node_datime_month = self.client.get_node(
            NS + ";s=DX_Custom_V.Datetime.Month")
        self._node_datime_day = self.client.get_node(
            NS + ";s=DX_Custom_V.Datetime.Day")
        self._node_datime_hour = self.client.get_node(
            NS + ";s=DX_Custom_V.Datetime.Hour")
        self._node_datime_minute = self.client.get_node(
            NS + ";s=DX_Custom_V.Datetime.Minute")
        self._node_datime_second = self.client.get_node(
            NS + ";s=DX_Custom_V.Datetime.Second")
        self._node_datime_millisecond = self.client.get_node(
            NS + ";s=DX_Custom_V.Datetime.Millisecond")

        # Control signal status

        # Not currently used
        self._node_trolley_direction_forward_request = self.client.get_node(
            NS + ";s=DX_Custom_V.Status.Trolley.ControlSignals.Direction1_Request")
        self._node_trolley_direction_backwards_request = self.client.get_node(
            NS + ";s=DX_Custom_V.Status.Trolley.ControlSignals.Direction2_Request")
        self._node_trolley_speed_request = self.client.get_node(
            NS + ";s=DX_Custom_V.Status.Trolley.ControlSignals.SpeedRequest")
        self._node_trolley_speed_feedback = self.client.get_node(
            NS + ";s=DX_Custom_V.Status.Trolley.ControlSignals.SpeedFeedback")
        self._node_trolley_speed_feedback_mmin = self.client.get_node(
            NS + ";s=DX_Custom_V.Status.Trolley.ControlSignals.SpeedFeedback_mmin")


        # Not currently used
        # TODO functions now working because currently not in use
        self._node_bridge_direction_forward_request = self.client.get_node(
            NS + ";s=DX_Custom_V.Status.Bridge.ControlSignals.Direction1_Request")
        self._node_bridge_direction_backward_request = self.client.get_node(
            NS + ";s=DX_Custom_V.Status.Bridge.ControlSignals.Direction2_Request")
        self._node_bridge_speed_request = self.client.get_node(
            NS + ";s=DX_Custom_V.Status.Bridge.ControlSignals.SpeedRequest")
        self._node_brige_speed_feedback = self.client.get_node(
            NS + ";s=DX_Custom_V.Status.Bridge.ControlSignals.SpeedFeedback")
        self._node_brige_speed_feedback_mmin = self.client.get_node(
            NS + ";s=DX_Custom_V.Status.Bridge.ControlSignals.SpeedFeedback_mmin")


        # Not currently used
        # TODO functions now working because currently not in use
        self._node_hoist_direction_up_request = self.client.get_node(
            NS + ";s=DX_Custom_V.Status.Hoist.ControlSignals.Direction1_Request")
        self._node_hoist_direction_down_request = self.client.get_node(
            NS + ";s=DX_Custom_V.Status.Hoist.ControlSignals.Direction2_Request")
        self._node_hoist_speed_request = self.client.get_node(
            NS + ";s=DX_Custom_V.Status.Hoist.ControlSignals.SpeedRequest")
        self._node_hoist_speed_feedback = self.client.get_node(
            NS + ";s=DX_Custom_V.Status.Hoist.ControlSignals.SpeedFeedback")
        self._node_hoist_speed_feedback_mmin = self.client.get_node(
            NS + ";s=DX_Custom_V.Status.Hoist.ControlSignals.SpeedFeedback_mmin")


        self.bridge_last_zeroed = self.get_motorcontroller_bridge_value()
        self.trolley_last_zeroed = self.get_motorcontroller_trolley_value()
        self.hoist_last_zeroed = self.get_motorcontroller_hoist_value()

        self._watchdog_value = self.get_watchdog()

        # Will be initialized in set_moving_height
        self.hoist_moving_height = None

        # Will be initialized in set_target_current_position later in __init__
        self.trolley_target = None
        self.bridge_target = None
        self.hoist_target = None

        self.set_target_current_position()

    def set_io_event_callback(self, callback):
        """Register a non-OPC-UA observer for completed I/O operations."""
        with self._io_meta_lock:
            self._io_event_callback = callback

    @contextmanager
    def io_reason(self, reason):
        """Label node transactions in the current thread without holding a lock."""
        previous = getattr(self._io_reason_local, "value", None)
        self._io_reason_local.value = str(reason)
        try:
            yield
        finally:
            if previous is None:
                try:
                    del self._io_reason_local.value
                except AttributeError:
                    pass
            else:
                self._io_reason_local.value = previous

    def io_snapshot(self):
        """Return the current shared-session owner for watchdog diagnostics."""
        now = time.monotonic()
        with self._io_meta_lock:
            since = self._io_owner_since_monotonic
            return {
                "owner": self._io_owner,
                "thread": self._io_owner_thread,
                "owner_since_monotonic": since,
                "owner_age_ms": (
                    max(0.0, (now - since) * 1000.0) if since is not None else 0.0
                ),
                "watchdog_pending": self._watchdog_priority.is_set(),
            }

    def _resolved_reason(self, explicit, default):
        return str(explicit or getattr(self._io_reason_local, "value", None) or default)

    @staticmethod
    def _is_any_node(node, candidates):
        return any(node is candidate for candidate in candidates)

    def _read_reason_for_node(self, node, explicit=None):
        contextual = explicit or getattr(self._io_reason_local, "value", None)
        if contextual:
            return str(contextual)
        if threading.current_thread().name == "executor":
            if self._is_any_node(
                node,
                (self._node_bridge_position_mm, self._node_bridge_position_m,
                 self._node_trolley_position_mm, self._node_trolley_position_m),
            ):
                return "move_xy"
            if self._is_any_node(
                node,
                (self._node_hoist_position_mm, self._node_hoist_position_m),
            ):
                return "move_hoist"
        return "state_telemetry"

    def _write_reason_for_node(self, node, explicit=None):
        contextual = explicit or getattr(self._io_reason_local, "value", None)
        if contextual:
            return str(contextual)
        if self._is_any_node(
            node,
            (self._node_bridge_forward, self._node_bridge_backward,
             self._node_trolley_forward, self._node_trolley_backward,
             self._node_bridge_speed, self._node_trolley_speed),
        ):
            return "move_xy"
        if self._is_any_node(
            node,
            (self._node_hoist_up, self._node_hoist_down, self._node_hoist_speed),
        ):
            return "move_hoist"
        return "motion_control"

    def _run_io(
        self,
        reason,
        operation,
        transaction,
        *,
        watchdog=False,
        scheduled_deadline_monotonic=None,
        attempt_started_monotonic=None,
    ):
        """Run exactly one OPC UA transaction and return its split timing."""
        if watchdog:
            self._watchdog_priority.set()
        else:
            # Low-priority work yields before requesting the session while a
            # watchdog tick is pending. No OPC UA lock is held while waiting.
            while self._watchdog_priority.is_set():
                time.sleep(0.001)

        attempt_started = (
            float(attempt_started_monotonic)
            if attempt_started_monotonic is not None
            else time.monotonic()
        )
        lock_requested = time.monotonic()
        owner_at_request = self.io_snapshot()
        if watchdog:
            self._io_lock.acquire()
        else:
            # Do not remain queued ahead of a watchdog tick. Poll briefly, and
            # if the watchdog became pending while this caller acquired the
            # session, release it before starting any OPC UA transaction.
            while True:
                if not self._io_lock.acquire(timeout=0.002):
                    continue
                if not self._watchdog_priority.is_set():
                    break
                self._io_lock.release()
        lock_acquired = time.monotonic()
        thread_name = threading.current_thread().name
        with self._io_meta_lock:
            previous_owner = (
                self._io_owner,
                self._io_owner_thread,
                self._io_owner_since_monotonic,
            )
            self._io_owner = str(reason)
            self._io_owner_thread = thread_name
            self._io_owner_since_monotonic = lock_acquired

        operation_started = time.monotonic()
        result = None
        error = None
        try:
            result = transaction()
        except BaseException as exc:
            error = exc
        operation_finished = time.monotonic()
        with self._io_meta_lock:
            self._io_owner, self._io_owner_thread, self._io_owner_since_monotonic = previous_owner
        self._io_lock.release()
        if watchdog:
            self._watchdog_priority.clear()

        scheduled = (
            float(scheduled_deadline_monotonic)
            if scheduled_deadline_monotonic is not None
            else attempt_started
        )
        timing = {
            "reason": str(reason),
            "operation": str(operation),
            "scheduled_deadline_monotonic": scheduled,
            "attempt_started_monotonic": attempt_started,
            "lock_requested_monotonic": lock_requested,
            "lock_acquired_monotonic": lock_acquired,
            "write_started_monotonic": operation_started,
            "write_finished_monotonic": operation_finished,
            "watchdog_schedule_lateness_ms": max(0.0, (attempt_started - scheduled) * 1000.0),
            "watchdog_lock_wait_ms": max(0.0, (lock_acquired - lock_requested) * 1000.0),
            "watchdog_write_duration_ms": max(0.0, (operation_finished - operation_started) * 1000.0),
            "watchdog_total_cycle_ms": max(0.0, (operation_finished - attempt_started) * 1000.0),
            "lock_owner_at_request": owner_at_request.get("owner"),
            "lock_owner_thread_at_request": owner_at_request.get("thread"),
            "success": error is None,
            "error": "" if error is None else f"{type(error).__name__}: {error}",
        }
        if watchdog:
            with self._io_meta_lock:
                self._last_watchdog_timing = dict(timing)
        with self._io_meta_lock:
            callback = self._io_event_callback
        if callback is not None:
            try:
                callback(dict(timing))
            except Exception:
                pass
        if error is not None:
            raise error
        return result, timing

    def _read_node(self, node, reason=None):
        """Read one OPC UA node through the shared-session coordinator."""
        value, _ = self._run_io(
            self._read_reason_for_node(node, reason),
            "read",
            node.read_value,
        )
        return value

    def _write_node(
        self,
        node,
        value,
        reason=None,
        *,
        scheduled_deadline_monotonic=None,
        attempt_started_monotonic=None,
    ):
        """Write one OPC UA node while preserving watchdog priority."""
        is_watchdog = node is self._node_watchdog
        _, timing = self._run_io(
            "watchdog" if is_watchdog else self._write_reason_for_node(node, reason),
            "write",
            lambda: node.write_value(value),
            watchdog=is_watchdog,
            scheduled_deadline_monotonic=scheduled_deadline_monotonic,
            attempt_started_monotonic=attempt_started_monotonic,
        )
        return timing


    """Functions related to connecting to opcua server"""

    # Works
    def connect(self):
        """Connect to the OPC UA Server."""
        self._run_io("connect", "connect", self.client.connect)

    # Not working
    def disconnect(self): #close
        """Disconnect from OPC UA Server."""
        self._run_io("disconnect", "disconnect", self.client.disconnect)


    """Functions related to watchdog"""
    # Works
    def get_watchdog(self):
        """Get Watchdog value."""
        return self._read_node(self._node_watchdog, reason="watchdog_read")

    def get_watchdog_fault(self):
        """Return PLC watchdog-fault status.

        For this crane interface, False means the external watchdog is healthy
        and automatic/remote mode is active. True means automatic mode is not
        available and motion commands must not be accepted.
        """
        return bool(self._read_node(self._node_watchdog_fault, reason="automatic_mode_guard"))

    def is_automatic_mode(self):
        """Return True only when DX_Custom_V.Status.WatchDogFault is false."""
        return not self.get_watchdog_fault()


    # Setting works but goes back to original value next iteration
    def set_watchdog(
        self,
        watchdog_value,
        *,
        scheduled_deadline_monotonic=None,
        attempt_started_monotonic=None,
    ):
        """Set Watchdog to number x."""
        return self._write_node(
            self._node_watchdog,
            ua.DataValue(ua.Variant(watchdog_value, ua.VariantType.Int16)),
            scheduled_deadline_monotonic=scheduled_deadline_monotonic,
            attempt_started_monotonic=attempt_started_monotonic,
        )

    # Works
    def increment_watchdog(self):
        """Increment Watchdog by 1."""
        #print(self._watchdog_value)
        self._watchdog_value = (self._watchdog_value % 30000) + 1
        return self.set_watchdog(self._watchdog_value)

    def increment_watchdog_timed(self, scheduled_deadline_monotonic, attempt_started_monotonic):
        """Increment the watchdog and return split schedule/lock/write timings."""
        self._watchdog_value = (self._watchdog_value % 30000) + 1
        return self.set_watchdog(
            self._watchdog_value,
            scheduled_deadline_monotonic=scheduled_deadline_monotonic,
            attempt_started_monotonic=attempt_started_monotonic,
        )

    def last_watchdog_timing(self):
        with self._io_meta_lock:
            return dict(self._last_watchdog_timing)


    
    
        """Functions related to accesscode"""
    # Works
    def get_accesscode(self):
        """Get AccessCode value."""
        return self._read_node(self._node_access_code)

    # Works, temporarely changes code. Doesnt save.
    def set_accesscode(self, accesscode):
        """Set AccessCode to number x."""
        self._write_node(
            self._node_access_code,
            ua.DataValue(ua.Variant(accesscode, ua.VariantType.Int32)),
            reason="configuration",
        )

    
    """Functions to get position for crane"""
    # Works
    # TODO Laser values are floating, e.g. 9383.000373840332
    def get_trolley_position_absolute(self):
        """Get absolute position for Trolley in mm (laser)."""
        return self._read_node(self._node_trolley_position_m) * 1000

    # Works
    # TODO which one is more accurate?
    def get_motorcontroller_trolley_value(self):
        """Get value from motorcontroller for Trolley."""
        return self._read_node(self._node_trolley_position_mm)

    # Works
    def get_bridge_position_absolute(self):
        """Get absolute position for Bridge in mm (laser)."""
        return self._read_node(self._node_bridge_position_m) * 1000

    # Works
    def get_motorcontroller_bridge_value(self):
        """Get value from motorcontroller for Bridge."""
        return self._read_node(self._node_bridge_position_mm)

    # Works
    def get_hoist_position_absolute(self):
        """ Get absolute position for Hoist in mm """
        return self._read_node(self._node_hoist_position_m) * 1000

    # Works
    def get_motorcontroller_hoist_value(self):
        """Get value from motorcontroller for Hoist."""
        return self._read_node(self._node_hoist_position_mm)
    
    # Works
    # Same values as get_motorcontroller_all
    def get_coordinates_absolute(self):
        """Get absolute position for Bridge,Trolley and Hoist in mm (laser)."""
        return(self._read_node(self._node_bridge_position_mm),
               self._read_node(self._node_trolley_position_mm),
               self._read_node(self._node_hoist_position_mm))
    # Works
    # Same values as get_coordinates_absolute
    def get_motorcontroller_all(self):
        """Get all values from motorcontroller, Bridge, Trolley, Hoist."""
        return(self.get_motorcontroller_bridge_value(),
               self.get_motorcontroller_trolley_value(),
               self.get_motorcontroller_hoist_value())



    # TODO Motocontroller changed to motorcontroller
    # TODO Missing hoist, is it necessary?
    """Functions to get positions with timestamp for bridge and trolley"""
    
    # Works
    def get_motorcontroller_bridge_value_with_timestamp(self):
        """Get value from motorcontroller for Bridge with timestamp."""
        data = self._node_bridge_position_mm.read_data_value()
        return (data.Value.Value, data.SourceTimestamp.timestamp())

    # Works
    def get_motorcontroller_trolley_value_with_timestamp(self):
        """Get value from motorcontroller for trolley with timestamp."""
        data = self._node_trolley_position_mm.read_data_value()
        return (data.Value.Value, data.SourceTimestamp.timestamp())


    # TODO changed order to match previous functions
    """Functions to get speed with timestamp for crane"""

    # Works
    def get_speed_trolley_value_with_timestamp(self):
        """Get value from motorcontroller for Bridge with timestamp."""
        data = self._node_trolley_speed_feedback.read_data_value()
        return (data.Value.Value, data.SourceTimestamp.timestamp())

    # Works
    def get_speed_bridge_value_with_timestamp(self):
        """Get value from motorcontroller for Bridge with timestamp."""
        data = self._node_brige_speed_feedback.read_data_value()
        return (data.Value.Value, data.SourceTimestamp.timestamp())

    # Works
    def get_speed_hoist_value_with_timestamp(self):
        """Get value from motorcontroller for Bridge with timestamp."""
        data = self._node_hoist_speed_feedback.read_data_value()
        return (data.Value.Value, data.SourceTimestamp.timestamp())



    # TODO Changed order to trol, brid, hoist
    """Crane target functions"""
    """Functions for setting targets for crane"""
    # Works
    def set_target_trolley(self, target):
        """Set target value of trolley min 285, max 8376."""
        self.trolley_target = target

    # Works
    def set_target_bridge(self, target):
        """Set target value of bridge min the other crane, max 25146."""
        self.bridge_target = target

    # Works
    def set_target_hoist(self, target):
        """Set target value of Hoist."""
        self.hoist_target = target

    # Works
    def set_moving_height(self, target):
        """Set target for moving height of Hoist."""
        self.hoist_moving_height = target

    # Works, gives outputs values
    def set_target_current_position(self):
        """Set current position to target"""
        x, y, z = self.get_coordinates_absolute()
        self.set_target_bridge(x)
        self.set_target_trolley(y)
        self.set_target_hoist(z)
        return x, y, z


    """Functions to get weight from the crane"""

    # TODO Works but what unit?
    def get_load(self):
        """Get current load from crane."""
        return self._read_node(self._node_hoist_current_load)

    # Works, same value as above
    def get_load_tared(self):
        """Get current tared load from crane."""
        return self._read_node(self._node_hoist_current_tared_load)
    
    # Doesnt work, badnode id unknown
    # TODO this doesnt make sense to be here, should be at the start imo
    def get_datetime(self):
        """Get Python datetime object from the crane."""
        year = self._read_node(self._node_datime_year)
        month = self._read_node(self._node_datime_month)
        day = self._read_node(self._node_datime_day)
        hour = self._read_node(self._node_datime_hour)
        minute = self._read_node(self._node_datime_minute)
        second = self._read_node(self._node_datime_second)
        millisecond = self._read_node(self._node_datime_millisecond)
        return datetime.datetime(year,month,day,hour,minute,second,millisecond*1000)


    # TODO changed layout to match trolley, bridge, hoist
    """Functions for getting distance to target"""

    # Works
    def trolley_to_target(self):
        """Returns mm to pre-set target by set_target_trolley()."""
        return self.get_trolley_position_absolute() - self.trolley_target

    # Works
    def bridge_to_target(self):
        """Returns mm to pre-set target by set_target_bridge()."""
        # Get value from opc-ua, minus target value
        # TODO How crane works when target negative? Can it be?
        return self.get_bridge_position_absolute() - self.bridge_target

    # Works
    def hoist_to_target(self):
        """Returns mm to pre-set target by set_target_hoist()."""
        return self.get_hoist_position_absolute() - self.hoist_target

    # Works
    def hoist_to_moving_height(self):
        """Returns mm to pre-set target by set_moving_height()."""
        return self.get_hoist_position_absolute() - self.hoist_moving_height


    # TEST!
    """Function to ramp cranes speed based on distance"""

    def ramp_speed(self, distance):
        """"Ramps the speed based on distance"""
        if -3 < distance < 3:
            speed = 0.3
        elif -5 < distance < 5:
            speed = 0.5
        elif -10 < distance < 10:
            speed = 1
        elif -50 < distance < 50:
            speed = 3
        elif -100 < distance < 100:
            speed = 8
        elif -300 < distance < 300:
            speed = 15
        else:
            speed = 20
        return speed


    def ramp_speed2(self, distance):
        """Ramps the speed based on distance, alternative option"""
        if -10 < distance < 10:
            speed = 2
        elif -300 < distance < 300:
            speed = abs(60.0*distance/300)
        else:
            speed = 30
        return speed


    def ramp_speed_horizontal(self, distance, fast=False):
        """Ramps the speed based on distance, optimized for horizontal movement.
            Use fast to limit minimum speed to certain value. Less accurate, but faster"""
        # If dist to target is under 15 mm, slow down a lot.
        # TODO Could this be faster?
        if -15 < distance < 15:
            speed = 0.6
        # If dist within 2 m, linear ramp speed down based on dist
        # TODO Better way? Slow non-linearly more when closer?
        # In that case, upper if is not needed.
        elif -2000 < distance < 2000:
            speed = abs(distance/20.0)
        else:
            speed = 100

        return 15 if fast and speed < 15 else speed

    # Works
    def ramp_speed_lower(self, distance):
        """Ramps the speed based on distance, slow ramp for lowering"""
        if -8 < distance < 8:
            speed = 2
        elif -400 < distance < 400:
            speed = abs(distance/4.0)
        else:
            speed = 100
        return speed

    # Works, but stays in overshooting loop
    def ramp_speed_lift(self, distance):
        """Ramps the speed based on distance, fast ramp for lifting"""
        if -8 < distance < 8:
            speed = 4
        elif -200 < distance < 200:
            speed = abs(distance/2.0)
        else:
            speed = 100
        return speed
    
        
    def speed_profile_trolley(self, distance):

        # Distance parameters
        d_total = abs(int(distance))  # Total distance to target in m
        dd = 1  # Distance step in mm
        max_speed = min((d_total/4.2), 300) # mm/s
        print("Max speed: ", max_speed)

        # Sigmoid function parameters for acceleration and deceleration
        base_k = 1.4  # Steepness of the sigmoid / bigger number = faster
        scale_k = max(1 / (d_total * 0.04), 0.0005)  # Scaling factor for k
        k = base_k * scale_k  # Adjusted steepness of the sigmoid
        print("K factor: ", k)

        # Data points, tested to be working
        distances = np.array([100, 200, 300, 500, 1000, 2000, 3000, 4000])  # in mm
        d_acc_values = np.array([0.56, 0.558, 0.47, 0.32, 0.22, 0.185, 0.175, 0.17])  # d_acc values

        # Function to perform linear interpolation
        def get_d_acc(distance, distances, d_acc_values):
            return np.interp(distance, distances, d_acc_values)

        d_acc = int(d_total * get_d_acc(d_total, distances, d_acc_values))
        print("Acc length: ", d_acc)

        # Sigmoid function in distance domain
        def sigmoid(d, k, d_0):
            return 1 / (1 + np.exp(-k * (d - d_0)))

        # Derivative of the sigmoid function (speed profile)
        def sigmoid_derivative(d, k, d_0):
            s = sigmoid(d, k, d_0)
            return k * s * (1 - s)

        # Generate distance array
        d = np.arange(0, d_total, dd)

        # Speed profile array
        speed_profile = np.zeros_like(d)

        # Acceleration phase
        accel_profile = sigmoid_derivative(d[:int(d_acc/dd)], k * 0.25, d_acc)
        speed_profile[:int(d_acc/dd)] = accel_profile / np.max(accel_profile) * max_speed

        # Constant speed phase
        speed_profile[int(d_acc/dd):int((d_total - d_acc)/dd)] = max_speed

        # Deceleration phase
        decel_profile = sigmoid_derivative(d[:int(d_acc/dd)], k, 0)
        speed_profile[int(((d_total - d_acc)/dd)):] = decel_profile / np.max(decel_profile) * max_speed

        remaining_distances = d_total - d  # Calculate remaining distances

        return speed_profile, remaining_distances
 

    def speed_profile_bridge(self, distance):
        """Create speed profile for moving bridge. Must be done before using s-curve."""

        # Distance parameters
        d_total = abs(int(distance))  # Total distance to target in m
        dd = 1  # Distance step in mm
        max_speed = min((d_total/4.2), 300) # mm/s
        print("Distance: ", d_total)
        print("Max speed: ", max_speed)

        # Sigmoid function parameters for acceleration and deceleration
        base_k = 1.4  # Steepness of the sigmoid / bigger number = faster
        scale_k = max(1 / (d_total * 0.04), 0.0005)  # Scaling factor for k
        k = base_k * scale_k  # Adjusted steepness of the sigmoid
        print("K factor: ", k)

        # Data points
        distances = np.array([100, 200, 300, 500, 1000, 2000, 3000, 4000])  # in mm
        d_acc_values = np.array([0.6, 0.6, 0.6, 0.44, 0.29, 0.2, 0.18, 0.17])  # values

        # Linear interpolation
        def get_d_acc(distance, distances, d_acc_values):
            return np.interp(distance, distances, d_acc_values)

        d_acc = int(d_total * get_d_acc(d_total, distances, d_acc_values))
        print("Acc length: ", d_acc)

        # Sigmoid function in distance domain
        def sigmoid(d, k, d_0):
            return 1 / (1 + np.exp(-k * (d - d_0)))

        # Derivative of the sigmoid function (speed profile)
        def sigmoid_derivative(d, k, d_0):
            s = sigmoid(d, k, d_0)
            return k * s * (1 - s)

        # Generate distance array
        d = np.arange(0, d_total, dd)

        # Speed profile array
        speed_profile = np.zeros_like(d)

        # Acceleration phase
        accel_profile = sigmoid_derivative(d[:int(d_acc/dd)], k * 0.25, d_acc)
        speed_profile[:int(d_acc/dd)] = accel_profile / np.max(accel_profile) * max_speed

        # Constant speed phase
        speed_profile[int(d_acc/dd):int((d_total - d_acc)/dd)] = max_speed

        # Deceleration phase
        decel_profile = sigmoid_derivative(d[:int(d_acc/dd)], k, 0)
        speed_profile[int(((d_total - d_acc)/dd)):] = decel_profile / np.max(decel_profile) * max_speed

        remaining_distances = d_total - d  # Calculate remaining distances

        return speed_profile, remaining_distances
       

    def s_curve(self, speed_profile, remaining_distances, distance):
        """Create interpolation function for speed based on remaining distance"""
        
        speed_interpolation = interp1d(remaining_distances, speed_profile, fill_value="extrapolate")

        def get_speed(remaining_distance):
            return speed_interpolation(remaining_distance)

        return float(get_speed(abs(distance)))


    # TODO changed hoist and hoist_precise places
    """Premade functions for moving crane to target"""

    # TODO No error if crane isnt able to move
    # Works
    def move_trolley_to_target(self, threshold=1, fast=False):
        """Moves trolley to target"""

        # Retrieve updated distance to target
        dist_to_target = self.trolley_to_target()
        speed = self.ramp_speed_horizontal(dist_to_target, fast)

        if -threshold <= dist_to_target <= threshold:
            self.stop_trolley()
            print("Trolley on target")
            flag = 1
        elif dist_to_target > 0:
            self.move_trolley_backward_speed(speed)
            flag = 0
        else:
            self.move_trolley_forward_speed(speed)
            flag = 0

        return flag
    def move_trolley_to_target_s(self, speed_profile, remaining_distances, threshold=1, fast=False):
        """Moves trolley to target using s-curve speed model."""

        # Retrieve updated distance to target
        dist_to_target = int(self.trolley_to_target())
        speed = max(abs(self.s_curve(speed_profile, remaining_distances, dist_to_target)), 1)
        print("Dist: ", dist_to_target, "Speed: ", speed)

        #speed = self.ramp_speed_horizontal(dist_to_target, fast)
        if -threshold <= dist_to_target <= threshold:
            self.stop_trolley()
            print("Trolley on target")
            flag = 1
        elif dist_to_target > 0:
            self.move_trolley_backward_speed(speed)
            flag = 0
        else:
            self.move_trolley_forward_speed(speed)
            flag = 0

        return flag

    # Works
    def  move_bridge_to_target(self, threshold=1, fast=False):
        """Moves bridge to target"""

        # Retrieve updated distance to target
        # TODO Could be run as thread? calculate every time input value changes
        dist_to_target = self.bridge_to_target()

        # Choose speed
        speed = self.ramp_speed_horizontal(dist_to_target, fast)

        if -threshold <= dist_to_target <= threshold:
            self.stop_bridge()
            print("Bridge on target")
            flag = 1
        elif dist_to_target > 0:
            self.move_bridge_backward_speed(speed)
            flag = 0
        else:
            self.move_bridge_forward_speed(speed)
            flag = 0

        return flag
    
    def  move_bridge_to_target_s(self, speed_profile, remaining_distances, threshold=2):
        """Moves trolley to target using s-curve speed model."""

        # Retrieve updated distance to target
        # TODO Could be run as thread? calculate every time input value changes
        dist_to_target = int(self.bridge_to_target())

        # Choose speed
        speed = max(abs(self.s_curve(speed_profile, remaining_distances, dist_to_target)), 1)
        print("Dist: ", dist_to_target, "Speed: ", speed)

        if -threshold <= dist_to_target <= threshold:
            self.stop_bridge()
            print("Bridge on target")
            flag = 1
        elif dist_to_target > 0:
            self.move_bridge_backward_speed(speed)
            flag = 0
        else:
            self.move_bridge_forward_speed(speed)
            flag = 0

        return flag
        
    
    # TODO Changed from "hoist in target" to "on target"
    # Works
        """Moves hoist to target"""
    def move_hoist_to_target(self, threshold=2, fast=False):

        # Retrieve updated distance to target
        dist_to_target = self.hoist_to_target()

        hoist_pos = self.get_hoist_position_absolute()

        if fast:
            speed = self.ramp_speed_lift(dist_to_target)
        else:
            speed = self.ramp_speed_lower(dist_to_target)

        if -threshold <= dist_to_target <= threshold: 
            self.stop_hoist()
            #print("Hoist on target")
            flag = 1
        elif dist_to_target > 0: 
            self.move_hoist_down_speed(speed)
            flag = 0
        else:
            self.move_hoist_up_speed(speed)
            flag = 0

        return flag

    # TODO works different than others, confusing
    # Works, really slow :(
    def move_hoist_to_target_precise(self, target):
        """
		Moves hoist to target by precision of 0.1 mm
		args:
			target: Hoist target position
		return:
			returns True if hoist is in target location
			False otherwise
		"""

        # Retrieve updated distance to target

        hoist_pos = self.get_motorcontroller_hoist_value()

        dist_to_target = target - hoist_pos

        speed = self.ramp_speed_lower(dist_to_target / 10)


        if dist_to_target < 0:
            self.move_hoist_down_speed(speed)
            return False
        if dist_to_target > 0:
            self.move_hoist_up_speed(speed)
            return False
        self.stop_hoist()
        return True

    # Works
    # TODO normal moving but using fast=True
    def move_hoist_to_target_lift(self):
        """Moves hoist to target fast"""

        return self.move_hoist_to_target(fast=True)

    # Not working
    def move_hoist_to_moving_height(self):
        """Moves hoist to moving height fast"""

        # Retrieve updated distance to target
        dist_to_target = self.hoist_to_moving_height()

        hoist_pos = self.get_hoist_position_absolute()

        speed = self.ramp_speed_lift(dist_to_target)
        if hoist_pos > (self.hoist_moving_height):
            self.move_hoist_down_speed(speed)
            flag = 0
        elif hoist_pos < (self.hoist_moving_height):
            self.move_hoist_up_speed(speed)
            flag = 0
        else:
            self.stop_hoist()
            print("Hoist in moving height")
            flag = 1

        return flag



    """Premade functions for moving crane to target with P control"""
    # Function works, but bad
    # TODO Gets stuck overshooting, cannot find target. works only (max=20)
    # TODO Slow speed has smoother approach but overshoots and is slow
    def speedPcontrol(self, error):
        """Simple P control for speed"""
        max = 20 # saturation level = max output
        threshold = 150 # apply ramp below this error
        offset = 0 # minimum output

        Pgain = max/threshold

        speed = Pgain*abs(error)+offset

        return speed if speed <= max else max

    # Works
    # TODO Uses speedPcontrol which is bad
    def move_trolley_to_target_p(self, precision=5):
        """Moves trolley to target"""

        # Retrieve updated distance to target
        dist_to_target = self.trolley_to_target()

        speed = self.speedPcontrol(dist_to_target)

        flag = 0
        if abs(dist_to_target) <= precision/2:
            self.stop_trolley()
            # print("Trolley on target")
            flag = 1
        elif dist_to_target > 0:
            self.move_trolley_backward_speed(speed)
        else:
            self.move_trolley_forward_speed(speed)

        return flag

    # Works
    def move_bridge_to_target_p(self, precision=5):
        """Moves bridge to target"""

        # Retrieve updated distance to target
        dist_to_target = self.bridge_to_target()

        # speed = self.ramp_speed_horizontal(dist_to_target, fast)
        speed = self.speedPcontrol(dist_to_target)

        flag = 0
        if abs(dist_to_target) <= precision/2:
            self.stop_bridge()
            # print("Bridge on target")
            flag = 1
        elif dist_to_target > 0:
            self.move_bridge_backward_speed(speed)
        else:
            self.move_bridge_forward_speed(speed)

        return flag

    # Works
    # TODO Difference to move_hoist_to_target_precise is use of speedPcontrol
    def move_hoist_to_target_p(self, precision=1):
        """Moves hoist to target"""

        # Retrieve updated distance to target
        dist_to_target = self.hoist_to_target()

        speed = self.speedPcontrol(dist_to_target)

        flag = 0
        if abs(dist_to_target) <= precision/2:
            self.stop_hoist()
            # print("Hoist in target")
            flag = 1
        elif dist_to_target > 0:
            self.move_hoist_down_speed(speed)
        else:
            self.move_hoist_up_speed(speed)

        return flag


    # Doesnt work, same as without _p
    # Has stored target
    def move_hoist_to_moving_height_p(self):
        """Moves hoist to moving height fast"""

        stored_target = self.hoist_moving_height

        # Set current target to moving height
        self.hoist_target = self.hoist_moving_height

        flag = self.move_hoist_to_target()

        # Restore original target value
        self.hoist_target = stored_target

        return flag



    # TODO changed order to trol, bridge, hoist
    # TODO changed "location to position in comment (more accurate term)"
    """Crane zeroing functions"""
    """Functions for zeroing cranes position"""
    # Works
    def zero_trolley_position(self):
        """ Zero the motorcontroller value of Trolley"""
        self.trolley_last_zeroed = self.get_motorcontroller_trolley_value()

    # Works
    def zero_bridge_position(self):
        """ Zero the motorcontroller value of Bridge"""
        self.bridge_last_zeroed = self.get_motorcontroller_bridge_value()

    # Works
    def zero_hoist_position(self):
        """ Zero the motorcontroller value of Hoist"""
        self.hoist_last_zeroed = self.get_motorcontroller_hoist_value()



    # TODO changed order to trol, bridge, hoist. Location to position in comment
    # TODO does it support multiple zeroed points? Should it?
    """Functions for getting crane's zeroed position"""

    # Works
    def get_zero_trolley_position(self):
        """Get last zeroed value of Trolley"""
        return self.trolley_last_zeroed

    # Works
    def get_zero_bridge_position(self):
        """Get last zeroed value of Bridge"""
        return self.bridge_last_zeroed

    # Works
    def get_zero_hoist_position(self):
        """Get last zeroed value of Hoist"""
        return self.hoist_last_zeroed



    # TODO changed order to trol, bridge, hoist. Location to position in comment
    """Functions for getting distance to cranes zeroed position"""
    
    # Works
    def get_difference_trolley_to_zero(self):
        """Difference from Trolley to last zeroed value."""
        return self.get_motorcontroller_trolley_value() - self.get_zero_trolley_position()
    
    # Works
    def get_difference_bridge_to_zero(self):
        """Difference from Bridge to last zeroed value."""
        return self.get_motorcontroller_bridge_value() - self.get_zero_bridge_position()

    # Works
    def get_difference_hoist_to_zero(self):
        """Difference from Hoist to last zeroed value."""
        return self.get_motorcontroller_hoist_value() - self.get_zero_hoist_position()


    # TODO Should it be B,T,H or T,B,H?
    # Works
    def get_difference_all_to_zero(self):
        """Difference from all axis to the last zeroed values, B,T,H."""
        return(self.get_difference_bridge_to_zero(),
               self.get_difference_trolley_to_zero(),
               self.get_difference_hoist_to_zero())


    # TODO Works, but doesnt have speed by themself. So motors activate but doesnt move
    # TODO need to set "set_trolley_speed" or other first. Reset after "stop_trolley"
    """Functions for setting cranes movement directions"""

    # Works
    def move_trolley_forward(self, boolean=True):
        """Set Move Trolley Forwardtrue or false."""
        self._write_node(self._node_trolley_forward, ua.DataValue(ua.Variant(
            boolean, ua.VariantType.Boolean)))

    # Works
    def move_trolley_backward(self, boolean=True):
        """Set Move Trolley Backward true or false."""
        self._write_node(self._node_trolley_backward, ua.DataValue(ua.Variant(
            boolean, ua.VariantType.Boolean)))

    # Works
    def move_bridge_forward(self, boolean=True):
        """Set Move Bridge Forward true or false."""
        self._write_node(self._node_bridge_forward, ua.DataValue(ua.Variant(
            boolean, ua.VariantType.Boolean)))

    # Works
    def move_bridge_backward(self, boolean=True):
        """Set Move Bridge Backward  true or false."""
        self._write_node(self._node_bridge_backward, ua.DataValue(ua.Variant(
            boolean, ua.VariantType.Boolean)))

    # Works
    def move_hoist_up(self, boolean=True):
        """Set Move Hoist up true or false."""
        self._write_node(self._node_hoist_up, ua.DataValue(ua.Variant(
            boolean, ua.VariantType.Boolean)))

    # Works
    def move_hoist_down(self, boolean=True):
        """Set Move Hoist down true or false."""
        self._write_node(self._node_hoist_down, ua.DataValue(ua.Variant(
            boolean, ua.VariantType.Boolean)))


    # These could be checked to remove the need for manual changing
    """Functions for getting boolean values of cranes movement directions"""

    # Works
    def get_trolley_forward(self):
        """Get Trolley_Forward boolean value."""
        return self._read_node(self._node_trolley_forward)

    # Works
    # TODO useless? only one function that is 0 or 1 could be used
    def get_trolley_backward(self):
        """Get Trolley_Backward boolean value."""
        return self._read_node(self._node_trolley_backward)

    # Works
    def get_bridge_forward(self):
        """Get Bridge_Forward boolean value."""
        return self._read_node(self._node_bridge_forward)

    # Works
    def get_bridge_backward(self):
        """Get Bridge_Backward boolean value."""
        return self._read_node(self._node_bridge_backward)

    # Works, hoist response slower than others
    def get_hoist_up(self):
        """Get Hoist_up boolean value."""
        return self._read_node(self._node_hoist_up)

    # Works, hoist response slower than others
    def get_hoist_down(self):
        """Get Hoist_down boolean value."""
        return self._read_node(self._node_hoist_down)



    """Functions to set cranes speed"""

    # Works
    def set_trolley_speed(self, speed):
        """Set speed Trolley in % 0-100"""
        self._write_node(self._node_trolley_speed, ua.DataValue(ua.Variant(
            self._scale(speed), ua.VariantType.Float)))

    # Works
    def set_bridge_speed(self, speed):
        """Set speed Bridge in % 0-100"""
        self._write_node(self._node_bridge_speed, ua.DataValue(ua.Variant(
            self._scale(speed), ua.VariantType.Float)))

    # Works
    def set_hoist_speed(self, speed):
        """Set speed Hoist in % 0-100"""
        self._write_node(self._node_hoist_speed, ua.DataValue(ua.Variant(
            self._scale(speed), ua.VariantType.Float)))


    # TODO changed "% 0-100" to "0-100 %" because confusing division mark
    # Not working, <bound method Crane.get_trolley_speed of <new_crane.Crane object at 0x000001BB4F218C10>>
    """Functions to get cranes speed"""

    # Works, but value wrong
    def get_trolley_speed(self):
        """Get speed Trolley in 0-100 % """
        return self._read_node(self._node_trolley_speed)

    # Works, but value wrong
    def get_bridge_speed(self):
        """Get speed Bridge in 0-100 %"""
        return self._read_node(self._node_bridge_speed)

    # Works, but value wrong
    def get_hoist_speed(self):
        """Get speed Hoist in 0-100 %"""
        return self._read_node(self._node_hoist_speed)



    """Functions to set crane move with specific speed to specific deirection"""
    # Works
    def move_trolley_forward_speed(self, speed):
        """Move trolley direction forward with speed"""
        self.move_trolley_backward(False)
        self.move_trolley_forward(True)
        self.set_trolley_speed(speed)
        return True

    # Works
    def move_trolley_backward_speed(self, speed):
        """Move trolley direction backward with speed"""
        self.move_trolley_forward(False)
        self.move_trolley_backward(True)
        self.set_trolley_speed(speed)
        return True

    # Works
    def move_bridge_forward_speed(self, speed):
        """Move bridge direction forward with speed"""
        self.move_bridge_backward(False)
        self.move_bridge_forward(True)
        self.set_bridge_speed(speed)
        return True

    # Works
    def move_bridge_backward_speed(self, speed):
        """Move bridge direction backward with speed"""
        self.move_bridge_forward(False)
        self.move_bridge_backward(True)
        self.set_bridge_speed(speed)
        return True

    # Works
    def move_hoist_down_speed(self, speed):
        """Move hoist direction forward with speed"""
        self.move_hoist_up(False)
        self.move_hoist_down(True)
        self.set_hoist_speed(speed)
        return True

    # Works
    def move_hoist_up_speed(self, speed):
        """Move hoist direction backward with speed"""
        self.move_hoist_down(False)
        self.move_hoist_up(True)
        self.set_hoist_speed(speed)
        return True


    # TODO Changed to trol, bridge, hoist
    """Functions for stopping crane"""

    # Works
    def stop_trolley(self):
        """Stop Trolley"""
        self.set_trolley_speed(0)
        self.move_trolley_forward(False)
        self.move_trolley_backward(False)
        time.sleep(0.1)

    # Works
    def stop_bridge(self):
        """Stop Bridge"""
        self.set_bridge_speed(0)
        self.move_bridge_forward(False)
        self.move_bridge_backward(False)
        time.sleep(0.1)

    # Works
    def stop_hoist(self):
        """Stop Hoist"""
        self.set_hoist_speed(0)
        self.move_hoist_up(False)
        self.move_hoist_down(False)
        time.sleep(0.1)

    # TODO use this instead of manual change through opcua
    # Works
    def stop_all(self, reason="stop_all"):
        """Stop all three axes, attributing each OPC UA write to *reason*."""
        with self.io_reason(reason):
            self.stop_bridge()
            self.stop_trolley()
            self.stop_hoist()
        time.sleep(0.1)


    # TODO Works, but value wrong
    # <bound method Crane.get_bridge_speed_request of <new_crane.Crane object at 0x0000023F6C81D090>>
    """Crane control signal status"""

    # Works but value wrong
    def get_trolley_speed_request(self):
        """ Get requested/target speed (ref), return negative if request is backward """
        inv = -1 if self._read_node(self._node_trolley_direction_backwards_request) else 1
        return inv*self._read_node(self._node_trolley_speed_request)

    # Works but value wrong
    def get_trolley_speed_feedback(self):
        return self._read_node(self._node_trolley_speed_feedback)

    # TODO m/min?
    # Works but value wrong
    def get_trolley_speed_feedback_mmin(self):
        return self._read_node(self._node_trolley_speed_feedback_mmin)

    # Works but value wrong
    def get_trolley_status(self):
        """ Gets the position, target speed and actual speed. Speed request is negative if request is backward """
        return self.get_trolley_position_absolute(), self.get_trolley_speed_request(), self.get_trolley_speed_feedback(), self.get_trolley_speed_feedback_mmin()

    # Works but value wrong
    def get_bridge_speed_request(self):
        """ Get requested/target speed (ref), return negative if request is backward """
        inv = -1 if self._read_node(self._node_bridge_direction_backward_request) else 1
        return inv*self._read_node(self._node_bridge_speed_request)

    # Works but value wrong
    def get_bridge_speed_feedback(self):
        return self._read_node(self._node_brige_speed_feedback)

    # Works but value wrong
    def get_bridge_speed_feedback_mmin(self):
        return self._read_node(self._node_brige_speed_feedback_mmin)

    # Works but value wrong
    def get_bridge_status(self):
        """ Gets the position, target speed and actual speed. Speed is negative if request is backward """
        return self.get_bridge_position_absolute(), self.get_bridge_speed_request(), self.get_bridge_speed_feedback(), self.get_bridge_speed_feedback_mmin()

    # Works but value wrong
    def get_hoist_speed_feedback(self):
        return self._read_node(self._node_hoist_speed_feedback)

    # Works but value wrong
    def get_hoist_speed_feedback_mmin(self):
        return self._read_node(self._node_hoist_speed_feedback_mmin)

    # Works but value wrong
    def get_hoist_speed_request(self):
        """ Get requested/target speed (ref), return negative if request is down """
        inv = -1 if self._read_node(self._node_hoist_direction_down_request) else 1
        return inv*self._read_node(self._node_hoist_speed_request)

    # Works but value wrong
    def get_hoist_status(self):
        """ Gets the position, target speed and actual speed. Speed is negative if request is down """
        return self.get_hoist_position_absolute(), self.get_hoist_speed_request(), self.get_hoist_speed_feedback(), self.get_hoist_speed_feedback_mmin()

    # What these do?
    """Functions for subscribing to crane's data"""

    class SubHandler:
        """Used with subscriptions"""

        def __init__(self, queue):
            self.queue = queue

        def datachange_notification(self, node, value, data):
            """Puts data in queue from subscripted node"""
            self.queue.put(
                [data.monitored_item.Value.Value.Value,
                 data.monitored_item.Value.SourceTimestamp.timestamp()])

    def _subscribe_node(self, interval, queue, node):
        """Create a subscription through the same serialized OPC UA session."""
        def transaction():
            handler = self.SubHandler(queue)
            subscription = self.client.create_subscription(interval, handler)
            handle = subscription.subscribe_data_change(node)
            return subscription, handle

        result, _ = self._run_io("subscription", "subscribe", transaction)
        return result

    # Not working
    def sub_trolley(self, interval, queue):
        """
        subscribes to trolleys position.
        Interval is how often data is updated from wanted node in ms.
        Queue is the queue where data will be put
        """

        return self._subscribe_node(interval, queue, self._node_trolley_position_mm)

    # Not working
    def sub_bridge(self, interval, queue):
        """
        subscribes to bridges position.
        Interval is how often data is updated from wanted node in ms.
        Queue is the queue where data will be put
        """

        return self._subscribe_node(interval, queue, self._node_bridge_position_mm)

    # Not working
    def sub_hoist(self, interval, queue):
        """
        subscribes to trolleys position.
        Interval is how often data is updated from wanted node in ms.
        Queue is the queue where data will be put
        """

        return self._subscribe_node(interval, queue, self._node_hoist_position_mm)

    # Not working
    def sub_trolley_speed(self, interval, queue):
        """
        subscribes to trolleys speed.
        Interval is how often data is updated from wanted node in ms.
        Queue is the queue where data will be put
        """

        return self._subscribe_node(interval, queue, self._node_trolley_speed_feedback)

    # Not working
    def sub_bridge_speed(self, interval, queue):
        """
        subscribes to bridges speed.
        Interval is how often data is updated from wanted node in ms.
        Queue is the queue where data will be put
        """

        return self._subscribe_node(interval, queue, self._node_brige_speed_feedback)
    
    # Not working
    def sub_hoist_speed(self, interval, queue):
        """
        subscribes to hoists speed.
        Interval is how often data is updated from wanted node in ms.
        Queue is the queue where data will be put
        """

        return self._subscribe_node(interval, queue, self._node_hoist_speed_feedback)
        
        
    # --- Global speed scaling (used by PAUSE/RESUME) -----------------------------
    def _scale(self, speed: float) -> float:
        """Apply global scale (0..1) and clamp to 0..100%."""
        try:
            v = float(speed) * float(self._global_speed_scale)
        except Exception:
            v = 0.0
        return max(0.0, min(100.0, v))

    def set_global_speed(self, scale: float) -> None:
        """Set global speed scale (0..1)."""
        self._global_speed_scale = max(0.0, min(1.0, float(scale)))

    def get_global_speed(self) -> float:
        """Get global speed scale (0..1)."""
        return float(self._global_speed_scale)

    # Aliases so the adapter can find any of these names:
    def set_speed_scaling(self, s: float): self.set_global_speed(s)
    def get_speed_scaling(self) -> float:  return self.get_global_speed()
    def set_speed_scale(self, s: float):   self.set_global_speed(s)
    def get_speed_scale(self) -> float:    return self.get_global_speed()
    def set_speed_factor(self, s: float):  self.set_global_speed(s)
    def get_speed_factor(self) -> float:   return self.get_global_speed()
