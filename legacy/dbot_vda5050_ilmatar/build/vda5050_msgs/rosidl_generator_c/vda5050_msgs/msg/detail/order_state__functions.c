// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from vda5050_msgs:msg/OrderState.idl
// generated code does not contain a copyright notice
#include "vda5050_msgs/msg/detail/order_state__functions.h"

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
// Member `last_node_id`
// Member `operating_mode`
#include "rosidl_runtime_c/string_functions.h"
// Member `node_states`
#include "vda5050_msgs/msg/detail/node_state__functions.h"
// Member `edge_states`
#include "vda5050_msgs/msg/detail/edge_state__functions.h"
// Member `agv_position`
#include "vda5050_msgs/msg/detail/agv_position__functions.h"
// Member `velocity`
#include "vda5050_msgs/msg/detail/velocity__functions.h"
// Member `loads`
#include "vda5050_msgs/msg/detail/load__functions.h"
// Member `action_states`
#include "vda5050_msgs/msg/detail/current_action__functions.h"
// Member `battery_state`
#include "vda5050_msgs/msg/detail/battery_state__functions.h"
// Member `errors`
#include "vda5050_msgs/msg/detail/error__functions.h"
// Member `informations`
#include "vda5050_msgs/msg/detail/info__functions.h"
// Member `safety_state`
#include "vda5050_msgs/msg/detail/safety_state__functions.h"

bool
vda5050_msgs__msg__OrderState__init(vda5050_msgs__msg__OrderState * msg)
{
  if (!msg) {
    return false;
  }
  // header_id
  // timestamp
  if (!rosidl_runtime_c__String__init(&msg->timestamp)) {
    vda5050_msgs__msg__OrderState__fini(msg);
    return false;
  }
  // version
  if (!rosidl_runtime_c__String__init(&msg->version)) {
    vda5050_msgs__msg__OrderState__fini(msg);
    return false;
  }
  // manufacturer
  if (!rosidl_runtime_c__String__init(&msg->manufacturer)) {
    vda5050_msgs__msg__OrderState__fini(msg);
    return false;
  }
  // serial_number
  if (!rosidl_runtime_c__String__init(&msg->serial_number)) {
    vda5050_msgs__msg__OrderState__fini(msg);
    return false;
  }
  // order_id
  if (!rosidl_runtime_c__String__init(&msg->order_id)) {
    vda5050_msgs__msg__OrderState__fini(msg);
    return false;
  }
  // order_update_id
  // zone_set_id
  if (!rosidl_runtime_c__String__init(&msg->zone_set_id)) {
    vda5050_msgs__msg__OrderState__fini(msg);
    return false;
  }
  // last_node_id
  if (!rosidl_runtime_c__String__init(&msg->last_node_id)) {
    vda5050_msgs__msg__OrderState__fini(msg);
    return false;
  }
  // last_node_sequence_id
  // node_states
  if (!vda5050_msgs__msg__NodeState__Sequence__init(&msg->node_states, 0)) {
    vda5050_msgs__msg__OrderState__fini(msg);
    return false;
  }
  // edge_states
  if (!vda5050_msgs__msg__EdgeState__Sequence__init(&msg->edge_states, 0)) {
    vda5050_msgs__msg__OrderState__fini(msg);
    return false;
  }
  // agv_position
  if (!vda5050_msgs__msg__AGVPosition__init(&msg->agv_position)) {
    vda5050_msgs__msg__OrderState__fini(msg);
    return false;
  }
  // velocity
  if (!vda5050_msgs__msg__Velocity__init(&msg->velocity)) {
    vda5050_msgs__msg__OrderState__fini(msg);
    return false;
  }
  // loads
  if (!vda5050_msgs__msg__Load__Sequence__init(&msg->loads, 0)) {
    vda5050_msgs__msg__OrderState__fini(msg);
    return false;
  }
  // driving
  // paused
  // new_base_request
  // distance_since_last_node
  // action_states
  if (!vda5050_msgs__msg__CurrentAction__Sequence__init(&msg->action_states, 0)) {
    vda5050_msgs__msg__OrderState__fini(msg);
    return false;
  }
  // battery_state
  if (!vda5050_msgs__msg__BatteryState__init(&msg->battery_state)) {
    vda5050_msgs__msg__OrderState__fini(msg);
    return false;
  }
  // operating_mode
  if (!rosidl_runtime_c__String__init(&msg->operating_mode)) {
    vda5050_msgs__msg__OrderState__fini(msg);
    return false;
  }
  // errors
  if (!vda5050_msgs__msg__Error__Sequence__init(&msg->errors, 0)) {
    vda5050_msgs__msg__OrderState__fini(msg);
    return false;
  }
  // informations
  if (!vda5050_msgs__msg__Info__Sequence__init(&msg->informations, 0)) {
    vda5050_msgs__msg__OrderState__fini(msg);
    return false;
  }
  // safety_state
  if (!vda5050_msgs__msg__SafetyState__init(&msg->safety_state)) {
    vda5050_msgs__msg__OrderState__fini(msg);
    return false;
  }
  return true;
}

