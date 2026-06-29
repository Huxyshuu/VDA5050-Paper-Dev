// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from vda5050_connector:action/ProcessVDAAction.idl
// generated code does not contain a copyright notice
#include "vda5050_connector/action/detail/process_vda_action__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `action`
#include "vda5050_msgs/msg/detail/action__functions.h"

bool
vda5050_connector__action__ProcessVDAAction_Goal__init(vda5050_connector__action__ProcessVDAAction_Goal * msg)
{
  if (!msg) {
    return false;
  }
  // action
  if (!vda5050_msgs__msg__Action__init(&msg->action)) {
    vda5050_connector__action__ProcessVDAAction_Goal__fini(msg);
    return false;
  }
  return true;
}

void
vda5050_connector__action__ProcessVDAAction_Goal__fini(vda5050_connector__action__ProcessVDAAction_Goal * msg)
{
  if (!msg) {
    return;
  }
  // action
  vda5050_msgs__msg__Action__fini(&msg->action);
}

bool
vda5050_connector__action__ProcessVDAAction_Goal__are_equal(const vda5050_connector__action__ProcessVDAAction_Goal * lhs, const vda5050_connector__action__ProcessVDAAction_Goal * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // action
  if (!vda5050_msgs__msg__Action__are_equal(
      &(lhs->action), &(rhs->action)))
  {
    return false;
  }
  return true;
}

bool
vda5050_connector__action__ProcessVDAAction_Goal__copy(
  const vda5050_connector__action__ProcessVDAAction_Goal * input,
  vda5050_connector__action__ProcessVDAAction_Goal * output)
{
  if (!input || !output) {
    return false;
  }
  // action
  if (!vda5050_msgs__msg__Action__copy(
      &(input->action), &(output->action)))
  {
    return false;
  }
  return true;
}

