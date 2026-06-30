// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vda5050_msgs:msg/Info.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__INFO__STRUCT_H_
#define VDA5050_MSGS__MSG__DETAIL__INFO__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'DEBUG'.
static const char * const vda5050_msgs__msg__Info__DEBUG = "DEBUG";

/// Constant 'INFO'.
static const char * const vda5050_msgs__msg__Info__INFO = "INFO";

// Include directives for member types
// Member 'info_type'
// Member 'info_description'
// Member 'info_level'
#include "rosidl_runtime_c/string.h"
// Member 'info_references'
#include "vda5050_msgs/msg/detail/info_reference__struct.h"

/// Struct defined in msg/Info in the package vda5050_msgs.
typedef struct vda5050_msgs__msg__Info
{
  /// Type / name of information
  rosidl_runtime_c__String info_type;
  /// array of references
  vda5050_msgs__msg__InfoReference__Sequence info_references;
  /// Info description
  rosidl_runtime_c__String info_description;
  /// Enum {DEBUG, INFO} DEBUG: used for debugging, INFO: used for visualization
  rosidl_runtime_c__String info_level;
} vda5050_msgs__msg__Info;

// Struct for a sequence of vda5050_msgs__msg__Info.
typedef struct vda5050_msgs__msg__Info__Sequence
{
  vda5050_msgs__msg__Info * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vda5050_msgs__msg__Info__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VDA5050_MSGS__MSG__DETAIL__INFO__STRUCT_H_
