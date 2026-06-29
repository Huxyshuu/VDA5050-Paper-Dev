// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from vda5050_msgs:msg/ActionParameterDefinition.idl
// generated code does not contain a copyright notice
#include "vda5050_msgs/msg/detail/action_parameter_definition__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `key`
// Member `value_data_type`
// Member `description`
#include "rosidl_runtime_c/string_functions.h"

bool
vda5050_msgs__msg__ActionParameterDefinition__init(vda5050_msgs__msg__ActionParameterDefinition * msg)
{
  if (!msg) {
    return false;
  }
  // key
  if (!rosidl_runtime_c__String__init(&msg->key)) {
    vda5050_msgs__msg__ActionParameterDefinition__fini(msg);
    return false;
  }
  // value_data_type
  if (!rosidl_runtime_c__String__init(&msg->value_data_type)) {
    vda5050_msgs__msg__ActionParameterDefinition__fini(msg);
    return false;
  }
  // description
  if (!rosidl_runtime_c__String__init(&msg->description)) {
    vda5050_msgs__msg__ActionParameterDefinition__fini(msg);
    return false;
  }
  // is_optional
  return true;
}

void
vda5050_msgs__msg__ActionParameterDefinition__fini(vda5050_msgs__msg__ActionParameterDefinition * msg)
{
  if (!msg) {
    return;
  }
  // key
  rosidl_runtime_c__String__fini(&msg->key);
  // value_data_type
  rosidl_runtime_c__String__fini(&msg->value_data_type);
  // description
  rosidl_runtime_c__String__fini(&msg->description);
  // is_optional
}

bool
vda5050_msgs__msg__ActionParameterDefinition__are_equal(const vda5050_msgs__msg__ActionParameterDefinition * lhs, const vda5050_msgs__msg__ActionParameterDefinition * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // key
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->key), &(rhs->key)))
  {
    return false;
  }
  // value_data_type
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->value_data_type), &(rhs->value_data_type)))
  {
    return false;
  }
  // description
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->description), &(rhs->description)))
  {
    return false;
  }
  // is_optional
  if (lhs->is_optional != rhs->is_optional) {
    return false;
  }
  return true;
}

bool
vda5050_msgs__msg__ActionParameterDefinition__copy(
  const vda5050_msgs__msg__ActionParameterDefinition * input,
  vda5050_msgs__msg__ActionParameterDefinition * output)
{
  if (!input || !output) {
    return false;
  }
  // key
  if (!rosidl_runtime_c__String__copy(
      &(input->key), &(output->key)))
  {
    return false;
  }
  // value_data_type
  if (!rosidl_runtime_c__String__copy(
      &(input->value_data_type), &(output->value_data_type)))
  {
    return false;
  }
  // description
  if (!rosidl_runtime_c__String__copy(
      &(input->description), &(output->description)))
  {
    return false;
  }
  // is_optional
  output->is_optional = input->is_optional;
  return true;
}

vda5050_msgs__msg__ActionParameterDefinition *
vda5050_msgs__msg__ActionParameterDefinition__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__ActionParameterDefinition * msg = (vda5050_msgs__msg__ActionParameterDefinition *)allocator.allocate(sizeof(vda5050_msgs__msg__ActionParameterDefinition), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vda5050_msgs__msg__ActionParameterDefinition));
  bool success = vda5050_msgs__msg__ActionParameterDefinition__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vda5050_msgs__msg__ActionParameterDefinition__destroy(vda5050_msgs__msg__ActionParameterDefinition * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vda5050_msgs__msg__ActionParameterDefinition__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vda5050_msgs__msg__ActionParameterDefinition__Sequence__init(vda5050_msgs__msg__ActionParameterDefinition__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__ActionParameterDefinition * data = NULL;

  if (size) {
    data = (vda5050_msgs__msg__ActionParameterDefinition *)allocator.zero_allocate(size, sizeof(vda5050_msgs__msg__ActionParameterDefinition), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vda5050_msgs__msg__ActionParameterDefinition__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vda5050_msgs__msg__ActionParameterDefinition__fini(&data[i - 1]);
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
vda5050_msgs__msg__ActionParameterDefinition__Sequence__fini(vda5050_msgs__msg__ActionParameterDefinition__Sequence * array)
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
      vda5050_msgs__msg__ActionParameterDefinition__fini(&array->data[i]);
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

vda5050_msgs__msg__ActionParameterDefinition__Sequence *
vda5050_msgs__msg__ActionParameterDefinition__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__ActionParameterDefinition__Sequence * array = (vda5050_msgs__msg__ActionParameterDefinition__Sequence *)allocator.allocate(sizeof(vda5050_msgs__msg__ActionParameterDefinition__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vda5050_msgs__msg__ActionParameterDefinition__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vda5050_msgs__msg__ActionParameterDefinition__Sequence__destroy(vda5050_msgs__msg__ActionParameterDefinition__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vda5050_msgs__msg__ActionParameterDefinition__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vda5050_msgs__msg__ActionParameterDefinition__Sequence__are_equal(const vda5050_msgs__msg__ActionParameterDefinition__Sequence * lhs, const vda5050_msgs__msg__ActionParameterDefinition__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vda5050_msgs__msg__ActionParameterDefinition__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vda5050_msgs__msg__ActionParameterDefinition__Sequence__copy(
  const vda5050_msgs__msg__ActionParameterDefinition__Sequence * input,
  vda5050_msgs__msg__ActionParameterDefinition__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vda5050_msgs__msg__ActionParameterDefinition);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    vda5050_msgs__msg__ActionParameterDefinition * data =
      (vda5050_msgs__msg__ActionParameterDefinition *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vda5050_msgs__msg__ActionParameterDefinition__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          vda5050_msgs__msg__ActionParameterDefinition__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vda5050_msgs__msg__ActionParameterDefinition__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
