// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from vda5050_msgs:msg/Factsheet.idl
// generated code does not contain a copyright notice
#include "vda5050_msgs/msg/detail/factsheet__functions.h"

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
#include "rosidl_runtime_c/string_functions.h"
// Member `type_specification`
#include "vda5050_msgs/msg/detail/type_specification__functions.h"
// Member `physical_parameters`
#include "vda5050_msgs/msg/detail/physical_parameters__functions.h"
// Member `protocol_limits`
#include "vda5050_msgs/msg/detail/protocol_limits__functions.h"
// Member `protocol_features`
#include "vda5050_msgs/msg/detail/protocol_features__functions.h"
// Member `agv_geometry`
#include "vda5050_msgs/msg/detail/agv_geometry__functions.h"
// Member `load_specification`
#include "vda5050_msgs/msg/detail/load_specification__functions.h"

bool
vda5050_msgs__msg__Factsheet__init(vda5050_msgs__msg__Factsheet * msg)
{
  if (!msg) {
    return false;
  }
  // header_id
  // timestamp
  if (!rosidl_runtime_c__String__init(&msg->timestamp)) {
    vda5050_msgs__msg__Factsheet__fini(msg);
    return false;
  }
  // version
  if (!rosidl_runtime_c__String__init(&msg->version)) {
    vda5050_msgs__msg__Factsheet__fini(msg);
    return false;
  }
  // manufacturer
  if (!rosidl_runtime_c__String__init(&msg->manufacturer)) {
    vda5050_msgs__msg__Factsheet__fini(msg);
    return false;
  }
  // serial_number
  if (!rosidl_runtime_c__String__init(&msg->serial_number)) {
    vda5050_msgs__msg__Factsheet__fini(msg);
    return false;
  }
  // type_specification
  if (!vda5050_msgs__msg__TypeSpecification__init(&msg->type_specification)) {
    vda5050_msgs__msg__Factsheet__fini(msg);
    return false;
  }
  // physical_parameters
  if (!vda5050_msgs__msg__PhysicalParameters__init(&msg->physical_parameters)) {
    vda5050_msgs__msg__Factsheet__fini(msg);
    return false;
  }
  // protocol_limits
  if (!vda5050_msgs__msg__ProtocolLimits__init(&msg->protocol_limits)) {
    vda5050_msgs__msg__Factsheet__fini(msg);
    return false;
  }
  // protocol_features
  if (!vda5050_msgs__msg__ProtocolFeatures__init(&msg->protocol_features)) {
    vda5050_msgs__msg__Factsheet__fini(msg);
    return false;
  }
  // agv_geometry
  if (!vda5050_msgs__msg__AGVGeometry__init(&msg->agv_geometry)) {
    vda5050_msgs__msg__Factsheet__fini(msg);
    return false;
  }
  // load_specification
  if (!vda5050_msgs__msg__LoadSpecification__init(&msg->load_specification)) {
    vda5050_msgs__msg__Factsheet__fini(msg);
    return false;
  }
  // localization_parameters
  return true;
}

void
vda5050_msgs__msg__Factsheet__fini(vda5050_msgs__msg__Factsheet * msg)
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
  // type_specification
  vda5050_msgs__msg__TypeSpecification__fini(&msg->type_specification);
  // physical_parameters
  vda5050_msgs__msg__PhysicalParameters__fini(&msg->physical_parameters);
  // protocol_limits
  vda5050_msgs__msg__ProtocolLimits__fini(&msg->protocol_limits);
  // protocol_features
  vda5050_msgs__msg__ProtocolFeatures__fini(&msg->protocol_features);
  // agv_geometry
  vda5050_msgs__msg__AGVGeometry__fini(&msg->agv_geometry);
  // load_specification
  vda5050_msgs__msg__LoadSpecification__fini(&msg->load_specification);
  // localization_parameters
}

