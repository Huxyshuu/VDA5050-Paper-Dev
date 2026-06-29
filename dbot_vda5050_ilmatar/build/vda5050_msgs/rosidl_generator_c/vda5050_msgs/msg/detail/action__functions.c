// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from vda5050_msgs:msg/Action.idl
// generated code does not contain a copyright notice
#include "vda5050_msgs/msg/detail/action__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `action_type`
// Member `action_id`
// Member `action_description`
// Member `blocking_type`
#include "rosidl_runtime_c/string_functions.h"
// Member `action_parameters`
#include "vda5050_msgs/msg/detail/action_parameter__functions.h"

bool
vda5050_msgs__msg__Action__init(vda5050_msgs__msg__Action * msg)
{
  if (!msg) {
    return false;
  }
  // action_type
  if (!rosidl_runtime_c__String__init(&msg->action_type)) {
    vda5050_msgs__msg__Action__fini(msg);
    return false;
  }
  // action_id
  if (!rosidl_runtime_c__String__init(&msg->action_id)) {
    vda5050_msgs__msg__Action__fini(msg);
    return false;
  }
  // action_description
  if (!rosidl_runtime_c__String__init(&msg->action_description)) {
    vda5050_msgs__msg__Action__fini(msg);
    return false;
  }
  // blocking_type
  if (!rosidl_runtime_c__String__init(&msg->blocking_type)) {
    vda5050_msgs__msg__Action__fini(msg);
    return false;
  }
  // action_parameters
  if (!vda5050_msgs__msg__ActionParameter__Sequence__init(&msg->action_parameters, 0)) {
    vda5050_msgs__msg__Action__fini(msg);
    return false;
  }
  return true;
}

void
vda5050_msgs__msg__Action__fini(vda5050_msgs__msg__Action * msg)
{
  if (!msg) {
    return;
  }
  // action_type
  rosidl_runtime_c__String__fini(&msg->action_type);
  // action_id
  rosidl_runtime_c__String__fini(&msg->action_id);
  // action_description
  rosidl_runtime_c__String__fini(&msg->action_description);
  // blocking_type
  rosidl_runtime_c__String__fini(&msg->blocking_type);
  // action_parameters
  vda5050_msgs__msg__ActionParameter__Sequence__fini(&msg->action_parameters);
}

bool
vda5050_msgs__msg__Action__are_equal(const vda5050_msgs__msg__Action * lhs, const vda5050_msgs__msg__Action * rhs)
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
  // action_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->action_id), &(rhs->action_id)))
  {
    return false;
  }
  // action_description
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->action_description), &(rhs->action_description)))
  {
    return false;
  }
  // blocking_type
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->blocking_type), &(rhs->blocking_type)))
  {
    return false;
  }
  // action_parameters
  if (!vda5050_msgs__msg__ActionParameter__Sequence__are_equal(
      &(lhs->action_parameters), &(rhs->action_parameters)))
  {
    return false;
  }
  return true;
}

bool
vda5050_msgs__msg__Action__copy(
  const vda5050_msgs__msg__Action * input,
  vda5050_msgs__msg__Action * output)
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
  // action_id
  if (!rosidl_runtime_c__String__copy(
      &(input->action_id), &(output->action_id)))
  {
    return false;
  }
  // action_description
  if (!rosidl_runtime_c__String__copy(
      &(input->action_description), &(output->action_description)))
  {
    return false;
  }
  // blocking_type
  if (!rosidl_runtime_c__String__copy(
      &(input->blocking_type), &(output->blocking_type)))
  {
    return false;
  }
  // action_parameters
  if (!vda5050_msgs__msg__ActionParameter__Sequence__copy(
      &(input->action_parameters), &(output->action_parameters)))
  {
    return false;
  }
  return true;
}

vda5050_msgs__msg__Action *
vda5050_msgs__msg__Action__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__Action * msg = (vda5050_msgs__msg__Action *)allocator.allocate(sizeof(vda5050_msgs__msg__Action), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vda5050_msgs__msg__Action));
  bool success = vda5050_msgs__msg__Action__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vda5050_msgs__msg__Action__destroy(vda5050_msgs__msg__Action * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vda5050_msgs__msg__Action__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vda5050_msgs__msg__Action__Sequence__init(vda5050_msgs__msg__Action__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__Action * data = NULL;

  if (size) {
    data = (vda5050_msgs__msg__Action *)allocator.zero_allocate(size, sizeof(vda5050_msgs__msg__Action), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vda5050_msgs__msg__Action__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vda5050_msgs__msg__Action__fini(&data[i - 1]);
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
vda5050_msgs__msg__Action__Sequence__fini(vda5050_msgs__msg__Action__Sequence * array)
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
      vda5050_msgs__msg__Action__fini(&array->data[i]);
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

vda5050_msgs__msg__Action__Sequence *
vda5050_msgs__msg__Action__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__Action__Sequence * array = (vda5050_msgs__msg__Action__Sequence *)allocator.allocate(sizeof(vda5050_msgs__msg__Action__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vda5050_msgs__msg__Action__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vda5050_msgs__msg__Action__Sequence__destroy(vda5050_msgs__msg__Action__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vda5050_msgs__msg__Action__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vda5050_msgs__msg__Action__Sequence__are_equal(const vda5050_msgs__msg__Action__Sequence * lhs, const vda5050_msgs__msg__Action__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vda5050_msgs__msg__Action__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vda5050_msgs__msg__Action__Sequence__copy(
  const vda5050_msgs__msg__Action__Sequence * input,
  vda5050_msgs__msg__Action__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vda5050_msgs__msg__Action);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    vda5050_msgs__msg__Action * data =
      (vda5050_msgs__msg__Action *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vda5050_msgs__msg__Action__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          vda5050_msgs__msg__Action__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vda5050_msgs__msg__Action__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
