#!/usr/bin/env bash
set -u

printf '\n== ROS distribution / middleware ==\n'
echo "ROS_DISTRO=${ROS_DISTRO:-<not sourced>}"
echo "RMW_IMPLEMENTATION=${RMW_IMPLEMENTATION:-<default>}"
echo "ROS_DOMAIN_ID=${ROS_DOMAIN_ID:-0}"

printf '\n== Required Nav2 action ==\n'
ros2 action list -t | grep -E '(^| )/navigate_to_pose ' || true

printf '\n== Required TF and odometry topics ==\n'
for topic in /tf /tf_static /odom /battery_state /emergency_stop_state /safety_state /scan; do
  printf '%-28s ' "$topic"
  ros2 topic type "$topic" 2>/dev/null || echo '<not found>'
done

printf '\n== Neobotix safety message definitions ==\n'
for type in neo_msgs2/msg/EmergencyStopState neo_msgs2/msg/SafetyState; do
  echo "--- $type"
  ros2 interface show "$type" 2>/dev/null || echo '<not installed>'
done

printf '\n== One map->base_link transform sample ==\n'
timeout 5 ros2 run tf2_ros tf2_echo map base_link 2>/dev/null | head -30 || true

printf '\nReview any <not found> entries before launching the VDA adapter.\n'
