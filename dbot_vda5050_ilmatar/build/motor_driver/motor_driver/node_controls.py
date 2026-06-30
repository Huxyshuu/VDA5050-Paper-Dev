"""Conversion functions for differential drive robot"""
import logging
from typing import Union
from pathlib import Path
import yaml
import numpy as np
import canopen

# pylint: disable=import-error
from geometry_msgs.msg import Twist
from .zlac8015d_canopen_2 import MotorValues


def mps2rpm(velocity: float, wheel_radius: float) -> float:
    """Conver a velocity value from m/s to RPM.

    Args:
        velocity (float): Ground velocity (unit: m/s)
        wheel_radius (float): Radius of the wheel (unit: m)

    Returns:
        float: Wheel velocity (unit: RPM)
    """
    return velocity * 60 / (2 * np.pi * wheel_radius)


def rpm2mps(velocity: float, wheel_radius: float) -> float:
    """Convert a velocity from RPM to m/s.

    Args:
        velocity (float):  Wheel velocity (unit: RPM)
        wheel_radius (float): Radius of the wheel (unit: m)

    Returns:
        float:  Ground velocity (unit: m/s)
    """
    return velocity * (2 * np.pi * wheel_radius) / 60


def radps2rpm(velocity: float, wheel_radius: float, wheel_span: float) -> float:
    """Convert angular velocity from rad/s to wheel RPM.

    Args:
        velocity (float): Angular velocity (unit: rad/s)
        wheel_radius (float): Radius of wheel (unit: m)
        wheel_span (float): Distance between wheels (unit: m)

    Returns:
        float: Wheel RPM (unit: r/min)
    """
    return mps2rpm(velocity * (wheel_span / 2), wheel_radius)


def rpm2radps(velocity: float, wheel_radius: float, wheel_span: float) -> float:
    """Convert from wheel RPM to angular velocity in rad/s.

    Args:
        velocity (float): Wheel RPM (unit: r/min)
        wheel_radius (float): Radius of wheel (unit: m)
        wheel_span (float): Distance between wheels (unit: m)

    Returns:
        float: Angular velocity (unit: rad/s)
    """
    return rpm2mps(velocity, wheel_radius) / (wheel_span / 2)


def rpms2linear(velocities: MotorValues, wheel_radius: float) -> float:
    """Convert differential drive robots wheel velocities in RPM to linear velocity in m/s.

    Args:
        velocities (MotorValues): Wheel velocities for left and right wheel (unit: r/min)
        wheel_radius (float): Radius of wheels (unit: m)

    Returns:
        float: Linear velocity of robot (unit: m/s)
    """
    return rpm2mps((velocities.left + velocities.right) / 2, wheel_radius)


def rpms2angular(
    velocities: MotorValues, wheel_radius: float, wheel_span: float
) -> float:
    """Convert differential drive robots wheel velocities in RPM to angular velocity in rad/s.

    Args:
        velocities (MotorValues): Wheel velocities for left and right wheel (unit: r/min)
        wheel_radius (float): Radius of wheels (unit: m)
        wheel_span (float): Distance between wheels (unit: m)

    Returns:
        float: Angular velocity of robot (unit: rad/s)
    """
    return rpm2radps((velocities.right - velocities.left) / 2, wheel_radius, wheel_span)


def get_config(file: Union[str, Path]) -> dict:
    """Get the yaml config for the D-Bot."""
    with open(file=file, mode="r", encoding="utf8") as file:
        config = yaml.load(file, yaml.FullLoader)
    return config


def connect_network(config: dict) -> canopen.Network:
    """Connect to PCAN-USB and add ZLAC8015D node"""

    # Create CANopen network and connect to PEAK systems USB-CAN device
    logging.debug("Connecting to CANopen network")
    canopen_network = canopen.Network()
    canopen_network.connect(
        bustype=config["bustype"], channel=config["channel"], bitrate=config["bitrate"]
    )
    # Check that no errors has occured in the recieving thread
    logging.debug("Checking for possible CANopen connection errors")
    canopen_network.check()
    logging.info("CAN bus connected. State: %s", canopen_network.bus.state)
    return canopen_network


def disconnect_network(network: canopen.Network):
    """Disconnect from CAN bus"""
    logging.info("Disconnecting CAN bus")
    if network:
        for node_id in network:
            node = network[node_id]
            node.state = "SWITCH ON DISABLED"
            node.nmt.state = "PRE-OPERATIONAL"
        network.sync.stop()
        network.disconnect()


def twist_to_motor_speeds(
    twist_msg: Twist, wheel_radius: float, wheel_span: float
) -> MotorValues:
    """Conversion function from ROS Twist message's linear and angular velocities to left and right motor speeds."""
    linear_x = twist_msg.linear.x  # Linear velocity along the x-axis (forward)
    angular_z = twist_msg.angular.z  # Angular velocity around the z-axis (yaw rate)

    # Convert linear and angular velocities to left and right motor speeds
    left_motor_speed = int((2 * linear_x - angular_z * wheel_span) / (2 * wheel_radius))
    right_motor_speed = int((2 * linear_x + angular_z * wheel_span) / (2 * wheel_radius))

    # Return the left and right motor speeds in rpm
    return MotorValues(left_motor_speed, right_motor_speed)


def motor_speeds_to_twist(
    velocities: MotorValues, wheel_radius: float, wheel_span: float
) -> Twist:
    """Conversion function from left and right motor speeds to ROS Twist message's
    linear and angular velocities."""
    msg = Twist()
    msg.linear.x = rpms2linear(velocities, wheel_radius)
    msg.angular.z = rpms2angular(velocities, wheel_radius, wheel_span)
    return msg
