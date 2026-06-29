// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vda5050_msgs:msg/Envelope2D.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__ENVELOPE2_D__BUILDER_HPP_
#define VDA5050_MSGS__MSG__DETAIL__ENVELOPE2_D__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vda5050_msgs/msg/detail/envelope2_d__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vda5050_msgs
{

namespace msg
{

namespace builder
{

class Init_Envelope2D_description
{
public:
  explicit Init_Envelope2D_description(::vda5050_msgs::msg::Envelope2D & msg)
  : msg_(msg)
  {}
  ::vda5050_msgs::msg::Envelope2D description(::vda5050_msgs::msg::Envelope2D::_description_type arg)
  {
    msg_.description = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vda5050_msgs::msg::Envelope2D msg_;
};

class Init_Envelope2D_polygon_points
{
public:
  explicit Init_Envelope2D_polygon_points(::vda5050_msgs::msg::Envelope2D & msg)
  : msg_(msg)
  {}
  Init_Envelope2D_description polygon_points(::vda5050_msgs::msg::Envelope2D::_polygon_points_type arg)
  {
    msg_.polygon_points = std::move(arg);
    return Init_Envelope2D_description(msg_);
  }

private:
  ::vda5050_msgs::msg::Envelope2D msg_;
};

class Init_Envelope2D_set
{
public:
  Init_Envelope2D_set()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Envelope2D_polygon_points set(::vda5050_msgs::msg::Envelope2D::_set_type arg)
  {
    msg_.set = std::move(arg);
    return Init_Envelope2D_polygon_points(msg_);
  }

private:
  ::vda5050_msgs::msg::Envelope2D msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vda5050_msgs::msg::Envelope2D>()
{
  return vda5050_msgs::msg::builder::Init_Envelope2D_set();
}

}  // namespace vda5050_msgs

#endif  // VDA5050_MSGS__MSG__DETAIL__ENVELOPE2_D__BUILDER_HPP_
