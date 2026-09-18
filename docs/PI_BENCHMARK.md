# Run the ROX paper benchmark from the Pi

This replaces every earlier ROX-runner and eight-timestamp procedure. The only
measured quantities are command-to-Nav2-acknowledgement and
command-to-Nav2-completion, both observed on the Pi. See
[architecture](architecture.md) for their exact boundaries.

## 1. Update software once

Apply this revision to the repository on the Pi and ROX. It is based on
`1441592` and does not require the previous suggested patch. Preserve local
site configuration, maps and results when merging. Review `git diff` before
committing. Do not replace your project with an extracted folder over the top
of local files.

On ROX, while idle, rebuild the existing adapter overlay:

```bash
cd ~/Projects/VDA5050-Paper-Dev
bash scripts/build_rox_overlay.sh
```

Use the normal ROX bringup, current map/localization and Nav2. Stop the old
adapter while idle, then start exactly one updated instance:

```bash
bash scripts/run_rox_adapter_real.sh
```

This is the usual robot service, not a test runner. No logging flag, benchmark
config file or measurement process is needed on ROX. The new adapter simply
relays its native Nav2 replies to the Pi. Old `BENCHMARK_LOG_*` and
`BENCHMARK_CONFIG_*` environment variables are obsolete and ignored.

## 2. Give the Pi a ROS 2 client

The direct baseline requires the Pi to call the remote Nav2 action over ROS 2.
MQTT alone cannot provide a native ROS 2 baseline. The Pi does not need robot
drivers, a Nav2 server, a map server or a Neobotix workspace.

The provided Docker environment runs the ROS Jazzy client on the Pi itself
and works independently of the Pi's existing Python/Flask environment. Use a
64-bit Pi OS and an installed Docker Engine. If Docker is absent on a Debian
or Ubuntu Pi, the distribution package is an option:

```bash
sudo apt update
sudo apt install docker.io
sudo systemctl enable --now docker
sudo usermod -aG docker "$USER"
```

Log out and back in after changing group membership. Build the client image:

```bash
cd ~/VDA5050-Paper-Dev
docker build -f deploy/pi-benchmark.Dockerfile -t vda5050-pi-benchmark:jazzy .
```

Use the SAME `ROS_DOMAIN_ID` and RMW as the running ROX stack. Check the
existing ROX launch environment or service configuration. The example below
uses this repository's domain 169; replace it if your robot uses another value:

```bash
export ROS_DOMAIN_ID=169
export RMW_IMPLEMENTATION=rmw_cyclonedds_cpp
```

The wrapper uses host networking and the Pi hostname; localhost therefore
refers to the Pi broker. Docker is not a fourth physical device. Keep this
same client environment for native and VDA trials. If your site requires a
Cyclone DDS interface/peer configuration, make it available inside the image
or container and use the same configuration in both conditions; do not
silently switch RMW to make one condition work.

The wrapper also uses the repository's ROX peer address `192.168.50.50` through
`ROS_STATIC_PEERS`; override it if the robot address changed. An exported
`CYCLONEDDS_URI` is forwarded, but any file it references must exist inside
the container at that path. The normal default needs no extra DDS file.

If the Pi already has a working **native ROS Jazzy** installation, use that
instead by setting `export PI_BENCHMARK_RUNTIME=native`. Install the packages
listed in `deploy/pi-benchmark.Dockerfile` in that ROS-compatible environment.
Do not use a Python 3.11 Flask virtual environment to import Jazzy's Python
3.12 modules. The remaining wrapper commands are identical.

Read-only installation check:

```bash
bash scripts/pi_benchmark.sh python3 -m unittest discover -s tests -p 'test_*.py'
```

Keep Mosquitto running on the Pi. The master/dashboard may run idle; do not
issue scenario or waypoint commands from it during the benchmark. Leave the
ROX adapter running for both conditions. Crane motion is not part of this test.

## 3. Verify the frozen benchmark configuration

Edit `benchmark/config/rox_benchmark.yaml` on the Pi. Existing x/y and A/B
headings are retained by the revision. Confirm they still describe the new
map and the physical benchmark position. A and B differ by 90 degrees.

| Setting | Required value/meaning |
|---|---|
| `runner_hostname` | Output of `hostname` on the Pi |
| `mqtt.host` | `127.0.0.1`, the local Pi broker |
| `schema_version` | `2` |
| `measurement_protocol` | `pi-nav2-v1` |
| `configured` | `true` only for physically verified coordinates |
| `ros.navigate_to_pose_action` | Same action used by the adapter, normally `/navigate_to_pose` |
| `ros.*_frame` | Frames in the running robot's TF tree |
| `tolerances` | Frozen start and endpoint checks, in metres/radians |
| `readiness` | Freshness/stationarity checks and settling time, outside timing |

