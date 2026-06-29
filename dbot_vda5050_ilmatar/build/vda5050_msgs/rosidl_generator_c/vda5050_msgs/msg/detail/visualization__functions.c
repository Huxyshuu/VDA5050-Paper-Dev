// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from vda5050_msgs:msg/Visualization.idl
// generated code does not contain a copyright notice
#include "vda5050_msgs/msg/detail/visualization__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `timestamp`
// Member `version`
// Member `manufacturer`
// Member `serial_number`
#include "rosidl_runtime_c/string_functions.h"
// Member `agv_position`
#include "vda5050_msgs/msg/detail/agv_position__functions.h"
// Member `velocity`
#include "vda5050_msgs/msg/detail/velocity__functions.h"

bool
vda5050_msgs__msg__Visualization__init(vda5050_msgs__msg__Visualization * msg)
{
  if (!msg) {
    return false;
  }
  // header_id
  // timestamp
  if (!rosidl_runtime_c__String__init(&msg->timestamp)) {
    vda5050_msgs__msg__Visualization__fini(msg);
    return false;
  }
  // version
  if (!rosidl_runtime_c__String__init(&msg->version)) {
    vda5050_msgs__msg__Visualization__fini(msg);
    return false;
  }
  // manufacturer
  if (!rosidl_runtime_c__String__init(&msg->manufacturer)) {
    vda5050_msgs__msg__Visualization__fini(msg);
    return false;
  }
  // serial_number
  if (!rosidl_runtime_c__String__init(&msg->serial_number)) {
    vda5050_msgs__msg__Visualization__fini(msg);
    return false;
  }
  // agv_position
  if (!vda5050_msgs__msg__AGVPosition__init(&msg->agv_position)) {
    vda5050_msgs__msg__Visualization__fini(msg);
    return false;
  }
  // velocity
  if (!vda5050_msgs__msg__Velocity__init(&msg->velocity)) {
    vda5050_msgs__msg__Visualization__fini(msg);
    return false;
  }
  return true;
}

void
vda5050_msgs__msg__Visualization__fini(vda5050_msgs__msg__Visualization * msg)
{
  if (!msg) {
    return;
  }
  // header_id
  // timestamp
  rosidl_runtime_c__String__fini(&msg->timestamp);
  // version
  rosidl_runtime_c__String__fini(&msg->version);
  // manufacturer
  rosidl_runtime_c__String__fini(&msg->manufacturer);
  // serial_number
  rosidl_runtime_c__String__fini(&msg->serial_number);
  // agv_position
  vda5050_msgs__msg__AGVPosition__fini(&msg->agv_position);
  // velocity
  vda5050_msgs__msg__Velocity__fini(&msg->velocity);
}

bool
vda5050_msgs__msg__Visualization__are_equal(const vda5050_msgs__msg__Visualization * lhs, const vda5050_msgs__msg__Visualization * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header_id
  if (lhs->header_id != rhs->header_id) {
    return false;
  }
  // timestamp
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->timestamp), &(rhs->timestamp)))
  {
    return false;
  }
  // version
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->version), &(rhs->version)))
  {
    return false;
  }
  // manufacturer
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->manufacturer), &(rhs->manufacturer)))
  {
    return false;
  }
  // serial_number
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->serial_number), &(rhs->serial_number)))
  {
    return false;
  }
  // agv_position
  if (!vda5050_msgs__msg__AGVPosition__are_equal(
      &(lhs->agv_position), &(rhs->agv_position)))
  {
    return false;
  }
  // velocity
  if (!vda5050_msgs__msg__Velocity__are_equal(
      &(lhs->velocity), &(rhs->velocity)))
  {
    return false;
  }
  return true;
}

bool
vda5050_msgs__msg__Visualization__copy(
  const vda5050_msgs__msg__Visualization * input,
  vda5050_msgs__msg__Visualization * output)
{
  if (!input || !output) {
    return false;
  }
  // header_id
  output->header_id = input->header_id;
  // timestamp
  if (!rosidl_runtime_c__String__copy(
      &(input->timestamp), &(output->timestamp)))
  {
    return false;
  }
  // version
  if (!rosidl_runtime_c__String__copy(
      &(input->version), &(output->version)))
  {
    return false;
  }
  // manufacturer
  if (!rosidl_runtime_c__String__copy(
      &(input->manufacturer), &(output->manufacturer)))
  {
    return false;
  }
  // serial_number
  if (!rosidl_runtime_c__String__copy(
      &(input->serial_number), &(output->serial_number)))
  {
    return false;
  }
  // agv_position
  if (!vda5050_msgs__msg__AGVPosition__copy(
      &(input->agv_position), &(output->agv_position)))
  {
    return false;
  }
  // velocity
  if (!vda5050_msgs__msg__Velocity__copy(
      &(input->velocity), &(output->velocity)))
  {
    return false;
  }
  return true;
}

vda5050_msgs__msg__Visualization *
vda5050_msgs__msg__Visualization__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__Visualization * msg = (vda5050_msgs__msg__Visualization *)allocator.allocate(sizeof(vda5050_msgs__msg__Visualization), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vda5050_msgs__msg__Visualization));
  bool success = vda5050_msgs__msg__Visualization__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vda5050_msgs__msg__Visualization__destroy(vda5050_msgs__msg__Visualization * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vda5050_msgs__msg__Visualization__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vda5050_msgs__msg__Visualization__Sequence__init(vda5050_msgs__msg__Visualization__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__Visualization * data = NULL;

  if (size) {
    data = (vda5050_msgs__msg__Visualization *)allocator.zero_allocate(size, sizeof(vda5050_msgs__msg__Visualization), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vda5050_msgs__msg__Visualization__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vda5050_msgs__msg__Visualization__fini(&data[i - 1]);
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
vda5050_msgs__msg__Visualization__Sequence__fini(vda5050_msgs__msg__Visualization__Sequence * array)
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
      vda5050_msgs__msg__Visualization__fini(&array->data[i]);
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

vda5050_msgs__msg__Visualization__Sequence *
vda5050_msgs__msg__Visualization__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__Visualization__Sequence * array = (vda5050_msgs__msg__Visualization__Sequence *)allocator.allocate(sizeof(vda5050_msgs__msg__Visualization__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vda5050_msgs__msg__Visualization__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vda5050_msgs__msg__Visualization__Sequence__destroy(vda5050_msgs__msg__Visualization__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vda5050_msgs__msg__Visualization__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vda5050_msgs__msg__Visualization__Sequence__are_equal(const vda5050_msgs__msg__Visualization__Sequence * lhs, const vda5050_msgs__msg__Visualization__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vda5050_msgs__msg__Visualization__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vda5050_msgs__msg__Visualization__Sequence__copy(
  const vda5050_msgs__msg__Visualization__Sequence * input,
  vda5050_msgs__msg__Visualization__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vda5050_msgs__msg__Visualization);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    vda5050_msgs__msg__Visualization * data =
      (vda5050_msgs__msg__Visualization *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vda5050_msgs__msg__Visualization__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          vda5050_msgs__msg__Visualization__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vda5050_msgs__msg__Visualization__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
