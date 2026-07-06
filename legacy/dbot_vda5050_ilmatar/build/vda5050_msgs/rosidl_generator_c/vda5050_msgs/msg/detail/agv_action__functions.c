// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from vda5050_msgs:msg/AGVAction.idl
// generated code does not contain a copyright notice
#include "vda5050_msgs/msg/detail/agv_action__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `action_type`
// Member `action_description`
// Member `action_scopes`
// Member `result_description`
#include "rosidl_runtime_c/string_functions.h"
// Member `action_parameters`
#include "vda5050_msgs/msg/detail/action_parameter_definition__functions.h"

bool
vda5050_msgs__msg__AGVAction__init(vda5050_msgs__msg__AGVAction * msg)
{
  if (!msg) {
    return false;
  }
  // action_type
  if (!rosidl_runtime_c__String__init(&msg->action_type)) {
    vda5050_msgs__msg__AGVAction__fini(msg);
    return false;
  }
  // action_description
  if (!rosidl_runtime_c__String__init(&msg->action_description)) {
    vda5050_msgs__msg__AGVAction__fini(msg);
    return false;
  }
  // action_scopes
  if (!rosidl_runtime_c__String__Sequence__init(&msg->action_scopes, 0)) {
    vda5050_msgs__msg__AGVAction__fini(msg);
    return false;
  }
  // action_parameters
  if (!vda5050_msgs__msg__ActionParameterDefinition__Sequence__init(&msg->action_parameters, 0)) {
    vda5050_msgs__msg__AGVAction__fini(msg);
    return false;
  }
  // result_description
  if (!rosidl_runtime_c__String__init(&msg->result_description)) {
    vda5050_msgs__msg__AGVAction__fini(msg);
    return false;
  }
  return true;
}

void
vda5050_msgs__msg__AGVAction__fini(vda5050_msgs__msg__AGVAction * msg)
{
  if (!msg) {
    return;
  }
  // action_type
  rosidl_runtime_c__String__fini(&msg->action_type);
  // action_description
  rosidl_runtime_c__String__fini(&msg->action_description);
  // action_scopes
  rosidl_runtime_c__String__Sequence__fini(&msg->action_scopes);
  // action_parameters
  vda5050_msgs__msg__ActionParameterDefinition__Sequence__fini(&msg->action_parameters);
  // result_description
  rosidl_runtime_c__String__fini(&msg->result_description);
}

bool
vda5050_msgs__msg__AGVAction__are_equal(const vda5050_msgs__msg__AGVAction * lhs, const vda5050_msgs__msg__AGVAction * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // action_type
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->action_type), &(rhs->action_type)))
  {
    return false;
  }
  // action_description
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->action_description), &(rhs->action_description)))
  {
    return false;
  }
  // action_scopes
  if (!rosidl_runtime_c__String__Sequence__are_equal(
      &(lhs->action_scopes), &(rhs->action_scopes)))
  {
    return false;
  }
  // action_parameters
  if (!vda5050_msgs__msg__ActionParameterDefinition__Sequence__are_equal(
      &(lhs->action_parameters), &(rhs->action_parameters)))
  {
    return false;
  }
  // result_description
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->result_description), &(rhs->result_description)))
  {
    return false;
  }
  return true;
}

bool
vda5050_msgs__msg__AGVAction__copy(
  const vda5050_msgs__msg__AGVAction * input,
  vda5050_msgs__msg__AGVAction * output)
{
  if (!input || !output) {
    return false;
  }
  // action_type
  if (!rosidl_runtime_c__String__copy(
      &(input->action_type), &(output->action_type)))
  {
    return false;
  }
  // action_description
  if (!rosidl_runtime_c__String__copy(
      &(input->action_description), &(output->action_description)))
  {
    return false;
  }
  // action_scopes
  if (!rosidl_runtime_c__String__Sequence__copy(
      &(input->action_scopes), &(output->action_scopes)))
  {
    return false;
  }
  // action_parameters
  if (!vda5050_msgs__msg__ActionParameterDefinition__Sequence__copy(
      &(input->action_parameters), &(output->action_parameters)))
  {
    return false;
  }
  // result_description
  if (!rosidl_runtime_c__String__copy(
      &(input->result_description), &(output->result_description)))
  {
    return false;
  }
  return true;
}

vda5050_msgs__msg__AGVAction *
vda5050_msgs__msg__AGVAction__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__AGVAction * msg = (vda5050_msgs__msg__AGVAction *)allocator.allocate(sizeof(vda5050_msgs__msg__AGVAction), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vda5050_msgs__msg__AGVAction));
  bool success = vda5050_msgs__msg__AGVAction__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vda5050_msgs__msg__AGVAction__destroy(vda5050_msgs__msg__AGVAction * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vda5050_msgs__msg__AGVAction__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vda5050_msgs__msg__AGVAction__Sequence__init(vda5050_msgs__msg__AGVAction__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__AGVAction * data = NULL;

  if (size) {
    data = (vda5050_msgs__msg__AGVAction *)allocator.zero_allocate(size, sizeof(vda5050_msgs__msg__AGVAction), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vda5050_msgs__msg__AGVAction__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vda5050_msgs__msg__AGVAction__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
vda5050_msgs__msg__AGVAction__Sequence__fini(vda5050_msgs__msg__AGVAction__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      vda5050_msgs__msg__AGVAction__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

vda5050_msgs__msg__AGVAction__Sequence *
vda5050_msgs__msg__AGVAction__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__AGVAction__Sequence * array = (vda5050_msgs__msg__AGVAction__Sequence *)allocator.allocate(sizeof(vda5050_msgs__msg__AGVAction__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vda5050_msgs__msg__AGVAction__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vda5050_msgs__msg__AGVAction__Sequence__destroy(vda5050_msgs__msg__AGVAction__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vda5050_msgs__msg__AGVAction__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vda5050_msgs__msg__AGVAction__Sequence__are_equal(const vda5050_msgs__msg__AGVAction__Sequence * lhs, const vda5050_msgs__msg__AGVAction__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vda5050_msgs__msg__AGVAction__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vda5050_msgs__msg__AGVAction__Sequence__copy(
  const vda5050_msgs__msg__AGVAction__Sequence * input,
  vda5050_msgs__msg__AGVAction__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vda5050_msgs__msg__AGVAction);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    vda5050_msgs__msg__AGVAction * data =
      (vda5050_msgs__msg__AGVAction *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vda5050_msgs__msg__AGVAction__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          vda5050_msgs__msg__AGVAction__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vda5050_msgs__msg__AGVAction__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
