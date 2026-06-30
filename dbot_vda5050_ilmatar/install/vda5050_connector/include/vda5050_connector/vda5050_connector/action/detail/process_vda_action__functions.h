// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from vda5050_connector:action/ProcessVDAAction.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_CONNECTOR__ACTION__DETAIL__PROCESS_VDA_ACTION__FUNCTIONS_H_
#define VDA5050_CONNECTOR__ACTION__DETAIL__PROCESS_VDA_ACTION__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "vda5050_connector/msg/rosidl_generator_c__visibility_control.h"

#include "vda5050_connector/action/detail/process_vda_action__struct.h"

/// Initialize action/ProcessVDAAction message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * vda5050_connector__action__ProcessVDAAction_Goal
 * )) before or use
 * vda5050_connector__action__ProcessVDAAction_Goal__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
bool
vda5050_connector__action__ProcessVDAAction_Goal__init(vda5050_connector__action__ProcessVDAAction_Goal * msg);

/// Finalize action/ProcessVDAAction message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
void
vda5050_connector__action__ProcessVDAAction_Goal__fini(vda5050_connector__action__ProcessVDAAction_Goal * msg);

/// Create action/ProcessVDAAction message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * vda5050_connector__action__ProcessVDAAction_Goal__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
vda5050_connector__action__ProcessVDAAction_Goal *
vda5050_connector__action__ProcessVDAAction_Goal__create();

