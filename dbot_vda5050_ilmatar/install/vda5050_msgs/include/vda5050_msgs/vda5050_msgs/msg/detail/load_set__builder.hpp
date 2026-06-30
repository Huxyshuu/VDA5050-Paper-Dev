// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vda5050_msgs:msg/LoadSet.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__LOAD_SET__BUILDER_HPP_
#define VDA5050_MSGS__MSG__DETAIL__LOAD_SET__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vda5050_msgs/msg/detail/load_set__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vda5050_msgs
{

namespace msg
{

namespace builder
{

class Init_LoadSet_description
{
public:
  explicit Init_LoadSet_description(::vda5050_msgs::msg::LoadSet & msg)
  : msg_(msg)
  {}
  ::vda5050_msgs::msg::LoadSet description(::vda5050_msgs::msg::LoadSet::_description_type arg)
  {
    msg_.description = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vda5050_msgs::msg::LoadSet msg_;
};

class Init_LoadSet_drop_time
{
public:
  explicit Init_LoadSet_drop_time(::vda5050_msgs::msg::LoadSet & msg)
  : msg_(msg)
  {}
  Init_LoadSet_description drop_time(::vda5050_msgs::msg::LoadSet::_drop_time_type arg)
  {
    msg_.drop_time = std::move(arg);
    return Init_LoadSet_description(msg_);
  }

private:
  ::vda5050_msgs::msg::LoadSet msg_;
};

class Init_LoadSet_pick_time
{
public:
  explicit Init_LoadSet_pick_time(::vda5050_msgs::msg::LoadSet & msg)
  : msg_(msg)
  {}
  Init_LoadSet_drop_time pick_time(::vda5050_msgs::msg::LoadSet::_pick_time_type arg)
  {
    msg_.pick_time = std::move(arg);
    return Init_LoadSet_drop_time(msg_);
  }

private:
  ::vda5050_msgs::msg::LoadSet msg_;
};

class Init_LoadSet_agv_deceleration_limit
{
public:
  explicit Init_LoadSet_agv_deceleration_limit(::vda5050_msgs::msg::LoadSet & msg)
  : msg_(msg)
  {}
  Init_LoadSet_pick_time agv_deceleration_limit(::vda5050_msgs::msg::LoadSet::_agv_deceleration_limit_type arg)
  {
    msg_.agv_deceleration_limit = std::move(arg);
    return Init_LoadSet_pick_time(msg_);
  }

private:
  ::vda5050_msgs::msg::LoadSet msg_;
};

class Init_LoadSet_agv_acceleration_limit
{
public:
  explicit Init_LoadSet_agv_acceleration_limit(::vda5050_msgs::msg::LoadSet & msg)
  : msg_(msg)
  {}
  Init_LoadSet_agv_deceleration_limit agv_acceleration_limit(::vda5050_msgs::msg::LoadSet::_agv_acceleration_limit_type arg)
  {
    msg_.agv_acceleration_limit = std::move(arg);
    return Init_LoadSet_agv_deceleration_limit(msg_);
  }

private:
  ::vda5050_msgs::msg::LoadSet msg_;
};

class Init_LoadSet_agv_speed_limit
{
public:
  explicit Init_LoadSet_agv_speed_limit(::vda5050_msgs::msg::LoadSet & msg)
  : msg_(msg)
  {}
  Init_LoadSet_agv_acceleration_limit agv_speed_limit(::vda5050_msgs::msg::LoadSet::_agv_speed_limit_type arg)
  {
    msg_.agv_speed_limit = std::move(arg);
    return Init_LoadSet_agv_acceleration_limit(msg_);
  }

private:
  ::vda5050_msgs::msg::LoadSet msg_;
};

class Init_LoadSet_max_loadhandling_tilt
{
public:
  explicit Init_LoadSet_max_loadhandling_tilt(::vda5050_msgs::msg::LoadSet & msg)
  : msg_(msg)
  {}
  Init_LoadSet_agv_speed_limit max_loadhandling_tilt(::vda5050_msgs::msg::LoadSet::_max_loadhandling_tilt_type arg)
  {
    msg_.max_loadhandling_tilt = std::move(arg);
    return Init_LoadSet_agv_speed_limit(msg_);
  }

private:
  ::vda5050_msgs::msg::LoadSet msg_;
};

class Init_LoadSet_min_loadhandling_tilt
{
public:
  explicit Init_LoadSet_min_loadhandling_tilt(::vda5050_msgs::msg::LoadSet & msg)
  : msg_(msg)
  {}
  Init_LoadSet_max_loadhandling_tilt min_loadhandling_tilt(::vda5050_msgs::msg::LoadSet::_min_loadhandling_tilt_type arg)
  {
    msg_.min_loadhandling_tilt = std::move(arg);
    return Init_LoadSet_max_loadhandling_tilt(msg_);
  }

private:
  ::vda5050_msgs::msg::LoadSet msg_;
};

class Init_LoadSet_max_loadhandling_depth
{
public:
  explicit Init_LoadSet_max_loadhandling_depth(::vda5050_msgs::msg::LoadSet & msg)
  : msg_(msg)
  {}
  Init_LoadSet_min_loadhandling_tilt max_loadhandling_depth(::vda5050_msgs::msg::LoadSet::_max_loadhandling_depth_type arg)
  {
    msg_.max_loadhandling_depth = std::move(arg);
    return Init_LoadSet_min_loadhandling_tilt(msg_);
  }

private:
  ::vda5050_msgs::msg::LoadSet msg_;
};

class Init_LoadSet_min_loadhandling_depth
{
public:
  explicit Init_LoadSet_min_loadhandling_depth(::vda5050_msgs::msg::LoadSet & msg)
  : msg_(msg)
  {}
  Init_LoadSet_max_loadhandling_depth min_loadhandling_depth(::vda5050_msgs::msg::LoadSet::_min_loadhandling_depth_type arg)
  {
    msg_.min_loadhandling_depth = std::move(arg);
    return Init_LoadSet_max_loadhandling_depth(msg_);
  }

private:
  ::vda5050_msgs::msg::LoadSet msg_;
};

class Init_LoadSet_max_loadhandling_height
{
public:
  explicit Init_LoadSet_max_loadhandling_height(::vda5050_msgs::msg::LoadSet & msg)
  : msg_(msg)
  {}
  Init_LoadSet_min_loadhandling_depth max_loadhandling_height(::vda5050_msgs::msg::LoadSet::_max_loadhandling_height_type arg)
  {
    msg_.max_loadhandling_height = std::move(arg);
    return Init_LoadSet_min_loadhandling_depth(msg_);
  }

private:
  ::vda5050_msgs::msg::LoadSet msg_;
};

class Init_LoadSet_min_loadhandling_height
{
public:
  explicit Init_LoadSet_min_loadhandling_height(::vda5050_msgs::msg::LoadSet & msg)
  : msg_(msg)
  {}
  Init_LoadSet_max_loadhandling_height min_loadhandling_height(::vda5050_msgs::msg::LoadSet::_min_loadhandling_height_type arg)
  {
    msg_.min_loadhandling_height = std::move(arg);
    return Init_LoadSet_max_loadhandling_height(msg_);
  }

private:
  ::vda5050_msgs::msg::LoadSet msg_;
};

class Init_LoadSet_max_weight
{
public:
  explicit Init_LoadSet_max_weight(::vda5050_msgs::msg::LoadSet & msg)
  : msg_(msg)
  {}
  Init_LoadSet_min_loadhandling_height max_weight(::vda5050_msgs::msg::LoadSet::_max_weight_type arg)
  {
    msg_.max_weight = std::move(arg);
    return Init_LoadSet_min_loadhandling_height(msg_);
  }

private:
  ::vda5050_msgs::msg::LoadSet msg_;
};

class Init_LoadSet_load_dimensions
{
public:
  explicit Init_LoadSet_load_dimensions(::vda5050_msgs::msg::LoadSet & msg)
  : msg_(msg)
  {}
  Init_LoadSet_max_weight load_dimensions(::vda5050_msgs::msg::LoadSet::_load_dimensions_type arg)
  {
    msg_.load_dimensions = std::move(arg);
    return Init_LoadSet_max_weight(msg_);
  }

private:
  ::vda5050_msgs::msg::LoadSet msg_;
};

class Init_LoadSet_bounding_box_reference
{
public:
  explicit Init_LoadSet_bounding_box_reference(::vda5050_msgs::msg::LoadSet & msg)
  : msg_(msg)
  {}
  Init_LoadSet_load_dimensions bounding_box_reference(::vda5050_msgs::msg::LoadSet::_bounding_box_reference_type arg)
  {
    msg_.bounding_box_reference = std::move(arg);
    return Init_LoadSet_load_dimensions(msg_);
  }

private:
  ::vda5050_msgs::msg::LoadSet msg_;
};

class Init_LoadSet_load_positions
{
public:
  explicit Init_LoadSet_load_positions(::vda5050_msgs::msg::LoadSet & msg)
  : msg_(msg)
  {}
  Init_LoadSet_bounding_box_reference load_positions(::vda5050_msgs::msg::LoadSet::_load_positions_type arg)
  {
    msg_.load_positions = std::move(arg);
    return Init_LoadSet_bounding_box_reference(msg_);
  }

private:
  ::vda5050_msgs::msg::LoadSet msg_;
};

class Init_LoadSet_load_type
{
public:
  explicit Init_LoadSet_load_type(::vda5050_msgs::msg::LoadSet & msg)
  : msg_(msg)
  {}
  Init_LoadSet_load_positions load_type(::vda5050_msgs::msg::LoadSet::_load_type_type arg)
  {
    msg_.load_type = std::move(arg);
    return Init_LoadSet_load_positions(msg_);
  }

private:
  ::vda5050_msgs::msg::LoadSet msg_;
};

class Init_LoadSet_set_name
{
public:
  Init_LoadSet_set_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LoadSet_load_type set_name(::vda5050_msgs::msg::LoadSet::_set_name_type arg)
  {
    msg_.set_name = std::move(arg);
    return Init_LoadSet_load_type(msg_);
  }

private:
  ::vda5050_msgs::msg::LoadSet msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vda5050_msgs::msg::LoadSet>()
{
  return vda5050_msgs::msg::builder::Init_LoadSet_set_name();
}

}  // namespace vda5050_msgs

#endif  // VDA5050_MSGS__MSG__DETAIL__LOAD_SET__BUILDER_HPP_
