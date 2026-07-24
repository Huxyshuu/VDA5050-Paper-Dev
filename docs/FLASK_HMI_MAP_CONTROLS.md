# Interactive Flask HMI map controls

The occupancy-map panel uses one canvas compositor. The occupancy image is drawn first, followed by the logical VDA route, waypoint markers, and the ROX-Diff marker. These controls change only the browser view; they do not alter the ROS `map` frame, AMCL/Nav2 localization, waypoint coordinates, `mapId`, or VDA 5050 orders.

## Single map layer

The HMI keeps exactly one `#mapCanvas` inside the map area. On startup and before rendering, it removes any legacy map image or extra canvas that may remain from an older dashboard version. Every frame is cleared completely before the map and overlays are redrawn.

Rendering is scheduled through `requestAnimationFrame`, so the 2 Hz dashboard poll, browser resize events, pointer movement, and map-image loading cannot create competing map frames.

## Default landscape view

The map viewport uses a desktop `16:9` layout. On first load, the HMI inspects the map dimensions:

- a portrait map is rotated 90 degrees clockwise so its long side is horizontal;
- an already-landscape map remains at 0 degrees;
- the robot and relevant waypoints are fitted into the view.

The **Reset** button returns to this landscape default and fits the complete occupancy image.

Map-view storage uses `vda5050-map-view-v4`, so the first load after this update intentionally starts from a clean view. Subsequent pan, zoom, and rotation settings remain persistent in the browser.

## Mouse and touch controls

- Drag with the mouse or one finger to pan.
- Use the mouse wheel or a two-finger pinch to zoom around the pointer.
- Use a two-finger twist to rotate on touch hardware.
- Double-click to center the view on ROX-Diff.
- Focus the canvas and use `+` / `-` to zoom, `Shift+Left` / `Shift+Right` to rotate, and `0` to restore the landscape default.

## Toolbar

- **− / +**: zoom out or in.
- **↶ / ↷**: rotate by 15 degrees.
- **Center robot**: place the current robot pose at the middle while preserving zoom and rotation.
- **Robot + all**: center on the robot and zoom out sufficiently to keep the robot, all waypoints, and the current command chain visible.
- **Reset**: restore the automatic landscape orientation and fit the complete map.

The lower-right readout shows relative zoom and visual rotation.

## Dashboard refresh rate

The dashboard polls `/api/dashboard` every 500 ms, providing a 2 Hz pose and mission-state update rate. Poll requests are serialized: the next timer starts only after the current request finishes, so slow responses cannot create overlapping fetches.

ROS, Nav2, MQTT, and safety control loops continue independently at their own rates.

## Persistence

The browser stores these values in `localStorage`, keyed by map identity and revision:

- zoom;
- rotation;
- normalized pan position.

Nothing is written to the Raspberry Pi configuration or Git repository.

## Coordinate fallback

When the occupancy image is unavailable, the same controls work over a coordinate-grid fallback. The map files should normally be present in:

```text
configs/maps/df_map.yaml
configs/maps/df_map.pgm
```

with:

```dotenv
FLEET_UI_MAP_YAML=configs/maps/df_map.yaml
```
