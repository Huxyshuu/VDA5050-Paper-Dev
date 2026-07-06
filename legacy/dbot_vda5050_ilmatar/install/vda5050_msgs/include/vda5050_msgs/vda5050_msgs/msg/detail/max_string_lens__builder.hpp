// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vda5050_msgs:msg/MaxStringLens.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__MAX_STRING_LENS__BUILDER_HPP_
#define VDA5050_MSGS__MSG__DETAIL__MAX_STRING_LENS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vda5050_msgs/msg/detail/max_string_lens__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vda5050_msgs
{

namespace msg
{

namespace builder
{

class Init_MaxStringLens_load_id_len
{
public:
  explicit Init_MaxStringLens_load_id_len(::vda5050_msgs::msg::MaxStringLens & msg)
  : msg_(msg)
  {}
  ::vda5050_msgs::msg::MaxStringLens load_id_len(::vda5050_msgs::msg::MaxStringLens::_load_id_len_type arg)
  {
    msg_.load_id_len = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vda5050_msgs::msg::MaxStringLens msg_;
};

class Init_MaxStringLens_enum_len
{
public:
  explicit Init_MaxStringLens_enum_len(::vda5050_msgs::msg::MaxStringLens & msg)
  : msg_(msg)
  {}
  Init_MaxStringLens_load_id_len enum_len(::vda5050_msgs::msg::MaxStringLens::_enum_len_type arg)
  {
    msg_.enum_len = std::move(arg);
    return Init_MaxStringLens_load_id_len(msg_);
  }

private:
  ::vda5050_msgs::msg::MaxStringLens msg_;
};

class Init_MaxStringLens_id_numerical_only
{
public:
  explicit Init_MaxStringLens_id_numerical_only(::vda5050_msgs::msg::MaxStringLens & msg)
  : msg_(msg)
  {}
  Init_MaxStringLens_enum_len id_numerical_only(::vda5050_msgs::msg::MaxStringLens::_id_numerical_only_type arg)
  {
    msg_.id_numerical_only = std::move(arg);
    return Init_MaxStringLens_enum_len(msg_);
  }

private:
  ::vda5050_msgs::msg::MaxStringLens msg_;
};

class Init_MaxStringLens_id_len
{
public:
  explicit Init_MaxStringLens_id_len(::vda5050_msgs::msg::MaxStringLens & msg)
  : msg_(msg)
  {}
  Init_MaxStringLens_id_numerical_only id_len(::vda5050_msgs::msg::MaxStringLens::_id_len_type arg)
  {
    msg_.id_len = std::move(arg);
    return Init_MaxStringLens_id_numerical_only(msg_);
  }

private:
  ::vda5050_msgs::msg::MaxStringLens msg_;
};

class Init_MaxStringLens_topic_elem_len
{
public:
  explicit Init_MaxStringLens_topic_elem_len(::vda5050_msgs::msg::MaxStringLens & msg)
  : msg_(msg)
  {}
  Init_MaxStringLens_id_len topic_elem_len(::vda5050_msgs::msg::MaxStringLens::_topic_elem_len_type arg)
  {
    msg_.topic_elem_len = std::move(arg);
    return Init_MaxStringLens_id_len(msg_);
  }

private:
  ::vda5050_msgs::msg::MaxStringLens msg_;
};

class Init_MaxStringLens_topic_serial_len
{
public:
  explicit Init_MaxStringLens_topic_serial_len(::vda5050_msgs::msg::MaxStringLens & msg)
  : msg_(msg)
  {}
  Init_MaxStringLens_topic_elem_len topic_serial_len(::vda5050_msgs::msg::MaxStringLens::_topic_serial_len_type arg)
  {
    msg_.topic_serial_len = std::move(arg);
    return Init_MaxStringLens_topic_elem_len(msg_);
  }

private:
  ::vda5050_msgs::msg::MaxStringLens msg_;
};

class Init_MaxStringLens_msg_len
{
public:
  Init_MaxStringLens_msg_len()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MaxStringLens_topic_serial_len msg_len(::vda5050_msgs::msg::MaxStringLens::_msg_len_type arg)
  {
    msg_.msg_len = std::move(arg);
    return Init_MaxStringLens_topic_serial_len(msg_);
  }

private:
  ::vda5050_msgs::msg::MaxStringLens msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vda5050_msgs::msg::MaxStringLens>()
{
  return vda5050_msgs::msg::builder::Init_MaxStringLens_msg_len();
}

}  // namespace vda5050_msgs

#endif  // VDA5050_MSGS__MSG__DETAIL__MAX_STRING_LENS__BUILDER_HPP_
