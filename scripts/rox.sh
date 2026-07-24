#!/usr/bin/env bash
# Role-aware single command entry point for ROX-Diff robot and operator computers.
set -eo pipefail

SCRIPT_PATH="$(readlink -f "${BASH_SOURCE[0]}")"
PROJECT_ROOT="$(cd "$(dirname "$SCRIPT_PATH")/.." && pwd)"
CONFIG_FILE="${ROX_CONFIG_FILE:-$HOME/.config/rox/rox.env}"
if [[ -f "$CONFIG_FILE" ]]; then
  # shellcheck disable=SC1090
  source "$CONFIG_FILE"
fi

export VDA5050_PROJECT="${VDA5050_PROJECT:-$PROJECT_ROOT}"
export ROS_DISTRO="${ROS_DISTRO:-jazzy}"
export RMW_IMPLEMENTATION="${RMW_IMPLEMENTATION:-rmw_cyclonedds_cpp}"
export ROS_DOMAIN_ID="${ROS_DOMAIN_ID:-169}"
export ROS_AUTOMATIC_DISCOVERY_RANGE="${ROS_AUTOMATIC_DISCOVERY_RANGE:-SUBNET}"
export AMENT_TRACE_SETUP_FILES="${AMENT_TRACE_SETUP_FILES:-}"
export ROX_ROBOT_IP="${ROX_ROBOT_IP:-192.168.50.50}"
export ROX_ROBOT_USER="${ROX_ROBOT_USER:-neobotix}"
export ROX_REMOTE_PROJECT="${ROX_REMOTE_PROJECT:-/home/neobotix/Projects/VDA5050-Paper-Dev}"
export ROX_NAV_START_TIMEOUT="${ROX_NAV_START_TIMEOUT:-60}"
unset ROS_LOCALHOST_ONLY

find_neobotix_ws() {
  if [[ -n "${NEOBOTIX_WS:-}" && -f "$NEOBOTIX_WS/install/setup.bash" ]]; then
    printf '%s\n' "$NEOBOTIX_WS"
    return
  fi
  local candidate
  for candidate in \
    "$HOME/ros2_workspace" \
    "$HOME/neobotix_view_ws" \
    "$HOME/rox_ws" \
    "$HOME/neobotix_ws"; do
    [[ -f "$candidate/install/setup.bash" ]] && { printf '%s\n' "$candidate"; return; }
  done
  printf '%s\n' "${NEOBOTIX_WS:-$HOME/ros2_workspace}"
}
export NEOBOTIX_WS="$(find_neobotix_ws)"

detect_role() {
  case "${ROX_ROLE:-auto}" in
    robot|operator) printf '%s\n' "$ROX_ROLE" ;;
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
      echo "ERROR: ROX_ROLE must be robot, operator or auto; got '$ROX_ROLE'" >&2
      exit 2
      ;;
  esac
}
ROLE="$(detect_role)"
if [[ "$ROLE" == "operator" ]]; then
  export ROS_STATIC_PEERS="${ROS_STATIC_PEERS:-$ROX_ROBOT_IP}"
fi

source_ros() {
  if [[ ! -f "/opt/ros/$ROS_DISTRO/setup.bash" ]]; then
    echo "ERROR: /opt/ros/$ROS_DISTRO/setup.bash not found" >&2
    exit 2
  fi
  if [[ ! -f "$NEOBOTIX_WS/install/setup.bash" ]]; then
    echo "ERROR: Neobotix workspace setup not found:" >&2
    echo "  $NEOBOTIX_WS/install/setup.bash" >&2
    echo "Run scripts/install_rox_shell.sh with the correct --neobotix-ws path." >&2
    exit 2
  fi
  # Keep nounset disabled while ROS-generated setup files are sourced.
  # shellcheck disable=SC1090
  source "/opt/ros/$ROS_DISTRO/setup.bash"
  # shellcheck disable=SC1090
  source "$NEOBOTIX_WS/install/setup.bash"
  if [[ -f "$PROJECT_ROOT/ros2_ws/install/setup.bash" ]]; then
    # shellcheck disable=SC1090
    source "$PROJECT_ROOT/ros2_ws/install/setup.bash"
  fi
}

