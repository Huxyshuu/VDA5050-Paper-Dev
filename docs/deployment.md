# Deployment Guide

## 1. Raspberry Pi

Expected current lab values:

```text
Pi/MQTT host: 192.168.1.115
MQTT port:    1883
Flask port:   5000
```

Install:

```bash
sudo apt update
sudo apt install -y mosquitto mosquitto-clients python3-venv netcat-openbsd
sudo systemctl enable --now mosquitto

cd ~/VDA5050-Paper-Dev
python3 -m venv .venv
source .venv/bin/activate
pip install -r fleet_control/requirements.txt
cp -n configs/fleet_control.env.example configs/fleet_control.env
```

For an isolated lab network, use the included listener example:

```bash
sudo cp deploy/mosquitto/vda5050-lab.conf.example \
  /etc/mosquitto/conf.d/vda5050-lab.conf
sudo systemctl restart mosquitto
ss -ltnp | grep 1883
```

Start the master:

```bash
./scripts/run_master_control.sh
```

Inspect:

```bash
curl http://192.168.1.115:5000/runtime | python3 -m json.tool
mosquitto_sub -h 192.168.1.115 -t 'vda5050/v3/#' -v
```

The `deploy/systemd/vda5050-master.service.example` file can be adapted after manual startup succeeds.

## 2. ROX-Diff project overlay

Keep the Neobotix workspace as the underlay. Build this repository's `ros2_ws` separately:

```bash
cd ~/VDA5050-Paper-Dev/ros2_ws
source /opt/ros/$ROS_DISTRO/setup.bash
source ~/ros2_workspace/install/setup.bash
rosdep install --from-paths src --ignore-src -r -y
colcon build --symlink-install
source install/setup.bash
```

Terminal source order:

```bash
source /opt/ros/$ROS_DISTRO/setup.bash
source ~/ros2_workspace/install/setup.bash
source ~/VDA5050-Paper-Dev/ros2_ws/install/setup.bash
```

Do not copy DBot packages and do not overwrite Neobotix `rox_bringup`, `rox_navigation`, drivers or message packages.

## 3. Native ROX bringup

Discover the exact native launch file and arguments installed on the delivered robot:

```bash
ros2 pkg prefix rox_bringup
find "$(ros2 pkg prefix rox_bringup)/share/rox_bringup/launch" \
  -maxdepth 1 -type f -name '*.launch.py' -printf '%f\n' | sort
ros2 launch rox_bringup <ACTUAL_BRINGUP_FILE>.launch.py --show-arguments
```

Start that file with `rox_type:=diff` and only the scanner/frame/namespace arguments verified for the delivered configuration.

Run:

```bash
./scripts/check_rox_ros_interfaces.sh
```

## 4. MQTT check from ROX

```bash
sudo apt install -y mosquitto-clients netcat-openbsd
./scripts/check_pi_mqtt_from_rox.sh 192.168.1.115 1883
```

On Pi:

```bash
mosquitto_sub -h 192.168.1.115 \
  -t 'vda5050/v3/commissioning/ping' -C 1 -v
```

## 5. Mapping and navigation

Use [rox_diff_mapping_and_orders.md](rox_diff_mapping_and_orders.md). Save the map outside the Neobotix source tree, for example:

```text
~/maps/warehouse_case_study.yaml
~/maps/warehouse_case_study.pgm
```

Start Nav2:

```bash
ros2 launch rox_navigation navigation.launch.py \
  rox_type:=diff \
  map:=$HOME/maps/warehouse_case_study.yaml
```

## 6. Adapter dry run

After bringup/Nav2 and overlay sourcing:

```bash
ros2 launch rox_vda5050_adapter rox_vda5050_adapter.launch.py \
  mqtt_host:=192.168.1.115 \
  map_id:=warehouse_case_study \
  dry_run_navigation:=true
```

Verify state/order/hold/release before setting dry run to false.

## 7. Real adapter motion

Only after the short order has been generated and native Nav2 goals work:

```bash
ros2 launch rox_vda5050_adapter rox_vda5050_adapter.launch.py \
  mqtt_host:=192.168.1.115 \
  map_id:=warehouse_case_study \
  dry_run_navigation:=false
```

Use low speed, clear space, accessible emergency stops and no crane motion for the first run.

## 8. Environment alignment

The Pi does not need matching ROS middleware because communication is MQTT. ROS domain/RMW alignment matters only among ROS processes on the ROX computer or other machines intentionally joining its ROS graph.

## 9. Credentials

Do not commit:

- crane access code;
- MQTT passwords;
- private certificates;
- machine-specific `.env` files containing secrets.

The distributed source includes examples only. Anonymous MQTT is for isolated commissioning, not production.
