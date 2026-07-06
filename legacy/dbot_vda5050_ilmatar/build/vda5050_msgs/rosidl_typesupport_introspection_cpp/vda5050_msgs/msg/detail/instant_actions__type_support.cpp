// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from vda5050_msgs:msg/InstantActions.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "vda5050_msgs/msg/detail/instant_actions__struct.hpp"
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

void InstantActions_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) vda5050_msgs::msg::InstantActions(_init);
}

void InstantActions_fini_function(void * message_memory)
{
  auto typed_message = static_cast<vda5050_msgs::msg::InstantActions *>(message_memory);
  typed_message->~InstantActions();
}

size_t size_function__InstantActions__actions(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<vda5050_msgs::msg::Action> *>(untyped_member);
  return member->size();
}

const void * get_const_function__InstantActions__actions(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<vda5050_msgs::msg::Action> *>(untyped_member);
  return &member[index];
}

void * get_function__InstantActions__actions(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<vda5050_msgs::msg::Action> *>(untyped_member);
  return &member[index];
}

void fetch_function__InstantActions__actions(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const vda5050_msgs::msg::Action *>(
    get_const_function__InstantActions__actions(untyped_member, index));
  auto & value = *reinterpret_cast<vda5050_msgs::msg::Action *>(untyped_value);
  value = item;
}

void assign_function__InstantActions__actions(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<vda5050_msgs::msg::Action *>(
    get_function__InstantActions__actions(untyped_member, index));
  const auto & value = *reinterpret_cast<const vda5050_msgs::msg::Action *>(untyped_value);
  item = value;
}

void resize_function__InstantActions__actions(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<vda5050_msgs::msg::Action> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember InstantActions_message_member_array[6] = {
  {
    "header_id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs::msg::InstantActions, header_id),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "timestamp",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs::msg::InstantActions, timestamp),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "version",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs::msg::InstantActions, version),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "manufacturer",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs::msg::InstantActions, manufacturer),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "serial_number",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs::msg::InstantActions, serial_number),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "actions",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<vda5050_msgs::msg::Action>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs::msg::InstantActions, actions),  // bytes offset in struct
    nullptr,  // default value
    size_function__InstantActions__actions,  // size() function pointer
    get_const_function__InstantActions__actions,  // get_const(index) function pointer
    get_function__InstantActions__actions,  // get(index) function pointer
    fetch_function__InstantActions__actions,  // fetch(index, &value) function pointer
    assign_function__InstantActions__actions,  // assign(index, value) function pointer
    resize_function__InstantActions__actions  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers InstantActions_message_members = {
  "vda5050_msgs::msg",  // message namespace
  "InstantActions",  // message name
  6,  // number of fields
  sizeof(vda5050_msgs::msg::InstantActions),
  InstantActions_message_member_array,  // message members
  InstantActions_init_function,  // function to initialize message memory (memory has to be allocated)
  InstantActions_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t InstantActions_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &InstantActions_message_members,
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
get_message_type_support_handle<vda5050_msgs::msg::InstantActions>()
{
  return &::vda5050_msgs::msg::rosidl_typesupport_introspection_cpp::InstantActions_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, vda5050_msgs, msg, InstantActions)() {
  return &::vda5050_msgs::msg::rosidl_typesupport_introspection_cpp::InstantActions_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
