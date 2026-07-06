// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from vda5050_msgs:msg/Edge.idl
// generated code does not contain a copyright notice
#include "vda5050_msgs/msg/detail/edge__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `edge_id`
// Member `edge_description`
// Member `start_node_id`
// Member `end_node_id`
// Member `direction`
#include "rosidl_runtime_c/string_functions.h"
// Member `trajectory`
#include "vda5050_msgs/msg/detail/trajectory__functions.h"
// Member `actions`
#include "vda5050_msgs/msg/detail/action__functions.h"

bool
vda5050_msgs__msg__Edge__init(vda5050_msgs__msg__Edge * msg)
{
  if (!msg) {
    return false;
  }
  // edge_id
  if (!rosidl_runtime_c__String__init(&msg->edge_id)) {
    vda5050_msgs__msg__Edge__fini(msg);
    return false;
  }
  // sequence_id
  // edge_description
  if (!rosidl_runtime_c__String__init(&msg->edge_description)) {
    vda5050_msgs__msg__Edge__fini(msg);
    return false;
  }
  // released
  // start_node_id
  if (!rosidl_runtime_c__String__init(&msg->start_node_id)) {
    vda5050_msgs__msg__Edge__fini(msg);
    return false;
  }
  // end_node_id
  if (!rosidl_runtime_c__String__init(&msg->end_node_id)) {
    vda5050_msgs__msg__Edge__fini(msg);
    return false;
  }
  // max_speed
  // max_height
  // min_height
  // orientation
  // direction
  if (!rosidl_runtime_c__String__init(&msg->direction)) {
    vda5050_msgs__msg__Edge__fini(msg);
    return false;
  }
  // rotation_allowed
  // max_rotation_speed
  // trajectory
  if (!vda5050_msgs__msg__Trajectory__init(&msg->trajectory)) {
    vda5050_msgs__msg__Edge__fini(msg);
    return false;
  }
  // length
  // actions
  if (!vda5050_msgs__msg__Action__Sequence__init(&msg->actions, 0)) {
    vda5050_msgs__msg__Edge__fini(msg);
    return false;
  }
  return true;
}

void
vda5050_msgs__msg__Edge__fini(vda5050_msgs__msg__Edge * msg)
{
  if (!msg) {
    return;
  }
  // edge_id
  rosidl_runtime_c__String__fini(&msg->edge_id);
  // sequence_id
  // edge_description
  rosidl_runtime_c__String__fini(&msg->edge_description);
  // released
  // start_node_id
  rosidl_runtime_c__String__fini(&msg->start_node_id);
  // end_node_id
  rosidl_runtime_c__String__fini(&msg->end_node_id);
  // max_speed
  // max_height
  // min_height
  // orientation
  // direction
  rosidl_runtime_c__String__fini(&msg->direction);
  // rotation_allowed
  // max_rotation_speed
  // trajectory
  vda5050_msgs__msg__Trajectory__fini(&msg->trajectory);
  // length
  // actions
  vda5050_msgs__msg__Action__Sequence__fini(&msg->actions);
}

