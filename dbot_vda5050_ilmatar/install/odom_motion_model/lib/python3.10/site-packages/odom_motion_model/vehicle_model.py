#! /usr/bin/env python3

## Refer chapter 5 section 5.3 of Probabilistics Robotics book by Sebastian Thrun to understand this code

import numpy as np
import math

X = 0
Y = 1
THETA = 2

def euler_to_quaternion(roll, pitch, yaw):
    """
    Convert Euler angles (roll, pitch, yaw) to quaternion representation.

    Parameters:
        roll (float): Roll angle in radians.
        pitch (float): Pitch angle in radians.
        yaw (float): Yaw angle in radians.

    Returns:
        numpy.array: Quaternion representation [w, x, y, z].
    """
    cy = math.cos(yaw * 0.5)
    sy = math.sin(yaw * 0.5)
    cp = math.cos(pitch * 0.5)
    sp = math.sin(pitch * 0.5)
    cr = math.cos(roll * 0.5)
    sr = math.sin(roll * 0.5)

    w = cr * cp * cy + sr * sp * sy
    x = sr * cp * cy - cr * sp * sy
    y = cr * sp * cy + sr * cp * sy
    z = cr * cp * sy - sr * sp * cy

    return [w, x, y, z]

class VehicleModel:
    def __init__(self, initial_position=[0.0, 0.0, 0.0], radius=0.1, wheel_base=0.65, initialize_time=None):
        self.current_state = initial_position

        self.radius_ = radius
        self.wheel_base_ = wheel_base
        self.previous_time = None # initialize_time

    def update_state(self, encoder_left_rpm, encoder_right_rpm, current_time):
        # Conversion from RPM to linear dist per second
        v_left = (2 * math.pi * self.radius_) * encoder_left_rpm / 60
        v_right = (2 * math.pi * self.radius_) * encoder_right_rpm / 60 

        # Calculate linear and angular velocities
        linear_vel = (v_right + v_left) / 2
        angular_vel = (v_right - v_left) / self.wheel_base_

        # Define radius of curvatire
        radius = 0.
        if abs(v_left - v_right) > 0.000001:
            radius = linear_vel / angular_vel

        x_c = self.current_state[X] - radius*math.sin(self.current_state[THETA])
        y_c = self.current_state[Y] + radius*math.cos(self.current_state[THETA])

        if self.previous_time == None:
            self.previous_time = current_time

        dt = (current_time.sec+current_time.nanosec*1e-9) - (self.previous_time.sec+self.previous_time.nanosec*1e-9)
        self.previous_time = current_time

        dyaw = self.current_state[THETA] + angular_vel*dt
        # Normalize yaw angle to (-pi, pi) range
        dyaw = math.atan2(math.sin(dyaw), math.cos(dyaw))
        
        # Update position and yaw
        self.current_state[X] = x_c + radius*math.sin(dyaw)
        self.current_state[Y] = y_c - radius*math.cos(dyaw)
        self.current_state[THETA] = dyaw
        
        quaternion = euler_to_quaternion(0.0, 0.0, dyaw)
        # Return current state (x, y, yaw), quaternions
        return self.current_state, quaternion, linear_vel, angular_vel