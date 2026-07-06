// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from vda5050_msgs:msg/LoadSet.idl
// generated code does not contain a copyright notice
#include "vda5050_msgs/msg/detail/load_set__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `set_name`
// Member `load_type`
// Member `load_positions`
// Member `description`
#include "rosidl_runtime_c/string_functions.h"
// Member `bounding_box_reference`
#include "vda5050_msgs/msg/detail/bounding_box_reference__functions.h"
// Member `load_dimensions`
#include "vda5050_msgs/msg/detail/load_dimensions__functions.h"

bool
vda5050_msgs__msg__LoadSet__init(vda5050_msgs__msg__LoadSet * msg)
{
  if (!msg) {
    return false;
  }
  // set_name
  if (!rosidl_runtime_c__String__init(&msg->set_name)) {
    vda5050_msgs__msg__LoadSet__fini(msg);
    return false;
  }
  // load_type
  if (!rosidl_runtime_c__String__init(&msg->load_type)) {
    vda5050_msgs__msg__LoadSet__fini(msg);
    return false;
  }
  // load_positions
  if (!rosidl_runtime_c__String__Sequence__init(&msg->load_positions, 0)) {
    vda5050_msgs__msg__LoadSet__fini(msg);
    return false;
  }
  // bounding_box_reference
  if (!vda5050_msgs__msg__BoundingBoxReference__init(&msg->bounding_box_reference)) {
    vda5050_msgs__msg__LoadSet__fini(msg);
    return false;
  }
  // load_dimensions
  if (!vda5050_msgs__msg__LoadDimensions__init(&msg->load_dimensions)) {
    vda5050_msgs__msg__LoadSet__fini(msg);
    return false;
  }
  // max_weight
  // min_loadhandling_height
  // max_loadhandling_height
  // min_loadhandling_depth
  // max_loadhandling_depth
  // min_loadhandling_tilt
  // max_loadhandling_tilt
  // agv_speed_limit
  // agv_acceleration_limit
  // agv_deceleration_limit
  // pick_time
  // drop_time
  // description
  if (!rosidl_runtime_c__String__init(&msg->description)) {
    vda5050_msgs__msg__LoadSet__fini(msg);
    return false;
  }
  return true;
}

void
vda5050_msgs__msg__LoadSet__fini(vda5050_msgs__msg__LoadSet * msg)
{
  if (!msg) {
    return;
  }
  // set_name
  rosidl_runtime_c__String__fini(&msg->set_name);
  // load_type
  rosidl_runtime_c__String__fini(&msg->load_type);
  // load_positions
  rosidl_runtime_c__String__Sequence__fini(&msg->load_positions);
  // bounding_box_reference
  vda5050_msgs__msg__BoundingBoxReference__fini(&msg->bounding_box_reference);
  // load_dimensions
  vda5050_msgs__msg__LoadDimensions__fini(&msg->load_dimensions);
  // max_weight
  // min_loadhandling_height
  // max_loadhandling_height
  // min_loadhandling_depth
  // max_loadhandling_depth
  // min_loadhandling_tilt
  // max_loadhandling_tilt
  // agv_speed_limit
  // agv_acceleration_limit
  // agv_deceleration_limit
  // pick_time
  // drop_time
  // description
  rosidl_runtime_c__String__fini(&msg->description);
}

