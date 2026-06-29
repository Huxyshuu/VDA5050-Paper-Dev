// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from vda5050_msgs:msg/PhysicalParameters.idl
// generated code does not contain a copyright notice
#include "vda5050_msgs/msg/detail/physical_parameters__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
vda5050_msgs__msg__PhysicalParameters__init(vda5050_msgs__msg__PhysicalParameters * msg)
{
  if (!msg) {
    return false;
  }
  // speed_min
  // speed_max
  // acceleration_max
  // deceleration_max
  // height_min
  // height_max
  // width
  // length
  return true;
}

void
vda5050_msgs__msg__PhysicalParameters__fini(vda5050_msgs__msg__PhysicalParameters * msg)
{
  if (!msg) {
    return;
  }
  // speed_min
  // speed_max
  // acceleration_max
  // deceleration_max
  // height_min
  // height_max
  // width
  // length
}

bool
vda5050_msgs__msg__PhysicalParameters__are_equal(const vda5050_msgs__msg__PhysicalParameters * lhs, const vda5050_msgs__msg__PhysicalParameters * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // speed_min
  if (lhs->speed_min != rhs->speed_min) {
    return false;
  }
  // speed_max
  if (lhs->speed_max != rhs->speed_max) {
    return false;
  }
  // acceleration_max
  if (lhs->acceleration_max != rhs->acceleration_max) {
    return false;
  }
  // deceleration_max
  if (lhs->deceleration_max != rhs->deceleration_max) {
    return false;
  }
  // height_min
  if (lhs->height_min != rhs->height_min) {
    return false;
  }
  // height_max
  if (lhs->height_max != rhs->height_max) {
    return false;
  }
  // width
  if (lhs->width != rhs->width) {
    return false;
  }
  // length
  if (lhs->length != rhs->length) {
    return false;
  }
  return true;
}

bool
vda5050_msgs__msg__PhysicalParameters__copy(
  const vda5050_msgs__msg__PhysicalParameters * input,
  vda5050_msgs__msg__PhysicalParameters * output)
{
  if (!input || !output) {
    return false;
  }
  // speed_min
  output->speed_min = input->speed_min;
  // speed_max
  output->speed_max = input->speed_max;
  // acceleration_max
  output->acceleration_max = input->acceleration_max;
  // deceleration_max
  output->deceleration_max = input->deceleration_max;
  // height_min
  output->height_min = input->height_min;
  // height_max
  output->height_max = input->height_max;
  // width
  output->width = input->width;
  // length
  output->length = input->length;
  return true;
}

vda5050_msgs__msg__PhysicalParameters *
vda5050_msgs__msg__PhysicalParameters__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__PhysicalParameters * msg = (vda5050_msgs__msg__PhysicalParameters *)allocator.allocate(sizeof(vda5050_msgs__msg__PhysicalParameters), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vda5050_msgs__msg__PhysicalParameters));
  bool success = vda5050_msgs__msg__PhysicalParameters__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vda5050_msgs__msg__PhysicalParameters__destroy(vda5050_msgs__msg__PhysicalParameters * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vda5050_msgs__msg__PhysicalParameters__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vda5050_msgs__msg__PhysicalParameters__Sequence__init(vda5050_msgs__msg__PhysicalParameters__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__PhysicalParameters * data = NULL;

  if (size) {
    data = (vda5050_msgs__msg__PhysicalParameters *)allocator.zero_allocate(size, sizeof(vda5050_msgs__msg__PhysicalParameters), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vda5050_msgs__msg__PhysicalParameters__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vda5050_msgs__msg__PhysicalParameters__fini(&data[i - 1]);
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
vda5050_msgs__msg__PhysicalParameters__Sequence__fini(vda5050_msgs__msg__PhysicalParameters__Sequence * array)
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
      vda5050_msgs__msg__PhysicalParameters__fini(&array->data[i]);
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

vda5050_msgs__msg__PhysicalParameters__Sequence *
vda5050_msgs__msg__PhysicalParameters__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__PhysicalParameters__Sequence * array = (vda5050_msgs__msg__PhysicalParameters__Sequence *)allocator.allocate(sizeof(vda5050_msgs__msg__PhysicalParameters__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vda5050_msgs__msg__PhysicalParameters__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vda5050_msgs__msg__PhysicalParameters__Sequence__destroy(vda5050_msgs__msg__PhysicalParameters__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vda5050_msgs__msg__PhysicalParameters__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vda5050_msgs__msg__PhysicalParameters__Sequence__are_equal(const vda5050_msgs__msg__PhysicalParameters__Sequence * lhs, const vda5050_msgs__msg__PhysicalParameters__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vda5050_msgs__msg__PhysicalParameters__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vda5050_msgs__msg__PhysicalParameters__Sequence__copy(
  const vda5050_msgs__msg__PhysicalParameters__Sequence * input,
  vda5050_msgs__msg__PhysicalParameters__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vda5050_msgs__msg__PhysicalParameters);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    vda5050_msgs__msg__PhysicalParameters * data =
      (vda5050_msgs__msg__PhysicalParameters *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vda5050_msgs__msg__PhysicalParameters__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          vda5050_msgs__msg__PhysicalParameters__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vda5050_msgs__msg__PhysicalParameters__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
