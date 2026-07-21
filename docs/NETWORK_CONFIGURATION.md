# DTLabOpen Network Configuration

## Verified addresses

```text
Raspberry Pi Ethernet / DTLabOpen: 192.168.50.115
Neobotix ROX-Diff / DTLabOpen:     192.168.50.50
Raspberry Pi Wi-Fi / Ilmatar:      192.168.0.116
DTLabOpen gateway:                 192.168.1.1 (unchanged)
```

Record the actual prefix lengths from `ip -br address`; do not infer them solely from the addresses.

## Required communication

The Pi and ROX-Diff communicate directly on DTLabOpen:

```text
ROX 192.168.50.50 <-> Pi 192.168.50.115
                         |- MQTT 1883
                         `- Flask 5000
```

No intermediate subnet, NAT, port forwarding or additional network device is part of this path. ROS 2/Nav2 remain local to the ROX-Diff; MQTT carries VDA 5050 messages to the Pi.

## Pi checks

```bash
ip -br address
ip route
ip route get 192.168.50.50
ping -c 3 192.168.50.50
nc -vz 192.168.50.50 22   # only when SSH is enabled on ROX
```

The Pi must retain both interfaces without assigning its Ethernet interface an address from the Ilmatar `192.168.0.x` range.

## ROX checks

```bash
ip -br address
ip route
ip route get 192.168.50.115
ping -c 3 192.168.50.115
nc -vz 192.168.50.115 1883
nc -vz 192.168.50.115 5000
./scripts/check_pi_mqtt_from_rox.sh 192.168.50.115 1883
```

## Mosquitto exposure

For lab commissioning, bind anonymous MQTT only to loopback and the Pi DTLabOpen address. Do not expose it through the Pi's Ilmatar interface. Use authentication and TLS outside the isolated lab environment.
