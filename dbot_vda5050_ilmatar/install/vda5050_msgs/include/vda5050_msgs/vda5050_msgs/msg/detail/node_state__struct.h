// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vda5050_msgs:msg/NodeState.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__NODE_STATE__STRUCT_H_
#define VDA5050_MSGS__MSG__DETAIL__NODE_STATE__STRUCT_H_

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

/// Struct defined in msg/NodeState in the package vda5050_msgs.
/**
  * Array of nodes to be traversed for fulfilling the order
 */
typedef struct vda5050_msgs__msg__NodeState
{
  /// Unique node identification
  rosidl_runtime_c__String node_id;
  /// sequenceId to discern multiple nodes with same nodeId.
  uint32_t sequence_id;
  /// Additional information on the node
  rosidl_runtime_c__String node_description;
  /// Node position (see Topic: Order)
  vda5050_msgs__msg__NodePosition node_position;
  /// true indicates that the node is part of the base.
  /// false indicates that the node is part of the horizon.
  bool released;
} vda5050_msgs__msg__NodeState;

// Struct for a sequence of vda5050_msgs__msg__NodeState.
typedef struct vda5050_msgs__msg__NodeState__Sequence
{
  vda5050_msgs__msg__NodeState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vda5050_msgs__msg__NodeState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VDA5050_MSGS__MSG__DETAIL__NODE_STATE__STRUCT_H_