waypoint_file="${ROX_WAYPOINT_FILE:-$PROJECT_ROOT/configs/rox_waypoints.yaml}"
pose_file="${ROX_LAST_POSE_FILE:-$PROJECT_ROOT/runtime/rox_last_pose.yaml}"
map_id="${VDA_MAP_ID:-df_map}"
auto_restore="${ROX_AUTO_RESTORE:-true}"
max_pose_age_hours="${ROX_MAX_POSE_AGE_HOURS:-0.0}"
marker_topic="${ROX_WAYPOINT_MARKER_TOPIC:-/waypoints}"
nav_pid_file="$PROJECT_ROOT/runtime/rox_nav.pid"
nav_log_file="$PROJECT_ROOT/runtime/rox_nav.log"
ssh_target="$ROX_ROBOT_USER@$ROX_ROBOT_IP"
ssh_options=(-o BatchMode=yes -o ConnectTimeout=8 -o ServerAliveInterval=15)

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
    printf '%s\n' "$NEOBOTIX_WS/install/rox_navigation/share/rox_navigation/maps/df_map.yaml"
  fi
}

require_role() {
  local expected="$1"
  [[ "$ROLE" == "$expected" ]] || {
    echo "ERROR: this command must run with ROX_ROLE=$expected; current role is $ROLE" >&2
    exit 2
  }
}

quote_remote_command() {
  local quoted="" arg
  for arg in "$@"; do
    printf -v quoted '%s %q' "$quoted" "$arg"
  done
  printf 'cd %q && exec ./scripts/rox.sh%s' "$ROX_REMOTE_PROJECT" "$quoted"
}

remote_rox() {
  local remote_command
  remote_command="$(quote_remote_command "$@")"
  ssh "${ssh_options[@]}" "$ssh_target" "$remote_command"
}

remote_rox_interactive() {
  local remote_command
  remote_command="$(quote_remote_command "$@")"
  exec ssh -t "${ssh_options[@]}" "$ssh_target" "$remote_command"
}

nav_action_available() {
  ros2 action list 2>/dev/null | grep -Fxq '/navigate_to_pose'
}

managed_nav_running() {
  [[ -f "$nav_pid_file" ]] || return 1
  local pid
  pid="$(cat "$nav_pid_file" 2>/dev/null || true)"
  [[ "$pid" =~ ^[0-9]+$ ]] && kill -0 "$pid" 2>/dev/null
}

run_navigation_foreground() {
  local use_rviz="$1"
  local restore_value="$2"
  local show_waypoints="$3"
  local map_yaml="${4:-$(resolve_map_yaml)}"
  [[ -f "$map_yaml" ]] || {
    echo "ERROR: map YAML not found: $map_yaml" >&2
    exit 2
  }
  mkdir -p "$(dirname "$pose_file")"
  exec ros2 launch rox_vda5050_adapter \
    navigation_with_pose_persistence.launch.py \
    rox_type:=diff \
    use_rviz:="$use_rviz" \
    map:="$map_yaml" \
    pose_file:="$pose_file" \
    map_id:="$map_id" \
    auto_restore:="$restore_value" \
    max_age_hours:="$max_pose_age_hours" \
    show_waypoints:="$show_waypoints" \
    waypoint_file:="$waypoint_file" \
    marker_topic:="$marker_topic"
}

