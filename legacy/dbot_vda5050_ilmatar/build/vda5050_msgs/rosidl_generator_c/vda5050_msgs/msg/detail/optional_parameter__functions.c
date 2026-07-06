// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from vda5050_msgs:msg/OptionalParameter.idl
// generated code does not contain a copyright notice
#include "vda5050_msgs/msg/detail/optional_parameter__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `parameter`
// Member `support`
// Member `description`
#include "rosidl_runtime_c/string_functions.h"

bool
vda5050_msgs__msg__OptionalParameter__init(vda5050_msgs__msg__OptionalParameter * msg)
{
  if (!msg) {
    return false;
  }
  // parameter
  if (!rosidl_runtime_c__String__init(&msg->parameter)) {
    vda5050_msgs__msg__OptionalParameter__fini(msg);
    return false;
  }
  // support
  if (!rosidl_runtime_c__String__init(&msg->support)) {
    vda5050_msgs__msg__OptionalParameter__fini(msg);
    return false;
  }
  // description
  if (!rosidl_runtime_c__String__init(&msg->description)) {
    vda5050_msgs__msg__OptionalParameter__fini(msg);
    return false;
  }
  return true;
}

void
vda5050_msgs__msg__OptionalParameter__fini(vda5050_msgs__msg__OptionalParameter * msg)
{
  if (!msg) {
    return;
  }
  // parameter
  rosidl_runtime_c__String__fini(&msg->parameter);
  // support
  rosidl_runtime_c__String__fini(&msg->support);
  // description
  rosidl_runtime_c__String__fini(&msg->description);
}

bool
vda5050_msgs__msg__OptionalParameter__are_equal(const vda5050_msgs__msg__OptionalParameter * lhs, const vda5050_msgs__msg__OptionalParameter * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // parameter
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->parameter), &(rhs->parameter)))
  {
    return false;
  }
  // support
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->support), &(rhs->support)))
  {
    return false;
  }
  // description
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->description), &(rhs->description)))
  {
    return false;
  }
  return true;
}

bool
vda5050_msgs__msg__OptionalParameter__copy(
  const vda5050_msgs__msg__OptionalParameter * input,
  vda5050_msgs__msg__OptionalParameter * output)
{
  if (!input || !output) {
    return false;
  }
  // parameter
  if (!rosidl_runtime_c__String__copy(
      &(input->parameter), &(output->parameter)))
  {
    return false;
  }
  // support
  if (!rosidl_runtime_c__String__copy(
      &(input->support), &(output->support)))
  {
    return false;
  }
  // description
  if (!rosidl_runtime_c__String__copy(
      &(input->description), &(output->description)))
  {
    return false;
  }
  return true;
}

vda5050_msgs__msg__OptionalParameter *
vda5050_msgs__msg__OptionalParameter__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__OptionalParameter * msg = (vda5050_msgs__msg__OptionalParameter *)allocator.allocate(sizeof(vda5050_msgs__msg__OptionalParameter), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vda5050_msgs__msg__OptionalParameter));
  bool success = vda5050_msgs__msg__OptionalParameter__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vda5050_msgs__msg__OptionalParameter__destroy(vda5050_msgs__msg__OptionalParameter * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vda5050_msgs__msg__OptionalParameter__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vda5050_msgs__msg__OptionalParameter__Sequence__init(vda5050_msgs__msg__OptionalParameter__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__OptionalParameter * data = NULL;

  if (size) {
    data = (vda5050_msgs__msg__OptionalParameter *)allocator.zero_allocate(size, sizeof(vda5050_msgs__msg__OptionalParameter), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vda5050_msgs__msg__OptionalParameter__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vda5050_msgs__msg__OptionalParameter__fini(&data[i - 1]);
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
vda5050_msgs__msg__OptionalParameter__Sequence__fini(vda5050_msgs__msg__OptionalParameter__Sequence * array)
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
      vda5050_msgs__msg__OptionalParameter__fini(&array->data[i]);
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

vda5050_msgs__msg__OptionalParameter__Sequence *
vda5050_msgs__msg__OptionalParameter__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__OptionalParameter__Sequence * array = (vda5050_msgs__msg__OptionalParameter__Sequence *)allocator.allocate(sizeof(vda5050_msgs__msg__OptionalParameter__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vda5050_msgs__msg__OptionalParameter__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vda5050_msgs__msg__OptionalParameter__Sequence__destroy(vda5050_msgs__msg__OptionalParameter__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vda5050_msgs__msg__OptionalParameter__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vda5050_msgs__msg__OptionalParameter__Sequence__are_equal(const vda5050_msgs__msg__OptionalParameter__Sequence * lhs, const vda5050_msgs__msg__OptionalParameter__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vda5050_msgs__msg__OptionalParameter__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vda5050_msgs__msg__OptionalParameter__Sequence__copy(
  const vda5050_msgs__msg__OptionalParameter__Sequence * input,
  vda5050_msgs__msg__OptionalParameter__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vda5050_msgs__msg__OptionalParameter);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    vda5050_msgs__msg__OptionalParameter * data =
      (vda5050_msgs__msg__OptionalParameter *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vda5050_msgs__msg__OptionalParameter__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          vda5050_msgs__msg__OptionalParameter__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vda5050_msgs__msg__OptionalParameter__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
