#!/usr/bin/env bash
# Run any benchmark/analysis command in the same Pi client environment.
set -eo pipefail
ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
cd "$ROOT"
export ROS_DOMAIN_ID="${ROS_DOMAIN_ID:-169}"
export ROS_STATIC_PEERS="${ROS_STATIC_PEERS:-192.168.50.50}"
export ROS_AUTOMATIC_DISCOVERY_RANGE="${ROS_AUTOMATIC_DISCOVERY_RANGE:-SUBNET}"
export ROS_LOCALHOST_ONLY=0
if [[ $# -eq 0 ]]; then
  echo "Usage: bash scripts/pi_benchmark.sh python3 benchmark/rox_latency_benchmark.py --help"
  exit 2
fi
if [[ "${PI_BENCHMARK_RUNTIME:-docker}" == "native" ]]; then
  source /opt/ros/jazzy/setup.bash
  export RMW_IMPLEMENTATION="${RMW_IMPLEMENTATION:-rmw_cyclonedds_cpp}"
  exec "$@"
fi
exec docker run --rm --init --network host --hostname "$(hostname)" \
  --user "$(id -u):$(id -g)" --volume "$ROOT:/project" --workdir /project \
  --env ROS_DOMAIN_ID="$ROS_DOMAIN_ID" \
  --env ROS_STATIC_PEERS="$ROS_STATIC_PEERS" --env CYCLONEDDS_URI \
  --env RMW_IMPLEMENTATION="${RMW_IMPLEMENTATION:-rmw_cyclonedds_cpp}" \
  --env ROS_AUTOMATIC_DISCOVERY_RANGE="${ROS_AUTOMATIC_DISCOVERY_RANGE:-SUBNET}" \
  --env ROS_LOCALHOST_ONLY=0 \
  "${PI_BENCHMARK_IMAGE:-vda5050-pi-benchmark:jazzy}" "$@"
