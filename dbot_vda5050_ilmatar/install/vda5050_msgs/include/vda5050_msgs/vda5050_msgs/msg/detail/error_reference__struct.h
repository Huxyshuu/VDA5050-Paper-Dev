// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vda5050_msgs:msg/ErrorReference.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__ERROR_REFERENCE__STRUCT_H_
#define VDA5050_MSGS__MSG__DETAIL__ERROR_REFERENCE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'reference_key'
// Member 'reference_value'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/ErrorReference in the package vda5050_msgs.
typedef struct vda5050_msgs__msg__ErrorReference
{
  /// References the type of reference (e. g. header_id, order_id, action_id, …).
  rosidl_runtime_c__String reference_key;
  /// References the value the reference key.
  rosidl_runtime_c__String reference_value;
} vda5050_msgs__msg__ErrorReference;

// Struct for a sequence of vda5050_msgs__msg__ErrorReference.
typedef struct vda5050_msgs__msg__ErrorReference__Sequence
{
  vda5050_msgs__msg__ErrorReference * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vda5050_msgs__msg__ErrorReference__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VDA5050_MSGS__MSG__DETAIL__ERROR_REFERENCE__STRUCT_H_
