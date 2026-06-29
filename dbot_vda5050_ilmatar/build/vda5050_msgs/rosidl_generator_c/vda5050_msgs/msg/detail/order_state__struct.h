// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vda5050_msgs:msg/OrderState.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__ORDER_STATE__STRUCT_H_
#define VDA5050_MSGS__MSG__DETAIL__ORDER_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'AUTOMATIC'.
/**
  * AGV is under full control of the supervisor. AGV drives and executes actions based on orders from the supervisor
 */
static const char * const vda5050_msgs__msg__OrderState__AUTOMATIC = "AUTOMATIC";

/// Constant 'SEMIAUTOMATIC'.
/**
  * AGV is under control of the supervisor. AGV drives and executes actions based on orders from the supervisor. The driving speeds is controlled by the HMI. (speed can’t exceed the speed of automatic mode) The steering is under automatic control. (non-safe HMI possible)
 */
static const char * const vda5050_msgs__msg__OrderState__SEMIAUTOMATIC = "SEMIAUTOMATIC";

/// Constant 'MANUAL'.
/**
  * Supervisor is not in control of the AGV. Supervisor doesn’t send driving order or actions to the AGV. HMI can be used the control the steering and velocity and handling device of the AGV. Location of the AGV is send to the supervisor. When AGV enters or leaves this mode, it immediately clears all the orders. (safe HMI required)
  * Supervisor is not in control of the AGV. Supervisor doesn’t send driving order or actions to the AGV. Authorized personal can reconfigure the AGV.
 */
static const char * const vda5050_msgs__msg__OrderState__MANUAL = "MANUAL";

/// Constant 'SERVICE'.
/**
  * Supervisor is not in control of the AGV. Supervisor doesn’t send driving order or actions to the AGV. The AGV is being taught, e.g. mapping is done by a supervisor
 */
static const char * const vda5050_msgs__msg__OrderState__SERVICE = "SERVICE";

/// Constant 'TEACHIN'.
static const char * const vda5050_msgs__msg__OrderState__TEACHIN = "TEACHIN";

// Include directives for member types
// Member 'timestamp'
// Member 'version'
// Member 'manufacturer'
// Member 'serial_number'
// Member 'order_id'
// Member 'zone_set_id'
// Member 'last_node_id'
// Member 'operating_mode'
#include "rosidl_runtime_c/string.h"
// Member 'node_states'
#include "vda5050_msgs/msg/detail/node_state__struct.h"
// Member 'edge_states'
#include "vda5050_msgs/msg/detail/edge_state__struct.h"
// Member 'agv_position'
#include "vda5050_msgs/msg/detail/agv_position__struct.h"
// Member 'velocity'
#include "vda5050_msgs/msg/detail/velocity__struct.h"
// Member 'loads'
#include "vda5050_msgs/msg/detail/load__struct.h"
// Member 'action_states'
#include "vda5050_msgs/msg/detail/current_action__struct.h"
// Member 'battery_state'
#include "vda5050_msgs/msg/detail/battery_state__struct.h"
// Member 'errors'
#include "vda5050_msgs/msg/detail/error__struct.h"
// Member 'informations'
#include "vda5050_msgs/msg/detail/info__struct.h"
// Member 'safety_state'
#include "vda5050_msgs/msg/detail/safety_state__struct.h"

/// Struct defined in msg/OrderState in the package vda5050_msgs.
/**
  * HEADER
 */
