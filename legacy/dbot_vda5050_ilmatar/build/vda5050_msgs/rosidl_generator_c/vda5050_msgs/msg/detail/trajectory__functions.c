// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from vda5050_msgs:msg/Trajectory.idl
// generated code does not contain a copyright notice
#include "vda5050_msgs/msg/detail/trajectory__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `knot_vector`
#include "rosidl_runtime_c/primitives_sequence_functions.h"
// Member `control_points`
#include "vda5050_msgs/msg/detail/control_point__functions.h"

bool
vda5050_msgs__msg__Trajectory__init(vda5050_msgs__msg__Trajectory * msg)
{
  if (!msg) {
    return false;
  }
  // degree
  msg->degree = 1.0l;
  // knot_vector
  if (!rosidl_runtime_c__double__Sequence__init(&msg->knot_vector, 0)) {
    vda5050_msgs__msg__Trajectory__fini(msg);
    return false;
  }
  // control_points
  if (!vda5050_msgs__msg__ControlPoint__Sequence__init(&msg->control_points, 0)) {
    vda5050_msgs__msg__Trajectory__fini(msg);
    return false;
  }
  return true;
}

void
vda5050_msgs__msg__Trajectory__fini(vda5050_msgs__msg__Trajectory * msg)
{
  if (!msg) {
    return;
  }
  // degree
  // knot_vector
  rosidl_runtime_c__double__Sequence__fini(&msg->knot_vector);
  // control_points
  vda5050_msgs__msg__ControlPoint__Sequence__fini(&msg->control_points);
}

bool
vda5050_msgs__msg__Trajectory__are_equal(const vda5050_msgs__msg__Trajectory * lhs, const vda5050_msgs__msg__Trajectory * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // degree
  if (lhs->degree != rhs->degree) {
    return false;
  }
  // knot_vector
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->knot_vector), &(rhs->knot_vector)))
  {
    return false;
  }
  // control_points
  if (!vda5050_msgs__msg__ControlPoint__Sequence__are_equal(
      &(lhs->control_points), &(rhs->control_points)))
  {
    return false;
  }
  return true;
}

bool
vda5050_msgs__msg__Trajectory__copy(
  const vda5050_msgs__msg__Trajectory * input,
  vda5050_msgs__msg__Trajectory * output)
{
  if (!input || !output) {
    return false;
  }
  // degree
  output->degree = input->degree;
  // knot_vector
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->knot_vector), &(output->knot_vector)))
  {
    return false;
  }
  // control_points
  if (!vda5050_msgs__msg__ControlPoint__Sequence__copy(
      &(input->control_points), &(output->control_points)))
  {
    return false;
  }
  return true;
}

vda5050_msgs__msg__Trajectory *
vda5050_msgs__msg__Trajectory__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__Trajectory * msg = (vda5050_msgs__msg__Trajectory *)allocator.allocate(sizeof(vda5050_msgs__msg__Trajectory), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vda5050_msgs__msg__Trajectory));
  bool success = vda5050_msgs__msg__Trajectory__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vda5050_msgs__msg__Trajectory__destroy(vda5050_msgs__msg__Trajectory * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vda5050_msgs__msg__Trajectory__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vda5050_msgs__msg__Trajectory__Sequence__init(vda5050_msgs__msg__Trajectory__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__Trajectory * data = NULL;

  if (size) {
    data = (vda5050_msgs__msg__Trajectory *)allocator.zero_allocate(size, sizeof(vda5050_msgs__msg__Trajectory), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vda5050_msgs__msg__Trajectory__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vda5050_msgs__msg__Trajectory__fini(&data[i - 1]);
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
vda5050_msgs__msg__Trajectory__Sequence__fini(vda5050_msgs__msg__Trajectory__Sequence * array)
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
      vda5050_msgs__msg__Trajectory__fini(&array->data[i]);
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

vda5050_msgs__msg__Trajectory__Sequence *
vda5050_msgs__msg__Trajectory__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__Trajectory__Sequence * array = (vda5050_msgs__msg__Trajectory__Sequence *)allocator.allocate(sizeof(vda5050_msgs__msg__Trajectory__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vda5050_msgs__msg__Trajectory__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vda5050_msgs__msg__Trajectory__Sequence__destroy(vda5050_msgs__msg__Trajectory__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vda5050_msgs__msg__Trajectory__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vda5050_msgs__msg__Trajectory__Sequence__are_equal(const vda5050_msgs__msg__Trajectory__Sequence * lhs, const vda5050_msgs__msg__Trajectory__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vda5050_msgs__msg__Trajectory__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vda5050_msgs__msg__Trajectory__Sequence__copy(
  const vda5050_msgs__msg__Trajectory__Sequence * input,
  vda5050_msgs__msg__Trajectory__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vda5050_msgs__msg__Trajectory);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    vda5050_msgs__msg__Trajectory * data =
      (vda5050_msgs__msg__Trajectory *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vda5050_msgs__msg__Trajectory__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          vda5050_msgs__msg__Trajectory__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vda5050_msgs__msg__Trajectory__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
