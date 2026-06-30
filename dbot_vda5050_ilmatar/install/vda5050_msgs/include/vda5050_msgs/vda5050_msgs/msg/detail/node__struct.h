// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vda5050_msgs:msg/Node.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__NODE__STRUCT_H_
#define VDA5050_MSGS__MSG__DETAIL__NODE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'node_id'
// Member 'node_description'
#include "rosidl_runtime_c/string.h"
// Member 'node_position'
#include "vda5050_msgs/msg/detail/node_position__struct.h"
// Member 'actions'
#include "vda5050_msgs/msg/detail/action__struct.h"

/// Struct defined in msg/Node in the package vda5050_msgs.
/**
  * Array of nodes to be traversed for fulfilling the order
 */
typedef struct vda5050_msgs__msg__Node
{
  /// Unique node identification.
  rosidl_runtime_c__String node_id;
  /// Id to track the sequence of nodes and edges in an order and to
  /// simplify order updates. The variable sequence_id runs across all
  /// nodes and edges of the same order and is reset when a new order_id is
  /// issued.
  uint32_t sequence_id;
  /// Additional information on the node
  rosidl_runtime_c__String node_description;
  /// True indicates that the node is part of the base. False indicates
  /// that the node is part of the horizon.
  bool released;
  /// Node position
  vda5050_msgs__msg__NodePosition node_position;
  /// Array of actions to be executed in node. Empty array if no actions
  /// required. An action triggered by a node will persist until changed
  /// in another node unless restricted by duration_type/duration_value.
  vda5050_msgs__msg__Action__Sequence actions;
} vda5050_msgs__msg__Node;

// Struct for a sequence of vda5050_msgs__msg__Node.
typedef struct vda5050_msgs__msg__Node__Sequence
{
  vda5050_msgs__msg__Node * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vda5050_msgs__msg__Node__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VDA5050_MSGS__MSG__DETAIL__NODE__STRUCT_H_
