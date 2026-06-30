// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vda5050_msgs:msg/LoadSpecification.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__LOAD_SPECIFICATION__STRUCT_H_
#define VDA5050_MSGS__MSG__DETAIL__LOAD_SPECIFICATION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'load_positions'
#include "rosidl_runtime_c/string.h"
// Member 'load_sets'
#include "vda5050_msgs/msg/detail/load_set__struct.h"

/// Struct defined in msg/LoadSpecification in the package vda5050_msgs.
typedef struct vda5050_msgs__msg__LoadSpecification
{
  /// List of load positions / load handling devices
  rosidl_runtime_c__String__Sequence load_positions;
  /// List of load-sets that can be handled by the AGV
  vda5050_msgs__msg__LoadSet__Sequence load_sets;
} vda5050_msgs__msg__LoadSpecification;

// Struct for a sequence of vda5050_msgs__msg__LoadSpecification.
typedef struct vda5050_msgs__msg__LoadSpecification__Sequence
{
  vda5050_msgs__msg__LoadSpecification * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vda5050_msgs__msg__LoadSpecification__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VDA5050_MSGS__MSG__DETAIL__LOAD_SPECIFICATION__STRUCT_H_
