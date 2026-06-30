// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vda5050_msgs:msg/Trajectory.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__TRAJECTORY__BUILDER_HPP_
#define VDA5050_MSGS__MSG__DETAIL__TRAJECTORY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vda5050_msgs/msg/detail/trajectory__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vda5050_msgs
{

namespace msg
{

namespace builder
{

class Init_Trajectory_control_points
{
public:
  explicit Init_Trajectory_control_points(::vda5050_msgs::msg::Trajectory & msg)
  : msg_(msg)
  {}
  ::vda5050_msgs::msg::Trajectory control_points(::vda5050_msgs::msg::Trajectory::_control_points_type arg)
  {
    msg_.control_points = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vda5050_msgs::msg::Trajectory msg_;
};

class Init_Trajectory_knot_vector
{
public:
  explicit Init_Trajectory_knot_vector(::vda5050_msgs::msg::Trajectory & msg)
  : msg_(msg)
  {}
  Init_Trajectory_control_points knot_vector(::vda5050_msgs::msg::Trajectory::_knot_vector_type arg)
  {
    msg_.knot_vector = std::move(arg);
    return Init_Trajectory_control_points(msg_);
  }

private:
  ::vda5050_msgs::msg::Trajectory msg_;
};

class Init_Trajectory_degree
{
public:
  Init_Trajectory_degree()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Trajectory_knot_vector degree(::vda5050_msgs::msg::Trajectory::_degree_type arg)
  {
    msg_.degree = std::move(arg);
    return Init_Trajectory_knot_vector(msg_);
  }

private:
  ::vda5050_msgs::msg::Trajectory msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vda5050_msgs::msg::Trajectory>()
{
  return vda5050_msgs::msg::builder::Init_Trajectory_degree();
}

}  // namespace vda5050_msgs

#endif  // VDA5050_MSGS__MSG__DETAIL__TRAJECTORY__BUILDER_HPP_
