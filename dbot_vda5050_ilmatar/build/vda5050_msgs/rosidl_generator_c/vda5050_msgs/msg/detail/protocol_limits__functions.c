// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from vda5050_msgs:msg/ProtocolLimits.idl
// generated code does not contain a copyright notice
#include "vda5050_msgs/msg/detail/protocol_limits__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `max_string_lens`
#include "vda5050_msgs/msg/detail/max_string_lens__functions.h"
// Member `max_array_lens`
#include "vda5050_msgs/msg/detail/max_array_lens__functions.h"
// Member `timing`
#include "vda5050_msgs/msg/detail/timing__functions.h"

bool
vda5050_msgs__msg__ProtocolLimits__init(vda5050_msgs__msg__ProtocolLimits * msg)
{
  if (!msg) {
    return false;
  }
  // max_string_lens
  if (!vda5050_msgs__msg__MaxStringLens__init(&msg->max_string_lens)) {
    vda5050_msgs__msg__ProtocolLimits__fini(msg);
    return false;
  }
  // max_array_lens
  if (!vda5050_msgs__msg__MaxArrayLens__init(&msg->max_array_lens)) {
    vda5050_msgs__msg__ProtocolLimits__fini(msg);
    return false;
  }
  // timing
  if (!vda5050_msgs__msg__Timing__init(&msg->timing)) {
    vda5050_msgs__msg__ProtocolLimits__fini(msg);
    return false;
  }
  return true;
}

void
vda5050_msgs__msg__ProtocolLimits__fini(vda5050_msgs__msg__ProtocolLimits * msg)
{
  if (!msg) {
    return;
  }
  // max_string_lens
  vda5050_msgs__msg__MaxStringLens__fini(&msg->max_string_lens);
  // max_array_lens
  vda5050_msgs__msg__MaxArrayLens__fini(&msg->max_array_lens);
  // timing
  vda5050_msgs__msg__Timing__fini(&msg->timing);
}

bool
vda5050_msgs__msg__ProtocolLimits__are_equal(const vda5050_msgs__msg__ProtocolLimits * lhs, const vda5050_msgs__msg__ProtocolLimits * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // max_string_lens
  if (!vda5050_msgs__msg__MaxStringLens__are_equal(
      &(lhs->max_string_lens), &(rhs->max_string_lens)))
  {
    return false;
  }
  // max_array_lens
  if (!vda5050_msgs__msg__MaxArrayLens__are_equal(
      &(lhs->max_array_lens), &(rhs->max_array_lens)))
  {
    return false;
  }
  // timing
  if (!vda5050_msgs__msg__Timing__are_equal(
      &(lhs->timing), &(rhs->timing)))
  {
    return false;
  }
  return true;
}

bool
vda5050_msgs__msg__ProtocolLimits__copy(
  const vda5050_msgs__msg__ProtocolLimits * input,
  vda5050_msgs__msg__ProtocolLimits * output)
{
  if (!input || !output) {
    return false;
  }
  // max_string_lens
  if (!vda5050_msgs__msg__MaxStringLens__copy(
      &(input->max_string_lens), &(output->max_string_lens)))
  {
    return false;
  }
  // max_array_lens
  if (!vda5050_msgs__msg__MaxArrayLens__copy(
      &(input->max_array_lens), &(output->max_array_lens)))
  {
    return false;
  }
  // timing
  if (!vda5050_msgs__msg__Timing__copy(
      &(input->timing), &(output->timing)))
  {
    return false;
  }
  return true;
}

vda5050_msgs__msg__ProtocolLimits *
vda5050_msgs__msg__ProtocolLimits__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__ProtocolLimits * msg = (vda5050_msgs__msg__ProtocolLimits *)allocator.allocate(sizeof(vda5050_msgs__msg__ProtocolLimits), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vda5050_msgs__msg__ProtocolLimits));
  bool success = vda5050_msgs__msg__ProtocolLimits__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vda5050_msgs__msg__ProtocolLimits__destroy(vda5050_msgs__msg__ProtocolLimits * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vda5050_msgs__msg__ProtocolLimits__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vda5050_msgs__msg__ProtocolLimits__Sequence__init(vda5050_msgs__msg__ProtocolLimits__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__ProtocolLimits * data = NULL;

  if (size) {
    data = (vda5050_msgs__msg__ProtocolLimits *)allocator.zero_allocate(size, sizeof(vda5050_msgs__msg__ProtocolLimits), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vda5050_msgs__msg__ProtocolLimits__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vda5050_msgs__msg__ProtocolLimits__fini(&data[i - 1]);
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
vda5050_msgs__msg__ProtocolLimits__Sequence__fini(vda5050_msgs__msg__ProtocolLimits__Sequence * array)
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
      vda5050_msgs__msg__ProtocolLimits__fini(&array->data[i]);
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

vda5050_msgs__msg__ProtocolLimits__Sequence *
vda5050_msgs__msg__ProtocolLimits__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__ProtocolLimits__Sequence * array = (vda5050_msgs__msg__ProtocolLimits__Sequence *)allocator.allocate(sizeof(vda5050_msgs__msg__ProtocolLimits__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vda5050_msgs__msg__ProtocolLimits__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vda5050_msgs__msg__ProtocolLimits__Sequence__destroy(vda5050_msgs__msg__ProtocolLimits__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vda5050_msgs__msg__ProtocolLimits__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vda5050_msgs__msg__ProtocolLimits__Sequence__are_equal(const vda5050_msgs__msg__ProtocolLimits__Sequence * lhs, const vda5050_msgs__msg__ProtocolLimits__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vda5050_msgs__msg__ProtocolLimits__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vda5050_msgs__msg__ProtocolLimits__Sequence__copy(
  const vda5050_msgs__msg__ProtocolLimits__Sequence * input,
  vda5050_msgs__msg__ProtocolLimits__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vda5050_msgs__msg__ProtocolLimits);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    vda5050_msgs__msg__ProtocolLimits * data =
      (vda5050_msgs__msg__ProtocolLimits *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vda5050_msgs__msg__ProtocolLimits__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          vda5050_msgs__msg__ProtocolLimits__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vda5050_msgs__msg__ProtocolLimits__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