void
vda5050_msgs__msg__OrderState__fini(vda5050_msgs__msg__OrderState * msg)
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
  // last_node_id
  rosidl_runtime_c__String__fini(&msg->last_node_id);
  // last_node_sequence_id
  // node_states
  vda5050_msgs__msg__NodeState__Sequence__fini(&msg->node_states);
  // edge_states
  vda5050_msgs__msg__EdgeState__Sequence__fini(&msg->edge_states);
  // agv_position
  vda5050_msgs__msg__AGVPosition__fini(&msg->agv_position);
  // velocity
  vda5050_msgs__msg__Velocity__fini(&msg->velocity);
  // loads
  vda5050_msgs__msg__Load__Sequence__fini(&msg->loads);
  // driving
  // paused
  // new_base_request
  // distance_since_last_node
  // action_states
  vda5050_msgs__msg__CurrentAction__Sequence__fini(&msg->action_states);
  // battery_state
  vda5050_msgs__msg__BatteryState__fini(&msg->battery_state);
  // operating_mode
  rosidl_runtime_c__String__fini(&msg->operating_mode);
  // errors
  vda5050_msgs__msg__Error__Sequence__fini(&msg->errors);
  // informations
  vda5050_msgs__msg__Info__Sequence__fini(&msg->informations);
  // safety_state
  vda5050_msgs__msg__SafetyState__fini(&msg->safety_state);
}

bool
vda5050_msgs__msg__OrderState__are_equal(const vda5050_msgs__msg__OrderState * lhs, const vda5050_msgs__msg__OrderState * rhs)
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
  // last_node_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->last_node_id), &(rhs->last_node_id)))
  {
    return false;
  }
  // last_node_sequence_id
  if (lhs->last_node_sequence_id != rhs->last_node_sequence_id) {
    return false;
  }
  // node_states
  if (!vda5050_msgs__msg__NodeState__Sequence__are_equal(
      &(lhs->node_states), &(rhs->node_states)))
  {
    return false;
  }
  // edge_states
  if (!vda5050_msgs__msg__EdgeState__Sequence__are_equal(
      &(lhs->edge_states), &(rhs->edge_states)))
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
  // loads
  if (!vda5050_msgs__msg__Load__Sequence__are_equal(
      &(lhs->loads), &(rhs->loads)))
  {
    return false;
  }
  // driving
  if (lhs->driving != rhs->driving) {
    return false;
  }
  // paused
  if (lhs->paused != rhs->paused) {
    return false;
  }
  // new_base_request
  if (lhs->new_base_request != rhs->new_base_request) {
    return false;
  }
  // distance_since_last_node
  if (lhs->distance_since_last_node != rhs->distance_since_last_node) {
    return false;
  }
  // action_states
  if (!vda5050_msgs__msg__CurrentAction__Sequence__are_equal(
      &(lhs->action_states), &(rhs->action_states)))
  {
    return false;
  }
  // battery_state
  if (!vda5050_msgs__msg__BatteryState__are_equal(
      &(lhs->battery_state), &(rhs->battery_state)))
  {
    return false;
  }
  // operating_mode
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->operating_mode), &(rhs->operating_mode)))
  {
    return false;
  }
  // errors
  if (!vda5050_msgs__msg__Error__Sequence__are_equal(
      &(lhs->errors), &(rhs->errors)))
  {
    return false;
  }
  // informations
  if (!vda5050_msgs__msg__Info__Sequence__are_equal(
      &(lhs->informations), &(rhs->informations)))
  {
    return false;
  }
  // safety_state
  if (!vda5050_msgs__msg__SafetyState__are_equal(
      &(lhs->safety_state), &(rhs->safety_state)))
  {
    return false;
  }
  return true;
}

