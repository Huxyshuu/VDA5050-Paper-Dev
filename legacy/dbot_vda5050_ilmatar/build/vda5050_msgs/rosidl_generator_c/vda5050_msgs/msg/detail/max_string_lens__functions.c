// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from vda5050_msgs:msg/MaxStringLens.idl
// generated code does not contain a copyright notice
#include "vda5050_msgs/msg/detail/max_string_lens__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
vda5050_msgs__msg__MaxStringLens__init(vda5050_msgs__msg__MaxStringLens * msg)
{
  if (!msg) {
    return false;
  }
  // msg_len
  // topic_serial_len
  // topic_elem_len
  // id_len
  // id_numerical_only
  // enum_len
  // load_id_len
  return true;
}

void
vda5050_msgs__msg__MaxStringLens__fini(vda5050_msgs__msg__MaxStringLens * msg)
{
  if (!msg) {
    return;
  }
  // msg_len
  // topic_serial_len
  // topic_elem_len
  // id_len
  // id_numerical_only
  // enum_len
  // load_id_len
}

bool
vda5050_msgs__msg__MaxStringLens__are_equal(const vda5050_msgs__msg__MaxStringLens * lhs, const vda5050_msgs__msg__MaxStringLens * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // msg_len
  if (lhs->msg_len != rhs->msg_len) {
    return false;
  }
  // topic_serial_len
  if (lhs->topic_serial_len != rhs->topic_serial_len) {
    return false;
  }
  // topic_elem_len
  if (lhs->topic_elem_len != rhs->topic_elem_len) {
    return false;
  }
  // id_len
  if (lhs->id_len != rhs->id_len) {
    return false;
  }
  // id_numerical_only
  if (lhs->id_numerical_only != rhs->id_numerical_only) {
    return false;
  }
  // enum_len
  if (lhs->enum_len != rhs->enum_len) {
    return false;
  }
  // load_id_len
  if (lhs->load_id_len != rhs->load_id_len) {
    return false;
  }
  return true;
}

bool
vda5050_msgs__msg__MaxStringLens__copy(
  const vda5050_msgs__msg__MaxStringLens * input,
  vda5050_msgs__msg__MaxStringLens * output)
{
  if (!input || !output) {
    return false;
  }
  // msg_len
  output->msg_len = input->msg_len;
  // topic_serial_len
  output->topic_serial_len = input->topic_serial_len;
  // topic_elem_len
  output->topic_elem_len = input->topic_elem_len;
  // id_len
  output->id_len = input->id_len;
  // id_numerical_only
  output->id_numerical_only = input->id_numerical_only;
  // enum_len
  output->enum_len = input->enum_len;
  // load_id_len
  output->load_id_len = input->load_id_len;
  return true;
}

vda5050_msgs__msg__MaxStringLens *
vda5050_msgs__msg__MaxStringLens__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__MaxStringLens * msg = (vda5050_msgs__msg__MaxStringLens *)allocator.allocate(sizeof(vda5050_msgs__msg__MaxStringLens), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vda5050_msgs__msg__MaxStringLens));
  bool success = vda5050_msgs__msg__MaxStringLens__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vda5050_msgs__msg__MaxStringLens__destroy(vda5050_msgs__msg__MaxStringLens * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vda5050_msgs__msg__MaxStringLens__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vda5050_msgs__msg__MaxStringLens__Sequence__init(vda5050_msgs__msg__MaxStringLens__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__MaxStringLens * data = NULL;

  if (size) {
    data = (vda5050_msgs__msg__MaxStringLens *)allocator.zero_allocate(size, sizeof(vda5050_msgs__msg__MaxStringLens), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vda5050_msgs__msg__MaxStringLens__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vda5050_msgs__msg__MaxStringLens__fini(&data[i - 1]);
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
vda5050_msgs__msg__MaxStringLens__Sequence__fini(vda5050_msgs__msg__MaxStringLens__Sequence * array)
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
      vda5050_msgs__msg__MaxStringLens__fini(&array->data[i]);
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

vda5050_msgs__msg__MaxStringLens__Sequence *
vda5050_msgs__msg__MaxStringLens__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__MaxStringLens__Sequence * array = (vda5050_msgs__msg__MaxStringLens__Sequence *)allocator.allocate(sizeof(vda5050_msgs__msg__MaxStringLens__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vda5050_msgs__msg__MaxStringLens__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vda5050_msgs__msg__MaxStringLens__Sequence__destroy(vda5050_msgs__msg__MaxStringLens__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vda5050_msgs__msg__MaxStringLens__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vda5050_msgs__msg__MaxStringLens__Sequence__are_equal(const vda5050_msgs__msg__MaxStringLens__Sequence * lhs, const vda5050_msgs__msg__MaxStringLens__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vda5050_msgs__msg__MaxStringLens__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vda5050_msgs__msg__MaxStringLens__Sequence__copy(
  const vda5050_msgs__msg__MaxStringLens__Sequence * input,
  vda5050_msgs__msg__MaxStringLens__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vda5050_msgs__msg__MaxStringLens);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    vda5050_msgs__msg__MaxStringLens * data =
      (vda5050_msgs__msg__MaxStringLens *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vda5050_msgs__msg__MaxStringLens__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          vda5050_msgs__msg__MaxStringLens__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vda5050_msgs__msg__MaxStringLens__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
