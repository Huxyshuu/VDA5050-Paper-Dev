// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vda5050_msgs:msg/SafetyState.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__SAFETY_STATE__STRUCT_H_
#define VDA5050_MSGS__MSG__DETAIL__SAFETY_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'AUTO_ACK'.
/**
  * Enums for eStop
 */
static const char * const vda5050_msgs__msg__SafetyState__AUTO_ACK = "AUTOACK";

/// Constant 'MANUAL'.
static const char * const vda5050_msgs__msg__SafetyState__MANUAL = "MANUAL";

/// Constant 'REMOTE'.
static const char * const vda5050_msgs__msg__SafetyState__REMOTE = "REMOTE";

/// Constant 'NONE'.
static const char * const vda5050_msgs__msg__SafetyState__NONE = "NONE";

// Include directives for member types
// Member 'e_stop'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/SafetyState in the package vda5050_msgs.
typedef struct vda5050_msgs__msg__SafetyState
{
  /// Enum {autoAck, manual, remote, none} Acknowledge-Type of eStop:
  /// autoAck: autoacknowledgeable e-stop is activated e.g. by bumper or protective field
  /// manual: e-stop has to be acknowledged manually at the vehicle
  /// remote: facility estop has to be acknowledged remotely
  /// none: no e-stop activated
  rosidl_runtime_c__String e_stop;
  /// Protective field violation. True: field is violated False: field is not violated
  bool field_violation;
} vda5050_msgs__msg__SafetyState;

// Struct for a sequence of vda5050_msgs__msg__SafetyState.
typedef struct vda5050_msgs__msg__SafetyState__Sequence
{
  vda5050_msgs__msg__SafetyState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vda5050_msgs__msg__SafetyState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VDA5050_MSGS__MSG__DETAIL__SAFETY_STATE__STRUCT_H_