bool
vda5050_msgs__msg__Edge__are_equal(const vda5050_msgs__msg__Edge * lhs, const vda5050_msgs__msg__Edge * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // edge_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->edge_id), &(rhs->edge_id)))
  {
    return false;
  }
  // sequence_id
  if (lhs->sequence_id != rhs->sequence_id) {
    return false;
  }
  // edge_description
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->edge_description), &(rhs->edge_description)))
  {
    return false;
  }
  // released
  if (lhs->released != rhs->released) {
    return false;
  }
  // start_node_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->start_node_id), &(rhs->start_node_id)))
  {
    return false;
  }
  // end_node_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->end_node_id), &(rhs->end_node_id)))
  {
    return false;
  }
  // max_speed
  if (lhs->max_speed != rhs->max_speed) {
    return false;
  }
  // max_height
  if (lhs->max_height != rhs->max_height) {
    return false;
  }
  // min_height
  if (lhs->min_height != rhs->min_height) {
    return false;
  }
  // orientation
  if (lhs->orientation != rhs->orientation) {
    return false;
  }
  // direction
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->direction), &(rhs->direction)))
  {
    return false;
  }
  // rotation_allowed
  if (lhs->rotation_allowed != rhs->rotation_allowed) {
    return false;
  }
  // max_rotation_speed
  if (lhs->max_rotation_speed != rhs->max_rotation_speed) {
    return false;
  }
  // trajectory
  if (!vda5050_msgs__msg__Trajectory__are_equal(
      &(lhs->trajectory), &(rhs->trajectory)))
  {
    return false;
  }
  // length
  if (lhs->length != rhs->length) {
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
vda5050_msgs__msg__Edge__copy(
  const vda5050_msgs__msg__Edge * input,
  vda5050_msgs__msg__Edge * output)
{
  if (!input || !output) {
    return false;
  }
  // edge_id
  if (!rosidl_runtime_c__String__copy(
      &(input->edge_id), &(output->edge_id)))
  {
    return false;
  }
  // sequence_id
  output->sequence_id = input->sequence_id;
  // edge_description
  if (!rosidl_runtime_c__String__copy(
      &(input->edge_description), &(output->edge_description)))
  {
    return false;
  }
  // released
  output->released = input->released;
  // start_node_id
  if (!rosidl_runtime_c__String__copy(
      &(input->start_node_id), &(output->start_node_id)))
  {
    return false;
  }
  // end_node_id
  if (!rosidl_runtime_c__String__copy(
      &(input->end_node_id), &(output->end_node_id)))
  {
    return false;
  }
  // max_speed
  output->max_speed = input->max_speed;
  // max_height
  output->max_height = input->max_height;
  // min_height
  output->min_height = input->min_height;
  // orientation
  output->orientation = input->orientation;
  // direction
  if (!rosidl_runtime_c__String__copy(
      &(input->direction), &(output->direction)))
  {
    return false;
  }
  // rotation_allowed
  output->rotation_allowed = input->rotation_allowed;
  // max_rotation_speed
  output->max_rotation_speed = input->max_rotation_speed;
  // trajectory
  if (!vda5050_msgs__msg__Trajectory__copy(
      &(input->trajectory), &(output->trajectory)))
  {
    return false;
  }
  // length
  output->length = input->length;
  // actions
  if (!vda5050_msgs__msg__Action__Sequence__copy(
      &(input->actions), &(output->actions)))
  {
    return false;
  }
  return true;
}

vda5050_msgs__msg__Edge *
vda5050_msgs__msg__Edge__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__Edge * msg = (vda5050_msgs__msg__Edge *)allocator.allocate(sizeof(vda5050_msgs__msg__Edge), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vda5050_msgs__msg__Edge));
  bool success = vda5050_msgs__msg__Edge__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vda5050_msgs__msg__Edge__destroy(vda5050_msgs__msg__Edge * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vda5050_msgs__msg__Edge__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vda5050_msgs__msg__Edge__Sequence__init(vda5050_msgs__msg__Edge__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__Edge * data = NULL;

  if (size) {
    data = (vda5050_msgs__msg__Edge *)allocator.zero_allocate(size, sizeof(vda5050_msgs__msg__Edge), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vda5050_msgs__msg__Edge__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vda5050_msgs__msg__Edge__fini(&data[i - 1]);
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
vda5050_msgs__msg__Edge__Sequence__fini(vda5050_msgs__msg__Edge__Sequence * array)
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
      vda5050_msgs__msg__Edge__fini(&array->data[i]);
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

vda5050_msgs__msg__Edge__Sequence *
vda5050_msgs__msg__Edge__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__Edge__Sequence * array = (vda5050_msgs__msg__Edge__Sequence *)allocator.allocate(sizeof(vda5050_msgs__msg__Edge__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vda5050_msgs__msg__Edge__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vda5050_msgs__msg__Edge__Sequence__destroy(vda5050_msgs__msg__Edge__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vda5050_msgs__msg__Edge__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vda5050_msgs__msg__Edge__Sequence__are_equal(const vda5050_msgs__msg__Edge__Sequence * lhs, const vda5050_msgs__msg__Edge__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vda5050_msgs__msg__Edge__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vda5050_msgs__msg__Edge__Sequence__copy(
  const vda5050_msgs__msg__Edge__Sequence * input,
  vda5050_msgs__msg__Edge__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vda5050_msgs__msg__Edge);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    vda5050_msgs__msg__Edge * data =
      (vda5050_msgs__msg__Edge *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vda5050_msgs__msg__Edge__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          vda5050_msgs__msg__Edge__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vda5050_msgs__msg__Edge__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
