// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from vda5050_msgs:msg/AGVAction.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "vda5050_msgs/msg/detail/agv_action__struct.hpp"
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

void AGVAction_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) vda5050_msgs::msg::AGVAction(_init);
}

void AGVAction_fini_function(void * message_memory)
{
  auto typed_message = static_cast<vda5050_msgs::msg::AGVAction *>(message_memory);
  typed_message->~AGVAction();
}

size_t size_function__AGVAction__action_scopes(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<std::string> *>(untyped_member);
  return member->size();
}

const void * get_const_function__AGVAction__action_scopes(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<std::string> *>(untyped_member);
  return &member[index];
}

void * get_function__AGVAction__action_scopes(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<std::string> *>(untyped_member);
  return &member[index];
}

void fetch_function__AGVAction__action_scopes(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const std::string *>(
    get_const_function__AGVAction__action_scopes(untyped_member, index));
  auto & value = *reinterpret_cast<std::string *>(untyped_value);
  value = item;
}

void assign_function__AGVAction__action_scopes(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<std::string *>(
    get_function__AGVAction__action_scopes(untyped_member, index));
  const auto & value = *reinterpret_cast<const std::string *>(untyped_value);
  item = value;
}

void resize_function__AGVAction__action_scopes(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<std::string> *>(untyped_member);
  member->resize(size);
}

size_t size_function__AGVAction__action_parameters(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<vda5050_msgs::msg::ActionParameterDefinition> *>(untyped_member);
  return member->size();
}

const void * get_const_function__AGVAction__action_parameters(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<vda5050_msgs::msg::ActionParameterDefinition> *>(untyped_member);
  return &member[index];
}

void * get_function__AGVAction__action_parameters(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<vda5050_msgs::msg::ActionParameterDefinition> *>(untyped_member);
  return &member[index];
}

void fetch_function__AGVAction__action_parameters(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const vda5050_msgs::msg::ActionParameterDefinition *>(
    get_const_function__AGVAction__action_parameters(untyped_member, index));
  auto & value = *reinterpret_cast<vda5050_msgs::msg::ActionParameterDefinition *>(untyped_value);
  value = item;
}

void assign_function__AGVAction__action_parameters(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<vda5050_msgs::msg::ActionParameterDefinition *>(
    get_function__AGVAction__action_parameters(untyped_member, index));
  const auto & value = *reinterpret_cast<const vda5050_msgs::msg::ActionParameterDefinition *>(untyped_value);
  item = value;
}

void resize_function__AGVAction__action_parameters(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<vda5050_msgs::msg::ActionParameterDefinition> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember AGVAction_message_member_array[5] = {
  {
    "action_type",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs::msg::AGVAction, action_type),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "action_description",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs::msg::AGVAction, action_description),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "action_scopes",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs::msg::AGVAction, action_scopes),  // bytes offset in struct
    nullptr,  // default value
    size_function__AGVAction__action_scopes,  // size() function pointer
    get_const_function__AGVAction__action_scopes,  // get_const(index) function pointer
    get_function__AGVAction__action_scopes,  // get(index) function pointer
    fetch_function__AGVAction__action_scopes,  // fetch(index, &value) function pointer
    assign_function__AGVAction__action_scopes,  // assign(index, value) function pointer
    resize_function__AGVAction__action_scopes  // resize(index) function pointer
  },
  {
    "action_parameters",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<vda5050_msgs::msg::ActionParameterDefinition>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs::msg::AGVAction, action_parameters),  // bytes offset in struct
    nullptr,  // default value
    size_function__AGVAction__action_parameters,  // size() function pointer
    get_const_function__AGVAction__action_parameters,  // get_const(index) function pointer
    get_function__AGVAction__action_parameters,  // get(index) function pointer
    fetch_function__AGVAction__action_parameters,  // fetch(index, &value) function pointer
    assign_function__AGVAction__action_parameters,  // assign(index, value) function pointer
    resize_function__AGVAction__action_parameters  // resize(index) function pointer
  },
  {
    "result_description",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs::msg::AGVAction, result_description),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers AGVAction_message_members = {
  "vda5050_msgs::msg",  // message namespace
  "AGVAction",  // message name
  5,  // number of fields
  sizeof(vda5050_msgs::msg::AGVAction),
  AGVAction_message_member_array,  // message members
  AGVAction_init_function,  // function to initialize message memory (memory has to be allocated)
  AGVAction_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t AGVAction_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &AGVAction_message_members,
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
get_message_type_support_handle<vda5050_msgs::msg::AGVAction>()
{
  return &::vda5050_msgs::msg::rosidl_typesupport_introspection_cpp::AGVAction_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, vda5050_msgs, msg, AGVAction)() {
  return &::vda5050_msgs::msg::rosidl_typesupport_introspection_cpp::AGVAction_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
