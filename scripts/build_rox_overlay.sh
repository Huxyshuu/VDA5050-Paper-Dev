#!/usr/bin/env bash
set -eo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
NEOBOTIX_WS="${NEOBOTIX_WS:-$HOME/ros2_workspace}"
ROS_DISTRO="${ROS_DISTRO:-jazzy}"
export AMENT_TRACE_SETUP_FILES="${AMENT_TRACE_SETUP_FILES:-}"

if [[ ! -f "/opt/ros/$ROS_DISTRO/setup.bash" ]]; then
  echo "ROS setup not found: /opt/ros/$ROS_DISTRO/setup.bash" >&2
  exit 2
fi
if [[ ! -f "$NEOBOTIX_WS/install/setup.bash" ]]; then
  echo "Neobotix underlay not found: $NEOBOTIX_WS/install/setup.bash" >&2
  exit 2
fi

# ROS-generated setup files may read variables that are unset. Keep nounset
# disabled while sourcing them; strict unset checking is not needed here.
source "/opt/ros/$ROS_DISTRO/setup.bash"
source "$NEOBOTIX_WS/install/setup.bash"

cd "$ROOT/ros2_ws"
rosdep install --from-paths src --ignore-src -r -y
colcon build --symlink-install
printf '\nBuild complete. In every new shell run:\n  source %q\n' \
  "$ROOT/ros2_ws/install/setup.bash"
