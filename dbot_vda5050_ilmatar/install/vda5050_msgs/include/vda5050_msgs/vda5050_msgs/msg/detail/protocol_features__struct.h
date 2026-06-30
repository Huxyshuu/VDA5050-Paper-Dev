// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vda5050_msgs:msg/ProtocolFeatures.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__PROTOCOL_FEATURES__STRUCT_H_
#define VDA5050_MSGS__MSG__DETAIL__PROTOCOL_FEATURES__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'optional_parameters'
#include "vda5050_msgs/msg/detail/optional_parameter__struct.h"
// Member 'agv_actions'
#include "vda5050_msgs/msg/detail/agv_action__struct.h"

/// Struct defined in msg/ProtocolFeatures in the package vda5050_msgs.
typedef struct vda5050_msgs__msg__ProtocolFeatures
{
  /// List of supported and/or required optional parameters
  vda5050_msgs__msg__OptionalParameter__Sequence optional_parameters;
  /// List of all actions with parameters supported by this AGV
  vda5050_msgs__msg__AGVAction__Sequence agv_actions;
} vda5050_msgs__msg__ProtocolFeatures;

// Struct for a sequence of vda5050_msgs__msg__ProtocolFeatures.
typedef struct vda5050_msgs__msg__ProtocolFeatures__Sequence
{
  vda5050_msgs__msg__ProtocolFeatures * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vda5050_msgs__msg__ProtocolFeatures__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VDA5050_MSGS__MSG__DETAIL__PROTOCOL_FEATURES__STRUCT_H_
