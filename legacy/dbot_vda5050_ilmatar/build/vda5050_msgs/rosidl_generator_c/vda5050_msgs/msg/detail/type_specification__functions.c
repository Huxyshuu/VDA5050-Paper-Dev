// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from vda5050_msgs:msg/TypeSpecification.idl
// generated code does not contain a copyright notice
#include "vda5050_msgs/msg/detail/type_specification__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `series_name`
// Member `series_description`
// Member `agv_kinematic`
// Member `agv_class`
// Member `localization_types`
// Member `navigation_types`
#include "rosidl_runtime_c/string_functions.h"

bool
vda5050_msgs__msg__TypeSpecification__init(vda5050_msgs__msg__TypeSpecification * msg)
{
  if (!msg) {
    return false;
  }
  // series_name
  if (!rosidl_runtime_c__String__init(&msg->series_name)) {
    vda5050_msgs__msg__TypeSpecification__fini(msg);
    return false;
  }
  // series_description
  if (!rosidl_runtime_c__String__init(&msg->series_description)) {
    vda5050_msgs__msg__TypeSpecification__fini(msg);
    return false;
  }
  // agv_kinematic
  if (!rosidl_runtime_c__String__init(&msg->agv_kinematic)) {
    vda5050_msgs__msg__TypeSpecification__fini(msg);
    return false;
  }
  // agv_class
  if (!rosidl_runtime_c__String__init(&msg->agv_class)) {
    vda5050_msgs__msg__TypeSpecification__fini(msg);
    return false;
  }
  // max_load_mass
  // localization_types
  if (!rosidl_runtime_c__String__Sequence__init(&msg->localization_types, 0)) {
    vda5050_msgs__msg__TypeSpecification__fini(msg);
    return false;
  }
  // navigation_types
  if (!rosidl_runtime_c__String__Sequence__init(&msg->navigation_types, 0)) {
    vda5050_msgs__msg__TypeSpecification__fini(msg);
    return false;
  }
  return true;
}

void
vda5050_msgs__msg__TypeSpecification__fini(vda5050_msgs__msg__TypeSpecification * msg)
{
  if (!msg) {
    return;
  }
  // series_name
  rosidl_runtime_c__String__fini(&msg->series_name);
  // series_description
  rosidl_runtime_c__String__fini(&msg->series_description);
  // agv_kinematic
  rosidl_runtime_c__String__fini(&msg->agv_kinematic);
  // agv_class
  rosidl_runtime_c__String__fini(&msg->agv_class);
  // max_load_mass
  // localization_types
  rosidl_runtime_c__String__Sequence__fini(&msg->localization_types);
  // navigation_types
  rosidl_runtime_c__String__Sequence__fini(&msg->navigation_types);
}

bool
vda5050_msgs__msg__TypeSpecification__are_equal(const vda5050_msgs__msg__TypeSpecification * lhs, const vda5050_msgs__msg__TypeSpecification * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // series_name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->series_name), &(rhs->series_name)))
  {
    return false;
  }
  // series_description
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->series_description), &(rhs->series_description)))
  {
    return false;
  }
  // agv_kinematic
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->agv_kinematic), &(rhs->agv_kinematic)))
  {
    return false;
  }
  // agv_class
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->agv_class), &(rhs->agv_class)))
  {
    return false;
  }
  // max_load_mass
  if (lhs->max_load_mass != rhs->max_load_mass) {
    return false;
  }
  // localization_types
  if (!rosidl_runtime_c__String__Sequence__are_equal(
      &(lhs->localization_types), &(rhs->localization_types)))
  {
    return false;
  }
  // navigation_types
  if (!rosidl_runtime_c__String__Sequence__are_equal(
      &(lhs->navigation_types), &(rhs->navigation_types)))
  {
    return false;
  }
  return true;
}

bool
vda5050_msgs__msg__TypeSpecification__copy(
  const vda5050_msgs__msg__TypeSpecification * input,
  vda5050_msgs__msg__TypeSpecification * output)
{
  if (!input || !output) {
    return false;
  }
  // series_name
  if (!rosidl_runtime_c__String__copy(
      &(input->series_name), &(output->series_name)))
  {
    return false;
  }
  // series_description
  if (!rosidl_runtime_c__String__copy(
      &(input->series_description), &(output->series_description)))
  {
    return false;
  }
  // agv_kinematic
  if (!rosidl_runtime_c__String__copy(
      &(input->agv_kinematic), &(output->agv_kinematic)))
  {
    return false;
  }
  // agv_class
  if (!rosidl_runtime_c__String__copy(
      &(input->agv_class), &(output->agv_class)))
  {
    return false;
  }
  // max_load_mass
  output->max_load_mass = input->max_load_mass;
  // localization_types
  if (!rosidl_runtime_c__String__Sequence__copy(
      &(input->localization_types), &(output->localization_types)))
  {
    return false;
  }
  // navigation_types
  if (!rosidl_runtime_c__String__Sequence__copy(
      &(input->navigation_types), &(output->navigation_types)))
  {
    return false;
  }
  return true;
}

vda5050_msgs__msg__TypeSpecification *
vda5050_msgs__msg__TypeSpecification__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__TypeSpecification * msg = (vda5050_msgs__msg__TypeSpecification *)allocator.allocate(sizeof(vda5050_msgs__msg__TypeSpecification), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vda5050_msgs__msg__TypeSpecification));
  bool success = vda5050_msgs__msg__TypeSpecification__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vda5050_msgs__msg__TypeSpecification__destroy(vda5050_msgs__msg__TypeSpecification * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vda5050_msgs__msg__TypeSpecification__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vda5050_msgs__msg__TypeSpecification__Sequence__init(vda5050_msgs__msg__TypeSpecification__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__TypeSpecification * data = NULL;

  if (size) {
    data = (vda5050_msgs__msg__TypeSpecification *)allocator.zero_allocate(size, sizeof(vda5050_msgs__msg__TypeSpecification), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vda5050_msgs__msg__TypeSpecification__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vda5050_msgs__msg__TypeSpecification__fini(&data[i - 1]);
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
vda5050_msgs__msg__TypeSpecification__Sequence__fini(vda5050_msgs__msg__TypeSpecification__Sequence * array)
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
      vda5050_msgs__msg__TypeSpecification__fini(&array->data[i]);
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

vda5050_msgs__msg__TypeSpecification__Sequence *
vda5050_msgs__msg__TypeSpecification__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__TypeSpecification__Sequence * array = (vda5050_msgs__msg__TypeSpecification__Sequence *)allocator.allocate(sizeof(vda5050_msgs__msg__TypeSpecification__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vda5050_msgs__msg__TypeSpecification__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vda5050_msgs__msg__TypeSpecification__Sequence__destroy(vda5050_msgs__msg__TypeSpecification__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vda5050_msgs__msg__TypeSpecification__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vda5050_msgs__msg__TypeSpecification__Sequence__are_equal(const vda5050_msgs__msg__TypeSpecification__Sequence * lhs, const vda5050_msgs__msg__TypeSpecification__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vda5050_msgs__msg__TypeSpecification__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vda5050_msgs__msg__TypeSpecification__Sequence__copy(
  const vda5050_msgs__msg__TypeSpecification__Sequence * input,
  vda5050_msgs__msg__TypeSpecification__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vda5050_msgs__msg__TypeSpecification);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    vda5050_msgs__msg__TypeSpecification * data =
      (vda5050_msgs__msg__TypeSpecification *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vda5050_msgs__msg__TypeSpecification__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          vda5050_msgs__msg__TypeSpecification__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vda5050_msgs__msg__TypeSpecification__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
