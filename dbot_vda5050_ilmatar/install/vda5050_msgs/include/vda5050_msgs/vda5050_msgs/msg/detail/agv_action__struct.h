// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vda5050_msgs:msg/AGVAction.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__AGV_ACTION__STRUCT_H_
#define VDA5050_MSGS__MSG__DETAIL__AGV_ACTION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'INSTANT'.
/**
  * Enums for action scopes
 */
static const char * const vda5050_msgs__msg__AGVAction__INSTANT = "INSTANT";

/// Constant 'NODE'.
static const char * const vda5050_msgs__msg__AGVAction__NODE = "NODE";

/// Constant 'EDGE'.
static const char * const vda5050_msgs__msg__AGVAction__EDGE = "EDGE";

// Include directives for member types
// Member 'action_type'
// Member 'action_description'
// Member 'action_scopes'
// Member 'result_description'
#include "rosidl_runtime_c/string.h"
// Member 'action_parameters'
#include "vda5050_msgs/msg/detail/action_parameter_definition__struct.h"

/// Struct defined in msg/AGVAction in the package vda5050_msgs.
typedef struct vda5050_msgs__msg__AGVAction
{
  /// Unique actionType corresponding to action.actionType
  rosidl_runtime_c__String action_type;
  rosidl_runtime_c__String action_description;
  /// Allowed scopes for using this action-type
  rosidl_runtime_c__String__Sequence action_scopes;
  /// List of parameters defined for the action
  vda5050_msgs__msg__ActionParameterDefinition__Sequence action_parameters;
  rosidl_runtime_c__String result_description;
} vda5050_msgs__msg__AGVAction;

// Struct for a sequence of vda5050_msgs__msg__AGVAction.
typedef struct vda5050_msgs__msg__AGVAction__Sequence
{
  vda5050_msgs__msg__AGVAction * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vda5050_msgs__msg__AGVAction__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VDA5050_MSGS__MSG__DETAIL__AGV_ACTION__STRUCT_H_
