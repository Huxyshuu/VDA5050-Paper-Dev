// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from vda5050_msgs:msg/ProtocolFeatures.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "vda5050_msgs/msg/detail/protocol_features__struct.hpp"
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

void ProtocolFeatures_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) vda5050_msgs::msg::ProtocolFeatures(_init);
}

void ProtocolFeatures_fini_function(void * message_memory)
{
  auto typed_message = static_cast<vda5050_msgs::msg::ProtocolFeatures *>(message_memory);
  typed_message->~ProtocolFeatures();
}

size_t size_function__ProtocolFeatures__optional_parameters(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<vda5050_msgs::msg::OptionalParameter> *>(untyped_member);
  return member->size();
}

const void * get_const_function__ProtocolFeatures__optional_parameters(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<vda5050_msgs::msg::OptionalParameter> *>(untyped_member);
  return &member[index];
}

void * get_function__ProtocolFeatures__optional_parameters(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<vda5050_msgs::msg::OptionalParameter> *>(untyped_member);
  return &member[index];
}

void fetch_function__ProtocolFeatures__optional_parameters(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const vda5050_msgs::msg::OptionalParameter *>(
    get_const_function__ProtocolFeatures__optional_parameters(untyped_member, index));
  auto & value = *reinterpret_cast<vda5050_msgs::msg::OptionalParameter *>(untyped_value);
  value = item;
}

void assign_function__ProtocolFeatures__optional_parameters(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<vda5050_msgs::msg::OptionalParameter *>(
    get_function__ProtocolFeatures__optional_parameters(untyped_member, index));
  const auto & value = *reinterpret_cast<const vda5050_msgs::msg::OptionalParameter *>(untyped_value);
  item = value;
}

void resize_function__ProtocolFeatures__optional_parameters(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<vda5050_msgs::msg::OptionalParameter> *>(untyped_member);
  member->resize(size);
}

size_t size_function__ProtocolFeatures__agv_actions(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<vda5050_msgs::msg::AGVAction> *>(untyped_member);
  return member->size();
}

const void * get_const_function__ProtocolFeatures__agv_actions(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<vda5050_msgs::msg::AGVAction> *>(untyped_member);
  return &member[index];
}

void * get_function__ProtocolFeatures__agv_actions(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<vda5050_msgs::msg::AGVAction> *>(untyped_member);
  return &member[index];
}

void fetch_function__ProtocolFeatures__agv_actions(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const vda5050_msgs::msg::AGVAction *>(
    get_const_function__ProtocolFeatures__agv_actions(untyped_member, index));
  auto & value = *reinterpret_cast<vda5050_msgs::msg::AGVAction *>(untyped_value);
  value = item;
}

void assign_function__ProtocolFeatures__agv_actions(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<vda5050_msgs::msg::AGVAction *>(
    get_function__ProtocolFeatures__agv_actions(untyped_member, index));
  const auto & value = *reinterpret_cast<const vda5050_msgs::msg::AGVAction *>(untyped_value);
  item = value;
}

void resize_function__ProtocolFeatures__agv_actions(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<vda5050_msgs::msg::AGVAction> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember ProtocolFeatures_message_member_array[2] = {
  {
    "optional_parameters",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<vda5050_msgs::msg::OptionalParameter>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs::msg::ProtocolFeatures, optional_parameters),  // bytes offset in struct
    nullptr,  // default value
    size_function__ProtocolFeatures__optional_parameters,  // size() function pointer
    get_const_function__ProtocolFeatures__optional_parameters,  // get_const(index) function pointer
    get_function__ProtocolFeatures__optional_parameters,  // get(index) function pointer
    fetch_function__ProtocolFeatures__optional_parameters,  // fetch(index, &value) function pointer
    assign_function__ProtocolFeatures__optional_parameters,  // assign(index, value) function pointer
    resize_function__ProtocolFeatures__optional_parameters  // resize(index) function pointer
  },
  {
    "agv_actions",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<vda5050_msgs::msg::AGVAction>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs::msg::ProtocolFeatures, agv_actions),  // bytes offset in struct
    nullptr,  // default value
    size_function__ProtocolFeatures__agv_actions,  // size() function pointer
    get_const_function__ProtocolFeatures__agv_actions,  // get_const(index) function pointer
    get_function__ProtocolFeatures__agv_actions,  // get(index) function pointer
    fetch_function__ProtocolFeatures__agv_actions,  // fetch(index, &value) function pointer
    assign_function__ProtocolFeatures__agv_actions,  // assign(index, value) function pointer
    resize_function__ProtocolFeatures__agv_actions  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers ProtocolFeatures_message_members = {
  "vda5050_msgs::msg",  // message namespace
  "ProtocolFeatures",  // message name
  2,  // number of fields
  sizeof(vda5050_msgs::msg::ProtocolFeatures),
  ProtocolFeatures_message_member_array,  // message members
  ProtocolFeatures_init_function,  // function to initialize message memory (memory has to be allocated)
  ProtocolFeatures_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t ProtocolFeatures_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ProtocolFeatures_message_members,
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
get_message_type_support_handle<vda5050_msgs::msg::ProtocolFeatures>()
{
  return &::vda5050_msgs::msg::rosidl_typesupport_introspection_cpp::ProtocolFeatures_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, vda5050_msgs, msg, ProtocolFeatures)() {
  return &::vda5050_msgs::msg::rosidl_typesupport_introspection_cpp::ProtocolFeatures_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
