#!/usr/bin/env bash
set -eo pipefail

PROJECT_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
ROS_DISTRO="${ROS_DISTRO:-jazzy}"
NEOBOTIX_WS="${NEOBOTIX_WS:-$HOME/ros2_workspace}"
WAYPOINT_FILE="${1:-$PROJECT_ROOT/configs/rox_waypoints.yaml}"

# Avoid ROS-generated setup scripts failing under nounset.
export AMENT_TRACE_SETUP_FILES="${AMENT_TRACE_SETUP_FILES:-}"

source "/opt/ros/$ROS_DISTRO/setup.bash"
source "$NEOBOTIX_WS/install/setup.bash"
source "$PROJECT_ROOT/ros2_ws/install/setup.bash"

exec ros2 launch rox_vda5050_adapter waypoint_visualizer.launch.py \
  waypoint_file:="$WAYPOINT_FILE" \
  frame_id:=map
