#!/usr/bin/env bash
set -euo pipefail

HOST="${1:-192.168.50.115}"
PORT="${2:-1883}"
TOPIC="${3:-vda5050/v3/commissioning/ping}"
PAYLOAD="rox-$(hostname)-$(date -u +%Y%m%dT%H%M%SZ)"

command -v mosquitto_pub >/dev/null || {
  echo "mosquitto_pub is missing. Install mosquitto-clients." >&2
  exit 2
}
command -v nc >/dev/null || {
  echo "nc is missing. Install netcat-openbsd." >&2
  exit 2
}

echo "Checking TCP ${HOST}:${PORT} ..."
nc -vz -w 3 "$HOST" "$PORT"
echo "Publishing MQTT test message to ${TOPIC} ..."
mosquitto_pub -h "$HOST" -p "$PORT" -t "$TOPIC" -m "$PAYLOAD" -q 0
cat <<EOF
Published: $PAYLOAD
On the Pi, confirm with:
  mosquitto_sub -h 127.0.0.1 -t '$TOPIC' -C 1 -v
EOF
