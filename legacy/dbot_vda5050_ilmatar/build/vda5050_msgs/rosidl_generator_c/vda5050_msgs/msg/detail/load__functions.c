// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from vda5050_msgs:msg/Load.idl
// generated code does not contain a copyright notice
#include "vda5050_msgs/msg/detail/load__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `load_id`
// Member `load_type`
// Member `load_position`
#include "rosidl_runtime_c/string_functions.h"
// Member `bounding_box_reference`
#include "vda5050_msgs/msg/detail/bounding_box_reference__functions.h"
// Member `load_dimensions`
#include "vda5050_msgs/msg/detail/load_dimensions__functions.h"

bool
vda5050_msgs__msg__Load__init(vda5050_msgs__msg__Load * msg)
{
  if (!msg) {
    return false;
  }
  // load_id
  if (!rosidl_runtime_c__String__init(&msg->load_id)) {
    vda5050_msgs__msg__Load__fini(msg);
    return false;
  }
  // load_type
  if (!rosidl_runtime_c__String__init(&msg->load_type)) {
    vda5050_msgs__msg__Load__fini(msg);
    return false;
  }
  // load_position
  if (!rosidl_runtime_c__String__init(&msg->load_position)) {
    vda5050_msgs__msg__Load__fini(msg);
    return false;
  }
  // bounding_box_reference
  if (!vda5050_msgs__msg__BoundingBoxReference__init(&msg->bounding_box_reference)) {
    vda5050_msgs__msg__Load__fini(msg);
    return false;
  }
  // load_dimensions
  if (!vda5050_msgs__msg__LoadDimensions__init(&msg->load_dimensions)) {
    vda5050_msgs__msg__Load__fini(msg);
    return false;
  }
  // weight
  return true;
}

void
vda5050_msgs__msg__Load__fini(vda5050_msgs__msg__Load * msg)
{
  if (!msg) {
    return;
  }
  // load_id
  rosidl_runtime_c__String__fini(&msg->load_id);
  // load_type
  rosidl_runtime_c__String__fini(&msg->load_type);
  // load_position
  rosidl_runtime_c__String__fini(&msg->load_position);
  // bounding_box_reference
  vda5050_msgs__msg__BoundingBoxReference__fini(&msg->bounding_box_reference);
  // load_dimensions
  vda5050_msgs__msg__LoadDimensions__fini(&msg->load_dimensions);
  // weight
}

bool
vda5050_msgs__msg__Load__are_equal(const vda5050_msgs__msg__Load * lhs, const vda5050_msgs__msg__Load * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // load_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->load_id), &(rhs->load_id)))
  {
    return false;
  }
  // load_type
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->load_type), &(rhs->load_type)))
  {
    return false;
  }
  // load_position
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->load_position), &(rhs->load_position)))
  {
    return false;
  }
  // bounding_box_reference
  if (!vda5050_msgs__msg__BoundingBoxReference__are_equal(
      &(lhs->bounding_box_reference), &(rhs->bounding_box_reference)))
  {
    return false;
  }
  // load_dimensions
  if (!vda5050_msgs__msg__LoadDimensions__are_equal(
      &(lhs->load_dimensions), &(rhs->load_dimensions)))
  {
    return false;
  }
  // weight
  if (lhs->weight != rhs->weight) {
    return false;
  }
  return true;
}

bool
vda5050_msgs__msg__Load__copy(
  const vda5050_msgs__msg__Load * input,
  vda5050_msgs__msg__Load * output)
{
  if (!input || !output) {
    return false;
  }
  // load_id
  if (!rosidl_runtime_c__String__copy(
      &(input->load_id), &(output->load_id)))
  {
    return false;
  }
  // load_type
  if (!rosidl_runtime_c__String__copy(
      &(input->load_type), &(output->load_type)))
  {
    return false;
  }
  // load_position
  if (!rosidl_runtime_c__String__copy(
      &(input->load_position), &(output->load_position)))
  {
    return false;
  }
  // bounding_box_reference
  if (!vda5050_msgs__msg__BoundingBoxReference__copy(
      &(input->bounding_box_reference), &(output->bounding_box_reference)))
  {
    return false;
  }
  // load_dimensions
  if (!vda5050_msgs__msg__LoadDimensions__copy(
      &(input->load_dimensions), &(output->load_dimensions)))
  {
    return false;
  }
  // weight
  output->weight = input->weight;
  return true;
}

vda5050_msgs__msg__Load *
vda5050_msgs__msg__Load__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__Load * msg = (vda5050_msgs__msg__Load *)allocator.allocate(sizeof(vda5050_msgs__msg__Load), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vda5050_msgs__msg__Load));
  bool success = vda5050_msgs__msg__Load__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vda5050_msgs__msg__Load__destroy(vda5050_msgs__msg__Load * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vda5050_msgs__msg__Load__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vda5050_msgs__msg__Load__Sequence__init(vda5050_msgs__msg__Load__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__Load * data = NULL;

  if (size) {
    data = (vda5050_msgs__msg__Load *)allocator.zero_allocate(size, sizeof(vda5050_msgs__msg__Load), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vda5050_msgs__msg__Load__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vda5050_msgs__msg__Load__fini(&data[i - 1]);
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
vda5050_msgs__msg__Load__Sequence__fini(vda5050_msgs__msg__Load__Sequence * array)
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
      vda5050_msgs__msg__Load__fini(&array->data[i]);
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

vda5050_msgs__msg__Load__Sequence *
vda5050_msgs__msg__Load__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__Load__Sequence * array = (vda5050_msgs__msg__Load__Sequence *)allocator.allocate(sizeof(vda5050_msgs__msg__Load__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vda5050_msgs__msg__Load__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vda5050_msgs__msg__Load__Sequence__destroy(vda5050_msgs__msg__Load__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vda5050_msgs__msg__Load__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vda5050_msgs__msg__Load__Sequence__are_equal(const vda5050_msgs__msg__Load__Sequence * lhs, const vda5050_msgs__msg__Load__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vda5050_msgs__msg__Load__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vda5050_msgs__msg__Load__Sequence__copy(
  const vda5050_msgs__msg__Load__Sequence * input,
  vda5050_msgs__msg__Load__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vda5050_msgs__msg__Load);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    vda5050_msgs__msg__Load * data =
      (vda5050_msgs__msg__Load *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vda5050_msgs__msg__Load__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          vda5050_msgs__msg__Load__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vda5050_msgs__msg__Load__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
