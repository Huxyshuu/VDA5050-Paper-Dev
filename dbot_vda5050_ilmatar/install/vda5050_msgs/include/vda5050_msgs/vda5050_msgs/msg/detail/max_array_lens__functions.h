// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from vda5050_msgs:msg/MaxArrayLens.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__MAX_ARRAY_LENS__FUNCTIONS_H_
#define VDA5050_MSGS__MSG__DETAIL__MAX_ARRAY_LENS__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "vda5050_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "vda5050_msgs/msg/detail/max_array_lens__struct.h"

/// Initialize msg/MaxArrayLens message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * vda5050_msgs__msg__MaxArrayLens
 * )) before or use
 * vda5050_msgs__msg__MaxArrayLens__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_msgs
bool
vda5050_msgs__msg__MaxArrayLens__init(vda5050_msgs__msg__MaxArrayLens * msg);

/// Finalize msg/MaxArrayLens message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_msgs
void
vda5050_msgs__msg__MaxArrayLens__fini(vda5050_msgs__msg__MaxArrayLens * msg);

/// Create msg/MaxArrayLens message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * vda5050_msgs__msg__MaxArrayLens__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_msgs
vda5050_msgs__msg__MaxArrayLens *
vda5050_msgs__msg__MaxArrayLens__create();

/// Destroy msg/MaxArrayLens message.
/**
 * It calls
 * vda5050_msgs__msg__MaxArrayLens__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_msgs
void
vda5050_msgs__msg__MaxArrayLens__destroy(vda5050_msgs__msg__MaxArrayLens * msg);

/// Check for msg/MaxArrayLens message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_msgs
bool
vda5050_msgs__msg__MaxArrayLens__are_equal(const vda5050_msgs__msg__MaxArrayLens * lhs, const vda5050_msgs__msg__MaxArrayLens * rhs);

/// Copy a msg/MaxArrayLens message.
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
vda5050_msgs__msg__MaxArrayLens__copy(
  const vda5050_msgs__msg__MaxArrayLens * input,
  vda5050_msgs__msg__MaxArrayLens * output);

/// Initialize array of msg/MaxArrayLens messages.
/**
 * It allocates the memory for the number of elements and calls
 * vda5050_msgs__msg__MaxArrayLens__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_msgs
bool
vda5050_msgs__msg__MaxArrayLens__Sequence__init(vda5050_msgs__msg__MaxArrayLens__Sequence * array, size_t size);

/// Finalize array of msg/MaxArrayLens messages.
/**
 * It calls
 * vda5050_msgs__msg__MaxArrayLens__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_msgs
void
vda5050_msgs__msg__MaxArrayLens__Sequence__fini(vda5050_msgs__msg__MaxArrayLens__Sequence * array);

/// Create array of msg/MaxArrayLens messages.
/**
 * It allocates the memory for the array and calls
 * vda5050_msgs__msg__MaxArrayLens__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_msgs
vda5050_msgs__msg__MaxArrayLens__Sequence *
vda5050_msgs__msg__MaxArrayLens__Sequence__create(size_t size);

/// Destroy array of msg/MaxArrayLens messages.
/**
 * It calls
 * vda5050_msgs__msg__MaxArrayLens__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_msgs
void
vda5050_msgs__msg__MaxArrayLens__Sequence__destroy(vda5050_msgs__msg__MaxArrayLens__Sequence * array);

/// Check for msg/MaxArrayLens message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_msgs
bool
vda5050_msgs__msg__MaxArrayLens__Sequence__are_equal(const vda5050_msgs__msg__MaxArrayLens__Sequence * lhs, const vda5050_msgs__msg__MaxArrayLens__Sequence * rhs);

/// Copy an array of msg/MaxArrayLens messages.
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
vda5050_msgs__msg__MaxArrayLens__Sequence__copy(
  const vda5050_msgs__msg__MaxArrayLens__Sequence * input,
  vda5050_msgs__msg__MaxArrayLens__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // VDA5050_MSGS__MSG__DETAIL__MAX_ARRAY_LENS__FUNCTIONS_H_
