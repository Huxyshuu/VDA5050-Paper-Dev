// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from vda5050_msgs:msg/WheelDefinition.idl
// generated code does not contain a copyright notice
#include "vda5050_msgs/msg/detail/wheel_definition__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `type`
// Member `constraints`
#include "rosidl_runtime_c/string_functions.h"
// Member `position`
#include "vda5050_msgs/msg/detail/position__functions.h"

bool
vda5050_msgs__msg__WheelDefinition__init(vda5050_msgs__msg__WheelDefinition * msg)
{
  if (!msg) {
    return false;
  }
  // type
  if (!rosidl_runtime_c__String__init(&msg->type)) {
    vda5050_msgs__msg__WheelDefinition__fini(msg);
    return false;
  }
  // is_active_driven
  // is_active_steered
  // position
  if (!vda5050_msgs__msg__Position__init(&msg->position)) {
    vda5050_msgs__msg__WheelDefinition__fini(msg);
    return false;
  }
  // diameter
  // width
  // center_displacement
  // constraints
  if (!rosidl_runtime_c__String__init(&msg->constraints)) {
    vda5050_msgs__msg__WheelDefinition__fini(msg);
    return false;
  }
  return true;
}

void
vda5050_msgs__msg__WheelDefinition__fini(vda5050_msgs__msg__WheelDefinition * msg)
{
  if (!msg) {
    return;
  }
  // type
  rosidl_runtime_c__String__fini(&msg->type);
  // is_active_driven
  // is_active_steered
  // position
  vda5050_msgs__msg__Position__fini(&msg->position);
  // diameter
  // width
  // center_displacement
  // constraints
  rosidl_runtime_c__String__fini(&msg->constraints);
}

bool
vda5050_msgs__msg__WheelDefinition__are_equal(const vda5050_msgs__msg__WheelDefinition * lhs, const vda5050_msgs__msg__WheelDefinition * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // type
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->type), &(rhs->type)))
  {
    return false;
  }
  // is_active_driven
  if (lhs->is_active_driven != rhs->is_active_driven) {
    return false;
  }
  // is_active_steered
  if (lhs->is_active_steered != rhs->is_active_steered) {
    return false;
  }
  // position
  if (!vda5050_msgs__msg__Position__are_equal(
      &(lhs->position), &(rhs->position)))
  {
    return false;
  }
  // diameter
  if (lhs->diameter != rhs->diameter) {
    return false;
  }
  // width
  if (lhs->width != rhs->width) {
    return false;
  }
  // center_displacement
  if (lhs->center_displacement != rhs->center_displacement) {
    return false;
  }
  // constraints
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->constraints), &(rhs->constraints)))
  {
    return false;
  }
  return true;
}

bool
vda5050_msgs__msg__WheelDefinition__copy(
  const vda5050_msgs__msg__WheelDefinition * input,
  vda5050_msgs__msg__WheelDefinition * output)
{
  if (!input || !output) {
    return false;
  }
  // type
  if (!rosidl_runtime_c__String__copy(
      &(input->type), &(output->type)))
  {
    return false;
  }
  // is_active_driven
  output->is_active_driven = input->is_active_driven;
  // is_active_steered
  output->is_active_steered = input->is_active_steered;
  // position
  if (!vda5050_msgs__msg__Position__copy(
      &(input->position), &(output->position)))
  {
    return false;
  }
  // diameter
  output->diameter = input->diameter;
  // width
  output->width = input->width;
  // center_displacement
  output->center_displacement = input->center_displacement;
  // constraints
  if (!rosidl_runtime_c__String__copy(
      &(input->constraints), &(output->constraints)))
  {
    return false;
  }
  return true;
}

vda5050_msgs__msg__WheelDefinition *
vda5050_msgs__msg__WheelDefinition__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__WheelDefinition * msg = (vda5050_msgs__msg__WheelDefinition *)allocator.allocate(sizeof(vda5050_msgs__msg__WheelDefinition), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vda5050_msgs__msg__WheelDefinition));
  bool success = vda5050_msgs__msg__WheelDefinition__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vda5050_msgs__msg__WheelDefinition__destroy(vda5050_msgs__msg__WheelDefinition * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vda5050_msgs__msg__WheelDefinition__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vda5050_msgs__msg__WheelDefinition__Sequence__init(vda5050_msgs__msg__WheelDefinition__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__WheelDefinition * data = NULL;

  if (size) {
    data = (vda5050_msgs__msg__WheelDefinition *)allocator.zero_allocate(size, sizeof(vda5050_msgs__msg__WheelDefinition), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vda5050_msgs__msg__WheelDefinition__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vda5050_msgs__msg__WheelDefinition__fini(&data[i - 1]);
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
vda5050_msgs__msg__WheelDefinition__Sequence__fini(vda5050_msgs__msg__WheelDefinition__Sequence * array)
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
      vda5050_msgs__msg__WheelDefinition__fini(&array->data[i]);
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

vda5050_msgs__msg__WheelDefinition__Sequence *
vda5050_msgs__msg__WheelDefinition__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__WheelDefinition__Sequence * array = (vda5050_msgs__msg__WheelDefinition__Sequence *)allocator.allocate(sizeof(vda5050_msgs__msg__WheelDefinition__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vda5050_msgs__msg__WheelDefinition__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vda5050_msgs__msg__WheelDefinition__Sequence__destroy(vda5050_msgs__msg__WheelDefinition__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vda5050_msgs__msg__WheelDefinition__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vda5050_msgs__msg__WheelDefinition__Sequence__are_equal(const vda5050_msgs__msg__WheelDefinition__Sequence * lhs, const vda5050_msgs__msg__WheelDefinition__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vda5050_msgs__msg__WheelDefinition__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vda5050_msgs__msg__WheelDefinition__Sequence__copy(
  const vda5050_msgs__msg__WheelDefinition__Sequence * input,
  vda5050_msgs__msg__WheelDefinition__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vda5050_msgs__msg__WheelDefinition);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    vda5050_msgs__msg__WheelDefinition * data =
      (vda5050_msgs__msg__WheelDefinition *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vda5050_msgs__msg__WheelDefinition__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          vda5050_msgs__msg__WheelDefinition__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vda5050_msgs__msg__WheelDefinition__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
