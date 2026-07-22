#!/usr/bin/env bash
set -o pipefail

printf '\n== ROS distribution / middleware ==\n'
echo "ROS_DISTRO=${ROS_DISTRO:-<not set>}"
echo "RMW_IMPLEMENTATION=${RMW_IMPLEMENTATION:-<not set>}"
echo "ROS_DOMAIN_ID=${ROS_DOMAIN_ID:-0}"

printf '\n== Required Nav2 action ==\n'
action_line="$(ros2 action list -t 2>/dev/null | grep -E '^/navigate_to_pose([[:space:]]|$)' || true)"
if [[ -n "$action_line" ]]; then
  echo "$action_line"
else
  echo '<not found — expected before Nav2 starts; required after navigation starts>'
fi

printf '\n== Required TF and robot topics ==\n'
for topic in /tf /tf_static /odom /battery_state /emergency_stop_state /safety_state /scan; do
  type="$(ros2 topic type "$topic" 2>/dev/null || true)"
  printf '%-28s %s\n' "$topic" "${type:-<not found>}"
done

printf '\n== Neobotix safety message definitions ==\n'
for type in neo_msgs2/msg/EmergencyStopState neo_msgs2/msg/SafetyState; do
  echo "--- $type"
  ros2 interface show "$type" 2>/dev/null || echo '<not found>'
done

printf '\n== One map->base_link transform sample ==\n'
tf_sample="$(timeout 5 ros2 run tf2_ros tf2_echo map base_link 2>/dev/null | head -30 || true)"
if [[ -n "$tf_sample" ]]; then
  echo "$tf_sample"
else
  echo '<not found — expected before localization starts; required after AMCL/Nav2 starts>'
fi

printf '\nInterpretation:\n'
printf '%s\n' '- Native bringup should provide the hardware topics.'
printf '%s\n' '- /navigate_to_pose and map->base_link are stage-dependent and are required after Nav2/localization starts.'
printf '%s\n' '- Review every remaining <not found> entry before launching the real-motion VDA adapter.'
