// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from vda5050_msgs:msg/Node.idl
// generated code does not contain a copyright notice
#include "vda5050_msgs/msg/detail/node__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `node_id`
// Member `node_description`
#include "rosidl_runtime_c/string_functions.h"
// Member `node_position`
#include "vda5050_msgs/msg/detail/node_position__functions.h"
// Member `actions`
#include "vda5050_msgs/msg/detail/action__functions.h"

bool
vda5050_msgs__msg__Node__init(vda5050_msgs__msg__Node * msg)
{
  if (!msg) {
    return false;
  }
  // node_id
  if (!rosidl_runtime_c__String__init(&msg->node_id)) {
    vda5050_msgs__msg__Node__fini(msg);
    return false;
  }
  // sequence_id
  // node_description
  if (!rosidl_runtime_c__String__init(&msg->node_description)) {
    vda5050_msgs__msg__Node__fini(msg);
    return false;
  }
  // released
  // node_position
  if (!vda5050_msgs__msg__NodePosition__init(&msg->node_position)) {
    vda5050_msgs__msg__Node__fini(msg);
    return false;
  }
  // actions
  if (!vda5050_msgs__msg__Action__Sequence__init(&msg->actions, 0)) {
    vda5050_msgs__msg__Node__fini(msg);
    return false;
  }
  return true;
}

void
vda5050_msgs__msg__Node__fini(vda5050_msgs__msg__Node * msg)
{
  if (!msg) {
    return;
  }
  // node_id
  rosidl_runtime_c__String__fini(&msg->node_id);
  // sequence_id
  // node_description
  rosidl_runtime_c__String__fini(&msg->node_description);
  // released
  // node_position
  vda5050_msgs__msg__NodePosition__fini(&msg->node_position);
  // actions
  vda5050_msgs__msg__Action__Sequence__fini(&msg->actions);
}

bool
vda5050_msgs__msg__Node__are_equal(const vda5050_msgs__msg__Node * lhs, const vda5050_msgs__msg__Node * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // node_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->node_id), &(rhs->node_id)))
  {
    return false;
  }
  // sequence_id
  if (lhs->sequence_id != rhs->sequence_id) {
    return false;
  }
  // node_description
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->node_description), &(rhs->node_description)))
  {
    return false;
  }
  // released
  if (lhs->released != rhs->released) {
    return false;
  }
  // node_position
  if (!vda5050_msgs__msg__NodePosition__are_equal(
      &(lhs->node_position), &(rhs->node_position)))
  {
    return false;
  }
  // actions
  if (!vda5050_msgs__msg__Action__Sequence__are_equal(
      &(lhs->actions), &(rhs->actions)))
  {
    return false;
  }
  return true;
}

bool
vda5050_msgs__msg__Node__copy(
  const vda5050_msgs__msg__Node * input,
  vda5050_msgs__msg__Node * output)
{
  if (!input || !output) {
    return false;
  }
  // node_id
  if (!rosidl_runtime_c__String__copy(
      &(input->node_id), &(output->node_id)))
  {
    return false;
  }
  // sequence_id
  output->sequence_id = input->sequence_id;
  // node_description
  if (!rosidl_runtime_c__String__copy(
      &(input->node_description), &(output->node_description)))
  {
    return false;
  }
  // released
  output->released = input->released;
  // node_position
  if (!vda5050_msgs__msg__NodePosition__copy(
      &(input->node_position), &(output->node_position)))
  {
    return false;
  }
  // actions
  if (!vda5050_msgs__msg__Action__Sequence__copy(
      &(input->actions), &(output->actions)))
  {
    return false;
  }
  return true;
}

vda5050_msgs__msg__Node *
vda5050_msgs__msg__Node__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__Node * msg = (vda5050_msgs__msg__Node *)allocator.allocate(sizeof(vda5050_msgs__msg__Node), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vda5050_msgs__msg__Node));
  bool success = vda5050_msgs__msg__Node__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vda5050_msgs__msg__Node__destroy(vda5050_msgs__msg__Node * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vda5050_msgs__msg__Node__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vda5050_msgs__msg__Node__Sequence__init(vda5050_msgs__msg__Node__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__Node * data = NULL;

  if (size) {
    data = (vda5050_msgs__msg__Node *)allocator.zero_allocate(size, sizeof(vda5050_msgs__msg__Node), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vda5050_msgs__msg__Node__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vda5050_msgs__msg__Node__fini(&data[i - 1]);
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
vda5050_msgs__msg__Node__Sequence__fini(vda5050_msgs__msg__Node__Sequence * array)
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
      vda5050_msgs__msg__Node__fini(&array->data[i]);
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

vda5050_msgs__msg__Node__Sequence *
vda5050_msgs__msg__Node__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__Node__Sequence * array = (vda5050_msgs__msg__Node__Sequence *)allocator.allocate(sizeof(vda5050_msgs__msg__Node__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vda5050_msgs__msg__Node__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vda5050_msgs__msg__Node__Sequence__destroy(vda5050_msgs__msg__Node__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vda5050_msgs__msg__Node__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vda5050_msgs__msg__Node__Sequence__are_equal(const vda5050_msgs__msg__Node__Sequence * lhs, const vda5050_msgs__msg__Node__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vda5050_msgs__msg__Node__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vda5050_msgs__msg__Node__Sequence__copy(
  const vda5050_msgs__msg__Node__Sequence * input,
  vda5050_msgs__msg__Node__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vda5050_msgs__msg__Node);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    vda5050_msgs__msg__Node * data =
      (vda5050_msgs__msg__Node *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vda5050_msgs__msg__Node__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          vda5050_msgs__msg__Node__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vda5050_msgs__msg__Node__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
