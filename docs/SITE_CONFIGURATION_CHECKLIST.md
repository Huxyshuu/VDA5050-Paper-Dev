# Site Configuration Checklist

Complete this file on the real equipment. Do not replace unknown values with guesses.

## Raspberry Pi and network

- [ ] Pi username: `____________________`
- [ ] Pi hostname: `____________________`
- [ ] Pi/MQTT IPv4 address: `____________________`
- [ ] MQTT port: `____________________`
- [ ] Pi project path: `____________________`
- [ ] Flask address/port: `____________________`
- [ ] ROX can ping the Pi.
- [ ] ROX can open TCP connection to MQTT port.
- [ ] MQTT is restricted to the trusted lab network.
- [ ] Authentication/TLS plan documented for non-lab use.

## Neobotix delivered software

- [ ] ROS distribution: `____________________`
- [ ] Neobotix workspace: `____________________`
- [ ] `rox_bringup` launch file: `____________________`
- [ ] Bringup arguments used: `____________________`
- [ ] `rox_navigation` mapping launch file: `____________________`
- [ ] Mapping arguments used: `____________________`
- [ ] Navigation launch file: `navigation.launch.py` / other: `____________________`
- [ ] `rox_type`: `diff`
- [ ] `frame_type`: `short` / `long` / other: `____________________`
- [ ] Robot namespace: `____________________`
- [ ] Lidar topic: `____________________`
- [ ] Odometry topic: `____________________`
- [ ] Battery topic and message type: `____________________`
- [ ] Emergency-stop topic and message type: `____________________`
- [ ] Safety-state topic and message type: `____________________`
- [ ] Nav2 action name: `____________________`
- [ ] Base frame: `____________________`
- [ ] Map frame: `____________________`

## Map and navigation

- [ ] Map ID: `____________________`
- [ ] Map YAML absolute path: `____________________`
- [ ] Map image absolute path: `____________________`
- [ ] Map backed up.
- [ ] Lidar alignment verified in RViz.
- [ ] Robot footprint and payload footprint verified.
- [ ] Global/local costmaps verified.
- [ ] Controller and planner verified.
- [ ] Commissioning maximum linear speed: `____________________`
- [ ] Commissioning maximum angular speed: `____________________`
- [ ] Emergency stops accessible throughout test route.

## Captured waypoints

| Waypoint | x (m) | y (m) | theta (rad) | XY tolerance (m) | theta tolerance (rad) | Repeated Nav2 test passed |
|---|---:|---:|---:|---:|---:|---|
| home | | | | | | [ ] |
| short_test | | | | | | [ ] |
| crane_handover | | | | | | [ ] |
| warehouse_dropoff | | | | | | [ ] |

- [ ] All waypoints belong to the same saved map.
- [ ] `configs/rox_waypoints.yaml` changed to `configured: true` only after verification.
- [ ] Short order generated and validated.
- [ ] Full route generated and validated.

## VDA identities and topics

- [ ] Version: `3.0.0`
- [ ] ROX manufacturer: `neobotix`
- [ ] ROX serial number: `rox_diff_1` / actual configured: `____________________`
- [ ] ROX topic root: `____________________`
- [ ] Crane manufacturer: `konecranes`
- [ ] Crane serial number: `ilmatar_1` / actual configured: `____________________`
- [ ] Crane topic root: `____________________`
- [ ] Factsheets contain verified physical/capability values.
- [ ] Factsheet identities match adapter/master identities exactly.

## Crane and handover

- [ ] OPC UA URL configured outside Git.
- [ ] Access code configured outside Git.
- [ ] Crane automatic mode requirement verified.
- [ ] Homing/preflight requirement verified.
- [ ] `ALLOW_UNHOMED_START=false` for motion tests.
- [ ] Crane handover node ID: `____________________`
- [ ] ROX handover node ID: `____________________`
- [ ] Automatic release action ID: `____________________`
- [ ] Manual release action ID: `____________________`
- [ ] Safe-lift completion action ID: `____________________`
- [ ] ROX hold action ID: `____________________`
- [ ] Manual release time-to-live: `____________________`
- [ ] Exact action IDs checked against both order files.
- [ ] Free-text `information[]` excluded from safety/control decisions.
- [ ] Crane-only test passed without load.
- [ ] ROX-only full route passed without crane motion.
- [ ] Coordinated no-load test passed repeatedly.
- [ ] Failure/recovery procedure documented for broker loss, adapter loss, localization loss, Nav2 failure and scanner intervention.

## Sign-off

- Test date: `____________________`
- Software commit/package: `____________________`
- Operator: `____________________`
- Observer/safety responsible person: `____________________`
- Result and open issues: `____________________________________________________________`
