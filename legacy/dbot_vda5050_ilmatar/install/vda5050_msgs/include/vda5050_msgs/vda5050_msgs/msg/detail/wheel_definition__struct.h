// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vda5050_msgs:msg/WheelDefinition.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__WHEEL_DEFINITION__STRUCT_H_
#define VDA5050_MSGS__MSG__DETAIL__WHEEL_DEFINITION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'DRIVE'.
/**
  * Enums for wheel type
 */
static const char * const vda5050_msgs__msg__WheelDefinition__DRIVE = "DRIVE";

/// Constant 'CASTER'.
static const char * const vda5050_msgs__msg__WheelDefinition__CASTER = "CASTER";

/// Constant 'FIXED'.
static const char * const vda5050_msgs__msg__WheelDefinition__FIXED = "FIXED";

/// Constant 'MECANUM'.
static const char * const vda5050_msgs__msg__WheelDefinition__MECANUM = "MECANUM";

// Include directives for member types
// Member 'type'
// Member 'constraints'
#include "rosidl_runtime_c/string.h"
// Member 'position'
#include "vda5050_msgs/msg/detail/position__struct.h"

/// Struct defined in msg/WheelDefinition in the package vda5050_msgs.
typedef struct vda5050_msgs__msg__WheelDefinition
{
  /// Wheel type
  rosidl_runtime_c__String type;
  bool is_active_driven;
  bool is_active_steered;
  vda5050_msgs__msg__Position position;
  /// Nominal diameter of the wheel
  double diameter;
  /// Nominal width of the wheel
  double width;
  /// Nominal displacement of the wheel’s center to the rotation point
  double center_displacement;
  rosidl_runtime_c__String constraints;
} vda5050_msgs__msg__WheelDefinition;

// Struct for a sequence of vda5050_msgs__msg__WheelDefinition.
typedef struct vda5050_msgs__msg__WheelDefinition__Sequence
{
  vda5050_msgs__msg__WheelDefinition * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vda5050_msgs__msg__WheelDefinition__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VDA5050_MSGS__MSG__DETAIL__WHEEL_DEFINITION__STRUCT_H_
