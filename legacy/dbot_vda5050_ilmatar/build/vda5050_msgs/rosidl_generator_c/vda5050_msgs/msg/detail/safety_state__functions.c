// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from vda5050_msgs:msg/SafetyState.idl
// generated code does not contain a copyright notice
#include "vda5050_msgs/msg/detail/safety_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `e_stop`
#include "rosidl_runtime_c/string_functions.h"

bool
vda5050_msgs__msg__SafetyState__init(vda5050_msgs__msg__SafetyState * msg)
{
  if (!msg) {
    return false;
  }
  // e_stop
  if (!rosidl_runtime_c__String__init(&msg->e_stop)) {
    vda5050_msgs__msg__SafetyState__fini(msg);
    return false;
  }
  // field_violation
  return true;
}

void
vda5050_msgs__msg__SafetyState__fini(vda5050_msgs__msg__SafetyState * msg)
{
  if (!msg) {
    return;
  }
  // e_stop
  rosidl_runtime_c__String__fini(&msg->e_stop);
  // field_violation
}

bool
vda5050_msgs__msg__SafetyState__are_equal(const vda5050_msgs__msg__SafetyState * lhs, const vda5050_msgs__msg__SafetyState * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // e_stop
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->e_stop), &(rhs->e_stop)))
  {
    return false;
  }
  // field_violation
  if (lhs->field_violation != rhs->field_violation) {
    return false;
  }
  return true;
}

bool
vda5050_msgs__msg__SafetyState__copy(
  const vda5050_msgs__msg__SafetyState * input,
  vda5050_msgs__msg__SafetyState * output)
{
  if (!input || !output) {
    return false;
  }
  // e_stop
  if (!rosidl_runtime_c__String__copy(
      &(input->e_stop), &(output->e_stop)))
  {
    return false;
  }
  // field_violation
  output->field_violation = input->field_violation;
  return true;
}

vda5050_msgs__msg__SafetyState *
vda5050_msgs__msg__SafetyState__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__SafetyState * msg = (vda5050_msgs__msg__SafetyState *)allocator.allocate(sizeof(vda5050_msgs__msg__SafetyState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vda5050_msgs__msg__SafetyState));
  bool success = vda5050_msgs__msg__SafetyState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vda5050_msgs__msg__SafetyState__destroy(vda5050_msgs__msg__SafetyState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vda5050_msgs__msg__SafetyState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vda5050_msgs__msg__SafetyState__Sequence__init(vda5050_msgs__msg__SafetyState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__SafetyState * data = NULL;

  if (size) {
    data = (vda5050_msgs__msg__SafetyState *)allocator.zero_allocate(size, sizeof(vda5050_msgs__msg__SafetyState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vda5050_msgs__msg__SafetyState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vda5050_msgs__msg__SafetyState__fini(&data[i - 1]);
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
vda5050_msgs__msg__SafetyState__Sequence__fini(vda5050_msgs__msg__SafetyState__Sequence * array)
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
      vda5050_msgs__msg__SafetyState__fini(&array->data[i]);
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

vda5050_msgs__msg__SafetyState__Sequence *
vda5050_msgs__msg__SafetyState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__SafetyState__Sequence * array = (vda5050_msgs__msg__SafetyState__Sequence *)allocator.allocate(sizeof(vda5050_msgs__msg__SafetyState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vda5050_msgs__msg__SafetyState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vda5050_msgs__msg__SafetyState__Sequence__destroy(vda5050_msgs__msg__SafetyState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vda5050_msgs__msg__SafetyState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vda5050_msgs__msg__SafetyState__Sequence__are_equal(const vda5050_msgs__msg__SafetyState__Sequence * lhs, const vda5050_msgs__msg__SafetyState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vda5050_msgs__msg__SafetyState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vda5050_msgs__msg__SafetyState__Sequence__copy(
  const vda5050_msgs__msg__SafetyState__Sequence * input,
  vda5050_msgs__msg__SafetyState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vda5050_msgs__msg__SafetyState);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    vda5050_msgs__msg__SafetyState * data =
      (vda5050_msgs__msg__SafetyState *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vda5050_msgs__msg__SafetyState__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          vda5050_msgs__msg__SafetyState__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vda5050_msgs__msg__SafetyState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
