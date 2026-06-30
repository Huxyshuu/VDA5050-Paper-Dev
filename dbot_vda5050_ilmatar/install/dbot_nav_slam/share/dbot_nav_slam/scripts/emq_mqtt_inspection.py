#!/usr/bin/env python3

import rclpy
from geometry_msgs.msg import PoseStamped
from nav2_simple_commander.robot_navigator import BasicNavigator, TaskResult
from paho.mqtt import client as mqtt_client
import json
import threading
import time
import random
import logging
import os


# === MQTT CONFIGURATION (match your first script) ===
BROKER = 'i7e2212f.ala.eu-central-1.emqxsl.com'
PORT = 8883
TOPIC_COMMAND = "robot/control"
TOPIC_STATUS = "robot/status"
USERNAME = 'admin'
PASSWORD = 'admin'
CA_CERTS = '/home/dbot2/ros2_ws/src/dbot_nav_slam/scripts/emqxsl-ca.crt'
CLIENT_ID = f'nav-robot-{random.randint(0, 1000)}'


# Reconnect params (same as your UI app)
FIRST_RECONNECT_DELAY = 1
RECONNECT_RATE = 2
MAX_RECONNECT_COUNT = 12
MAX_RECONNECT_DELAY = 60

# Global flags
current_command = None
manual_override_active = False
mqtt_client_instance = None  # Global client for publishing status

# Define poses
def get_home_pose(navigator):
    pose = PoseStamped()
    pose.header.frame_id = 'map'
    pose.header.stamp = navigator.get_clock().now().to_msg()
    pose.pose.position.x = 0.5600028109498111
    pose.pose.position.y = -2.0063307877073226
    pose.pose.orientation.z = 0.7544211433660732
    pose.pose.orientation.w = 0.6563906903988103
    
    # pose.header.stamp = navigator.get_clock().now().to_msg()
    # pose.pose.position.x = 0.36857872087308025
    # pose.pose.position.y = -2.1599910443464148
    # pose.pose.orientation.z = 0.6948646616894995
    # pose.pose.orientation.w = 0.7191405300323
    return pose

def get_start_pose(navigator):
    pose = PoseStamped()
    pose.header.frame_id = 'map'
    pose.header.stamp = navigator.get_clock().now().to_msg()
    pose.pose.position.x = -0.9451751252784691
    pose.pose.position.y = -0.51670155554402738
    pose.pose.orientation.z = -0.7425778437096872
    pose.pose.orientation.w = 0.669759767402814
    return pose

# MQTT Callbacks and helpers
def on_connect(client, userdata, flags, rc):
    if rc == 0:
        print("MQTT connected successfully")
        client.subscribe(TOPIC_COMMAND)
    else:
        print(f"Failed to connect to MQTT broker, return code {rc}")

def on_disconnect(client, userdata, rc):
    logging.info(f"Disconnected with result code: {rc}")
    reconnect_count, reconnect_delay = 0, FIRST_RECONNECT_DELAY
    while reconnect_count < MAX_RECONNECT_COUNT:
        logging.info(f"Reconnecting in {reconnect_delay} seconds...")
        time.sleep(reconnect_delay)
        try:
            client.reconnect()
            logging.info("Reconnected successfully!")
            return
        except Exception as err:
            logging.error(f"{err}. Reconnect failed. Retrying...")
        reconnect_delay *= RECONNECT_RATE
        reconnect_delay = min(reconnect_delay, MAX_RECONNECT_DELAY)
        reconnect_count += 1

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
            manual_override_active = False
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

# MQTT Loop in background thread with reconnect logic
def mqtt_loop():
    global mqtt_client_instance
    client = mqtt_client.Client(CLIENT_ID)
    client.username_pw_set(USERNAME, PASSWORD)
    client.tls_set(ca_certs=CA_CERTS)
    client.on_connect = on_connect
    client.on_disconnect = on_disconnect
    client.on_message = on_message

    try:
        client.connect(BROKER, PORT)
    except Exception as e:
        logging.error(f"Could not connect to MQTT broker: {e}")
        return

    mqtt_client_instance = client  # save globally to publish status

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
    global current_command, mqtt_client_instance

    logging.basicConfig(level=logging.INFO)

    # Start MQTT listener thread
    threading.Thread(target=mqtt_loop, daemon=True).start()

    # ROS setup
    rclpy.init()
    navigator = BasicNavigator()
    navigator.waitUntilNav2Active()

    # Set initial pose to home
    initial_pose = get_home_pose(navigator)
    navigator.setInitialPose(initial_pose)

    # Wait until the mqtt_loop sets mqtt_client_instance
    while mqtt_client_instance is None:
        time.sleep(0.1)

    try:
        command_loop(navigator, mqtt_client_instance)
    except KeyboardInterrupt:
        print("Shutting down...")
    finally:
        if mqtt_client_instance:
            mqtt_client_instance.loop_stop()
            mqtt_client_instance.disconnect()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
