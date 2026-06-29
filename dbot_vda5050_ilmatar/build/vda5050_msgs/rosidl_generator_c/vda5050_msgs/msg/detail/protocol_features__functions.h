// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from vda5050_msgs:msg/ProtocolFeatures.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__PROTOCOL_FEATURES__FUNCTIONS_H_
#define VDA5050_MSGS__MSG__DETAIL__PROTOCOL_FEATURES__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "vda5050_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "vda5050_msgs/msg/detail/protocol_features__struct.h"

/// Initialize msg/ProtocolFeatures message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * vda5050_msgs__msg__ProtocolFeatures
 * )) before or use
 * vda5050_msgs__msg__ProtocolFeatures__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_msgs
bool
vda5050_msgs__msg__ProtocolFeatures__init(vda5050_msgs__msg__ProtocolFeatures * msg);

/// Finalize msg/ProtocolFeatures message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_msgs
void
vda5050_msgs__msg__ProtocolFeatures__fini(vda5050_msgs__msg__ProtocolFeatures * msg);

/// Create msg/ProtocolFeatures message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * vda5050_msgs__msg__ProtocolFeatures__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_msgs
vda5050_msgs__msg__ProtocolFeatures *
vda5050_msgs__msg__ProtocolFeatures__create();

/// Destroy msg/ProtocolFeatures message.
/**
 * It calls
 * vda5050_msgs__msg__ProtocolFeatures__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_msgs
void
vda5050_msgs__msg__ProtocolFeatures__destroy(vda5050_msgs__msg__ProtocolFeatures * msg);

/// Check for msg/ProtocolFeatures message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_msgs
bool
vda5050_msgs__msg__ProtocolFeatures__are_equal(const vda5050_msgs__msg__ProtocolFeatures * lhs, const vda5050_msgs__msg__ProtocolFeatures * rhs);

/// Copy a msg/ProtocolFeatures message.
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
vda5050_msgs__msg__ProtocolFeatures__copy(
  const vda5050_msgs__msg__ProtocolFeatures * input,
  vda5050_msgs__msg__ProtocolFeatures * output);

/// Initialize array of msg/ProtocolFeatures messages.
/**
 * It allocates the memory for the number of elements and calls
 * vda5050_msgs__msg__ProtocolFeatures__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_msgs
bool
vda5050_msgs__msg__ProtocolFeatures__Sequence__init(vda5050_msgs__msg__ProtocolFeatures__Sequence * array, size_t size);

/// Finalize array of msg/ProtocolFeatures messages.
/**
 * It calls
 * vda5050_msgs__msg__ProtocolFeatures__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_msgs
void
vda5050_msgs__msg__ProtocolFeatures__Sequence__fini(vda5050_msgs__msg__ProtocolFeatures__Sequence * array);

/// Create array of msg/ProtocolFeatures messages.
/**
 * It allocates the memory for the array and calls
 * vda5050_msgs__msg__ProtocolFeatures__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_msgs
vda5050_msgs__msg__ProtocolFeatures__Sequence *
vda5050_msgs__msg__ProtocolFeatures__Sequence__create(size_t size);

/// Destroy array of msg/ProtocolFeatures messages.
/**
 * It calls
 * vda5050_msgs__msg__ProtocolFeatures__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_msgs
void
vda5050_msgs__msg__ProtocolFeatures__Sequence__destroy(vda5050_msgs__msg__ProtocolFeatures__Sequence * array);

/// Check for msg/ProtocolFeatures message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_msgs
bool
vda5050_msgs__msg__ProtocolFeatures__Sequence__are_equal(const vda5050_msgs__msg__ProtocolFeatures__Sequence * lhs, const vda5050_msgs__msg__ProtocolFeatures__Sequence * rhs);

/// Copy an array of msg/ProtocolFeatures messages.
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
vda5050_msgs__msg__ProtocolFeatures__Sequence__copy(
  const vda5050_msgs__msg__ProtocolFeatures__Sequence * input,
  vda5050_msgs__msg__ProtocolFeatures__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // VDA5050_MSGS__MSG__DETAIL__PROTOCOL_FEATURES__FUNCTIONS_H_
