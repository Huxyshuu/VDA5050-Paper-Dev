# rox_vda5050_adapter

ROS 2 package replacing the legacy DBot/TurtleBot VDA connector chain. It communicates directly through official VDA 5050 v3.0 MQTT/JSON, translates order nodes to Nav2 `NavigateToPose`, and publishes robot state/connection feedback.

## Deployment

Build as a separate overlay after sourcing the Neobotix workspace:

```bash
cd ~/vda5050-v3-amr-crane-case-study/ros2_ws
source /opt/ros/$ROS_DISTRO/setup.bash
source ~/ros2_workspace/install/setup.bash
rosdep install --from-paths src --ignore-src -r -y
colcon build --symlink-install
source install/setup.bash
```

Do not replace `rox_bringup`, `rox_navigation`, robot drivers or `neo_msgs2`.

## Inputs

MQTT:

```text
vda5050/v3/neobotix/rox_diff_1/order
vda5050/v3/neobotix/rox_diff_1/instantActions
```

ROS:

```text
map -> base_link TF
/odom
/battery_state
/emergency_stop_state
/safety_state
/navigate_to_pose
/initialpose
```

Topic names and participant identity are configurable ROS parameters.

## Outputs

MQTT:

```text
.../state
.../connection
.../factsheet     when a verified factsheet file is configured
```

## Supported order actions

```text
holdPose
waitForTrigger
noop / noOp
```

Edge actions are rejected in the first migration version.

## Supported instant actions

```text
startPause
stopPause
cancelOrder
initializePosition
factsheetRequest
releaseHold             project-specific
trigger
retry
skipRetry
```

`retry`/`skipRetry` currently apply only to the current blocked node action in `RETRIABLE`.

## Order acceptance constraints

The first implementation accepts only new orders with `orderUpdateId: 0`. It requires:

- matching manufacturer, serial number and version;
- matching `mapId`;
- continuous sequence IDs;
- even node and odd edge sequence IDs;
- first node sequence `0` and released;
- one edge between each consecutive pair of nodes;
- no unsupported node or edge actions;
- localization near the first node during real navigation.

Dry-run mode intentionally assumes the first node is current.

## Safe commissioning

Dry-run is the default:

```bash
ros2 launch rox_vda5050_adapter rox_vda5050_adapter.launch.py \
  mqtt_host:=192.168.1.115 \
  map_id:=warehouse_case_study \
  dry_run_navigation:=true
```

Set `dry_run_navigation:=false` only after native Nav2 and MQTT state/order flow are verified.

## Battery and safety mapping

The adapter discovers the actual ROS message types at runtime instead of hard-coding a specific delivered `neo_msgs2` release. Verify the installed fields with:

```bash
ros2 topic type /battery_state
ros2 topic type /emergency_stop_state
ros2 topic type /safety_state
ros2 interface show neo_msgs2/msg/EmergencyStopState
ros2 interface show neo_msgs2/msg/SafetyState
```

VDA safety state is reporting only. It is not a safety-control path.

## Factsheet

The included factsheet is a template. Physical dimensions, accelerations, battery details, load capacity and capabilities must be checked against the delivered ROX-Diff before setting the `factsheet_file` parameter.

## Deferred features

- order update/base-horizon merging;
- edge actions;
- `zoneSet`/`responses`/zone requests;
- planned/intermediate path reporting;
- visualization;
- persistent recovery across restart;
- automated Nav2 integration tests.
