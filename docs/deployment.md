# Deployment Guide

This guide records the current Aalto lab deployment. For commissioning order and safety gates, use [COMMISSIONING_RUNBOOK.md](COMMISSIONING_RUNBOOK.md). For daily ROX commands, use [ROX_COMMANDS.md](ROX_COMMANDS.md).

## Current hosts and network

```text
Raspberry Pi eth0 / DTLabOpen: 192.168.50.115
ROX-Diff / DTLabOpen:         192.168.50.50
Raspberry Pi Wi-Fi / Ilmatar: 192.168.0.116
MQTT:                         192.168.50.115:1883
Flask master:                 192.168.50.115:5000
```

The Pi and ROX are direct DTLabOpen peers. No router, NAT or port forwarding is used between them.

Verify from the ROX:

```bash
ip route get 192.168.50.115
ping -c 3 192.168.50.115
nc -vz 192.168.50.115 1883
```

## Raspberry Pi

```bash
cd ~/VDA5050-Paper-Dev
git pull --ff-only
sudo apt update
sudo apt install -y mosquitto mosquitto-clients python3-venv netcat-openbsd
sudo systemctl enable --now mosquitto
python3 -m venv .venv
source .venv/bin/activate
python -m pip install --upgrade pip
python -m pip install -r fleet_control/requirements.txt
cp -n configs/fleet_control.env.example configs/fleet_control.env
./scripts/run_static_checks.sh
./scripts/run_master_control.sh
```

Monitor:

```bash
curl http://192.168.50.115:5000/runtime | python3 -m json.tool
mosquitto_sub -h 192.168.50.115 -t 'vda5050/v3/#' -v
```

## ROX-Diff project overlay

The delivered Neobotix workspace remains the underlay:

```text
/home/neobotix/ros2_workspace
```

The project is a separate overlay:

```text
/home/neobotix/Projects/VDA5050-Paper-Dev/ros2_ws
```

Build:

```bash
cd ~/Projects/VDA5050-Paper-Dev
git pull --ff-only
./scripts/rox.sh build
source ros2_ws/install/setup.bash
./scripts/rox.sh status
```

The helper avoids enabling Bash `nounset` while ROS-generated setup files are sourced.

## Native hardware bringup

The robot already starts the native hardware stack at boot through `ROS_AUTOSTART.sh`:

```bash
source ~/ros2_workspace/install/setup.bash
sleep 2
ros2 launch rox_bringup bringup_launch.py \
  rox_type:=diff \
  imu_enable:=True \
  use_d435:=True \
  enable_io_board:=True
```

Do not start a duplicate bringup. Verify it with:

```bash
./scripts/rox.sh interfaces
```

## Nav2 and commissioned map

The current map pair is:

```text
/home/neobotix/ros2_workspace/install/rox_navigation/share/rox_navigation/maps/df_map.yaml
/home/neobotix/ros2_workspace/install/rox_navigation/share/rox_navigation/maps/df_map.pgm
```

Back up both files outside `install/`.

Start Nav2, AMCL and RViz:

```bash
./scripts/rox.sh nav
```

Set the initial pose in RViz and verify:

```bash
./scripts/rox.sh status
./scripts/rox.sh tf
```

## Waypoint tools

```bash
./scripts/rox.sh visualize
./scripts/rox.sh list
./scripts/rox.sh goto-dry short_test
./scripts/rox.sh goto short_test
```

Capture or recapture:

```bash
./scripts/rox.sh capture home
./scripts/rox.sh capture short_test
./scripts/rox.sh capture crane_handover
./scripts/rox.sh capture warehouse_dropoff
```

Any recapture resets `configured: false`. Restore `configured: true` only after repeated exact-goal and physical checks pass.

## VDA adapter

Dry-run first:

```bash
./scripts/rox.sh adapter-dry
```

Real Nav2 movement only after ordinary Nav2 waypoint tests and dry-run VDA tests pass:

```bash
./scripts/rox.sh adapter-real
```

Both runners use these defaults:

```text
VDA_MQTT_HOST=192.168.50.115
VDA_MAP_ID=df_map
```

## Optional services

Adapt and review before enabling:

```text
deploy/systemd/vda5050-master.service.example
deploy/systemd/rox-vda5050-adapter-dry.service.example
deploy/systemd/rox-vda5050-adapter-real.service.example
```

Start with the dry-run ROX service. Do not enable the real-motion service until supervised manual commissioning passes.
