#!/usr/bin/env bash
# Single command entry point for common ROX-Diff commissioning operations.
set -eo pipefail

PROJECT_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
export VDA5050_PROJECT="${VDA5050_PROJECT:-$PROJECT_ROOT}"
export ROS_DISTRO="${ROS_DISTRO:-jazzy}"
export NEOBOTIX_WS="${NEOBOTIX_WS:-$HOME/ros2_workspace}"
export RMW_IMPLEMENTATION="${RMW_IMPLEMENTATION:-rmw_cyclonedds_cpp}"
export ROS_DOMAIN_ID="${ROS_DOMAIN_ID:-0}"
export AMENT_TRACE_SETUP_FILES="${AMENT_TRACE_SETUP_FILES:-}"

source_ros() {
  if [[ ! -f "/opt/ros/$ROS_DISTRO/setup.bash" ]]; then
    echo "ERROR: /opt/ros/$ROS_DISTRO/setup.bash not found" >&2
    exit 2
  fi
  if [[ ! -f "$NEOBOTIX_WS/install/setup.bash" ]]; then
    echo "ERROR: $NEOBOTIX_WS/install/setup.bash not found" >&2
    exit 2
  fi
  # Keep nounset disabled while ROS-generated setup files are sourced.
  source "/opt/ros/$ROS_DISTRO/setup.bash"
  source "$NEOBOTIX_WS/install/setup.bash"
  if [[ -f "$PROJECT_ROOT/ros2_ws/install/setup.bash" ]]; then
    source "$PROJECT_ROOT/ros2_ws/install/setup.bash"
  fi
}

waypoint_file="${ROX_WAYPOINT_FILE:-$PROJECT_ROOT/configs/rox_waypoints.yaml}"
map_id="${VDA_MAP_ID:-df_map}"

resolve_map_yaml() {
  if [[ -n "${ROX_MAP_YAML:-}" ]]; then
    printf '%s\n' "$ROX_MAP_YAML"
    return
  fi
  if [[ -f "$HOME/maps/df_map.yaml" ]]; then
    printf '%s\n' "$HOME/maps/df_map.yaml"
    return
  fi
  local prefix
  prefix="$(ros2 pkg prefix rox_navigation 2>/dev/null || true)"
  if [[ -n "$prefix" ]]; then
    printf '%s\n' "$prefix/share/rox_navigation/maps/df_map.yaml"
  else
    printf '%s\n' \
      "$NEOBOTIX_WS/install/rox_navigation/share/rox_navigation/maps/df_map.yaml"
  fi
}

usage() {
  cat <<EOF
Usage: ./scripts/rox.sh COMMAND [ARGUMENTS]

Daily commands:
  build                   Build the project ROS overlay
  nav [MAP_YAML]          Start Nav2/AMCL/RViz using df_map.yaml
  interfaces              Check ROX topics, messages, TF and Nav2 action
  visualize [YAML]        Publish YAML waypoints as RViz MarkerArray markers
  list [YAML]             List exact waypoint poses and tolerances
  goto NAME [YAML]        Send the exact named waypoint to Nav2 and verify TF
  goto-dry NAME [YAML]    Print/validate the exact goal without moving
  capture NAME [YAML]     Capture current map->base_link pose into YAML
  tf                      Echo map->base_link continuously
  status                  Show relevant topics, actions and configured files
  adapter-dry             Start the VDA adapter without real Nav2 movement
  adapter-real            Start the VDA adapter with real Nav2 movement
  env                     Print resolved environment and paths
  help                    Show this help

Environment overrides:
  ROS_DISTRO, NEOBOTIX_WS, RMW_IMPLEMENTATION, ROS_DOMAIN_ID
  ROX_MAP_YAML, ROX_WAYPOINT_FILE, VDA_MAP_ID

The native rox_bringup is already started at robot boot by ROS_AUTOSTART.sh.
Do not start a second bringup instance.
EOF
}

command="${1:-help}"
shift || true

case "$command" in
  help|-h|--help)
    usage
    ;;
  env)
    source_ros
    map_yaml="$(resolve_map_yaml)"
    cat <<EOF
