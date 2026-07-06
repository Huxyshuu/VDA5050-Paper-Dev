// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from vda5050_msgs:msg/BoundingBoxReference.idl
// generated code does not contain a copyright notice
#include "vda5050_msgs/msg/detail/bounding_box_reference__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
vda5050_msgs__msg__BoundingBoxReference__init(vda5050_msgs__msg__BoundingBoxReference * msg)
{
  if (!msg) {
    return false;
  }
  // x
  // y
  // z
  // theta
  return true;
}

void
vda5050_msgs__msg__BoundingBoxReference__fini(vda5050_msgs__msg__BoundingBoxReference * msg)
{
  if (!msg) {
    return;
  }
  // x
  // y
  // z
  // theta
}

bool
vda5050_msgs__msg__BoundingBoxReference__are_equal(const vda5050_msgs__msg__BoundingBoxReference * lhs, const vda5050_msgs__msg__BoundingBoxReference * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  // y
  if (lhs->y != rhs->y) {
    return false;
  }
  // z
  if (lhs->z != rhs->z) {
    return false;
  }
  // theta
  if (lhs->theta != rhs->theta) {
    return false;
  }
  return true;
}

bool
vda5050_msgs__msg__BoundingBoxReference__copy(
  const vda5050_msgs__msg__BoundingBoxReference * input,
  vda5050_msgs__msg__BoundingBoxReference * output)
{
  if (!input || !output) {
    return false;
  }
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  // z
  output->z = input->z;
  // theta
  output->theta = input->theta;
  return true;
}

vda5050_msgs__msg__BoundingBoxReference *
vda5050_msgs__msg__BoundingBoxReference__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__BoundingBoxReference * msg = (vda5050_msgs__msg__BoundingBoxReference *)allocator.allocate(sizeof(vda5050_msgs__msg__BoundingBoxReference), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vda5050_msgs__msg__BoundingBoxReference));
  bool success = vda5050_msgs__msg__BoundingBoxReference__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vda5050_msgs__msg__BoundingBoxReference__destroy(vda5050_msgs__msg__BoundingBoxReference * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vda5050_msgs__msg__BoundingBoxReference__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vda5050_msgs__msg__BoundingBoxReference__Sequence__init(vda5050_msgs__msg__BoundingBoxReference__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__BoundingBoxReference * data = NULL;

  if (size) {
    data = (vda5050_msgs__msg__BoundingBoxReference *)allocator.zero_allocate(size, sizeof(vda5050_msgs__msg__BoundingBoxReference), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vda5050_msgs__msg__BoundingBoxReference__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vda5050_msgs__msg__BoundingBoxReference__fini(&data[i - 1]);
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
vda5050_msgs__msg__BoundingBoxReference__Sequence__fini(vda5050_msgs__msg__BoundingBoxReference__Sequence * array)
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
      vda5050_msgs__msg__BoundingBoxReference__fini(&array->data[i]);
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

vda5050_msgs__msg__BoundingBoxReference__Sequence *
vda5050_msgs__msg__BoundingBoxReference__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__BoundingBoxReference__Sequence * array = (vda5050_msgs__msg__BoundingBoxReference__Sequence *)allocator.allocate(sizeof(vda5050_msgs__msg__BoundingBoxReference__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vda5050_msgs__msg__BoundingBoxReference__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vda5050_msgs__msg__BoundingBoxReference__Sequence__destroy(vda5050_msgs__msg__BoundingBoxReference__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vda5050_msgs__msg__BoundingBoxReference__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vda5050_msgs__msg__BoundingBoxReference__Sequence__are_equal(const vda5050_msgs__msg__BoundingBoxReference__Sequence * lhs, const vda5050_msgs__msg__BoundingBoxReference__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vda5050_msgs__msg__BoundingBoxReference__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vda5050_msgs__msg__BoundingBoxReference__Sequence__copy(
  const vda5050_msgs__msg__BoundingBoxReference__Sequence * input,
  vda5050_msgs__msg__BoundingBoxReference__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vda5050_msgs__msg__BoundingBoxReference);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    vda5050_msgs__msg__BoundingBoxReference * data =
      (vda5050_msgs__msg__BoundingBoxReference *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vda5050_msgs__msg__BoundingBoxReference__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          vda5050_msgs__msg__BoundingBoxReference__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vda5050_msgs__msg__BoundingBoxReference__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
