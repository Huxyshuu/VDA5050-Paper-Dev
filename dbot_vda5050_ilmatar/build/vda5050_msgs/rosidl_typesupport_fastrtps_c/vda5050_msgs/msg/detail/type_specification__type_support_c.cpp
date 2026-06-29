// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from vda5050_msgs:msg/TypeSpecification.idl
// generated code does not contain a copyright notice
#include "vda5050_msgs/msg/detail/type_specification__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "vda5050_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "vda5050_msgs/msg/detail/type_specification__struct.h"
#include "vda5050_msgs/msg/detail/type_specification__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/string.h"  // agv_class, agv_kinematic, localization_types, navigation_types, series_description, series_name
#include "rosidl_runtime_c/string_functions.h"  // agv_class, agv_kinematic, localization_types, navigation_types, series_description, series_name

// forward declare type support functions


using _TypeSpecification__ros_msg_type = vda5050_msgs__msg__TypeSpecification;

static bool _TypeSpecification__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _TypeSpecification__ros_msg_type * ros_message = static_cast<const _TypeSpecification__ros_msg_type *>(untyped_ros_message);
  // Field name: series_name
  {
    const rosidl_runtime_c__String * str = &ros_message->series_name;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: series_description
  {
    const rosidl_runtime_c__String * str = &ros_message->series_description;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: agv_kinematic
  {
    const rosidl_runtime_c__String * str = &ros_message->agv_kinematic;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: agv_class
  {
    const rosidl_runtime_c__String * str = &ros_message->agv_class;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: max_load_mass
  {
    cdr << ros_message->max_load_mass;
  }

  // Field name: localization_types
  {
    size_t size = ros_message->localization_types.size;
    auto array_ptr = ros_message->localization_types.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      const rosidl_runtime_c__String * str = &array_ptr[i];
      if (str->capacity == 0 || str->capacity <= str->size) {
        fprintf(stderr, "string capacity not greater than size\n");
        return false;
      }
      if (str->data[str->size] != '\0') {
        fprintf(stderr, "string not null-terminated\n");
        return false;
      }
      cdr << str->data;
    }
  }

  // Field name: navigation_types
  {
    size_t size = ros_message->navigation_types.size;
    auto array_ptr = ros_message->navigation_types.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      const rosidl_runtime_c__String * str = &array_ptr[i];
      if (str->capacity == 0 || str->capacity <= str->size) {
        fprintf(stderr, "string capacity not greater than size\n");
        return false;
      }
      if (str->data[str->size] != '\0') {
        fprintf(stderr, "string not null-terminated\n");
        return false;
      }
      cdr << str->data;
    }
  }

  return true;
}

static bool _TypeSpecification__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _TypeSpecification__ros_msg_type * ros_message = static_cast<_TypeSpecification__ros_msg_type *>(untyped_ros_message);
  // Field name: series_name
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->series_name.data) {
      rosidl_runtime_c__String__init(&ros_message->series_name);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->series_name,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'series_name'\n");
      return false;
    }
  }

  // Field name: series_description
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->series_description.data) {
      rosidl_runtime_c__String__init(&ros_message->series_description);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->series_description,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'series_description'\n");
      return false;
    }
  }

  // Field name: agv_kinematic
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->agv_kinematic.data) {
      rosidl_runtime_c__String__init(&ros_message->agv_kinematic);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->agv_kinematic,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'agv_kinematic'\n");
      return false;
    }
  }

  // Field name: agv_class
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->agv_class.data) {
      rosidl_runtime_c__String__init(&ros_message->agv_class);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->agv_class,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'agv_class'\n");
      return false;
    }
  }

  // Field name: max_load_mass
  {
    cdr >> ros_message->max_load_mass;
  }

  // Field name: localization_types
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->localization_types.data) {
      rosidl_runtime_c__String__Sequence__fini(&ros_message->localization_types);
    }
    if (!rosidl_runtime_c__String__Sequence__init(&ros_message->localization_types, size)) {
      fprintf(stderr, "failed to create array for field 'localization_types'");
      return false;
    }
    auto array_ptr = ros_message->localization_types.data;
    for (size_t i = 0; i < size; ++i) {
      std::string tmp;
      cdr >> tmp;
      auto & ros_i = array_ptr[i];
      if (!ros_i.data) {
        rosidl_runtime_c__String__init(&ros_i);
      }
      bool succeeded = rosidl_runtime_c__String__assign(
        &ros_i,
        tmp.c_str());
      if (!succeeded) {
        fprintf(stderr, "failed to assign string into field 'localization_types'\n");
        return false;
      }
    }
  }

  // Field name: navigation_types
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->navigation_types.data) {
      rosidl_runtime_c__String__Sequence__fini(&ros_message->navigation_types);
    }
    if (!rosidl_runtime_c__String__Sequence__init(&ros_message->navigation_types, size)) {
      fprintf(stderr, "failed to create array for field 'navigation_types'");
      return false;
    }
    auto array_ptr = ros_message->navigation_types.data;
    for (size_t i = 0; i < size; ++i) {
      std::string tmp;
      cdr >> tmp;
      auto & ros_i = array_ptr[i];
      if (!ros_i.data) {
        rosidl_runtime_c__String__init(&ros_i);
      }
      bool succeeded = rosidl_runtime_c__String__assign(
        &ros_i,
        tmp.c_str());
      if (!succeeded) {
        fprintf(stderr, "failed to assign string into field 'navigation_types'\n");
        return false;
      }
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_vda5050_msgs
size_t get_serialized_size_vda5050_msgs__msg__TypeSpecification(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _TypeSpecification__ros_msg_type * ros_message = static_cast<const _TypeSpecification__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name series_name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->series_name.size + 1);
  // field.name series_description
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->series_description.size + 1);
  // field.name agv_kinematic
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->agv_kinematic.size + 1);
  // field.name agv_class
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->agv_class.size + 1);
  // field.name max_load_mass
  {
    size_t item_size = sizeof(ros_message->max_load_mass);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name localization_types
  {
    size_t array_size = ros_message->localization_types.size;
    auto array_ptr = ros_message->localization_types.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        (array_ptr[index].size + 1);
    }
  }
  // field.name navigation_types
  {
    size_t array_size = ros_message->navigation_types.size;
    auto array_ptr = ros_message->navigation_types.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        (array_ptr[index].size + 1);
    }
  }

  return current_alignment - initial_alignment;
}

static uint32_t _TypeSpecification__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_vda5050_msgs__msg__TypeSpecification(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_vda5050_msgs
size_t max_serialized_size_vda5050_msgs__msg__TypeSpecification(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: series_name
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: series_description
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: agv_kinematic
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: agv_class
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: max_load_mass
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: localization_types
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: navigation_types
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = vda5050_msgs__msg__TypeSpecification;
    is_plain =
      (
      offsetof(DataType, navigation_types) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _TypeSpecification__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_vda5050_msgs__msg__TypeSpecification(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_TypeSpecification = {
  "vda5050_msgs::msg",
  "TypeSpecification",
  _TypeSpecification__cdr_serialize,
  _TypeSpecification__cdr_deserialize,
  _TypeSpecification__get_serialized_size,
  _TypeSpecification__max_serialized_size
};

static rosidl_message_type_support_t _TypeSpecification__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_TypeSpecification,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, vda5050_msgs, msg, TypeSpecification)() {
  return &_TypeSpecification__type_support;
}

#if defined(__cplusplus)
}
#endif
