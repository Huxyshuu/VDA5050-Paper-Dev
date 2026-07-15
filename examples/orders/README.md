# Order templates

- `order_ilmatar_v3.json`: active crane template used by the Raspberry Pi master.
- `order_rox_diff_v3.json`: intentionally generated only after mapping and waypoint capture. It is ignored by Git to prevent accidental use of stale/site-specific coordinates.

Generate a short commissioning order:

```bash
python3 scripts/generate_rox_order.py \
  --waypoints configs/rox_waypoints.yaml \
  --route examples/routes/rox_short_motion_test.yaml \
  --output examples/orders/order_rox_diff_v3.json \
  --update-fleet-env configs/fleet_control.env
```

Generate the full case-study order by changing the route to `rox_crane_case_study.yaml`.

The old DBot coordinates/templates remain under `legacy/` only and must never be sent to ROX-Diff.
