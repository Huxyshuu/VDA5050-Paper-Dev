// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from vda5050_msgs:msg/AGVGeometry.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "vda5050_msgs/msg/detail/agv_geometry__struct.hpp"
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

void AGVGeometry_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) vda5050_msgs::msg::AGVGeometry(_init);
}

void AGVGeometry_fini_function(void * message_memory)
{
  auto typed_message = static_cast<vda5050_msgs::msg::AGVGeometry *>(message_memory);
  typed_message->~AGVGeometry();
}

size_t size_function__AGVGeometry__wheel_definitions(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<vda5050_msgs::msg::WheelDefinition> *>(untyped_member);
  return member->size();
}

const void * get_const_function__AGVGeometry__wheel_definitions(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<vda5050_msgs::msg::WheelDefinition> *>(untyped_member);
  return &member[index];
}

void * get_function__AGVGeometry__wheel_definitions(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<vda5050_msgs::msg::WheelDefinition> *>(untyped_member);
  return &member[index];
}

void fetch_function__AGVGeometry__wheel_definitions(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const vda5050_msgs::msg::WheelDefinition *>(
    get_const_function__AGVGeometry__wheel_definitions(untyped_member, index));
  auto & value = *reinterpret_cast<vda5050_msgs::msg::WheelDefinition *>(untyped_value);
  value = item;
}

void assign_function__AGVGeometry__wheel_definitions(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<vda5050_msgs::msg::WheelDefinition *>(
    get_function__AGVGeometry__wheel_definitions(untyped_member, index));
  const auto & value = *reinterpret_cast<const vda5050_msgs::msg::WheelDefinition *>(untyped_value);
  item = value;
}

void resize_function__AGVGeometry__wheel_definitions(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<vda5050_msgs::msg::WheelDefinition> *>(untyped_member);
  member->resize(size);
}

size_t size_function__AGVGeometry__envelopes2d(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<vda5050_msgs::msg::Envelope2D> *>(untyped_member);
  return member->size();
}

const void * get_const_function__AGVGeometry__envelopes2d(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<vda5050_msgs::msg::Envelope2D> *>(untyped_member);
  return &member[index];
}

void * get_function__AGVGeometry__envelopes2d(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<vda5050_msgs::msg::Envelope2D> *>(untyped_member);
  return &member[index];
}

void fetch_function__AGVGeometry__envelopes2d(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const vda5050_msgs::msg::Envelope2D *>(
    get_const_function__AGVGeometry__envelopes2d(untyped_member, index));
  auto & value = *reinterpret_cast<vda5050_msgs::msg::Envelope2D *>(untyped_value);
  value = item;
}

void assign_function__AGVGeometry__envelopes2d(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<vda5050_msgs::msg::Envelope2D *>(
    get_function__AGVGeometry__envelopes2d(untyped_member, index));
  const auto & value = *reinterpret_cast<const vda5050_msgs::msg::Envelope2D *>(untyped_value);
  item = value;
}

void resize_function__AGVGeometry__envelopes2d(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<vda5050_msgs::msg::Envelope2D> *>(untyped_member);
  member->resize(size);
}

size_t size_function__AGVGeometry__envelopes3d(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<vda5050_msgs::msg::Envelope3D> *>(untyped_member);
  return member->size();
}

const void * get_const_function__AGVGeometry__envelopes3d(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<vda5050_msgs::msg::Envelope3D> *>(untyped_member);
  return &member[index];
}

void * get_function__AGVGeometry__envelopes3d(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<vda5050_msgs::msg::Envelope3D> *>(untyped_member);
  return &member[index];
}

void fetch_function__AGVGeometry__envelopes3d(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const vda5050_msgs::msg::Envelope3D *>(
    get_const_function__AGVGeometry__envelopes3d(untyped_member, index));
  auto & value = *reinterpret_cast<vda5050_msgs::msg::Envelope3D *>(untyped_value);
  value = item;
}

void assign_function__AGVGeometry__envelopes3d(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<vda5050_msgs::msg::Envelope3D *>(
    get_function__AGVGeometry__envelopes3d(untyped_member, index));
  const auto & value = *reinterpret_cast<const vda5050_msgs::msg::Envelope3D *>(untyped_value);
  item = value;
}

void resize_function__AGVGeometry__envelopes3d(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<vda5050_msgs::msg::Envelope3D> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember AGVGeometry_message_member_array[3] = {
  {
    "wheel_definitions",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<vda5050_msgs::msg::WheelDefinition>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs::msg::AGVGeometry, wheel_definitions),  // bytes offset in struct
    nullptr,  // default value
    size_function__AGVGeometry__wheel_definitions,  // size() function pointer
    get_const_function__AGVGeometry__wheel_definitions,  // get_const(index) function pointer
    get_function__AGVGeometry__wheel_definitions,  // get(index) function pointer
    fetch_function__AGVGeometry__wheel_definitions,  // fetch(index, &value) function pointer
    assign_function__AGVGeometry__wheel_definitions,  // assign(index, value) function pointer
    resize_function__AGVGeometry__wheel_definitions  // resize(index) function pointer
  },
  {
    "envelopes2d",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<vda5050_msgs::msg::Envelope2D>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs::msg::AGVGeometry, envelopes2d),  // bytes offset in struct
    nullptr,  // default value
    size_function__AGVGeometry__envelopes2d,  // size() function pointer
    get_const_function__AGVGeometry__envelopes2d,  // get_const(index) function pointer
    get_function__AGVGeometry__envelopes2d,  // get(index) function pointer
    fetch_function__AGVGeometry__envelopes2d,  // fetch(index, &value) function pointer
    assign_function__AGVGeometry__envelopes2d,  // assign(index, value) function pointer
    resize_function__AGVGeometry__envelopes2d  // resize(index) function pointer
  },
  {
    "envelopes3d",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<vda5050_msgs::msg::Envelope3D>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs::msg::AGVGeometry, envelopes3d),  // bytes offset in struct
    nullptr,  // default value
    size_function__AGVGeometry__envelopes3d,  // size() function pointer
    get_const_function__AGVGeometry__envelopes3d,  // get_const(index) function pointer
    get_function__AGVGeometry__envelopes3d,  // get(index) function pointer
    fetch_function__AGVGeometry__envelopes3d,  // fetch(index, &value) function pointer
    assign_function__AGVGeometry__envelopes3d,  // assign(index, value) function pointer
    resize_function__AGVGeometry__envelopes3d  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers AGVGeometry_message_members = {
  "vda5050_msgs::msg",  // message namespace
  "AGVGeometry",  // message name
  3,  // number of fields
  sizeof(vda5050_msgs::msg::AGVGeometry),
  AGVGeometry_message_member_array,  // message members
  AGVGeometry_init_function,  // function to initialize message memory (memory has to be allocated)
  AGVGeometry_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t AGVGeometry_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &AGVGeometry_message_members,
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
get_message_type_support_handle<vda5050_msgs::msg::AGVGeometry>()
{
  return &::vda5050_msgs::msg::rosidl_typesupport_introspection_cpp::AGVGeometry_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, vda5050_msgs, msg, AGVGeometry)() {
  return &::vda5050_msgs::msg::rosidl_typesupport_introspection_cpp::AGVGeometry_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