/// Destroy action/ProcessVDAAction message.
/**
 * It calls
 * vda5050_connector__action__ProcessVDAAction_Goal__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
void
vda5050_connector__action__ProcessVDAAction_Goal__destroy(vda5050_connector__action__ProcessVDAAction_Goal * msg);

/// Check for action/ProcessVDAAction message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
bool
vda5050_connector__action__ProcessVDAAction_Goal__are_equal(const vda5050_connector__action__ProcessVDAAction_Goal * lhs, const vda5050_connector__action__ProcessVDAAction_Goal * rhs);

/// Copy a action/ProcessVDAAction message.
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
vda5050_connector__action__ProcessVDAAction_Goal__copy(
  const vda5050_connector__action__ProcessVDAAction_Goal * input,
  vda5050_connector__action__ProcessVDAAction_Goal * output);

/// Initialize array of action/ProcessVDAAction messages.
/**
 * It allocates the memory for the number of elements and calls
 * vda5050_connector__action__ProcessVDAAction_Goal__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
bool
vda5050_connector__action__ProcessVDAAction_Goal__Sequence__init(vda5050_connector__action__ProcessVDAAction_Goal__Sequence * array, size_t size);

/// Finalize array of action/ProcessVDAAction messages.
/**
 * It calls
 * vda5050_connector__action__ProcessVDAAction_Goal__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
void
vda5050_connector__action__ProcessVDAAction_Goal__Sequence__fini(vda5050_connector__action__ProcessVDAAction_Goal__Sequence * array);

/// Create array of action/ProcessVDAAction messages.
/**
 * It allocates the memory for the array and calls
 * vda5050_connector__action__ProcessVDAAction_Goal__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
vda5050_connector__action__ProcessVDAAction_Goal__Sequence *
vda5050_connector__action__ProcessVDAAction_Goal__Sequence__create(size_t size);

/// Destroy array of action/ProcessVDAAction messages.
/**
 * It calls
 * vda5050_connector__action__ProcessVDAAction_Goal__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
void
vda5050_connector__action__ProcessVDAAction_Goal__Sequence__destroy(vda5050_connector__action__ProcessVDAAction_Goal__Sequence * array);

/// Check for action/ProcessVDAAction message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
bool
vda5050_connector__action__ProcessVDAAction_Goal__Sequence__are_equal(const vda5050_connector__action__ProcessVDAAction_Goal__Sequence * lhs, const vda5050_connector__action__ProcessVDAAction_Goal__Sequence * rhs);

/// Copy an array of action/ProcessVDAAction messages.
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
vda5050_connector__action__ProcessVDAAction_Goal__Sequence__copy(
  const vda5050_connector__action__ProcessVDAAction_Goal__Sequence * input,
  vda5050_connector__action__ProcessVDAAction_Goal__Sequence * output);

/// Initialize action/ProcessVDAAction message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * vda5050_connector__action__ProcessVDAAction_Result
 * )) before or use
 * vda5050_connector__action__ProcessVDAAction_Result__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
bool
vda5050_connector__action__ProcessVDAAction_Result__init(vda5050_connector__action__ProcessVDAAction_Result * msg);

/// Finalize action/ProcessVDAAction message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
void
vda5050_connector__action__ProcessVDAAction_Result__fini(vda5050_connector__action__ProcessVDAAction_Result * msg);

/// Create action/ProcessVDAAction message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * vda5050_connector__action__ProcessVDAAction_Result__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
vda5050_connector__action__ProcessVDAAction_Result *
vda5050_connector__action__ProcessVDAAction_Result__create();

/// Destroy action/ProcessVDAAction message.
/**
 * It calls
 * vda5050_connector__action__ProcessVDAAction_Result__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
void
vda5050_connector__action__ProcessVDAAction_Result__destroy(vda5050_connector__action__ProcessVDAAction_Result * msg);

/// Check for action/ProcessVDAAction message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
bool
vda5050_connector__action__ProcessVDAAction_Result__are_equal(const vda5050_connector__action__ProcessVDAAction_Result * lhs, const vda5050_connector__action__ProcessVDAAction_Result * rhs);

/// Copy a action/ProcessVDAAction message.
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
vda5050_connector__action__ProcessVDAAction_Result__copy(
  const vda5050_connector__action__ProcessVDAAction_Result * input,
  vda5050_connector__action__ProcessVDAAction_Result * output);

/// Initialize array of action/ProcessVDAAction messages.
/**
 * It allocates the memory for the number of elements and calls
 * vda5050_connector__action__ProcessVDAAction_Result__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
bool
vda5050_connector__action__ProcessVDAAction_Result__Sequence__init(vda5050_connector__action__ProcessVDAAction_Result__Sequence * array, size_t size);

/// Finalize array of action/ProcessVDAAction messages.
/**
 * It calls
 * vda5050_connector__action__ProcessVDAAction_Result__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
void
vda5050_connector__action__ProcessVDAAction_Result__Sequence__fini(vda5050_connector__action__ProcessVDAAction_Result__Sequence * array);

/// Create array of action/ProcessVDAAction messages.
/**
 * It allocates the memory for the array and calls
 * vda5050_connector__action__ProcessVDAAction_Result__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
vda5050_connector__action__ProcessVDAAction_Result__Sequence *
vda5050_connector__action__ProcessVDAAction_Result__Sequence__create(size_t size);

/// Destroy array of action/ProcessVDAAction messages.
/**
 * It calls
 * vda5050_connector__action__ProcessVDAAction_Result__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
void
vda5050_connector__action__ProcessVDAAction_Result__Sequence__destroy(vda5050_connector__action__ProcessVDAAction_Result__Sequence * array);

/// Check for action/ProcessVDAAction message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
bool
vda5050_connector__action__ProcessVDAAction_Result__Sequence__are_equal(const vda5050_connector__action__ProcessVDAAction_Result__Sequence * lhs, const vda5050_connector__action__ProcessVDAAction_Result__Sequence * rhs);

/// Copy an array of action/ProcessVDAAction messages.
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
vda5050_connector__action__ProcessVDAAction_Result__Sequence__copy(
  const vda5050_connector__action__ProcessVDAAction_Result__Sequence * input,
  vda5050_connector__action__ProcessVDAAction_Result__Sequence * output);

/// Initialize action/ProcessVDAAction message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * vda5050_connector__action__ProcessVDAAction_Feedback
 * )) before or use
 * vda5050_connector__action__ProcessVDAAction_Feedback__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
bool
vda5050_connector__action__ProcessVDAAction_Feedback__init(vda5050_connector__action__ProcessVDAAction_Feedback * msg);

/// Finalize action/ProcessVDAAction message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
void
vda5050_connector__action__ProcessVDAAction_Feedback__fini(vda5050_connector__action__ProcessVDAAction_Feedback * msg);

/// Create action/ProcessVDAAction message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * vda5050_connector__action__ProcessVDAAction_Feedback__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
vda5050_connector__action__ProcessVDAAction_Feedback *
vda5050_connector__action__ProcessVDAAction_Feedback__create();

/// Destroy action/ProcessVDAAction message.
/**
 * It calls
 * vda5050_connector__action__ProcessVDAAction_Feedback__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
void
vda5050_connector__action__ProcessVDAAction_Feedback__destroy(vda5050_connector__action__ProcessVDAAction_Feedback * msg);

/// Check for action/ProcessVDAAction message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
bool
vda5050_connector__action__ProcessVDAAction_Feedback__are_equal(const vda5050_connector__action__ProcessVDAAction_Feedback * lhs, const vda5050_connector__action__ProcessVDAAction_Feedback * rhs);

/// Copy a action/ProcessVDAAction message.
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
vda5050_connector__action__ProcessVDAAction_Feedback__copy(
  const vda5050_connector__action__ProcessVDAAction_Feedback * input,
  vda5050_connector__action__ProcessVDAAction_Feedback * output);

/// Initialize array of action/ProcessVDAAction messages.
/**
 * It allocates the memory for the number of elements and calls
 * vda5050_connector__action__ProcessVDAAction_Feedback__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
bool
vda5050_connector__action__ProcessVDAAction_Feedback__Sequence__init(vda5050_connector__action__ProcessVDAAction_Feedback__Sequence * array, size_t size);

/// Finalize array of action/ProcessVDAAction messages.
/**
 * It calls
 * vda5050_connector__action__ProcessVDAAction_Feedback__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
void
vda5050_connector__action__ProcessVDAAction_Feedback__Sequence__fini(vda5050_connector__action__ProcessVDAAction_Feedback__Sequence * array);

/// Create array of action/ProcessVDAAction messages.
/**
 * It allocates the memory for the array and calls
 * vda5050_connector__action__ProcessVDAAction_Feedback__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
vda5050_connector__action__ProcessVDAAction_Feedback__Sequence *
vda5050_connector__action__ProcessVDAAction_Feedback__Sequence__create(size_t size);

/// Destroy array of action/ProcessVDAAction messages.
/**
 * It calls
 * vda5050_connector__action__ProcessVDAAction_Feedback__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
void
vda5050_connector__action__ProcessVDAAction_Feedback__Sequence__destroy(vda5050_connector__action__ProcessVDAAction_Feedback__Sequence * array);

/// Check for action/ProcessVDAAction message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
bool
vda5050_connector__action__ProcessVDAAction_Feedback__Sequence__are_equal(const vda5050_connector__action__ProcessVDAAction_Feedback__Sequence * lhs, const vda5050_connector__action__ProcessVDAAction_Feedback__Sequence * rhs);

/// Copy an array of action/ProcessVDAAction messages.
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
vda5050_connector__action__ProcessVDAAction_Feedback__Sequence__copy(
  const vda5050_connector__action__ProcessVDAAction_Feedback__Sequence * input,
  vda5050_connector__action__ProcessVDAAction_Feedback__Sequence * output);

/// Initialize action/ProcessVDAAction message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * vda5050_connector__action__ProcessVDAAction_SendGoal_Request
 * )) before or use
 * vda5050_connector__action__ProcessVDAAction_SendGoal_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
bool
vda5050_connector__action__ProcessVDAAction_SendGoal_Request__init(vda5050_connector__action__ProcessVDAAction_SendGoal_Request * msg);

/// Finalize action/ProcessVDAAction message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
void
vda5050_connector__action__ProcessVDAAction_SendGoal_Request__fini(vda5050_connector__action__ProcessVDAAction_SendGoal_Request * msg);

/// Create action/ProcessVDAAction message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * vda5050_connector__action__ProcessVDAAction_SendGoal_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
vda5050_connector__action__ProcessVDAAction_SendGoal_Request *
vda5050_connector__action__ProcessVDAAction_SendGoal_Request__create();

/// Destroy action/ProcessVDAAction message.
/**
 * It calls
 * vda5050_connector__action__ProcessVDAAction_SendGoal_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
void
vda5050_connector__action__ProcessVDAAction_SendGoal_Request__destroy(vda5050_connector__action__ProcessVDAAction_SendGoal_Request * msg);

/// Check for action/ProcessVDAAction message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
bool
vda5050_connector__action__ProcessVDAAction_SendGoal_Request__are_equal(const vda5050_connector__action__ProcessVDAAction_SendGoal_Request * lhs, const vda5050_connector__action__ProcessVDAAction_SendGoal_Request * rhs);

/// Copy a action/ProcessVDAAction message.
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
vda5050_connector__action__ProcessVDAAction_SendGoal_Request__copy(
  const vda5050_connector__action__ProcessVDAAction_SendGoal_Request * input,
  vda5050_connector__action__ProcessVDAAction_SendGoal_Request * output);

/// Initialize array of action/ProcessVDAAction messages.
/**
 * It allocates the memory for the number of elements and calls
 * vda5050_connector__action__ProcessVDAAction_SendGoal_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
bool
vda5050_connector__action__ProcessVDAAction_SendGoal_Request__Sequence__init(vda5050_connector__action__ProcessVDAAction_SendGoal_Request__Sequence * array, size_t size);

/// Finalize array of action/ProcessVDAAction messages.
/**
 * It calls
 * vda5050_connector__action__ProcessVDAAction_SendGoal_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
void
vda5050_connector__action__ProcessVDAAction_SendGoal_Request__Sequence__fini(vda5050_connector__action__ProcessVDAAction_SendGoal_Request__Sequence * array);

/// Create array of action/ProcessVDAAction messages.
/**
 * It allocates the memory for the array and calls
 * vda5050_connector__action__ProcessVDAAction_SendGoal_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
vda5050_connector__action__ProcessVDAAction_SendGoal_Request__Sequence *
vda5050_connector__action__ProcessVDAAction_SendGoal_Request__Sequence__create(size_t size);

/// Destroy array of action/ProcessVDAAction messages.
/**
 * It calls
 * vda5050_connector__action__ProcessVDAAction_SendGoal_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
void
vda5050_connector__action__ProcessVDAAction_SendGoal_Request__Sequence__destroy(vda5050_connector__action__ProcessVDAAction_SendGoal_Request__Sequence * array);

/// Check for action/ProcessVDAAction message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
bool
vda5050_connector__action__ProcessVDAAction_SendGoal_Request__Sequence__are_equal(const vda5050_connector__action__ProcessVDAAction_SendGoal_Request__Sequence * lhs, const vda5050_connector__action__ProcessVDAAction_SendGoal_Request__Sequence * rhs);

/// Copy an array of action/ProcessVDAAction messages.
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
vda5050_connector__action__ProcessVDAAction_SendGoal_Request__Sequence__copy(
  const vda5050_connector__action__ProcessVDAAction_SendGoal_Request__Sequence * input,
  vda5050_connector__action__ProcessVDAAction_SendGoal_Request__Sequence * output);

/// Initialize action/ProcessVDAAction message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * vda5050_connector__action__ProcessVDAAction_SendGoal_Response
 * )) before or use
 * vda5050_connector__action__ProcessVDAAction_SendGoal_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
bool
vda5050_connector__action__ProcessVDAAction_SendGoal_Response__init(vda5050_connector__action__ProcessVDAAction_SendGoal_Response * msg);

/// Finalize action/ProcessVDAAction message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
void
vda5050_connector__action__ProcessVDAAction_SendGoal_Response__fini(vda5050_connector__action__ProcessVDAAction_SendGoal_Response * msg);

/// Create action/ProcessVDAAction message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * vda5050_connector__action__ProcessVDAAction_SendGoal_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
vda5050_connector__action__ProcessVDAAction_SendGoal_Response *
vda5050_connector__action__ProcessVDAAction_SendGoal_Response__create();

/// Destroy action/ProcessVDAAction message.
/**
 * It calls
 * vda5050_connector__action__ProcessVDAAction_SendGoal_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
void
vda5050_connector__action__ProcessVDAAction_SendGoal_Response__destroy(vda5050_connector__action__ProcessVDAAction_SendGoal_Response * msg);

/// Check for action/ProcessVDAAction message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
bool
vda5050_connector__action__ProcessVDAAction_SendGoal_Response__are_equal(const vda5050_connector__action__ProcessVDAAction_SendGoal_Response * lhs, const vda5050_connector__action__ProcessVDAAction_SendGoal_Response * rhs);

/// Copy a action/ProcessVDAAction message.
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
vda5050_connector__action__ProcessVDAAction_SendGoal_Response__copy(
  const vda5050_connector__action__ProcessVDAAction_SendGoal_Response * input,
  vda5050_connector__action__ProcessVDAAction_SendGoal_Response * output);

/// Initialize array of action/ProcessVDAAction messages.
/**
 * It allocates the memory for the number of elements and calls
 * vda5050_connector__action__ProcessVDAAction_SendGoal_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
bool
vda5050_connector__action__ProcessVDAAction_SendGoal_Response__Sequence__init(vda5050_connector__action__ProcessVDAAction_SendGoal_Response__Sequence * array, size_t size);

/// Finalize array of action/ProcessVDAAction messages.
/**
 * It calls
 * vda5050_connector__action__ProcessVDAAction_SendGoal_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
void
vda5050_connector__action__ProcessVDAAction_SendGoal_Response__Sequence__fini(vda5050_connector__action__ProcessVDAAction_SendGoal_Response__Sequence * array);

/// Create array of action/ProcessVDAAction messages.
/**
 * It allocates the memory for the array and calls
 * vda5050_connector__action__ProcessVDAAction_SendGoal_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
vda5050_connector__action__ProcessVDAAction_SendGoal_Response__Sequence *
vda5050_connector__action__ProcessVDAAction_SendGoal_Response__Sequence__create(size_t size);

/// Destroy array of action/ProcessVDAAction messages.
/**
 * It calls
 * vda5050_connector__action__ProcessVDAAction_SendGoal_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
void
vda5050_connector__action__ProcessVDAAction_SendGoal_Response__Sequence__destroy(vda5050_connector__action__ProcessVDAAction_SendGoal_Response__Sequence * array);

/// Check for action/ProcessVDAAction message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
bool
vda5050_connector__action__ProcessVDAAction_SendGoal_Response__Sequence__are_equal(const vda5050_connector__action__ProcessVDAAction_SendGoal_Response__Sequence * lhs, const vda5050_connector__action__ProcessVDAAction_SendGoal_Response__Sequence * rhs);

/// Copy an array of action/ProcessVDAAction messages.
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
vda5050_connector__action__ProcessVDAAction_SendGoal_Response__Sequence__copy(
  const vda5050_connector__action__ProcessVDAAction_SendGoal_Response__Sequence * input,
  vda5050_connector__action__ProcessVDAAction_SendGoal_Response__Sequence * output);

/// Initialize action/ProcessVDAAction message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * vda5050_connector__action__ProcessVDAAction_GetResult_Request
 * )) before or use
 * vda5050_connector__action__ProcessVDAAction_GetResult_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
bool
vda5050_connector__action__ProcessVDAAction_GetResult_Request__init(vda5050_connector__action__ProcessVDAAction_GetResult_Request * msg);

/// Finalize action/ProcessVDAAction message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
void
vda5050_connector__action__ProcessVDAAction_GetResult_Request__fini(vda5050_connector__action__ProcessVDAAction_GetResult_Request * msg);

/// Create action/ProcessVDAAction message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * vda5050_connector__action__ProcessVDAAction_GetResult_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
vda5050_connector__action__ProcessVDAAction_GetResult_Request *
vda5050_connector__action__ProcessVDAAction_GetResult_Request__create();

/// Destroy action/ProcessVDAAction message.
/**
 * It calls
 * vda5050_connector__action__ProcessVDAAction_GetResult_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
void
vda5050_connector__action__ProcessVDAAction_GetResult_Request__destroy(vda5050_connector__action__ProcessVDAAction_GetResult_Request * msg);

/// Check for action/ProcessVDAAction message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
bool
vda5050_connector__action__ProcessVDAAction_GetResult_Request__are_equal(const vda5050_connector__action__ProcessVDAAction_GetResult_Request * lhs, const vda5050_connector__action__ProcessVDAAction_GetResult_Request * rhs);

/// Copy a action/ProcessVDAAction message.
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
vda5050_connector__action__ProcessVDAAction_GetResult_Request__copy(
  const vda5050_connector__action__ProcessVDAAction_GetResult_Request * input,
  vda5050_connector__action__ProcessVDAAction_GetResult_Request * output);

/// Initialize array of action/ProcessVDAAction messages.
/**
 * It allocates the memory for the number of elements and calls
 * vda5050_connector__action__ProcessVDAAction_GetResult_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
bool
vda5050_connector__action__ProcessVDAAction_GetResult_Request__Sequence__init(vda5050_connector__action__ProcessVDAAction_GetResult_Request__Sequence * array, size_t size);

/// Finalize array of action/ProcessVDAAction messages.
/**
 * It calls
 * vda5050_connector__action__ProcessVDAAction_GetResult_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
void
vda5050_connector__action__ProcessVDAAction_GetResult_Request__Sequence__fini(vda5050_connector__action__ProcessVDAAction_GetResult_Request__Sequence * array);

/// Create array of action/ProcessVDAAction messages.
/**
 * It allocates the memory for the array and calls
 * vda5050_connector__action__ProcessVDAAction_GetResult_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
vda5050_connector__action__ProcessVDAAction_GetResult_Request__Sequence *
vda5050_connector__action__ProcessVDAAction_GetResult_Request__Sequence__create(size_t size);

/// Destroy array of action/ProcessVDAAction messages.
/**
 * It calls
 * vda5050_connector__action__ProcessVDAAction_GetResult_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
void
vda5050_connector__action__ProcessVDAAction_GetResult_Request__Sequence__destroy(vda5050_connector__action__ProcessVDAAction_GetResult_Request__Sequence * array);

/// Check for action/ProcessVDAAction message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
bool
vda5050_connector__action__ProcessVDAAction_GetResult_Request__Sequence__are_equal(const vda5050_connector__action__ProcessVDAAction_GetResult_Request__Sequence * lhs, const vda5050_connector__action__ProcessVDAAction_GetResult_Request__Sequence * rhs);

/// Copy an array of action/ProcessVDAAction messages.
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
vda5050_connector__action__ProcessVDAAction_GetResult_Request__Sequence__copy(
  const vda5050_connector__action__ProcessVDAAction_GetResult_Request__Sequence * input,
  vda5050_connector__action__ProcessVDAAction_GetResult_Request__Sequence * output);

/// Initialize action/ProcessVDAAction message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * vda5050_connector__action__ProcessVDAAction_GetResult_Response
 * )) before or use
 * vda5050_connector__action__ProcessVDAAction_GetResult_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
bool
vda5050_connector__action__ProcessVDAAction_GetResult_Response__init(vda5050_connector__action__ProcessVDAAction_GetResult_Response * msg);

/// Finalize action/ProcessVDAAction message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
void
vda5050_connector__action__ProcessVDAAction_GetResult_Response__fini(vda5050_connector__action__ProcessVDAAction_GetResult_Response * msg);

/// Create action/ProcessVDAAction message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * vda5050_connector__action__ProcessVDAAction_GetResult_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
vda5050_connector__action__ProcessVDAAction_GetResult_Response *
vda5050_connector__action__ProcessVDAAction_GetResult_Response__create();

/// Destroy action/ProcessVDAAction message.
/**
 * It calls
 * vda5050_connector__action__ProcessVDAAction_GetResult_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
void
vda5050_connector__action__ProcessVDAAction_GetResult_Response__destroy(vda5050_connector__action__ProcessVDAAction_GetResult_Response * msg);

/// Check for action/ProcessVDAAction message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
bool
vda5050_connector__action__ProcessVDAAction_GetResult_Response__are_equal(const vda5050_connector__action__ProcessVDAAction_GetResult_Response * lhs, const vda5050_connector__action__ProcessVDAAction_GetResult_Response * rhs);

/// Copy a action/ProcessVDAAction message.
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
vda5050_connector__action__ProcessVDAAction_GetResult_Response__copy(
  const vda5050_connector__action__ProcessVDAAction_GetResult_Response * input,
  vda5050_connector__action__ProcessVDAAction_GetResult_Response * output);

/// Initialize array of action/ProcessVDAAction messages.
/**
 * It allocates the memory for the number of elements and calls
 * vda5050_connector__action__ProcessVDAAction_GetResult_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
bool
vda5050_connector__action__ProcessVDAAction_GetResult_Response__Sequence__init(vda5050_connector__action__ProcessVDAAction_GetResult_Response__Sequence * array, size_t size);

/// Finalize array of action/ProcessVDAAction messages.
/**
 * It calls
 * vda5050_connector__action__ProcessVDAAction_GetResult_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
void
vda5050_connector__action__ProcessVDAAction_GetResult_Response__Sequence__fini(vda5050_connector__action__ProcessVDAAction_GetResult_Response__Sequence * array);

/// Create array of action/ProcessVDAAction messages.
/**
 * It allocates the memory for the array and calls
 * vda5050_connector__action__ProcessVDAAction_GetResult_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
vda5050_connector__action__ProcessVDAAction_GetResult_Response__Sequence *
vda5050_connector__action__ProcessVDAAction_GetResult_Response__Sequence__create(size_t size);

/// Destroy array of action/ProcessVDAAction messages.
/**
 * It calls
 * vda5050_connector__action__ProcessVDAAction_GetResult_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
void
vda5050_connector__action__ProcessVDAAction_GetResult_Response__Sequence__destroy(vda5050_connector__action__ProcessVDAAction_GetResult_Response__Sequence * array);

/// Check for action/ProcessVDAAction message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
bool
vda5050_connector__action__ProcessVDAAction_GetResult_Response__Sequence__are_equal(const vda5050_connector__action__ProcessVDAAction_GetResult_Response__Sequence * lhs, const vda5050_connector__action__ProcessVDAAction_GetResult_Response__Sequence * rhs);

/// Copy an array of action/ProcessVDAAction messages.
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
vda5050_connector__action__ProcessVDAAction_GetResult_Response__Sequence__copy(
  const vda5050_connector__action__ProcessVDAAction_GetResult_Response__Sequence * input,
  vda5050_connector__action__ProcessVDAAction_GetResult_Response__Sequence * output);

/// Initialize action/ProcessVDAAction message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * vda5050_connector__action__ProcessVDAAction_FeedbackMessage
 * )) before or use
 * vda5050_connector__action__ProcessVDAAction_FeedbackMessage__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
bool
vda5050_connector__action__ProcessVDAAction_FeedbackMessage__init(vda5050_connector__action__ProcessVDAAction_FeedbackMessage * msg);

/// Finalize action/ProcessVDAAction message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
void
vda5050_connector__action__ProcessVDAAction_FeedbackMessage__fini(vda5050_connector__action__ProcessVDAAction_FeedbackMessage * msg);

/// Create action/ProcessVDAAction message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * vda5050_connector__action__ProcessVDAAction_FeedbackMessage__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
vda5050_connector__action__ProcessVDAAction_FeedbackMessage *
vda5050_connector__action__ProcessVDAAction_FeedbackMessage__create();

/// Destroy action/ProcessVDAAction message.
/**
 * It calls
 * vda5050_connector__action__ProcessVDAAction_FeedbackMessage__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
void
vda5050_connector__action__ProcessVDAAction_FeedbackMessage__destroy(vda5050_connector__action__ProcessVDAAction_FeedbackMessage * msg);

/// Check for action/ProcessVDAAction message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
bool
vda5050_connector__action__ProcessVDAAction_FeedbackMessage__are_equal(const vda5050_connector__action__ProcessVDAAction_FeedbackMessage * lhs, const vda5050_connector__action__ProcessVDAAction_FeedbackMessage * rhs);

/// Copy a action/ProcessVDAAction message.
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
vda5050_connector__action__ProcessVDAAction_FeedbackMessage__copy(
  const vda5050_connector__action__ProcessVDAAction_FeedbackMessage * input,
  vda5050_connector__action__ProcessVDAAction_FeedbackMessage * output);

/// Initialize array of action/ProcessVDAAction messages.
/**
 * It allocates the memory for the number of elements and calls
 * vda5050_connector__action__ProcessVDAAction_FeedbackMessage__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
bool
vda5050_connector__action__ProcessVDAAction_FeedbackMessage__Sequence__init(vda5050_connector__action__ProcessVDAAction_FeedbackMessage__Sequence * array, size_t size);

/// Finalize array of action/ProcessVDAAction messages.
/**
 * It calls
 * vda5050_connector__action__ProcessVDAAction_FeedbackMessage__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
void
vda5050_connector__action__ProcessVDAAction_FeedbackMessage__Sequence__fini(vda5050_connector__action__ProcessVDAAction_FeedbackMessage__Sequence * array);

/// Create array of action/ProcessVDAAction messages.
/**
 * It allocates the memory for the array and calls
 * vda5050_connector__action__ProcessVDAAction_FeedbackMessage__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
vda5050_connector__action__ProcessVDAAction_FeedbackMessage__Sequence *
vda5050_connector__action__ProcessVDAAction_FeedbackMessage__Sequence__create(size_t size);

/// Destroy array of action/ProcessVDAAction messages.
/**
 * It calls
 * vda5050_connector__action__ProcessVDAAction_FeedbackMessage__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
void
vda5050_connector__action__ProcessVDAAction_FeedbackMessage__Sequence__destroy(vda5050_connector__action__ProcessVDAAction_FeedbackMessage__Sequence * array);

/// Check for action/ProcessVDAAction message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_vda5050_connector
bool
vda5050_connector__action__ProcessVDAAction_FeedbackMessage__Sequence__are_equal(const vda5050_connector__action__ProcessVDAAction_FeedbackMessage__Sequence * lhs, const vda5050_connector__action__ProcessVDAAction_FeedbackMessage__Sequence * rhs);

/// Copy an array of action/ProcessVDAAction messages.
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
vda5050_connector__action__ProcessVDAAction_FeedbackMessage__Sequence__copy(
  const vda5050_connector__action__ProcessVDAAction_FeedbackMessage__Sequence * input,
  vda5050_connector__action__ProcessVDAAction_FeedbackMessage__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // VDA5050_CONNECTOR__ACTION__DETAIL__PROCESS_VDA_ACTION__FUNCTIONS_H_
