// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vda5050_msgs:msg/Action.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__ACTION__STRUCT_H_
#define VDA5050_MSGS__MSG__DETAIL__ACTION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'NONE'.
/**
  * Enums for blockingType
 */
static const char * const vda5050_msgs__msg__Action__NONE = "NONE";

/// Constant 'SOFT'.
static const char * const vda5050_msgs__msg__Action__SOFT = "SOFT";

/// Constant 'HARD'.
static const char * const vda5050_msgs__msg__Action__HARD = "HARD";

// Include directives for member types
// Member 'action_type'
// Member 'action_id'
// Member 'action_description'
// Member 'blocking_type'
#include "rosidl_runtime_c/string.h"
// Member 'action_parameters'
#include "vda5050_msgs/msg/detail/action_parameter__struct.h"

/// Struct defined in msg/Action in the package vda5050_msgs.
/**
  * Action the AGV can perform.
 */
typedef struct vda5050_msgs__msg__Action
{
  /// Name of action as described in the first column
  /// of "Actions and Parameters".
  /// Identifies the function of the action.
  rosidl_runtime_c__String action_type;
  /// Unique ID to identify the action and map them to
  /// the actionState in the state.
  /// Suggestion: Use UUIDs.
  rosidl_runtime_c__String action_id;
  /// Additional information on the action
  rosidl_runtime_c__String action_description;
  /// Enum {NONE, SOFT, HARD}
  /// “NONE” – allows driving and other actions
  /// “SOFT” - allows other actions, but not driving
  /// “HARD” - is the only allowd action at that time
  rosidl_runtime_c__String blocking_type;
  /// Array of actionParameter objects for the indicated
  /// action e. g. deviceId, loadId, external Triggers.
  /// See “Actions and Parameters”.
  ///
  /// Note on Porting to ROS:
  /// Since those parameter vary in type but their
  /// serialization is always a json dictionary with "key"
  /// and "value" we decided to serialize the value as
  /// string. This way the (de-)serialization has to be done by
  /// the user depending on the key, but the protocol is met
  vda5050_msgs__msg__ActionParameter__Sequence action_parameters;
} vda5050_msgs__msg__Action;

// Struct for a sequence of vda5050_msgs__msg__Action.
typedef struct vda5050_msgs__msg__Action__Sequence
{
  vda5050_msgs__msg__Action * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vda5050_msgs__msg__Action__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VDA5050_MSGS__MSG__DETAIL__ACTION__STRUCT_H_
