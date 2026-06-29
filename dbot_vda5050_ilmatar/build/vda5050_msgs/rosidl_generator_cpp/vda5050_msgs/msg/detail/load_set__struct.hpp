// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from vda5050_msgs:msg/LoadSet.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__LOAD_SET__STRUCT_HPP_
#define VDA5050_MSGS__MSG__DETAIL__LOAD_SET__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'bounding_box_reference'
#include "vda5050_msgs/msg/detail/bounding_box_reference__struct.hpp"
// Member 'load_dimensions'
#include "vda5050_msgs/msg/detail/load_dimensions__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__vda5050_msgs__msg__LoadSet __attribute__((deprecated))
#else
# define DEPRECATED__vda5050_msgs__msg__LoadSet __declspec(deprecated)
#endif

namespace vda5050_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct LoadSet_
{
  using Type = LoadSet_<ContainerAllocator>;

  explicit LoadSet_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : bounding_box_reference(_init),
    load_dimensions(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->set_name = "";
      this->load_type = "";
      this->max_weight = 0.0;
      this->min_loadhandling_height = 0.0;
      this->max_loadhandling_height = 0.0;
      this->min_loadhandling_depth = 0.0;
      this->max_loadhandling_depth = 0.0;
      this->min_loadhandling_tilt = 0.0;
      this->max_loadhandling_tilt = 0.0;
      this->agv_speed_limit = 0.0;
      this->agv_acceleration_limit = 0.0;
      this->agv_deceleration_limit = 0.0;
      this->pick_time = 0.0;
      this->drop_time = 0.0;
      this->description = "";
    }
  }

  explicit LoadSet_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : set_name(_alloc),
    load_type(_alloc),
    bounding_box_reference(_alloc, _init),
    load_dimensions(_alloc, _init),
    description(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->set_name = "";
      this->load_type = "";
      this->max_weight = 0.0;
      this->min_loadhandling_height = 0.0;
      this->max_loadhandling_height = 0.0;
      this->min_loadhandling_depth = 0.0;
      this->max_loadhandling_depth = 0.0;
      this->min_loadhandling_tilt = 0.0;
      this->max_loadhandling_tilt = 0.0;
      this->agv_speed_limit = 0.0;
      this->agv_acceleration_limit = 0.0;
      this->agv_deceleration_limit = 0.0;
      this->pick_time = 0.0;
      this->drop_time = 0.0;
      this->description = "";
    }
  }

  // field types and members
  using _set_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _set_name_type set_name;
  using _load_type_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _load_type_type load_type;
  using _load_positions_type =
    std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>>;
  _load_positions_type load_positions;
  using _bounding_box_reference_type =
    vda5050_msgs::msg::BoundingBoxReference_<ContainerAllocator>;
  _bounding_box_reference_type bounding_box_reference;
  using _load_dimensions_type =
    vda5050_msgs::msg::LoadDimensions_<ContainerAllocator>;
  _load_dimensions_type load_dimensions;
  using _max_weight_type =
    double;
  _max_weight_type max_weight;
  using _min_loadhandling_height_type =
    double;
  _min_loadhandling_height_type min_loadhandling_height;
  using _max_loadhandling_height_type =
    double;
  _max_loadhandling_height_type max_loadhandling_height;
  using _min_loadhandling_depth_type =
    double;
  _min_loadhandling_depth_type min_loadhandling_depth;
  using _max_loadhandling_depth_type =
    double;
  _max_loadhandling_depth_type max_loadhandling_depth;
  using _min_loadhandling_tilt_type =
    double;
  _min_loadhandling_tilt_type min_loadhandling_tilt;
  using _max_loadhandling_tilt_type =
    double;
  _max_loadhandling_tilt_type max_loadhandling_tilt;
  using _agv_speed_limit_type =
    double;
  _agv_speed_limit_type agv_speed_limit;
  using _agv_acceleration_limit_type =
    double;
  _agv_acceleration_limit_type agv_acceleration_limit;
  using _agv_deceleration_limit_type =
    double;
  _agv_deceleration_limit_type agv_deceleration_limit;
  using _pick_time_type =
    double;
  _pick_time_type pick_time;
  using _drop_time_type =
    double;
  _drop_time_type drop_time;
  using _description_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _description_type description;

  // setters for named parameter idiom
  Type & set__set_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->set_name = _arg;
    return *this;
  }
  Type & set__load_type(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->load_type = _arg;
    return *this;
  }
  Type & set__load_positions(
    const std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>> & _arg)
  {
    this->load_positions = _arg;
    return *this;
  }
  Type & set__bounding_box_reference(
    const vda5050_msgs::msg::BoundingBoxReference_<ContainerAllocator> & _arg)
  {
    this->bounding_box_reference = _arg;
    return *this;
  }
  Type & set__load_dimensions(
    const vda5050_msgs::msg::LoadDimensions_<ContainerAllocator> & _arg)
  {
    this->load_dimensions = _arg;
    return *this;
  }
  Type & set__max_weight(
    const double & _arg)
  {
    this->max_weight = _arg;
    return *this;
  }
  Type & set__min_loadhandling_height(
    const double & _arg)
  {
    this->min_loadhandling_height = _arg;
    return *this;
  }
  Type & set__max_loadhandling_height(
    const double & _arg)
  {
    this->max_loadhandling_height = _arg;
    return *this;
  }
  Type & set__min_loadhandling_depth(
    const double & _arg)
  {
    this->min_loadhandling_depth = _arg;
    return *this;
  }
  Type & set__max_loadhandling_depth(
    const double & _arg)
  {
    this->max_loadhandling_depth = _arg;
    return *this;
  }
  Type & set__min_loadhandling_tilt(
    const double & _arg)
  {
    this->min_loadhandling_tilt = _arg;
    return *this;
  }
  Type & set__max_loadhandling_tilt(
    const double & _arg)
  {
    this->max_loadhandling_tilt = _arg;
    return *this;
  }
  Type & set__agv_speed_limit(
    const double & _arg)
  {
    this->agv_speed_limit = _arg;
    return *this;
  }
  Type & set__agv_acceleration_limit(
    const double & _arg)
  {
    this->agv_acceleration_limit = _arg;
    return *this;
  }
  Type & set__agv_deceleration_limit(
    const double & _arg)
  {
    this->agv_deceleration_limit = _arg;
    return *this;
  }
  Type & set__pick_time(
    const double & _arg)
  {
    this->pick_time = _arg;
    return *this;
  }
  Type & set__drop_time(
    const double & _arg)
  {
    this->drop_time = _arg;
    return *this;
  }
  Type & set__description(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->description = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    vda5050_msgs::msg::LoadSet_<ContainerAllocator> *;
  using ConstRawPtr =
    const vda5050_msgs::msg::LoadSet_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vda5050_msgs::msg::LoadSet_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vda5050_msgs::msg::LoadSet_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vda5050_msgs::msg::LoadSet_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vda5050_msgs::msg::LoadSet_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vda5050_msgs::msg::LoadSet_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vda5050_msgs::msg::LoadSet_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vda5050_msgs::msg::LoadSet_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vda5050_msgs::msg::LoadSet_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vda5050_msgs__msg__LoadSet
    std::shared_ptr<vda5050_msgs::msg::LoadSet_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vda5050_msgs__msg__LoadSet
    std::shared_ptr<vda5050_msgs::msg::LoadSet_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const LoadSet_ & other) const
  {
    if (this->set_name != other.set_name) {
      return false;
    }
    if (this->load_type != other.load_type) {
      return false;
    }
    if (this->load_positions != other.load_positions) {
      return false;
    }
    if (this->bounding_box_reference != other.bounding_box_reference) {
      return false;
    }
    if (this->load_dimensions != other.load_dimensions) {
      return false;
    }
    if (this->max_weight != other.max_weight) {
      return false;
    }
    if (this->min_loadhandling_height != other.min_loadhandling_height) {
      return false;
    }
    if (this->max_loadhandling_height != other.max_loadhandling_height) {
      return false;
    }
    if (this->min_loadhandling_depth != other.min_loadhandling_depth) {
      return false;
    }
    if (this->max_loadhandling_depth != other.max_loadhandling_depth) {
      return false;
    }
    if (this->min_loadhandling_tilt != other.min_loadhandling_tilt) {
      return false;
    }
    if (this->max_loadhandling_tilt != other.max_loadhandling_tilt) {
      return false;
    }
    if (this->agv_speed_limit != other.agv_speed_limit) {
      return false;
    }
    if (this->agv_acceleration_limit != other.agv_acceleration_limit) {
      return false;
    }
    if (this->agv_deceleration_limit != other.agv_deceleration_limit) {
      return false;
    }
    if (this->pick_time != other.pick_time) {
      return false;
    }
    if (this->drop_time != other.drop_time) {
      return false;
    }
    if (this->description != other.description) {
      return false;
    }
    return true;
  }
  bool operator!=(const LoadSet_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct LoadSet_

// alias to use template instance with default allocator
using LoadSet =
  vda5050_msgs::msg::LoadSet_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace vda5050_msgs

#endif  // VDA5050_MSGS__MSG__DETAIL__LOAD_SET__STRUCT_HPP_
