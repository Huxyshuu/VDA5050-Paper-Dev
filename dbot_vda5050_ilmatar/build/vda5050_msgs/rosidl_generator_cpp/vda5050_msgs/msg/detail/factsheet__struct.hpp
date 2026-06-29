// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from vda5050_msgs:msg/Factsheet.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__FACTSHEET__STRUCT_HPP_
#define VDA5050_MSGS__MSG__DETAIL__FACTSHEET__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'type_specification'
#include "vda5050_msgs/msg/detail/type_specification__struct.hpp"
// Member 'physical_parameters'
#include "vda5050_msgs/msg/detail/physical_parameters__struct.hpp"
// Member 'protocol_limits'
#include "vda5050_msgs/msg/detail/protocol_limits__struct.hpp"
// Member 'protocol_features'
#include "vda5050_msgs/msg/detail/protocol_features__struct.hpp"
// Member 'agv_geometry'
#include "vda5050_msgs/msg/detail/agv_geometry__struct.hpp"
// Member 'load_specification'
#include "vda5050_msgs/msg/detail/load_specification__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__vda5050_msgs__msg__Factsheet __attribute__((deprecated))
#else
# define DEPRECATED__vda5050_msgs__msg__Factsheet __declspec(deprecated)
#endif

namespace vda5050_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Factsheet_
{
  using Type = Factsheet_<ContainerAllocator>;

  explicit Factsheet_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : type_specification(_init),
    physical_parameters(_init),
    protocol_limits(_init),
    protocol_features(_init),
    agv_geometry(_init),
    load_specification(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->header_id = 0ul;
      this->timestamp = "";
      this->version = "";
      this->manufacturer = "";
      this->serial_number = "";
      this->localization_parameters = 0l;
    }
  }

  explicit Factsheet_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : timestamp(_alloc),
    version(_alloc),
    manufacturer(_alloc),
    serial_number(_alloc),
    type_specification(_alloc, _init),
    physical_parameters(_alloc, _init),
    protocol_limits(_alloc, _init),
    protocol_features(_alloc, _init),
    agv_geometry(_alloc, _init),
    load_specification(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->header_id = 0ul;
      this->timestamp = "";
      this->version = "";
      this->manufacturer = "";
      this->serial_number = "";
      this->localization_parameters = 0l;
    }
  }

  // field types and members
  using _header_id_type =
    uint32_t;
  _header_id_type header_id;
  using _timestamp_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _timestamp_type timestamp;
  using _version_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _version_type version;
  using _manufacturer_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _manufacturer_type manufacturer;
  using _serial_number_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _serial_number_type serial_number;
  using _type_specification_type =
    vda5050_msgs::msg::TypeSpecification_<ContainerAllocator>;
  _type_specification_type type_specification;
  using _physical_parameters_type =
    vda5050_msgs::msg::PhysicalParameters_<ContainerAllocator>;
  _physical_parameters_type physical_parameters;
  using _protocol_limits_type =
    vda5050_msgs::msg::ProtocolLimits_<ContainerAllocator>;
  _protocol_limits_type protocol_limits;
  using _protocol_features_type =
    vda5050_msgs::msg::ProtocolFeatures_<ContainerAllocator>;
  _protocol_features_type protocol_features;
  using _agv_geometry_type =
    vda5050_msgs::msg::AGVGeometry_<ContainerAllocator>;
  _agv_geometry_type agv_geometry;
  using _load_specification_type =
    vda5050_msgs::msg::LoadSpecification_<ContainerAllocator>;
  _load_specification_type load_specification;
  using _localization_parameters_type =
    int32_t;
  _localization_parameters_type localization_parameters;

  // setters for named parameter idiom
  Type & set__header_id(
    const uint32_t & _arg)
  {
    this->header_id = _arg;
    return *this;
  }
  Type & set__timestamp(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->timestamp = _arg;
    return *this;
  }
  Type & set__version(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->version = _arg;
    return *this;
  }
  Type & set__manufacturer(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->manufacturer = _arg;
    return *this;
  }
  Type & set__serial_number(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->serial_number = _arg;
    return *this;
  }
  Type & set__type_specification(
    const vda5050_msgs::msg::TypeSpecification_<ContainerAllocator> & _arg)
  {
    this->type_specification = _arg;
    return *this;
  }
  Type & set__physical_parameters(
    const vda5050_msgs::msg::PhysicalParameters_<ContainerAllocator> & _arg)
  {
    this->physical_parameters = _arg;
    return *this;
  }
  Type & set__protocol_limits(
    const vda5050_msgs::msg::ProtocolLimits_<ContainerAllocator> & _arg)
  {
    this->protocol_limits = _arg;
    return *this;
  }
  Type & set__protocol_features(
    const vda5050_msgs::msg::ProtocolFeatures_<ContainerAllocator> & _arg)
  {
    this->protocol_features = _arg;
    return *this;
  }
  Type & set__agv_geometry(
    const vda5050_msgs::msg::AGVGeometry_<ContainerAllocator> & _arg)
  {
    this->agv_geometry = _arg;
    return *this;
  }
  Type & set__load_specification(
    const vda5050_msgs::msg::LoadSpecification_<ContainerAllocator> & _arg)
  {
    this->load_specification = _arg;
    return *this;
  }
  Type & set__localization_parameters(
    const int32_t & _arg)
  {
    this->localization_parameters = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    vda5050_msgs::msg::Factsheet_<ContainerAllocator> *;
  using ConstRawPtr =
    const vda5050_msgs::msg::Factsheet_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vda5050_msgs::msg::Factsheet_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vda5050_msgs::msg::Factsheet_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vda5050_msgs::msg::Factsheet_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vda5050_msgs::msg::Factsheet_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vda5050_msgs::msg::Factsheet_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vda5050_msgs::msg::Factsheet_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vda5050_msgs::msg::Factsheet_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vda5050_msgs::msg::Factsheet_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vda5050_msgs__msg__Factsheet
    std::shared_ptr<vda5050_msgs::msg::Factsheet_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vda5050_msgs__msg__Factsheet
    std::shared_ptr<vda5050_msgs::msg::Factsheet_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Factsheet_ & other) const
  {
    if (this->header_id != other.header_id) {
      return false;
    }
    if (this->timestamp != other.timestamp) {
      return false;
    }
    if (this->version != other.version) {
      return false;
    }
    if (this->manufacturer != other.manufacturer) {
      return false;
    }
    if (this->serial_number != other.serial_number) {
      return false;
    }
    if (this->type_specification != other.type_specification) {
      return false;
    }
    if (this->physical_parameters != other.physical_parameters) {
      return false;
    }
    if (this->protocol_limits != other.protocol_limits) {
      return false;
    }
    if (this->protocol_features != other.protocol_features) {
      return false;
    }
    if (this->agv_geometry != other.agv_geometry) {
      return false;
    }
    if (this->load_specification != other.load_specification) {
      return false;
    }
    if (this->localization_parameters != other.localization_parameters) {
      return false;
    }
    return true;
  }
  bool operator!=(const Factsheet_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Factsheet_

// alias to use template instance with default allocator
using Factsheet =
  vda5050_msgs::msg::Factsheet_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace vda5050_msgs

#endif  // VDA5050_MSGS__MSG__DETAIL__FACTSHEET__STRUCT_HPP_
