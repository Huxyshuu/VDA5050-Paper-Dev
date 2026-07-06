// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from dbot_custom_msgs:msg/WheelEncoder.idl
// generated code does not contain a copyright notice

#ifndef DBOT_CUSTOM_MSGS__MSG__DETAIL__WHEEL_ENCODER__FUNCTIONS_H_
#define DBOT_CUSTOM_MSGS__MSG__DETAIL__WHEEL_ENCODER__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "dbot_custom_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "dbot_custom_msgs/msg/detail/wheel_encoder__struct.h"

/// Initialize msg/WheelEncoder message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * dbot_custom_msgs__msg__WheelEncoder
 * )) before or use
 * dbot_custom_msgs__msg__WheelEncoder__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_dbot_custom_msgs
bool
dbot_custom_msgs__msg__WheelEncoder__init(dbot_custom_msgs__msg__WheelEncoder * msg);

/// Finalize msg/WheelEncoder message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dbot_custom_msgs
void
dbot_custom_msgs__msg__WheelEncoder__fini(dbot_custom_msgs__msg__WheelEncoder * msg);

/// Create msg/WheelEncoder message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * dbot_custom_msgs__msg__WheelEncoder__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_dbot_custom_msgs
dbot_custom_msgs__msg__WheelEncoder *
dbot_custom_msgs__msg__WheelEncoder__create();

/// Destroy msg/WheelEncoder message.
/**
 * It calls
 * dbot_custom_msgs__msg__WheelEncoder__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dbot_custom_msgs
void
dbot_custom_msgs__msg__WheelEncoder__destroy(dbot_custom_msgs__msg__WheelEncoder * msg);

/// Check for msg/WheelEncoder message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_dbot_custom_msgs
bool
dbot_custom_msgs__msg__WheelEncoder__are_equal(const dbot_custom_msgs__msg__WheelEncoder * lhs, const dbot_custom_msgs__msg__WheelEncoder * rhs);

/// Copy a msg/WheelEncoder message.
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
ROSIDL_GENERATOR_C_PUBLIC_dbot_custom_msgs
bool
dbot_custom_msgs__msg__WheelEncoder__copy(
  const dbot_custom_msgs__msg__WheelEncoder * input,
  dbot_custom_msgs__msg__WheelEncoder * output);

/// Initialize array of msg/WheelEncoder messages.
/**
 * It allocates the memory for the number of elements and calls
 * dbot_custom_msgs__msg__WheelEncoder__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_dbot_custom_msgs
bool
dbot_custom_msgs__msg__WheelEncoder__Sequence__init(dbot_custom_msgs__msg__WheelEncoder__Sequence * array, size_t size);

/// Finalize array of msg/WheelEncoder messages.
/**
 * It calls
 * dbot_custom_msgs__msg__WheelEncoder__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dbot_custom_msgs
void
dbot_custom_msgs__msg__WheelEncoder__Sequence__fini(dbot_custom_msgs__msg__WheelEncoder__Sequence * array);

/// Create array of msg/WheelEncoder messages.
/**
 * It allocates the memory for the array and calls
 * dbot_custom_msgs__msg__WheelEncoder__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_dbot_custom_msgs
dbot_custom_msgs__msg__WheelEncoder__Sequence *
dbot_custom_msgs__msg__WheelEncoder__Sequence__create(size_t size);

/// Destroy array of msg/WheelEncoder messages.
/**
 * It calls
 * dbot_custom_msgs__msg__WheelEncoder__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dbot_custom_msgs
void
dbot_custom_msgs__msg__WheelEncoder__Sequence__destroy(dbot_custom_msgs__msg__WheelEncoder__Sequence * array);

/// Check for msg/WheelEncoder message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_dbot_custom_msgs
bool
dbot_custom_msgs__msg__WheelEncoder__Sequence__are_equal(const dbot_custom_msgs__msg__WheelEncoder__Sequence * lhs, const dbot_custom_msgs__msg__WheelEncoder__Sequence * rhs);

/// Copy an array of msg/WheelEncoder messages.
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
ROSIDL_GENERATOR_C_PUBLIC_dbot_custom_msgs
bool
dbot_custom_msgs__msg__WheelEncoder__Sequence__copy(
  const dbot_custom_msgs__msg__WheelEncoder__Sequence * input,
  dbot_custom_msgs__msg__WheelEncoder__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // DBOT_CUSTOM_MSGS__MSG__DETAIL__WHEEL_ENCODER__FUNCTIONS_H_
