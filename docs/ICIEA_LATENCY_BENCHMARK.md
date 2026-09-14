# ICIEA native-versus-VDA latency benchmark

This protocol measures the incremental cost of VDA 5050 v3 orchestration over
the same native device operation. It deliberately uses one small, repeatable
motion per device:

- ROX-Diff: rotate 90 degrees at a fixed map position;
- Ilmatar: move the hoist between two fixed, supervised heights.

The physical controller, target, speed, safety functions, and host are held
constant. Only the orchestration path changes. Release zones, disturbance
catalogues, and full-handover throughput are outside this confirmatory test.

## Safety and validity rules

1. Keep both config files at `configured: false` until every coordinate has
   been physically verified under supervision.
2. Keep the E-stop available and follow the existing commissioning runbook.
3. Stop the crane adapter before a native crane row. Only one process may own
   the crane control session.
4. Use the runner and adapter on the same physical host for a device. ROX
   timings are produced on the ROX computer; crane timings are produced on the
   Pi. Never subtract `monotonic_ns` values from different `host` or `boot_id`
   values.
5. Do not edit raw JSONL after collection. If a trial fails, retain it and run
   a new trial with a new ID; do not overwrite or silently exclude it.
6. Treat the live UI as an operator view. Host JSONL files are the research
   source of truth.

## Event model

Every component uses `benchmark/experiment_logger.py` and the schema in
`benchmark/event_schema.json`. The clock is captured before serialization,
file I/O, or MQTT publishing. A background thread writes the event.

| Event | Native | VDA | Meaning |
|---|---:|---:|---|
| `COMMAND_ISSUED` | yes | yes | runner starts the measured command |
| `MQTT_RECEIVED` | no | yes | adapter callback receives the VDA order |
| `VDA_ACCEPTED` | no | yes | schema and semantic checks succeed |
| `NATIVE_DISPATCH` | yes | yes | immediately before Nav2/crane native call |
| `NATIVE_ACK` | yes | yes | native interface accepts/returns |
| `MOTION_STARTED` | yes | yes | odometry/position crosses frozen threshold |
| `MOTION_COMPLETED` | yes | yes | native controller reports the target complete |
| `RESULT_OBSERVED` | yes | yes | completion reaches the benchmark runner |

The UI and analysis calculate elapsed milliseconds only when the origin and
event have the same `host`, `boot_id`, and `trial_id`.

## 1. Install and verify software

On the Pi:

```bash
cd ~/VDA5050-Paper-Dev
source .venv/bin/activate
pip install -r fleet_control/requirements.txt
pip install -r crane_edge/requirements.txt
pip install -r analysis/requirements.txt
python3 -m unittest discover -s tests -p 'test_*.py'
python3 benchmark/logger_overhead.py \
  --output results/benchmark/logger_overhead_pi.json
```

On ROX, install the Python requirements in the interpreter used by the
benchmark runner, then rebuild the overlay because the adapter package now
installs the shared logger:

```bash
cd ~/Projects/VDA5050-Paper-Dev
python3 -m pip install paho-mqtt PyYAML jsonschema
./scripts/build_rox_overlay.sh
```

## 2. Freeze the physical configurations

Edit `benchmark/config/rox_benchmark.yaml` on ROX:

- set the verified `x` and `y` of an obstacle-free benchmark position;
- set `theta_a` and normalized `theta_b = theta_a + pi/2`;
- confirm the map, topic, Nav2 action, MQTT identity, and thresholds;
- set `configured: true` only after supervised native goal checks.

Edit `benchmark/config/crane_benchmark.yaml` on the Pi:

- set fixed bridge and trolley coordinates;
- set safe, repeatable `z_a_m` and `z_b_m` heights;
- confirm the VDA identity, map, MQTT values, and tolerances;
- verify the live bridge and trolley positions are within `start_xy_mm` so the
  VDA order cannot introduce an incidental XY movement;
- set `configured: true` only after supervised native checks.

Commit the frozen configs or preserve exact copies with the dataset. Every
event records their SHA-256 identifier.

## 3. Enable adapter instrumentation and the UI

On the Pi, copy the added benchmark variables from
`configs/fleet_control.env.example` to the local environment and use:

```bash
BENCHMARK_LOG_ENABLED=true
BENCHMARK_LOG_PATH=results/benchmark/crane_adapter_events.jsonl
BENCHMARK_CONFIG_FILE=benchmark/config/crane_benchmark.yaml
BENCHMARK_EVENT_TOPIC=vda5050/benchmark/events
```

Start the master normally:

```bash
./scripts/run_master_control.sh
```

The dashboard now contains a dedicated **Monotonic action timeline**. It shows
the raw `monotonic_ns`, same-clock elapsed milliseconds, event source,
architecture, device, trial, and completion status. The Export button returns
the full in-memory raw event stream; clearing the panel does not delete host
JSONL evidence.

On ROX:

```bash
export BENCHMARK_LOG_ENABLED=true
export BENCHMARK_LOG_PATH="$PWD/results/benchmark/rox_adapter_events.jsonl"
export BENCHMARK_CONFIG_FILE="$PWD/benchmark/config/rox_benchmark.yaml"
./scripts/run_rox_adapter_real.sh
```

For crane VDA rows, start the adapter with the Pi environment above:

```bash
./scripts/run_crane_adapter.sh
```

## 4. Generate immutable schedules

Pilot schedules contain five pairs, ten measured trials, and five excluded
reset rows per device:

```bash
python3 benchmark/generate_schedule.py --device rox --pairs 5 --seed 5050 \
  --output benchmark/schedules/rox_pilot.csv
python3 benchmark/generate_schedule.py --device crane --pairs 5 --seed 5050 \
  --output benchmark/schedules/crane_pilot.csv
```

