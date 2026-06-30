#!/usr/bin/env python3

import rclpy
from geometry_msgs.msg import PoseStamped
from nav2_simple_commander.robot_navigator import BasicNavigator, TaskResult
from rclpy.duration import Duration
from paho.mqtt import client as mqtt_client
import json
import threading
import time

# MQTT Configuration
BROKER = '192.168.1.150'
PORT = 1883
TOPIC = "robot/control"
USERNAME = 'admin'
PASSWORD = 'admin'
CLIENT_ID = 'nav-robot'

# Global flags
start_inspection_flag = False
stop_requested = False
inspection_in_progress = False

# MQTT Callbacks
def on_connect(client, userdata, flags, rc):
    if rc == 0:
        print("MQTT connected successfully")
        client.subscribe(TOPIC)
    else:
        print(f"Failed to connect to MQTT broker, return code {rc}")

def on_message(client, userdata, msg):
    global start_inspection_flag, stop_requested, inspection_in_progress
    try:
        payload = json.loads(msg.payload.decode())
        command = payload.get("command", "")

        if command == "start_inspection":
            if not inspection_in_progress:
                print("Received start command.")
                start_inspection_flag = True
            else:
                print("Inspection already in progress. Ignoring start command.")
        elif command == "stop_inspection":
            print("Received stop command.")
            stop_requested = True
        else:
            print(f"Unknown command received: {command}")
    except json.JSONDecodeError:
        print("Failed to decode MQTT message.")

# MQTT Thread
def mqtt_thread():
    client = mqtt_client.Client(CLIENT_ID)
    client.username_pw_set(USERNAME, PASSWORD)
    client.on_connect = on_connect
    client.on_message = on_message
    client.connect(BROKER, PORT)
    client.loop_forever()

# Wait for start command
def wait_for_start():
    global start_inspection_flag
    print("Waiting for 'start_inspection' command from MQTT...")
    while not start_inspection_flag:
        time.sleep(0.5)

# Return to new home position (the old initial pose)
def return_to_home(navigator):
    print("Returning to home position...")
    home_pose = PoseStamped()
    home_pose.header.frame_id = 'map'
    home_pose.header.stamp = navigator.get_clock().now().to_msg()
    home_pose.pose.position.x = 0.06915
    home_pose.pose.position.y = 0.00875
    home_pose.pose.orientation.z = -0.01012096346046257
    home_pose.pose.orientation.w = 0.9999487817376608

    navigator.goToPose(home_pose)

    while not navigator.isTaskComplete():
        time.sleep(1)

    print("Returned to home position.")

# Main inspection routine
def run_inspection(navigator, initial_pose):
    global stop_requested, start_inspection_flag, inspection_in_progress
    stop_requested = False
    start_inspection_flag = False
    inspection_in_progress = True

    # Re-stamp and set initial pose
    initial_pose.header.stamp = navigator.get_clock().now().to_msg()
    navigator.setInitialPose(initial_pose)

    # Define goal poses
    goal_poses = []

    goal_pose1 = PoseStamped()
    goal_pose1.header.frame_id = 'map'
    goal_pose1.header.stamp = navigator.get_clock().now().to_msg()
    goal_pose1.pose.position.x = -0.07
    goal_pose1.pose.position.y = -4.12
    goal_pose1.pose.orientation.w = -0.74264
    goal_pose1.pose.orientation.z = 0.66969
    goal_poses.append(goal_pose1)

    goal_pose2 = PoseStamped()
    goal_pose2.header.frame_id = 'map'
    goal_pose2.header.stamp = navigator.get_clock().now().to_msg()
    goal_pose2.pose.position.x = -1.89
    goal_pose2.pose.position.y = -3.82
    goal_pose2.pose.orientation.w = 0.99630
    goal_pose2.pose.orientation.z = 0.08593
    goal_poses.append(goal_pose2)

    goal_pose3 = PoseStamped()
    goal_pose3.header.frame_id = 'map'
    goal_pose3.header.stamp = navigator.get_clock().now().to_msg()
    goal_pose3.pose.position.x = -1.25
    goal_pose3.pose.position.y = 0.10
    goal_pose3.pose.orientation.w = 0.13027
    goal_pose3.pose.orientation.z = 0.99148
    goal_poses.append(goal_pose3)

    navigator.goThroughPoses(goal_poses)

    i = 0
    while not navigator.isTaskComplete():
        i += 1
        feedback = navigator.getFeedback()

        if feedback and i % 5 == 0:
            eta = Duration.from_msg(feedback.estimated_time_remaining).nanoseconds / 1e9
            print(f'ETA: {eta:.0f} seconds')

        if stop_requested:
            print("Stop requested. Cancelling navigation.")
            navigator.cancelTask()

            while not navigator.isTaskComplete():
                time.sleep(0.5)

            print("Navigation canceled. Returning home.")
            return_to_home(navigator)

            start_inspection_flag = False
            stop_requested = False
            inspection_in_progress = False
            return

    # Normal result handling
    result = navigator.getResult()
    if result == TaskResult.SUCCEEDED:
        print('Inspection complete.')
        return_to_home(navigator)
    elif result == TaskResult.CANCELED:
        print('Navigation canceled by user.')
    elif result == TaskResult.FAILED:
        print('Navigation failed.')
    else:
        print('Unknown navigation result.')

    start_inspection_flag = False
    stop_requested = False
    inspection_in_progress = False

# Main execution loop
def main():
    global inspection_in_progress

    mqtt_thread_handle = threading.Thread(target=mqtt_thread, daemon=True)
    mqtt_thread_handle.start()

    rclpy.init()
    navigator = BasicNavigator()
    navigator.waitUntilNav2Active()

    # Updated initial pose
    initial_pose = PoseStamped()
    initial_pose.header.frame_id = 'map'
    initial_pose.pose.position.x = 0.31111342927293456
    initial_pose.pose.position.y = -0.019256190677326222
    initial_pose.pose.position.z = 0.0
    initial_pose.pose.orientation.x = 0.0
    initial_pose.pose.orientation.y = 0.0
    initial_pose.pose.orientation.z = 0.16858797441667703
    initial_pose.pose.orientation.w = 0.9856866108870922

    while True:
        wait_for_start()
        run_inspection(navigator, initial_pose)

if __name__ == '__main__':
    main()
