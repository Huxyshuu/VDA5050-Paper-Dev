# Deployment Architecture

## Component boundary

```text
Warehouse operator / case-study script
                 |
                 v
Raspberry Pi fleet/master control
                 |
                 v
          Mosquitto MQTT broker
        VDA 5050 v3.0 JSON topics
          /                    \
         v                      v
Crane VDA adapter          ROX VDA adapter
Raspberry Pi / edge        ROX onboard ROS 2
         |                      |
       OPC UA              Nav2 + Neobotix stack
         |                      |
    Crane PLC/safety        ROX drivers/safety
```

## Raspberry Pi

Runs:

- Mosquitto;
- `fleet_control/master_control.py`;
- normally `crane_edge/crane_vda5050_adapter_v3.py`.

Responsibilities:

- stamp and publish orders;
- publish standard and project-specific instant actions;
- receive state/connection/factsheet messages;
- cache order/action mappings;
- coordinate the first crane/ROX rendezvous;
- expose Flask UI/API and `/runtime` diagnostics.

The Pi does not run Nav2 and does not need to join the robot ROS domain.

## Crane edge

The existing crane adapter maps VDA actions to OPC UA/PLC calls and maps crane feedback to VDA state. The crane PLC and local safety functions remain authoritative.

## ROX-Diff onboard computer

Runs:

- Neobotix `rox_bringup`;
- Neobotix `rox_navigation` / Nav2;
- this project's separate ROS overlay;
- `rox_vda5050_adapter`.

The adapter is the only bridge from the robot ROS graph to MQTT. It turns VDA nodes into Nav2 goals and turns TF/odometry/battery/safety feedback into VDA state.

## Active topic roots

```text
vda5050/v3/konecranes/ilmatar_1/{order,instantActions,state,connection,factsheet}
vda5050/v3/neobotix/rox_diff_1/{order,instantActions,state,connection,factsheet}
```

Most topics use QoS 0. `connection` uses QoS 1 and is retained, with a last will for unexpected disconnects.

## Coordinate systems

ROX uses ROS frames:

```text
map -> odom -> base_link
```

VDA order node positions use the same numerical `map` frame coordinates and a stable project-level `mapId`, `df_map`.

The crane and ROX logical node IDs can match for orchestration (`node2`/`node2`) even though their physical coordinate models are different. The master pairs logical workflow states; it does not compare crane XY and robot XY directly.

## Safety boundary

VDA/MQTT/Flask orchestration is not safety-rated. The robot scanner/FlexiSoft/relayboard/controller and crane PLC/local safety remain authoritative. The master may enforce workflow gates, but those gates are additional orchestration logic rather than safety certification.

## Current lab network

```text
Ilmatar private network
  Raspberry Pi Wi-Fi: 192.168.0.116

DTLabOpen
  Raspberry Pi Ethernet: 192.168.50.115
  Neobotix ROX-Diff:     192.168.50.50
```

The Pi and ROX-Diff communicate directly over DTLabOpen. The Pi hosts MQTT on `192.168.50.115:1883` and Flask on `192.168.50.115:5000`. No NAT or port-forwarding boundary exists between them. ROS 2 and Nav2 remain local to the ROX-Diff.

