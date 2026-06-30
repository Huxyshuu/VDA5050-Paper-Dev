// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vda5050_msgs:msg/PolygonPoint.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__POLYGON_POINT__STRUCT_H_
#define VDA5050_MSGS__MSG__DETAIL__POLYGON_POINT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/PolygonPoint in the package vda5050_msgs.
typedef struct vda5050_msgs__msg__PolygonPoint
{
  /// x-position of polygon-point
  double x;
  /// y-position of polygon-point
  double y;
} vda5050_msgs__msg__PolygonPoint;

// Struct for a sequence of vda5050_msgs__msg__PolygonPoint.
typedef struct vda5050_msgs__msg__PolygonPoint__Sequence
{
  vda5050_msgs__msg__PolygonPoint * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vda5050_msgs__msg__PolygonPoint__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VDA5050_MSGS__MSG__DETAIL__POLYGON_POINT__STRUCT_H_
