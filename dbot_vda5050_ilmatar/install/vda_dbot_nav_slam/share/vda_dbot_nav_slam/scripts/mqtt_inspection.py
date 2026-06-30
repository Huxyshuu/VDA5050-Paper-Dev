#!/usr/bin/env python3

import rclpy
from geometry_msgs.msg import PoseStamped
from nav2_simple_commander.robot_navigator import BasicNavigator, TaskResult
from paho.mqtt import client as mqtt_client
import json
import threading
import time

# MQTT Configuration
BROKER = '192.168.1.115'
PORT = 1883
TOPIC_COMMAND = "robot/control"
TOPIC_STATUS = "robot/status"
USERNAME = 'vda5050'
PASSWORD = 'vda5050'
CLIENT_ID = 'nav-robot'

# Global flags
current_command = None
manual_override_active = False

# Define poses
def get_home_pose(navigator):
    pose = PoseStamped()
    pose.header.frame_id = 'map'
    pose.header.stamp = navigator.get_clock().now().to_msg()
    pose.pose.position.x = 2.8660196518413743
    pose.pose.position.y = -8.390116662088968
    pose.pose.orientation.z = 0.6640529114284784
    pose.pose.orientation.w = 0.7476855828644561
    return pose

def get_start_pose(navigator):
    pose = PoseStamped()
    pose.header.frame_id = 'map'
    pose.header.stamp = navigator.get_clock().now().to_msg()
    pose.pose.position.x = -0.9451751252784691
    pose.pose.position.y = -0.11670155554402738
    pose.pose.orientation.z = -0.7425778437096872
    pose.pose.orientation.w = 0.669759767402814
    return pose

# MQTT Callbacks
def on_connect(client, userdata, flags, rc):
    if rc == 0:
        print("MQTT connected successfully")
        client.subscribe(TOPIC_COMMAND)
    else:
        print(f"Failed to connect to MQTT broker, return code {rc}")

def on_message(client, userdata, msg):
    global current_command, manual_override_active
    try:
        payload = json.loads(msg.payload.decode())
        command = payload.get("command", "")
        print(f"Received MQTT command: {command}")

        if command == "go_to_start":
            manual_override_active = False
            current_command = command
        elif command == "go_home":
            manual_override_active = False
            current_command = command
        elif command == "stop_inspection":
            print("Received stop command.")
            manual_override_active = False  # Reset manual override
            current_command = "go_home"
            publish_status(client, {"status": "stopping_and_returning_home"})
        elif command == "manual_override_on":
            manual_override_active = True
            current_command = "cancel_and_manual"
            publish_status(client, {"status": "manual_override_active"})
        elif command == "manual_override_off":
            manual_override_active = False
            current_command = None
            publish_status(client, {"status": "manual_override_disabled"})
        else:
            print(f"Unknown command received: {command}")
    except json.JSONDecodeError:
        print("Failed to decode MQTT message.")

def publish_status(client, status_dict):
    payload = json.dumps(status_dict)
    client.publish(TOPIC_STATUS, payload)
    print(f"Published status: {payload}")

# MQTT Loop in background thread
def mqtt_loop():
    client = mqtt_client.Client(CLIENT_ID)
    client.username_pw_set(USERNAME, PASSWORD)
    client.on_connect = on_connect
    client.on_message = on_message
    client.connect(BROKER, PORT)
    client.loop_forever()

# Navigation command loop
def command_loop(navigator, mqtt_client_instance):
    global current_command

    while rclpy.ok():
        if current_command is None:
            time.sleep(0.2)
            continue

        if current_command == "go_to_start":
            print("Navigating to start location...")
            pose = get_start_pose(navigator)
            navigator.goToPose(pose)

            while not navigator.isTaskComplete():
                if manual_override_active:
                    print("Manual override triggered. Cancelling navigation.")
                    navigator.cancelTask()
                    break
                time.sleep(0.5)

            if not manual_override_active and navigator.getResult() == TaskResult.SUCCEEDED:
                print("Arrived at start location.")
                publish_status(mqtt_client_instance, {"status": "at_start"})

        elif current_command == "go_home":
            print("Navigating to home position...")
            pose = get_home_pose(navigator)
            navigator.goToPose(pose)

            while not navigator.isTaskComplete():
                time.sleep(0.5)

            if navigator.getResult() == TaskResult.SUCCEEDED:
                print("Returned to home position.")
                publish_status(mqtt_client_instance, {"status": "at_home"})

        elif current_command == "cancel_and_manual":
            navigator.cancelTask()
            print("Cancelled current goal for manual control.")

        current_command = None

# Main function
def main():
    global current_command

    # Start MQTT listener thread
    threading.Thread(target=mqtt_loop, daemon=True).start()

    # ROS setup
    rclpy.init()
    navigator = BasicNavigator()
    navigator.waitUntilNav2Active()

    # Set initial pose to home
    initial_pose = get_home_pose(navigator)
    navigator.setInitialPose(initial_pose)

    # Separate MQTT client for publishing status
    mqtt_client_instance = mqtt_client.Client(CLIENT_ID + "_status")
    mqtt_client_instance.username_pw_set(USERNAME, PASSWORD)
    mqtt_client_instance.connect(BROKER, PORT)
    mqtt_client_instance.loop_start()

    try:
        command_loop(navigator, mqtt_client_instance)
    except KeyboardInterrupt:
        print("Shutting down...")
    finally:
        mqtt_client_instance.loop_stop()
        mqtt_client_instance.disconnect()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