After the pilot and protocol freeze, generate the confirmatory campaign with a
new recorded seed:

```bash
python3 benchmark/generate_schedule.py --device rox --pairs 30 --seed 20271001 \
  --output benchmark/schedules/rox_campaign.csv
python3 benchmark/generate_schedule.py --device crane --pairs 30 --seed 20271002 \
  --output benchmark/schedules/crane_campaign.csv
```

Each pair measures the same direction under native and VDA orchestration. A
native setup row returns the device to the pair start between treatments. Pair
direction alternates so the end of one pair is the start of the next. Never
reorder or delete schedule rows after collection begins.

## 5. Execute ROX rows

Keep Nav2/localization active and the instrumented VDA adapter running for all
rows. Execute the schedule in row order:

```bash
python3 benchmark/rox_latency_benchmark.py \
  --schedule benchmark/schedules/rox_pilot.csv --row 1
```

Repeat with rows 2 through 15. The runner reads the mode, direction, pair, and
trial ID from the row, verifies the live start pose, and refuses to move if it
is outside the frozen tolerance. Setup rows are logged as `architecture=setup`
and excluded from confirmatory analysis.

A one-off supervised diagnostic trial can be run explicitly:

```bash
python3 benchmark/rox_latency_benchmark.py --mode native \
  --direction a-to-b --trial-id diagnostic-rox-001
```

## 6. Execute crane rows

Run rows in schedule order. For a `vda` row, the crane adapter must be active.
For a `native` or setup row, stop the crane adapter first so the runner can own
the crane control and watchdog sessions.

```bash
python3 benchmark/crane_latency_benchmark.py \
  --schedule benchmark/schedules/crane_pilot.csv --row 1
```

The runner verifies the configured starting height. The native path uses the
same `Crane.set_target_hoist()` and `move_hoist_to_target(fast=True)` primitives
as the VDA adapter. It refuses motion when the automatic/watchdog preflight is
not satisfied.

## 7. Pilot acceptance gate

Do not start 30-pair collection until all five pilot pairs satisfy these
checks:

- every measured native trial has six required events;
- every measured VDA trial has eight required events;
- the runner and adapter events join by identical trial/order ID;
- compared events share one host and boot ID;
- native and VDA target values are identical inside each pair;
- no unexpected command, retry, timeout, or safety state occurs;
- logger p95 call overhead is recorded and negligible relative to the observed
  interface effects;
- threshold and tolerance choices are frozen before confirmatory collection.

Create the derived pilot table. The command fails the integrity gate if a
required sequence is incomplete:

```bash
python3 analysis/derive_latency.py \
  results/benchmark/rox_events.jsonl \
  results/benchmark/rox_adapter_events.jsonl \
  --output analysis/output/rox_pilot_trials.csv
```

Use the analogous two crane files for the crane pilot. `--allow-incomplete`
exists for diagnosis only and must not be used to make the campaign pass.

## 8. Freeze environment evidence

Run this on each device immediately before the confirmatory campaign:

```bash
python3 benchmark/freeze_environment.py \
  --config benchmark/config/rox_benchmark.yaml \
  --config '<active Nav2 parameter YAML>' \
  --output results/benchmark/rox_environment.json \
  --network-note 'ROX 192.168.50.50 to Pi Mosquitto 192.168.50.115 over DTLabOpen'
```

On the Pi, replace the config and add the crane/PLC software identifier:

```bash
python3 benchmark/freeze_environment.py \
  --config benchmark/config/crane_benchmark.yaml \
  --config '<active Mosquitto configuration>' \
  --output results/benchmark/crane_environment.json \
  --crane-software '<verified PLC/crane release>' \
  --network-note 'Pi Ethernet to MQTT/ROX; separate Ilmatar Wi-Fi to OPC UA PLC'
```

This captures Git commit, config hashes, Python/platform, ROS/RMW environment,
Nav2 package evidence, Mosquitto version, and non-secret network evidence.

## 9. Derive and analyse the campaign

Copy the immutable ROX logs from ROX to the analysis machine and the crane logs
from the Pi. Do not include the UI export when the same host events are already
present in raw logs; the derivation tool deduplicates exact events, but the host
files remain authoritative.

```bash
python3 analysis/derive_latency.py \
  results/benchmark/rox_events.jsonl \
  results/benchmark/rox_adapter_events.jsonl \
  results/benchmark/crane_events.jsonl \
  results/benchmark/crane_adapter_events.jsonl \
  --output analysis/output/all_trials.csv

python3 analysis/statistics.py analysis/output/all_trials.csv \
  --output-dir analysis/output --bootstrap-samples 10000 --seed 5050
```

Outputs are:

- `latency_summary.csv`: n, median, IQR, p95, p99, paired effect and CI;
- `paired_differences.csv`: native, VDA, delta, and percentage by pair;
- `trial_accounting.csv`: complete, successful, failed, and incomplete counts;
- `latency_summary_table.tex`: paper-ready compact effect table;
- `latency_comparison.pdf` and `.png`: native/VDA latency distributions.

The primary effect is paired `VDA - native`. Do not treat failure to reject a
null hypothesis as proof of equivalence, and do not combine the ROX and crane
numbers into a ranking of ROS 2 versus OPC UA.

## 10. Descriptive system validation

After the command campaign is locked, run 5--10 complete VDA AMR–crane
handovers with the existing supervised workflow. Record success, failed
actions, retries, timeouts, and unexpected states. Report these as descriptive
system validation, not as a second confirmatory throughput experiment.

The include-ready manuscript bookmarks are in
`docs/ICIEA_BENCHMARK_LATEX_BOOKMARKS.tex`.
