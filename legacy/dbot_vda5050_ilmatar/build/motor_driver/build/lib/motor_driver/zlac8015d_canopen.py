"""Provides missing functionality for ZLAC8015D Servo Motor driver to use canopen BaseNode402."""
import logging
import time
import struct
from typing import NamedTuple, Union

from canopen.profiles.p402 import BaseNode402
from canopen.pdo.base import Map

from . import od_definitions as defs
from .log_connector import ConnectPythonLoggingToROS2
#from std_msgs.msg import Float64


# reconnect logging calls which are children of this to the ros log system
logging.getLogger(__name__).addHandler(ConnectPythonLoggingToROS2())
# logs sent to children of trigger with a level >= this will be redirected to ROS
logging.getLogger(__name__).setLevel(logging.DEBUG)


class MotorValues(NamedTuple):
    """NamedTuple used for passing motor values for both left and right motor.

    Args:
        left (int | float | bool): Value for left motor.
        right (int | float | bool): Value for right motor.
    """

    left: Union[int, float, bool] = 0
    right: Union[int, float, bool] = 0


class ZLAC8015D(BaseNode402):
    """Class that abstracts some ZLAC8015D fucntions,
    and adds missing functionality to canopen BaseNode402"""

    def __init__(self, node_id, object_dictionary) -> None:
        super().__init__(node_id=node_id, object_dictionary=object_dictionary)

        # Add additional info to OD for more readable code
        defs.add_od_descriptions(self.object_dictionary, defs.OD_DESCRIPTIONS)
        defs.add_od_value_descriptions(
            self.object_dictionary, defs.OD_VALUE_DESCRIPTIONS
        )
        defs.add_od_bit_definitions(self.object_dictionary, defs.OD_BIT_DEFINITIONS)
        defs.add_od_factors_and_units(self.object_dictionary, defs.OD_FACTORS_AND_UNITS)

        self.velocity = MotorValues(0, 0)
        self.position = MotorValues(0, 0)
        #self.velocity_control_mode = self.sdo["Synchronous/asynchronous control flag"]
        logging.info("Driver initialized successfully!")

    def is_op_mode_supported(self, mode):
        """Check if the operation mode is supported by the node.

        Overwrites BaseNode402 checker that uses SDO, as ZLAC8015D does not include entry 0x6502 for supported operation modes.

        Args:
            mode (str): operation mode (see documentation for supported modes)

        Returns:
            bool: If the operation mode is supported.
        """
        supported_modes = {
            "NO MODE",
            "PROFILED POSITION",
            "PROFILED VELOCITY",
            "PROFILED TORQUE",
        }
        return mode in supported_modes

    def get_errors(self):
        """Check over SDO if there are any errors in register 0x603F

        Reads 0x603F over SDO, then checks if any of the error flags are set and appends the corresponding description to the return array

        Returns:
            List[str] | None: List of errors as strings, None if no errors present
        """
        bits = self.sdo[0x603F].raw
        if not bits == 0:
            return None
        errors = []
        for bit, error in defs.ERROR_FLAGS.items():
            if bits & bit:
                errors.append(error)
        return errors

    def _position_callback(self, message: Map):
        """Callback function for storing position values over PDO.

        Args:
            message (Map): PDO message
        """
        self.position = MotorValues(
            left=message["Position actual value.Position actual value (left)"].phys,
            right=message["Position actual value.Position actual value (right)"].phys,
        )

    def _velocity_callback(self, message: Map):
        """Callback function for storing velocity values over PDO.

        Args:
            message (Map): PDO message
        """
        logging.info("Velocity callback called!")
        
        self.velocity = MotorValues(
            left=message["Velocity actual value.Velocity actual value (left)"].phys,
            right=message["Velocity actual value.Velocity actual value (right)"].phys,
        )
        logging.info(self.velocity)

    # def setup_pdo(self):
    #     """Setup planned PDO mappings."""

    #     self.pdo.read()

    #     # Setup TPDO1 with Statusword and Operation mode display
    #     self.tpdo[1].clear()
    #     self.tpdo[1].add_variable("Statusword")  # U32 
    #     self.tpdo[1].add_variable("Modes of operation display")  # I8 6041
    #     self.tpdo[1].trans_type = 255
    #     self.tpdo[1].event_timer = 100
    #     self.tpdo[1].enabled = True

    #     self.tpdo[2].clear()
    #     self.tpdo[2].add_variable(
    #         "Position actual value", "Position actual value (left)"
    #     )  # I32 Encoder pos left
    #     self.tpdo[2].add_variable(
    #         "Position actual value", "Position actual value (right)"
    #     )  # I32 Encoder pos right
    #     self.tpdo[2].trans_type = 255
    #     self.tpdo[2].event_timer = 100
    #     self.tpdo[2].enabled = True
    #     self.tpdo[2].add_callback(self._position_callback)

    #     self.tpdo[3].clear()
    #     self.tpdo[3].add_variable(
    #         "Velocity actual value", "Velocity actual value (left)"
    #     )  # I32 Velocity left
    #     self.tpdo[3].add_variable(
    #         "Velocity actual value", "Velocity actual value (right)"
    #     )  # I32 Velocity right
    #     self.tpdo[3].trans_type = 255
    #     self.tpdo[3].inhibit_time = 100
    #     self.tpdo[3].event_timer = 1000
    #     self.tpdo[3].add_callback(self._velocity_callback)
    #     self.tpdo[3].enabled = True

    #     self.rpdo[1].clear()
    #     self.rpdo[1].add_variable("Controlword")  # U16
    #     self.rpdo[1].add_variable("Modes of operation")  # U8
    #     self.rpdo[1].enabled = True

    #     self.rpdo[2].clear()
    #     self.rpdo[2].add_variable(
    #         "Target position", "Target position (left)"
    #     )  # I32 Target pos left
    #     self.rpdo[2].add_variable(
    #         "Target position", "Target position (right)"
    #     )  # I32 Target pos right
    #     self.rpdo[2].enabled = True

    #     self.rpdo[3].clear()
    #     self.rpdo[3].add_variable(
    #         "Target velocity", "Target velocity (left)"
    #     )  # I32 Target velocity left
    #     self.rpdo[3].add_variable(
    #         "Target velocity", "Target velocity (right)"
    #     )  # I32 Target velocity right
    #     self.rpdo[3].enabled = True

    #     logging.debug("Node state before saving PDO: %s", self.nmt.state)
    #     self.nmt.state = "PRE-OPERATIONAL"
    #     self.tpdo[1].save()
    #     self.tpdo[2].save()
    #     self.tpdo[3].save()
    #     logging.debug("Node TPDO saved!")
    #     self.rpdo[1].save()
    #     self.rpdo[2].save()
    #     self.rpdo[3].save()
    #     logging.debug("Node RPDO saved!")

    #def setup_sdo(self):
     #   self.VELOCITY_INDEX = 0x606C
     #   self.SUBINDEX_LEFT = 1
     #   self.SUBINDEX_RIGHT = 2
     #   self.SUBINDEX_BOTH = 3
        

    def set_dual_pdo_value(self, index: Union[str, int], values: MotorValues):
        """Set the byte value over pdo."""
        self.pdo[index].data = struct.pack("<hh", -values.right, values.left)

    def get_dual_pdo_value(self, index: Union[str, int]) -> MotorValues:
        """Get the byte value over pdo."""
        values = MotorValues()
        values.left, values.right = struct.unpack("<hh", self.pdo[index].data)
        values.right *= -1
        return values

    def set_both_motors(self, index: Union[int, str], values: MotorValues):
        """Sets index to values for both left and right motor

        Assuming that the left motors value is stored at subindex 1 and the right at subindex 2.
        Sets the physical value (Variable.factor * value)

        Args:
            index (Union[int, str]): Object directory index or name for value to set
            values (MotorValues): Values to set the values at <index>sub01 and <index>sub02 to
        """
        obj = self.sdo[index]
        obj[1].phys = values.left
        obj[2].phys = values.right

    def get_both_motors(self, index: Union[int, str]) -> MotorValues:
        """Gets values at index for both left and right motor

        Assuming that the left motors value is stored at subindex 1 and the right at subindex 2.
        Gets the physical value (Variable.factor * value)

        Args:
            index (Union[int, str]): Object directory index or name for value to get

        Returns:
            MotorValues: Physical values of the motors' attributes
        """
        obj = self.sdo[index]
        return MotorValues(left=obj[1].phys, right=obj[2].phys)

    def set_acceleration_time(self, acc_time: MotorValues):
        """Set time (in ms) for acceleration profile

        Args:
            time (MotorValues): Acceleration time (unit: ms) for left and right motor
        """
        self.set_both_motors("Profile acceleration", acc_time)

    def set_deceleration_time(self, dec_time: MotorValues):
        """Set time (in ms) for deceleration profile

        Args:
            time (MotorValues): Deceleration time (unit: ms) for left and right motor
        """
        self.set_both_motors("Profile deceleration", dec_time)

    def set_max_velocity(self, velocities: MotorValues):
        """Set maximum velocity (in r/min) for motors, used in profiled position mode

        Args:
            velocities (MotorValues): Maximum velocity (unit: r/min) for left and right motor
        """
        self.set_both_motors("Profile velocity", velocities)

    def set_sync_target_velocity(self, velocities: MotorValues):
        """Set the target velocities for motors synchronously at index 0x60FF subindex 3.

        Args:
            velocities (MotorValues): Target velocities (unit: r/min) for left and right mode
        """
        # TODO! OD says it read only? Might not work... Also check left low, right high or opposite, and negative values
        # pylint: disable=unsubscriptable-object
        # obj = self.sdo["Target velocity"]["Target velocity (both)"]
        # obj.bits["left"] = velocities.left
        # obj.bits["right"] = -velocities.right
        # Alternatives:
        value = struct.pack("<hh", velocities.left, -velocities.right)
        self.sdo["Target velocity"]["Target velocity (both)"].raw = value
        value = (velocities.left << 16) | (-velocities.right)

        #self.VELOCITY_INDEX = 0x606C
        #self.SUBINDEX_LEFT = 1
        #self.SUBINDEX_RIGHT = 2

        #velocity_left = self.sdo[self.VELOCITY_INDEX][self.SUBINDEX_LEFT].raw
        #velocity_right = self.sdo[self.VELOCITY_INDEX][self.SUBINDEX_RIGHT].raw

        #velocity_left_msg = Float64()
        #velocity_right_msg = Float64()

        #velocity_left = 10 * float(velocity_left) 
        #velocity_right = -10 * float(velocity_right) 

        #self.publisher_left.publish(velocity_left_msg)
        #self.publisher_right.publish(velocity_right_msg)
        #print(f'Publishing Velocity Left: {velocity_left}, Velocity Right: {velocity_right}')

    def set_async_target_velocity(self, velocities: MotorValues):
        """Set the target velocities for motors asynchronously at index 0x60FF subindex 1 and 2.

        Args:
            velocities (MotorValues): Target velocities (unit: r/min) for left and right mode
        """
        if 0x60FF in self.rpdo_pointers:
            # Set target velocity over PDO
            self.rpdo[3][
                "Target velocity.Target velocity (left)"
            ].phys = velocities.left
            self.rpdo[3][
                "Target velocity.Target velocity (right)"
            ].phys = velocities.right
            self.rpdo[3].transmit()
        else:
            # Set target velocity over SDO
            self.set_both_motors("Target velocity", velocities)
            logging.info(
                "Setup target velocity to use PDO communication for better response."
            )

    def set_target_velocity(self, velocities: MotorValues):
        """Set target velocities for both motors in profiled velocity mode

        Args:
            velocities (MotorValues): Target velocities for motors
            sync (bool, optional): If the motors are controlled synchronously. Defaults to False.
        """
        # self.set_velocity_pdo(velocities)
        #if self.velocity_control_mode.desc == "sync":
        self.set_sync_target_velocity(velocities)
        #else:
        #    self.set_async_target_velocity(velocities)

    def set_target_position(self, target_pos: MotorValues):
        """Motor encoders target position.

        Args:
            target_pos (MotorValues): Target position for encoders in pulses.
        """
        self.set_both_motors("Target position", target_pos)

    def halt_operation(self, halt=True):
        """Halts the operation by setting the halt bit in the controlword.

        Args:
            halt (bool, optional): The value of the halt bit. Defaults to True.
        """
        self.sdo["Controlword"].bits["Halt"] = halt

    def init_profile_velocity(
        self,
        sync: bool = False,
        acceleration: MotorValues = MotorValues(100, 100),
        deceleration: MotorValues = MotorValues(100, 100),
    ):
        """Initialize and start profile velocity mode

        Follows the example given in ZLAC8015D CANopen documentation on pages 17-19

        Args:
            sync (bool, optional): If the motors should be controlled syncronously. Defaults to False.
            timeout (int, optional): Time after wich operation is disabeld. If <= 0, the operation will not be disabled. Defaults to 0.
        """
        # Set 402 state machine to enable power
        #self.state = "SWITCHED ON"

        # Set synchronous or asynchronous control mode and operation mode to profiled velocity
        #self.velocity_control_mode.desc = "sync" if sync else "async"
        #self.op_mode = "PROFILED VELOCITY"

        # Set the acceleration and deceleration times for profiled velocity mode
        self.set_acceleration_time(acceleration)
        self.set_deceleration_time(deceleration)

        # Enable operation for 402 state machine, ready to take target velocities
        self.state = "OPERATION ENABLED"

    def init_profile_position(
        self,
        max_velocity: MotorValues = MotorValues(120, 120),
        acceleration: MotorValues = MotorValues(100, 100),
        deceleration: MotorValues = MotorValues(100, 100),
    ):
        """Initialize drivers profiled position mode and enable operation

        Args:
            max_velocity (MotorValues, optional): Maximum velocity for motors (unit: r/min). Defaults to MotorValues(120, 120).
            acceleration (MotorValues, optional): Acceleration time (unit: ms). Defaults to MotorValues(100, 100).
            deceleration (MotorValues, optional): Deceleration time (unit: ms). Defaults to MotorValues(100, 100).
        """
        self.state = "SWITCHED ON"

        self.op_mode = "PROFILED POSITION"
        self.set_acceleration_time(acceleration)
        self.set_deceleration_time(deceleration)
        self.set_max_velocity(max_velocity)
        self.state = "OPERATION ENABLED"
        logging.info(
            "Position mode initialised. Node state %s, OP mode %s",
            self.state,
            self.op_mode,
        )

    def goto_target_position(self, target_pos: MotorValues, relative: bool = True):
        """Sets a target position and enables operation. Waits for motors to reach target.

        Args:
            target_pos (MotorValues): Target positions for motor encoders.
            relative (bool, optional): Relative or absolute positions. Defaults to True (relative).
        """
        self.set_target_position(target_pos)
        self.state = "OPERATION ENABLED"
        self.sdo["Controlword"].bits["Relative"] = relative
        self.sdo["Controlword"].bits["New set-point"] = True
        logging.info(
            "Target set, waitng for reached message. Statusword %s",
            self.sdo["Statusword"].raw,
        )
        logging.info(
            "Initial velocity: %d",
            self.tpdo["Velocity actual value.Velocity actual value (left)"].phys,
        )
        logging.info(
            "Initial position: %d",
            self.tpdo["Position actual value.Position actual value (left)"].phys,
        )
        print(self.sdo["Statusword"].bits["Target reached (right)"] is False)
        while (
            self.sdo["Statusword"].bits["Target reached (right)"] == False
            or self.sdo["Statusword"].bits["Target reached (left)"] == False
        ):
            time.sleep(1)
            logging.info("Waiting for Target reached to be set to true")
            logging.info(
                "Current velocity: %d",
                self.tpdo["Velocity actual value.Velocity actual value (left)"].phys,
            )
            logging.info(
                "Current position: %d",
                self.tpdo["Position actual value.Position actual value (left)"].phys,
            )
        logging.info(
            "Final velocity: %d",
            self.tpdo["Velocity actual value.Velocity actual value (left)"].phys,
        )
        logging.info(
            "Final position: %d",
            self.tpdo["Position actual value.Position actual value (left)"].phys,
        )

    def clear_position_feedback(self, motors: MotorValues = MotorValues(True, True)):
        """Clears the motor drivers position feedback, used for relative position mode.

        Args:
            motors (MotorValues, optional): Which motor's feedback should be cleared. Defaults to MotorValues(True, True).
        """
        obj = self.sdo["Clear position feedback"]
        obj.bits["left"] = motors.left
        obj.bits["right"] = motors.right

    def set_cuurent_pos_as_origin(self, motors: MotorValues = MotorValues(True, True)):
        obj = self.sdo["Set original position"]
        if motors.left and motors.right:
            obj.desc = "both"
        elif motors.left:
            obj.desc = "left"
        elif motors.right:
            obj.desc = "right"
        else:
            obj.desc = "invalid"

    def set_max_velocity_limit(self, velocity: int = 1000):
        self.sdo["Motor max speed"].phys = velocity

    def restore_register_params_to_factory_settings(self):
        self.sdo["Register parameter setting"].raw = 1

    def get_starting_speed(self) -> MotorValues:
        # TODO! Test this, what can it be used for?
        return self.get_both_motors("Starting speed")

    def get_encoder_wire_amount(self) -> MotorValues:
        # TODO! Test this, use for position control (count -> rounds, deg)
        return self.get_both_motors("Encoder wire number setting")

    def store_changes_synchronously_to_eeprom(self, store: bool):
        self.sdo["Whether the parameters are updated to EEPROM"] = store

    def get_position(self) -> MotorValues:
        return self.position

    def get_velocity(self) -> MotorValues:
        return self.velocity
