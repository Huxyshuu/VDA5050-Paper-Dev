// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from vda5050_msgs:msg/PolygonPoint.idl
// generated code does not contain a copyright notice
#include "vda5050_msgs/msg/detail/polygon_point__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
vda5050_msgs__msg__PolygonPoint__init(vda5050_msgs__msg__PolygonPoint * msg)
{
  if (!msg) {
    return false;
  }
  // x
  // y
  return true;
}

void
vda5050_msgs__msg__PolygonPoint__fini(vda5050_msgs__msg__PolygonPoint * msg)
{
  if (!msg) {
    return;
  }
  // x
  // y
}

bool
vda5050_msgs__msg__PolygonPoint__are_equal(const vda5050_msgs__msg__PolygonPoint * lhs, const vda5050_msgs__msg__PolygonPoint * rhs)
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
  return true;
}

bool
vda5050_msgs__msg__PolygonPoint__copy(
  const vda5050_msgs__msg__PolygonPoint * input,
  vda5050_msgs__msg__PolygonPoint * output)
{
  if (!input || !output) {
    return false;
  }
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  return true;
}

vda5050_msgs__msg__PolygonPoint *
vda5050_msgs__msg__PolygonPoint__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__PolygonPoint * msg = (vda5050_msgs__msg__PolygonPoint *)allocator.allocate(sizeof(vda5050_msgs__msg__PolygonPoint), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vda5050_msgs__msg__PolygonPoint));
  bool success = vda5050_msgs__msg__PolygonPoint__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vda5050_msgs__msg__PolygonPoint__destroy(vda5050_msgs__msg__PolygonPoint * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vda5050_msgs__msg__PolygonPoint__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vda5050_msgs__msg__PolygonPoint__Sequence__init(vda5050_msgs__msg__PolygonPoint__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__PolygonPoint * data = NULL;

  if (size) {
    data = (vda5050_msgs__msg__PolygonPoint *)allocator.zero_allocate(size, sizeof(vda5050_msgs__msg__PolygonPoint), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vda5050_msgs__msg__PolygonPoint__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vda5050_msgs__msg__PolygonPoint__fini(&data[i - 1]);
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
vda5050_msgs__msg__PolygonPoint__Sequence__fini(vda5050_msgs__msg__PolygonPoint__Sequence * array)
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
      vda5050_msgs__msg__PolygonPoint__fini(&array->data[i]);
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

vda5050_msgs__msg__PolygonPoint__Sequence *
vda5050_msgs__msg__PolygonPoint__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__PolygonPoint__Sequence * array = (vda5050_msgs__msg__PolygonPoint__Sequence *)allocator.allocate(sizeof(vda5050_msgs__msg__PolygonPoint__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vda5050_msgs__msg__PolygonPoint__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vda5050_msgs__msg__PolygonPoint__Sequence__destroy(vda5050_msgs__msg__PolygonPoint__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vda5050_msgs__msg__PolygonPoint__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vda5050_msgs__msg__PolygonPoint__Sequence__are_equal(const vda5050_msgs__msg__PolygonPoint__Sequence * lhs, const vda5050_msgs__msg__PolygonPoint__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vda5050_msgs__msg__PolygonPoint__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vda5050_msgs__msg__PolygonPoint__Sequence__copy(
  const vda5050_msgs__msg__PolygonPoint__Sequence * input,
  vda5050_msgs__msg__PolygonPoint__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vda5050_msgs__msg__PolygonPoint);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    vda5050_msgs__msg__PolygonPoint * data =
      (vda5050_msgs__msg__PolygonPoint *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vda5050_msgs__msg__PolygonPoint__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          vda5050_msgs__msg__PolygonPoint__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vda5050_msgs__msg__PolygonPoint__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