bool
vda5050_msgs__msg__LoadSet__are_equal(const vda5050_msgs__msg__LoadSet * lhs, const vda5050_msgs__msg__LoadSet * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // set_name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->set_name), &(rhs->set_name)))
  {
    return false;
  }
  // load_type
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->load_type), &(rhs->load_type)))
  {
    return false;
  }
  // load_positions
  if (!rosidl_runtime_c__String__Sequence__are_equal(
      &(lhs->load_positions), &(rhs->load_positions)))
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
  // max_weight
  if (lhs->max_weight != rhs->max_weight) {
    return false;
  }
  // min_loadhandling_height
  if (lhs->min_loadhandling_height != rhs->min_loadhandling_height) {
    return false;
  }
  // max_loadhandling_height
  if (lhs->max_loadhandling_height != rhs->max_loadhandling_height) {
    return false;
  }
  // min_loadhandling_depth
  if (lhs->min_loadhandling_depth != rhs->min_loadhandling_depth) {
    return false;
  }
  // max_loadhandling_depth
  if (lhs->max_loadhandling_depth != rhs->max_loadhandling_depth) {
    return false;
  }
  // min_loadhandling_tilt
  if (lhs->min_loadhandling_tilt != rhs->min_loadhandling_tilt) {
    return false;
  }
  // max_loadhandling_tilt
  if (lhs->max_loadhandling_tilt != rhs->max_loadhandling_tilt) {
    return false;
  }
  // agv_speed_limit
  if (lhs->agv_speed_limit != rhs->agv_speed_limit) {
    return false;
  }
  // agv_acceleration_limit
  if (lhs->agv_acceleration_limit != rhs->agv_acceleration_limit) {
    return false;
  }
  // agv_deceleration_limit
  if (lhs->agv_deceleration_limit != rhs->agv_deceleration_limit) {
    return false;
  }
  // pick_time
  if (lhs->pick_time != rhs->pick_time) {
    return false;
  }
  // drop_time
  if (lhs->drop_time != rhs->drop_time) {
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
vda5050_msgs__msg__LoadSet__copy(
  const vda5050_msgs__msg__LoadSet * input,
  vda5050_msgs__msg__LoadSet * output)
{
  if (!input || !output) {
    return false;
  }
  // set_name
  if (!rosidl_runtime_c__String__copy(
      &(input->set_name), &(output->set_name)))
  {
    return false;
  }
  // load_type
  if (!rosidl_runtime_c__String__copy(
      &(input->load_type), &(output->load_type)))
  {
    return false;
  }
  // load_positions
  if (!rosidl_runtime_c__String__Sequence__copy(
      &(input->load_positions), &(output->load_positions)))
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
  // max_weight
  output->max_weight = input->max_weight;
  // min_loadhandling_height
  output->min_loadhandling_height = input->min_loadhandling_height;
  // max_loadhandling_height
  output->max_loadhandling_height = input->max_loadhandling_height;
  // min_loadhandling_depth
  output->min_loadhandling_depth = input->min_loadhandling_depth;
  // max_loadhandling_depth
  output->max_loadhandling_depth = input->max_loadhandling_depth;
  // min_loadhandling_tilt
  output->min_loadhandling_tilt = input->min_loadhandling_tilt;
  // max_loadhandling_tilt
  output->max_loadhandling_tilt = input->max_loadhandling_tilt;
  // agv_speed_limit
  output->agv_speed_limit = input->agv_speed_limit;
  // agv_acceleration_limit
  output->agv_acceleration_limit = input->agv_acceleration_limit;
  // agv_deceleration_limit
  output->agv_deceleration_limit = input->agv_deceleration_limit;
  // pick_time
  output->pick_time = input->pick_time;
  // drop_time
  output->drop_time = input->drop_time;
  // description
  if (!rosidl_runtime_c__String__copy(
      &(input->description), &(output->description)))
  {
    return false;
  }
  return true;
}

vda5050_msgs__msg__LoadSet *
vda5050_msgs__msg__LoadSet__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__LoadSet * msg = (vda5050_msgs__msg__LoadSet *)allocator.allocate(sizeof(vda5050_msgs__msg__LoadSet), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vda5050_msgs__msg__LoadSet));
  bool success = vda5050_msgs__msg__LoadSet__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vda5050_msgs__msg__LoadSet__destroy(vda5050_msgs__msg__LoadSet * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vda5050_msgs__msg__LoadSet__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vda5050_msgs__msg__LoadSet__Sequence__init(vda5050_msgs__msg__LoadSet__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__LoadSet * data = NULL;

  if (size) {
    data = (vda5050_msgs__msg__LoadSet *)allocator.zero_allocate(size, sizeof(vda5050_msgs__msg__LoadSet), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vda5050_msgs__msg__LoadSet__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vda5050_msgs__msg__LoadSet__fini(&data[i - 1]);
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
vda5050_msgs__msg__LoadSet__Sequence__fini(vda5050_msgs__msg__LoadSet__Sequence * array)
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
      vda5050_msgs__msg__LoadSet__fini(&array->data[i]);
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

vda5050_msgs__msg__LoadSet__Sequence *
vda5050_msgs__msg__LoadSet__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__LoadSet__Sequence * array = (vda5050_msgs__msg__LoadSet__Sequence *)allocator.allocate(sizeof(vda5050_msgs__msg__LoadSet__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vda5050_msgs__msg__LoadSet__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vda5050_msgs__msg__LoadSet__Sequence__destroy(vda5050_msgs__msg__LoadSet__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vda5050_msgs__msg__LoadSet__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vda5050_msgs__msg__LoadSet__Sequence__are_equal(const vda5050_msgs__msg__LoadSet__Sequence * lhs, const vda5050_msgs__msg__LoadSet__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vda5050_msgs__msg__LoadSet__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vda5050_msgs__msg__LoadSet__Sequence__copy(
  const vda5050_msgs__msg__LoadSet__Sequence * input,
  vda5050_msgs__msg__LoadSet__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vda5050_msgs__msg__LoadSet);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    vda5050_msgs__msg__LoadSet * data =
      (vda5050_msgs__msg__LoadSet *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vda5050_msgs__msg__LoadSet__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          vda5050_msgs__msg__LoadSet__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vda5050_msgs__msg__LoadSet__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
