// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from vda5050_connector:action/NavigateToNode.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "vda5050_connector/action/detail/navigate_to_node__rosidl_typesupport_introspection_c.h"
#include "vda5050_connector/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "vda5050_connector/action/detail/navigate_to_node__functions.h"
#include "vda5050_connector/action/detail/navigate_to_node__struct.h"


// Include directives for member types
// Member `edge`
#include "vda5050_msgs/msg/edge.h"
// Member `edge`
#include "vda5050_msgs/msg/detail/edge__rosidl_typesupport_introspection_c.h"
// Member `node`
#include "vda5050_msgs/msg/node.h"
// Member `node`
#include "vda5050_msgs/msg/detail/node__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void vda5050_connector__action__NavigateToNode_Goal__rosidl_typesupport_introspection_c__NavigateToNode_Goal_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  vda5050_connector__action__NavigateToNode_Goal__init(message_memory);
}

void vda5050_connector__action__NavigateToNode_Goal__rosidl_typesupport_introspection_c__NavigateToNode_Goal_fini_function(void * message_memory)
{
  vda5050_connector__action__NavigateToNode_Goal__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember vda5050_connector__action__NavigateToNode_Goal__rosidl_typesupport_introspection_c__NavigateToNode_Goal_message_member_array[2] = {
  {
    "edge",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_connector__action__NavigateToNode_Goal, edge),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "node",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_connector__action__NavigateToNode_Goal, node),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers vda5050_connector__action__NavigateToNode_Goal__rosidl_typesupport_introspection_c__NavigateToNode_Goal_message_members = {
  "vda5050_connector__action",  // message namespace
  "NavigateToNode_Goal",  // message name
  2,  // number of fields
  sizeof(vda5050_connector__action__NavigateToNode_Goal),
  vda5050_connector__action__NavigateToNode_Goal__rosidl_typesupport_introspection_c__NavigateToNode_Goal_message_member_array,  // message members
  vda5050_connector__action__NavigateToNode_Goal__rosidl_typesupport_introspection_c__NavigateToNode_Goal_init_function,  // function to initialize message memory (memory has to be allocated)
  vda5050_connector__action__NavigateToNode_Goal__rosidl_typesupport_introspection_c__NavigateToNode_Goal_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t vda5050_connector__action__NavigateToNode_Goal__rosidl_typesupport_introspection_c__NavigateToNode_Goal_message_type_support_handle = {
  0,
  &vda5050_connector__action__NavigateToNode_Goal__rosidl_typesupport_introspection_c__NavigateToNode_Goal_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_vda5050_connector
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vda5050_connector, action, NavigateToNode_Goal)() {
  vda5050_connector__action__NavigateToNode_Goal__rosidl_typesupport_introspection_c__NavigateToNode_Goal_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vda5050_msgs, msg, Edge)();
  vda5050_connector__action__NavigateToNode_Goal__rosidl_typesupport_introspection_c__NavigateToNode_Goal_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vda5050_msgs, msg, Node)();
  if (!vda5050_connector__action__NavigateToNode_Goal__rosidl_typesupport_introspection_c__NavigateToNode_Goal_message_type_support_handle.typesupport_identifier) {
    vda5050_connector__action__NavigateToNode_Goal__rosidl_typesupport_introspection_c__NavigateToNode_Goal_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &vda5050_connector__action__NavigateToNode_Goal__rosidl_typesupport_introspection_c__NavigateToNode_Goal_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "vda5050_connector/action/detail/navigate_to_node__rosidl_typesupport_introspection_c.h"
// already included above
// #include "vda5050_connector/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "vda5050_connector/action/detail/navigate_to_node__functions.h"
// already included above
// #include "vda5050_connector/action/detail/navigate_to_node__struct.h"


// Include directives for member types
// Member `result`
#include "std_msgs/msg/empty.h"
// Member `result`
#include "std_msgs/msg/detail/empty__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void vda5050_connector__action__NavigateToNode_Result__rosidl_typesupport_introspection_c__NavigateToNode_Result_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  vda5050_connector__action__NavigateToNode_Result__init(message_memory);
}

void vda5050_connector__action__NavigateToNode_Result__rosidl_typesupport_introspection_c__NavigateToNode_Result_fini_function(void * message_memory)
{
  vda5050_connector__action__NavigateToNode_Result__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember vda5050_connector__action__NavigateToNode_Result__rosidl_typesupport_introspection_c__NavigateToNode_Result_message_member_array[1] = {
  {
    "result",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_connector__action__NavigateToNode_Result, result),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers vda5050_connector__action__NavigateToNode_Result__rosidl_typesupport_introspection_c__NavigateToNode_Result_message_members = {
  "vda5050_connector__action",  // message namespace
  "NavigateToNode_Result",  // message name
  1,  // number of fields
  sizeof(vda5050_connector__action__NavigateToNode_Result),
  vda5050_connector__action__NavigateToNode_Result__rosidl_typesupport_introspection_c__NavigateToNode_Result_message_member_array,  // message members
  vda5050_connector__action__NavigateToNode_Result__rosidl_typesupport_introspection_c__NavigateToNode_Result_init_function,  // function to initialize message memory (memory has to be allocated)
  vda5050_connector__action__NavigateToNode_Result__rosidl_typesupport_introspection_c__NavigateToNode_Result_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t vda5050_connector__action__NavigateToNode_Result__rosidl_typesupport_introspection_c__NavigateToNode_Result_message_type_support_handle = {
  0,
  &vda5050_connector__action__NavigateToNode_Result__rosidl_typesupport_introspection_c__NavigateToNode_Result_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_vda5050_connector
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vda5050_connector, action, NavigateToNode_Result)() {
  vda5050_connector__action__NavigateToNode_Result__rosidl_typesupport_introspection_c__NavigateToNode_Result_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Empty)();
  if (!vda5050_connector__action__NavigateToNode_Result__rosidl_typesupport_introspection_c__NavigateToNode_Result_message_type_support_handle.typesupport_identifier) {
    vda5050_connector__action__NavigateToNode_Result__rosidl_typesupport_introspection_c__NavigateToNode_Result_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &vda5050_connector__action__NavigateToNode_Result__rosidl_typesupport_introspection_c__NavigateToNode_Result_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "vda5050_connector/action/detail/navigate_to_node__rosidl_typesupport_introspection_c.h"
// already included above
// #include "vda5050_connector/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "vda5050_connector/action/detail/navigate_to_node__functions.h"
// already included above
// #include "vda5050_connector/action/detail/navigate_to_node__struct.h"


// Include directives for member types
// Member `position`
#include "vda5050_msgs/msg/agv_position.h"
// Member `position`
#include "vda5050_msgs/msg/detail/agv_position__rosidl_typesupport_introspection_c.h"
// Member `velocity`
#include "vda5050_msgs/msg/velocity.h"
// Member `velocity`
#include "vda5050_msgs/msg/detail/velocity__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void vda5050_connector__action__NavigateToNode_Feedback__rosidl_typesupport_introspection_c__NavigateToNode_Feedback_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  vda5050_connector__action__NavigateToNode_Feedback__init(message_memory);
}

void vda5050_connector__action__NavigateToNode_Feedback__rosidl_typesupport_introspection_c__NavigateToNode_Feedback_fini_function(void * message_memory)
{
  vda5050_connector__action__NavigateToNode_Feedback__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember vda5050_connector__action__NavigateToNode_Feedback__rosidl_typesupport_introspection_c__NavigateToNode_Feedback_message_member_array[2] = {
  {
    "position",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_connector__action__NavigateToNode_Feedback, position),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "velocity",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_connector__action__NavigateToNode_Feedback, velocity),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers vda5050_connector__action__NavigateToNode_Feedback__rosidl_typesupport_introspection_c__NavigateToNode_Feedback_message_members = {
  "vda5050_connector__action",  // message namespace
  "NavigateToNode_Feedback",  // message name
  2,  // number of fields
  sizeof(vda5050_connector__action__NavigateToNode_Feedback),
  vda5050_connector__action__NavigateToNode_Feedback__rosidl_typesupport_introspection_c__NavigateToNode_Feedback_message_member_array,  // message members
  vda5050_connector__action__NavigateToNode_Feedback__rosidl_typesupport_introspection_c__NavigateToNode_Feedback_init_function,  // function to initialize message memory (memory has to be allocated)
  vda5050_connector__action__NavigateToNode_Feedback__rosidl_typesupport_introspection_c__NavigateToNode_Feedback_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t vda5050_connector__action__NavigateToNode_Feedback__rosidl_typesupport_introspection_c__NavigateToNode_Feedback_message_type_support_handle = {
  0,
  &vda5050_connector__action__NavigateToNode_Feedback__rosidl_typesupport_introspection_c__NavigateToNode_Feedback_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_vda5050_connector
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vda5050_connector, action, NavigateToNode_Feedback)() {
  vda5050_connector__action__NavigateToNode_Feedback__rosidl_typesupport_introspection_c__NavigateToNode_Feedback_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vda5050_msgs, msg, AGVPosition)();
  vda5050_connector__action__NavigateToNode_Feedback__rosidl_typesupport_introspection_c__NavigateToNode_Feedback_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vda5050_msgs, msg, Velocity)();
  if (!vda5050_connector__action__NavigateToNode_Feedback__rosidl_typesupport_introspection_c__NavigateToNode_Feedback_message_type_support_handle.typesupport_identifier) {
    vda5050_connector__action__NavigateToNode_Feedback__rosidl_typesupport_introspection_c__NavigateToNode_Feedback_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &vda5050_connector__action__NavigateToNode_Feedback__rosidl_typesupport_introspection_c__NavigateToNode_Feedback_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "vda5050_connector/action/detail/navigate_to_node__rosidl_typesupport_introspection_c.h"
// already included above
// #include "vda5050_connector/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "vda5050_connector/action/detail/navigate_to_node__functions.h"
// already included above
// #include "vda5050_connector/action/detail/navigate_to_node__struct.h"


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"
// Member `goal`
#include "vda5050_connector/action/navigate_to_node.h"
// Member `goal`
// already included above
// #include "vda5050_connector/action/detail/navigate_to_node__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void vda5050_connector__action__NavigateToNode_SendGoal_Request__rosidl_typesupport_introspection_c__NavigateToNode_SendGoal_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  vda5050_connector__action__NavigateToNode_SendGoal_Request__init(message_memory);
}

void vda5050_connector__action__NavigateToNode_SendGoal_Request__rosidl_typesupport_introspection_c__NavigateToNode_SendGoal_Request_fini_function(void * message_memory)
{
  vda5050_connector__action__NavigateToNode_SendGoal_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember vda5050_connector__action__NavigateToNode_SendGoal_Request__rosidl_typesupport_introspection_c__NavigateToNode_SendGoal_Request_message_member_array[2] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_connector__action__NavigateToNode_SendGoal_Request, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "goal",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_connector__action__NavigateToNode_SendGoal_Request, goal),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers vda5050_connector__action__NavigateToNode_SendGoal_Request__rosidl_typesupport_introspection_c__NavigateToNode_SendGoal_Request_message_members = {
  "vda5050_connector__action",  // message namespace
  "NavigateToNode_SendGoal_Request",  // message name
  2,  // number of fields
  sizeof(vda5050_connector__action__NavigateToNode_SendGoal_Request),
  vda5050_connector__action__NavigateToNode_SendGoal_Request__rosidl_typesupport_introspection_c__NavigateToNode_SendGoal_Request_message_member_array,  // message members
  vda5050_connector__action__NavigateToNode_SendGoal_Request__rosidl_typesupport_introspection_c__NavigateToNode_SendGoal_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  vda5050_connector__action__NavigateToNode_SendGoal_Request__rosidl_typesupport_introspection_c__NavigateToNode_SendGoal_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t vda5050_connector__action__NavigateToNode_SendGoal_Request__rosidl_typesupport_introspection_c__NavigateToNode_SendGoal_Request_message_type_support_handle = {
  0,
  &vda5050_connector__action__NavigateToNode_SendGoal_Request__rosidl_typesupport_introspection_c__NavigateToNode_SendGoal_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_vda5050_connector
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vda5050_connector, action, NavigateToNode_SendGoal_Request)() {
  vda5050_connector__action__NavigateToNode_SendGoal_Request__rosidl_typesupport_introspection_c__NavigateToNode_SendGoal_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  vda5050_connector__action__NavigateToNode_SendGoal_Request__rosidl_typesupport_introspection_c__NavigateToNode_SendGoal_Request_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vda5050_connector, action, NavigateToNode_Goal)();
  if (!vda5050_connector__action__NavigateToNode_SendGoal_Request__rosidl_typesupport_introspection_c__NavigateToNode_SendGoal_Request_message_type_support_handle.typesupport_identifier) {
    vda5050_connector__action__NavigateToNode_SendGoal_Request__rosidl_typesupport_introspection_c__NavigateToNode_SendGoal_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &vda5050_connector__action__NavigateToNode_SendGoal_Request__rosidl_typesupport_introspection_c__NavigateToNode_SendGoal_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "vda5050_connector/action/detail/navigate_to_node__rosidl_typesupport_introspection_c.h"
// already included above
// #include "vda5050_connector/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "vda5050_connector/action/detail/navigate_to_node__functions.h"
// already included above
// #include "vda5050_connector/action/detail/navigate_to_node__struct.h"


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/time.h"
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void vda5050_connector__action__NavigateToNode_SendGoal_Response__rosidl_typesupport_introspection_c__NavigateToNode_SendGoal_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  vda5050_connector__action__NavigateToNode_SendGoal_Response__init(message_memory);
}

void vda5050_connector__action__NavigateToNode_SendGoal_Response__rosidl_typesupport_introspection_c__NavigateToNode_SendGoal_Response_fini_function(void * message_memory)
{
  vda5050_connector__action__NavigateToNode_SendGoal_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember vda5050_connector__action__NavigateToNode_SendGoal_Response__rosidl_typesupport_introspection_c__NavigateToNode_SendGoal_Response_message_member_array[2] = {
  {
    "accepted",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_connector__action__NavigateToNode_SendGoal_Response, accepted),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "stamp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_connector__action__NavigateToNode_SendGoal_Response, stamp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers vda5050_connector__action__NavigateToNode_SendGoal_Response__rosidl_typesupport_introspection_c__NavigateToNode_SendGoal_Response_message_members = {
  "vda5050_connector__action",  // message namespace
  "NavigateToNode_SendGoal_Response",  // message name
  2,  // number of fields
  sizeof(vda5050_connector__action__NavigateToNode_SendGoal_Response),
  vda5050_connector__action__NavigateToNode_SendGoal_Response__rosidl_typesupport_introspection_c__NavigateToNode_SendGoal_Response_message_member_array,  // message members
  vda5050_connector__action__NavigateToNode_SendGoal_Response__rosidl_typesupport_introspection_c__NavigateToNode_SendGoal_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  vda5050_connector__action__NavigateToNode_SendGoal_Response__rosidl_typesupport_introspection_c__NavigateToNode_SendGoal_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t vda5050_connector__action__NavigateToNode_SendGoal_Response__rosidl_typesupport_introspection_c__NavigateToNode_SendGoal_Response_message_type_support_handle = {
  0,
  &vda5050_connector__action__NavigateToNode_SendGoal_Response__rosidl_typesupport_introspection_c__NavigateToNode_SendGoal_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_vda5050_connector
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vda5050_connector, action, NavigateToNode_SendGoal_Response)() {
  vda5050_connector__action__NavigateToNode_SendGoal_Response__rosidl_typesupport_introspection_c__NavigateToNode_SendGoal_Response_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, builtin_interfaces, msg, Time)();
  if (!vda5050_connector__action__NavigateToNode_SendGoal_Response__rosidl_typesupport_introspection_c__NavigateToNode_SendGoal_Response_message_type_support_handle.typesupport_identifier) {
    vda5050_connector__action__NavigateToNode_SendGoal_Response__rosidl_typesupport_introspection_c__NavigateToNode_SendGoal_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &vda5050_connector__action__NavigateToNode_SendGoal_Response__rosidl_typesupport_introspection_c__NavigateToNode_SendGoal_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "vda5050_connector/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "vda5050_connector/action/detail/navigate_to_node__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers vda5050_connector__action__detail__navigate_to_node__rosidl_typesupport_introspection_c__NavigateToNode_SendGoal_service_members = {
  "vda5050_connector__action",  // service namespace
  "NavigateToNode_SendGoal",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // vda5050_connector__action__detail__navigate_to_node__rosidl_typesupport_introspection_c__NavigateToNode_SendGoal_Request_message_type_support_handle,
  NULL  // response message
  // vda5050_connector__action__detail__navigate_to_node__rosidl_typesupport_introspection_c__NavigateToNode_SendGoal_Response_message_type_support_handle
};

static rosidl_service_type_support_t vda5050_connector__action__detail__navigate_to_node__rosidl_typesupport_introspection_c__NavigateToNode_SendGoal_service_type_support_handle = {
  0,
  &vda5050_connector__action__detail__navigate_to_node__rosidl_typesupport_introspection_c__NavigateToNode_SendGoal_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vda5050_connector, action, NavigateToNode_SendGoal_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vda5050_connector, action, NavigateToNode_SendGoal_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_vda5050_connector
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vda5050_connector, action, NavigateToNode_SendGoal)() {
  if (!vda5050_connector__action__detail__navigate_to_node__rosidl_typesupport_introspection_c__NavigateToNode_SendGoal_service_type_support_handle.typesupport_identifier) {
    vda5050_connector__action__detail__navigate_to_node__rosidl_typesupport_introspection_c__NavigateToNode_SendGoal_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)vda5050_connector__action__detail__navigate_to_node__rosidl_typesupport_introspection_c__NavigateToNode_SendGoal_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vda5050_connector, action, NavigateToNode_SendGoal_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vda5050_connector, action, NavigateToNode_SendGoal_Response)()->data;
  }

  return &vda5050_connector__action__detail__navigate_to_node__rosidl_typesupport_introspection_c__NavigateToNode_SendGoal_service_type_support_handle;
}

// already included above
// #include <stddef.h>
// already included above
// #include "vda5050_connector/action/detail/navigate_to_node__rosidl_typesupport_introspection_c.h"
// already included above
// #include "vda5050_connector/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "vda5050_connector/action/detail/navigate_to_node__functions.h"
// already included above
// #include "vda5050_connector/action/detail/navigate_to_node__struct.h"


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void vda5050_connector__action__NavigateToNode_GetResult_Request__rosidl_typesupport_introspection_c__NavigateToNode_GetResult_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  vda5050_connector__action__NavigateToNode_GetResult_Request__init(message_memory);
}

void vda5050_connector__action__NavigateToNode_GetResult_Request__rosidl_typesupport_introspection_c__NavigateToNode_GetResult_Request_fini_function(void * message_memory)
{
  vda5050_connector__action__NavigateToNode_GetResult_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember vda5050_connector__action__NavigateToNode_GetResult_Request__rosidl_typesupport_introspection_c__NavigateToNode_GetResult_Request_message_member_array[1] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_connector__action__NavigateToNode_GetResult_Request, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers vda5050_connector__action__NavigateToNode_GetResult_Request__rosidl_typesupport_introspection_c__NavigateToNode_GetResult_Request_message_members = {
  "vda5050_connector__action",  // message namespace
  "NavigateToNode_GetResult_Request",  // message name
  1,  // number of fields
  sizeof(vda5050_connector__action__NavigateToNode_GetResult_Request),
  vda5050_connector__action__NavigateToNode_GetResult_Request__rosidl_typesupport_introspection_c__NavigateToNode_GetResult_Request_message_member_array,  // message members
  vda5050_connector__action__NavigateToNode_GetResult_Request__rosidl_typesupport_introspection_c__NavigateToNode_GetResult_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  vda5050_connector__action__NavigateToNode_GetResult_Request__rosidl_typesupport_introspection_c__NavigateToNode_GetResult_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t vda5050_connector__action__NavigateToNode_GetResult_Request__rosidl_typesupport_introspection_c__NavigateToNode_GetResult_Request_message_type_support_handle = {
  0,
  &vda5050_connector__action__NavigateToNode_GetResult_Request__rosidl_typesupport_introspection_c__NavigateToNode_GetResult_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_vda5050_connector
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vda5050_connector, action, NavigateToNode_GetResult_Request)() {
  vda5050_connector__action__NavigateToNode_GetResult_Request__rosidl_typesupport_introspection_c__NavigateToNode_GetResult_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  if (!vda5050_connector__action__NavigateToNode_GetResult_Request__rosidl_typesupport_introspection_c__NavigateToNode_GetResult_Request_message_type_support_handle.typesupport_identifier) {
    vda5050_connector__action__NavigateToNode_GetResult_Request__rosidl_typesupport_introspection_c__NavigateToNode_GetResult_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &vda5050_connector__action__NavigateToNode_GetResult_Request__rosidl_typesupport_introspection_c__NavigateToNode_GetResult_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "vda5050_connector/action/detail/navigate_to_node__rosidl_typesupport_introspection_c.h"
// already included above
// #include "vda5050_connector/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "vda5050_connector/action/detail/navigate_to_node__functions.h"
// already included above
// #include "vda5050_connector/action/detail/navigate_to_node__struct.h"


// Include directives for member types
// Member `result`
// already included above
// #include "vda5050_connector/action/navigate_to_node.h"
// Member `result`
// already included above
// #include "vda5050_connector/action/detail/navigate_to_node__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void vda5050_connector__action__NavigateToNode_GetResult_Response__rosidl_typesupport_introspection_c__NavigateToNode_GetResult_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  vda5050_connector__action__NavigateToNode_GetResult_Response__init(message_memory);
}

void vda5050_connector__action__NavigateToNode_GetResult_Response__rosidl_typesupport_introspection_c__NavigateToNode_GetResult_Response_fini_function(void * message_memory)
{
  vda5050_connector__action__NavigateToNode_GetResult_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember vda5050_connector__action__NavigateToNode_GetResult_Response__rosidl_typesupport_introspection_c__NavigateToNode_GetResult_Response_message_member_array[2] = {
  {
    "status",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_connector__action__NavigateToNode_GetResult_Response, status),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "result",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_connector__action__NavigateToNode_GetResult_Response, result),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers vda5050_connector__action__NavigateToNode_GetResult_Response__rosidl_typesupport_introspection_c__NavigateToNode_GetResult_Response_message_members = {
  "vda5050_connector__action",  // message namespace
  "NavigateToNode_GetResult_Response",  // message name
  2,  // number of fields
  sizeof(vda5050_connector__action__NavigateToNode_GetResult_Response),
  vda5050_connector__action__NavigateToNode_GetResult_Response__rosidl_typesupport_introspection_c__NavigateToNode_GetResult_Response_message_member_array,  // message members
  vda5050_connector__action__NavigateToNode_GetResult_Response__rosidl_typesupport_introspection_c__NavigateToNode_GetResult_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  vda5050_connector__action__NavigateToNode_GetResult_Response__rosidl_typesupport_introspection_c__NavigateToNode_GetResult_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t vda5050_connector__action__NavigateToNode_GetResult_Response__rosidl_typesupport_introspection_c__NavigateToNode_GetResult_Response_message_type_support_handle = {
  0,
  &vda5050_connector__action__NavigateToNode_GetResult_Response__rosidl_typesupport_introspection_c__NavigateToNode_GetResult_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_vda5050_connector
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vda5050_connector, action, NavigateToNode_GetResult_Response)() {
  vda5050_connector__action__NavigateToNode_GetResult_Response__rosidl_typesupport_introspection_c__NavigateToNode_GetResult_Response_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vda5050_connector, action, NavigateToNode_Result)();
  if (!vda5050_connector__action__NavigateToNode_GetResult_Response__rosidl_typesupport_introspection_c__NavigateToNode_GetResult_Response_message_type_support_handle.typesupport_identifier) {
    vda5050_connector__action__NavigateToNode_GetResult_Response__rosidl_typesupport_introspection_c__NavigateToNode_GetResult_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &vda5050_connector__action__NavigateToNode_GetResult_Response__rosidl_typesupport_introspection_c__NavigateToNode_GetResult_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "vda5050_connector/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "vda5050_connector/action/detail/navigate_to_node__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers vda5050_connector__action__detail__navigate_to_node__rosidl_typesupport_introspection_c__NavigateToNode_GetResult_service_members = {
  "vda5050_connector__action",  // service namespace
  "NavigateToNode_GetResult",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // vda5050_connector__action__detail__navigate_to_node__rosidl_typesupport_introspection_c__NavigateToNode_GetResult_Request_message_type_support_handle,
  NULL  // response message
  // vda5050_connector__action__detail__navigate_to_node__rosidl_typesupport_introspection_c__NavigateToNode_GetResult_Response_message_type_support_handle
};

static rosidl_service_type_support_t vda5050_connector__action__detail__navigate_to_node__rosidl_typesupport_introspection_c__NavigateToNode_GetResult_service_type_support_handle = {
  0,
  &vda5050_connector__action__detail__navigate_to_node__rosidl_typesupport_introspection_c__NavigateToNode_GetResult_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vda5050_connector, action, NavigateToNode_GetResult_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vda5050_connector, action, NavigateToNode_GetResult_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_vda5050_connector
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vda5050_connector, action, NavigateToNode_GetResult)() {
  if (!vda5050_connector__action__detail__navigate_to_node__rosidl_typesupport_introspection_c__NavigateToNode_GetResult_service_type_support_handle.typesupport_identifier) {
    vda5050_connector__action__detail__navigate_to_node__rosidl_typesupport_introspection_c__NavigateToNode_GetResult_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)vda5050_connector__action__detail__navigate_to_node__rosidl_typesupport_introspection_c__NavigateToNode_GetResult_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vda5050_connector, action, NavigateToNode_GetResult_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vda5050_connector, action, NavigateToNode_GetResult_Response)()->data;
  }

  return &vda5050_connector__action__detail__navigate_to_node__rosidl_typesupport_introspection_c__NavigateToNode_GetResult_service_type_support_handle;
}

// already included above
// #include <stddef.h>
// already included above
// #include "vda5050_connector/action/detail/navigate_to_node__rosidl_typesupport_introspection_c.h"
// already included above
// #include "vda5050_connector/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "vda5050_connector/action/detail/navigate_to_node__functions.h"
// already included above
// #include "vda5050_connector/action/detail/navigate_to_node__struct.h"


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"
// Member `feedback`
// already included above
// #include "vda5050_connector/action/navigate_to_node.h"
// Member `feedback`
// already included above
// #include "vda5050_connector/action/detail/navigate_to_node__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void vda5050_connector__action__NavigateToNode_FeedbackMessage__rosidl_typesupport_introspection_c__NavigateToNode_FeedbackMessage_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  vda5050_connector__action__NavigateToNode_FeedbackMessage__init(message_memory);
}

void vda5050_connector__action__NavigateToNode_FeedbackMessage__rosidl_typesupport_introspection_c__NavigateToNode_FeedbackMessage_fini_function(void * message_memory)
{
  vda5050_connector__action__NavigateToNode_FeedbackMessage__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember vda5050_connector__action__NavigateToNode_FeedbackMessage__rosidl_typesupport_introspection_c__NavigateToNode_FeedbackMessage_message_member_array[2] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_connector__action__NavigateToNode_FeedbackMessage, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "feedback",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_connector__action__NavigateToNode_FeedbackMessage, feedback),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers vda5050_connector__action__NavigateToNode_FeedbackMessage__rosidl_typesupport_introspection_c__NavigateToNode_FeedbackMessage_message_members = {
  "vda5050_connector__action",  // message namespace
  "NavigateToNode_FeedbackMessage",  // message name
  2,  // number of fields
  sizeof(vda5050_connector__action__NavigateToNode_FeedbackMessage),
  vda5050_connector__action__NavigateToNode_FeedbackMessage__rosidl_typesupport_introspection_c__NavigateToNode_FeedbackMessage_message_member_array,  // message members
  vda5050_connector__action__NavigateToNode_FeedbackMessage__rosidl_typesupport_introspection_c__NavigateToNode_FeedbackMessage_init_function,  // function to initialize message memory (memory has to be allocated)
  vda5050_connector__action__NavigateToNode_FeedbackMessage__rosidl_typesupport_introspection_c__NavigateToNode_FeedbackMessage_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t vda5050_connector__action__NavigateToNode_FeedbackMessage__rosidl_typesupport_introspection_c__NavigateToNode_FeedbackMessage_message_type_support_handle = {
  0,
  &vda5050_connector__action__NavigateToNode_FeedbackMessage__rosidl_typesupport_introspection_c__NavigateToNode_FeedbackMessage_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_vda5050_connector
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vda5050_connector, action, NavigateToNode_FeedbackMessage)() {
  vda5050_connector__action__NavigateToNode_FeedbackMessage__rosidl_typesupport_introspection_c__NavigateToNode_FeedbackMessage_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  vda5050_connector__action__NavigateToNode_FeedbackMessage__rosidl_typesupport_introspection_c__NavigateToNode_FeedbackMessage_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vda5050_connector, action, NavigateToNode_Feedback)();
  if (!vda5050_connector__action__NavigateToNode_FeedbackMessage__rosidl_typesupport_introspection_c__NavigateToNode_FeedbackMessage_message_type_support_handle.typesupport_identifier) {
    vda5050_connector__action__NavigateToNode_FeedbackMessage__rosidl_typesupport_introspection_c__NavigateToNode_FeedbackMessage_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &vda5050_connector__action__NavigateToNode_FeedbackMessage__rosidl_typesupport_introspection_c__NavigateToNode_FeedbackMessage_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
