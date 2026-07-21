#!/usr/bin/env bash
set -eo pipefail
ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
NEOBOTIX_WS="${NEOBOTIX_WS:-$HOME/ros2_workspace}"
PROJECT_WS="$ROOT/ros2_ws"
ROS_DISTRO="${ROS_DISTRO:-jazzy}"
source "/opt/ros/$ROS_DISTRO/setup.bash"
source "$NEOBOTIX_WS/install/setup.bash"
source "$PROJECT_WS/install/setup.bash"

set -u

exec ros2 launch rox_vda5050_adapter rox_vda5050_adapter.launch.py \
  mqtt_host:="${VDA_MQTT_HOST:-192.168.50.115}" \
  map_id:="${VDA_MAP_ID:-warehouse_case_study}" \
  dry_run_navigation:=false
