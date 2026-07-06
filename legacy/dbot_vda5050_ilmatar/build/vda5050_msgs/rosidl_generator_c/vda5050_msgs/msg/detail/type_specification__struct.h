// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vda5050_msgs:msg/TypeSpecification.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__TYPE_SPECIFICATION__STRUCT_H_
#define VDA5050_MSGS__MSG__DETAIL__TYPE_SPECIFICATION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'DIFF'.
/**
  * Enums for agv_kinematic
 */
static const char * const vda5050_msgs__msg__TypeSpecification__DIFF = "DIFF";

/// Constant 'OMNI'.
static const char * const vda5050_msgs__msg__TypeSpecification__OMNI = "OMNI";

/// Constant 'THREEWHEEL'.
static const char * const vda5050_msgs__msg__TypeSpecification__THREEWHEEL = "THREEWHEEL";

/// Constant 'FORKLIFT'.
/**
  * Enums for agv_class
 */
static const char * const vda5050_msgs__msg__TypeSpecification__FORKLIFT = "FORKLIFT";

/// Constant 'CONVEYOR'.
static const char * const vda5050_msgs__msg__TypeSpecification__CONVEYOR = "CONVEYOR";

/// Constant 'TUGGER'.
static const char * const vda5050_msgs__msg__TypeSpecification__TUGGER = "TUGGER";

/// Constant 'CARRIER'.
static const char * const vda5050_msgs__msg__TypeSpecification__CARRIER = "CARRIER";

/// Constant 'NATURAL'.
/**
  * Enums for localization_types
 */
static const char * const vda5050_msgs__msg__TypeSpecification__NATURAL = "NATURAL";

/// Constant 'REFLECTOR'.
static const char * const vda5050_msgs__msg__TypeSpecification__REFLECTOR = "REFLECTOR";

/// Constant 'RFID'.
static const char * const vda5050_msgs__msg__TypeSpecification__RFID = "RFID";

/// Constant 'DMC'.
static const char * const vda5050_msgs__msg__TypeSpecification__DMC = "DMC";

/// Constant 'SPOT'.
static const char * const vda5050_msgs__msg__TypeSpecification__SPOT = "SPOT";

/// Constant 'GRID'.
static const char * const vda5050_msgs__msg__TypeSpecification__GRID = "GRID";

/// Constant 'PHYSICAL_LINE_GUIDED'.
/**
  * Enums for navigation_types
 */
static const char * const vda5050_msgs__msg__TypeSpecification__PHYSICAL_LINE_GUIDED = "PHYSICAL_LINE_GUIDED";

/// Constant 'VIRTUAL_LINE_GUIDED'.
static const char * const vda5050_msgs__msg__TypeSpecification__VIRTUAL_LINE_GUIDED = "VIRTUAL_LINE_GUIDED";

/// Constant 'AUTONOMOUS'.
static const char * const vda5050_msgs__msg__TypeSpecification__AUTONOMOUS = "AUTONOMOUS";

// Include directives for member types
// Member 'series_name'
// Member 'series_description'
// Member 'agv_kinematic'
// Member 'agv_class'
// Member 'localization_types'
// Member 'navigation_types'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/TypeSpecification in the package vda5050_msgs.
typedef struct vda5050_msgs__msg__TypeSpecification
{
  /// Generalized series name as specified by manufacturer
  rosidl_runtime_c__String series_name;
  /// Human readable description of the AGV type series
  rosidl_runtime_c__String series_description;
  /// Simplified description of AGV kinematics-type
  rosidl_runtime_c__String agv_kinematic;
  /// Simplified description of AGV class
  rosidl_runtime_c__String agv_class;
  /// Maximum loadable mass
  double max_load_mass;
  /// Simplified description of localization type
  rosidl_runtime_c__String__Sequence localization_types;
  /// Path planning types supported by the AGV, sorted by priority
  rosidl_runtime_c__String__Sequence navigation_types;
} vda5050_msgs__msg__TypeSpecification;

// Struct for a sequence of vda5050_msgs__msg__TypeSpecification.
typedef struct vda5050_msgs__msg__TypeSpecification__Sequence
{
  vda5050_msgs__msg__TypeSpecification * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vda5050_msgs__msg__TypeSpecification__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VDA5050_MSGS__MSG__DETAIL__TYPE_SPECIFICATION__STRUCT_H_
