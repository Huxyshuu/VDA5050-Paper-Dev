// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vda5050_msgs:msg/ActionParameterDefinition.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__ACTION_PARAMETER_DEFINITION__STRUCT_H_
#define VDA5050_MSGS__MSG__DETAIL__ACTION_PARAMETER_DEFINITION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'BOOL'.
/**
  * Enums for valueDataType
 */
static const char * const vda5050_msgs__msg__ActionParameterDefinition__BOOL = "BOOL";

/// Constant 'NUMBER'.
static const char * const vda5050_msgs__msg__ActionParameterDefinition__NUMBER = "NUMBER";

/// Constant 'INTEGER'.
static const char * const vda5050_msgs__msg__ActionParameterDefinition__INTEGER = "INTEGER";

/// Constant 'FLOAT'.
static const char * const vda5050_msgs__msg__ActionParameterDefinition__FLOAT = "FLOAT";

/// Constant 'STRING'.
static const char * const vda5050_msgs__msg__ActionParameterDefinition__STRING = "STRING";

/// Constant 'OBJECT'.
static const char * const vda5050_msgs__msg__ActionParameterDefinition__OBJECT = "OBJECT";

/// Constant 'ARRAY'.
static const char * const vda5050_msgs__msg__ActionParameterDefinition__ARRAY = "ARRAY";

// Include directives for member types
// Member 'key'
// Member 'value_data_type'
// Member 'description'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/ActionParameterDefinition in the package vda5050_msgs.
typedef struct vda5050_msgs__msg__ActionParameterDefinition
{
  rosidl_runtime_c__String key;
  rosidl_runtime_c__String value_data_type;
  rosidl_runtime_c__String description;
  bool is_optional;
} vda5050_msgs__msg__ActionParameterDefinition;

// Struct for a sequence of vda5050_msgs__msg__ActionParameterDefinition.
typedef struct vda5050_msgs__msg__ActionParameterDefinition__Sequence
{
  vda5050_msgs__msg__ActionParameterDefinition * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vda5050_msgs__msg__ActionParameterDefinition__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VDA5050_MSGS__MSG__DETAIL__ACTION_PARAMETER_DEFINITION__STRUCT_H_
