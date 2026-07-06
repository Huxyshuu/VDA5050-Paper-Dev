// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from vda5050_msgs:msg/Order.idl
// generated code does not contain a copyright notice
#include "vda5050_msgs/msg/detail/order__functions.h"

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
// Member `order_id`
// Member `zone_set_id`
#include "rosidl_runtime_c/string_functions.h"
// Member `nodes`
#include "vda5050_msgs/msg/detail/node__functions.h"
// Member `edges`
#include "vda5050_msgs/msg/detail/edge__functions.h"

bool
vda5050_msgs__msg__Order__init(vda5050_msgs__msg__Order * msg)
{
  if (!msg) {
    return false;
  }
  // header_id
  // timestamp
  if (!rosidl_runtime_c__String__init(&msg->timestamp)) {
    vda5050_msgs__msg__Order__fini(msg);
    return false;
  }
  // version
  if (!rosidl_runtime_c__String__init(&msg->version)) {
    vda5050_msgs__msg__Order__fini(msg);
    return false;
  }
  // manufacturer
  if (!rosidl_runtime_c__String__init(&msg->manufacturer)) {
    vda5050_msgs__msg__Order__fini(msg);
    return false;
  }
  // serial_number
  if (!rosidl_runtime_c__String__init(&msg->serial_number)) {
    vda5050_msgs__msg__Order__fini(msg);
    return false;
  }
  // order_id
  if (!rosidl_runtime_c__String__init(&msg->order_id)) {
    vda5050_msgs__msg__Order__fini(msg);
    return false;
  }
  // order_update_id
  // zone_set_id
  if (!rosidl_runtime_c__String__init(&msg->zone_set_id)) {
    vda5050_msgs__msg__Order__fini(msg);
    return false;
  }
  // nodes
  if (!vda5050_msgs__msg__Node__Sequence__init(&msg->nodes, 0)) {
    vda5050_msgs__msg__Order__fini(msg);
    return false;
  }
  // edges
  if (!vda5050_msgs__msg__Edge__Sequence__init(&msg->edges, 0)) {
    vda5050_msgs__msg__Order__fini(msg);
    return false;
  }
  return true;
}

void
vda5050_msgs__msg__Order__fini(vda5050_msgs__msg__Order * msg)
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
  // order_id
  rosidl_runtime_c__String__fini(&msg->order_id);
  // order_update_id
  // zone_set_id
  rosidl_runtime_c__String__fini(&msg->zone_set_id);
  // nodes
  vda5050_msgs__msg__Node__Sequence__fini(&msg->nodes);
  // edges
  vda5050_msgs__msg__Edge__Sequence__fini(&msg->edges);
}

bool
vda5050_msgs__msg__Order__are_equal(const vda5050_msgs__msg__Order * lhs, const vda5050_msgs__msg__Order * rhs)
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
  // order_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->order_id), &(rhs->order_id)))
  {
    return false;
  }
  // order_update_id
  if (lhs->order_update_id != rhs->order_update_id) {
    return false;
  }
  // zone_set_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->zone_set_id), &(rhs->zone_set_id)))
  {
    return false;
  }
  // nodes
  if (!vda5050_msgs__msg__Node__Sequence__are_equal(
      &(lhs->nodes), &(rhs->nodes)))
  {
    return false;
  }
  // edges
  if (!vda5050_msgs__msg__Edge__Sequence__are_equal(
      &(lhs->edges), &(rhs->edges)))
  {
    return false;
  }
  return true;
}

bool
vda5050_msgs__msg__Order__copy(
  const vda5050_msgs__msg__Order * input,
  vda5050_msgs__msg__Order * output)
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
  // order_id
  if (!rosidl_runtime_c__String__copy(
      &(input->order_id), &(output->order_id)))
  {
    return false;
  }
  // order_update_id
  output->order_update_id = input->order_update_id;
  // zone_set_id
  if (!rosidl_runtime_c__String__copy(
      &(input->zone_set_id), &(output->zone_set_id)))
  {
    return false;
  }
  // nodes
  if (!vda5050_msgs__msg__Node__Sequence__copy(
      &(input->nodes), &(output->nodes)))
  {
    return false;
  }
  // edges
  if (!vda5050_msgs__msg__Edge__Sequence__copy(
      &(input->edges), &(output->edges)))
  {
    return false;
  }
  return true;
}

vda5050_msgs__msg__Order *
vda5050_msgs__msg__Order__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__Order * msg = (vda5050_msgs__msg__Order *)allocator.allocate(sizeof(vda5050_msgs__msg__Order), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vda5050_msgs__msg__Order));
  bool success = vda5050_msgs__msg__Order__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vda5050_msgs__msg__Order__destroy(vda5050_msgs__msg__Order * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vda5050_msgs__msg__Order__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vda5050_msgs__msg__Order__Sequence__init(vda5050_msgs__msg__Order__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__Order * data = NULL;

  if (size) {
    data = (vda5050_msgs__msg__Order *)allocator.zero_allocate(size, sizeof(vda5050_msgs__msg__Order), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vda5050_msgs__msg__Order__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vda5050_msgs__msg__Order__fini(&data[i - 1]);
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
vda5050_msgs__msg__Order__Sequence__fini(vda5050_msgs__msg__Order__Sequence * array)
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
      vda5050_msgs__msg__Order__fini(&array->data[i]);
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

vda5050_msgs__msg__Order__Sequence *
vda5050_msgs__msg__Order__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__Order__Sequence * array = (vda5050_msgs__msg__Order__Sequence *)allocator.allocate(sizeof(vda5050_msgs__msg__Order__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vda5050_msgs__msg__Order__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vda5050_msgs__msg__Order__Sequence__destroy(vda5050_msgs__msg__Order__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vda5050_msgs__msg__Order__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vda5050_msgs__msg__Order__Sequence__are_equal(const vda5050_msgs__msg__Order__Sequence * lhs, const vda5050_msgs__msg__Order__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vda5050_msgs__msg__Order__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vda5050_msgs__msg__Order__Sequence__copy(
  const vda5050_msgs__msg__Order__Sequence * input,
  vda5050_msgs__msg__Order__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vda5050_msgs__msg__Order);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    vda5050_msgs__msg__Order * data =
      (vda5050_msgs__msg__Order *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vda5050_msgs__msg__Order__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          vda5050_msgs__msg__Order__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vda5050_msgs__msg__Order__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
