# Crane edge runtime

The active Ilmatar adapter remains separate from the ROX ROS overlay.

Files:

- `crane.py`: low-level OPC UA wrapper;
- `crane_vda5050_adapter_v3.py`: VDA 5050 v3 crane adapter;
- `access.txt.example`: required local credential file format.

On the Raspberry Pi/crane edge device:

```bash
cd crane_edge
cp access.txt.example access.txt
```

Edit `access.txt` so line 1 is the OPC UA URL and line 2 is the numeric crane access code. `access.txt` is ignored by Git and must not be distributed.

The adapter currently opens `access.txt` relative to its working directory, so start it from `crane_edge/` unless that code is later refactored to an environment/config path.
