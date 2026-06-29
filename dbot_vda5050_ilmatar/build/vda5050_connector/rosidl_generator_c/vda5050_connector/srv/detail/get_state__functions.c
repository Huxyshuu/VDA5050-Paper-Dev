// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from vda5050_connector:srv/GetState.idl
// generated code does not contain a copyright notice
#include "vda5050_connector/srv/detail/get_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
vda5050_connector__srv__GetState_Request__init(vda5050_connector__srv__GetState_Request * msg)
{
  if (!msg) {
    return false;
  }
  // structure_needs_at_least_one_member
  return true;
}

void
vda5050_connector__srv__GetState_Request__fini(vda5050_connector__srv__GetState_Request * msg)
{
  if (!msg) {
    return;
  }
  // structure_needs_at_least_one_member
}

bool
vda5050_connector__srv__GetState_Request__are_equal(const vda5050_connector__srv__GetState_Request * lhs, const vda5050_connector__srv__GetState_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // structure_needs_at_least_one_member
  if (lhs->structure_needs_at_least_one_member != rhs->structure_needs_at_least_one_member) {
    return false;
  }
  return true;
}

bool
vda5050_connector__srv__GetState_Request__copy(
  const vda5050_connector__srv__GetState_Request * input,
  vda5050_connector__srv__GetState_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // structure_needs_at_least_one_member
  output->structure_needs_at_least_one_member = input->structure_needs_at_least_one_member;
  return true;
}

vda5050_connector__srv__GetState_Request *
vda5050_connector__srv__GetState_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_connector__srv__GetState_Request * msg = (vda5050_connector__srv__GetState_Request *)allocator.allocate(sizeof(vda5050_connector__srv__GetState_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vda5050_connector__srv__GetState_Request));
  bool success = vda5050_connector__srv__GetState_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vda5050_connector__srv__GetState_Request__destroy(vda5050_connector__srv__GetState_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vda5050_connector__srv__GetState_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vda5050_connector__srv__GetState_Request__Sequence__init(vda5050_connector__srv__GetState_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_connector__srv__GetState_Request * data = NULL;

  if (size) {
    data = (vda5050_connector__srv__GetState_Request *)allocator.zero_allocate(size, sizeof(vda5050_connector__srv__GetState_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vda5050_connector__srv__GetState_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vda5050_connector__srv__GetState_Request__fini(&data[i - 1]);
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
vda5050_connector__srv__GetState_Request__Sequence__fini(vda5050_connector__srv__GetState_Request__Sequence * array)
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
      vda5050_connector__srv__GetState_Request__fini(&array->data[i]);
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

vda5050_connector__srv__GetState_Request__Sequence *
vda5050_connector__srv__GetState_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_connector__srv__GetState_Request__Sequence * array = (vda5050_connector__srv__GetState_Request__Sequence *)allocator.allocate(sizeof(vda5050_connector__srv__GetState_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vda5050_connector__srv__GetState_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vda5050_connector__srv__GetState_Request__Sequence__destroy(vda5050_connector__srv__GetState_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vda5050_connector__srv__GetState_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vda5050_connector__srv__GetState_Request__Sequence__are_equal(const vda5050_connector__srv__GetState_Request__Sequence * lhs, const vda5050_connector__srv__GetState_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vda5050_connector__srv__GetState_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vda5050_connector__srv__GetState_Request__Sequence__copy(
  const vda5050_connector__srv__GetState_Request__Sequence * input,
  vda5050_connector__srv__GetState_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vda5050_connector__srv__GetState_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    vda5050_connector__srv__GetState_Request * data =
      (vda5050_connector__srv__GetState_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vda5050_connector__srv__GetState_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          vda5050_connector__srv__GetState_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vda5050_connector__srv__GetState_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `state`
#include "vda5050_msgs/msg/detail/order_state__functions.h"

bool
vda5050_connector__srv__GetState_Response__init(vda5050_connector__srv__GetState_Response * msg)
{
  if (!msg) {
    return false;
  }
  // state
  if (!vda5050_msgs__msg__OrderState__init(&msg->state)) {
    vda5050_connector__srv__GetState_Response__fini(msg);
    return false;
  }
  return true;
}

void
vda5050_connector__srv__GetState_Response__fini(vda5050_connector__srv__GetState_Response * msg)
{
  if (!msg) {
    return;
  }
  // state
  vda5050_msgs__msg__OrderState__fini(&msg->state);
}

bool
vda5050_connector__srv__GetState_Response__are_equal(const vda5050_connector__srv__GetState_Response * lhs, const vda5050_connector__srv__GetState_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // state
  if (!vda5050_msgs__msg__OrderState__are_equal(
      &(lhs->state), &(rhs->state)))
  {
    return false;
  }
  return true;
}

bool
vda5050_connector__srv__GetState_Response__copy(
  const vda5050_connector__srv__GetState_Response * input,
  vda5050_connector__srv__GetState_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // state
  if (!vda5050_msgs__msg__OrderState__copy(
      &(input->state), &(output->state)))
  {
    return false;
  }
  return true;
}

vda5050_connector__srv__GetState_Response *
vda5050_connector__srv__GetState_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_connector__srv__GetState_Response * msg = (vda5050_connector__srv__GetState_Response *)allocator.allocate(sizeof(vda5050_connector__srv__GetState_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vda5050_connector__srv__GetState_Response));
  bool success = vda5050_connector__srv__GetState_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vda5050_connector__srv__GetState_Response__destroy(vda5050_connector__srv__GetState_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vda5050_connector__srv__GetState_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vda5050_connector__srv__GetState_Response__Sequence__init(vda5050_connector__srv__GetState_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_connector__srv__GetState_Response * data = NULL;

  if (size) {
    data = (vda5050_connector__srv__GetState_Response *)allocator.zero_allocate(size, sizeof(vda5050_connector__srv__GetState_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vda5050_connector__srv__GetState_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vda5050_connector__srv__GetState_Response__fini(&data[i - 1]);
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
vda5050_connector__srv__GetState_Response__Sequence__fini(vda5050_connector__srv__GetState_Response__Sequence * array)
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
      vda5050_connector__srv__GetState_Response__fini(&array->data[i]);
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

vda5050_connector__srv__GetState_Response__Sequence *
vda5050_connector__srv__GetState_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_connector__srv__GetState_Response__Sequence * array = (vda5050_connector__srv__GetState_Response__Sequence *)allocator.allocate(sizeof(vda5050_connector__srv__GetState_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vda5050_connector__srv__GetState_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vda5050_connector__srv__GetState_Response__Sequence__destroy(vda5050_connector__srv__GetState_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vda5050_connector__srv__GetState_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vda5050_connector__srv__GetState_Response__Sequence__are_equal(const vda5050_connector__srv__GetState_Response__Sequence * lhs, const vda5050_connector__srv__GetState_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vda5050_connector__srv__GetState_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vda5050_connector__srv__GetState_Response__Sequence__copy(
  const vda5050_connector__srv__GetState_Response__Sequence * input,
  vda5050_connector__srv__GetState_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vda5050_connector__srv__GetState_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    vda5050_connector__srv__GetState_Response * data =
      (vda5050_connector__srv__GetState_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vda5050_connector__srv__GetState_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          vda5050_connector__srv__GetState_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vda5050_connector__srv__GetState_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
