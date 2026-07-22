#!/usr/bin/env bash
set -eo pipefail
ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
NEOBOTIX_WS="${NEOBOTIX_WS:-$HOME/ros2_workspace}"
PROJECT_WS="$ROOT/ros2_ws"
ROS_DISTRO="${ROS_DISTRO:-jazzy}"
export AMENT_TRACE_SETUP_FILES="${AMENT_TRACE_SETUP_FILES:-}"

source "/opt/ros/$ROS_DISTRO/setup.bash"
if [[ -f "$NEOBOTIX_WS/install/setup.bash" ]]; then
  source "$NEOBOTIX_WS/install/setup.bash"
else
  echo "Neobotix underlay not found at $NEOBOTIX_WS/install/setup.bash" >&2
  exit 2
fi
if [[ -f "$PROJECT_WS/install/setup.bash" ]]; then
  source "$PROJECT_WS/install/setup.bash"
else
  echo "Project overlay is not built: $PROJECT_WS/install/setup.bash" >&2
  exit 2
fi

exec ros2 launch rox_vda5050_adapter rox_vda5050_adapter.launch.py \
  mqtt_host:="${VDA_MQTT_HOST:-192.168.50.115}" \
  map_id:="${VDA_MAP_ID:-df_map}" \
  dry_run_navigation:=true
