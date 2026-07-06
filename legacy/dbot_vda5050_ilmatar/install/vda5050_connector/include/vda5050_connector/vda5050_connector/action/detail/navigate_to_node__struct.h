// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vda5050_connector:action/NavigateToNode.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_CONNECTOR__ACTION__DETAIL__NAVIGATE_TO_NODE__STRUCT_H_
#define VDA5050_CONNECTOR__ACTION__DETAIL__NAVIGATE_TO_NODE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'edge'
#include "vda5050_msgs/msg/detail/edge__struct.h"
// Member 'node'
#include "vda5050_msgs/msg/detail/node__struct.h"

/// Struct defined in action/NavigateToNode in the package vda5050_connector.
typedef struct vda5050_connector__action__NavigateToNode_Goal
{
  vda5050_msgs__msg__Edge edge;
  vda5050_msgs__msg__Node node;
} vda5050_connector__action__NavigateToNode_Goal;

// Struct for a sequence of vda5050_connector__action__NavigateToNode_Goal.
typedef struct vda5050_connector__action__NavigateToNode_Goal__Sequence
{
  vda5050_connector__action__NavigateToNode_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vda5050_connector__action__NavigateToNode_Goal__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
#include "std_msgs/msg/detail/empty__struct.h"

/// Struct defined in action/NavigateToNode in the package vda5050_connector.
typedef struct vda5050_connector__action__NavigateToNode_Result
{
  std_msgs__msg__Empty result;
} vda5050_connector__action__NavigateToNode_Result;

// Struct for a sequence of vda5050_connector__action__NavigateToNode_Result.
typedef struct vda5050_connector__action__NavigateToNode_Result__Sequence
{
  vda5050_connector__action__NavigateToNode_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vda5050_connector__action__NavigateToNode_Result__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'position'
#include "vda5050_msgs/msg/detail/agv_position__struct.h"
// Member 'velocity'
#include "vda5050_msgs/msg/detail/velocity__struct.h"

/// Struct defined in action/NavigateToNode in the package vda5050_connector.
typedef struct vda5050_connector__action__NavigateToNode_Feedback
{
  vda5050_msgs__msg__AGVPosition position;
  vda5050_msgs__msg__Velocity velocity;
} vda5050_connector__action__NavigateToNode_Feedback;

// Struct for a sequence of vda5050_connector__action__NavigateToNode_Feedback.
typedef struct vda5050_connector__action__NavigateToNode_Feedback__Sequence
{
  vda5050_connector__action__NavigateToNode_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vda5050_connector__action__NavigateToNode_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "vda5050_connector/action/detail/navigate_to_node__struct.h"

/// Struct defined in action/NavigateToNode in the package vda5050_connector.
typedef struct vda5050_connector__action__NavigateToNode_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  vda5050_connector__action__NavigateToNode_Goal goal;
} vda5050_connector__action__NavigateToNode_SendGoal_Request;

// Struct for a sequence of vda5050_connector__action__NavigateToNode_SendGoal_Request.
typedef struct vda5050_connector__action__NavigateToNode_SendGoal_Request__Sequence
{
  vda5050_connector__action__NavigateToNode_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vda5050_connector__action__NavigateToNode_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/NavigateToNode in the package vda5050_connector.
typedef struct vda5050_connector__action__NavigateToNode_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} vda5050_connector__action__NavigateToNode_SendGoal_Response;

// Struct for a sequence of vda5050_connector__action__NavigateToNode_SendGoal_Response.
typedef struct vda5050_connector__action__NavigateToNode_SendGoal_Response__Sequence
{
  vda5050_connector__action__NavigateToNode_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vda5050_connector__action__NavigateToNode_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/NavigateToNode in the package vda5050_connector.
typedef struct vda5050_connector__action__NavigateToNode_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} vda5050_connector__action__NavigateToNode_GetResult_Request;

// Struct for a sequence of vda5050_connector__action__NavigateToNode_GetResult_Request.
typedef struct vda5050_connector__action__NavigateToNode_GetResult_Request__Sequence
{
  vda5050_connector__action__NavigateToNode_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vda5050_connector__action__NavigateToNode_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "vda5050_connector/action/detail/navigate_to_node__struct.h"

/// Struct defined in action/NavigateToNode in the package vda5050_connector.
typedef struct vda5050_connector__action__NavigateToNode_GetResult_Response
{
  int8_t status;
  vda5050_connector__action__NavigateToNode_Result result;
} vda5050_connector__action__NavigateToNode_GetResult_Response;

// Struct for a sequence of vda5050_connector__action__NavigateToNode_GetResult_Response.
typedef struct vda5050_connector__action__NavigateToNode_GetResult_Response__Sequence
{
  vda5050_connector__action__NavigateToNode_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vda5050_connector__action__NavigateToNode_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "vda5050_connector/action/detail/navigate_to_node__struct.h"

/// Struct defined in action/NavigateToNode in the package vda5050_connector.
typedef struct vda5050_connector__action__NavigateToNode_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  vda5050_connector__action__NavigateToNode_Feedback feedback;
} vda5050_connector__action__NavigateToNode_FeedbackMessage;

// Struct for a sequence of vda5050_connector__action__NavigateToNode_FeedbackMessage.
typedef struct vda5050_connector__action__NavigateToNode_FeedbackMessage__Sequence
{
  vda5050_connector__action__NavigateToNode_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vda5050_connector__action__NavigateToNode_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VDA5050_CONNECTOR__ACTION__DETAIL__NAVIGATE_TO_NODE__STRUCT_H_