vda5050_connector__action__ProcessVDAAction_Goal *
vda5050_connector__action__ProcessVDAAction_Goal__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_connector__action__ProcessVDAAction_Goal * msg = (vda5050_connector__action__ProcessVDAAction_Goal *)allocator.allocate(sizeof(vda5050_connector__action__ProcessVDAAction_Goal), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vda5050_connector__action__ProcessVDAAction_Goal));
  bool success = vda5050_connector__action__ProcessVDAAction_Goal__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vda5050_connector__action__ProcessVDAAction_Goal__destroy(vda5050_connector__action__ProcessVDAAction_Goal * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vda5050_connector__action__ProcessVDAAction_Goal__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vda5050_connector__action__ProcessVDAAction_Goal__Sequence__init(vda5050_connector__action__ProcessVDAAction_Goal__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_connector__action__ProcessVDAAction_Goal * data = NULL;

  if (size) {
    data = (vda5050_connector__action__ProcessVDAAction_Goal *)allocator.zero_allocate(size, sizeof(vda5050_connector__action__ProcessVDAAction_Goal), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vda5050_connector__action__ProcessVDAAction_Goal__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vda5050_connector__action__ProcessVDAAction_Goal__fini(&data[i - 1]);
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
vda5050_connector__action__ProcessVDAAction_Goal__Sequence__fini(vda5050_connector__action__ProcessVDAAction_Goal__Sequence * array)
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
      vda5050_connector__action__ProcessVDAAction_Goal__fini(&array->data[i]);
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

vda5050_connector__action__ProcessVDAAction_Goal__Sequence *
vda5050_connector__action__ProcessVDAAction_Goal__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_connector__action__ProcessVDAAction_Goal__Sequence * array = (vda5050_connector__action__ProcessVDAAction_Goal__Sequence *)allocator.allocate(sizeof(vda5050_connector__action__ProcessVDAAction_Goal__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vda5050_connector__action__ProcessVDAAction_Goal__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vda5050_connector__action__ProcessVDAAction_Goal__Sequence__destroy(vda5050_connector__action__ProcessVDAAction_Goal__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vda5050_connector__action__ProcessVDAAction_Goal__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vda5050_connector__action__ProcessVDAAction_Goal__Sequence__are_equal(const vda5050_connector__action__ProcessVDAAction_Goal__Sequence * lhs, const vda5050_connector__action__ProcessVDAAction_Goal__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vda5050_connector__action__ProcessVDAAction_Goal__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vda5050_connector__action__ProcessVDAAction_Goal__Sequence__copy(
  const vda5050_connector__action__ProcessVDAAction_Goal__Sequence * input,
  vda5050_connector__action__ProcessVDAAction_Goal__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vda5050_connector__action__ProcessVDAAction_Goal);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    vda5050_connector__action__ProcessVDAAction_Goal * data =
      (vda5050_connector__action__ProcessVDAAction_Goal *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vda5050_connector__action__ProcessVDAAction_Goal__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          vda5050_connector__action__ProcessVDAAction_Goal__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vda5050_connector__action__ProcessVDAAction_Goal__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `result`
#include "vda5050_msgs/msg/detail/current_action__functions.h"

bool
vda5050_connector__action__ProcessVDAAction_Result__init(vda5050_connector__action__ProcessVDAAction_Result * msg)
{
  if (!msg) {
    return false;
  }
  // result
  if (!vda5050_msgs__msg__CurrentAction__init(&msg->result)) {
    vda5050_connector__action__ProcessVDAAction_Result__fini(msg);
    return false;
  }
  return true;
}

void
vda5050_connector__action__ProcessVDAAction_Result__fini(vda5050_connector__action__ProcessVDAAction_Result * msg)
{
  if (!msg) {
    return;
  }
  // result
  vda5050_msgs__msg__CurrentAction__fini(&msg->result);
}

bool
vda5050_connector__action__ProcessVDAAction_Result__are_equal(const vda5050_connector__action__ProcessVDAAction_Result * lhs, const vda5050_connector__action__ProcessVDAAction_Result * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // result
  if (!vda5050_msgs__msg__CurrentAction__are_equal(
      &(lhs->result), &(rhs->result)))
  {
    return false;
  }
  return true;
}

bool
vda5050_connector__action__ProcessVDAAction_Result__copy(
  const vda5050_connector__action__ProcessVDAAction_Result * input,
  vda5050_connector__action__ProcessVDAAction_Result * output)
{
  if (!input || !output) {
    return false;
  }
  // result
  if (!vda5050_msgs__msg__CurrentAction__copy(
      &(input->result), &(output->result)))
  {
    return false;
  }
  return true;
}

vda5050_connector__action__ProcessVDAAction_Result *
vda5050_connector__action__ProcessVDAAction_Result__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_connector__action__ProcessVDAAction_Result * msg = (vda5050_connector__action__ProcessVDAAction_Result *)allocator.allocate(sizeof(vda5050_connector__action__ProcessVDAAction_Result), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vda5050_connector__action__ProcessVDAAction_Result));
  bool success = vda5050_connector__action__ProcessVDAAction_Result__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vda5050_connector__action__ProcessVDAAction_Result__destroy(vda5050_connector__action__ProcessVDAAction_Result * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vda5050_connector__action__ProcessVDAAction_Result__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vda5050_connector__action__ProcessVDAAction_Result__Sequence__init(vda5050_connector__action__ProcessVDAAction_Result__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_connector__action__ProcessVDAAction_Result * data = NULL;

  if (size) {
    data = (vda5050_connector__action__ProcessVDAAction_Result *)allocator.zero_allocate(size, sizeof(vda5050_connector__action__ProcessVDAAction_Result), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vda5050_connector__action__ProcessVDAAction_Result__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vda5050_connector__action__ProcessVDAAction_Result__fini(&data[i - 1]);
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
vda5050_connector__action__ProcessVDAAction_Result__Sequence__fini(vda5050_connector__action__ProcessVDAAction_Result__Sequence * array)
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
      vda5050_connector__action__ProcessVDAAction_Result__fini(&array->data[i]);
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

vda5050_connector__action__ProcessVDAAction_Result__Sequence *
vda5050_connector__action__ProcessVDAAction_Result__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_connector__action__ProcessVDAAction_Result__Sequence * array = (vda5050_connector__action__ProcessVDAAction_Result__Sequence *)allocator.allocate(sizeof(vda5050_connector__action__ProcessVDAAction_Result__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vda5050_connector__action__ProcessVDAAction_Result__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vda5050_connector__action__ProcessVDAAction_Result__Sequence__destroy(vda5050_connector__action__ProcessVDAAction_Result__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vda5050_connector__action__ProcessVDAAction_Result__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vda5050_connector__action__ProcessVDAAction_Result__Sequence__are_equal(const vda5050_connector__action__ProcessVDAAction_Result__Sequence * lhs, const vda5050_connector__action__ProcessVDAAction_Result__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vda5050_connector__action__ProcessVDAAction_Result__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vda5050_connector__action__ProcessVDAAction_Result__Sequence__copy(
  const vda5050_connector__action__ProcessVDAAction_Result__Sequence * input,
  vda5050_connector__action__ProcessVDAAction_Result__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vda5050_connector__action__ProcessVDAAction_Result);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    vda5050_connector__action__ProcessVDAAction_Result * data =
      (vda5050_connector__action__ProcessVDAAction_Result *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vda5050_connector__action__ProcessVDAAction_Result__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          vda5050_connector__action__ProcessVDAAction_Result__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vda5050_connector__action__ProcessVDAAction_Result__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `current_action`
// already included above
// #include "vda5050_msgs/msg/detail/current_action__functions.h"

bool
vda5050_connector__action__ProcessVDAAction_Feedback__init(vda5050_connector__action__ProcessVDAAction_Feedback * msg)
{
  if (!msg) {
    return false;
  }
  // current_action
  if (!vda5050_msgs__msg__CurrentAction__init(&msg->current_action)) {
    vda5050_connector__action__ProcessVDAAction_Feedback__fini(msg);
    return false;
  }
  return true;
}

void
vda5050_connector__action__ProcessVDAAction_Feedback__fini(vda5050_connector__action__ProcessVDAAction_Feedback * msg)
{
  if (!msg) {
    return;
  }
  // current_action
  vda5050_msgs__msg__CurrentAction__fini(&msg->current_action);
}

bool
vda5050_connector__action__ProcessVDAAction_Feedback__are_equal(const vda5050_connector__action__ProcessVDAAction_Feedback * lhs, const vda5050_connector__action__ProcessVDAAction_Feedback * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // current_action
  if (!vda5050_msgs__msg__CurrentAction__are_equal(
      &(lhs->current_action), &(rhs->current_action)))
  {
    return false;
  }
  return true;
}

bool
vda5050_connector__action__ProcessVDAAction_Feedback__copy(
  const vda5050_connector__action__ProcessVDAAction_Feedback * input,
  vda5050_connector__action__ProcessVDAAction_Feedback * output)
{
  if (!input || !output) {
    return false;
  }
  // current_action
  if (!vda5050_msgs__msg__CurrentAction__copy(
      &(input->current_action), &(output->current_action)))
  {
    return false;
  }
  return true;
}

vda5050_connector__action__ProcessVDAAction_Feedback *
vda5050_connector__action__ProcessVDAAction_Feedback__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_connector__action__ProcessVDAAction_Feedback * msg = (vda5050_connector__action__ProcessVDAAction_Feedback *)allocator.allocate(sizeof(vda5050_connector__action__ProcessVDAAction_Feedback), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vda5050_connector__action__ProcessVDAAction_Feedback));
  bool success = vda5050_connector__action__ProcessVDAAction_Feedback__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vda5050_connector__action__ProcessVDAAction_Feedback__destroy(vda5050_connector__action__ProcessVDAAction_Feedback * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vda5050_connector__action__ProcessVDAAction_Feedback__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vda5050_connector__action__ProcessVDAAction_Feedback__Sequence__init(vda5050_connector__action__ProcessVDAAction_Feedback__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_connector__action__ProcessVDAAction_Feedback * data = NULL;

  if (size) {
    data = (vda5050_connector__action__ProcessVDAAction_Feedback *)allocator.zero_allocate(size, sizeof(vda5050_connector__action__ProcessVDAAction_Feedback), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vda5050_connector__action__ProcessVDAAction_Feedback__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vda5050_connector__action__ProcessVDAAction_Feedback__fini(&data[i - 1]);
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
vda5050_connector__action__ProcessVDAAction_Feedback__Sequence__fini(vda5050_connector__action__ProcessVDAAction_Feedback__Sequence * array)
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
      vda5050_connector__action__ProcessVDAAction_Feedback__fini(&array->data[i]);
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

vda5050_connector__action__ProcessVDAAction_Feedback__Sequence *
vda5050_connector__action__ProcessVDAAction_Feedback__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_connector__action__ProcessVDAAction_Feedback__Sequence * array = (vda5050_connector__action__ProcessVDAAction_Feedback__Sequence *)allocator.allocate(sizeof(vda5050_connector__action__ProcessVDAAction_Feedback__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vda5050_connector__action__ProcessVDAAction_Feedback__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vda5050_connector__action__ProcessVDAAction_Feedback__Sequence__destroy(vda5050_connector__action__ProcessVDAAction_Feedback__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vda5050_connector__action__ProcessVDAAction_Feedback__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vda5050_connector__action__ProcessVDAAction_Feedback__Sequence__are_equal(const vda5050_connector__action__ProcessVDAAction_Feedback__Sequence * lhs, const vda5050_connector__action__ProcessVDAAction_Feedback__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vda5050_connector__action__ProcessVDAAction_Feedback__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vda5050_connector__action__ProcessVDAAction_Feedback__Sequence__copy(
  const vda5050_connector__action__ProcessVDAAction_Feedback__Sequence * input,
  vda5050_connector__action__ProcessVDAAction_Feedback__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vda5050_connector__action__ProcessVDAAction_Feedback);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    vda5050_connector__action__ProcessVDAAction_Feedback * data =
      (vda5050_connector__action__ProcessVDAAction_Feedback *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vda5050_connector__action__ProcessVDAAction_Feedback__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          vda5050_connector__action__ProcessVDAAction_Feedback__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vda5050_connector__action__ProcessVDAAction_Feedback__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `goal`
// already included above
// #include "vda5050_connector/action/detail/process_vda_action__functions.h"

bool
vda5050_connector__action__ProcessVDAAction_SendGoal_Request__init(vda5050_connector__action__ProcessVDAAction_SendGoal_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    vda5050_connector__action__ProcessVDAAction_SendGoal_Request__fini(msg);
    return false;
  }
  // goal
  if (!vda5050_connector__action__ProcessVDAAction_Goal__init(&msg->goal)) {
    vda5050_connector__action__ProcessVDAAction_SendGoal_Request__fini(msg);
    return false;
  }
  return true;
}

void
vda5050_connector__action__ProcessVDAAction_SendGoal_Request__fini(vda5050_connector__action__ProcessVDAAction_SendGoal_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // goal
  vda5050_connector__action__ProcessVDAAction_Goal__fini(&msg->goal);
}

bool
vda5050_connector__action__ProcessVDAAction_SendGoal_Request__are_equal(const vda5050_connector__action__ProcessVDAAction_SendGoal_Request * lhs, const vda5050_connector__action__ProcessVDAAction_SendGoal_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // goal
  if (!vda5050_connector__action__ProcessVDAAction_Goal__are_equal(
      &(lhs->goal), &(rhs->goal)))
  {
    return false;
  }
  return true;
}

bool
vda5050_connector__action__ProcessVDAAction_SendGoal_Request__copy(
  const vda5050_connector__action__ProcessVDAAction_SendGoal_Request * input,
  vda5050_connector__action__ProcessVDAAction_SendGoal_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // goal
  if (!vda5050_connector__action__ProcessVDAAction_Goal__copy(
      &(input->goal), &(output->goal)))
  {
    return false;
  }
  return true;
}

vda5050_connector__action__ProcessVDAAction_SendGoal_Request *
vda5050_connector__action__ProcessVDAAction_SendGoal_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_connector__action__ProcessVDAAction_SendGoal_Request * msg = (vda5050_connector__action__ProcessVDAAction_SendGoal_Request *)allocator.allocate(sizeof(vda5050_connector__action__ProcessVDAAction_SendGoal_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vda5050_connector__action__ProcessVDAAction_SendGoal_Request));
  bool success = vda5050_connector__action__ProcessVDAAction_SendGoal_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vda5050_connector__action__ProcessVDAAction_SendGoal_Request__destroy(vda5050_connector__action__ProcessVDAAction_SendGoal_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vda5050_connector__action__ProcessVDAAction_SendGoal_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vda5050_connector__action__ProcessVDAAction_SendGoal_Request__Sequence__init(vda5050_connector__action__ProcessVDAAction_SendGoal_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_connector__action__ProcessVDAAction_SendGoal_Request * data = NULL;

  if (size) {
    data = (vda5050_connector__action__ProcessVDAAction_SendGoal_Request *)allocator.zero_allocate(size, sizeof(vda5050_connector__action__ProcessVDAAction_SendGoal_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vda5050_connector__action__ProcessVDAAction_SendGoal_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vda5050_connector__action__ProcessVDAAction_SendGoal_Request__fini(&data[i - 1]);
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
vda5050_connector__action__ProcessVDAAction_SendGoal_Request__Sequence__fini(vda5050_connector__action__ProcessVDAAction_SendGoal_Request__Sequence * array)
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
      vda5050_connector__action__ProcessVDAAction_SendGoal_Request__fini(&array->data[i]);
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

vda5050_connector__action__ProcessVDAAction_SendGoal_Request__Sequence *
vda5050_connector__action__ProcessVDAAction_SendGoal_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_connector__action__ProcessVDAAction_SendGoal_Request__Sequence * array = (vda5050_connector__action__ProcessVDAAction_SendGoal_Request__Sequence *)allocator.allocate(sizeof(vda5050_connector__action__ProcessVDAAction_SendGoal_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vda5050_connector__action__ProcessVDAAction_SendGoal_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vda5050_connector__action__ProcessVDAAction_SendGoal_Request__Sequence__destroy(vda5050_connector__action__ProcessVDAAction_SendGoal_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vda5050_connector__action__ProcessVDAAction_SendGoal_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vda5050_connector__action__ProcessVDAAction_SendGoal_Request__Sequence__are_equal(const vda5050_connector__action__ProcessVDAAction_SendGoal_Request__Sequence * lhs, const vda5050_connector__action__ProcessVDAAction_SendGoal_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vda5050_connector__action__ProcessVDAAction_SendGoal_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vda5050_connector__action__ProcessVDAAction_SendGoal_Request__Sequence__copy(
  const vda5050_connector__action__ProcessVDAAction_SendGoal_Request__Sequence * input,
  vda5050_connector__action__ProcessVDAAction_SendGoal_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vda5050_connector__action__ProcessVDAAction_SendGoal_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    vda5050_connector__action__ProcessVDAAction_SendGoal_Request * data =
      (vda5050_connector__action__ProcessVDAAction_SendGoal_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vda5050_connector__action__ProcessVDAAction_SendGoal_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          vda5050_connector__action__ProcessVDAAction_SendGoal_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vda5050_connector__action__ProcessVDAAction_SendGoal_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
vda5050_connector__action__ProcessVDAAction_SendGoal_Response__init(vda5050_connector__action__ProcessVDAAction_SendGoal_Response * msg)
{
  if (!msg) {
    return false;
  }
  // accepted
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    vda5050_connector__action__ProcessVDAAction_SendGoal_Response__fini(msg);
    return false;
  }
  return true;
}

void
vda5050_connector__action__ProcessVDAAction_SendGoal_Response__fini(vda5050_connector__action__ProcessVDAAction_SendGoal_Response * msg)
{
  if (!msg) {
    return;
  }
  // accepted
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
}

bool
vda5050_connector__action__ProcessVDAAction_SendGoal_Response__are_equal(const vda5050_connector__action__ProcessVDAAction_SendGoal_Response * lhs, const vda5050_connector__action__ProcessVDAAction_SendGoal_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // accepted
  if (lhs->accepted != rhs->accepted) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->stamp), &(rhs->stamp)))
  {
    return false;
  }
  return true;
}

bool
vda5050_connector__action__ProcessVDAAction_SendGoal_Response__copy(
  const vda5050_connector__action__ProcessVDAAction_SendGoal_Response * input,
  vda5050_connector__action__ProcessVDAAction_SendGoal_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // accepted
  output->accepted = input->accepted;
  // stamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->stamp), &(output->stamp)))
  {
    return false;
  }
  return true;
}

vda5050_connector__action__ProcessVDAAction_SendGoal_Response *
vda5050_connector__action__ProcessVDAAction_SendGoal_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_connector__action__ProcessVDAAction_SendGoal_Response * msg = (vda5050_connector__action__ProcessVDAAction_SendGoal_Response *)allocator.allocate(sizeof(vda5050_connector__action__ProcessVDAAction_SendGoal_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vda5050_connector__action__ProcessVDAAction_SendGoal_Response));
  bool success = vda5050_connector__action__ProcessVDAAction_SendGoal_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vda5050_connector__action__ProcessVDAAction_SendGoal_Response__destroy(vda5050_connector__action__ProcessVDAAction_SendGoal_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vda5050_connector__action__ProcessVDAAction_SendGoal_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vda5050_connector__action__ProcessVDAAction_SendGoal_Response__Sequence__init(vda5050_connector__action__ProcessVDAAction_SendGoal_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_connector__action__ProcessVDAAction_SendGoal_Response * data = NULL;

  if (size) {
    data = (vda5050_connector__action__ProcessVDAAction_SendGoal_Response *)allocator.zero_allocate(size, sizeof(vda5050_connector__action__ProcessVDAAction_SendGoal_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vda5050_connector__action__ProcessVDAAction_SendGoal_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vda5050_connector__action__ProcessVDAAction_SendGoal_Response__fini(&data[i - 1]);
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
vda5050_connector__action__ProcessVDAAction_SendGoal_Response__Sequence__fini(vda5050_connector__action__ProcessVDAAction_SendGoal_Response__Sequence * array)
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
      vda5050_connector__action__ProcessVDAAction_SendGoal_Response__fini(&array->data[i]);
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

vda5050_connector__action__ProcessVDAAction_SendGoal_Response__Sequence *
vda5050_connector__action__ProcessVDAAction_SendGoal_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_connector__action__ProcessVDAAction_SendGoal_Response__Sequence * array = (vda5050_connector__action__ProcessVDAAction_SendGoal_Response__Sequence *)allocator.allocate(sizeof(vda5050_connector__action__ProcessVDAAction_SendGoal_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vda5050_connector__action__ProcessVDAAction_SendGoal_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vda5050_connector__action__ProcessVDAAction_SendGoal_Response__Sequence__destroy(vda5050_connector__action__ProcessVDAAction_SendGoal_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vda5050_connector__action__ProcessVDAAction_SendGoal_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vda5050_connector__action__ProcessVDAAction_SendGoal_Response__Sequence__are_equal(const vda5050_connector__action__ProcessVDAAction_SendGoal_Response__Sequence * lhs, const vda5050_connector__action__ProcessVDAAction_SendGoal_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vda5050_connector__action__ProcessVDAAction_SendGoal_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vda5050_connector__action__ProcessVDAAction_SendGoal_Response__Sequence__copy(
  const vda5050_connector__action__ProcessVDAAction_SendGoal_Response__Sequence * input,
  vda5050_connector__action__ProcessVDAAction_SendGoal_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vda5050_connector__action__ProcessVDAAction_SendGoal_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    vda5050_connector__action__ProcessVDAAction_SendGoal_Response * data =
      (vda5050_connector__action__ProcessVDAAction_SendGoal_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vda5050_connector__action__ProcessVDAAction_SendGoal_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          vda5050_connector__action__ProcessVDAAction_SendGoal_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vda5050_connector__action__ProcessVDAAction_SendGoal_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"

bool
vda5050_connector__action__ProcessVDAAction_GetResult_Request__init(vda5050_connector__action__ProcessVDAAction_GetResult_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    vda5050_connector__action__ProcessVDAAction_GetResult_Request__fini(msg);
    return false;
  }
  return true;
}

void
vda5050_connector__action__ProcessVDAAction_GetResult_Request__fini(vda5050_connector__action__ProcessVDAAction_GetResult_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
}

bool
vda5050_connector__action__ProcessVDAAction_GetResult_Request__are_equal(const vda5050_connector__action__ProcessVDAAction_GetResult_Request * lhs, const vda5050_connector__action__ProcessVDAAction_GetResult_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  return true;
}

bool
vda5050_connector__action__ProcessVDAAction_GetResult_Request__copy(
  const vda5050_connector__action__ProcessVDAAction_GetResult_Request * input,
  vda5050_connector__action__ProcessVDAAction_GetResult_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  return true;
}

vda5050_connector__action__ProcessVDAAction_GetResult_Request *
vda5050_connector__action__ProcessVDAAction_GetResult_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_connector__action__ProcessVDAAction_GetResult_Request * msg = (vda5050_connector__action__ProcessVDAAction_GetResult_Request *)allocator.allocate(sizeof(vda5050_connector__action__ProcessVDAAction_GetResult_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vda5050_connector__action__ProcessVDAAction_GetResult_Request));
  bool success = vda5050_connector__action__ProcessVDAAction_GetResult_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vda5050_connector__action__ProcessVDAAction_GetResult_Request__destroy(vda5050_connector__action__ProcessVDAAction_GetResult_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vda5050_connector__action__ProcessVDAAction_GetResult_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vda5050_connector__action__ProcessVDAAction_GetResult_Request__Sequence__init(vda5050_connector__action__ProcessVDAAction_GetResult_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_connector__action__ProcessVDAAction_GetResult_Request * data = NULL;

  if (size) {
    data = (vda5050_connector__action__ProcessVDAAction_GetResult_Request *)allocator.zero_allocate(size, sizeof(vda5050_connector__action__ProcessVDAAction_GetResult_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vda5050_connector__action__ProcessVDAAction_GetResult_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vda5050_connector__action__ProcessVDAAction_GetResult_Request__fini(&data[i - 1]);
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
vda5050_connector__action__ProcessVDAAction_GetResult_Request__Sequence__fini(vda5050_connector__action__ProcessVDAAction_GetResult_Request__Sequence * array)
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
      vda5050_connector__action__ProcessVDAAction_GetResult_Request__fini(&array->data[i]);
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

vda5050_connector__action__ProcessVDAAction_GetResult_Request__Sequence *
vda5050_connector__action__ProcessVDAAction_GetResult_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_connector__action__ProcessVDAAction_GetResult_Request__Sequence * array = (vda5050_connector__action__ProcessVDAAction_GetResult_Request__Sequence *)allocator.allocate(sizeof(vda5050_connector__action__ProcessVDAAction_GetResult_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vda5050_connector__action__ProcessVDAAction_GetResult_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vda5050_connector__action__ProcessVDAAction_GetResult_Request__Sequence__destroy(vda5050_connector__action__ProcessVDAAction_GetResult_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vda5050_connector__action__ProcessVDAAction_GetResult_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vda5050_connector__action__ProcessVDAAction_GetResult_Request__Sequence__are_equal(const vda5050_connector__action__ProcessVDAAction_GetResult_Request__Sequence * lhs, const vda5050_connector__action__ProcessVDAAction_GetResult_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vda5050_connector__action__ProcessVDAAction_GetResult_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vda5050_connector__action__ProcessVDAAction_GetResult_Request__Sequence__copy(
  const vda5050_connector__action__ProcessVDAAction_GetResult_Request__Sequence * input,
  vda5050_connector__action__ProcessVDAAction_GetResult_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vda5050_connector__action__ProcessVDAAction_GetResult_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    vda5050_connector__action__ProcessVDAAction_GetResult_Request * data =
      (vda5050_connector__action__ProcessVDAAction_GetResult_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vda5050_connector__action__ProcessVDAAction_GetResult_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          vda5050_connector__action__ProcessVDAAction_GetResult_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vda5050_connector__action__ProcessVDAAction_GetResult_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `result`
// already included above
// #include "vda5050_connector/action/detail/process_vda_action__functions.h"

bool
vda5050_connector__action__ProcessVDAAction_GetResult_Response__init(vda5050_connector__action__ProcessVDAAction_GetResult_Response * msg)
{
  if (!msg) {
    return false;
  }
  // status
  // result
  if (!vda5050_connector__action__ProcessVDAAction_Result__init(&msg->result)) {
    vda5050_connector__action__ProcessVDAAction_GetResult_Response__fini(msg);
    return false;
  }
  return true;
}

void
vda5050_connector__action__ProcessVDAAction_GetResult_Response__fini(vda5050_connector__action__ProcessVDAAction_GetResult_Response * msg)
{
  if (!msg) {
    return;
  }
  // status
  // result
  vda5050_connector__action__ProcessVDAAction_Result__fini(&msg->result);
}

bool
vda5050_connector__action__ProcessVDAAction_GetResult_Response__are_equal(const vda5050_connector__action__ProcessVDAAction_GetResult_Response * lhs, const vda5050_connector__action__ProcessVDAAction_GetResult_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // status
  if (lhs->status != rhs->status) {
    return false;
  }
  // result
  if (!vda5050_connector__action__ProcessVDAAction_Result__are_equal(
      &(lhs->result), &(rhs->result)))
  {
    return false;
  }
  return true;
}

bool
vda5050_connector__action__ProcessVDAAction_GetResult_Response__copy(
  const vda5050_connector__action__ProcessVDAAction_GetResult_Response * input,
  vda5050_connector__action__ProcessVDAAction_GetResult_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // status
  output->status = input->status;
  // result
  if (!vda5050_connector__action__ProcessVDAAction_Result__copy(
      &(input->result), &(output->result)))
  {
    return false;
  }
  return true;
}

vda5050_connector__action__ProcessVDAAction_GetResult_Response *
vda5050_connector__action__ProcessVDAAction_GetResult_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_connector__action__ProcessVDAAction_GetResult_Response * msg = (vda5050_connector__action__ProcessVDAAction_GetResult_Response *)allocator.allocate(sizeof(vda5050_connector__action__ProcessVDAAction_GetResult_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vda5050_connector__action__ProcessVDAAction_GetResult_Response));
  bool success = vda5050_connector__action__ProcessVDAAction_GetResult_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vda5050_connector__action__ProcessVDAAction_GetResult_Response__destroy(vda5050_connector__action__ProcessVDAAction_GetResult_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vda5050_connector__action__ProcessVDAAction_GetResult_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vda5050_connector__action__ProcessVDAAction_GetResult_Response__Sequence__init(vda5050_connector__action__ProcessVDAAction_GetResult_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_connector__action__ProcessVDAAction_GetResult_Response * data = NULL;

  if (size) {
    data = (vda5050_connector__action__ProcessVDAAction_GetResult_Response *)allocator.zero_allocate(size, sizeof(vda5050_connector__action__ProcessVDAAction_GetResult_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vda5050_connector__action__ProcessVDAAction_GetResult_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vda5050_connector__action__ProcessVDAAction_GetResult_Response__fini(&data[i - 1]);
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
vda5050_connector__action__ProcessVDAAction_GetResult_Response__Sequence__fini(vda5050_connector__action__ProcessVDAAction_GetResult_Response__Sequence * array)
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
      vda5050_connector__action__ProcessVDAAction_GetResult_Response__fini(&array->data[i]);
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

vda5050_connector__action__ProcessVDAAction_GetResult_Response__Sequence *
vda5050_connector__action__ProcessVDAAction_GetResult_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_connector__action__ProcessVDAAction_GetResult_Response__Sequence * array = (vda5050_connector__action__ProcessVDAAction_GetResult_Response__Sequence *)allocator.allocate(sizeof(vda5050_connector__action__ProcessVDAAction_GetResult_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vda5050_connector__action__ProcessVDAAction_GetResult_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vda5050_connector__action__ProcessVDAAction_GetResult_Response__Sequence__destroy(vda5050_connector__action__ProcessVDAAction_GetResult_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vda5050_connector__action__ProcessVDAAction_GetResult_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vda5050_connector__action__ProcessVDAAction_GetResult_Response__Sequence__are_equal(const vda5050_connector__action__ProcessVDAAction_GetResult_Response__Sequence * lhs, const vda5050_connector__action__ProcessVDAAction_GetResult_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vda5050_connector__action__ProcessVDAAction_GetResult_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vda5050_connector__action__ProcessVDAAction_GetResult_Response__Sequence__copy(
  const vda5050_connector__action__ProcessVDAAction_GetResult_Response__Sequence * input,
  vda5050_connector__action__ProcessVDAAction_GetResult_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vda5050_connector__action__ProcessVDAAction_GetResult_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    vda5050_connector__action__ProcessVDAAction_GetResult_Response * data =
      (vda5050_connector__action__ProcessVDAAction_GetResult_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vda5050_connector__action__ProcessVDAAction_GetResult_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          vda5050_connector__action__ProcessVDAAction_GetResult_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vda5050_connector__action__ProcessVDAAction_GetResult_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `feedback`
// already included above
// #include "vda5050_connector/action/detail/process_vda_action__functions.h"

bool
vda5050_connector__action__ProcessVDAAction_FeedbackMessage__init(vda5050_connector__action__ProcessVDAAction_FeedbackMessage * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    vda5050_connector__action__ProcessVDAAction_FeedbackMessage__fini(msg);
    return false;
  }
  // feedback
  if (!vda5050_connector__action__ProcessVDAAction_Feedback__init(&msg->feedback)) {
    vda5050_connector__action__ProcessVDAAction_FeedbackMessage__fini(msg);
    return false;
  }
  return true;
}

void
vda5050_connector__action__ProcessVDAAction_FeedbackMessage__fini(vda5050_connector__action__ProcessVDAAction_FeedbackMessage * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // feedback
  vda5050_connector__action__ProcessVDAAction_Feedback__fini(&msg->feedback);
}

bool
vda5050_connector__action__ProcessVDAAction_FeedbackMessage__are_equal(const vda5050_connector__action__ProcessVDAAction_FeedbackMessage * lhs, const vda5050_connector__action__ProcessVDAAction_FeedbackMessage * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // feedback
  if (!vda5050_connector__action__ProcessVDAAction_Feedback__are_equal(
      &(lhs->feedback), &(rhs->feedback)))
  {
    return false;
  }
  return true;
}

bool
vda5050_connector__action__ProcessVDAAction_FeedbackMessage__copy(
  const vda5050_connector__action__ProcessVDAAction_FeedbackMessage * input,
  vda5050_connector__action__ProcessVDAAction_FeedbackMessage * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // feedback
  if (!vda5050_connector__action__ProcessVDAAction_Feedback__copy(
      &(input->feedback), &(output->feedback)))
  {
    return false;
  }
  return true;
}

vda5050_connector__action__ProcessVDAAction_FeedbackMessage *
vda5050_connector__action__ProcessVDAAction_FeedbackMessage__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_connector__action__ProcessVDAAction_FeedbackMessage * msg = (vda5050_connector__action__ProcessVDAAction_FeedbackMessage *)allocator.allocate(sizeof(vda5050_connector__action__ProcessVDAAction_FeedbackMessage), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vda5050_connector__action__ProcessVDAAction_FeedbackMessage));
  bool success = vda5050_connector__action__ProcessVDAAction_FeedbackMessage__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vda5050_connector__action__ProcessVDAAction_FeedbackMessage__destroy(vda5050_connector__action__ProcessVDAAction_FeedbackMessage * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vda5050_connector__action__ProcessVDAAction_FeedbackMessage__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vda5050_connector__action__ProcessVDAAction_FeedbackMessage__Sequence__init(vda5050_connector__action__ProcessVDAAction_FeedbackMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_connector__action__ProcessVDAAction_FeedbackMessage * data = NULL;

  if (size) {
    data = (vda5050_connector__action__ProcessVDAAction_FeedbackMessage *)allocator.zero_allocate(size, sizeof(vda5050_connector__action__ProcessVDAAction_FeedbackMessage), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vda5050_connector__action__ProcessVDAAction_FeedbackMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vda5050_connector__action__ProcessVDAAction_FeedbackMessage__fini(&data[i - 1]);
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
vda5050_connector__action__ProcessVDAAction_FeedbackMessage__Sequence__fini(vda5050_connector__action__ProcessVDAAction_FeedbackMessage__Sequence * array)
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
      vda5050_connector__action__ProcessVDAAction_FeedbackMessage__fini(&array->data[i]);
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

vda5050_connector__action__ProcessVDAAction_FeedbackMessage__Sequence *
vda5050_connector__action__ProcessVDAAction_FeedbackMessage__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_connector__action__ProcessVDAAction_FeedbackMessage__Sequence * array = (vda5050_connector__action__ProcessVDAAction_FeedbackMessage__Sequence *)allocator.allocate(sizeof(vda5050_connector__action__ProcessVDAAction_FeedbackMessage__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vda5050_connector__action__ProcessVDAAction_FeedbackMessage__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vda5050_connector__action__ProcessVDAAction_FeedbackMessage__Sequence__destroy(vda5050_connector__action__ProcessVDAAction_FeedbackMessage__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vda5050_connector__action__ProcessVDAAction_FeedbackMessage__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vda5050_connector__action__ProcessVDAAction_FeedbackMessage__Sequence__are_equal(const vda5050_connector__action__ProcessVDAAction_FeedbackMessage__Sequence * lhs, const vda5050_connector__action__ProcessVDAAction_FeedbackMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vda5050_connector__action__ProcessVDAAction_FeedbackMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vda5050_connector__action__ProcessVDAAction_FeedbackMessage__Sequence__copy(
  const vda5050_connector__action__ProcessVDAAction_FeedbackMessage__Sequence * input,
  vda5050_connector__action__ProcessVDAAction_FeedbackMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vda5050_connector__action__ProcessVDAAction_FeedbackMessage);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    vda5050_connector__action__ProcessVDAAction_FeedbackMessage * data =
      (vda5050_connector__action__ProcessVDAAction_FeedbackMessage *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vda5050_connector__action__ProcessVDAAction_FeedbackMessage__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          vda5050_connector__action__ProcessVDAAction_FeedbackMessage__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vda5050_connector__action__ProcessVDAAction_FeedbackMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
