// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vda5050_msgs:msg/Load.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__LOAD__STRUCT_H_
#define VDA5050_MSGS__MSG__DETAIL__LOAD__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'load_id'
// Member 'load_type'
// Member 'load_position'
#include "rosidl_runtime_c/string.h"
// Member 'bounding_box_reference'
#include "vda5050_msgs/msg/detail/bounding_box_reference__struct.h"
// Member 'load_dimensions'
#include "vda5050_msgs/msg/detail/load_dimensions__struct.h"

/// Struct defined in msg/Load in the package vda5050_msgs.
typedef struct vda5050_msgs__msg__Load
{
  /// Unique identification number of the load (e. g. barcode or
  /// RFID)
  rosidl_runtime_c__String load_id;
  /// Type of load
  rosidl_runtime_c__String load_type;
  /// Indicates which load handling/carrying unit of the AGV is
  /// used, e. g. in case the AGV has multiple spots/positions to
  /// carry loads. For example: “front”, “back”, “positionC1”, etc.
  rosidl_runtime_c__String load_position;
  /// Point of reference for the location of the bounding box. The
  /// point of reference is always the center of the bounding box’s
  /// bottom surface (at height = 0) and is described in coordinates
  /// of the AGV’s coordinate system.
  vda5050_msgs__msg__BoundingBoxReference bounding_box_reference;
  /// Dimensions of the load’s bounding box in meters.
  vda5050_msgs__msg__LoadDimensions load_dimensions;
  /// Absolute weight of the load measured in kg.
  double weight;
} vda5050_msgs__msg__Load;

// Struct for a sequence of vda5050_msgs__msg__Load.
typedef struct vda5050_msgs__msg__Load__Sequence
{
  vda5050_msgs__msg__Load * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vda5050_msgs__msg__Load__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VDA5050_MSGS__MSG__DETAIL__LOAD__STRUCT_H_
