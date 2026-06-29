// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from vda5050_msgs:msg/CurrentAction.idl
// generated code does not contain a copyright notice
#include "vda5050_msgs/msg/detail/current_action__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `action_id`
// Member `action_type`
// Member `action_description`
// Member `action_status`
// Member `result_description`
#include "rosidl_runtime_c/string_functions.h"

bool
vda5050_msgs__msg__CurrentAction__init(vda5050_msgs__msg__CurrentAction * msg)
{
  if (!msg) {
    return false;
  }
  // action_id
  if (!rosidl_runtime_c__String__init(&msg->action_id)) {
    vda5050_msgs__msg__CurrentAction__fini(msg);
    return false;
  }
  // action_type
  if (!rosidl_runtime_c__String__init(&msg->action_type)) {
    vda5050_msgs__msg__CurrentAction__fini(msg);
    return false;
  }
  // action_description
  if (!rosidl_runtime_c__String__init(&msg->action_description)) {
    vda5050_msgs__msg__CurrentAction__fini(msg);
    return false;
  }
  // action_status
  if (!rosidl_runtime_c__String__init(&msg->action_status)) {
    vda5050_msgs__msg__CurrentAction__fini(msg);
    return false;
  }
  // result_description
  if (!rosidl_runtime_c__String__init(&msg->result_description)) {
    vda5050_msgs__msg__CurrentAction__fini(msg);
    return false;
  }
  return true;
}

void
vda5050_msgs__msg__CurrentAction__fini(vda5050_msgs__msg__CurrentAction * msg)
{
  if (!msg) {
    return;
  }
  // action_id
  rosidl_runtime_c__String__fini(&msg->action_id);
  // action_type
  rosidl_runtime_c__String__fini(&msg->action_type);
  // action_description
  rosidl_runtime_c__String__fini(&msg->action_description);
  // action_status
  rosidl_runtime_c__String__fini(&msg->action_status);
  // result_description
  rosidl_runtime_c__String__fini(&msg->result_description);
}

bool
vda5050_msgs__msg__CurrentAction__are_equal(const vda5050_msgs__msg__CurrentAction * lhs, const vda5050_msgs__msg__CurrentAction * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // action_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->action_id), &(rhs->action_id)))
  {
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
  // action_status
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->action_status), &(rhs->action_status)))
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
vda5050_msgs__msg__CurrentAction__copy(
  const vda5050_msgs__msg__CurrentAction * input,
  vda5050_msgs__msg__CurrentAction * output)
{
  if (!input || !output) {
    return false;
  }
  // action_id
  if (!rosidl_runtime_c__String__copy(
      &(input->action_id), &(output->action_id)))
  {
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
  // action_status
  if (!rosidl_runtime_c__String__copy(
      &(input->action_status), &(output->action_status)))
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

vda5050_msgs__msg__CurrentAction *
vda5050_msgs__msg__CurrentAction__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__CurrentAction * msg = (vda5050_msgs__msg__CurrentAction *)allocator.allocate(sizeof(vda5050_msgs__msg__CurrentAction), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vda5050_msgs__msg__CurrentAction));
  bool success = vda5050_msgs__msg__CurrentAction__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vda5050_msgs__msg__CurrentAction__destroy(vda5050_msgs__msg__CurrentAction * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vda5050_msgs__msg__CurrentAction__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vda5050_msgs__msg__CurrentAction__Sequence__init(vda5050_msgs__msg__CurrentAction__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__CurrentAction * data = NULL;

  if (size) {
    data = (vda5050_msgs__msg__CurrentAction *)allocator.zero_allocate(size, sizeof(vda5050_msgs__msg__CurrentAction), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vda5050_msgs__msg__CurrentAction__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vda5050_msgs__msg__CurrentAction__fini(&data[i - 1]);
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
vda5050_msgs__msg__CurrentAction__Sequence__fini(vda5050_msgs__msg__CurrentAction__Sequence * array)
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
      vda5050_msgs__msg__CurrentAction__fini(&array->data[i]);
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

vda5050_msgs__msg__CurrentAction__Sequence *
vda5050_msgs__msg__CurrentAction__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__CurrentAction__Sequence * array = (vda5050_msgs__msg__CurrentAction__Sequence *)allocator.allocate(sizeof(vda5050_msgs__msg__CurrentAction__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vda5050_msgs__msg__CurrentAction__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vda5050_msgs__msg__CurrentAction__Sequence__destroy(vda5050_msgs__msg__CurrentAction__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vda5050_msgs__msg__CurrentAction__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vda5050_msgs__msg__CurrentAction__Sequence__are_equal(const vda5050_msgs__msg__CurrentAction__Sequence * lhs, const vda5050_msgs__msg__CurrentAction__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vda5050_msgs__msg__CurrentAction__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vda5050_msgs__msg__CurrentAction__Sequence__copy(
  const vda5050_msgs__msg__CurrentAction__Sequence * input,
  vda5050_msgs__msg__CurrentAction__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vda5050_msgs__msg__CurrentAction);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    vda5050_msgs__msg__CurrentAction * data =
      (vda5050_msgs__msg__CurrentAction *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vda5050_msgs__msg__CurrentAction__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          vda5050_msgs__msg__CurrentAction__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vda5050_msgs__msg__CurrentAction__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
