// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from vda5050_msgs:msg/Error.idl
// generated code does not contain a copyright notice
#include "vda5050_msgs/msg/detail/error__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `error_type`
// Member `error_description`
// Member `error_level`
#include "rosidl_runtime_c/string_functions.h"
// Member `error_references`
#include "vda5050_msgs/msg/detail/error_reference__functions.h"

bool
vda5050_msgs__msg__Error__init(vda5050_msgs__msg__Error * msg)
{
  if (!msg) {
    return false;
  }
  // error_type
  if (!rosidl_runtime_c__String__init(&msg->error_type)) {
    vda5050_msgs__msg__Error__fini(msg);
    return false;
  }
  // error_references
  if (!vda5050_msgs__msg__ErrorReference__Sequence__init(&msg->error_references, 0)) {
    vda5050_msgs__msg__Error__fini(msg);
    return false;
  }
  // error_description
  if (!rosidl_runtime_c__String__init(&msg->error_description)) {
    vda5050_msgs__msg__Error__fini(msg);
    return false;
  }
  // error_level
  if (!rosidl_runtime_c__String__init(&msg->error_level)) {
    vda5050_msgs__msg__Error__fini(msg);
    return false;
  }
  return true;
}

void
vda5050_msgs__msg__Error__fini(vda5050_msgs__msg__Error * msg)
{
  if (!msg) {
    return;
  }
  // error_type
  rosidl_runtime_c__String__fini(&msg->error_type);
  // error_references
  vda5050_msgs__msg__ErrorReference__Sequence__fini(&msg->error_references);
  // error_description
  rosidl_runtime_c__String__fini(&msg->error_description);
  // error_level
  rosidl_runtime_c__String__fini(&msg->error_level);
}

bool
vda5050_msgs__msg__Error__are_equal(const vda5050_msgs__msg__Error * lhs, const vda5050_msgs__msg__Error * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // error_type
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->error_type), &(rhs->error_type)))
  {
    return false;
  }
  // error_references
  if (!vda5050_msgs__msg__ErrorReference__Sequence__are_equal(
      &(lhs->error_references), &(rhs->error_references)))
  {
    return false;
  }
  // error_description
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->error_description), &(rhs->error_description)))
  {
    return false;
  }
  // error_level
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->error_level), &(rhs->error_level)))
  {
    return false;
  }
  return true;
}

bool
vda5050_msgs__msg__Error__copy(
  const vda5050_msgs__msg__Error * input,
  vda5050_msgs__msg__Error * output)
{
  if (!input || !output) {
    return false;
  }
  // error_type
  if (!rosidl_runtime_c__String__copy(
      &(input->error_type), &(output->error_type)))
  {
    return false;
  }
  // error_references
  if (!vda5050_msgs__msg__ErrorReference__Sequence__copy(
      &(input->error_references), &(output->error_references)))
  {
    return false;
  }
  // error_description
  if (!rosidl_runtime_c__String__copy(
      &(input->error_description), &(output->error_description)))
  {
    return false;
  }
  // error_level
  if (!rosidl_runtime_c__String__copy(
      &(input->error_level), &(output->error_level)))
  {
    return false;
  }
  return true;
}

vda5050_msgs__msg__Error *
vda5050_msgs__msg__Error__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__Error * msg = (vda5050_msgs__msg__Error *)allocator.allocate(sizeof(vda5050_msgs__msg__Error), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vda5050_msgs__msg__Error));
  bool success = vda5050_msgs__msg__Error__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vda5050_msgs__msg__Error__destroy(vda5050_msgs__msg__Error * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vda5050_msgs__msg__Error__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vda5050_msgs__msg__Error__Sequence__init(vda5050_msgs__msg__Error__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__Error * data = NULL;

  if (size) {
    data = (vda5050_msgs__msg__Error *)allocator.zero_allocate(size, sizeof(vda5050_msgs__msg__Error), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vda5050_msgs__msg__Error__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vda5050_msgs__msg__Error__fini(&data[i - 1]);
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
vda5050_msgs__msg__Error__Sequence__fini(vda5050_msgs__msg__Error__Sequence * array)
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
      vda5050_msgs__msg__Error__fini(&array->data[i]);
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

vda5050_msgs__msg__Error__Sequence *
vda5050_msgs__msg__Error__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__Error__Sequence * array = (vda5050_msgs__msg__Error__Sequence *)allocator.allocate(sizeof(vda5050_msgs__msg__Error__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vda5050_msgs__msg__Error__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vda5050_msgs__msg__Error__Sequence__destroy(vda5050_msgs__msg__Error__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vda5050_msgs__msg__Error__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vda5050_msgs__msg__Error__Sequence__are_equal(const vda5050_msgs__msg__Error__Sequence * lhs, const vda5050_msgs__msg__Error__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vda5050_msgs__msg__Error__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vda5050_msgs__msg__Error__Sequence__copy(
  const vda5050_msgs__msg__Error__Sequence * input,
  vda5050_msgs__msg__Error__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vda5050_msgs__msg__Error);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    vda5050_msgs__msg__Error * data =
      (vda5050_msgs__msg__Error *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vda5050_msgs__msg__Error__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          vda5050_msgs__msg__Error__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vda5050_msgs__msg__Error__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
