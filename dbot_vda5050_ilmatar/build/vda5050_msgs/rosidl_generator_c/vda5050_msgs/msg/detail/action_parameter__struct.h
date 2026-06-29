// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vda5050_msgs:msg/ActionParameter.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__ACTION_PARAMETER__STRUCT_H_
#define VDA5050_MSGS__MSG__DETAIL__ACTION_PARAMETER__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'key'
// Member 'value'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/ActionParameter in the package vda5050_msgs.
typedef struct vda5050_msgs__msg__ActionParameter
{
  rosidl_runtime_c__String key;
  rosidl_runtime_c__String value;
} vda5050_msgs__msg__ActionParameter;

// Struct for a sequence of vda5050_msgs__msg__ActionParameter.
typedef struct vda5050_msgs__msg__ActionParameter__Sequence
{
  vda5050_msgs__msg__ActionParameter * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vda5050_msgs__msg__ActionParameter__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VDA5050_MSGS__MSG__DETAIL__ACTION_PARAMETER__STRUCT_H_
