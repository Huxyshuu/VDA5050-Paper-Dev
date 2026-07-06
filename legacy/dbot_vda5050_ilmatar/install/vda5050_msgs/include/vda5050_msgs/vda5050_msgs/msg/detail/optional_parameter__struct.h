// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vda5050_msgs:msg/OptionalParameter.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__OPTIONAL_PARAMETER__STRUCT_H_
#define VDA5050_MSGS__MSG__DETAIL__OPTIONAL_PARAMETER__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'SUPPORTED'.
/**
  * Enums for support
 */
static const char * const vda5050_msgs__msg__OptionalParameter__SUPPORTED = "SUPPORTED";

/// Constant 'REQUIRED'.
static const char * const vda5050_msgs__msg__OptionalParameter__REQUIRED = "REQUIRED";

// Include directives for member types
// Member 'parameter'
// Member 'support'
// Member 'description'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/OptionalParameter in the package vda5050_msgs.
typedef struct vda5050_msgs__msg__OptionalParameter
{
  /// Full name of optional parameter
  rosidl_runtime_c__String parameter;
  /// Type of support for the optional parameter
  rosidl_runtime_c__String support;
  /// Description of optional parameter
  rosidl_runtime_c__String description;
} vda5050_msgs__msg__OptionalParameter;

// Struct for a sequence of vda5050_msgs__msg__OptionalParameter.
typedef struct vda5050_msgs__msg__OptionalParameter__Sequence
{
  vda5050_msgs__msg__OptionalParameter * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vda5050_msgs__msg__OptionalParameter__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VDA5050_MSGS__MSG__DETAIL__OPTIONAL_PARAMETER__STRUCT_H_