typedef struct vda5050_msgs__msg__OrderState
{
  /// header ID of the message. The header_id is defined per topic and incremented by 1 with each sent
  /// (but not necessarily received) message.
  uint32_t header_id;
  /// Timestamp after ISO8601 in the format YYYY-MM-DDTHH:mm:ss.ssZ (e.g.“2017-04-15T11:40:03.12Z”)
  rosidl_runtime_c__String timestamp;
  /// Version of the protocol [Major].[Minor].[Patch] (e.g. 1.3.2)
  rosidl_runtime_c__String version;
  /// Manufacturer of the AGV
  rosidl_runtime_c__String manufacturer;
  /// Serial Number of the AGV
  rosidl_runtime_c__String serial_number;
  /// CONTENTS
  /// Unique order identification “none” if vehicle is idle and has no order
  rosidl_runtime_c__String order_id;
  /// order_update identification. Is unique per order_id. If an order update is rejected, this field is to be passed in the rejection message.
  uint32_t order_update_id;
  /// Unique ID of the zone set that the AGV currently uses for path planning. Must be the same as the one used in the order,
  /// otherwise the AGV hasto reject the order. Optional: If the AGV does not use zones, this field can be omitted.
  rosidl_runtime_c__String zone_set_id;
  /// nodeId of last reached node or, if AGV is currently on a node, current node (e.g. „node7”).
  /// Empty string ("") if no lastNodeId is available.
  rosidl_runtime_c__String last_node_id;
  /// sequence_id of the last reached node or, if the AGV is currently on a node, sequence_id of current node.
  /// “0” if no last_node_sequence_id is available.
  uint32_t last_node_sequence_id;
  /// Array of node_state_objects (empty list if idle)
  vda5050_msgs__msg__NodeState__Sequence node_states;
  /// Array of edge_state_objects (empty list if idle)
  vda5050_msgs__msg__EdgeState__Sequence edge_states;
  /// Current position of the AGV. Optional: Can only be omitted for
  /// AGVs without the capability to localize themselves, e.g. line
  /// guided AGVs.
  vda5050_msgs__msg__AGVPosition agv_position;
  /// AGV's velocity in vehicle coordinates
  vda5050_msgs__msg__Velocity velocity;
  /// Loads that are currently handled by the AGV.
  /// Optional: If AGV cannot determine load state, leave the array out of the state.
  /// If the  AGV  can determine the  load  state,  but  the  array  is  empty,  the  AGV  is considered unloaded.
  vda5050_msgs__msg__Load__Sequence loads;
  /// True: indicates that the AGV is driving and/or rotating. Other
  /// movements of the AGV (e.g. lift movements) are not included here.
  /// False: indicates that the AGV is neither driving nor rotating
  bool driving;
  /// True: AGV is currently in a paused state, either because of the push of a physical button on the AGV or
  /// because of an instantAction. The AGV can resume the order.
  /// False: The AGV is currently not in a paused state
  bool paused;
  /// True: AGV is almost at the end of the base and will reduce speed if no new base is transmitted. Trigger for MC to send ne base
  /// False: no base update required
  bool new_base_request;
  /// Used by line guided vehicles to indicate the distance it has been driving past the last_node_id. Distance is in meters
  double distance_since_last_node;
  /// Contains a list of the current actions and the actions which are
  /// yet to be finished. This may include actions from previous nodes
  /// that are still in progress. When an action is completed, an
  /// updated state message is published with action_status set to
  /// finished and if applicable with the corresponding
  /// result_description. Completed actions are omitted from the array
  vda5050_msgs__msg__CurrentAction__Sequence action_states;
  /// Contains all batteryrelated information.
  vda5050_msgs__msg__BatteryState battery_state;
  /// Enum {AUTOMATIC, SEMIAUTOMATIC, MANUAL, SERVICE, TEACHIN}
  /// For additional information see chapter 6.2
  rosidl_runtime_c__String operating_mode;
  /// Array of errorobjects. Empty array if there are no errors.
  vda5050_msgs__msg__Error__Sequence errors;
  /// Array of info-objects. An empty array indicates that the AGV has no information.
  /// This should only be used for visualization or debugging – it must not be used for logic in master control
  vda5050_msgs__msg__Info__Sequence informations;
  /// Contains all safetyrelated information.
  /// Enums for operatingMode
  vda5050_msgs__msg__SafetyState safety_state;
} vda5050_msgs__msg__OrderState;

// Struct for a sequence of vda5050_msgs__msg__OrderState.
typedef struct vda5050_msgs__msg__OrderState__Sequence
{
  vda5050_msgs__msg__OrderState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vda5050_msgs__msg__OrderState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VDA5050_MSGS__MSG__DETAIL__ORDER_STATE__STRUCT_H_
