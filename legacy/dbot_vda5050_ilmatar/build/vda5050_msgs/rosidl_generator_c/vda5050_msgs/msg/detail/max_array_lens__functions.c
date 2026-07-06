// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from vda5050_msgs:msg/MaxArrayLens.idl
// generated code does not contain a copyright notice
#include "vda5050_msgs/msg/detail/max_array_lens__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
vda5050_msgs__msg__MaxArrayLens__init(vda5050_msgs__msg__MaxArrayLens * msg)
{
  if (!msg) {
    return false;
  }
  // order_nodes
  // order_edges
  // node_actions
  // edge_actions
  // actions_parameters
  // instant_actions
  // trajectory_knot_vector
  // trajectory_control_points
  // state_node_states
  // state_edge_states
  // state_loads
  // state_action_states
  // state_errors
  // state_information
  // error_references
  // info_references
  return true;
}

void
vda5050_msgs__msg__MaxArrayLens__fini(vda5050_msgs__msg__MaxArrayLens * msg)
{
  if (!msg) {
    return;
  }
  // order_nodes
  // order_edges
  // node_actions
  // edge_actions
  // actions_parameters
  // instant_actions
  // trajectory_knot_vector
  // trajectory_control_points
  // state_node_states
  // state_edge_states
  // state_loads
  // state_action_states
  // state_errors
  // state_information
  // error_references
  // info_references
}

bool
vda5050_msgs__msg__MaxArrayLens__are_equal(const vda5050_msgs__msg__MaxArrayLens * lhs, const vda5050_msgs__msg__MaxArrayLens * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // order_nodes
  if (lhs->order_nodes != rhs->order_nodes) {
    return false;
  }
  // order_edges
  if (lhs->order_edges != rhs->order_edges) {
    return false;
  }
  // node_actions
  if (lhs->node_actions != rhs->node_actions) {
    return false;
  }
  // edge_actions
  if (lhs->edge_actions != rhs->edge_actions) {
    return false;
  }
  // actions_parameters
  if (lhs->actions_parameters != rhs->actions_parameters) {
    return false;
  }
  // instant_actions
  if (lhs->instant_actions != rhs->instant_actions) {
    return false;
  }
  // trajectory_knot_vector
  if (lhs->trajectory_knot_vector != rhs->trajectory_knot_vector) {
    return false;
  }
  // trajectory_control_points
  if (lhs->trajectory_control_points != rhs->trajectory_control_points) {
    return false;
  }
  // state_node_states
  if (lhs->state_node_states != rhs->state_node_states) {
    return false;
  }
  // state_edge_states
  if (lhs->state_edge_states != rhs->state_edge_states) {
    return false;
  }
  // state_loads
  if (lhs->state_loads != rhs->state_loads) {
    return false;
  }
  // state_action_states
  if (lhs->state_action_states != rhs->state_action_states) {
    return false;
  }
  // state_errors
  if (lhs->state_errors != rhs->state_errors) {
    return false;
  }
  // state_information
  if (lhs->state_information != rhs->state_information) {
    return false;
  }
  // error_references
  if (lhs->error_references != rhs->error_references) {
    return false;
  }
  // info_references
  if (lhs->info_references != rhs->info_references) {
    return false;
  }
  return true;
}

bool
vda5050_msgs__msg__MaxArrayLens__copy(
  const vda5050_msgs__msg__MaxArrayLens * input,
  vda5050_msgs__msg__MaxArrayLens * output)
{
  if (!input || !output) {
    return false;
  }
  // order_nodes
  output->order_nodes = input->order_nodes;
  // order_edges
  output->order_edges = input->order_edges;
  // node_actions
  output->node_actions = input->node_actions;
  // edge_actions
  output->edge_actions = input->edge_actions;
  // actions_parameters
  output->actions_parameters = input->actions_parameters;
  // instant_actions
  output->instant_actions = input->instant_actions;
  // trajectory_knot_vector
  output->trajectory_knot_vector = input->trajectory_knot_vector;
  // trajectory_control_points
  output->trajectory_control_points = input->trajectory_control_points;
  // state_node_states
  output->state_node_states = input->state_node_states;
  // state_edge_states
  output->state_edge_states = input->state_edge_states;
  // state_loads
  output->state_loads = input->state_loads;
  // state_action_states
  output->state_action_states = input->state_action_states;
  // state_errors
  output->state_errors = input->state_errors;
  // state_information
  output->state_information = input->state_information;
  // error_references
  output->error_references = input->error_references;
  // info_references
  output->info_references = input->info_references;
  return true;
}

vda5050_msgs__msg__MaxArrayLens *
vda5050_msgs__msg__MaxArrayLens__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__MaxArrayLens * msg = (vda5050_msgs__msg__MaxArrayLens *)allocator.allocate(sizeof(vda5050_msgs__msg__MaxArrayLens), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vda5050_msgs__msg__MaxArrayLens));
  bool success = vda5050_msgs__msg__MaxArrayLens__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vda5050_msgs__msg__MaxArrayLens__destroy(vda5050_msgs__msg__MaxArrayLens * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vda5050_msgs__msg__MaxArrayLens__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vda5050_msgs__msg__MaxArrayLens__Sequence__init(vda5050_msgs__msg__MaxArrayLens__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__MaxArrayLens * data = NULL;

  if (size) {
    data = (vda5050_msgs__msg__MaxArrayLens *)allocator.zero_allocate(size, sizeof(vda5050_msgs__msg__MaxArrayLens), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vda5050_msgs__msg__MaxArrayLens__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vda5050_msgs__msg__MaxArrayLens__fini(&data[i - 1]);
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
vda5050_msgs__msg__MaxArrayLens__Sequence__fini(vda5050_msgs__msg__MaxArrayLens__Sequence * array)
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
      vda5050_msgs__msg__MaxArrayLens__fini(&array->data[i]);
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

vda5050_msgs__msg__MaxArrayLens__Sequence *
vda5050_msgs__msg__MaxArrayLens__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__MaxArrayLens__Sequence * array = (vda5050_msgs__msg__MaxArrayLens__Sequence *)allocator.allocate(sizeof(vda5050_msgs__msg__MaxArrayLens__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vda5050_msgs__msg__MaxArrayLens__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vda5050_msgs__msg__MaxArrayLens__Sequence__destroy(vda5050_msgs__msg__MaxArrayLens__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vda5050_msgs__msg__MaxArrayLens__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vda5050_msgs__msg__MaxArrayLens__Sequence__are_equal(const vda5050_msgs__msg__MaxArrayLens__Sequence * lhs, const vda5050_msgs__msg__MaxArrayLens__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vda5050_msgs__msg__MaxArrayLens__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vda5050_msgs__msg__MaxArrayLens__Sequence__copy(
  const vda5050_msgs__msg__MaxArrayLens__Sequence * input,
  vda5050_msgs__msg__MaxArrayLens__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vda5050_msgs__msg__MaxArrayLens);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    vda5050_msgs__msg__MaxArrayLens * data =
      (vda5050_msgs__msg__MaxArrayLens *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vda5050_msgs__msg__MaxArrayLens__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          vda5050_msgs__msg__MaxArrayLens__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vda5050_msgs__msg__MaxArrayLens__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