start_managed_nav() {
  local fresh="${1:-false}"
  require_role robot
  source_ros
  mkdir -p "$PROJECT_ROOT/runtime"

  if managed_nav_running; then
    echo "Nav2 is already running under the ROX command manager (PID $(cat "$nav_pid_file"))."
    return 0
  fi
  rm -f "$nav_pid_file"

  if nav_action_available; then
    echo "Nav2 is already active, but it was not started by the ROX command manager."
    if [[ "$fresh" == "true" ]]; then
      echo "ERROR: fresh localization requires stopping that external Nav2 instance first." >&2
      return 3
    fi
    echo "Not starting a duplicate navigation stack."
    return 0
  fi

  local subcommand="nav-headless"
  if [[ "$fresh" == "true" ]]; then
    subcommand="nav-headless-fresh"
  fi

  nohup setsid "$SCRIPT_PATH" "$subcommand" \
    >"$nav_log_file" 2>&1 < /dev/null &
  local pid=$!
  printf '%s\n' "$pid" > "$nav_pid_file"
  sleep 3

  if ! kill -0 "$pid" 2>/dev/null; then
    echo "ERROR: Nav2 exited during startup. Last log lines:" >&2
    tail -n 80 "$nav_log_file" >&2 || true
    rm -f "$nav_pid_file"
    return 1
  fi

  echo "Started headless Nav2 on the ROX-Diff."
  echo "  PID: $pid"
  echo "  log: $nav_log_file"
}

stop_managed_nav() {
  require_role robot
  source_ros
  if ! managed_nav_running; then
    rm -f "$nav_pid_file"
    if nav_action_available; then
      echo "Nav2 is active but was not started by 'rox nav-start'."
      echo "Stop the terminal or service that launched it; refusing to kill an unknown process."
      return 3
    fi
    echo "Managed Nav2 is not running."
    return 0
  fi

  local pid
  pid="$(cat "$nav_pid_file")"
  echo "Stopping managed Nav2 process group $pid ..."
  kill -INT -- "-$pid" 2>/dev/null || kill -INT "$pid" 2>/dev/null || true

  local _
  for _ in {1..20}; do
    kill -0 "$pid" 2>/dev/null || break
    sleep 1
  done
  if kill -0 "$pid" 2>/dev/null; then
    kill -TERM -- "-$pid" 2>/dev/null || kill -TERM "$pid" 2>/dev/null || true
    sleep 2
  fi
  if kill -0 "$pid" 2>/dev/null; then
    echo "WARNING: forcing Nav2 process group to stop" >&2
    kill -KILL -- "-$pid" 2>/dev/null || kill -KILL "$pid" 2>/dev/null || true
  fi
  rm -f "$nav_pid_file"
  echo "Managed Nav2 stopped. The pose-persistence node was given time to save the last pose."
}

wait_for_navigation() {
  local timeout="$ROX_NAV_START_TIMEOUT"
  local elapsed=0
  printf 'Waiting for /navigate_to_pose'
  while (( elapsed < timeout )); do
    if nav_action_available; then
      printf ' ready.\n'
      return 0
    fi
    printf '.'
    sleep 1
    ((elapsed += 1))
  done
  printf '\n' >&2
  echo "ERROR: /navigate_to_pose was not discovered after ${timeout}s." >&2
  echo "Run 'rox doctor' and 'rox nav-log' for diagnostics." >&2
  return 1
}

ensure_remote_nav() {
  local fresh="${1:-false}"
  require_role operator
  source_ros

  if [[ "$fresh" != "true" ]] && nav_action_available; then
    echo "Robot Nav2 is already active; connecting local RViz."
    return 0
  fi

  if ! ssh "${ssh_options[@]}" "$ssh_target" true; then
    echo "ERROR: password-free SSH to $ssh_target is not ready." >&2
    echo "Run once: ssh-copy-id $ssh_target" >&2
    return 2
  fi

  if [[ "$fresh" == "true" ]]; then
    remote_rox nav-start-fresh
  else
    remote_rox nav-start
  fi
  wait_for_navigation
}

launch_local_rviz() {
  source_ros
  [[ -f "$waypoint_file" ]] || {
    echo "ERROR: waypoint YAML not found: $waypoint_file" >&2
    exit 2
  }
  exec ros2 launch rox_vda5050_adapter operator_rviz.launch.py \
    waypoint_file:="$waypoint_file" \
    frame_id:=map \
    marker_topic:="$marker_topic"
}

