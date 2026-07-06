// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from vda5050_msgs:msg/LoadSpecification.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "vda5050_msgs/msg/detail/load_specification__struct.hpp"
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

void LoadSpecification_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) vda5050_msgs::msg::LoadSpecification(_init);
}

void LoadSpecification_fini_function(void * message_memory)
{
  auto typed_message = static_cast<vda5050_msgs::msg::LoadSpecification *>(message_memory);
  typed_message->~LoadSpecification();
}

size_t size_function__LoadSpecification__load_positions(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<std::string> *>(untyped_member);
  return member->size();
}

const void * get_const_function__LoadSpecification__load_positions(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<std::string> *>(untyped_member);
  return &member[index];
}

void * get_function__LoadSpecification__load_positions(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<std::string> *>(untyped_member);
  return &member[index];
}

void fetch_function__LoadSpecification__load_positions(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const std::string *>(
    get_const_function__LoadSpecification__load_positions(untyped_member, index));
  auto & value = *reinterpret_cast<std::string *>(untyped_value);
  value = item;
}

void assign_function__LoadSpecification__load_positions(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<std::string *>(
    get_function__LoadSpecification__load_positions(untyped_member, index));
  const auto & value = *reinterpret_cast<const std::string *>(untyped_value);
  item = value;
}

void resize_function__LoadSpecification__load_positions(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<std::string> *>(untyped_member);
  member->resize(size);
}

size_t size_function__LoadSpecification__load_sets(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<vda5050_msgs::msg::LoadSet> *>(untyped_member);
  return member->size();
}

const void * get_const_function__LoadSpecification__load_sets(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<vda5050_msgs::msg::LoadSet> *>(untyped_member);
  return &member[index];
}

void * get_function__LoadSpecification__load_sets(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<vda5050_msgs::msg::LoadSet> *>(untyped_member);
  return &member[index];
}

void fetch_function__LoadSpecification__load_sets(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const vda5050_msgs::msg::LoadSet *>(
    get_const_function__LoadSpecification__load_sets(untyped_member, index));
  auto & value = *reinterpret_cast<vda5050_msgs::msg::LoadSet *>(untyped_value);
  value = item;
}

void assign_function__LoadSpecification__load_sets(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<vda5050_msgs::msg::LoadSet *>(
    get_function__LoadSpecification__load_sets(untyped_member, index));
  const auto & value = *reinterpret_cast<const vda5050_msgs::msg::LoadSet *>(untyped_value);
  item = value;
}

void resize_function__LoadSpecification__load_sets(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<vda5050_msgs::msg::LoadSet> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember LoadSpecification_message_member_array[2] = {
  {
    "load_positions",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs::msg::LoadSpecification, load_positions),  // bytes offset in struct
    nullptr,  // default value
    size_function__LoadSpecification__load_positions,  // size() function pointer
    get_const_function__LoadSpecification__load_positions,  // get_const(index) function pointer
    get_function__LoadSpecification__load_positions,  // get(index) function pointer
    fetch_function__LoadSpecification__load_positions,  // fetch(index, &value) function pointer
    assign_function__LoadSpecification__load_positions,  // assign(index, value) function pointer
    resize_function__LoadSpecification__load_positions  // resize(index) function pointer
  },
  {
    "load_sets",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<vda5050_msgs::msg::LoadSet>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs::msg::LoadSpecification, load_sets),  // bytes offset in struct
    nullptr,  // default value
    size_function__LoadSpecification__load_sets,  // size() function pointer
    get_const_function__LoadSpecification__load_sets,  // get_const(index) function pointer
    get_function__LoadSpecification__load_sets,  // get(index) function pointer
    fetch_function__LoadSpecification__load_sets,  // fetch(index, &value) function pointer
    assign_function__LoadSpecification__load_sets,  // assign(index, value) function pointer
    resize_function__LoadSpecification__load_sets  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers LoadSpecification_message_members = {
  "vda5050_msgs::msg",  // message namespace
  "LoadSpecification",  // message name
  2,  // number of fields
  sizeof(vda5050_msgs::msg::LoadSpecification),
  LoadSpecification_message_member_array,  // message members
  LoadSpecification_init_function,  // function to initialize message memory (memory has to be allocated)
  LoadSpecification_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t LoadSpecification_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &LoadSpecification_message_members,
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
get_message_type_support_handle<vda5050_msgs::msg::LoadSpecification>()
{
  return &::vda5050_msgs::msg::rosidl_typesupport_introspection_cpp::LoadSpecification_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, vda5050_msgs, msg, LoadSpecification)() {
  return &::vda5050_msgs::msg::rosidl_typesupport_introspection_cpp::LoadSpecification_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
