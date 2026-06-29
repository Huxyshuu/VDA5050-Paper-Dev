// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from vda5050_connector:srv/SupportedActions.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_CONNECTOR__SRV__DETAIL__SUPPORTED_ACTIONS__FUNCTIONS_H_
#define VDA5050_CONNECTOR__SRV__DETAIL__SUPPORTED_ACTIONS__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "vda5050_connector/msg/rosidl_generator_c__visibility_control.h"

#include "vda5050_connector/srv/detail/supported_actions__struct.h"

/// Initialize srv/SupportedActions message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * vda5050_connector__srv__SupportedActions_Request
 * )) before or use
 * vda5050_connector__srv__SupportedActions_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
bool
vda5050_connector__srv__SupportedActions_Request__init(vda5050_connector__srv__SupportedActions_Request * msg);

/// Finalize srv/SupportedActions message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
void
vda5050_connector__srv__SupportedActions_Request__fini(vda5050_connector__srv__SupportedActions_Request * msg);

/// Create srv/SupportedActions message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * vda5050_connector__srv__SupportedActions_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
vda5050_connector__srv__SupportedActions_Request *
vda5050_connector__srv__SupportedActions_Request__create();

/// Destroy srv/SupportedActions message.
/**
 * It calls
 * vda5050_connector__srv__SupportedActions_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
void
vda5050_connector__srv__SupportedActions_Request__destroy(vda5050_connector__srv__SupportedActions_Request * msg);

/// Check for srv/SupportedActions message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
bool
vda5050_connector__srv__SupportedActions_Request__are_equal(const vda5050_connector__srv__SupportedActions_Request * lhs, const vda5050_connector__srv__SupportedActions_Request * rhs);

/// Copy a srv/SupportedActions message.
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
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
bool
vda5050_connector__srv__SupportedActions_Request__copy(
  const vda5050_connector__srv__SupportedActions_Request * input,
  vda5050_connector__srv__SupportedActions_Request * output);

/// Initialize array of srv/SupportedActions messages.
/**
 * It allocates the memory for the number of elements and calls
 * vda5050_connector__srv__SupportedActions_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
bool
vda5050_connector__srv__SupportedActions_Request__Sequence__init(vda5050_connector__srv__SupportedActions_Request__Sequence * array, size_t size);

/// Finalize array of srv/SupportedActions messages.
/**
 * It calls
 * vda5050_connector__srv__SupportedActions_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
void
vda5050_connector__srv__SupportedActions_Request__Sequence__fini(vda5050_connector__srv__SupportedActions_Request__Sequence * array);

/// Create array of srv/SupportedActions messages.
/**
 * It allocates the memory for the array and calls
 * vda5050_connector__srv__SupportedActions_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
vda5050_connector__srv__SupportedActions_Request__Sequence *
vda5050_connector__srv__SupportedActions_Request__Sequence__create(size_t size);

/// Destroy array of srv/SupportedActions messages.
/**
 * It calls
 * vda5050_connector__srv__SupportedActions_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
void
vda5050_connector__srv__SupportedActions_Request__Sequence__destroy(vda5050_connector__srv__SupportedActions_Request__Sequence * array);

/// Check for srv/SupportedActions message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
bool
vda5050_connector__srv__SupportedActions_Request__Sequence__are_equal(const vda5050_connector__srv__SupportedActions_Request__Sequence * lhs, const vda5050_connector__srv__SupportedActions_Request__Sequence * rhs);

/// Copy an array of srv/SupportedActions messages.
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
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
bool
vda5050_connector__srv__SupportedActions_Request__Sequence__copy(
  const vda5050_connector__srv__SupportedActions_Request__Sequence * input,
  vda5050_connector__srv__SupportedActions_Request__Sequence * output);

/// Initialize srv/SupportedActions message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * vda5050_connector__srv__SupportedActions_Response
 * )) before or use
 * vda5050_connector__srv__SupportedActions_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
bool
vda5050_connector__srv__SupportedActions_Response__init(vda5050_connector__srv__SupportedActions_Response * msg);

/// Finalize srv/SupportedActions message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
void
vda5050_connector__srv__SupportedActions_Response__fini(vda5050_connector__srv__SupportedActions_Response * msg);

/// Create srv/SupportedActions message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * vda5050_connector__srv__SupportedActions_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
vda5050_connector__srv__SupportedActions_Response *
vda5050_connector__srv__SupportedActions_Response__create();

/// Destroy srv/SupportedActions message.
/**
 * It calls
 * vda5050_connector__srv__SupportedActions_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
void
vda5050_connector__srv__SupportedActions_Response__destroy(vda5050_connector__srv__SupportedActions_Response * msg);

/// Check for srv/SupportedActions message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
bool
vda5050_connector__srv__SupportedActions_Response__are_equal(const vda5050_connector__srv__SupportedActions_Response * lhs, const vda5050_connector__srv__SupportedActions_Response * rhs);

/// Copy a srv/SupportedActions message.
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
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
bool
vda5050_connector__srv__SupportedActions_Response__copy(
  const vda5050_connector__srv__SupportedActions_Response * input,
  vda5050_connector__srv__SupportedActions_Response * output);

/// Initialize array of srv/SupportedActions messages.
/**
 * It allocates the memory for the number of elements and calls
 * vda5050_connector__srv__SupportedActions_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
bool
vda5050_connector__srv__SupportedActions_Response__Sequence__init(vda5050_connector__srv__SupportedActions_Response__Sequence * array, size_t size);

/// Finalize array of srv/SupportedActions messages.
/**
 * It calls
 * vda5050_connector__srv__SupportedActions_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
void
vda5050_connector__srv__SupportedActions_Response__Sequence__fini(vda5050_connector__srv__SupportedActions_Response__Sequence * array);

/// Create array of srv/SupportedActions messages.
/**
 * It allocates the memory for the array and calls
 * vda5050_connector__srv__SupportedActions_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
vda5050_connector__srv__SupportedActions_Response__Sequence *
vda5050_connector__srv__SupportedActions_Response__Sequence__create(size_t size);

/// Destroy array of srv/SupportedActions messages.
/**
 * It calls
 * vda5050_connector__srv__SupportedActions_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
void
vda5050_connector__srv__SupportedActions_Response__Sequence__destroy(vda5050_connector__srv__SupportedActions_Response__Sequence * array);

/// Check for srv/SupportedActions message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
bool
vda5050_connector__srv__SupportedActions_Response__Sequence__are_equal(const vda5050_connector__srv__SupportedActions_Response__Sequence * lhs, const vda5050_connector__srv__SupportedActions_Response__Sequence * rhs);

/// Copy an array of srv/SupportedActions messages.
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
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
bool
vda5050_connector__srv__SupportedActions_Response__Sequence__copy(
  const vda5050_connector__srv__SupportedActions_Response__Sequence * input,
  vda5050_connector__srv__SupportedActions_Response__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // VDA5050_CONNECTOR__SRV__DETAIL__SUPPORTED_ACTIONS__FUNCTIONS_H_
