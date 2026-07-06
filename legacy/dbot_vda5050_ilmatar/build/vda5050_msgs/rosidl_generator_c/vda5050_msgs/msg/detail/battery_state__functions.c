// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from vda5050_msgs:msg/BatteryState.idl
// generated code does not contain a copyright notice
#include "vda5050_msgs/msg/detail/battery_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
vda5050_msgs__msg__BatteryState__init(vda5050_msgs__msg__BatteryState * msg)
{
  if (!msg) {
    return false;
  }
  // battery_charge
  // battery_voltage
  // battery_health
  // charging
  // reach
  return true;
}

void
vda5050_msgs__msg__BatteryState__fini(vda5050_msgs__msg__BatteryState * msg)
{
  if (!msg) {
    return;
  }
  // battery_charge
  // battery_voltage
  // battery_health
  // charging
  // reach
}

bool
vda5050_msgs__msg__BatteryState__are_equal(const vda5050_msgs__msg__BatteryState * lhs, const vda5050_msgs__msg__BatteryState * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // battery_charge
  if (lhs->battery_charge != rhs->battery_charge) {
    return false;
  }
  // battery_voltage
  if (lhs->battery_voltage != rhs->battery_voltage) {
    return false;
  }
  // battery_health
  if (lhs->battery_health != rhs->battery_health) {
    return false;
  }
  // charging
  if (lhs->charging != rhs->charging) {
    return false;
  }
  // reach
  if (lhs->reach != rhs->reach) {
    return false;
  }
  return true;
}

bool
vda5050_msgs__msg__BatteryState__copy(
  const vda5050_msgs__msg__BatteryState * input,
  vda5050_msgs__msg__BatteryState * output)
{
  if (!input || !output) {
    return false;
  }
  // battery_charge
  output->battery_charge = input->battery_charge;
  // battery_voltage
  output->battery_voltage = input->battery_voltage;
  // battery_health
  output->battery_health = input->battery_health;
  // charging
  output->charging = input->charging;
  // reach
  output->reach = input->reach;
  return true;
}

vda5050_msgs__msg__BatteryState *
vda5050_msgs__msg__BatteryState__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__BatteryState * msg = (vda5050_msgs__msg__BatteryState *)allocator.allocate(sizeof(vda5050_msgs__msg__BatteryState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vda5050_msgs__msg__BatteryState));
  bool success = vda5050_msgs__msg__BatteryState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vda5050_msgs__msg__BatteryState__destroy(vda5050_msgs__msg__BatteryState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vda5050_msgs__msg__BatteryState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vda5050_msgs__msg__BatteryState__Sequence__init(vda5050_msgs__msg__BatteryState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__BatteryState * data = NULL;

  if (size) {
    data = (vda5050_msgs__msg__BatteryState *)allocator.zero_allocate(size, sizeof(vda5050_msgs__msg__BatteryState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vda5050_msgs__msg__BatteryState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vda5050_msgs__msg__BatteryState__fini(&data[i - 1]);
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
vda5050_msgs__msg__BatteryState__Sequence__fini(vda5050_msgs__msg__BatteryState__Sequence * array)
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
      vda5050_msgs__msg__BatteryState__fini(&array->data[i]);
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

vda5050_msgs__msg__BatteryState__Sequence *
vda5050_msgs__msg__BatteryState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__BatteryState__Sequence * array = (vda5050_msgs__msg__BatteryState__Sequence *)allocator.allocate(sizeof(vda5050_msgs__msg__BatteryState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vda5050_msgs__msg__BatteryState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vda5050_msgs__msg__BatteryState__Sequence__destroy(vda5050_msgs__msg__BatteryState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vda5050_msgs__msg__BatteryState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vda5050_msgs__msg__BatteryState__Sequence__are_equal(const vda5050_msgs__msg__BatteryState__Sequence * lhs, const vda5050_msgs__msg__BatteryState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vda5050_msgs__msg__BatteryState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vda5050_msgs__msg__BatteryState__Sequence__copy(
  const vda5050_msgs__msg__BatteryState__Sequence * input,
  vda5050_msgs__msg__BatteryState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vda5050_msgs__msg__BatteryState);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    vda5050_msgs__msg__BatteryState * data =
      (vda5050_msgs__msg__BatteryState *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vda5050_msgs__msg__BatteryState__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          vda5050_msgs__msg__BatteryState__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vda5050_msgs__msg__BatteryState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