usage() {
  cat <<EOF2
Usage: rox COMMAND [ARGUMENTS]
       ./scripts/rox.sh COMMAND [ARGUMENTS]

Commands available on both robot and operator laptop:
  build                   Build this computer's project ROS overlay
  doctor                  Validate ROS, ROX packages, network, SSH and topics
  nav                     Robot: start Nav2+RViz. Operator: start remote Nav2
                          when needed, then open local RViz with model+waypoints
  nav-fresh               Clear saved pose, start remote/local Nav2, open RViz
  rviz                    Open local Neobotix Nav2 RViz+waypoints only
  nav-start               Start managed headless Nav2 (remote when operator)
  nav-start-fresh         Restart managed headless Nav2 without pose restore
  nav-stop                Stop managed headless Nav2 (remote when operator)
  nav-status              Show managed Nav2 status
  nav-log [N|-f]          Show last N Nav2 log lines, or follow with -f
  interfaces              Check ROX topics, messages, TF and Nav2 action
  visualize [YAML]        Publish YAML waypoint markers on $marker_topic
  list [YAML]             List exact waypoint poses and tolerances
  goto NAME [YAML]        Send exact named waypoint to Nav2 and verify final TF
  goto-dry NAME [YAML]    Validate/print exact goal without moving
  capture NAME [YAML]     Capture current map->base_link pose into local YAML
  pose-save               Save current pose on robot immediately
  pose-restore            Publish robot's saved pose to AMCL
  pose-status             Inspect robot's saved pose
  pose-clear              Delete robot's saved pose
  tf                      Echo map->base_link continuously
  status                  Show environment, topics, tools and navigation state
  adapter-dry             Start adapter dry-run (remote when operator)
  adapter-real            Start real adapter (remote when operator)
  env                     Print resolved role, environment and paths
  help                    Show this help

One-time shell setup:
  Operator: ./scripts/install_rox_shell.sh operator --neobotix-ws ~/neobotix_view_ws
  Robot:    ./scripts/install_rox_shell.sh robot --neobotix-ws ~/ros2_workspace

Important:
  - Hardware bringup and Nav2 execute only on the ROX-Diff.
  - The operator laptop runs RViz and command clients over ROS 2 DDS.
  - 'rox nav' will not start a duplicate Nav2 stack.
  - Use only one active operator for motion commands at a time.
EOF2
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
    cat <<EOF2
ROX_EFFECTIVE_ROLE=$ROLE
PROJECT_ROOT=$PROJECT_ROOT
ROS_DISTRO=$ROS_DISTRO
NEOBOTIX_WS=$NEOBOTIX_WS
RMW_IMPLEMENTATION=$RMW_IMPLEMENTATION
ROS_DOMAIN_ID=$ROS_DOMAIN_ID
ROS_AUTOMATIC_DISCOVERY_RANGE=$ROS_AUTOMATIC_DISCOVERY_RANGE
ROS_STATIC_PEERS=${ROS_STATIC_PEERS:-unset}
ROX_ROBOT_IP=$ROX_ROBOT_IP
ROX_ROBOT_USER=$ROX_ROBOT_USER
ROX_REMOTE_PROJECT=$ROX_REMOTE_PROJECT
ROX_MAP_YAML=$map_yaml
ROX_WAYPOINT_FILE=$waypoint_file
ROX_WAYPOINT_MARKER_TOPIC=$marker_topic
ROX_LAST_POSE_FILE=$pose_file
VDA_MAP_ID=$map_id
EOF2
    ;;
  build)
    cd "$PROJECT_ROOT"
    exec "$PROJECT_ROOT/scripts/build_rox_overlay.sh"
    ;;
  doctor)
    source_ros
    failures=0
    echo "== Role and middleware =="
    echo "role=$ROLE"
    echo "RMW_IMPLEMENTATION=$RMW_IMPLEMENTATION"
    echo "ROS_DOMAIN_ID=$ROS_DOMAIN_ID"
    echo "ROS_STATIC_PEERS=${ROS_STATIC_PEERS:-unset}"
    echo "NEOBOTIX_WS=$NEOBOTIX_WS"
    echo
    echo "== Required local packages =="
    for pkg in rox_description rox_navigation rox_vda5050_adapter; do
      if prefix="$(ros2 pkg prefix "$pkg" 2>/dev/null)"; then
        echo "PASS $pkg -> $prefix"
      else
        echo "FAIL $pkg not found"
        failures=$((failures + 1))
      fi
    done
    if [[ "$ROLE" == "operator" ]]; then
      echo
      echo "== Robot connectivity =="
      if ping -c 1 -W 2 "$ROX_ROBOT_IP" >/dev/null 2>&1; then
        echo "PASS ping $ROX_ROBOT_IP"
      else
        echo "FAIL ping $ROX_ROBOT_IP"
        failures=$((failures + 1))
      fi
      if ssh "${ssh_options[@]}" "$ssh_target" true >/dev/null 2>&1; then
        echo "PASS password-free SSH $ssh_target"
      else
        echo "FAIL password-free SSH $ssh_target"
        echo "     run: ssh-copy-id $ssh_target"
        failures=$((failures + 1))
      fi
    fi
    echo
    echo "== ROS graph =="
    for topic in /tf /robot_description /scan; do
      if ros2 topic list 2>/dev/null | grep -Fxq "$topic"; then
        echo "PASS topic $topic"
      else
        echo "WARN topic $topic not currently visible"
      fi
    done
    if nav_action_available; then
      echo "PASS action /navigate_to_pose"
    else
      echo "INFO /navigate_to_pose is not active; 'rox nav' can start it"
    fi
    echo
    if (( failures == 0 )); then
      echo "ROX doctor: PASS"
    else
      echo "ROX doctor: $failures required check(s) failed" >&2
      exit 1
    fi
    ;;
  nav)
    if [[ "$ROLE" == "operator" ]]; then
      ensure_remote_nav false
      launch_local_rviz
    else
      source_ros
      run_navigation_foreground True "$auto_restore" true "${1:-}"
    fi
    ;;
  nav-fresh)
    if [[ "$ROLE" == "operator" ]]; then
      ensure_remote_nav true
      launch_local_rviz
    else
      source_ros
      rm -f "$pose_file"
      echo "Cleared saved pose for fresh manual localization: $pose_file"
      run_navigation_foreground True false true "${1:-}"
    fi
    ;;
  nav-headless|nav-headless-fresh)
    require_role robot
    source_ros
    restore="$auto_restore"
    if [[ "$command" == "nav-headless-fresh" ]]; then
      restore=false
      rm -f "$pose_file"
      echo "Cleared saved pose for fresh manual localization: $pose_file"
    fi
    run_navigation_foreground False "$restore" false "${1:-}"
    ;;
  nav-start|nav-start-fresh)
    if [[ "$ROLE" == "operator" ]]; then
      if [[ "$command" == "nav-start-fresh" ]]; then
        remote_rox nav-start-fresh
      else
        remote_rox nav-start
      fi
    else
      if [[ "$command" == "nav-start-fresh" ]]; then
        if managed_nav_running; then stop_managed_nav; fi
        start_managed_nav true
      else
        start_managed_nav false
      fi
    fi
    ;;
  nav-stop)
    if [[ "$ROLE" == "operator" ]]; then remote_rox nav-stop; else stop_managed_nav; fi
    ;;
  nav-status)
    if [[ "$ROLE" == "operator" ]]; then
      remote_rox nav-status
    else
      source_ros
      if managed_nav_running; then
        echo "managed_nav=running"
        echo "pid=$(cat "$nav_pid_file")"
      else
        echo "managed_nav=stopped"
      fi
      if nav_action_available; then echo "navigate_to_pose=available"; else echo "navigate_to_pose=absent"; fi
      echo "log=$nav_log_file"
    fi
    ;;
  nav-log)
    if [[ "$ROLE" == "operator" ]]; then
      if [[ "${1:-}" == "-f" ]]; then remote_rox_interactive nav-log -f; else remote_rox nav-log "${1:-100}"; fi
    else
      if [[ "${1:-}" == "-f" ]]; then exec tail -f "$nav_log_file"; else tail -n "${1:-100}" "$nav_log_file"; fi
    fi
    ;;
  rviz)
    launch_local_rviz
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
      waypoint_file:="$file" frame_id:=map marker_topic:="$marker_topic"
    ;;
  list)
    source_ros
    file="${1:-$waypoint_file}"
    exec ros2 run rox_vda5050_adapter goto_waypoint --list --waypoint-file "$file"
    ;;
  goto|goto-dry)
    name="${1:-}"
    [[ -n "$name" ]] || { echo "ERROR: waypoint name required" >&2; usage; exit 2; }
    shift
    file="${1:-$waypoint_file}"
    source_ros
    extra=()
    [[ "$command" == "goto-dry" ]] && extra+=(--dry-run)
    exec ros2 run rox_vda5050_adapter goto_waypoint \
      --name "$name" --waypoint-file "$file" --expected-map-id "$map_id" "${extra[@]}"
    ;;
  capture)
    name="${1:-}"
    [[ -n "$name" ]] || { echo "ERROR: waypoint name required" >&2; usage; exit 2; }
    shift
    file="${1:-$waypoint_file}"
    source_ros
    exec ros2 run rox_vda5050_adapter capture_waypoint \
      --name "$name" --output "$file" --map-id "$map_id"
    ;;
  pose-save|pose-restore|pose-status|pose-clear)
    if [[ "$ROLE" == "operator" ]]; then
      remote_rox "$command" "$@"
      exit $?
    fi
    if [[ "$command" == "pose-clear" ]]; then
      if [[ -f "$pose_file" ]]; then rm -f "$pose_file"; echo "Deleted saved pose: $pose_file"; else echo "No saved pose exists: $pose_file"; fi
      exit 0
    fi
    source_ros
    map_yaml="$(resolve_map_yaml)"
    [[ -f "$map_yaml" ]] || { echo "ERROR: map YAML not found: $map_yaml" >&2; exit 2; }
    subcommand="${command#pose-}"
    extra_ros_args=()
    [[ "$command" == "pose-save" ]] && extra_ros_args+=(--ros-args -r __node:=rox_pose_save_once)
    [[ "$command" == "pose-restore" ]] && extra_ros_args+=(--ros-args -r __node:=rox_pose_restore_once)
    exec ros2 run rox_vda5050_adapter pose_persistence "$subcommand" \
      --pose-file "$pose_file" --map-id "$map_id" --map-yaml "$map_yaml" "${extra_ros_args[@]}"
    ;;
  tf)
    source_ros
    exec ros2 run tf2_ros tf2_echo map base_link
    ;;
  status)
    source_ros
    echo "== Environment =="
    echo "role=$ROLE"
    echo "RMW_IMPLEMENTATION=$RMW_IMPLEMENTATION"
    echo "ROS_DOMAIN_ID=$ROS_DOMAIN_ID"
    echo "ROS_STATIC_PEERS=${ROS_STATIC_PEERS:-unset}"
    echo "NEOBOTIX_WS=$NEOBOTIX_WS"
    echo "waypoints=$waypoint_file"
    echo
    echo "== Core topics =="
    ros2 topic list -t | grep -E '^/(tf|tf_static|odom|scan|robot_description|battery_state|emergency_stop_state|safety_state|initialpose|map)' || true
    echo
    echo "== Navigation action =="
    ros2 action list -t | grep navigate_to_pose || true
    echo
    echo "== Local waypoint tools =="
    ros2 pkg executables rox_vda5050_adapter | grep -E 'capture_waypoint|goto_waypoint|waypoint_visualizer|pose_persistence' || true
    if [[ "$ROLE" == "operator" ]]; then
      echo
      echo "== Robot managed navigation =="
      remote_rox nav-status 2>/dev/null || echo "Robot SSH/status unavailable"
    fi
    ;;
  adapter-dry|adapter-real)
    if [[ "$ROLE" == "operator" ]]; then
      remote_rox_interactive "$command"
    elif [[ "$command" == "adapter-dry" ]]; then
      cd "$PROJECT_ROOT"; exec "$PROJECT_ROOT/scripts/run_rox_adapter_dry.sh"
    else
      cd "$PROJECT_ROOT"; exec "$PROJECT_ROOT/scripts/run_rox_adapter_real.sh"
    fi
    ;;
  *)
    echo "ERROR: unknown command '$command'" >&2
    usage
    exit 2
    ;;
esac