The supplied readiness check expects live `/tf` updates for `odom` and
`base_link`, plus `/odom`. Adjust frame names to the actual chain if your
robot uses a different configuration. It never compares remote header times
with the Pi monotonic clock.

## 4. Prepare and run a new five-pair pilot

All commands below run on the Pi in `~/VDA5050-Paper-Dev`.
Use a NEW run directory each time a campaign is prepared:

```bash
bash scripts/pi_benchmark.sh python3 benchmark/rox_latency_benchmark.py prepare \
  --run-dir results/benchmark/rox_pi_pilot01 --pairs 5 --seed 5050 --start-at A

bash scripts/pi_benchmark.sh python3 benchmark/rox_latency_benchmark.py check \
  --run-dir results/benchmark/rox_pi_pilot01
```

If ROX is currently at heading B after your previous pilot, use `--start-at B`
when preparing instead. It reverses the scheduled directions; it does not
move the robot. The check refuses motion when the frozen start does not match.

`prepare` freezes config, schedule, source and Pi ROS environment. `check`
verifies Pi-to-Nav2 discovery, the local MQTT connection, updated adapter
feedback, real navigation mode, matching frames/map, fresh localization and a
stationary robot. Neither commands motion. A stale adapter will fail the
handshake rather than quietly producing old timestamps.

Run the first pair under supervision, keeping the area clear and the existing
stop controls available:

```bash
bash scripts/pi_benchmark.sh python3 benchmark/rox_latency_benchmark.py run \
  --run-dir results/benchmark/rox_pi_pilot01 --end-row 3

bash scripts/pi_benchmark.sh python3 analysis/derive_latency.py \
  results/benchmark/rox_pi_pilot01/events.jsonl \
  --schedule results/benchmark/rox_pi_pilot01/schedule.csv --through-row 3 \
  --output results/benchmark/rox_pi_pilot01/first_pair.csv
```

Each pair is three rows: the first randomized condition, an excluded native
reset, and the other condition in the same direction. Two rows are measured.
After the first-pair audit passes, continue automatically from the next row:

```bash
bash scripts/pi_benchmark.sh python3 benchmark/rox_latency_benchmark.py run \
  --run-dir results/benchmark/rox_pi_pilot01
```

There are 15 pilot rows: ten measurements and five resets. The runner prints
both times after every completed row. It stops at any failure and never retries
or repeats an ID. Resumption works after a clean stop between successful rows.
An interrupted/failed trial blocks automatic continuation and remains evidence.
Cancellation is best effort: a stopped script does not prove physical motion
has stopped. Verify the robot state before any further command.

## 5. Audit and analyse the pilot

```bash
bash scripts/pi_benchmark.sh python3 analysis/derive_latency.py \
  results/benchmark/rox_pi_pilot01/events.jsonl \
  --schedule results/benchmark/rox_pi_pilot01/schedule.csv \
  --output results/benchmark/rox_pi_pilot01/trials.csv

bash scripts/pi_benchmark.sh python3 analysis/statistics.py \
  results/benchmark/rox_pi_pilot01/trials.csv \
  --output-dir results/benchmark/rox_pi_pilot01/analysis
```

The audit uses the schedule, not just the events that happened to arrive. A
wholly missing trial therefore appears in the CSV. The CSV is written even
when failed/missing/invalid rows require review; a nonzero exit flags them.
Keep the failed attempts and all scheduled denominators. Do not delete rows,
replace IDs, or collect until a desired success count is reached.

Check complete event sequences, equal target poses, acceptable localization
residuals, and logging reliability. Use the pilot to finalize the practical
effect size, sample-size rationale and settings before collecting final data.
Thirty pairs are a planned count, not a power guarantee.

## 6. Freeze and run the final campaign

Create a fresh directory and recorded seed. Select the robot's verified
current heading; five pairs end at the opposite heading to their start:

```bash
bash scripts/pi_benchmark.sh python3 benchmark/rox_latency_benchmark.py prepare \
  --run-dir results/benchmark/rox_pi_final01 --pairs 30 --seed 20271001 --start-at B

bash scripts/pi_benchmark.sh python3 benchmark/rox_latency_benchmark.py check \
  --run-dir results/benchmark/rox_pi_final01

bash scripts/pi_benchmark.sh python3 benchmark/logger_overhead.py \
  --output results/benchmark/rox_pi_final01/logger_overhead.json

bash scripts/pi_benchmark.sh python3 benchmark/freeze_environment.py \
  --config results/benchmark/rox_pi_final01/config.yaml \
  --config results/benchmark/rox_pi_final01/schedule.csv \
  --output results/benchmark/rox_pi_final01/environment.json \
  --network-note 'Pi local Mosquitto; Pi-to-ROX on DTLabOpen; document actual wired/Wi-Fi links'

docker image inspect vda5050-pi-benchmark:jazzy \
  > results/benchmark/rox_pi_final01/container_image.json
mosquitto -h > results/benchmark/rox_pi_final01/broker_version.txt
```

Review `environment.json`: the Pi queries the **running remote** Nav2, AMCL
and map parameters. A timed-out or failed dump is not successful evidence;
resolve the node namespace and save its actual parameter dump. Copy the active
map YAML/image into the run directory, and record the actual broker
configuration (without passwords), ROX deployed commit/build, Nav2 version,
network links and background workload. The source snapshot preserves the
reviewed source but does not by itself prove which binary runs on ROX.

Run the first final pair and audit its prefix as above, using the final
directory. Then run the same `run --run-dir ...` command without `--end-row`
to finish the remaining rows. For 30 pairs there are **90 rows: 60 measured
commands and 30 excluded resets**. All are automatically scheduled from the
Pi, with fresh-start/settling checks before each command. No ROX-side test
commands are needed.

Do not rebuild, remap, tune Nav2, change tolerances, or change the client
environment during the final campaign. Any necessary change starts a new,
separately identified campaign, with the earlier evidence preserved.

## 7. Obtain the paper results

```bash
bash scripts/pi_benchmark.sh python3 analysis/derive_latency.py \
  results/benchmark/rox_pi_final01/events.jsonl \
  --schedule results/benchmark/rox_pi_final01/schedule.csv \
  --output results/benchmark/rox_pi_final01/trials.csv

bash scripts/pi_benchmark.sh python3 analysis/statistics.py \
  results/benchmark/rox_pi_final01/trials.csv \
  --output-dir results/benchmark/rox_pi_final01/analysis \
  --bootstrap-samples 10000 --seed 5050

tar -czf rox_pi_final01_results.tar.gz -C results/benchmark rox_pi_final01
```

| File | Purpose |
|---|---|
| `events.jsonl` | Authoritative Pi timestamp and outcome records |
| `trials.csv` | All 90 scheduled rows, including resets/failures; exact nanoseconds and two durations in ms |
| `analysis/latency_summary.csv` | n, mean, sample SD, median, quartiles, IQR, p95 and range |
| `analysis/paired_differences.csv` | Each pair's VDA-minus-native effect in ms and percent |
| `analysis/trial_accounting.csv` | Measured scheduled, successful, failed, missing and invalid counts |
| `analysis/latency_summary_table.tex` | Paired effects and bootstrap 95% CIs for the paper |
| `analysis/latency_comparison.pdf` / `.png` | Native/VDA acknowledgement and completion distributions |

Statistics use complete successful measured trials; failures remain in the
accounting and must be reported. Paired effects use only pairs with both
conditions available. Mean and average are the same quantity; `std` is sample
standard deviation. Bootstrap CIs estimate uncertainty in the median paired
difference. Do not infer equivalence from a nonsignificant difference, claim
reliable p99 from 30 observations, or infer full handover throughput from
single rotations.

Back up the complete archive off the Pi. The dashboard's **Pi command timing**
section is a live view of these values, not the authoritative CSV generator.

## Troubleshooting

| Message | Action |
|---|---|
| Pi cannot reach NavigateToPose | Match domain/RMW, verify remote Nav2 is active, inspect network/DDS interfaces; MQTT connectivity alone is insufficient |
| No adapter handshake | Update/rebuild/restart the single ROX adapter; check MQTT identity and topic |
| Adapter busy | Finish/cancel the existing order and verify idle; do not start another controller |
| No fresh TF/odometry | Restore DDS state delivery and localization; inspect frame names |
| Start pose error | Check A/B schedule origin and the commissioned map/pose; do not loosen tolerances to force a pass |
| Source/config/environment changed | Restore the frozen setup or create a new named campaign |
| Failed/interrupted attempt | Preserve the run and review it; no automatic retry or silent row deletion |

The crane will require a separate, correctly defined OPC UA/PLC response
contract. Existing crane operation continues; this guide and these metrics
are specifically for Nav2 on ROX.
