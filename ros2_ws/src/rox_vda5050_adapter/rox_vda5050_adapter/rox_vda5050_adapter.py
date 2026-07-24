"""VDA 5050 v3.0 MQTT adapter for a Neobotix ROX-Diff running ROS 2/Nav2.

The adapter deliberately talks directly in official VDA 5050 v3 JSON on MQTT.
It does not reuse the legacy DBot v2 ROS message/controller stack. ROS remains an
internal implementation detail on the robot; the fleet control only sees VDA
5050 messages.
"""

from __future__ import annotations

import json
import math
import queue
import threading
import time
from pathlib import Path
from typing import Any, Dict, List, Optional, Tuple

import paho.mqtt.client as mqtt
import rclpy
from action_msgs.msg import GoalStatus
from ament_index_python.packages import get_package_share_directory
from geometry_msgs.msg import PoseWithCovarianceStamped
from nav2_msgs.action import NavigateToPose
from nav_msgs.msg import Odometry
from rclpy.action import ActionClient
from rclpy.node import Node
from rosidl_runtime_py.utilities import get_message
from tf2_ros import Buffer, TransformException, TransformListener

from .vda5050_protocol import (
    HeaderCounter,
    SchemaSet,
    action_parameters,
    build_header,
    nested_value,
    normalize_angle,
)

FINAL_ACTION_STATES = {"FINISHED", "FAILED"}
SUPPORTED_NODE_ACTIONS = {"holdPose", "waitForTrigger", "noop", "noOp"}


class OrderRejected(ValueError):
    """Order-level rejection carrying the VDA error type to report."""

    def __init__(self, error_type: str, description: str, level: str = "WARNING"):
        super().__init__(description)
        self.error_type = error_type
        self.level = level


