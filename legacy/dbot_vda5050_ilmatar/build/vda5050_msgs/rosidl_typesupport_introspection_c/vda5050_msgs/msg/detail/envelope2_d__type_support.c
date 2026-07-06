// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from vda5050_msgs:msg/Envelope2D.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "vda5050_msgs/msg/detail/envelope2_d__rosidl_typesupport_introspection_c.h"
#include "vda5050_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "vda5050_msgs/msg/detail/envelope2_d__functions.h"
#include "vda5050_msgs/msg/detail/envelope2_d__struct.h"


// Include directives for member types
// Member `set`
// Member `description`
#include "rosidl_runtime_c/string_functions.h"
// Member `polygon_points`
#include "vda5050_msgs/msg/polygon_point.h"
// Member `polygon_points`
#include "vda5050_msgs/msg/detail/polygon_point__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void vda5050_msgs__msg__Envelope2D__rosidl_typesupport_introspection_c__Envelope2D_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  vda5050_msgs__msg__Envelope2D__init(message_memory);
}

void vda5050_msgs__msg__Envelope2D__rosidl_typesupport_introspection_c__Envelope2D_fini_function(void * message_memory)
{
  vda5050_msgs__msg__Envelope2D__fini(message_memory);
}

size_t vda5050_msgs__msg__Envelope2D__rosidl_typesupport_introspection_c__size_function__Envelope2D__polygon_points(
  const void * untyped_member)
{
  const vda5050_msgs__msg__PolygonPoint__Sequence * member =
    (const vda5050_msgs__msg__PolygonPoint__Sequence *)(untyped_member);
  return member->size;
}

const void * vda5050_msgs__msg__Envelope2D__rosidl_typesupport_introspection_c__get_const_function__Envelope2D__polygon_points(
  const void * untyped_member, size_t index)
{
  const vda5050_msgs__msg__PolygonPoint__Sequence * member =
    (const vda5050_msgs__msg__PolygonPoint__Sequence *)(untyped_member);
  return &member->data[index];
}

void * vda5050_msgs__msg__Envelope2D__rosidl_typesupport_introspection_c__get_function__Envelope2D__polygon_points(
  void * untyped_member, size_t index)
{
  vda5050_msgs__msg__PolygonPoint__Sequence * member =
    (vda5050_msgs__msg__PolygonPoint__Sequence *)(untyped_member);
  return &member->data[index];
}

void vda5050_msgs__msg__Envelope2D__rosidl_typesupport_introspection_c__fetch_function__Envelope2D__polygon_points(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const vda5050_msgs__msg__PolygonPoint * item =
    ((const vda5050_msgs__msg__PolygonPoint *)
    vda5050_msgs__msg__Envelope2D__rosidl_typesupport_introspection_c__get_const_function__Envelope2D__polygon_points(untyped_member, index));
  vda5050_msgs__msg__PolygonPoint * value =
    (vda5050_msgs__msg__PolygonPoint *)(untyped_value);
  *value = *item;
}

void vda5050_msgs__msg__Envelope2D__rosidl_typesupport_introspection_c__assign_function__Envelope2D__polygon_points(
  void * untyped_member, size_t index, const void * untyped_value)
{
  vda5050_msgs__msg__PolygonPoint * item =
    ((vda5050_msgs__msg__PolygonPoint *)
    vda5050_msgs__msg__Envelope2D__rosidl_typesupport_introspection_c__get_function__Envelope2D__polygon_points(untyped_member, index));
  const vda5050_msgs__msg__PolygonPoint * value =
    (const vda5050_msgs__msg__PolygonPoint *)(untyped_value);
  *item = *value;
}

bool vda5050_msgs__msg__Envelope2D__rosidl_typesupport_introspection_c__resize_function__Envelope2D__polygon_points(
  void * untyped_member, size_t size)
{
  vda5050_msgs__msg__PolygonPoint__Sequence * member =
    (vda5050_msgs__msg__PolygonPoint__Sequence *)(untyped_member);
  vda5050_msgs__msg__PolygonPoint__Sequence__fini(member);
  return vda5050_msgs__msg__PolygonPoint__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember vda5050_msgs__msg__Envelope2D__rosidl_typesupport_introspection_c__Envelope2D_message_member_array[3] = {
  {
    "set",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs__msg__Envelope2D, set),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "polygon_points",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs__msg__Envelope2D, polygon_points),  // bytes offset in struct
    NULL,  // default value
    vda5050_msgs__msg__Envelope2D__rosidl_typesupport_introspection_c__size_function__Envelope2D__polygon_points,  // size() function pointer
    vda5050_msgs__msg__Envelope2D__rosidl_typesupport_introspection_c__get_const_function__Envelope2D__polygon_points,  // get_const(index) function pointer
    vda5050_msgs__msg__Envelope2D__rosidl_typesupport_introspection_c__get_function__Envelope2D__polygon_points,  // get(index) function pointer
    vda5050_msgs__msg__Envelope2D__rosidl_typesupport_introspection_c__fetch_function__Envelope2D__polygon_points,  // fetch(index, &value) function pointer
    vda5050_msgs__msg__Envelope2D__rosidl_typesupport_introspection_c__assign_function__Envelope2D__polygon_points,  // assign(index, value) function pointer
    vda5050_msgs__msg__Envelope2D__rosidl_typesupport_introspection_c__resize_function__Envelope2D__polygon_points  // resize(index) function pointer
  },
  {
    "description",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs__msg__Envelope2D, description),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers vda5050_msgs__msg__Envelope2D__rosidl_typesupport_introspection_c__Envelope2D_message_members = {
  "vda5050_msgs__msg",  // message namespace
  "Envelope2D",  // message name
  3,  // number of fields
  sizeof(vda5050_msgs__msg__Envelope2D),
  vda5050_msgs__msg__Envelope2D__rosidl_typesupport_introspection_c__Envelope2D_message_member_array,  // message members
  vda5050_msgs__msg__Envelope2D__rosidl_typesupport_introspection_c__Envelope2D_init_function,  // function to initialize message memory (memory has to be allocated)
  vda5050_msgs__msg__Envelope2D__rosidl_typesupport_introspection_c__Envelope2D_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t vda5050_msgs__msg__Envelope2D__rosidl_typesupport_introspection_c__Envelope2D_message_type_support_handle = {
  0,
  &vda5050_msgs__msg__Envelope2D__rosidl_typesupport_introspection_c__Envelope2D_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_vda5050_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vda5050_msgs, msg, Envelope2D)() {
  vda5050_msgs__msg__Envelope2D__rosidl_typesupport_introspection_c__Envelope2D_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vda5050_msgs, msg, PolygonPoint)();
  if (!vda5050_msgs__msg__Envelope2D__rosidl_typesupport_introspection_c__Envelope2D_message_type_support_handle.typesupport_identifier) {
    vda5050_msgs__msg__Envelope2D__rosidl_typesupport_introspection_c__Envelope2D_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &vda5050_msgs__msg__Envelope2D__rosidl_typesupport_introspection_c__Envelope2D_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
