// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from vda5050_msgs:msg/ControlPoint.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__CONTROL_POINT__FUNCTIONS_H_
#define VDA5050_MSGS__MSG__DETAIL__CONTROL_POINT__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "vda5050_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "vda5050_msgs/msg/detail/control_point__struct.h"

/// Initialize msg/ControlPoint message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * vda5050_msgs__msg__ControlPoint
 * )) before or use
 * vda5050_msgs__msg__ControlPoint__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_msgs
bool
vda5050_msgs__msg__ControlPoint__init(vda5050_msgs__msg__ControlPoint * msg);

/// Finalize msg/ControlPoint message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_msgs
void
vda5050_msgs__msg__ControlPoint__fini(vda5050_msgs__msg__ControlPoint * msg);

/// Create msg/ControlPoint message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * vda5050_msgs__msg__ControlPoint__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_msgs
vda5050_msgs__msg__ControlPoint *
vda5050_msgs__msg__ControlPoint__create();

/// Destroy msg/ControlPoint message.
/**
 * It calls
 * vda5050_msgs__msg__ControlPoint__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_msgs
void
vda5050_msgs__msg__ControlPoint__destroy(vda5050_msgs__msg__ControlPoint * msg);

/// Check for msg/ControlPoint message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_msgs
bool
vda5050_msgs__msg__ControlPoint__are_equal(const vda5050_msgs__msg__ControlPoint * lhs, const vda5050_msgs__msg__ControlPoint * rhs);

/// Copy a msg/ControlPoint message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_msgs
bool
vda5050_msgs__msg__ControlPoint__copy(
  const vda5050_msgs__msg__ControlPoint * input,
  vda5050_msgs__msg__ControlPoint * output);

/// Initialize array of msg/ControlPoint messages.
/**
 * It allocates the memory for the number of elements and calls
 * vda5050_msgs__msg__ControlPoint__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_msgs
bool
vda5050_msgs__msg__ControlPoint__Sequence__init(vda5050_msgs__msg__ControlPoint__Sequence * array, size_t size);

/// Finalize array of msg/ControlPoint messages.
/**
 * It calls
 * vda5050_msgs__msg__ControlPoint__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_msgs
void
vda5050_msgs__msg__ControlPoint__Sequence__fini(vda5050_msgs__msg__ControlPoint__Sequence * array);

/// Create array of msg/ControlPoint messages.
/**
 * It allocates the memory for the array and calls
 * vda5050_msgs__msg__ControlPoint__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_msgs
vda5050_msgs__msg__ControlPoint__Sequence *
vda5050_msgs__msg__ControlPoint__Sequence__create(size_t size);

/// Destroy array of msg/ControlPoint messages.
/**
 * It calls
 * vda5050_msgs__msg__ControlPoint__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_msgs
void
vda5050_msgs__msg__ControlPoint__Sequence__destroy(vda5050_msgs__msg__ControlPoint__Sequence * array);

/// Check for msg/ControlPoint message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_msgs
bool
vda5050_msgs__msg__ControlPoint__Sequence__are_equal(const vda5050_msgs__msg__ControlPoint__Sequence * lhs, const vda5050_msgs__msg__ControlPoint__Sequence * rhs);

/// Copy an array of msg/ControlPoint messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_msgs
bool
vda5050_msgs__msg__ControlPoint__Sequence__copy(
  const vda5050_msgs__msg__ControlPoint__Sequence * input,
  vda5050_msgs__msg__ControlPoint__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // VDA5050_MSGS__MSG__DETAIL__CONTROL_POINT__FUNCTIONS_H_