PROJECT_ROOT=$PROJECT_ROOT
ROS_DISTRO=$ROS_DISTRO
NEOBOTIX_WS=$NEOBOTIX_WS
RMW_IMPLEMENTATION=$RMW_IMPLEMENTATION
ROS_DOMAIN_ID=$ROS_DOMAIN_ID
ROX_MAP_YAML=$map_yaml
ROX_WAYPOINT_FILE=$waypoint_file
VDA_MAP_ID=$map_id
EOF
    ;;
  build)
    cd "$PROJECT_ROOT"
    exec "$PROJECT_ROOT/scripts/build_rox_overlay.sh"
    ;;
  nav)
    source_ros
    map_yaml="${1:-$(resolve_map_yaml)}"
    [[ -f "$map_yaml" ]] || {
      echo "ERROR: map YAML not found: $map_yaml" >&2
      exit 2
    }
    exec ros2 launch rox_navigation navigation.launch.py \
      rox_type:=diff \
      use_rviz:=True \
      map:="$map_yaml"
    ;;
  interfaces)
    source_ros
    cd "$PROJECT_ROOT"
    exec "$PROJECT_ROOT/scripts/check_rox_ros_interfaces.sh"
    ;;
  visualize|waypoints)
    source_ros
    file="${1:-$waypoint_file}"
    exec ros2 launch rox_vda5050_adapter waypoint_visualizer.launch.py \
      waypoint_file:="$file" \
      frame_id:=map
    ;;
  list)
    source_ros
    file="${1:-$waypoint_file}"
    exec ros2 run rox_vda5050_adapter goto_waypoint \
      --list --waypoint-file "$file"
    ;;
  goto|goto-dry)
    name="${1:-}"
    [[ -n "$name" ]] || {
      echo "ERROR: waypoint name required" >&2
      usage
      exit 2
    }
    shift
    file="${1:-$waypoint_file}"
    source_ros
    extra=()
    [[ "$command" == "goto-dry" ]] && extra+=(--dry-run)
    exec ros2 run rox_vda5050_adapter goto_waypoint \
      --name "$name" \
      --waypoint-file "$file" \
      --expected-map-id "$map_id" \
      "${extra[@]}"
    ;;
  capture)
    name="${1:-}"
    [[ -n "$name" ]] || {
      echo "ERROR: waypoint name required" >&2
      usage
      exit 2
    }
    shift
    file="${1:-$waypoint_file}"
    source_ros
    exec ros2 run rox_vda5050_adapter capture_waypoint \
      --name "$name" \
      --output "$file" \
      --map-id "$map_id"
    ;;
  tf)
    source_ros
    exec ros2 run tf2_ros tf2_echo map base_link
    ;;
  status)
    source_ros
    map_yaml="$(resolve_map_yaml)"
    echo "== Environment =="
    echo "ROS_DISTRO=$ROS_DISTRO"
    echo "RMW_IMPLEMENTATION=$RMW_IMPLEMENTATION"
    echo "ROS_DOMAIN_ID=$ROS_DOMAIN_ID"
    echo "map=$map_yaml"
    echo "waypoints=$waypoint_file"
    echo
    echo "== Core topics =="
    ros2 topic list -t | grep -E '^/(tf|tf_static|odom|scan|battery_state|emergency_stop_state|safety_state)' || true
    echo
    echo "== Navigation action =="
    ros2 action list -t | grep navigate_to_pose || true
    echo
    echo "== Waypoint tools =="
    ros2 pkg executables rox_vda5050_adapter | grep -E 'capture_waypoint|goto_waypoint|waypoint_visualizer' || true
    ;;
  adapter-dry)
    cd "$PROJECT_ROOT"
    exec "$PROJECT_ROOT/scripts/run_rox_adapter_dry.sh"
    ;;
  adapter-real)
    cd "$PROJECT_ROOT"
    exec "$PROJECT_ROOT/scripts/run_rox_adapter_real.sh"
    ;;
  *)
    echo "ERROR: unknown command '$command'" >&2
    usage
    exit 2
    ;;
esac
