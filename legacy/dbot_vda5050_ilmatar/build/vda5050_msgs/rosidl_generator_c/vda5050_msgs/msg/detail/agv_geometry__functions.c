// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from vda5050_msgs:msg/AGVGeometry.idl
// generated code does not contain a copyright notice
#include "vda5050_msgs/msg/detail/agv_geometry__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `wheel_definitions`
#include "vda5050_msgs/msg/detail/wheel_definition__functions.h"
// Member `envelopes2d`
#include "vda5050_msgs/msg/detail/envelope2_d__functions.h"
// Member `envelopes3d`
#include "vda5050_msgs/msg/detail/envelope3_d__functions.h"

bool
vda5050_msgs__msg__AGVGeometry__init(vda5050_msgs__msg__AGVGeometry * msg)
{
  if (!msg) {
    return false;
  }
  // wheel_definitions
  if (!vda5050_msgs__msg__WheelDefinition__Sequence__init(&msg->wheel_definitions, 0)) {
    vda5050_msgs__msg__AGVGeometry__fini(msg);
    return false;
  }
  // envelopes2d
  if (!vda5050_msgs__msg__Envelope2D__Sequence__init(&msg->envelopes2d, 0)) {
    vda5050_msgs__msg__AGVGeometry__fini(msg);
    return false;
  }
  // envelopes3d
  if (!vda5050_msgs__msg__Envelope3D__Sequence__init(&msg->envelopes3d, 0)) {
    vda5050_msgs__msg__AGVGeometry__fini(msg);
    return false;
  }
  return true;
}

void
vda5050_msgs__msg__AGVGeometry__fini(vda5050_msgs__msg__AGVGeometry * msg)
{
  if (!msg) {
    return;
  }
  // wheel_definitions
  vda5050_msgs__msg__WheelDefinition__Sequence__fini(&msg->wheel_definitions);
  // envelopes2d
  vda5050_msgs__msg__Envelope2D__Sequence__fini(&msg->envelopes2d);
  // envelopes3d
  vda5050_msgs__msg__Envelope3D__Sequence__fini(&msg->envelopes3d);
}

bool
vda5050_msgs__msg__AGVGeometry__are_equal(const vda5050_msgs__msg__AGVGeometry * lhs, const vda5050_msgs__msg__AGVGeometry * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // wheel_definitions
  if (!vda5050_msgs__msg__WheelDefinition__Sequence__are_equal(
      &(lhs->wheel_definitions), &(rhs->wheel_definitions)))
  {
    return false;
  }
  // envelopes2d
  if (!vda5050_msgs__msg__Envelope2D__Sequence__are_equal(
      &(lhs->envelopes2d), &(rhs->envelopes2d)))
  {
    return false;
  }
  // envelopes3d
  if (!vda5050_msgs__msg__Envelope3D__Sequence__are_equal(
      &(lhs->envelopes3d), &(rhs->envelopes3d)))
  {
    return false;
  }
  return true;
}

bool
vda5050_msgs__msg__AGVGeometry__copy(
  const vda5050_msgs__msg__AGVGeometry * input,
  vda5050_msgs__msg__AGVGeometry * output)
{
  if (!input || !output) {
    return false;
  }
  // wheel_definitions
  if (!vda5050_msgs__msg__WheelDefinition__Sequence__copy(
      &(input->wheel_definitions), &(output->wheel_definitions)))
  {
    return false;
  }
  // envelopes2d
  if (!vda5050_msgs__msg__Envelope2D__Sequence__copy(
      &(input->envelopes2d), &(output->envelopes2d)))
  {
    return false;
  }
  // envelopes3d
  if (!vda5050_msgs__msg__Envelope3D__Sequence__copy(
      &(input->envelopes3d), &(output->envelopes3d)))
  {
    return false;
  }
  return true;
}

vda5050_msgs__msg__AGVGeometry *
vda5050_msgs__msg__AGVGeometry__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__AGVGeometry * msg = (vda5050_msgs__msg__AGVGeometry *)allocator.allocate(sizeof(vda5050_msgs__msg__AGVGeometry), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vda5050_msgs__msg__AGVGeometry));
  bool success = vda5050_msgs__msg__AGVGeometry__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vda5050_msgs__msg__AGVGeometry__destroy(vda5050_msgs__msg__AGVGeometry * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vda5050_msgs__msg__AGVGeometry__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vda5050_msgs__msg__AGVGeometry__Sequence__init(vda5050_msgs__msg__AGVGeometry__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__AGVGeometry * data = NULL;

  if (size) {
    data = (vda5050_msgs__msg__AGVGeometry *)allocator.zero_allocate(size, sizeof(vda5050_msgs__msg__AGVGeometry), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vda5050_msgs__msg__AGVGeometry__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vda5050_msgs__msg__AGVGeometry__fini(&data[i - 1]);
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
vda5050_msgs__msg__AGVGeometry__Sequence__fini(vda5050_msgs__msg__AGVGeometry__Sequence * array)
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
      vda5050_msgs__msg__AGVGeometry__fini(&array->data[i]);
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

vda5050_msgs__msg__AGVGeometry__Sequence *
vda5050_msgs__msg__AGVGeometry__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__AGVGeometry__Sequence * array = (vda5050_msgs__msg__AGVGeometry__Sequence *)allocator.allocate(sizeof(vda5050_msgs__msg__AGVGeometry__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vda5050_msgs__msg__AGVGeometry__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vda5050_msgs__msg__AGVGeometry__Sequence__destroy(vda5050_msgs__msg__AGVGeometry__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vda5050_msgs__msg__AGVGeometry__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vda5050_msgs__msg__AGVGeometry__Sequence__are_equal(const vda5050_msgs__msg__AGVGeometry__Sequence * lhs, const vda5050_msgs__msg__AGVGeometry__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vda5050_msgs__msg__AGVGeometry__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vda5050_msgs__msg__AGVGeometry__Sequence__copy(
  const vda5050_msgs__msg__AGVGeometry__Sequence * input,
  vda5050_msgs__msg__AGVGeometry__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vda5050_msgs__msg__AGVGeometry);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    vda5050_msgs__msg__AGVGeometry * data =
      (vda5050_msgs__msg__AGVGeometry *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vda5050_msgs__msg__AGVGeometry__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          vda5050_msgs__msg__AGVGeometry__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vda5050_msgs__msg__AGVGeometry__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
