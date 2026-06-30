// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vda5050_msgs:msg/CurrentAction.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__CURRENT_ACTION__STRUCT_H_
#define VDA5050_MSGS__MSG__DETAIL__CURRENT_ACTION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'WAITING'.
/**
  * Enums for actionStatus
 */
static const char * const vda5050_msgs__msg__CurrentAction__WAITING = "WAITING";

/// Constant 'INITIALIZING'.
static const char * const vda5050_msgs__msg__CurrentAction__INITIALIZING = "INITIALIZING";

/// Constant 'RUNNING'.
static const char * const vda5050_msgs__msg__CurrentAction__RUNNING = "RUNNING";

/// Constant 'PAUSED'.
static const char * const vda5050_msgs__msg__CurrentAction__PAUSED = "PAUSED";

/// Constant 'FINISHED'.
static const char * const vda5050_msgs__msg__CurrentAction__FINISHED = "FINISHED";

/// Constant 'FAILED'.
static const char * const vda5050_msgs__msg__CurrentAction__FAILED = "FAILED";

// Include directives for member types
// Member 'action_id'
// Member 'action_type'
// Member 'action_description'
// Member 'action_status'
// Member 'result_description'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/CurrentAction in the package vda5050_msgs.
typedef struct vda5050_msgs__msg__CurrentAction
{
  /// action_name_ID
  rosidl_runtime_c__String action_id;
  /// actionType of the action.
  /// Optional: Only for informational or
  /// visualization purposes. Order knows
  /// the type.
  rosidl_runtime_c__String action_type;
  /// Additional information on the current action
  rosidl_runtime_c__String action_description;
  /// Enum {waiting; initializing; running; finished; failed} waiting: waiting for trigger
  /// failed: action could not be performed.
  rosidl_runtime_c__String action_status;
  /// Description of the result, e.g. the result of a RFID-read. Errors will be transmitted in
  /// errors. Examples for results are given in 5.2
  rosidl_runtime_c__String result_description;
} vda5050_msgs__msg__CurrentAction;

// Struct for a sequence of vda5050_msgs__msg__CurrentAction.
typedef struct vda5050_msgs__msg__CurrentAction__Sequence
{
  vda5050_msgs__msg__CurrentAction * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vda5050_msgs__msg__CurrentAction__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VDA5050_MSGS__MSG__DETAIL__CURRENT_ACTION__STRUCT_H_
