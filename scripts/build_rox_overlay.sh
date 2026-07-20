#!/usr/bin/env bash
set -euo pipefail
ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
NEOBOTIX_WS="${NEOBOTIX_WS:-$HOME/ros2_workspace}"
ROS_DISTRO="${ROS_DISTRO:-jazzy}"

source "/opt/ros/$ROS_DISTRO/setup.bash"
if [[ ! -f "$NEOBOTIX_WS/install/setup.bash" ]]; then
  echo "Neobotix underlay not found: $NEOBOTIX_WS/install/setup.bash" >&2
  exit 2
fi
source "$NEOBOTIX_WS/install/setup.bash"
cd "$ROOT/ros2_ws"
rosdep install --from-paths src --ignore-src -r -y
colcon build --symlink-install
printf '\nBuild complete. In every new shell run:\n  source %q\n' "$ROOT/ros2_ws/install/setup.bash"
