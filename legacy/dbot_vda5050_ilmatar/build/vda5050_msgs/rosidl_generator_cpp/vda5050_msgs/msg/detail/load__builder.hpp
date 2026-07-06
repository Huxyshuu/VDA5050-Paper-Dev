// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vda5050_msgs:msg/Load.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__LOAD__BUILDER_HPP_
#define VDA5050_MSGS__MSG__DETAIL__LOAD__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vda5050_msgs/msg/detail/load__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vda5050_msgs
{

namespace msg
{

namespace builder
{

class Init_Load_weight
{
public:
  explicit Init_Load_weight(::vda5050_msgs::msg::Load & msg)
  : msg_(msg)
  {}
  ::vda5050_msgs::msg::Load weight(::vda5050_msgs::msg::Load::_weight_type arg)
  {
    msg_.weight = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vda5050_msgs::msg::Load msg_;
};

class Init_Load_load_dimensions
{
public:
  explicit Init_Load_load_dimensions(::vda5050_msgs::msg::Load & msg)
  : msg_(msg)
  {}
  Init_Load_weight load_dimensions(::vda5050_msgs::msg::Load::_load_dimensions_type arg)
  {
    msg_.load_dimensions = std::move(arg);
    return Init_Load_weight(msg_);
  }

private:
  ::vda5050_msgs::msg::Load msg_;
};

class Init_Load_bounding_box_reference
{
public:
  explicit Init_Load_bounding_box_reference(::vda5050_msgs::msg::Load & msg)
  : msg_(msg)
  {}
  Init_Load_load_dimensions bounding_box_reference(::vda5050_msgs::msg::Load::_bounding_box_reference_type arg)
  {
    msg_.bounding_box_reference = std::move(arg);
    return Init_Load_load_dimensions(msg_);
  }

private:
  ::vda5050_msgs::msg::Load msg_;
};

class Init_Load_load_position
{
public:
  explicit Init_Load_load_position(::vda5050_msgs::msg::Load & msg)
  : msg_(msg)
  {}
  Init_Load_bounding_box_reference load_position(::vda5050_msgs::msg::Load::_load_position_type arg)
  {
    msg_.load_position = std::move(arg);
    return Init_Load_bounding_box_reference(msg_);
  }

private:
  ::vda5050_msgs::msg::Load msg_;
};

class Init_Load_load_type
{
public:
  explicit Init_Load_load_type(::vda5050_msgs::msg::Load & msg)
  : msg_(msg)
  {}
  Init_Load_load_position load_type(::vda5050_msgs::msg::Load::_load_type_type arg)
  {
    msg_.load_type = std::move(arg);
    return Init_Load_load_position(msg_);
  }

private:
  ::vda5050_msgs::msg::Load msg_;
};

class Init_Load_load_id
{
public:
  Init_Load_load_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Load_load_type load_id(::vda5050_msgs::msg::Load::_load_id_type arg)
  {
    msg_.load_id = std::move(arg);
    return Init_Load_load_type(msg_);
  }

private:
  ::vda5050_msgs::msg::Load msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vda5050_msgs::msg::Load>()
{
  return vda5050_msgs::msg::builder::Init_Load_load_id();
}

}  // namespace vda5050_msgs

#endif  // VDA5050_MSGS__MSG__DETAIL__LOAD__BUILDER_HPP_
