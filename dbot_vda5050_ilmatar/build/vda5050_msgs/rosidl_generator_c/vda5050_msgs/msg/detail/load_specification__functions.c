// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from vda5050_msgs:msg/LoadSpecification.idl
// generated code does not contain a copyright notice
#include "vda5050_msgs/msg/detail/load_specification__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `load_positions`
#include "rosidl_runtime_c/string_functions.h"
// Member `load_sets`
#include "vda5050_msgs/msg/detail/load_set__functions.h"

bool
vda5050_msgs__msg__LoadSpecification__init(vda5050_msgs__msg__LoadSpecification * msg)
{
  if (!msg) {
    return false;
  }
  // load_positions
  if (!rosidl_runtime_c__String__Sequence__init(&msg->load_positions, 0)) {
    vda5050_msgs__msg__LoadSpecification__fini(msg);
    return false;
  }
  // load_sets
  if (!vda5050_msgs__msg__LoadSet__Sequence__init(&msg->load_sets, 0)) {
    vda5050_msgs__msg__LoadSpecification__fini(msg);
    return false;
  }
  return true;
}

void
vda5050_msgs__msg__LoadSpecification__fini(vda5050_msgs__msg__LoadSpecification * msg)
{
  if (!msg) {
    return;
  }
  // load_positions
  rosidl_runtime_c__String__Sequence__fini(&msg->load_positions);
  // load_sets
  vda5050_msgs__msg__LoadSet__Sequence__fini(&msg->load_sets);
}

bool
vda5050_msgs__msg__LoadSpecification__are_equal(const vda5050_msgs__msg__LoadSpecification * lhs, const vda5050_msgs__msg__LoadSpecification * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // load_positions
  if (!rosidl_runtime_c__String__Sequence__are_equal(
      &(lhs->load_positions), &(rhs->load_positions)))
  {
    return false;
  }
  // load_sets
  if (!vda5050_msgs__msg__LoadSet__Sequence__are_equal(
      &(lhs->load_sets), &(rhs->load_sets)))
  {
    return false;
  }
  return true;
}

bool
vda5050_msgs__msg__LoadSpecification__copy(
  const vda5050_msgs__msg__LoadSpecification * input,
  vda5050_msgs__msg__LoadSpecification * output)
{
  if (!input || !output) {
    return false;
  }
  // load_positions
  if (!rosidl_runtime_c__String__Sequence__copy(
      &(input->load_positions), &(output->load_positions)))
  {
    return false;
  }
  // load_sets
  if (!vda5050_msgs__msg__LoadSet__Sequence__copy(
      &(input->load_sets), &(output->load_sets)))
  {
    return false;
  }
  return true;
}

vda5050_msgs__msg__LoadSpecification *
vda5050_msgs__msg__LoadSpecification__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__LoadSpecification * msg = (vda5050_msgs__msg__LoadSpecification *)allocator.allocate(sizeof(vda5050_msgs__msg__LoadSpecification), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vda5050_msgs__msg__LoadSpecification));
  bool success = vda5050_msgs__msg__LoadSpecification__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vda5050_msgs__msg__LoadSpecification__destroy(vda5050_msgs__msg__LoadSpecification * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vda5050_msgs__msg__LoadSpecification__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vda5050_msgs__msg__LoadSpecification__Sequence__init(vda5050_msgs__msg__LoadSpecification__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__LoadSpecification * data = NULL;

  if (size) {
    data = (vda5050_msgs__msg__LoadSpecification *)allocator.zero_allocate(size, sizeof(vda5050_msgs__msg__LoadSpecification), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vda5050_msgs__msg__LoadSpecification__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vda5050_msgs__msg__LoadSpecification__fini(&data[i - 1]);
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
vda5050_msgs__msg__LoadSpecification__Sequence__fini(vda5050_msgs__msg__LoadSpecification__Sequence * array)
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
      vda5050_msgs__msg__LoadSpecification__fini(&array->data[i]);
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

vda5050_msgs__msg__LoadSpecification__Sequence *
vda5050_msgs__msg__LoadSpecification__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__LoadSpecification__Sequence * array = (vda5050_msgs__msg__LoadSpecification__Sequence *)allocator.allocate(sizeof(vda5050_msgs__msg__LoadSpecification__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vda5050_msgs__msg__LoadSpecification__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vda5050_msgs__msg__LoadSpecification__Sequence__destroy(vda5050_msgs__msg__LoadSpecification__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vda5050_msgs__msg__LoadSpecification__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vda5050_msgs__msg__LoadSpecification__Sequence__are_equal(const vda5050_msgs__msg__LoadSpecification__Sequence * lhs, const vda5050_msgs__msg__LoadSpecification__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vda5050_msgs__msg__LoadSpecification__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vda5050_msgs__msg__LoadSpecification__Sequence__copy(
  const vda5050_msgs__msg__LoadSpecification__Sequence * input,
  vda5050_msgs__msg__LoadSpecification__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vda5050_msgs__msg__LoadSpecification);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    vda5050_msgs__msg__LoadSpecification * data =
      (vda5050_msgs__msg__LoadSpecification *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vda5050_msgs__msg__LoadSpecification__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          vda5050_msgs__msg__LoadSpecification__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vda5050_msgs__msg__LoadSpecification__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
