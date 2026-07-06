// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from vda5050_msgs:msg/Envelope2D.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "vda5050_msgs/msg/detail/envelope2_d__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace vda5050_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void Envelope2D_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) vda5050_msgs::msg::Envelope2D(_init);
}

void Envelope2D_fini_function(void * message_memory)
{
  auto typed_message = static_cast<vda5050_msgs::msg::Envelope2D *>(message_memory);
  typed_message->~Envelope2D();
}

size_t size_function__Envelope2D__polygon_points(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<vda5050_msgs::msg::PolygonPoint> *>(untyped_member);
  return member->size();
}

const void * get_const_function__Envelope2D__polygon_points(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<vda5050_msgs::msg::PolygonPoint> *>(untyped_member);
  return &member[index];
}

void * get_function__Envelope2D__polygon_points(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<vda5050_msgs::msg::PolygonPoint> *>(untyped_member);
  return &member[index];
}

void fetch_function__Envelope2D__polygon_points(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const vda5050_msgs::msg::PolygonPoint *>(
    get_const_function__Envelope2D__polygon_points(untyped_member, index));
  auto & value = *reinterpret_cast<vda5050_msgs::msg::PolygonPoint *>(untyped_value);
  value = item;
}

void assign_function__Envelope2D__polygon_points(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<vda5050_msgs::msg::PolygonPoint *>(
    get_function__Envelope2D__polygon_points(untyped_member, index));
  const auto & value = *reinterpret_cast<const vda5050_msgs::msg::PolygonPoint *>(untyped_value);
  item = value;
}

void resize_function__Envelope2D__polygon_points(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<vda5050_msgs::msg::PolygonPoint> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Envelope2D_message_member_array[3] = {
  {
    "set",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs::msg::Envelope2D, set),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "polygon_points",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<vda5050_msgs::msg::PolygonPoint>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs::msg::Envelope2D, polygon_points),  // bytes offset in struct
    nullptr,  // default value
    size_function__Envelope2D__polygon_points,  // size() function pointer
    get_const_function__Envelope2D__polygon_points,  // get_const(index) function pointer
    get_function__Envelope2D__polygon_points,  // get(index) function pointer
    fetch_function__Envelope2D__polygon_points,  // fetch(index, &value) function pointer
    assign_function__Envelope2D__polygon_points,  // assign(index, value) function pointer
    resize_function__Envelope2D__polygon_points  // resize(index) function pointer
  },
  {
    "description",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs::msg::Envelope2D, description),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Envelope2D_message_members = {
  "vda5050_msgs::msg",  // message namespace
  "Envelope2D",  // message name
  3,  // number of fields
  sizeof(vda5050_msgs::msg::Envelope2D),
  Envelope2D_message_member_array,  // message members
  Envelope2D_init_function,  // function to initialize message memory (memory has to be allocated)
  Envelope2D_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Envelope2D_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Envelope2D_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace vda5050_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<vda5050_msgs::msg::Envelope2D>()
{
  return &::vda5050_msgs::msg::rosidl_typesupport_introspection_cpp::Envelope2D_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, vda5050_msgs, msg, Envelope2D)() {
  return &::vda5050_msgs::msg::rosidl_typesupport_introspection_cpp::Envelope2D_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
