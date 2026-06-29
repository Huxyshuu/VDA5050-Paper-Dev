// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from vda5050_msgs:msg/Trajectory.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "vda5050_msgs/msg/detail/trajectory__rosidl_typesupport_introspection_c.h"
#include "vda5050_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "vda5050_msgs/msg/detail/trajectory__functions.h"
#include "vda5050_msgs/msg/detail/trajectory__struct.h"


// Include directives for member types
// Member `knot_vector`
#include "rosidl_runtime_c/primitives_sequence_functions.h"
// Member `control_points`
#include "vda5050_msgs/msg/control_point.h"
// Member `control_points`
#include "vda5050_msgs/msg/detail/control_point__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void vda5050_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__Trajectory_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  vda5050_msgs__msg__Trajectory__init(message_memory);
}

void vda5050_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__Trajectory_fini_function(void * message_memory)
{
  vda5050_msgs__msg__Trajectory__fini(message_memory);
}

size_t vda5050_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__size_function__Trajectory__knot_vector(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * vda5050_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__get_const_function__Trajectory__knot_vector(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * vda5050_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__get_function__Trajectory__knot_vector(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void vda5050_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__fetch_function__Trajectory__knot_vector(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    vda5050_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__get_const_function__Trajectory__knot_vector(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void vda5050_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__assign_function__Trajectory__knot_vector(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    vda5050_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__get_function__Trajectory__knot_vector(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool vda5050_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__resize_function__Trajectory__knot_vector(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

size_t vda5050_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__size_function__Trajectory__control_points(
  const void * untyped_member)
{
  const vda5050_msgs__msg__ControlPoint__Sequence * member =
    (const vda5050_msgs__msg__ControlPoint__Sequence *)(untyped_member);
  return member->size;
}

const void * vda5050_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__get_const_function__Trajectory__control_points(
  const void * untyped_member, size_t index)
{
  const vda5050_msgs__msg__ControlPoint__Sequence * member =
    (const vda5050_msgs__msg__ControlPoint__Sequence *)(untyped_member);
  return &member->data[index];
}

void * vda5050_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__get_function__Trajectory__control_points(
  void * untyped_member, size_t index)
{
  vda5050_msgs__msg__ControlPoint__Sequence * member =
    (vda5050_msgs__msg__ControlPoint__Sequence *)(untyped_member);
  return &member->data[index];
}

void vda5050_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__fetch_function__Trajectory__control_points(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const vda5050_msgs__msg__ControlPoint * item =
    ((const vda5050_msgs__msg__ControlPoint *)
    vda5050_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__get_const_function__Trajectory__control_points(untyped_member, index));
  vda5050_msgs__msg__ControlPoint * value =
    (vda5050_msgs__msg__ControlPoint *)(untyped_value);
  *value = *item;
}

void vda5050_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__assign_function__Trajectory__control_points(
  void * untyped_member, size_t index, const void * untyped_value)
{
  vda5050_msgs__msg__ControlPoint * item =
    ((vda5050_msgs__msg__ControlPoint *)
    vda5050_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__get_function__Trajectory__control_points(untyped_member, index));
  const vda5050_msgs__msg__ControlPoint * value =
    (const vda5050_msgs__msg__ControlPoint *)(untyped_value);
  *item = *value;
}

bool vda5050_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__resize_function__Trajectory__control_points(
  void * untyped_member, size_t size)
{
  vda5050_msgs__msg__ControlPoint__Sequence * member =
    (vda5050_msgs__msg__ControlPoint__Sequence *)(untyped_member);
  vda5050_msgs__msg__ControlPoint__Sequence__fini(member);
  return vda5050_msgs__msg__ControlPoint__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember vda5050_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__Trajectory_message_member_array[3] = {
  {
    "degree",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs__msg__Trajectory, degree),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "knot_vector",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs__msg__Trajectory, knot_vector),  // bytes offset in struct
    NULL,  // default value
    vda5050_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__size_function__Trajectory__knot_vector,  // size() function pointer
    vda5050_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__get_const_function__Trajectory__knot_vector,  // get_const(index) function pointer
    vda5050_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__get_function__Trajectory__knot_vector,  // get(index) function pointer
    vda5050_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__fetch_function__Trajectory__knot_vector,  // fetch(index, &value) function pointer
    vda5050_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__assign_function__Trajectory__knot_vector,  // assign(index, value) function pointer
    vda5050_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__resize_function__Trajectory__knot_vector  // resize(index) function pointer
  },
  {
    "control_points",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs__msg__Trajectory, control_points),  // bytes offset in struct
    NULL,  // default value
    vda5050_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__size_function__Trajectory__control_points,  // size() function pointer
    vda5050_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__get_const_function__Trajectory__control_points,  // get_const(index) function pointer
    vda5050_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__get_function__Trajectory__control_points,  // get(index) function pointer
    vda5050_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__fetch_function__Trajectory__control_points,  // fetch(index, &value) function pointer
    vda5050_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__assign_function__Trajectory__control_points,  // assign(index, value) function pointer
    vda5050_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__resize_function__Trajectory__control_points  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers vda5050_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__Trajectory_message_members = {
  "vda5050_msgs__msg",  // message namespace
  "Trajectory",  // message name
  3,  // number of fields
  sizeof(vda5050_msgs__msg__Trajectory),
  vda5050_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__Trajectory_message_member_array,  // message members
  vda5050_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__Trajectory_init_function,  // function to initialize message memory (memory has to be allocated)
  vda5050_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__Trajectory_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t vda5050_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__Trajectory_message_type_support_handle = {
  0,
  &vda5050_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__Trajectory_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_vda5050_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vda5050_msgs, msg, Trajectory)() {
  vda5050_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__Trajectory_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vda5050_msgs, msg, ControlPoint)();
  if (!vda5050_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__Trajectory_message_type_support_handle.typesupport_identifier) {
    vda5050_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__Trajectory_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &vda5050_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__Trajectory_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
