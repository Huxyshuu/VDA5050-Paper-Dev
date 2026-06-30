// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vda5050_msgs:msg/BoundingBoxReference.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__BOUNDING_BOX_REFERENCE__STRUCT_H_
#define VDA5050_MSGS__MSG__DETAIL__BOUNDING_BOX_REFERENCE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/BoundingBoxReference in the package vda5050_msgs.
/**
  * Point of reference for the location of the bounding box. The point of reference is always the center of the bounding
  * box’s bottom surface (at height = 0) and is described in coordinates of the AGV’s coordinate system.
 */
typedef struct vda5050_msgs__msg__BoundingBoxReference
{
  /// x-coordinate of the point of reference.
  double x;
  /// y-coordinate of the point of reference.
  double y;
  /// z-coordinate of the point of reference.
  double z;
  /// Orientation of the loads bounding box. Important for tugger trains etc
  double theta;
} vda5050_msgs__msg__BoundingBoxReference;

// Struct for a sequence of vda5050_msgs__msg__BoundingBoxReference.
typedef struct vda5050_msgs__msg__BoundingBoxReference__Sequence
{
  vda5050_msgs__msg__BoundingBoxReference * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vda5050_msgs__msg__BoundingBoxReference__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VDA5050_MSGS__MSG__DETAIL__BOUNDING_BOX_REFERENCE__STRUCT_H_
