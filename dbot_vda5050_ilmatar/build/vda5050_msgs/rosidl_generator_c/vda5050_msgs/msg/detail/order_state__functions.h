// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from vda5050_msgs:msg/OrderState.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__ORDER_STATE__FUNCTIONS_H_
#define VDA5050_MSGS__MSG__DETAIL__ORDER_STATE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "vda5050_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "vda5050_msgs/msg/detail/order_state__struct.h"

/// Initialize msg/OrderState message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * vda5050_msgs__msg__OrderState
 * )) before or use
 * vda5050_msgs__msg__OrderState__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_msgs
bool
vda5050_msgs__msg__OrderState__init(vda5050_msgs__msg__OrderState * msg);

/// Finalize msg/OrderState message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_msgs
void
vda5050_msgs__msg__OrderState__fini(vda5050_msgs__msg__OrderState * msg);

/// Create msg/OrderState message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * vda5050_msgs__msg__OrderState__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_msgs
vda5050_msgs__msg__OrderState *
vda5050_msgs__msg__OrderState__create();

/// Destroy msg/OrderState message.
/**
 * It calls
 * vda5050_msgs__msg__OrderState__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_msgs
void
vda5050_msgs__msg__OrderState__destroy(vda5050_msgs__msg__OrderState * msg);

/// Check for msg/OrderState message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_msgs
bool
vda5050_msgs__msg__OrderState__are_equal(const vda5050_msgs__msg__OrderState * lhs, const vda5050_msgs__msg__OrderState * rhs);

/// Copy a msg/OrderState message.
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
vda5050_msgs__msg__OrderState__copy(
  const vda5050_msgs__msg__OrderState * input,
  vda5050_msgs__msg__OrderState * output);

/// Initialize array of msg/OrderState messages.
/**
 * It allocates the memory for the number of elements and calls
 * vda5050_msgs__msg__OrderState__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_msgs
bool
vda5050_msgs__msg__OrderState__Sequence__init(vda5050_msgs__msg__OrderState__Sequence * array, size_t size);

/// Finalize array of msg/OrderState messages.
/**
 * It calls
 * vda5050_msgs__msg__OrderState__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_msgs
void
vda5050_msgs__msg__OrderState__Sequence__fini(vda5050_msgs__msg__OrderState__Sequence * array);

/// Create array of msg/OrderState messages.
/**
 * It allocates the memory for the array and calls
 * vda5050_msgs__msg__OrderState__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_msgs
vda5050_msgs__msg__OrderState__Sequence *
vda5050_msgs__msg__OrderState__Sequence__create(size_t size);

/// Destroy array of msg/OrderState messages.
/**
 * It calls
 * vda5050_msgs__msg__OrderState__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_msgs
void
vda5050_msgs__msg__OrderState__Sequence__destroy(vda5050_msgs__msg__OrderState__Sequence * array);

/// Check for msg/OrderState message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_msgs
bool
vda5050_msgs__msg__OrderState__Sequence__are_equal(const vda5050_msgs__msg__OrderState__Sequence * lhs, const vda5050_msgs__msg__OrderState__Sequence * rhs);

/// Copy an array of msg/OrderState messages.
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
vda5050_msgs__msg__OrderState__Sequence__copy(
  const vda5050_msgs__msg__OrderState__Sequence * input,
  vda5050_msgs__msg__OrderState__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // VDA5050_MSGS__MSG__DETAIL__ORDER_STATE__FUNCTIONS_H_
