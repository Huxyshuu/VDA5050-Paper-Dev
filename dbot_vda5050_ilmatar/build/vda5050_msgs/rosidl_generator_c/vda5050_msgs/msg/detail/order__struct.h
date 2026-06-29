// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vda5050_msgs:msg/Order.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__ORDER__STRUCT_H_
#define VDA5050_MSGS__MSG__DETAIL__ORDER__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'timestamp'
// Member 'version'
// Member 'manufacturer'
// Member 'serial_number'
// Member 'order_id'
// Member 'zone_set_id'
#include "rosidl_runtime_c/string.h"
// Member 'nodes'
#include "vda5050_msgs/msg/detail/node__struct.h"
// Member 'edges'
#include "vda5050_msgs/msg/detail/edge__struct.h"

/// Struct defined in msg/Order in the package vda5050_msgs.
/**
  * HEADER
 */
typedef struct vda5050_msgs__msg__Order
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
  /// Unique order identification
  rosidl_runtime_c__String order_id;
  /// order_update identification. Is unique per order_id. If an order update is
  /// rejected, this field is to be passed in the rejection message
  uint32_t order_update_id;
  /// Unique identifier of the zone set that the AGV has to use for navigation or that was used by master controlfor planning
  /// Optional: Some master controlsystems do not use zones. Some AGVs do not understand zones. Do not add to message if no zones are used
  rosidl_runtime_c__String zone_set_id;
  /// Array of nodes to be traversed for fulfilling the order. The nodes come
  /// in the sequence of the fulfilling.
  vda5050_msgs__msg__Node__Sequence nodes;
  /// Array of edges to be traversed for fulfilling the order
  vda5050_msgs__msg__Edge__Sequence edges;
} vda5050_msgs__msg__Order;

// Struct for a sequence of vda5050_msgs__msg__Order.
typedef struct vda5050_msgs__msg__Order__Sequence
{
  vda5050_msgs__msg__Order * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vda5050_msgs__msg__Order__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VDA5050_MSGS__MSG__DETAIL__ORDER__STRUCT_H_
