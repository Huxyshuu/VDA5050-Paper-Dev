// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from vda5050_msgs:msg/Envelope3D.idl
// generated code does not contain a copyright notice
#include "vda5050_msgs/msg/detail/envelope3_d__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `set`
// Member `format`
// Member `data`
// Member `url`
// Member `description`
#include "rosidl_runtime_c/string_functions.h"

bool
vda5050_msgs__msg__Envelope3D__init(vda5050_msgs__msg__Envelope3D * msg)
{
  if (!msg) {
    return false;
  }
  // set
  if (!rosidl_runtime_c__String__init(&msg->set)) {
    vda5050_msgs__msg__Envelope3D__fini(msg);
    return false;
  }
  // format
  if (!rosidl_runtime_c__String__init(&msg->format)) {
    vda5050_msgs__msg__Envelope3D__fini(msg);
    return false;
  }
  // data
  if (!rosidl_runtime_c__String__init(&msg->data)) {
    vda5050_msgs__msg__Envelope3D__fini(msg);
    return false;
  }
  // url
  if (!rosidl_runtime_c__String__init(&msg->url)) {
    vda5050_msgs__msg__Envelope3D__fini(msg);
    return false;
  }
  // description
  if (!rosidl_runtime_c__String__init(&msg->description)) {
    vda5050_msgs__msg__Envelope3D__fini(msg);
    return false;
  }
  return true;
}

void
vda5050_msgs__msg__Envelope3D__fini(vda5050_msgs__msg__Envelope3D * msg)
{
  if (!msg) {
    return;
  }
  // set
  rosidl_runtime_c__String__fini(&msg->set);
  // format
  rosidl_runtime_c__String__fini(&msg->format);
  // data
  rosidl_runtime_c__String__fini(&msg->data);
  // url
  rosidl_runtime_c__String__fini(&msg->url);
  // description
  rosidl_runtime_c__String__fini(&msg->description);
}

bool
vda5050_msgs__msg__Envelope3D__are_equal(const vda5050_msgs__msg__Envelope3D * lhs, const vda5050_msgs__msg__Envelope3D * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // set
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->set), &(rhs->set)))
  {
    return false;
  }
  // format
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->format), &(rhs->format)))
  {
    return false;
  }
  // data
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->data), &(rhs->data)))
  {
    return false;
  }
  // url
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->url), &(rhs->url)))
  {
    return false;
  }
  // description
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->description), &(rhs->description)))
  {
    return false;
  }
  return true;
}

bool
vda5050_msgs__msg__Envelope3D__copy(
  const vda5050_msgs__msg__Envelope3D * input,
  vda5050_msgs__msg__Envelope3D * output)
{
  if (!input || !output) {
    return false;
  }
  // set
  if (!rosidl_runtime_c__String__copy(
      &(input->set), &(output->set)))
  {
    return false;
  }
  // format
  if (!rosidl_runtime_c__String__copy(
      &(input->format), &(output->format)))
  {
    return false;
  }
  // data
  if (!rosidl_runtime_c__String__copy(
      &(input->data), &(output->data)))
  {
    return false;
  }
  // url
  if (!rosidl_runtime_c__String__copy(
      &(input->url), &(output->url)))
  {
    return false;
  }
  // description
  if (!rosidl_runtime_c__String__copy(
      &(input->description), &(output->description)))
  {
    return false;
  }
  return true;
}

vda5050_msgs__msg__Envelope3D *
vda5050_msgs__msg__Envelope3D__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__Envelope3D * msg = (vda5050_msgs__msg__Envelope3D *)allocator.allocate(sizeof(vda5050_msgs__msg__Envelope3D), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vda5050_msgs__msg__Envelope3D));
  bool success = vda5050_msgs__msg__Envelope3D__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vda5050_msgs__msg__Envelope3D__destroy(vda5050_msgs__msg__Envelope3D * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vda5050_msgs__msg__Envelope3D__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vda5050_msgs__msg__Envelope3D__Sequence__init(vda5050_msgs__msg__Envelope3D__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__Envelope3D * data = NULL;

  if (size) {
    data = (vda5050_msgs__msg__Envelope3D *)allocator.zero_allocate(size, sizeof(vda5050_msgs__msg__Envelope3D), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vda5050_msgs__msg__Envelope3D__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vda5050_msgs__msg__Envelope3D__fini(&data[i - 1]);
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
vda5050_msgs__msg__Envelope3D__Sequence__fini(vda5050_msgs__msg__Envelope3D__Sequence * array)
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
      vda5050_msgs__msg__Envelope3D__fini(&array->data[i]);
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

vda5050_msgs__msg__Envelope3D__Sequence *
vda5050_msgs__msg__Envelope3D__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__Envelope3D__Sequence * array = (vda5050_msgs__msg__Envelope3D__Sequence *)allocator.allocate(sizeof(vda5050_msgs__msg__Envelope3D__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vda5050_msgs__msg__Envelope3D__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vda5050_msgs__msg__Envelope3D__Sequence__destroy(vda5050_msgs__msg__Envelope3D__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vda5050_msgs__msg__Envelope3D__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vda5050_msgs__msg__Envelope3D__Sequence__are_equal(const vda5050_msgs__msg__Envelope3D__Sequence * lhs, const vda5050_msgs__msg__Envelope3D__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vda5050_msgs__msg__Envelope3D__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vda5050_msgs__msg__Envelope3D__Sequence__copy(
  const vda5050_msgs__msg__Envelope3D__Sequence * input,
  vda5050_msgs__msg__Envelope3D__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vda5050_msgs__msg__Envelope3D);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    vda5050_msgs__msg__Envelope3D * data =
      (vda5050_msgs__msg__Envelope3D *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vda5050_msgs__msg__Envelope3D__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          vda5050_msgs__msg__Envelope3D__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vda5050_msgs__msg__Envelope3D__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
