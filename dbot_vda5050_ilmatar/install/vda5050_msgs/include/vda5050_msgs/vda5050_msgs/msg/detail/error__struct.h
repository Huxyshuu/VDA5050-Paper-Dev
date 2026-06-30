// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vda5050_msgs:msg/Error.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__ERROR__STRUCT_H_
#define VDA5050_MSGS__MSG__DETAIL__ERROR__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'WARNING'.
/**
  * Enums for error_level
 */
static const char * const vda5050_msgs__msg__Error__WARNING = "WARNING";

/// Constant 'FATAL'.
static const char * const vda5050_msgs__msg__Error__FATAL = "FATAL";

// Include directives for member types
// Member 'error_type'
// Member 'error_description'
// Member 'error_level'
#include "rosidl_runtime_c/string.h"
// Member 'error_references'
#include "vda5050_msgs/msg/detail/error_reference__struct.h"

/// Struct defined in msg/Error in the package vda5050_msgs.
typedef struct vda5050_msgs__msg__Error
{
  /// Type / name of error
  rosidl_runtime_c__String error_type;
  /// Array of references to identify the source of the error (e. g. header_id,
  /// order_id, action_id, …). For additional information see best practice
  /// chapter 6.3
  vda5050_msgs__msg__ErrorReference__Sequence error_references;
  /// Error description
  rosidl_runtime_c__String error_description;
  /// Enum {warning, fatal} warning: AGV is ready to start (e.g. maintenance
  /// cycle expiration warning) fatal: AGV is not in running condition, user
  /// intervention required (e.g. laser scanner is contaminated)
  rosidl_runtime_c__String error_level;
} vda5050_msgs__msg__Error;

// Struct for a sequence of vda5050_msgs__msg__Error.
typedef struct vda5050_msgs__msg__Error__Sequence
{
  vda5050_msgs__msg__Error * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vda5050_msgs__msg__Error__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VDA5050_MSGS__MSG__DETAIL__ERROR__STRUCT_H_
