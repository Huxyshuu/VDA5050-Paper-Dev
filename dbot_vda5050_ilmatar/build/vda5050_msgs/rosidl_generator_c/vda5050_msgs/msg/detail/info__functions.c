// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from vda5050_msgs:msg/Info.idl
// generated code does not contain a copyright notice
#include "vda5050_msgs/msg/detail/info__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `info_type`
// Member `info_description`
// Member `info_level`
#include "rosidl_runtime_c/string_functions.h"
// Member `info_references`
#include "vda5050_msgs/msg/detail/info_reference__functions.h"

bool
vda5050_msgs__msg__Info__init(vda5050_msgs__msg__Info * msg)
{
  if (!msg) {
    return false;
  }
  // info_type
  if (!rosidl_runtime_c__String__init(&msg->info_type)) {
    vda5050_msgs__msg__Info__fini(msg);
    return false;
  }
  // info_references
  if (!vda5050_msgs__msg__InfoReference__Sequence__init(&msg->info_references, 0)) {
    vda5050_msgs__msg__Info__fini(msg);
    return false;
  }
  // info_description
  if (!rosidl_runtime_c__String__init(&msg->info_description)) {
    vda5050_msgs__msg__Info__fini(msg);
    return false;
  }
  // info_level
  if (!rosidl_runtime_c__String__init(&msg->info_level)) {
    vda5050_msgs__msg__Info__fini(msg);
    return false;
  }
  return true;
}

void
vda5050_msgs__msg__Info__fini(vda5050_msgs__msg__Info * msg)
{
  if (!msg) {
    return;
  }
  // info_type
  rosidl_runtime_c__String__fini(&msg->info_type);
  // info_references
  vda5050_msgs__msg__InfoReference__Sequence__fini(&msg->info_references);
  // info_description
  rosidl_runtime_c__String__fini(&msg->info_description);
  // info_level
  rosidl_runtime_c__String__fini(&msg->info_level);
}

bool
vda5050_msgs__msg__Info__are_equal(const vda5050_msgs__msg__Info * lhs, const vda5050_msgs__msg__Info * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // info_type
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->info_type), &(rhs->info_type)))
  {
    return false;
  }
  // info_references
  if (!vda5050_msgs__msg__InfoReference__Sequence__are_equal(
      &(lhs->info_references), &(rhs->info_references)))
  {
    return false;
  }
  // info_description
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->info_description), &(rhs->info_description)))
  {
    return false;
  }
  // info_level
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->info_level), &(rhs->info_level)))
  {
    return false;
  }
  return true;
}

bool
vda5050_msgs__msg__Info__copy(
  const vda5050_msgs__msg__Info * input,
  vda5050_msgs__msg__Info * output)
{
  if (!input || !output) {
    return false;
  }
  // info_type
  if (!rosidl_runtime_c__String__copy(
      &(input->info_type), &(output->info_type)))
  {
    return false;
  }
  // info_references
  if (!vda5050_msgs__msg__InfoReference__Sequence__copy(
      &(input->info_references), &(output->info_references)))
  {
    return false;
  }
  // info_description
  if (!rosidl_runtime_c__String__copy(
      &(input->info_description), &(output->info_description)))
  {
    return false;
  }
  // info_level
  if (!rosidl_runtime_c__String__copy(
      &(input->info_level), &(output->info_level)))
  {
    return false;
  }
  return true;
}

vda5050_msgs__msg__Info *
vda5050_msgs__msg__Info__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__Info * msg = (vda5050_msgs__msg__Info *)allocator.allocate(sizeof(vda5050_msgs__msg__Info), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vda5050_msgs__msg__Info));
  bool success = vda5050_msgs__msg__Info__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vda5050_msgs__msg__Info__destroy(vda5050_msgs__msg__Info * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vda5050_msgs__msg__Info__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vda5050_msgs__msg__Info__Sequence__init(vda5050_msgs__msg__Info__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__Info * data = NULL;

  if (size) {
    data = (vda5050_msgs__msg__Info *)allocator.zero_allocate(size, sizeof(vda5050_msgs__msg__Info), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vda5050_msgs__msg__Info__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vda5050_msgs__msg__Info__fini(&data[i - 1]);
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
vda5050_msgs__msg__Info__Sequence__fini(vda5050_msgs__msg__Info__Sequence * array)
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
      vda5050_msgs__msg__Info__fini(&array->data[i]);
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

vda5050_msgs__msg__Info__Sequence *
vda5050_msgs__msg__Info__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__Info__Sequence * array = (vda5050_msgs__msg__Info__Sequence *)allocator.allocate(sizeof(vda5050_msgs__msg__Info__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vda5050_msgs__msg__Info__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vda5050_msgs__msg__Info__Sequence__destroy(vda5050_msgs__msg__Info__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vda5050_msgs__msg__Info__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vda5050_msgs__msg__Info__Sequence__are_equal(const vda5050_msgs__msg__Info__Sequence * lhs, const vda5050_msgs__msg__Info__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vda5050_msgs__msg__Info__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vda5050_msgs__msg__Info__Sequence__copy(
  const vda5050_msgs__msg__Info__Sequence * input,
  vda5050_msgs__msg__Info__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vda5050_msgs__msg__Info);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    vda5050_msgs__msg__Info * data =
      (vda5050_msgs__msg__Info *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vda5050_msgs__msg__Info__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          vda5050_msgs__msg__Info__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vda5050_msgs__msg__Info__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
