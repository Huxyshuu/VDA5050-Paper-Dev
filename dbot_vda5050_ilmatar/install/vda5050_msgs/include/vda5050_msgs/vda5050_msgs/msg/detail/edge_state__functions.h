// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from vda5050_msgs:msg/EdgeState.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__EDGE_STATE__FUNCTIONS_H_
#define VDA5050_MSGS__MSG__DETAIL__EDGE_STATE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "vda5050_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "vda5050_msgs/msg/detail/edge_state__struct.h"

/// Initialize msg/EdgeState message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * vda5050_msgs__msg__EdgeState
 * )) before or use
 * vda5050_msgs__msg__EdgeState__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_msgs
bool
vda5050_msgs__msg__EdgeState__init(vda5050_msgs__msg__EdgeState * msg);

/// Finalize msg/EdgeState message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_msgs
void
vda5050_msgs__msg__EdgeState__fini(vda5050_msgs__msg__EdgeState * msg);

/// Create msg/EdgeState message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * vda5050_msgs__msg__EdgeState__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_msgs
vda5050_msgs__msg__EdgeState *
vda5050_msgs__msg__EdgeState__create();

/// Destroy msg/EdgeState message.
/**
 * It calls
 * vda5050_msgs__msg__EdgeState__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_msgs
void
vda5050_msgs__msg__EdgeState__destroy(vda5050_msgs__msg__EdgeState * msg);

/// Check for msg/EdgeState message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_msgs
bool
vda5050_msgs__msg__EdgeState__are_equal(const vda5050_msgs__msg__EdgeState * lhs, const vda5050_msgs__msg__EdgeState * rhs);

/// Copy a msg/EdgeState message.
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
vda5050_msgs__msg__EdgeState__copy(
  const vda5050_msgs__msg__EdgeState * input,
  vda5050_msgs__msg__EdgeState * output);

/// Initialize array of msg/EdgeState messages.
/**
 * It allocates the memory for the number of elements and calls
 * vda5050_msgs__msg__EdgeState__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_msgs
bool
vda5050_msgs__msg__EdgeState__Sequence__init(vda5050_msgs__msg__EdgeState__Sequence * array, size_t size);

/// Finalize array of msg/EdgeState messages.
/**
 * It calls
 * vda5050_msgs__msg__EdgeState__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_msgs
void
vda5050_msgs__msg__EdgeState__Sequence__fini(vda5050_msgs__msg__EdgeState__Sequence * array);

/// Create array of msg/EdgeState messages.
/**
 * It allocates the memory for the array and calls
 * vda5050_msgs__msg__EdgeState__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_msgs
vda5050_msgs__msg__EdgeState__Sequence *
vda5050_msgs__msg__EdgeState__Sequence__create(size_t size);

/// Destroy array of msg/EdgeState messages.
/**
 * It calls
 * vda5050_msgs__msg__EdgeState__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_msgs
void
vda5050_msgs__msg__EdgeState__Sequence__destroy(vda5050_msgs__msg__EdgeState__Sequence * array);

/// Check for msg/EdgeState message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_msgs
bool
vda5050_msgs__msg__EdgeState__Sequence__are_equal(const vda5050_msgs__msg__EdgeState__Sequence * lhs, const vda5050_msgs__msg__EdgeState__Sequence * rhs);

/// Copy an array of msg/EdgeState messages.
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
vda5050_msgs__msg__EdgeState__Sequence__copy(
  const vda5050_msgs__msg__EdgeState__Sequence * input,
  vda5050_msgs__msg__EdgeState__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // VDA5050_MSGS__MSG__DETAIL__EDGE_STATE__FUNCTIONS_H_
