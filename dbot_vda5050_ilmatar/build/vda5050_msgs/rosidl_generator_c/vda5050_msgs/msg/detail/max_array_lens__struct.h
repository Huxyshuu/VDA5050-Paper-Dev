// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vda5050_msgs:msg/MaxArrayLens.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__MAX_ARRAY_LENS__STRUCT_H_
#define VDA5050_MSGS__MSG__DETAIL__MAX_ARRAY_LENS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/MaxArrayLens in the package vda5050_msgs.
typedef struct vda5050_msgs__msg__MaxArrayLens
{
  /// Maximum number of nodes per order processable by the AGV
  uint32_t order_nodes;
  /// Maximum number of edges per order processable by the AGV
  uint32_t order_edges;
  /// Maximum number of action per node processable by the AGV
  uint32_t node_actions;
  /// Maximum number of action per edge processable by the AGV
  uint32_t edge_actions;
  /// Maximum number of parameters per action processable by the AGV
  uint32_t actions_parameters;
  /// Maximum number of instant actions per message processable by the AGV
  uint32_t instant_actions;
  /// Maximum number of knots per trajectory processable by the AGV
  uint32_t trajectory_knot_vector;
  /// Maximum number of control points per trajectory processable by the AGV
  uint32_t trajectory_control_points;
  /// Maximum number of nodeStates sent by the AGV, maximum number of nodes in base of AGV
  uint32_t state_node_states;
  /// Maximum number of edgeStates sent by the AGV, maximum number of edges in base of AGV
  uint32_t state_edge_states;
  /// Maximum number of load-objects sent by the AGV
  uint32_t state_loads;
  /// Maximum number of actionStates sent by the AGV
  uint32_t state_action_states;
  /// Maximum number of errors sent by the AGV in one state-message
  uint32_t state_errors;
  /// Maximum number of information objects sent by the AGV in one state-message
  uint32_t state_information;
  /// Maximum number of error references sent by the AGV for each error
  uint32_t error_references;
  /// Maximum number of info references sent by the AGV for each information
  uint32_t info_references;
} vda5050_msgs__msg__MaxArrayLens;

// Struct for a sequence of vda5050_msgs__msg__MaxArrayLens.
typedef struct vda5050_msgs__msg__MaxArrayLens__Sequence
{
  vda5050_msgs__msg__MaxArrayLens * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vda5050_msgs__msg__MaxArrayLens__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VDA5050_MSGS__MSG__DETAIL__MAX_ARRAY_LENS__STRUCT_H_
