// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from dbot_custom_msgs:msg/WheelEncoder.idl
// generated code does not contain a copyright notice
#include "dbot_custom_msgs/msg/detail/wheel_encoder__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
dbot_custom_msgs__msg__WheelEncoder__init(dbot_custom_msgs__msg__WheelEncoder * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    dbot_custom_msgs__msg__WheelEncoder__fini(msg);
    return false;
  }
  // left
  // right
  return true;
}

void
dbot_custom_msgs__msg__WheelEncoder__fini(dbot_custom_msgs__msg__WheelEncoder * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // left
  // right
}

bool
dbot_custom_msgs__msg__WheelEncoder__are_equal(const dbot_custom_msgs__msg__WheelEncoder * lhs, const dbot_custom_msgs__msg__WheelEncoder * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // left
  if (lhs->left != rhs->left) {
    return false;
  }
  // right
  if (lhs->right != rhs->right) {
    return false;
  }
  return true;
}

bool
dbot_custom_msgs__msg__WheelEncoder__copy(
  const dbot_custom_msgs__msg__WheelEncoder * input,
  dbot_custom_msgs__msg__WheelEncoder * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // left
  output->left = input->left;
  // right
  output->right = input->right;
  return true;
}

dbot_custom_msgs__msg__WheelEncoder *
dbot_custom_msgs__msg__WheelEncoder__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dbot_custom_msgs__msg__WheelEncoder * msg = (dbot_custom_msgs__msg__WheelEncoder *)allocator.allocate(sizeof(dbot_custom_msgs__msg__WheelEncoder), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(dbot_custom_msgs__msg__WheelEncoder));
  bool success = dbot_custom_msgs__msg__WheelEncoder__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
dbot_custom_msgs__msg__WheelEncoder__destroy(dbot_custom_msgs__msg__WheelEncoder * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    dbot_custom_msgs__msg__WheelEncoder__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
dbot_custom_msgs__msg__WheelEncoder__Sequence__init(dbot_custom_msgs__msg__WheelEncoder__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dbot_custom_msgs__msg__WheelEncoder * data = NULL;

  if (size) {
    data = (dbot_custom_msgs__msg__WheelEncoder *)allocator.zero_allocate(size, sizeof(dbot_custom_msgs__msg__WheelEncoder), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = dbot_custom_msgs__msg__WheelEncoder__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        dbot_custom_msgs__msg__WheelEncoder__fini(&data[i - 1]);
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
dbot_custom_msgs__msg__WheelEncoder__Sequence__fini(dbot_custom_msgs__msg__WheelEncoder__Sequence * array)
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
      dbot_custom_msgs__msg__WheelEncoder__fini(&array->data[i]);
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

dbot_custom_msgs__msg__WheelEncoder__Sequence *
dbot_custom_msgs__msg__WheelEncoder__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dbot_custom_msgs__msg__WheelEncoder__Sequence * array = (dbot_custom_msgs__msg__WheelEncoder__Sequence *)allocator.allocate(sizeof(dbot_custom_msgs__msg__WheelEncoder__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = dbot_custom_msgs__msg__WheelEncoder__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
dbot_custom_msgs__msg__WheelEncoder__Sequence__destroy(dbot_custom_msgs__msg__WheelEncoder__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    dbot_custom_msgs__msg__WheelEncoder__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
dbot_custom_msgs__msg__WheelEncoder__Sequence__are_equal(const dbot_custom_msgs__msg__WheelEncoder__Sequence * lhs, const dbot_custom_msgs__msg__WheelEncoder__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!dbot_custom_msgs__msg__WheelEncoder__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
dbot_custom_msgs__msg__WheelEncoder__Sequence__copy(
  const dbot_custom_msgs__msg__WheelEncoder__Sequence * input,
  dbot_custom_msgs__msg__WheelEncoder__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(dbot_custom_msgs__msg__WheelEncoder);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    dbot_custom_msgs__msg__WheelEncoder * data =
      (dbot_custom_msgs__msg__WheelEncoder *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!dbot_custom_msgs__msg__WheelEncoder__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          dbot_custom_msgs__msg__WheelEncoder__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!dbot_custom_msgs__msg__WheelEncoder__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
