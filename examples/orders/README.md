# Active order files

- `order_ilmatar_v3.json` is the active crane example/order template.
- `order_rox_diff_v3.json` is intentionally not distributed with site coordinates. Generate it after mapping and waypoint capture:

```bash
python3 scripts/generate_rox_order.py \
  --waypoints configs/rox_waypoints.yaml \
  --route examples/routes/rox_short_motion_test.yaml \
  --output examples/orders/order_rox_diff_v3.json \
  --update-fleet-env configs/fleet_control.env
```

Replace the short route with `examples/routes/rox_crane_case_study.yaml` only after the short real-motion test passes.