bool
vda5050_msgs__msg__OrderState__copy(
  const vda5050_msgs__msg__OrderState * input,
  vda5050_msgs__msg__OrderState * output)
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
  // last_node_id
  if (!rosidl_runtime_c__String__copy(
      &(input->last_node_id), &(output->last_node_id)))
  {
    return false;
  }
  // last_node_sequence_id
  output->last_node_sequence_id = input->last_node_sequence_id;
  // node_states
  if (!vda5050_msgs__msg__NodeState__Sequence__copy(
      &(input->node_states), &(output->node_states)))
  {
    return false;
  }
  // edge_states
  if (!vda5050_msgs__msg__EdgeState__Sequence__copy(
      &(input->edge_states), &(output->edge_states)))
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
  // loads
  if (!vda5050_msgs__msg__Load__Sequence__copy(
      &(input->loads), &(output->loads)))
  {
    return false;
  }
  // driving
  output->driving = input->driving;
  // paused
  output->paused = input->paused;
  // new_base_request
  output->new_base_request = input->new_base_request;
  // distance_since_last_node
  output->distance_since_last_node = input->distance_since_last_node;
  // action_states
  if (!vda5050_msgs__msg__CurrentAction__Sequence__copy(
      &(input->action_states), &(output->action_states)))
  {
    return false;
  }
  // battery_state
  if (!vda5050_msgs__msg__BatteryState__copy(
      &(input->battery_state), &(output->battery_state)))
  {
    return false;
  }
  // operating_mode
  if (!rosidl_runtime_c__String__copy(
      &(input->operating_mode), &(output->operating_mode)))
  {
    return false;
  }
  // errors
  if (!vda5050_msgs__msg__Error__Sequence__copy(
      &(input->errors), &(output->errors)))
  {
    return false;
  }
  // informations
  if (!vda5050_msgs__msg__Info__Sequence__copy(
      &(input->informations), &(output->informations)))
  {
    return false;
  }
  // safety_state
  if (!vda5050_msgs__msg__SafetyState__copy(
      &(input->safety_state), &(output->safety_state)))
  {
    return false;
  }
  return true;
}

vda5050_msgs__msg__OrderState *
vda5050_msgs__msg__OrderState__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__OrderState * msg = (vda5050_msgs__msg__OrderState *)allocator.allocate(sizeof(vda5050_msgs__msg__OrderState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vda5050_msgs__msg__OrderState));
  bool success = vda5050_msgs__msg__OrderState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vda5050_msgs__msg__OrderState__destroy(vda5050_msgs__msg__OrderState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vda5050_msgs__msg__OrderState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vda5050_msgs__msg__OrderState__Sequence__init(vda5050_msgs__msg__OrderState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__OrderState * data = NULL;

  if (size) {
    data = (vda5050_msgs__msg__OrderState *)allocator.zero_allocate(size, sizeof(vda5050_msgs__msg__OrderState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vda5050_msgs__msg__OrderState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vda5050_msgs__msg__OrderState__fini(&data[i - 1]);
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
vda5050_msgs__msg__OrderState__Sequence__fini(vda5050_msgs__msg__OrderState__Sequence * array)
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
      vda5050_msgs__msg__OrderState__fini(&array->data[i]);
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

vda5050_msgs__msg__OrderState__Sequence *
vda5050_msgs__msg__OrderState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__OrderState__Sequence * array = (vda5050_msgs__msg__OrderState__Sequence *)allocator.allocate(sizeof(vda5050_msgs__msg__OrderState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vda5050_msgs__msg__OrderState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vda5050_msgs__msg__OrderState__Sequence__destroy(vda5050_msgs__msg__OrderState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vda5050_msgs__msg__OrderState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vda5050_msgs__msg__OrderState__Sequence__are_equal(const vda5050_msgs__msg__OrderState__Sequence * lhs, const vda5050_msgs__msg__OrderState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vda5050_msgs__msg__OrderState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vda5050_msgs__msg__OrderState__Sequence__copy(
  const vda5050_msgs__msg__OrderState__Sequence * input,
  vda5050_msgs__msg__OrderState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vda5050_msgs__msg__OrderState);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    vda5050_msgs__msg__OrderState * data =
      (vda5050_msgs__msg__OrderState *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vda5050_msgs__msg__OrderState__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          vda5050_msgs__msg__OrderState__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vda5050_msgs__msg__OrderState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
