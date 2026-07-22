#!/usr/bin/env bash
set -eo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
CONFIG_FILE="${ROX_CONFIG_FILE:-$HOME/.config/rox/rox.env}"
[[ -f "$CONFIG_FILE" ]] && source "$CONFIG_FILE"
ROS_DISTRO="${ROS_DISTRO:-jazzy}"
export AMENT_TRACE_SETUP_FILES="${AMENT_TRACE_SETUP_FILES:-}"

find_neobotix_ws() {
  if [[ -n "${NEOBOTIX_WS:-}" && -f "$NEOBOTIX_WS/install/setup.bash" ]]; then
    printf '%s\n' "$NEOBOTIX_WS"; return
  fi
  local candidate
  for candidate in "$HOME/ros2_workspace" "$HOME/neobotix_view_ws" "$HOME/rox_ws" "$HOME/neobotix_ws"; do
    [[ -f "$candidate/install/setup.bash" ]] && { printf '%s\n' "$candidate"; return; }
  done
  return 1
}
NEOBOTIX_WS="$(find_neobotix_ws)" || {
  echo "ERROR: no built Neobotix workspace was found." >&2
  echo "Run scripts/install_rox_shell.sh with --neobotix-ws PATH." >&2
  exit 2
}

[[ -f "/opt/ros/$ROS_DISTRO/setup.bash" ]] || { echo "ROS setup not found: /opt/ros/$ROS_DISTRO/setup.bash" >&2; exit 2; }
source "/opt/ros/$ROS_DISTRO/setup.bash"
source "$NEOBOTIX_WS/install/setup.bash"

cd "$ROOT/ros2_ws"
rosdep install --from-paths src --ignore-src -r -y
colcon build --symlink-install

printf '\nBuild complete: %s\n' "$ROOT/ros2_ws/install/setup.bash"
if grep -q 'VDA5050 ROX environment' "$HOME/.bashrc" 2>/dev/null; then
  echo "New terminals will source this overlay automatically."
else
  echo "Install automatic shell setup with:"
  echo "  $ROOT/scripts/install_rox_shell.sh operator --neobotix-ws $NEOBOTIX_WS"
fi
