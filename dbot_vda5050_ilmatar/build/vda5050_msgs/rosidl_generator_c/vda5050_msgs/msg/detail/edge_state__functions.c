// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from vda5050_msgs:msg/EdgeState.idl
// generated code does not contain a copyright notice
#include "vda5050_msgs/msg/detail/edge_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `edge_id`
// Member `edge_description`
#include "rosidl_runtime_c/string_functions.h"
// Member `trajectory`
#include "vda5050_msgs/msg/detail/trajectory__functions.h"

bool
vda5050_msgs__msg__EdgeState__init(vda5050_msgs__msg__EdgeState * msg)
{
  if (!msg) {
    return false;
  }
  // edge_id
  if (!rosidl_runtime_c__String__init(&msg->edge_id)) {
    vda5050_msgs__msg__EdgeState__fini(msg);
    return false;
  }
  // sequence_id
  // edge_description
  if (!rosidl_runtime_c__String__init(&msg->edge_description)) {
    vda5050_msgs__msg__EdgeState__fini(msg);
    return false;
  }
  // released
  // trajectory
  if (!vda5050_msgs__msg__Trajectory__init(&msg->trajectory)) {
    vda5050_msgs__msg__EdgeState__fini(msg);
    return false;
  }
  return true;
}

void
vda5050_msgs__msg__EdgeState__fini(vda5050_msgs__msg__EdgeState * msg)
{
  if (!msg) {
    return;
  }
  // edge_id
  rosidl_runtime_c__String__fini(&msg->edge_id);
  // sequence_id
  // edge_description
  rosidl_runtime_c__String__fini(&msg->edge_description);
  // released
  // trajectory
  vda5050_msgs__msg__Trajectory__fini(&msg->trajectory);
}

bool
vda5050_msgs__msg__EdgeState__are_equal(const vda5050_msgs__msg__EdgeState * lhs, const vda5050_msgs__msg__EdgeState * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // edge_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->edge_id), &(rhs->edge_id)))
  {
    return false;
  }
  // sequence_id
  if (lhs->sequence_id != rhs->sequence_id) {
    return false;
  }
  // edge_description
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->edge_description), &(rhs->edge_description)))
  {
    return false;
  }
  // released
  if (lhs->released != rhs->released) {
    return false;
  }
  // trajectory
  if (!vda5050_msgs__msg__Trajectory__are_equal(
      &(lhs->trajectory), &(rhs->trajectory)))
  {
    return false;
  }
  return true;
}

bool
vda5050_msgs__msg__EdgeState__copy(
  const vda5050_msgs__msg__EdgeState * input,
  vda5050_msgs__msg__EdgeState * output)
{
  if (!input || !output) {
    return false;
  }
  // edge_id
  if (!rosidl_runtime_c__String__copy(
      &(input->edge_id), &(output->edge_id)))
  {
    return false;
  }
  // sequence_id
  output->sequence_id = input->sequence_id;
  // edge_description
  if (!rosidl_runtime_c__String__copy(
      &(input->edge_description), &(output->edge_description)))
  {
    return false;
  }
  // released
  output->released = input->released;
  // trajectory
  if (!vda5050_msgs__msg__Trajectory__copy(
      &(input->trajectory), &(output->trajectory)))
  {
    return false;
  }
  return true;
}

vda5050_msgs__msg__EdgeState *
vda5050_msgs__msg__EdgeState__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__EdgeState * msg = (vda5050_msgs__msg__EdgeState *)allocator.allocate(sizeof(vda5050_msgs__msg__EdgeState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vda5050_msgs__msg__EdgeState));
  bool success = vda5050_msgs__msg__EdgeState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vda5050_msgs__msg__EdgeState__destroy(vda5050_msgs__msg__EdgeState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vda5050_msgs__msg__EdgeState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vda5050_msgs__msg__EdgeState__Sequence__init(vda5050_msgs__msg__EdgeState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__EdgeState * data = NULL;

  if (size) {
    data = (vda5050_msgs__msg__EdgeState *)allocator.zero_allocate(size, sizeof(vda5050_msgs__msg__EdgeState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vda5050_msgs__msg__EdgeState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vda5050_msgs__msg__EdgeState__fini(&data[i - 1]);
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
vda5050_msgs__msg__EdgeState__Sequence__fini(vda5050_msgs__msg__EdgeState__Sequence * array)
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
      vda5050_msgs__msg__EdgeState__fini(&array->data[i]);
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

vda5050_msgs__msg__EdgeState__Sequence *
vda5050_msgs__msg__EdgeState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__EdgeState__Sequence * array = (vda5050_msgs__msg__EdgeState__Sequence *)allocator.allocate(sizeof(vda5050_msgs__msg__EdgeState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vda5050_msgs__msg__EdgeState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vda5050_msgs__msg__EdgeState__Sequence__destroy(vda5050_msgs__msg__EdgeState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vda5050_msgs__msg__EdgeState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vda5050_msgs__msg__EdgeState__Sequence__are_equal(const vda5050_msgs__msg__EdgeState__Sequence * lhs, const vda5050_msgs__msg__EdgeState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vda5050_msgs__msg__EdgeState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vda5050_msgs__msg__EdgeState__Sequence__copy(
  const vda5050_msgs__msg__EdgeState__Sequence * input,
  vda5050_msgs__msg__EdgeState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vda5050_msgs__msg__EdgeState);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    vda5050_msgs__msg__EdgeState * data =
      (vda5050_msgs__msg__EdgeState *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vda5050_msgs__msg__EdgeState__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          vda5050_msgs__msg__EdgeState__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vda5050_msgs__msg__EdgeState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
