# Crane edge runtime

The active Ilmatar crane adapter remains separate from the ROX ROS overlay.

## Files

- `crane.py`: low-level OPC UA wrapper;
- `crane_vda5050_adapter_v3.py`: VDA 5050 v3 adapter;
- `requirements.txt`: runtime Python dependencies;
- `access.txt.example`: local credential-file format;
- `factsheets/ilmatar_crane_factsheet.template.json`: schema-valid template with unknown physical values set to zero.

## Install

```bash
cd ~/VDA5050-Paper-Dev
python3 -m venv .venv-crane
source .venv-crane/bin/activate
python -m pip install --upgrade pip
python -m pip install -r crane_edge/requirements.txt
```

## Credentials

Prefer environment variables:

```bash
export CRANE_OPCUA_URL='<REAL_OPCUA_URL>'
export CRANE_ACCESS_CODE='<REAL_NUMERIC_ACCESS_CODE>'
```

Alternatively:

```bash
cd ~/VDA5050-Paper-Dev/crane_edge
cp access.txt.example access.txt
chmod 600 access.txt
nano access.txt
```

Line 1 is the OPC UA URL and line 2 is the numeric access code. The path can be overridden with `CRANE_ACCESS_FILE`. The real file is ignored by Git and must never be distributed.

## Start

```bash
cd ~/VDA5050-Paper-Dev
export VDA_MQTT_HOST=192.168.1.115
export ALLOW_UNHOMED_START=false
./scripts/run_crane_adapter.sh
```

Startup is fail-closed: the adapter exits if automatic mode/preflight/homing is not valid. `ALLOW_UNHOMED_START=true` is restricted to supervised telemetry diagnosis and must not be used for motion commissioning.
