#!/usr/bin/env bash
# Shared ROS 2 environment for ROX-Diff robot and operator workstations.
# This file is safe to source repeatedly from ~/.bashrc and from scripts.

_ROX_ENV_SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
_ROX_ENV_PROJECT_DEFAULT="$(cd "$_ROX_ENV_SCRIPT_DIR/.." && pwd)"
_ROX_CONFIG_FILE="${ROX_CONFIG_FILE:-$HOME/.config/rox/rox.env}"

if [[ -f "$_ROX_CONFIG_FILE" ]]; then
  # shellcheck disable=SC1090
  source "$_ROX_CONFIG_FILE"
fi

export VDA5050_PROJECT="${VDA5050_PROJECT:-$_ROX_ENV_PROJECT_DEFAULT}"
export ROS_DISTRO="${ROS_DISTRO:-jazzy}"
export RMW_IMPLEMENTATION="${RMW_IMPLEMENTATION:-rmw_cyclonedds_cpp}"
export ROS_DOMAIN_ID="${ROS_DOMAIN_ID:-169}"
export ROS_AUTOMATIC_DISCOVERY_RANGE="${ROS_AUTOMATIC_DISCOVERY_RANGE:-SUBNET}"
export AMENT_TRACE_SETUP_FILES="${AMENT_TRACE_SETUP_FILES:-}"
export ROX_ROBOT_IP="${ROX_ROBOT_IP:-192.168.50.50}"
export ROX_ROBOT_USER="${ROX_ROBOT_USER:-neobotix}"
export ROX_REMOTE_PROJECT="${ROX_REMOTE_PROJECT:-/home/neobotix/Projects/VDA5050-Paper-Dev}"

_rox_detect_role() {
  case "${ROX_ROLE:-auto}" in
    robot|operator)
      printf '%s\n' "$ROX_ROLE"
      ;;
    auto|"")
      if command -v ip >/dev/null 2>&1 \
          && ip -o -4 addr show 2>/dev/null \
            | awk '{print $4}' | cut -d/ -f1 \
            | grep -Fxq "$ROX_ROBOT_IP"; then
        printf 'robot\n'
      elif [[ "${USER:-}" == "neobotix" || "$(hostname 2>/dev/null || true)" == "uni-aalto" ]]; then
        printf 'robot\n'
      else
        printf 'operator\n'
      fi
      ;;
    *)
      printf 'ERROR: ROX_ROLE must be robot, operator or auto; got %s\n' "$ROX_ROLE" >&2
      return 2
      ;;
  esac
}

export ROX_EFFECTIVE_ROLE="$(_rox_detect_role)"

_rox_find_neobotix_ws() {
  if [[ -n "${NEOBOTIX_WS:-}" && -f "$NEOBOTIX_WS/install/setup.bash" ]]; then
    printf '%s\n' "$NEOBOTIX_WS"
    return
  fi

  local candidate
  if [[ "$ROX_EFFECTIVE_ROLE" == "robot" ]]; then
    for candidate in \
      "$HOME/ros2_workspace" \
      "$HOME/rox_ws" \
      "$HOME/neobotix_view_ws" \
      "$HOME/neobotix_ws"; do
      [[ -f "$candidate/install/setup.bash" ]] && { printf '%s\n' "$candidate"; return; }
    done
    printf '%s\n' "$HOME/ros2_workspace"
  else
    for candidate in \
      "$HOME/neobotix_view_ws" \
      "$HOME/rox_ws" \
      "$HOME/neobotix_ws" \
      "$HOME/ros2_workspace"; do
      [[ -f "$candidate/install/setup.bash" ]] && { printf '%s\n' "$candidate"; return; }
    done
    printf '%s\n' "$HOME/neobotix_view_ws"
  fi
}

export NEOBOTIX_WS="$(_rox_find_neobotix_ws)"

if [[ "$ROX_EFFECTIVE_ROLE" == "operator" ]]; then
  export ROS_STATIC_PEERS="${ROS_STATIC_PEERS:-$ROX_ROBOT_IP}"
fi
unset ROS_LOCALHOST_ONLY

# ROS-generated setup files may reference unset variables, so do not enable
# nounset while sourcing them.
if [[ -f "/opt/ros/$ROS_DISTRO/setup.bash" ]]; then
  # shellcheck disable=SC1090
  source "/opt/ros/$ROS_DISTRO/setup.bash"
fi
if [[ -f "$NEOBOTIX_WS/install/setup.bash" ]]; then
  # shellcheck disable=SC1090
  source "$NEOBOTIX_WS/install/setup.bash"
fi
if [[ -f "$VDA5050_PROJECT/ros2_ws/install/setup.bash" ]]; then
  # shellcheck disable=SC1090
  source "$VDA5050_PROJECT/ros2_ws/install/setup.bash"
fi

# Run the central command from any directory: `rox nav`, `rox goto home`, etc.
rox() {
  "$VDA5050_PROJECT/scripts/rox.sh" "$@"
}

roxcd() {
  cd "$VDA5050_PROJECT" || return
}

if [[ $- == *i* ]] && command -v complete >/dev/null 2>&1; then
  complete -W 'build doctor env nav nav-fresh nav-start nav-start-fresh nav-stop nav-status nav-log rviz interfaces visualize list goto goto-dry capture pose-save pose-restore pose-status pose-clear tf status adapter-dry adapter-real help' rox
fi

unset _ROX_ENV_SCRIPT_DIR _ROX_ENV_PROJECT_DEFAULT _ROX_CONFIG_FILE