class RoxVda5050Adapter(Node):
    def __init__(self) -> None:
        super().__init__("rox_vda5050_adapter")
        self._declare_parameters()
        self._read_parameters()

        self._headers = HeaderCounter()
        self._schemas = self._load_schemas()
        self._mqtt_inbox: "queue.Queue[Tuple[str, Dict[str, Any]]]" = queue.Queue()
        self._lock = threading.RLock()

        # Robot / VDA runtime state.
        self._pose: Optional[Dict[str, Any]] = None
        self._velocity = {"vx": 0.0, "vy": 0.0, "omega": 0.0}
        self._power_supply: Dict[str, Any] = {
            "stateOfCharge": 80.0,
            "charging": False,
        }
        self._active_emergency_stop = "NONE"
        self._field_violation = False
        self._triggered_cutoff_paths: List[int] = []
        self._operating_mode = "STARTUP"
        self._errors: List[Dict[str, Any]] = []
        self._information: List[Dict[str, Any]] = []

        self._order: Optional[Dict[str, Any]] = None
        self._order_id = ""
        self._order_update_id = 0
        self._nodes: List[Dict[str, Any]] = []
        self._edges: List[Dict[str, Any]] = []
        self._node_states: List[Dict[str, Any]] = []
        self._edge_states: List[Dict[str, Any]] = []
        self._action_states: List[Dict[str, Any]] = []
        self._instant_action_states: List[Dict[str, Any]] = []
        self._current_node_index = -1
        self._last_node_id = ""
        self._last_node_sequence_id = 0
        self._active_node_action_index = 0
        self._active_hold_action_id: Optional[str] = None
        self._active_wait_action_id: Optional[str] = None
        self._paused = False
        self._driving = False
        self._cancelled = False
        self._dry_run_deadline: Optional[float] = None
        self._dry_run_goal_index: Optional[int] = None
        self._nav_goal_handle = None
        self._nav_goal_index: Optional[int] = None
        self._goal_request_pending = False
        self._resume_goal_index: Optional[int] = None
        self._pending_cancel_action_id: Optional[str] = None

        # ROS interfaces exposed by the Neobotix stack.
        self._tf_buffer = Buffer()
        self._tf_listener = TransformListener(self._tf_buffer, self)
        self._odom_sub = self.create_subscription(
            Odometry, self.odom_topic, self._on_odom, 20
        )
        self._initial_pose_pub = self.create_publisher(
            PoseWithCovarianceStamped, self.initial_pose_topic, 10
        )
        self._nav_client = ActionClient(self, NavigateToPose, self.nav2_action_name)

        # Neobotix battery and safety topics use neo_msgs2. To avoid hard-coding a
        # particular message release, subscribe dynamically after discovering the
        # actual type in the robot graph.
        self._dynamic_subscriptions: Dict[str, Any] = {}
        self._dynamic_topic_handlers = {
            self.battery_topic: self._on_battery_dynamic,
            self.emergency_stop_topic: self._on_emergency_stop_dynamic,
            self.safety_state_topic: self._on_safety_state_dynamic,
        }

        self._mqtt = self._create_mqtt_client()
        self._mqtt.connect_async(self.mqtt_host, self.mqtt_port, self.mqtt_keepalive)
        self._mqtt.loop_start()

        self.create_timer(0.05, self._process_mqtt_inbox)
        self.create_timer(0.1, self._update_pose)
        self.create_timer(1.0, self._discover_dynamic_topics)
        self.create_timer(1.0 / max(self.state_rate_hz, 0.1), self._publish_state)
        self.create_timer(0.05, self._check_dry_run_navigation)

        self.get_logger().info(
            f"ROX-Diff VDA 5050 adapter ready: {self.topic_root} -> {self.mqtt_host}:{self.mqtt_port}"
        )

    # ------------------------------------------------------------------
    # Configuration
    def _declare_parameters(self) -> None:
        defaults = {
            "mqtt_host": "192.168.50.115",
            "mqtt_port": 1883,
            "mqtt_username": "",
            "mqtt_password": "",
            "mqtt_keepalive": 20,
            "interface_name": "vda5050",
            "major_version": "v3",
            "protocol_version": "3.0.0",
            "manufacturer": "neobotix",
            "serial_number": "rox_diff_1",
            "map_id": "df_map",
            "map_version": "1.0",
            "map_frame": "map",
            "base_frame": "base_link",
            "odom_topic": "/odom",
            "battery_topic": "/battery_state",
            "emergency_stop_topic": "/emergency_stop_state",
            "safety_state_topic": "/safety_state",
            "initial_pose_topic": "/initialpose",
            "nav2_action_name": "/navigate_to_pose",
            "state_rate_hz": 2.0,
            "validate_messages": True,
            "schema_package": "vda5050_schemas_v3",
            "schema_directory": "",
            "factsheet_file": "",
            "initial_node_tolerance_m": 0.35,
            "dry_run_navigation": True,
            "dry_run_delay_s": 1.0,
        }
        for name, value in defaults.items():
            self.declare_parameter(name, value)

    def _read_parameters(self) -> None:
        gp = lambda name: self.get_parameter(name).value
        self.mqtt_host = str(gp("mqtt_host"))
        self.mqtt_port = int(gp("mqtt_port"))
        self.mqtt_username = str(gp("mqtt_username"))
        self.mqtt_password = str(gp("mqtt_password"))
        self.mqtt_keepalive = int(gp("mqtt_keepalive"))
        self.interface_name = str(gp("interface_name"))
        self.major_version = str(gp("major_version"))
        self.protocol_version = str(gp("protocol_version"))
        self.manufacturer = str(gp("manufacturer"))
        self.serial_number = str(gp("serial_number"))
        self.map_id = str(gp("map_id"))
        self.map_version = str(gp("map_version"))
        self.map_frame = str(gp("map_frame"))
        self.base_frame = str(gp("base_frame"))
        self.odom_topic = str(gp("odom_topic"))
        self.battery_topic = str(gp("battery_topic"))
        self.emergency_stop_topic = str(gp("emergency_stop_topic"))
        self.safety_state_topic = str(gp("safety_state_topic"))
        self.initial_pose_topic = str(gp("initial_pose_topic"))
        self.nav2_action_name = str(gp("nav2_action_name"))
        self.state_rate_hz = float(gp("state_rate_hz"))
        self.validate_messages = bool(gp("validate_messages"))
        self.schema_package = str(gp("schema_package"))
        self.schema_directory = str(gp("schema_directory"))
        self.factsheet_file = str(gp("factsheet_file"))
        if not self.factsheet_file:
            self.factsheet_file = str(
                Path(get_package_share_directory("rox_vda5050_adapter"))
                / "factsheets"
                / "rox_diff_factsheet.template.json"
            )
        self.initial_node_tolerance_m = float(gp("initial_node_tolerance_m"))
        self.dry_run_navigation = bool(gp("dry_run_navigation"))
        self.dry_run_delay_s = float(gp("dry_run_delay_s"))
        self.topic_root = (
            f"{self.interface_name}/{self.major_version}/"
            f"{self.manufacturer}/{self.serial_number}"
        )

    def _load_schemas(self) -> SchemaSet:
        if self.schema_directory:
            directory = Path(self.schema_directory).expanduser()
        else:
            directory = (
                Path(get_package_share_directory(self.schema_package)) / "schemas"
            )
        schemas = SchemaSet(directory, enabled=self.validate_messages)
        schemas.load(
            [
                "order.schema",
                "state.schema",
                "instantActions.schema",
                "connection.schema",
                "factsheet.schema",
            ]
        )
        return schemas

    # ------------------------------------------------------------------
    # MQTT
    def _create_mqtt_client(self) -> mqtt.Client:
        try:
            client = mqtt.Client(
                mqtt.CallbackAPIVersion.VERSION2,
                client_id=f"rox-vda5050-{self.serial_number}",
                clean_session=True,
            )
        except (AttributeError, TypeError):
            client = mqtt.Client(
                client_id=f"rox-vda5050-{self.serial_number}", clean_session=True
            )
        if self.mqtt_username:
            client.username_pw_set(self.mqtt_username, self.mqtt_password)
        client.on_connect = self._on_mqtt_connect
        client.on_disconnect = self._on_mqtt_disconnect
        client.on_message = self._on_mqtt_message
        broken = self._build_connection("CONNECTION_BROKEN")
        client.will_set(
            f"{self.topic_root}/connection",
            json.dumps(broken),
            qos=1,
            retain=True,
        )
        return client

    def _on_mqtt_connect(self, client, userdata, flags, rc, properties=None) -> None:
        if rc != 0:
            self.get_logger().error(f"MQTT connection failed with rc={rc}")
            return
        client.subscribe(f"{self.topic_root}/order", qos=0)
        client.subscribe(f"{self.topic_root}/instantActions", qos=0)
        self._publish_connection("ONLINE")
        try:
            self._publish_factsheet()
        except Exception as exc:
            self.get_logger().warning(f"Factsheet not published at connect: {exc}")
        self.get_logger().info("MQTT connected; subscribed to order and instantActions")

    def _on_mqtt_disconnect(
        self,
        client,
        userdata,
        disconnect_flags_or_rc,
        reason_code=None,
        properties=None,
    ) -> None:
        # Callback API v1 passes rc directly; v2 passes flags then reason_code.
        rc = disconnect_flags_or_rc if reason_code is None else reason_code
        self.get_logger().warning(f"MQTT disconnected rc={rc}")

    def _on_mqtt_message(self, client, userdata, message) -> None:
        try:
            payload = json.loads(message.payload.decode("utf-8"))
            if not isinstance(payload, dict):
                raise ValueError("payload is not a JSON object")
            self._mqtt_inbox.put((message.topic, payload))
        except Exception as exc:
            self.get_logger().error(f"Invalid MQTT JSON on {message.topic}: {exc}")

    def _process_mqtt_inbox(self) -> None:
        for _ in range(20):
            try:
                topic, payload = self._mqtt_inbox.get_nowait()
            except queue.Empty:
                break
            try:
                if topic.endswith("/order"):
                    self._accept_order(payload)
                elif topic.endswith("/instantActions"):
                    self._handle_instant_actions(payload)
            except Exception as exc:
                self.get_logger().error(f"Failed to process {topic}: {exc}")
                self._add_error("ADAPTER_INTERNAL_ERROR", "CRITICAL", str(exc))

    def _mqtt_publish(
        self, topic_name: str, payload: Dict[str, Any], qos: int = 0, retain: bool = False
    ) -> None:
        self._mqtt.publish(
            f"{self.topic_root}/{topic_name}",
            json.dumps(
                payload,
                separators=(",", ":"),
                allow_nan=False,
            ),
            qos=qos,
            retain=retain,
        )

    # ------------------------------------------------------------------
    # ROS state acquisition
    def _on_odom(self, message: Odometry) -> None:
        with self._lock:
            self._velocity = {
                "vx": float(message.twist.twist.linear.x),
                "vy": float(message.twist.twist.linear.y),
                "omega": float(message.twist.twist.angular.z),
            }

    def _update_pose(self) -> None:
        try:
            transform = self._tf_buffer.lookup_transform(
                self.map_frame, self.base_frame, rclpy.time.Time()
            )
        except TransformException:
            return
        q = transform.transform.rotation
        theta = math.atan2(
            2.0 * (q.w * q.z + q.x * q.y),
            1.0 - 2.0 * (q.y * q.y + q.z * q.z),
        )
        with self._lock:
            self._pose = {
                "x": float(transform.transform.translation.x),
                "y": float(transform.transform.translation.y),
                "theta": normalize_angle(theta),
                "mapId": self.map_id,
                "localized": True,
            }
            if self._operating_mode == "STARTUP":
                self._operating_mode = "AUTOMATIC"

    def _discover_dynamic_topics(self) -> None:
        graph = dict(self.get_topic_names_and_types())
        for topic, callback in self._dynamic_topic_handlers.items():
            if topic in self._dynamic_subscriptions or topic not in graph:
                continue
            type_names = graph[topic]
            if not type_names:
                continue
            try:
                message_type = get_message(type_names[0])
                self._dynamic_subscriptions[topic] = self.create_subscription(
                    message_type, topic, callback, 10
                )
                self.get_logger().info(
                    f"Subscribed dynamically to {topic} ({type_names[0]})"
                )
            except Exception as exc:
                self.get_logger().warning(
                    f"Cannot subscribe to {topic} ({type_names[0]}): {exc}"
                )

    def _on_battery_dynamic(self, message: Any) -> None:
        raw_soc = nested_value(
            message,
            ["state_of_charge", "stateOfCharge", "percentage", "charge"],
            80.0,
        )
        try:
            soc = float(raw_soc)
            if 0.0 <= soc <= 1.0:
                soc *= 100.0
            soc = max(0.0, min(100.0, soc))
        except (TypeError, ValueError):
            soc = 80.0
        charging = bool(
            nested_value(message, ["charging", "is_charging", "isCharging"], False)
        )
        # sensor_msgs/BatteryState exposes an enum instead of a boolean.
        power_supply_status = nested_value(message, ["power_supply_status"], None)
        charging_constant = getattr(message, "POWER_SUPPLY_STATUS_CHARGING", None)
        if power_supply_status is not None and charging_constant is not None:
            charging = int(power_supply_status) == int(charging_constant)
        voltage = nested_value(message, ["voltage", "battery_voltage"], None)
        current = nested_value(message, ["current", "battery_current"], None)
        power: Dict[str, Any] = {"stateOfCharge": soc, "charging": charging}
        for key, raw_value in (
            ("batteryVoltage", voltage),
            ("batteryCurrent", current),
        ):
            if raw_value is None:
                continue

            try:
                numeric_value = float(raw_value)
            except (TypeError, ValueError):
                continue

            # Unknown sensor values are commonly represented as NaN.
            # Omit optional VDA fields instead of publishing invalid JSON.
            if math.isfinite(numeric_value):
                power[key] = numeric_value
        with self._lock:
            self._power_supply = power

    def _on_emergency_stop_dynamic(self, message: Any) -> None:
        remote_stop = bool(
            nested_value(message, ["remote_emergency_stop"], False)
        )
        emergency_button_stop = bool(
            nested_value(message, ["emergency_button_stop"], False)
        )
        software_stop = bool(
            nested_value(message, ["software_stop"], False)
        )
        scanner_stop = bool(
            nested_value(message, ["scanner_stop"], False)
        )

        # VDA 5050 activeEmergencyStop represents an actual emergency stop.
        if remote_stop:
            mapped = "REMOTE"
        elif emergency_button_stop or software_stop:
            mapped = "MANUAL"
        else:
            mapped = "NONE"

        with self._lock:
            self._active_emergency_stop = mapped

            # A protective scanner stop maps to VDA 5050 fieldViolation.
            self._field_violation = scanner_stop

            if mapped != "NONE":
                self._operating_mode = "INTERVENED"
            elif self._pose is not None and self._operating_mode == "INTERVENED":
                self._operating_mode = "AUTOMATIC"

    def _on_safety_state_dynamic(self, message: Any) -> None:
        paths = nested_value(message, ["triggered_cutoff_paths"], []) or []

        triggered_paths = [
            index
            for index, triggered in enumerate(paths)
            if bool(triggered)
        ]

        # These paths are retained for diagnostics only. Their exact meanings
        # depend on the site-specific FlexiSoft/scanner configuration.
        with self._lock:
            self._triggered_cutoff_paths = triggered_paths

    # ------------------------------------------------------------------
    # Order handling
    def _accept_order(self, payload: Dict[str, Any]) -> None:
        try:
            self._schemas.validate("order.schema", payload)
        except Exception as exc:
            self._add_error("ORDER_VALIDATION_ERROR", "WARNING", str(exc))
            return
        if not self._identity_matches(payload):
            self._add_error("ORDER_IDENTITY_MISMATCH", "WARNING", "Order identity does not match this ROX-Diff adapter")
            return
        if self._order_active():
            self._add_error("ORDER_REJECTED_BUSY", "WARNING", "A different order is already active")
            return
        if int(payload.get("orderUpdateId", 0)) != 0:
            self._add_error("ORDER_UPDATE_UNSUPPORTED", "WARNING", "This first migration version accepts only new orders with orderUpdateId 0")
            return

        nodes = sorted(payload.get("nodes", []), key=lambda item: item["sequenceId"])
        edges = sorted(payload.get("edges", []), key=lambda item: item["sequenceId"])
        try:
            self._validate_order_semantics(nodes, edges)
        except OrderRejected as exc:
            self._add_error(exc.error_type, exc.level, str(exc))
            return
        with self._lock:
            self._order = payload
            self._order_id = str(payload["orderId"])
            self._order_update_id = int(payload["orderUpdateId"])
            self._nodes = nodes
            self._edges = edges
            self._node_states = [self._node_to_state(node) for node in nodes]
            self._edge_states = [self._edge_to_state(edge) for edge in edges]
            self._action_states = [
                self._new_action_state(action, "WAITING")
                for node in nodes
                for action in node.get("actions", []) or []
            ] + [
                self._new_action_state(action, "WAITING")
                for edge in edges
                for action in edge.get("actions", []) or []
            ]
            self._current_node_index = -1
            self._active_node_action_index = 0
            self._active_hold_action_id = None
            self._active_wait_action_id = None
            self._paused = False
            self._cancelled = False
            self._errors = []
        self.get_logger().info(
            f"Accepted order {self._order_id} with {len(nodes)} nodes"
        )
        # VDA 5050 requires the first node to be trivially reachable and it shall
        # not be reported in nodeStates. The semantic validation above enforces
        # that condition on real hardware; dry-run mode deliberately assumes it.
        self._on_node_reached(0)

    def _validate_order_semantics(
        self, nodes: List[Dict[str, Any]], edges: List[Dict[str, Any]]
    ) -> None:
        if not nodes:
            raise OrderRejected("VALIDATION_FAILURE", "Order has no nodes")
        if len(edges) != len(nodes) - 1:
            raise OrderRejected(
                "VALIDATION_FAILURE",
                f"Expected {len(nodes) - 1} edges for {len(nodes)} nodes, got {len(edges)}",
            )

        ordered_items = sorted(
            [(int(node["sequenceId"]), "node") for node in nodes]
            + [(int(edge["sequenceId"]), "edge") for edge in edges]
        )
        sequence_ids = [item[0] for item in ordered_items]
        if sequence_ids != list(range(len(ordered_items))):
            raise OrderRejected(
                "VALIDATION_FAILURE",
                f"sequenceId values must be continuous from 0; got {sequence_ids}",
            )
        if int(nodes[0]["sequenceId"]) != 0 or not bool(nodes[0]["released"]):
            raise OrderRejected(
                "VALIDATION_FAILURE",
                "The first node must have sequenceId 0 and released=true",
            )
        if any(int(node["sequenceId"]) % 2 != 0 for node in nodes):
            raise OrderRejected(
                "VALIDATION_FAILURE",
                "Node sequenceId values must be even (0, 2, 4, ...)",
            )
        if any(int(edge["sequenceId"]) % 2 != 1 for edge in edges):
            raise OrderRejected(
                "VALIDATION_FAILURE",
                "Edge sequenceId values must be odd (1, 3, 5, ...)",
            )

        for node in nodes:
            position = node.get("nodePosition")
            if not isinstance(position, dict):
                raise OrderRejected(
                    "UNSUPPORTED_PARAMETER",
                    f"Node {node['nodeId']} has no nodePosition; this Nav2 adapter requires positions",
                    "CRITICAL",
                )
            if str(position.get("mapId")) != self.map_id:
                raise OrderRejected(
                    "UNKNOWN_MAP_ID",
                    f"Node {node['nodeId']} references mapId={position.get('mapId')!r}; enabled map is {self.map_id!r}",
                )
            for action in node.get("actions", []) or []:
                if str(action.get("actionType")) not in SUPPORTED_NODE_ACTIONS:
                    raise OrderRejected(
                        "INVALID_ORDER_ACTION",
                        f"Unsupported node action {action.get('actionType')!r} in node {node['nodeId']}",
                    )

        for edge in edges:
            if edge.get("actions"):
                raise OrderRejected(
                    "INVALID_ORDER_ACTION",
                    f"Edge actions are not implemented in this migration version ({edge['edgeId']})",
                )

        # In dry-run mode there may be no localization/TF source, so explicitly
        # assume that the first node is the current pose. Real navigation remains
        # strict and rejects an order if localization is missing or out of range.
        if self.dry_run_navigation:
            return
        if self._pose is None:
            raise OrderRejected(
                "LOCALIZATION_ERROR",
                "No map-to-base transform is available; localize the ROX-Diff before sending an order",
                "FATAL",
            )

        first_position = nodes[0]["nodePosition"]
        distance = math.hypot(
            float(first_position["x"]) - float(self._pose["x"]),
            float(first_position["y"]) - float(self._pose["y"]),
        )
        allowed = self.initial_node_tolerance_m
        deviation = first_position.get("allowedDeviationXY")
        if isinstance(deviation, dict):
            try:
                allowed = max(allowed, float(deviation.get("a", 0.0)), float(deviation.get("b", 0.0)))
            except (TypeError, ValueError):
                pass
        if distance > allowed:
            raise OrderRejected(
                "START_NODE_OUT_OF_RANGE",
                f"ROX-Diff is {distance:.3f} m from first node {nodes[0]['nodeId']}; allowed {allowed:.3f} m",
            )

    def _identity_matches(self, payload: Dict[str, Any]) -> bool:
        return (
            str(payload.get("manufacturer")) == self.manufacturer
            and str(payload.get("serialNumber")) == self.serial_number
            and str(payload.get("version")) == self.protocol_version
        )

    def _order_active(self) -> bool:
        if self._order is None:
            return False
        if self._node_states or self._edge_states:
            return True
        return any(
            state.get("actionStatus") not in FINAL_ACTION_STATES
            for state in self._action_states
        )

    def _start_or_reach_node(self, index: int) -> None:
        if self._paused or self._cancelled or index >= len(self._nodes):
            return
        node = self._nodes[index]
        position = node.get("nodePosition")
        if position is None:
            self._add_error("NODE_POSITION_MISSING", "CRITICAL", f"Node {node['nodeId']} has no position")
            return
        self._navigate_to_node(index)

    def _navigate_to_node(self, index: int) -> None:
        if self._paused or self._cancelled:
            return
        node = self._nodes[index]
        position = node["nodePosition"]
        self._nav_goal_index = index
        self._driving = True
        if self.dry_run_navigation:
            self._dry_run_goal_index = index
            self._dry_run_deadline = time.monotonic() + self.dry_run_delay_s
            self.get_logger().info(f"Dry-run navigation to {node['nodeId']}")
            return
        if not self._nav_client.wait_for_server(timeout_sec=2.0):
            self._driving = False
            self._add_error("NAV2_SERVER_UNAVAILABLE", "CRITICAL", f"Action server {self.nav2_action_name} is not available")
            return

        goal = NavigateToPose.Goal()
        goal.pose.header.frame_id = self.map_frame
        goal.pose.header.stamp = self.get_clock().now().to_msg()
        goal.pose.pose.position.x = float(position["x"])
        goal.pose.pose.position.y = float(position["y"])
        theta = float(position.get("theta", 0.0))
        goal.pose.pose.orientation.z = math.sin(theta / 2.0)
        goal.pose.pose.orientation.w = math.cos(theta / 2.0)

        self._goal_request_pending = True
        future = self._nav_client.send_goal_async(goal)
        future.add_done_callback(lambda result, idx=index: self._on_goal_response(result, idx))

    def _on_goal_response(self, future, index: int) -> None:
        self._goal_request_pending = False
        try:
            goal_handle = future.result()
        except Exception as exc:
            self._driving = False
            self._add_error(
                "NAV2_GOAL_REQUEST_FAILED",
                "CRITICAL",
                f"Nav2 goal request for {self._nodes[index]['nodeId']} failed: {exc}",
            )
            if self._cancelled:
                self._finish_pending_cancel()
            return
        if not goal_handle.accepted:
            self._driving = False
            if self._cancelled:
                self._finish_pending_cancel()
            else:
                self._add_error(
                    "NAV2_GOAL_REJECTED",
                    "CRITICAL",
                    f"Nav2 rejected node {self._nodes[index]['nodeId']}",
                )
            return
        self._nav_goal_handle = goal_handle
        result_future = goal_handle.get_result_async()
        result_future.add_done_callback(lambda result, idx=index: self._on_nav_result(result, idx))

        # A pause or cancel can arrive while the asynchronous goal request is in
        # flight. Cancel immediately after acceptance so a late callback cannot
        # start unintended robot motion.
        if self._cancelled or self._paused:
            if self._paused:
                self._resume_goal_index = index
            goal_handle.cancel_goal_async()

    def _on_nav_result(self, future, index: int) -> None:
        self._nav_goal_handle = None
        self._driving = False
        try:
            wrapped = future.result()
        except Exception as exc:
            if self._cancelled:
                self._finish_pending_cancel()
            else:
                self._add_error(
                    "NAV2_RESULT_FAILED",
                    "CRITICAL",
                    f"Could not obtain Nav2 result for {self._nodes[index]['nodeId']}: {exc}",
                )
            return
        if self._cancelled:
            self._finish_pending_cancel()
        elif wrapped.status == GoalStatus.STATUS_SUCCEEDED:
            self._on_node_reached(index)
        elif self._paused:
            self._resume_goal_index = index
        elif not self._cancelled:
            self._add_error("NAVIGATION_FAILED", "CRITICAL", f"Navigation to {self._nodes[index]['nodeId']} ended with status {wrapped.status}")

    def _check_dry_run_navigation(self) -> None:
        if self._dry_run_deadline is None or time.monotonic() < self._dry_run_deadline:
            return
        index = self._dry_run_goal_index
        self._dry_run_deadline = None
        self._dry_run_goal_index = None
        self._driving = False
        if index is not None and not self._paused and not self._cancelled:
            self._on_node_reached(index)

    def _on_node_reached(self, index: int) -> None:
        if self._cancelled:
            return
        node = self._nodes[index]
        with self._lock:
            self._current_node_index = index
            self._last_node_id = str(node["nodeId"])
            self._last_node_sequence_id = int(node["sequenceId"])
            self._active_node_action_index = 0
            self._node_states = [
                state for state in self._node_states if state["sequenceId"] > node["sequenceId"]
            ]
            self._edge_states = [
                state for state in self._edge_states if state["sequenceId"] > node["sequenceId"]
            ]
        self.get_logger().info(f"Reached VDA node {node['nodeId']}")
        self._execute_next_node_action()

    def _execute_next_node_action(self) -> None:
        if self._paused or self._cancelled or self._current_node_index < 0:
            return
        node = self._nodes[self._current_node_index]
        actions = node.get("actions", []) or []
        if self._active_node_action_index >= len(actions):
            next_index = self._current_node_index + 1
            if next_index < len(self._nodes):
                self._start_or_reach_node(next_index)
            else:
                self.get_logger().info(f"Order {self._order_id} completed")
            return

        action = actions[self._active_node_action_index]
        action_id = str(action["actionId"])
        action_type = str(action["actionType"])
        self._set_action_status(action_id, "INITIALIZING")
        if action_type == "holdPose":
            self._active_hold_action_id = action_id
            self._set_action_status(action_id, "RUNNING")
            self.get_logger().info(f"holdPose active at {node['nodeId']}")
        elif action_type == "waitForTrigger":
            self._active_wait_action_id = action_id
            self._set_action_status(action_id, "RUNNING")
        elif action_type in {"noop", "noOp"}:
            self._finish_current_node_action("FINISHED", "No operation")
        else:
            target = "RETRIABLE" if bool(action.get("retriable", False)) else "FAILED"
            self._set_action_status(action_id, target, f"Unsupported ROX-Diff action {action_type}")
            self._add_error("UNSUPPORTED_ACTION", "CRITICAL", f"Unsupported order action {action_type}", action_id=action_id)

    def _finish_current_node_action(self, status: str, result: str = "") -> None:
        node = self._nodes[self._current_node_index]
        actions = node.get("actions", []) or []
        if self._active_node_action_index >= len(actions):
            return
        action_id = str(actions[self._active_node_action_index]["actionId"])
        self._set_action_status(action_id, status, result)
        if status == "FINISHED":
            self._active_node_action_index += 1
            self._execute_next_node_action()

    # ------------------------------------------------------------------
    # Instant actions
    def _handle_instant_actions(self, payload: Dict[str, Any]) -> None:
        try:
            self._schemas.validate("instantActions.schema", payload)
        except Exception as exc:
            self._add_error("INSTANT_ACTION_VALIDATION_ERROR", "WARNING", str(exc))
            return
        if not self._identity_matches(payload):
            self._add_error("INSTANT_ACTION_IDENTITY_MISMATCH", "WARNING", "Instant action identity does not match this adapter")
            return
        for action in payload.get("actions", []):
            self._run_instant_action(action)

    def _run_instant_action(self, action: Dict[str, Any]) -> None:
        action_id = str(action["actionId"])
        action_type = str(action["actionType"])
        params = action_parameters(action)
        self._upsert_instant_action_state(action, "RUNNING")
        finish_immediately = True
        try:
            if action_type == "startPause":
                self._pause_order()
            elif action_type == "stopPause":
                self._resume_order()
            elif action_type == "cancelOrder":
                requested_order = params.get("orderId")
                if requested_order and requested_order != self._order_id:
                    raise ValueError(f"cancelOrder refers to {requested_order}, active order is {self._order_id}")
                finish_immediately = self._cancel_order(action_id)
            elif action_type == "initializePosition":
                self._initialize_position(params)
            elif action_type == "releaseHold":
                self._release_hold()
            elif action_type == "trigger":
                self._trigger_wait(params)
            elif action_type == "factsheetRequest":
                self._publish_factsheet()
            elif action_type == "retry":
                self._retry_action(params)
            elif action_type == "skipRetry":
                self._skip_retry(params)
            else:
                raise ValueError(f"Unsupported instant action {action_type}")
            if finish_immediately:
                self._set_instant_action_status(action_id, "FINISHED")
        except Exception as exc:
            self._set_instant_action_status(action_id, "FAILED", str(exc))
            self._add_error("INSTANT_ACTION_FAILED", "WARNING", str(exc), action_id=action_id)

    def _pause_order(self) -> None:
        self._paused = True
        self._driving = False
        if self._dry_run_goal_index is not None:
            self._resume_goal_index = self._dry_run_goal_index
            self._dry_run_goal_index = None
            self._dry_run_deadline = None
        elif self._nav_goal_handle is not None or self._goal_request_pending:
            self._resume_goal_index = self._nav_goal_index
            if self._nav_goal_handle is not None:
                self._nav_goal_handle.cancel_goal_async()
        if self._active_hold_action_id:
            self._set_action_status(self._active_hold_action_id, "PAUSED")
        if self._active_wait_action_id:
            self._set_action_status(self._active_wait_action_id, "PAUSED")

    def _resume_order(self) -> None:
        self._paused = False
        if self._active_hold_action_id:
            self._set_action_status(self._active_hold_action_id, "RUNNING")
        elif self._active_wait_action_id:
            self._set_action_status(self._active_wait_action_id, "RUNNING")
        elif self._resume_goal_index is not None:
            index = self._resume_goal_index
            self._resume_goal_index = None
            self._navigate_to_node(index)

    def _cancel_order(self, instant_action_id: str) -> bool:
        if not self._order_active():
            self._add_error(
                "NO_ORDER_TO_CANCEL",
                "WARNING",
                "cancelOrder received while no order is active",
                action_id=instant_action_id,
            )
            raise ValueError("No active order to cancel")
        self._cancelled = True
        self._paused = False
        self._driving = False
        nav_cancel_pending = self._nav_goal_handle is not None or self._goal_request_pending
        if nav_cancel_pending:
            self._pending_cancel_action_id = instant_action_id
            if self._nav_goal_handle is not None:
                self._nav_goal_handle.cancel_goal_async()
        self._dry_run_deadline = None
        self._node_states = []
        self._edge_states = []
        for state in self._action_states:
            if state.get("actionStatus") not in FINAL_ACTION_STATES:
                state["actionStatus"] = "FAILED"
                state["actionResult"] = "Order cancelled"
        self._active_hold_action_id = None
        self._active_wait_action_id = None
        return not nav_cancel_pending

    def _finish_pending_cancel(self) -> None:
        if self._pending_cancel_action_id:
            self._set_instant_action_status(
                self._pending_cancel_action_id,
                "FINISHED",
                "Order motion and actions stopped",
            )
            self._pending_cancel_action_id = None

    def _retry_action(self, params: Dict[str, Any]) -> None:
        action_id = str(params.get("actionId", ""))
        if not action_id:
            raise ValueError("retry requires actionId")
        state = next(
            (item for item in self._action_states if item.get("actionId") == action_id),
            None,
        )
        if state is None or state.get("actionStatus") != "RETRIABLE":
            raise ValueError(f"Action {action_id!r} is not in RETRIABLE state")
        if self._current_node_index < 0:
            raise ValueError("No active node action can be retried")
        actions = self._nodes[self._current_node_index].get("actions", []) or []
        if self._active_node_action_index >= len(actions) or str(
            actions[self._active_node_action_index].get("actionId")
        ) != action_id:
            raise ValueError("Only the currently blocked node action can be retried")
        self._set_action_status(action_id, "WAITING", "Retry requested")
        self._execute_next_node_action()

    def _skip_retry(self, params: Dict[str, Any]) -> None:
        action_id = str(params.get("actionId", ""))
        if not action_id:
            raise ValueError("skipRetry requires actionId")
        state = next(
            (item for item in self._action_states if item.get("actionId") == action_id),
            None,
        )
        if state is None or state.get("actionStatus") != "RETRIABLE":
            raise ValueError(f"Action {action_id!r} is not in RETRIABLE state")
        self._set_action_status(action_id, "FAILED", "Retry skipped by fleet control")
        if self._current_node_index >= 0:
            actions = self._nodes[self._current_node_index].get("actions", []) or []
            if self._active_node_action_index < len(actions) and str(
                actions[self._active_node_action_index].get("actionId")
            ) == action_id:
                self._active_node_action_index += 1
                self._execute_next_node_action()

    def _initialize_position(self, params: Dict[str, Any]) -> None:
        required = ["x", "y", "theta", "mapId"]
        missing = [name for name in required if name not in params]
        if missing:
            raise ValueError(f"initializePosition missing {missing}")
        requested_map_id = str(params["mapId"])
        if requested_map_id != self.map_id:
            raise ValueError(
                f"initializePosition mapId={requested_map_id!r} does not match "
                f"enabled mapId={self.map_id!r}"
            )
        message = PoseWithCovarianceStamped()
        # mapId is a VDA logical identifier; frame_id must be the ROS TF frame.
        message.header.frame_id = self.map_frame
        message.header.stamp = self.get_clock().now().to_msg()
        message.pose.pose.position.x = float(params["x"])
        message.pose.pose.position.y = float(params["y"])
        theta = float(params["theta"])
        message.pose.pose.orientation.z = math.sin(theta / 2.0)
        message.pose.pose.orientation.w = math.cos(theta / 2.0)
        # Moderate initial covariance; tune for the localization system in use.
        message.pose.covariance[0] = 0.25
        message.pose.covariance[7] = 0.25
        message.pose.covariance[35] = 0.0685
        self._initial_pose_pub.publish(message)
        self._last_node_id = str(params.get("lastNodeId", ""))
        try:
            self._last_node_sequence_id = int(params.get("lastNodeSequenceId", 0))
        except (TypeError, ValueError):
            self._last_node_sequence_id = 0

    def _release_hold(self) -> None:
        if not self._active_hold_action_id:
            raise ValueError("No holdPose action is active")
        self._set_action_status(self._active_hold_action_id, "FINISHED", "Released by fleet control")
        self._active_hold_action_id = None
        self._active_node_action_index += 1
        self._execute_next_node_action()

    def _trigger_wait(self, params: Dict[str, Any]) -> None:
        if not self._active_wait_action_id:
            raise ValueError("No waitForTrigger action is active")
        requested = params.get("actionId") or params.get("triggeredActionId")
        if requested and str(requested) != self._active_wait_action_id:
            raise ValueError(f"Trigger actionId {requested} does not match active wait {self._active_wait_action_id}")
        self._set_action_status(self._active_wait_action_id, "FINISHED", "External trigger received")
        self._active_wait_action_id = None
        self._active_node_action_index += 1
        self._execute_next_node_action()

    # ------------------------------------------------------------------
    # VDA message construction
    def _node_to_state(self, node: Dict[str, Any]) -> Dict[str, Any]:
        result = {
            "nodeId": node["nodeId"],
            "sequenceId": node["sequenceId"],
            "released": node["released"],
        }
        if "nodeDescriptor" in node:
            result["nodeDescriptor"] = node["nodeDescriptor"]
        if "nodePosition" in node:
            p = node["nodePosition"]
            result["nodePosition"] = {
                key: p[key] for key in ("x", "y", "theta", "mapId") if key in p
            }
        return result

    def _edge_to_state(self, edge: Dict[str, Any]) -> Dict[str, Any]:
        result = {
            "edgeId": edge["edgeId"],
            "sequenceId": edge["sequenceId"],
            "released": edge["released"],
        }
        if "edgeDescriptor" in edge:
            result["edgeDescriptor"] = edge["edgeDescriptor"]
        if "trajectory" in edge:
            result["trajectory"] = edge["trajectory"]
        return result

    def _new_action_state(self, action: Dict[str, Any], status: str) -> Dict[str, Any]:
        state = {
            "actionId": str(action["actionId"]),
            "actionType": str(action["actionType"]),
            "actionStatus": status,
        }
        if "actionDescriptor" in action:
            state["actionDescriptor"] = action["actionDescriptor"]
        return state

    def _set_action_status(self, action_id: str, status: str, result: str = "") -> None:
        for state in self._action_states:
            if state.get("actionId") == action_id:
                state["actionStatus"] = status
                if result:
                    state["actionResult"] = result
                return

    def _upsert_instant_action_state(self, action: Dict[str, Any], status: str) -> None:
        existing = next(
            (item for item in self._instant_action_states if item["actionId"] == action["actionId"]),
            None,
        )
        if existing:
            existing["actionStatus"] = status
        else:
            self._instant_action_states.append(self._new_action_state(action, status))

    def _set_instant_action_status(self, action_id: str, status: str, result: str = "") -> None:
        for state in self._instant_action_states:
            if state["actionId"] == action_id:
                state["actionStatus"] = status
                if result:
                    state["actionResult"] = result
                return

    def _add_error(
        self,
        error_type: str,
        level: str,
        description: str,
        action_id: Optional[str] = None,
    ) -> None:
        error: Dict[str, Any] = {
            "errorType": error_type,
            "errorLevel": level,
            "errorDescription": description[:1000],
        }
        if action_id:
            error["errorReferences"] = [
                {"referenceKey": "actionId", "referenceValue": action_id}
            ]
        self._errors = [item for item in self._errors if item.get("errorType") != error_type]
        self._errors.append(error)
        self.get_logger().error(f"{error_type}: {description}")

    def _build_connection(self, state: str) -> Dict[str, Any]:
        payload = build_header(
            self._headers,
            "connection",
            self.protocol_version,
            self.manufacturer,
            self.serial_number,
        )
        payload["connectionState"] = state
        return payload

    def _publish_connection(self, state: str) -> None:
        payload = self._build_connection(state)
        self._schemas.validate("connection.schema", payload)
        self._mqtt_publish("connection", payload, qos=1, retain=True)

    def _publish_state(self) -> None:
        with self._lock:
            payload = build_header(
                self._headers,
                "state",
                self.protocol_version,
                self.manufacturer,
                self.serial_number,
            )
            payload.update(
                {
                    "orderId": self._order_id,
                    "orderUpdateId": self._order_update_id,
                    "lastNodeId": self._last_node_id,
                    "lastNodeSequenceId": self._last_node_sequence_id,
                    "nodeStates": list(self._node_states),
                    "edgeStates": list(self._edge_states),
                    "driving": bool(self._driving),
                    "paused": bool(self._paused),
                    "actionStates": list(self._action_states),
                    "instantActionStates": list(self._instant_action_states),
                    "powerSupply": dict(self._power_supply),
                    "operatingMode": self._operating_mode,
                    "errors": list(self._errors),
                    "safetyState": {
                        "activeEmergencyStop": self._active_emergency_stop,
                        "fieldViolation": bool(self._field_violation),
                    },
                    "maps": [
                        {
                            "mapId": self.map_id,
                            "mapVersion": self.map_version,
                            "mapDescriptor": self.map_frame,
                            "mapStatus": "ENABLED",
                        }
                    ],
                }
            )
            if self._pose is not None:
                payload["mobileRobotPosition"] = dict(self._pose)
                payload["velocity"] = dict(self._velocity)
        try:
            self._schemas.validate("state.schema", payload)
        except Exception as exc:
            self.get_logger().error(f"Refusing invalid state message: {exc}")
            return
        self._mqtt_publish("state", payload)

    def _publish_factsheet(self) -> None:
        if not self.factsheet_file:
            raise ValueError("factsheet_file is not configured")
        path = Path(self.factsheet_file).expanduser()
        with path.open("r", encoding="utf-8") as handle:
            payload = json.load(handle)
        payload.update(
            build_header(
                self._headers,
                "factsheet",
                self.protocol_version,
                self.manufacturer,
                self.serial_number,
            )
        )
        self._schemas.validate("factsheet.schema", payload)
        # VDA 5050 requires factsheet messages to be retained.
        self._mqtt_publish("factsheet", payload, retain=True)

    def destroy_node(self) -> bool:
        try:
            if self._mqtt.is_connected():
                self._publish_connection("OFFLINE")
                time.sleep(0.1)
        finally:
            self._mqtt.loop_stop()
            self._mqtt.disconnect()
        return super().destroy_node()


def main(args=None) -> None:
    rclpy.init(args=args)
    node = RoxVda5050Adapter()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()