bool
vda5050_msgs__msg__Factsheet__are_equal(const vda5050_msgs__msg__Factsheet * lhs, const vda5050_msgs__msg__Factsheet * rhs)
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
  // type_specification
  if (!vda5050_msgs__msg__TypeSpecification__are_equal(
      &(lhs->type_specification), &(rhs->type_specification)))
  {
    return false;
  }
  // physical_parameters
  if (!vda5050_msgs__msg__PhysicalParameters__are_equal(
      &(lhs->physical_parameters), &(rhs->physical_parameters)))
  {
    return false;
  }
  // protocol_limits
  if (!vda5050_msgs__msg__ProtocolLimits__are_equal(
      &(lhs->protocol_limits), &(rhs->protocol_limits)))
  {
    return false;
  }
  // protocol_features
  if (!vda5050_msgs__msg__ProtocolFeatures__are_equal(
      &(lhs->protocol_features), &(rhs->protocol_features)))
  {
    return false;
  }
  // agv_geometry
  if (!vda5050_msgs__msg__AGVGeometry__are_equal(
      &(lhs->agv_geometry), &(rhs->agv_geometry)))
  {
    return false;
  }
  // load_specification
  if (!vda5050_msgs__msg__LoadSpecification__are_equal(
      &(lhs->load_specification), &(rhs->load_specification)))
  {
    return false;
  }
  // localization_parameters
  if (lhs->localization_parameters != rhs->localization_parameters) {
    return false;
  }
  return true;
}

bool
vda5050_msgs__msg__Factsheet__copy(
  const vda5050_msgs__msg__Factsheet * input,
  vda5050_msgs__msg__Factsheet * output)
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
  // type_specification
  if (!vda5050_msgs__msg__TypeSpecification__copy(
      &(input->type_specification), &(output->type_specification)))
  {
    return false;
  }
  // physical_parameters
  if (!vda5050_msgs__msg__PhysicalParameters__copy(
      &(input->physical_parameters), &(output->physical_parameters)))
  {
    return false;
  }
  // protocol_limits
  if (!vda5050_msgs__msg__ProtocolLimits__copy(
      &(input->protocol_limits), &(output->protocol_limits)))
  {
    return false;
  }
  // protocol_features
  if (!vda5050_msgs__msg__ProtocolFeatures__copy(
      &(input->protocol_features), &(output->protocol_features)))
  {
    return false;
  }
  // agv_geometry
  if (!vda5050_msgs__msg__AGVGeometry__copy(
      &(input->agv_geometry), &(output->agv_geometry)))
  {
    return false;
  }
  // load_specification
  if (!vda5050_msgs__msg__LoadSpecification__copy(
      &(input->load_specification), &(output->load_specification)))
  {
    return false;
  }
  // localization_parameters
  output->localization_parameters = input->localization_parameters;
  return true;
}

vda5050_msgs__msg__Factsheet *
vda5050_msgs__msg__Factsheet__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__Factsheet * msg = (vda5050_msgs__msg__Factsheet *)allocator.allocate(sizeof(vda5050_msgs__msg__Factsheet), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vda5050_msgs__msg__Factsheet));
  bool success = vda5050_msgs__msg__Factsheet__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vda5050_msgs__msg__Factsheet__destroy(vda5050_msgs__msg__Factsheet * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vda5050_msgs__msg__Factsheet__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vda5050_msgs__msg__Factsheet__Sequence__init(vda5050_msgs__msg__Factsheet__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__Factsheet * data = NULL;

  if (size) {
    data = (vda5050_msgs__msg__Factsheet *)allocator.zero_allocate(size, sizeof(vda5050_msgs__msg__Factsheet), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vda5050_msgs__msg__Factsheet__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vda5050_msgs__msg__Factsheet__fini(&data[i - 1]);
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
vda5050_msgs__msg__Factsheet__Sequence__fini(vda5050_msgs__msg__Factsheet__Sequence * array)
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
      vda5050_msgs__msg__Factsheet__fini(&array->data[i]);
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

vda5050_msgs__msg__Factsheet__Sequence *
vda5050_msgs__msg__Factsheet__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vda5050_msgs__msg__Factsheet__Sequence * array = (vda5050_msgs__msg__Factsheet__Sequence *)allocator.allocate(sizeof(vda5050_msgs__msg__Factsheet__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vda5050_msgs__msg__Factsheet__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vda5050_msgs__msg__Factsheet__Sequence__destroy(vda5050_msgs__msg__Factsheet__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vda5050_msgs__msg__Factsheet__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vda5050_msgs__msg__Factsheet__Sequence__are_equal(const vda5050_msgs__msg__Factsheet__Sequence * lhs, const vda5050_msgs__msg__Factsheet__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vda5050_msgs__msg__Factsheet__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vda5050_msgs__msg__Factsheet__Sequence__copy(
  const vda5050_msgs__msg__Factsheet__Sequence * input,
  vda5050_msgs__msg__Factsheet__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vda5050_msgs__msg__Factsheet);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    vda5050_msgs__msg__Factsheet * data =
      (vda5050_msgs__msg__Factsheet *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vda5050_msgs__msg__Factsheet__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          vda5050_msgs__msg__Factsheet__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vda5050_msgs__msg__Factsheet__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
