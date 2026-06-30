#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "vda5050_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__Action() -> *const std::ffi::c_void;
}

#[link(name = "vda5050_msgs__rosidl_generator_c")]
extern "C" {
    fn vda5050_msgs__msg__Action__init(msg: *mut Action) -> bool;
    fn vda5050_msgs__msg__Action__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Action>, size: usize) -> bool;
    fn vda5050_msgs__msg__Action__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Action>);
    fn vda5050_msgs__msg__Action__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Action>, out_seq: *mut rosidl_runtime_rs::Sequence<Action>) -> bool;
}

// Corresponds to vda5050_msgs__msg__Action
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// Action the AGV can perform.

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Action {
    /// Name of action as described in the first column
    /// of "Actions and Parameters".
    /// Identifies the function of the action.
    pub action_type: rosidl_runtime_rs::String,

    /// Unique ID to identify the action and map them to
    /// the actionState in the state.
    /// Suggestion: Use UUIDs.
    pub action_id: rosidl_runtime_rs::String,

    /// Additional information on the action
    pub action_description: rosidl_runtime_rs::String,

    /// Enum {NONE, SOFT, HARD}
    /// “NONE” – allows driving and other actions
    /// “SOFT” - allows other actions, but not driving
    /// “HARD” - is the only allowd action at that time
    pub blocking_type: rosidl_runtime_rs::String,

    /// Array of actionParameter objects for the indicated
    /// action e. g. deviceId, loadId, external Triggers.
    /// See “Actions and Parameters”.
    ///
    /// Note on Porting to ROS:
    /// Since those parameter vary in type but their
    /// serialization is always a json dictionary with "key"
    /// and "value" we decided to serialize the value as
    /// string. This way the (de-)serialization has to be done by
    /// the user depending on the key, but the protocol is met
    pub action_parameters: rosidl_runtime_rs::Sequence<super::super::msg::rmw::ActionParameter>,

}

impl Action {
    /// Enums for blockingType
    pub const NONE: &'static str = "NONE";


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const SOFT: &'static str = "SOFT";


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const HARD: &'static str = "HARD";

}


impl Default for Action {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !vda5050_msgs__msg__Action__init(&mut msg as *mut _) {
        panic!("Call to vda5050_msgs__msg__Action__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Action {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__Action__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__Action__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__Action__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Action {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Action where Self: Sized {
  const TYPE_NAME: &'static str = "vda5050_msgs/msg/Action";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__Action() }
  }
}


#[link(name = "vda5050_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__ActionParameter() -> *const std::ffi::c_void;
}

#[link(name = "vda5050_msgs__rosidl_generator_c")]
extern "C" {
    fn vda5050_msgs__msg__ActionParameter__init(msg: *mut ActionParameter) -> bool;
    fn vda5050_msgs__msg__ActionParameter__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ActionParameter>, size: usize) -> bool;
    fn vda5050_msgs__msg__ActionParameter__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ActionParameter>);
    fn vda5050_msgs__msg__ActionParameter__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ActionParameter>, out_seq: *mut rosidl_runtime_rs::Sequence<ActionParameter>) -> bool;
}

// Corresponds to vda5050_msgs__msg__ActionParameter
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ActionParameter {

    // This member is not documented.
    #[allow(missing_docs)]
    pub key: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub value: rosidl_runtime_rs::String,

}



impl Default for ActionParameter {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !vda5050_msgs__msg__ActionParameter__init(&mut msg as *mut _) {
        panic!("Call to vda5050_msgs__msg__ActionParameter__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ActionParameter {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__ActionParameter__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__ActionParameter__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__ActionParameter__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ActionParameter {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ActionParameter where Self: Sized {
  const TYPE_NAME: &'static str = "vda5050_msgs/msg/ActionParameter";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__ActionParameter() }
  }
}


#[link(name = "vda5050_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__ActionParameterDefinition() -> *const std::ffi::c_void;
}

#[link(name = "vda5050_msgs__rosidl_generator_c")]
extern "C" {
    fn vda5050_msgs__msg__ActionParameterDefinition__init(msg: *mut ActionParameterDefinition) -> bool;
    fn vda5050_msgs__msg__ActionParameterDefinition__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ActionParameterDefinition>, size: usize) -> bool;
    fn vda5050_msgs__msg__ActionParameterDefinition__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ActionParameterDefinition>);
    fn vda5050_msgs__msg__ActionParameterDefinition__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ActionParameterDefinition>, out_seq: *mut rosidl_runtime_rs::Sequence<ActionParameterDefinition>) -> bool;
}

// Corresponds to vda5050_msgs__msg__ActionParameterDefinition
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ActionParameterDefinition {

    // This member is not documented.
    #[allow(missing_docs)]
    pub key: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub value_data_type: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub description: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub is_optional: bool,

}

impl ActionParameterDefinition {
    /// Enums for valueDataType
    pub const BOOL: &'static str = "BOOL";


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const NUMBER: &'static str = "NUMBER";


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const INTEGER: &'static str = "INTEGER";


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FLOAT: &'static str = "FLOAT";


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const STRING: &'static str = "STRING";


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const OBJECT: &'static str = "OBJECT";


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const ARRAY: &'static str = "ARRAY";

}


impl Default for ActionParameterDefinition {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !vda5050_msgs__msg__ActionParameterDefinition__init(&mut msg as *mut _) {
        panic!("Call to vda5050_msgs__msg__ActionParameterDefinition__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ActionParameterDefinition {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__ActionParameterDefinition__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__ActionParameterDefinition__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__ActionParameterDefinition__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ActionParameterDefinition {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ActionParameterDefinition where Self: Sized {
  const TYPE_NAME: &'static str = "vda5050_msgs/msg/ActionParameterDefinition";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__ActionParameterDefinition() }
  }
}


#[link(name = "vda5050_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__AGVAction() -> *const std::ffi::c_void;
}

#[link(name = "vda5050_msgs__rosidl_generator_c")]
extern "C" {
    fn vda5050_msgs__msg__AGVAction__init(msg: *mut AGVAction) -> bool;
    fn vda5050_msgs__msg__AGVAction__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<AGVAction>, size: usize) -> bool;
    fn vda5050_msgs__msg__AGVAction__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<AGVAction>);
    fn vda5050_msgs__msg__AGVAction__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<AGVAction>, out_seq: *mut rosidl_runtime_rs::Sequence<AGVAction>) -> bool;
}

// Corresponds to vda5050_msgs__msg__AGVAction
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct AGVAction {
    /// Unique actionType corresponding to action.actionType
    pub action_type: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub action_description: rosidl_runtime_rs::String,

    /// Allowed scopes for using this action-type
    pub action_scopes: rosidl_runtime_rs::Sequence<rosidl_runtime_rs::String>,

    /// List of parameters defined for the action
    pub action_parameters: rosidl_runtime_rs::Sequence<super::super::msg::rmw::ActionParameterDefinition>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub result_description: rosidl_runtime_rs::String,

}

impl AGVAction {
    /// Enums for action scopes
    pub const INSTANT: &'static str = "INSTANT";


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const NODE: &'static str = "NODE";


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const EDGE: &'static str = "EDGE";

}


impl Default for AGVAction {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !vda5050_msgs__msg__AGVAction__init(&mut msg as *mut _) {
        panic!("Call to vda5050_msgs__msg__AGVAction__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for AGVAction {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__AGVAction__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__AGVAction__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__AGVAction__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for AGVAction {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for AGVAction where Self: Sized {
  const TYPE_NAME: &'static str = "vda5050_msgs/msg/AGVAction";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__AGVAction() }
  }
}


#[link(name = "vda5050_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__AGVGeometry() -> *const std::ffi::c_void;
}

#[link(name = "vda5050_msgs__rosidl_generator_c")]
extern "C" {
    fn vda5050_msgs__msg__AGVGeometry__init(msg: *mut AGVGeometry) -> bool;
    fn vda5050_msgs__msg__AGVGeometry__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<AGVGeometry>, size: usize) -> bool;
    fn vda5050_msgs__msg__AGVGeometry__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<AGVGeometry>);
    fn vda5050_msgs__msg__AGVGeometry__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<AGVGeometry>, out_seq: *mut rosidl_runtime_rs::Sequence<AGVGeometry>) -> bool;
}

// Corresponds to vda5050_msgs__msg__AGVGeometry
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct AGVGeometry {
    /// List of wheels, containing wheel-arrangement and geometry
    pub wheel_definitions: rosidl_runtime_rs::Sequence<super::super::msg::rmw::WheelDefinition>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub envelopes2d: rosidl_runtime_rs::Sequence<super::super::msg::rmw::Envelope2D>,

    /// List of AGV-envelope curves in 3D
    pub envelopes3d: rosidl_runtime_rs::Sequence<super::super::msg::rmw::Envelope3D>,

}



impl Default for AGVGeometry {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !vda5050_msgs__msg__AGVGeometry__init(&mut msg as *mut _) {
        panic!("Call to vda5050_msgs__msg__AGVGeometry__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for AGVGeometry {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__AGVGeometry__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__AGVGeometry__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__AGVGeometry__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for AGVGeometry {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for AGVGeometry where Self: Sized {
  const TYPE_NAME: &'static str = "vda5050_msgs/msg/AGVGeometry";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__AGVGeometry() }
  }
}


#[link(name = "vda5050_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__AGVPosition() -> *const std::ffi::c_void;
}

#[link(name = "vda5050_msgs__rosidl_generator_c")]
extern "C" {
    fn vda5050_msgs__msg__AGVPosition__init(msg: *mut AGVPosition) -> bool;
    fn vda5050_msgs__msg__AGVPosition__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<AGVPosition>, size: usize) -> bool;
    fn vda5050_msgs__msg__AGVPosition__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<AGVPosition>);
    fn vda5050_msgs__msg__AGVPosition__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<AGVPosition>, out_seq: *mut rosidl_runtime_rs::Sequence<AGVPosition>) -> bool;
}

// Corresponds to vda5050_msgs__msg__AGVPosition
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// Defines the position on a map in world coordinates. Each floor has its own map.

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct AGVPosition {
    /// False: position is not initialized True: position is initialized
    pub position_initialized: bool,

    /// Range: Describes the quality of the localization and therefore, can be used
    /// e. g. by SLAMAGVs to describe how accurate the current position information is.
    /// 0.0: position unknown 1.0: position known
    pub localization_score: f64,

    /// Value for the deviation range of the position in meters.
    pub deviation_range: f64,

    /// X-position on the map in reference to the map coordinate system. Precision is up to
    /// the specific implementation
    pub x: f64,

    /// Y-position on the map in reference to the map coordinate system. Precision is up to
    /// the specific implementation.
    pub y: f64,

    /// [rad] Range: [-Pi … Pi] Orientation of the AGV.
    pub theta: f64,

    /// Unique identification of the map in which the position is referenced. Each map has the
    /// same origin of coordinates. When an AGV uses an elevator, e. g. leading from a departure
    /// floor to a target floor, it will disappear off the map of the departure floor and spawn
    /// in the related lift node on the map of the target floor.
    pub map_id: rosidl_runtime_rs::String,

    /// Additional information on the map.
    pub map_description: rosidl_runtime_rs::String,

}



impl Default for AGVPosition {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !vda5050_msgs__msg__AGVPosition__init(&mut msg as *mut _) {
        panic!("Call to vda5050_msgs__msg__AGVPosition__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for AGVPosition {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__AGVPosition__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__AGVPosition__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__AGVPosition__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for AGVPosition {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for AGVPosition where Self: Sized {
  const TYPE_NAME: &'static str = "vda5050_msgs/msg/AGVPosition";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__AGVPosition() }
  }
}


#[link(name = "vda5050_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__BatteryState() -> *const std::ffi::c_void;
}

#[link(name = "vda5050_msgs__rosidl_generator_c")]
extern "C" {
    fn vda5050_msgs__msg__BatteryState__init(msg: *mut BatteryState) -> bool;
    fn vda5050_msgs__msg__BatteryState__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<BatteryState>, size: usize) -> bool;
    fn vda5050_msgs__msg__BatteryState__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<BatteryState>);
    fn vda5050_msgs__msg__BatteryState__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<BatteryState>, out_seq: *mut rosidl_runtime_rs::Sequence<BatteryState>) -> bool;
}

// Corresponds to vda5050_msgs__msg__BatteryState
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct BatteryState {
    /// State of Charge: if AGV only provides values for good or bad battery levels, these will
    /// be indicated as 20% (bad) and 80% (good).
    pub battery_charge: f64,

    /// Battery Voltage
    pub battery_voltage: f64,

    /// State of Health
    pub battery_health: i8,

    /// True: charging in progress False: AGV is currently not charging
    pub charging: bool,

    /// Estimated reach with current SoC
    pub reach: u32,

}



impl Default for BatteryState {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !vda5050_msgs__msg__BatteryState__init(&mut msg as *mut _) {
        panic!("Call to vda5050_msgs__msg__BatteryState__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for BatteryState {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__BatteryState__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__BatteryState__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__BatteryState__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for BatteryState {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for BatteryState where Self: Sized {
  const TYPE_NAME: &'static str = "vda5050_msgs/msg/BatteryState";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__BatteryState() }
  }
}


#[link(name = "vda5050_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__BoundingBoxReference() -> *const std::ffi::c_void;
}

#[link(name = "vda5050_msgs__rosidl_generator_c")]
extern "C" {
    fn vda5050_msgs__msg__BoundingBoxReference__init(msg: *mut BoundingBoxReference) -> bool;
    fn vda5050_msgs__msg__BoundingBoxReference__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<BoundingBoxReference>, size: usize) -> bool;
    fn vda5050_msgs__msg__BoundingBoxReference__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<BoundingBoxReference>);
    fn vda5050_msgs__msg__BoundingBoxReference__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<BoundingBoxReference>, out_seq: *mut rosidl_runtime_rs::Sequence<BoundingBoxReference>) -> bool;
}

// Corresponds to vda5050_msgs__msg__BoundingBoxReference
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// Point of reference for the location of the bounding box. The point of reference is always the center of the bounding
/// box’s bottom surface (at height = 0) and is described in coordinates of the AGV’s coordinate system.

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct BoundingBoxReference {
    /// x-coordinate of the point of reference.
    pub x: f64,

    /// y-coordinate of the point of reference.
    pub y: f64,

    /// z-coordinate of the point of reference.
    pub z: f64,

    /// Orientation of the loads bounding box. Important for tugger trains etc
    pub theta: f64,

}



impl Default for BoundingBoxReference {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !vda5050_msgs__msg__BoundingBoxReference__init(&mut msg as *mut _) {
        panic!("Call to vda5050_msgs__msg__BoundingBoxReference__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for BoundingBoxReference {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__BoundingBoxReference__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__BoundingBoxReference__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__BoundingBoxReference__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for BoundingBoxReference {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for BoundingBoxReference where Self: Sized {
  const TYPE_NAME: &'static str = "vda5050_msgs/msg/BoundingBoxReference";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__BoundingBoxReference() }
  }
}


#[link(name = "vda5050_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__Connection() -> *const std::ffi::c_void;
}

#[link(name = "vda5050_msgs__rosidl_generator_c")]
extern "C" {
    fn vda5050_msgs__msg__Connection__init(msg: *mut Connection) -> bool;
    fn vda5050_msgs__msg__Connection__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Connection>, size: usize) -> bool;
    fn vda5050_msgs__msg__Connection__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Connection>);
    fn vda5050_msgs__msg__Connection__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Connection>, out_seq: *mut rosidl_runtime_rs::Sequence<Connection>) -> bool;
}

// Corresponds to vda5050_msgs__msg__Connection
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// HEADER

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Connection {
    /// header ID of the message. The headerId is defined per topic and incremented by 1 with each sent
    /// (but not necessarily received) message.
    pub header_id: u32,

    /// Timestamp after ISO8601 in the format YYYY-MM-DDTHH:mm:ss.ssZ (e.g.“2017-04-15T11:40:03.12Z”)
    pub timestamp: rosidl_runtime_rs::String,

    /// Version of the protocol [Major].[Minor].[Patch] (e.g. 1.3.2)
    pub version: rosidl_runtime_rs::String,

    /// Manufacturer of the AGV
    pub manufacturer: rosidl_runtime_rs::String,

    /// Serial Number of the AGV
    pub serial_number: rosidl_runtime_rs::String,

    /// CONTENTS
    /// Enum{ONLINE, OFFLINE, CONNECTIONBROKEN}
    /// ONLINE: connection between AGV and broker is active.
    /// OFFLINE: connection between AGV and broker has gone offline in a coordinated way.
    /// CONNECTIONBROKEN: The connection between  AGV and  broker  has unexpectedly ended.
    pub connection_state: rosidl_runtime_rs::String,

}

impl Connection {

    // This constant is not documented.
    #[allow(missing_docs)]
    pub const ONLINE: &'static str = "ONLINE";


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const OFFLINE: &'static str = "OFFLINE";


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const CONNECTIONBROKEN: &'static str = "CONNECTIONBROKEN";

}


impl Default for Connection {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !vda5050_msgs__msg__Connection__init(&mut msg as *mut _) {
        panic!("Call to vda5050_msgs__msg__Connection__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Connection {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__Connection__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__Connection__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__Connection__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Connection {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Connection where Self: Sized {
  const TYPE_NAME: &'static str = "vda5050_msgs/msg/Connection";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__Connection() }
  }
}


#[link(name = "vda5050_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__ControlPoint() -> *const std::ffi::c_void;
}

#[link(name = "vda5050_msgs__rosidl_generator_c")]
extern "C" {
    fn vda5050_msgs__msg__ControlPoint__init(msg: *mut ControlPoint) -> bool;
    fn vda5050_msgs__msg__ControlPoint__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ControlPoint>, size: usize) -> bool;
    fn vda5050_msgs__msg__ControlPoint__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ControlPoint>);
    fn vda5050_msgs__msg__ControlPoint__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ControlPoint>, out_seq: *mut rosidl_runtime_rs::Sequence<ControlPoint>) -> bool;
}

// Corresponds to vda5050_msgs__msg__ControlPoint
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ControlPoint {
    /// X coordinate described in the world coordinate system.
    pub x: f64,

    /// Y coordinate described in the world coordinate system.
    pub y: f64,

    /// [rad] Range [-pi...pi] Orientation of the AGV on this position of the curve.
    /// The orientation is in world coordinates.
    /// When not defined the orientation of the AGV will be tangential to the curve.
    pub orientation: f64,

    /// Range [0..infinity) The weight with which this control point pulls on the curve.
    /// When not defined, the default will be 1.0
    pub weight: f64,

}



impl Default for ControlPoint {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !vda5050_msgs__msg__ControlPoint__init(&mut msg as *mut _) {
        panic!("Call to vda5050_msgs__msg__ControlPoint__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ControlPoint {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__ControlPoint__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__ControlPoint__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__ControlPoint__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ControlPoint {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ControlPoint where Self: Sized {
  const TYPE_NAME: &'static str = "vda5050_msgs/msg/ControlPoint";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__ControlPoint() }
  }
}


#[link(name = "vda5050_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__CurrentAction() -> *const std::ffi::c_void;
}

#[link(name = "vda5050_msgs__rosidl_generator_c")]
extern "C" {
    fn vda5050_msgs__msg__CurrentAction__init(msg: *mut CurrentAction) -> bool;
    fn vda5050_msgs__msg__CurrentAction__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<CurrentAction>, size: usize) -> bool;
    fn vda5050_msgs__msg__CurrentAction__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<CurrentAction>);
    fn vda5050_msgs__msg__CurrentAction__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<CurrentAction>, out_seq: *mut rosidl_runtime_rs::Sequence<CurrentAction>) -> bool;
}

// Corresponds to vda5050_msgs__msg__CurrentAction
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct CurrentAction {
    /// action_name_ID
    pub action_id: rosidl_runtime_rs::String,

    /// actionType of the action.
    /// Optional: Only for informational or
    /// visualization purposes. Order knows
    /// the type.
    pub action_type: rosidl_runtime_rs::String,

    /// Additional information on the current action
    pub action_description: rosidl_runtime_rs::String,

    /// Enum {waiting; initializing; running; finished; failed} waiting: waiting for trigger
    /// failed: action could not be performed.
    pub action_status: rosidl_runtime_rs::String,

    /// Description of the result, e.g. the result of a RFID-read. Errors will be transmitted in
    /// errors. Examples for results are given in 5.2
    pub result_description: rosidl_runtime_rs::String,

}

impl CurrentAction {
    /// Enums for actionStatus
    pub const WAITING: &'static str = "WAITING";


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const INITIALIZING: &'static str = "INITIALIZING";


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const RUNNING: &'static str = "RUNNING";


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const PAUSED: &'static str = "PAUSED";


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FINISHED: &'static str = "FINISHED";


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FAILED: &'static str = "FAILED";

}


impl Default for CurrentAction {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !vda5050_msgs__msg__CurrentAction__init(&mut msg as *mut _) {
        panic!("Call to vda5050_msgs__msg__CurrentAction__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for CurrentAction {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__CurrentAction__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__CurrentAction__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__CurrentAction__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for CurrentAction {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for CurrentAction where Self: Sized {
  const TYPE_NAME: &'static str = "vda5050_msgs/msg/CurrentAction";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__CurrentAction() }
  }
}


#[link(name = "vda5050_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__Edge() -> *const std::ffi::c_void;
}

#[link(name = "vda5050_msgs__rosidl_generator_c")]
extern "C" {
    fn vda5050_msgs__msg__Edge__init(msg: *mut Edge) -> bool;
    fn vda5050_msgs__msg__Edge__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Edge>, size: usize) -> bool;
    fn vda5050_msgs__msg__Edge__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Edge>);
    fn vda5050_msgs__msg__Edge__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Edge>, out_seq: *mut rosidl_runtime_rs::Sequence<Edge>) -> bool;
}

// Corresponds to vda5050_msgs__msg__Edge
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// Directional connection between two nodes

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Edge {
    /// Unique edge identification
    pub edge_id: rosidl_runtime_rs::String,

    /// Id to track the sequence of nodes and edges in an order and to simplify order
    /// updates. The variable sequence_id runs across all nodes and edges of the same order
    /// and is reset when a new order_id is issued.
    pub sequence_id: u32,

    /// Additional information on the edge
    pub edge_description: rosidl_runtime_rs::String,

    /// True indicates that the edge is part of the base. False indicates that the edge is
    /// part of the horizon.
    pub released: bool,

    /// nodeID of startNode
    pub start_node_id: rosidl_runtime_rs::String,

    /// nodeID of endNode
    pub end_node_id: rosidl_runtime_rs::String,

    /// Permitted maximum speed on the edge. Speed is defined by the fastest point of the
    /// vehicle.
    pub max_speed: f64,

    /// Permitted maximum height of the vehicle, including the load, on edge
    pub max_height: f64,

    /// Permitted minimal height of the edge measured at the bottom of the load
    pub min_height: f64,

    /// Orientation of the AGV on the edge relative to the global project specific
    /// map coordinate origin (for holonomic vehicles with more than one driving
    /// direction).
    /// Example: orientation Pi/2 rad will lead to a rotation of 90 degrees.
    /// If AGVstarts in different orientation, rotate the vehicle on the edge to the
    /// desired orientation if rotationAllowed is set to “true”. If rotationAllowed
    /// is “false", rotate before entering the edge. If that is not possible, reject
    /// the order.
    /// If a trajectory with orientation is defined, follow the trajectories orientation.
    /// If a trajectory without orientation and the orientation field here is defined,
    /// apply the orientation to the tangent of the trajectory.
    pub orientation: f64,

    /// Sets direction at junctions for line-guided vehicles, to be defined initially
    /// (vehicle individual) Example: left, right, straight, 433MHz
    pub direction: rosidl_runtime_rs::String,

    /// “true”: rotation is allowed on the edge. “false”: rotation is not allowed on the edge.
    /// Optional: Default to “false”. If this value is set, rotation is allowed on the edge.
    pub rotation_allowed: bool,

    /// Maximum rotation speed Optional: No limit if not set
    pub max_rotation_speed: f64,

    /// Trajectory JSON-object for this edge as a NURBS. Defines the curve on which the
    /// AGV should move between start_node and end_node. Optional: Can be omitted if AGV
    /// cannot process trajectories or if AGV plans its own trajectory.
    pub trajectory: super::super::msg::rmw::Trajectory,

    /// Length of the path from startNode to endNode. Optional: This value is used
    /// by lineguided AGVs to decrease their speed before reaching a stop position.
    pub length: f64,

    /// Array of action_ids to be executed on the edge. An action triggered by an edge will
    /// only be active for the time that the AGV is traversing the edge which triggered
    /// the action. When the AGV leaves the edge, the action will stop and the state
    /// before entering the edge will be restored.
    pub actions: rosidl_runtime_rs::Sequence<super::super::msg::rmw::Action>,

}



impl Default for Edge {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !vda5050_msgs__msg__Edge__init(&mut msg as *mut _) {
        panic!("Call to vda5050_msgs__msg__Edge__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Edge {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__Edge__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__Edge__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__Edge__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Edge {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Edge where Self: Sized {
  const TYPE_NAME: &'static str = "vda5050_msgs/msg/Edge";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__Edge() }
  }
}


#[link(name = "vda5050_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__EdgeState() -> *const std::ffi::c_void;
}

#[link(name = "vda5050_msgs__rosidl_generator_c")]
extern "C" {
    fn vda5050_msgs__msg__EdgeState__init(msg: *mut EdgeState) -> bool;
    fn vda5050_msgs__msg__EdgeState__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<EdgeState>, size: usize) -> bool;
    fn vda5050_msgs__msg__EdgeState__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<EdgeState>);
    fn vda5050_msgs__msg__EdgeState__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<EdgeState>, out_seq: *mut rosidl_runtime_rs::Sequence<EdgeState>) -> bool;
}

// Corresponds to vda5050_msgs__msg__EdgeState
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct EdgeState {
    /// Unique edge identification
    pub edge_id: rosidl_runtime_rs::String,

    /// sequenceId to differentiate between multiple edges with
    pub sequence_id: u32,

    /// Additional information on the edge
    pub edge_description: rosidl_runtime_rs::String,

    /// True indicates that the edge is part of the base. False indicates that the edge is
    /// part of the horizon.
    pub released: bool,

    /// The trajectory is to be communicated as a NURBS and is defined in chapter6.4
    /// Trajectory segments are from the point where the AGV starts to enter the edge
    /// until the point where it reports that the next node was traversed.
    pub trajectory: super::super::msg::rmw::Trajectory,

}



impl Default for EdgeState {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !vda5050_msgs__msg__EdgeState__init(&mut msg as *mut _) {
        panic!("Call to vda5050_msgs__msg__EdgeState__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for EdgeState {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__EdgeState__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__EdgeState__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__EdgeState__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for EdgeState {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for EdgeState where Self: Sized {
  const TYPE_NAME: &'static str = "vda5050_msgs/msg/EdgeState";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__EdgeState() }
  }
}


#[link(name = "vda5050_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__Envelope2D() -> *const std::ffi::c_void;
}

#[link(name = "vda5050_msgs__rosidl_generator_c")]
extern "C" {
    fn vda5050_msgs__msg__Envelope2D__init(msg: *mut Envelope2D) -> bool;
    fn vda5050_msgs__msg__Envelope2D__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Envelope2D>, size: usize) -> bool;
    fn vda5050_msgs__msg__Envelope2D__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Envelope2D>);
    fn vda5050_msgs__msg__Envelope2D__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Envelope2D>, out_seq: *mut rosidl_runtime_rs::Sequence<Envelope2D>) -> bool;
}

// Corresponds to vda5050_msgs__msg__Envelope2D
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Envelope2D {
    /// Name of the envelope curve set
    pub set: rosidl_runtime_rs::String,

    /// Envelope curve as a x/y-polygon
    pub polygon_points: rosidl_runtime_rs::Sequence<super::super::msg::rmw::PolygonPoint>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub description: rosidl_runtime_rs::String,

}



impl Default for Envelope2D {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !vda5050_msgs__msg__Envelope2D__init(&mut msg as *mut _) {
        panic!("Call to vda5050_msgs__msg__Envelope2D__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Envelope2D {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__Envelope2D__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__Envelope2D__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__Envelope2D__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Envelope2D {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Envelope2D where Self: Sized {
  const TYPE_NAME: &'static str = "vda5050_msgs/msg/Envelope2D";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__Envelope2D() }
  }
}


#[link(name = "vda5050_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__Envelope3D() -> *const std::ffi::c_void;
}

#[link(name = "vda5050_msgs__rosidl_generator_c")]
extern "C" {
    fn vda5050_msgs__msg__Envelope3D__init(msg: *mut Envelope3D) -> bool;
    fn vda5050_msgs__msg__Envelope3D__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Envelope3D>, size: usize) -> bool;
    fn vda5050_msgs__msg__Envelope3D__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Envelope3D>);
    fn vda5050_msgs__msg__Envelope3D__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Envelope3D>, out_seq: *mut rosidl_runtime_rs::Sequence<Envelope3D>) -> bool;
}

// Corresponds to vda5050_msgs__msg__Envelope3D
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Envelope3D {
    /// Name of the envelope curve set
    pub set: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub format: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub data: rosidl_runtime_rs::String,

    /// Protocol and url-definition for downloading the 3D-envelope curve data
    pub url: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub description: rosidl_runtime_rs::String,

}



impl Default for Envelope3D {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !vda5050_msgs__msg__Envelope3D__init(&mut msg as *mut _) {
        panic!("Call to vda5050_msgs__msg__Envelope3D__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Envelope3D {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__Envelope3D__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__Envelope3D__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__Envelope3D__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Envelope3D {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Envelope3D where Self: Sized {
  const TYPE_NAME: &'static str = "vda5050_msgs/msg/Envelope3D";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__Envelope3D() }
  }
}


#[link(name = "vda5050_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__Error() -> *const std::ffi::c_void;
}

#[link(name = "vda5050_msgs__rosidl_generator_c")]
extern "C" {
    fn vda5050_msgs__msg__Error__init(msg: *mut Error) -> bool;
    fn vda5050_msgs__msg__Error__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Error>, size: usize) -> bool;
    fn vda5050_msgs__msg__Error__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Error>);
    fn vda5050_msgs__msg__Error__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Error>, out_seq: *mut rosidl_runtime_rs::Sequence<Error>) -> bool;
}

// Corresponds to vda5050_msgs__msg__Error
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Error {
    /// Type / name of error
    pub error_type: rosidl_runtime_rs::String,

    /// Array of references to identify the source of the error (e. g. header_id,
    /// order_id, action_id, …). For additional information see best practice
    /// chapter 6.3
    pub error_references: rosidl_runtime_rs::Sequence<super::super::msg::rmw::ErrorReference>,

    /// Error description
    pub error_description: rosidl_runtime_rs::String,

    /// Enum {warning, fatal} warning: AGV is ready to start (e.g. maintenance
    /// cycle expiration warning) fatal: AGV is not in running condition, user
    /// intervention required (e.g. laser scanner is contaminated)
    pub error_level: rosidl_runtime_rs::String,

}

impl Error {
    /// Enums for error_level
    pub const WARNING: &'static str = "WARNING";


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FATAL: &'static str = "FATAL";

}


impl Default for Error {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !vda5050_msgs__msg__Error__init(&mut msg as *mut _) {
        panic!("Call to vda5050_msgs__msg__Error__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Error {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__Error__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__Error__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__Error__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Error {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Error where Self: Sized {
  const TYPE_NAME: &'static str = "vda5050_msgs/msg/Error";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__Error() }
  }
}


#[link(name = "vda5050_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__ErrorReference() -> *const std::ffi::c_void;
}

#[link(name = "vda5050_msgs__rosidl_generator_c")]
extern "C" {
    fn vda5050_msgs__msg__ErrorReference__init(msg: *mut ErrorReference) -> bool;
    fn vda5050_msgs__msg__ErrorReference__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ErrorReference>, size: usize) -> bool;
    fn vda5050_msgs__msg__ErrorReference__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ErrorReference>);
    fn vda5050_msgs__msg__ErrorReference__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ErrorReference>, out_seq: *mut rosidl_runtime_rs::Sequence<ErrorReference>) -> bool;
}

// Corresponds to vda5050_msgs__msg__ErrorReference
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ErrorReference {
    /// References the type of reference (e. g. header_id, order_id, action_id, …).
    pub reference_key: rosidl_runtime_rs::String,

    /// References the value the reference key.
    pub reference_value: rosidl_runtime_rs::String,

}



impl Default for ErrorReference {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !vda5050_msgs__msg__ErrorReference__init(&mut msg as *mut _) {
        panic!("Call to vda5050_msgs__msg__ErrorReference__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ErrorReference {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__ErrorReference__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__ErrorReference__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__ErrorReference__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ErrorReference {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ErrorReference where Self: Sized {
  const TYPE_NAME: &'static str = "vda5050_msgs/msg/ErrorReference";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__ErrorReference() }
  }
}


#[link(name = "vda5050_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__Factsheet() -> *const std::ffi::c_void;
}

#[link(name = "vda5050_msgs__rosidl_generator_c")]
extern "C" {
    fn vda5050_msgs__msg__Factsheet__init(msg: *mut Factsheet) -> bool;
    fn vda5050_msgs__msg__Factsheet__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Factsheet>, size: usize) -> bool;
    fn vda5050_msgs__msg__Factsheet__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Factsheet>);
    fn vda5050_msgs__msg__Factsheet__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Factsheet>, out_seq: *mut rosidl_runtime_rs::Sequence<Factsheet>) -> bool;
}

// Corresponds to vda5050_msgs__msg__Factsheet
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// HEADER

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Factsheet {
    /// header ID of the message. The headerId is defined per topic and incremented by 1 with each sent
    /// (but not necessarily received) message.
    pub header_id: u32,

    /// Timestamp after ISO8601 in the format YYYY-MM-DDTHH:mm:ss.ssZ (e.g.“2017-04-15T11:40:03.12Z”)
    pub timestamp: rosidl_runtime_rs::String,

    /// Version of the protocol [Major].[Minor].[Patch] (e.g. 1.3.2)
    pub version: rosidl_runtime_rs::String,

    /// Manufacturer of the AGV
    pub manufacturer: rosidl_runtime_rs::String,

    /// Serial Number of the AGV
    pub serial_number: rosidl_runtime_rs::String,

    /// CONTENTS
    /// Class and capabilities of the AGV
    pub type_specification: super::super::msg::rmw::TypeSpecification,

    /// Physical properties of the AGV
    pub physical_parameters: super::super::msg::rmw::PhysicalParameters,

    /// Protocol limitations of the AGV
    pub protocol_limits: super::super::msg::rmw::ProtocolLimits,

    /// Supported and/or required optional parameters
    pub protocol_features: super::super::msg::rmw::ProtocolFeatures,

    /// Detailed definition of AGV geometry
    pub agv_geometry: super::super::msg::rmw::AGVGeometry,

    /// Load positions / load handling devices
    pub load_specification: super::super::msg::rmw::LoadSpecification,

    /// Detailed specification of localization
    pub localization_parameters: i32,

}



impl Default for Factsheet {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !vda5050_msgs__msg__Factsheet__init(&mut msg as *mut _) {
        panic!("Call to vda5050_msgs__msg__Factsheet__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Factsheet {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__Factsheet__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__Factsheet__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__Factsheet__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Factsheet {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Factsheet where Self: Sized {
  const TYPE_NAME: &'static str = "vda5050_msgs/msg/Factsheet";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__Factsheet() }
  }
}


#[link(name = "vda5050_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__Info() -> *const std::ffi::c_void;
}

#[link(name = "vda5050_msgs__rosidl_generator_c")]
extern "C" {
    fn vda5050_msgs__msg__Info__init(msg: *mut Info) -> bool;
    fn vda5050_msgs__msg__Info__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Info>, size: usize) -> bool;
    fn vda5050_msgs__msg__Info__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Info>);
    fn vda5050_msgs__msg__Info__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Info>, out_seq: *mut rosidl_runtime_rs::Sequence<Info>) -> bool;
}

// Corresponds to vda5050_msgs__msg__Info
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Info {
    /// Type / name of information
    pub info_type: rosidl_runtime_rs::String,

    /// array of references
    pub info_references: rosidl_runtime_rs::Sequence<super::super::msg::rmw::InfoReference>,

    /// Info description
    pub info_description: rosidl_runtime_rs::String,

    /// Enum {DEBUG, INFO} DEBUG: used for debugging, INFO: used for visualization
    pub info_level: rosidl_runtime_rs::String,

}

impl Info {

    // This constant is not documented.
    #[allow(missing_docs)]
    pub const DEBUG: &'static str = "DEBUG";


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const INFO: &'static str = "INFO";

}


impl Default for Info {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !vda5050_msgs__msg__Info__init(&mut msg as *mut _) {
        panic!("Call to vda5050_msgs__msg__Info__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Info {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__Info__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__Info__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__Info__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Info {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Info where Self: Sized {
  const TYPE_NAME: &'static str = "vda5050_msgs/msg/Info";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__Info() }
  }
}


#[link(name = "vda5050_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__InfoReference() -> *const std::ffi::c_void;
}

#[link(name = "vda5050_msgs__rosidl_generator_c")]
extern "C" {
    fn vda5050_msgs__msg__InfoReference__init(msg: *mut InfoReference) -> bool;
    fn vda5050_msgs__msg__InfoReference__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<InfoReference>, size: usize) -> bool;
    fn vda5050_msgs__msg__InfoReference__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<InfoReference>);
    fn vda5050_msgs__msg__InfoReference__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<InfoReference>, out_seq: *mut rosidl_runtime_rs::Sequence<InfoReference>) -> bool;
}

// Corresponds to vda5050_msgs__msg__InfoReference
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct InfoReference {
    /// References the type of reference (e. g. headerId, orderId, actionId, …).
    pub reference_key: rosidl_runtime_rs::String,

    /// References the value the reference key.
    pub reference_value: rosidl_runtime_rs::String,

}



impl Default for InfoReference {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !vda5050_msgs__msg__InfoReference__init(&mut msg as *mut _) {
        panic!("Call to vda5050_msgs__msg__InfoReference__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for InfoReference {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__InfoReference__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__InfoReference__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__InfoReference__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for InfoReference {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for InfoReference where Self: Sized {
  const TYPE_NAME: &'static str = "vda5050_msgs/msg/InfoReference";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__InfoReference() }
  }
}


#[link(name = "vda5050_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__Header() -> *const std::ffi::c_void;
}

#[link(name = "vda5050_msgs__rosidl_generator_c")]
extern "C" {
    fn vda5050_msgs__msg__Header__init(msg: *mut Header) -> bool;
    fn vda5050_msgs__msg__Header__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Header>, size: usize) -> bool;
    fn vda5050_msgs__msg__Header__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Header>);
    fn vda5050_msgs__msg__Header__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Header>, out_seq: *mut rosidl_runtime_rs::Sequence<Header>) -> bool;
}

// Corresponds to vda5050_msgs__msg__Header
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Header {
    /// header ID of the message. The header_id is defined per topic and incremented by 1 with each sent
    /// (but not necessarily received) message.
    pub header_id: i32,

    /// Timestamp after ISO8601 in the format YYYY-MM-DDTHH:mm:ss.ssZ (e.g.“2017-04-15T11:40:03.12Z”)
    pub timestamp: rosidl_runtime_rs::String,

    /// Version of the protocol [Major].[Minor].[Patch] (e.g. 1.3.2)
    pub version: rosidl_runtime_rs::String,

    /// Manufacturer of the AGV
    pub manufacturer: rosidl_runtime_rs::String,

    /// Serial Number of the AGV
    pub serial_number: rosidl_runtime_rs::String,

}



impl Default for Header {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !vda5050_msgs__msg__Header__init(&mut msg as *mut _) {
        panic!("Call to vda5050_msgs__msg__Header__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Header {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__Header__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__Header__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__Header__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Header {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Header where Self: Sized {
  const TYPE_NAME: &'static str = "vda5050_msgs/msg/Header";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__Header() }
  }
}


#[link(name = "vda5050_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__InstantActions() -> *const std::ffi::c_void;
}

#[link(name = "vda5050_msgs__rosidl_generator_c")]
extern "C" {
    fn vda5050_msgs__msg__InstantActions__init(msg: *mut InstantActions) -> bool;
    fn vda5050_msgs__msg__InstantActions__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<InstantActions>, size: usize) -> bool;
    fn vda5050_msgs__msg__InstantActions__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<InstantActions>);
    fn vda5050_msgs__msg__InstantActions__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<InstantActions>, out_seq: *mut rosidl_runtime_rs::Sequence<InstantActions>) -> bool;
}

// Corresponds to vda5050_msgs__msg__InstantActions
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct InstantActions {
    /// header ID of the message. The headerId is defined per topic and incremented by 1 with each sent
    /// (but not necessarily received) message.
    pub header_id: u32,

    /// Timestamp after ISO8601 in the format YYYY-MM-DDTHH:mm:ss.ssZ (e.g.“2017-04-15T11:40:03.12Z”)
    pub timestamp: rosidl_runtime_rs::String,

    /// Version of the protocol [Major].[Minor].[Patch] (e.g. 1.3.2)
    pub version: rosidl_runtime_rs::String,

    /// Manufacturer of the AGV
    pub manufacturer: rosidl_runtime_rs::String,

    /// Serial Number of the AGV
    pub serial_number: rosidl_runtime_rs::String,

    /// List of actions to execute
    pub actions: rosidl_runtime_rs::Sequence<super::super::msg::rmw::Action>,

}



impl Default for InstantActions {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !vda5050_msgs__msg__InstantActions__init(&mut msg as *mut _) {
        panic!("Call to vda5050_msgs__msg__InstantActions__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for InstantActions {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__InstantActions__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__InstantActions__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__InstantActions__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for InstantActions {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for InstantActions where Self: Sized {
  const TYPE_NAME: &'static str = "vda5050_msgs/msg/InstantActions";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__InstantActions() }
  }
}


#[link(name = "vda5050_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__Load() -> *const std::ffi::c_void;
}

#[link(name = "vda5050_msgs__rosidl_generator_c")]
extern "C" {
    fn vda5050_msgs__msg__Load__init(msg: *mut Load) -> bool;
    fn vda5050_msgs__msg__Load__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Load>, size: usize) -> bool;
    fn vda5050_msgs__msg__Load__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Load>);
    fn vda5050_msgs__msg__Load__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Load>, out_seq: *mut rosidl_runtime_rs::Sequence<Load>) -> bool;
}

// Corresponds to vda5050_msgs__msg__Load
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Load {
    /// Unique identification number of the load (e. g. barcode or
    /// RFID)
    pub load_id: rosidl_runtime_rs::String,

    /// Type of load
    pub load_type: rosidl_runtime_rs::String,

    /// Indicates which load handling/carrying unit of the AGV is
    /// used, e. g. in case the AGV has multiple spots/positions to
    /// carry loads. For example: “front”, “back”, “positionC1”, etc.
    pub load_position: rosidl_runtime_rs::String,

    /// Point of reference for the location of the bounding box. The
    /// point of reference is always the center of the bounding box’s
    /// bottom surface (at height = 0) and is described in coordinates
    /// of the AGV’s coordinate system.
    pub bounding_box_reference: super::super::msg::rmw::BoundingBoxReference,

    /// Dimensions of the load’s bounding box in meters.
    pub load_dimensions: super::super::msg::rmw::LoadDimensions,

    /// Absolute weight of the load measured in kg.
    pub weight: f64,

}



impl Default for Load {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !vda5050_msgs__msg__Load__init(&mut msg as *mut _) {
        panic!("Call to vda5050_msgs__msg__Load__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Load {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__Load__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__Load__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__Load__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Load {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Load where Self: Sized {
  const TYPE_NAME: &'static str = "vda5050_msgs/msg/Load";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__Load() }
  }
}


#[link(name = "vda5050_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__LoadDimensions() -> *const std::ffi::c_void;
}

#[link(name = "vda5050_msgs__rosidl_generator_c")]
extern "C" {
    fn vda5050_msgs__msg__LoadDimensions__init(msg: *mut LoadDimensions) -> bool;
    fn vda5050_msgs__msg__LoadDimensions__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<LoadDimensions>, size: usize) -> bool;
    fn vda5050_msgs__msg__LoadDimensions__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<LoadDimensions>);
    fn vda5050_msgs__msg__LoadDimensions__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<LoadDimensions>, out_seq: *mut rosidl_runtime_rs::Sequence<LoadDimensions>) -> bool;
}

// Corresponds to vda5050_msgs__msg__LoadDimensions
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// Dimensions of the load’s bounding box in meters.

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct LoadDimensions {
    /// Absolute length of the load’s bounding box.
    pub length: f64,

    /// Absolute width of the load’s bounding box.
    pub width: f64,

    /// Absolute height of the load’s bounding box. Optional: Set value only if known.
    pub height: f64,

}



impl Default for LoadDimensions {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !vda5050_msgs__msg__LoadDimensions__init(&mut msg as *mut _) {
        panic!("Call to vda5050_msgs__msg__LoadDimensions__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for LoadDimensions {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__LoadDimensions__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__LoadDimensions__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__LoadDimensions__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for LoadDimensions {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for LoadDimensions where Self: Sized {
  const TYPE_NAME: &'static str = "vda5050_msgs/msg/LoadDimensions";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__LoadDimensions() }
  }
}


#[link(name = "vda5050_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__LoadSet() -> *const std::ffi::c_void;
}

#[link(name = "vda5050_msgs__rosidl_generator_c")]
extern "C" {
    fn vda5050_msgs__msg__LoadSet__init(msg: *mut LoadSet) -> bool;
    fn vda5050_msgs__msg__LoadSet__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<LoadSet>, size: usize) -> bool;
    fn vda5050_msgs__msg__LoadSet__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<LoadSet>);
    fn vda5050_msgs__msg__LoadSet__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<LoadSet>, out_seq: *mut rosidl_runtime_rs::Sequence<LoadSet>) -> bool;
}

// Corresponds to vda5050_msgs__msg__LoadSet
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct LoadSet {

    // This member is not documented.
    #[allow(missing_docs)]
    pub set_name: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub load_type: rosidl_runtime_rs::String,

    /// List of load positions / load handling devices
    pub load_positions: rosidl_runtime_rs::Sequence<rosidl_runtime_rs::String>,

    /// Bounding box reference as defined in parameter loads[] in state-message
    pub bounding_box_reference: super::super::msg::rmw::BoundingBoxReference,


    // This member is not documented.
    #[allow(missing_docs)]
    pub load_dimensions: super::super::msg::rmw::LoadDimensions,

    /// Maximum weight of load type
    pub max_weight: f64,

    /// Minimum allowed height for handling of this load-type and weight
    pub min_loadhandling_height: f64,

    /// Maximum allowed height for handling of this load-type and weight
    pub max_loadhandling_height: f64,

    /// Minimum allowed depth for this load-type and weight
    pub min_loadhandling_depth: f64,

    /// Maximum allowed depth for this load-type and weight
    pub max_loadhandling_depth: f64,

    /// Minimum allowed tilt for this load-type and weight
    pub min_loadhandling_tilt: f64,

    /// Maximum allowed tilt for this load-type and weight
    pub max_loadhandling_tilt: f64,

    /// Maximum allowed speed for this load-type and weight
    pub agv_speed_limit: f64,

    /// Maximum allowed acceleration for this load-type and weight
    pub agv_acceleration_limit: f64,

    /// Maximum allowed deceleration for this load-type and weight
    pub agv_deceleration_limit: f64,

    /// Approx. time for picking up the load
    pub pick_time: f64,

    /// Approx. time for dropping the load
    pub drop_time: f64,

    /// Free description of the load handling set
    pub description: rosidl_runtime_rs::String,

}



impl Default for LoadSet {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !vda5050_msgs__msg__LoadSet__init(&mut msg as *mut _) {
        panic!("Call to vda5050_msgs__msg__LoadSet__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for LoadSet {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__LoadSet__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__LoadSet__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__LoadSet__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for LoadSet {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for LoadSet where Self: Sized {
  const TYPE_NAME: &'static str = "vda5050_msgs/msg/LoadSet";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__LoadSet() }
  }
}


#[link(name = "vda5050_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__LoadSpecification() -> *const std::ffi::c_void;
}

#[link(name = "vda5050_msgs__rosidl_generator_c")]
extern "C" {
    fn vda5050_msgs__msg__LoadSpecification__init(msg: *mut LoadSpecification) -> bool;
    fn vda5050_msgs__msg__LoadSpecification__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<LoadSpecification>, size: usize) -> bool;
    fn vda5050_msgs__msg__LoadSpecification__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<LoadSpecification>);
    fn vda5050_msgs__msg__LoadSpecification__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<LoadSpecification>, out_seq: *mut rosidl_runtime_rs::Sequence<LoadSpecification>) -> bool;
}

// Corresponds to vda5050_msgs__msg__LoadSpecification
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct LoadSpecification {
    /// List of load positions / load handling devices
    pub load_positions: rosidl_runtime_rs::Sequence<rosidl_runtime_rs::String>,

    /// List of load-sets that can be handled by the AGV
    pub load_sets: rosidl_runtime_rs::Sequence<super::super::msg::rmw::LoadSet>,

}



impl Default for LoadSpecification {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !vda5050_msgs__msg__LoadSpecification__init(&mut msg as *mut _) {
        panic!("Call to vda5050_msgs__msg__LoadSpecification__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for LoadSpecification {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__LoadSpecification__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__LoadSpecification__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__LoadSpecification__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for LoadSpecification {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for LoadSpecification where Self: Sized {
  const TYPE_NAME: &'static str = "vda5050_msgs/msg/LoadSpecification";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__LoadSpecification() }
  }
}


#[link(name = "vda5050_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__MaxArrayLens() -> *const std::ffi::c_void;
}

#[link(name = "vda5050_msgs__rosidl_generator_c")]
extern "C" {
    fn vda5050_msgs__msg__MaxArrayLens__init(msg: *mut MaxArrayLens) -> bool;
    fn vda5050_msgs__msg__MaxArrayLens__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<MaxArrayLens>, size: usize) -> bool;
    fn vda5050_msgs__msg__MaxArrayLens__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<MaxArrayLens>);
    fn vda5050_msgs__msg__MaxArrayLens__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<MaxArrayLens>, out_seq: *mut rosidl_runtime_rs::Sequence<MaxArrayLens>) -> bool;
}

// Corresponds to vda5050_msgs__msg__MaxArrayLens
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MaxArrayLens {
    /// Maximum number of nodes per order processable by the AGV
    pub order_nodes: u32,

    /// Maximum number of edges per order processable by the AGV
    pub order_edges: u32,

    /// Maximum number of action per node processable by the AGV
    pub node_actions: u32,

    /// Maximum number of action per edge processable by the AGV
    pub edge_actions: u32,

    /// Maximum number of parameters per action processable by the AGV
    pub actions_parameters: u32,

    /// Maximum number of instant actions per message processable by the AGV
    pub instant_actions: u32,

    /// Maximum number of knots per trajectory processable by the AGV
    pub trajectory_knot_vector: u32,

    /// Maximum number of control points per trajectory processable by the AGV
    pub trajectory_control_points: u32,

    /// Maximum number of nodeStates sent by the AGV, maximum number of nodes in base of AGV
    pub state_node_states: u32,

    /// Maximum number of edgeStates sent by the AGV, maximum number of edges in base of AGV
    pub state_edge_states: u32,

    /// Maximum number of load-objects sent by the AGV
    pub state_loads: u32,

    /// Maximum number of actionStates sent by the AGV
    pub state_action_states: u32,

    /// Maximum number of errors sent by the AGV in one state-message
    pub state_errors: u32,

    /// Maximum number of information objects sent by the AGV in one state-message
    pub state_information: u32,

    /// Maximum number of error references sent by the AGV for each error
    pub error_references: u32,

    /// Maximum number of info references sent by the AGV for each information
    pub info_references: u32,

}



impl Default for MaxArrayLens {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !vda5050_msgs__msg__MaxArrayLens__init(&mut msg as *mut _) {
        panic!("Call to vda5050_msgs__msg__MaxArrayLens__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for MaxArrayLens {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__MaxArrayLens__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__MaxArrayLens__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__MaxArrayLens__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for MaxArrayLens {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for MaxArrayLens where Self: Sized {
  const TYPE_NAME: &'static str = "vda5050_msgs/msg/MaxArrayLens";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__MaxArrayLens() }
  }
}


#[link(name = "vda5050_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__MaxStringLens() -> *const std::ffi::c_void;
}

#[link(name = "vda5050_msgs__rosidl_generator_c")]
extern "C" {
    fn vda5050_msgs__msg__MaxStringLens__init(msg: *mut MaxStringLens) -> bool;
    fn vda5050_msgs__msg__MaxStringLens__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<MaxStringLens>, size: usize) -> bool;
    fn vda5050_msgs__msg__MaxStringLens__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<MaxStringLens>);
    fn vda5050_msgs__msg__MaxStringLens__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<MaxStringLens>, out_seq: *mut rosidl_runtime_rs::Sequence<MaxStringLens>) -> bool;
}

// Corresponds to vda5050_msgs__msg__MaxStringLens
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MaxStringLens {
    /// Maximum MQTT Message length
    pub msg_len: u32,

    /// Maximum length of serial-number part in MQTT-topics
    pub topic_serial_len: u32,

    /// Maximum length of all other parts in MQTT-topics (timestamp, versions, manufacturer)
    pub topic_elem_len: u32,

    /// Maximum length of ID-Strings
    pub id_len: u32,

    /// If true ID-strings need to contain numerical values only
    pub id_numerical_only: bool,

    /// Maximum length of ENUM- and Key-Strings
    pub enum_len: u32,

    /// Maximum length of loadId Strings
    pub load_id_len: u32,

}



impl Default for MaxStringLens {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !vda5050_msgs__msg__MaxStringLens__init(&mut msg as *mut _) {
        panic!("Call to vda5050_msgs__msg__MaxStringLens__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for MaxStringLens {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__MaxStringLens__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__MaxStringLens__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__MaxStringLens__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for MaxStringLens {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for MaxStringLens where Self: Sized {
  const TYPE_NAME: &'static str = "vda5050_msgs/msg/MaxStringLens";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__MaxStringLens() }
  }
}


#[link(name = "vda5050_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__Node() -> *const std::ffi::c_void;
}

#[link(name = "vda5050_msgs__rosidl_generator_c")]
extern "C" {
    fn vda5050_msgs__msg__Node__init(msg: *mut Node) -> bool;
    fn vda5050_msgs__msg__Node__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Node>, size: usize) -> bool;
    fn vda5050_msgs__msg__Node__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Node>);
    fn vda5050_msgs__msg__Node__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Node>, out_seq: *mut rosidl_runtime_rs::Sequence<Node>) -> bool;
}

// Corresponds to vda5050_msgs__msg__Node
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// Array of nodes to be traversed for fulfilling the order

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Node {
    /// Unique node identification.
    pub node_id: rosidl_runtime_rs::String,

    /// Id to track the sequence of nodes and edges in an order and to
    /// simplify order updates. The variable sequence_id runs across all
    /// nodes and edges of the same order and is reset when a new order_id is
    /// issued.
    pub sequence_id: u32,

    /// Additional information on the node
    pub node_description: rosidl_runtime_rs::String,

    /// True indicates that the node is part of the base. False indicates
    /// that the node is part of the horizon.
    pub released: bool,

    /// Node position
    pub node_position: super::super::msg::rmw::NodePosition,

    /// Array of actions to be executed in node. Empty array if no actions
    /// required. An action triggered by a node will persist until changed
    /// in another node unless restricted by duration_type/duration_value.
    pub actions: rosidl_runtime_rs::Sequence<super::super::msg::rmw::Action>,

}



impl Default for Node {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !vda5050_msgs__msg__Node__init(&mut msg as *mut _) {
        panic!("Call to vda5050_msgs__msg__Node__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Node {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__Node__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__Node__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__Node__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Node {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Node where Self: Sized {
  const TYPE_NAME: &'static str = "vda5050_msgs/msg/Node";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__Node() }
  }
}


#[link(name = "vda5050_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__NodePosition() -> *const std::ffi::c_void;
}

#[link(name = "vda5050_msgs__rosidl_generator_c")]
extern "C" {
    fn vda5050_msgs__msg__NodePosition__init(msg: *mut NodePosition) -> bool;
    fn vda5050_msgs__msg__NodePosition__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<NodePosition>, size: usize) -> bool;
    fn vda5050_msgs__msg__NodePosition__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<NodePosition>);
    fn vda5050_msgs__msg__NodePosition__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<NodePosition>, out_seq: *mut rosidl_runtime_rs::Sequence<NodePosition>) -> bool;
}

// Corresponds to vda5050_msgs__msg__NodePosition
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// Defines the position on a map in world coordinates. Each floor has its own map.

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct NodePosition {
    /// X-position on the map in reference to the world coordinate system
    pub x: f64,

    /// Y-position on the map in reference to the world coordinate system
    pub y: f64,

    /// The angular dimension
    pub theta: f64,

    /// Indicates how exact an AGV has to drive over a node in order for it
    /// to count as traversed.
    ///
    /// If = 0: no deviation is allowed (no deviation means within the
    /// normal tolerance of the AGV manufacturer).
    ///
    /// If > 0: allowed deviationradius in meters. If the AGV passes a node
    /// within the deviation-radius, the node is considered to have been
    /// traversed.
    pub allowed_deviation_x_y: f32,

    /// Range:
    /// Indicates how big the deviation of theta angle can be.
    /// The lowest acceptable angle  is theta -allowedDevaitionTheta and
    /// the  highest acceptable angle is theta + allowedDeviationTheta
    pub allowed_deviation_theta: f32,

    /// Unique identification of the map in which the position is referenced. Each map has the same
    /// origin of coordinates. When an AGV uses an elevator, e. g. leading from a departure floor to a
    /// target floor, it will disappear off the map of the departure floor and spawn in the related
    /// lift node on the map of the target floor.
    pub map_id: rosidl_runtime_rs::String,

    /// Additional information on the map
    pub map_description: rosidl_runtime_rs::String,

}



impl Default for NodePosition {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !vda5050_msgs__msg__NodePosition__init(&mut msg as *mut _) {
        panic!("Call to vda5050_msgs__msg__NodePosition__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for NodePosition {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__NodePosition__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__NodePosition__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__NodePosition__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for NodePosition {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for NodePosition where Self: Sized {
  const TYPE_NAME: &'static str = "vda5050_msgs/msg/NodePosition";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__NodePosition() }
  }
}


#[link(name = "vda5050_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__NodeState() -> *const std::ffi::c_void;
}

#[link(name = "vda5050_msgs__rosidl_generator_c")]
extern "C" {
    fn vda5050_msgs__msg__NodeState__init(msg: *mut NodeState) -> bool;
    fn vda5050_msgs__msg__NodeState__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<NodeState>, size: usize) -> bool;
    fn vda5050_msgs__msg__NodeState__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<NodeState>);
    fn vda5050_msgs__msg__NodeState__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<NodeState>, out_seq: *mut rosidl_runtime_rs::Sequence<NodeState>) -> bool;
}

// Corresponds to vda5050_msgs__msg__NodeState
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// Array of nodes to be traversed for fulfilling the order

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct NodeState {
    /// Unique node identification
    pub node_id: rosidl_runtime_rs::String,

    /// sequenceId to discern multiple nodes with same nodeId.
    pub sequence_id: u32,

    /// Additional information on the node
    pub node_description: rosidl_runtime_rs::String,

    /// Node position (see Topic: Order)
    pub node_position: super::super::msg::rmw::NodePosition,

    /// true indicates that the node is part of the base.
    /// false indicates that the node is part of the horizon.
    pub released: bool,

}



impl Default for NodeState {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !vda5050_msgs__msg__NodeState__init(&mut msg as *mut _) {
        panic!("Call to vda5050_msgs__msg__NodeState__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for NodeState {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__NodeState__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__NodeState__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__NodeState__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for NodeState {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for NodeState where Self: Sized {
  const TYPE_NAME: &'static str = "vda5050_msgs/msg/NodeState";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__NodeState() }
  }
}


#[link(name = "vda5050_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__OptionalParameter() -> *const std::ffi::c_void;
}

#[link(name = "vda5050_msgs__rosidl_generator_c")]
extern "C" {
    fn vda5050_msgs__msg__OptionalParameter__init(msg: *mut OptionalParameter) -> bool;
    fn vda5050_msgs__msg__OptionalParameter__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<OptionalParameter>, size: usize) -> bool;
    fn vda5050_msgs__msg__OptionalParameter__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<OptionalParameter>);
    fn vda5050_msgs__msg__OptionalParameter__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<OptionalParameter>, out_seq: *mut rosidl_runtime_rs::Sequence<OptionalParameter>) -> bool;
}

// Corresponds to vda5050_msgs__msg__OptionalParameter
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct OptionalParameter {
    /// Full name of optional parameter
    pub parameter: rosidl_runtime_rs::String,

    /// Type of support for the optional parameter
    pub support: rosidl_runtime_rs::String,

    /// Description of optional parameter
    pub description: rosidl_runtime_rs::String,

}

impl OptionalParameter {
    /// Enums for support
    pub const SUPPORTED: &'static str = "SUPPORTED";


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const REQUIRED: &'static str = "REQUIRED";

}


impl Default for OptionalParameter {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !vda5050_msgs__msg__OptionalParameter__init(&mut msg as *mut _) {
        panic!("Call to vda5050_msgs__msg__OptionalParameter__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for OptionalParameter {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__OptionalParameter__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__OptionalParameter__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__OptionalParameter__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for OptionalParameter {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for OptionalParameter where Self: Sized {
  const TYPE_NAME: &'static str = "vda5050_msgs/msg/OptionalParameter";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__OptionalParameter() }
  }
}


#[link(name = "vda5050_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__Order() -> *const std::ffi::c_void;
}

#[link(name = "vda5050_msgs__rosidl_generator_c")]
extern "C" {
    fn vda5050_msgs__msg__Order__init(msg: *mut Order) -> bool;
    fn vda5050_msgs__msg__Order__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Order>, size: usize) -> bool;
    fn vda5050_msgs__msg__Order__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Order>);
    fn vda5050_msgs__msg__Order__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Order>, out_seq: *mut rosidl_runtime_rs::Sequence<Order>) -> bool;
}

// Corresponds to vda5050_msgs__msg__Order
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// HEADER

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Order {
    /// header ID of the message. The header_id is defined per topic and incremented by 1 with each sent
    /// (but not necessarily received) message.
    pub header_id: u32,

    /// Timestamp after ISO8601 in the format YYYY-MM-DDTHH:mm:ss.ssZ (e.g.“2017-04-15T11:40:03.12Z”)
    pub timestamp: rosidl_runtime_rs::String,

    /// Version of the protocol [Major].[Minor].[Patch] (e.g. 1.3.2)
    pub version: rosidl_runtime_rs::String,

    /// Manufacturer of the AGV
    pub manufacturer: rosidl_runtime_rs::String,

    /// Serial Number of the AGV
    pub serial_number: rosidl_runtime_rs::String,

    /// CONTENTS
    /// Unique order identification
    pub order_id: rosidl_runtime_rs::String,

    /// order_update identification. Is unique per order_id. If an order update is
    /// rejected, this field is to be passed in the rejection message
    pub order_update_id: u32,

    /// Unique identifier of the zone set that the AGV has to use for navigation or that was used by master controlfor planning
    /// Optional: Some master controlsystems do not use zones. Some AGVs do not understand zones. Do not add to message if no zones are used
    pub zone_set_id: rosidl_runtime_rs::String,

    /// Array of nodes to be traversed for fulfilling the order. The nodes come
    /// in the sequence of the fulfilling.
    pub nodes: rosidl_runtime_rs::Sequence<super::super::msg::rmw::Node>,

    /// Array of edges to be traversed for fulfilling the order
    pub edges: rosidl_runtime_rs::Sequence<super::super::msg::rmw::Edge>,

}



impl Default for Order {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !vda5050_msgs__msg__Order__init(&mut msg as *mut _) {
        panic!("Call to vda5050_msgs__msg__Order__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Order {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__Order__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__Order__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__Order__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Order {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Order where Self: Sized {
  const TYPE_NAME: &'static str = "vda5050_msgs/msg/Order";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__Order() }
  }
}


#[link(name = "vda5050_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__OrderState() -> *const std::ffi::c_void;
}

#[link(name = "vda5050_msgs__rosidl_generator_c")]
extern "C" {
    fn vda5050_msgs__msg__OrderState__init(msg: *mut OrderState) -> bool;
    fn vda5050_msgs__msg__OrderState__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<OrderState>, size: usize) -> bool;
    fn vda5050_msgs__msg__OrderState__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<OrderState>);
    fn vda5050_msgs__msg__OrderState__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<OrderState>, out_seq: *mut rosidl_runtime_rs::Sequence<OrderState>) -> bool;
}

// Corresponds to vda5050_msgs__msg__OrderState
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// HEADER

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct OrderState {
    /// header ID of the message. The header_id is defined per topic and incremented by 1 with each sent
    /// (but not necessarily received) message.
    pub header_id: u32,

    /// Timestamp after ISO8601 in the format YYYY-MM-DDTHH:mm:ss.ssZ (e.g.“2017-04-15T11:40:03.12Z”)
    pub timestamp: rosidl_runtime_rs::String,

    /// Version of the protocol [Major].[Minor].[Patch] (e.g. 1.3.2)
    pub version: rosidl_runtime_rs::String,

    /// Manufacturer of the AGV
    pub manufacturer: rosidl_runtime_rs::String,

    /// Serial Number of the AGV
    pub serial_number: rosidl_runtime_rs::String,

    /// CONTENTS
    /// Unique order identification “none” if vehicle is idle and has no order
    pub order_id: rosidl_runtime_rs::String,

    /// order_update identification. Is unique per order_id. If an order update is rejected, this field is to be passed in the rejection message.
    pub order_update_id: u32,

    /// Unique ID of the zone set that the AGV currently uses for path planning. Must be the same as the one used in the order,
    /// otherwise the AGV hasto reject the order. Optional: If the AGV does not use zones, this field can be omitted.
    pub zone_set_id: rosidl_runtime_rs::String,

    /// nodeId of last reached node or, if AGV is currently on a node, current node (e.g. „node7”).
    /// Empty string ("") if no lastNodeId is available.
    pub last_node_id: rosidl_runtime_rs::String,

    /// sequence_id of the last reached node or, if the AGV is currently on a node, sequence_id of current node.
    /// “0” if no last_node_sequence_id is available.
    pub last_node_sequence_id: u32,

    /// Array of node_state_objects (empty list if idle)
    pub node_states: rosidl_runtime_rs::Sequence<super::super::msg::rmw::NodeState>,

    /// Array of edge_state_objects (empty list if idle)
    pub edge_states: rosidl_runtime_rs::Sequence<super::super::msg::rmw::EdgeState>,

    /// Current position of the AGV. Optional: Can only be omitted for
    /// AGVs without the capability to localize themselves, e.g. line
    /// guided AGVs.
    pub agv_position: super::super::msg::rmw::AGVPosition,

    /// AGV's velocity in vehicle coordinates
    pub velocity: super::super::msg::rmw::Velocity,

    /// Loads that are currently handled by the AGV.
    /// Optional: If AGV cannot determine load state, leave the array out of the state.
    /// If the  AGV  can determine the  load  state,  but  the  array  is  empty,  the  AGV  is considered unloaded.
    pub loads: rosidl_runtime_rs::Sequence<super::super::msg::rmw::Load>,

    /// True: indicates that the AGV is driving and/or rotating. Other
    /// movements of the AGV (e.g. lift movements) are not included here.
    /// False: indicates that the AGV is neither driving nor rotating
    pub driving: bool,

    /// True: AGV is currently in a paused state, either because of the push of a physical button on the AGV or
    /// because of an instantAction. The AGV can resume the order.
    /// False: The AGV is currently not in a paused state
    pub paused: bool,

    /// True: AGV is almost at the end of the base and will reduce speed if no new base is transmitted. Trigger for MC to send ne base
    /// False: no base update required
    pub new_base_request: bool,

    /// Used by line guided vehicles to indicate the distance it has been driving past the last_node_id. Distance is in meters
    pub distance_since_last_node: f64,

    /// Contains a list of the current actions and the actions which are
    /// yet to be finished. This may include actions from previous nodes
    /// that are still in progress. When an action is completed, an
    /// updated state message is published with action_status set to
    /// finished and if applicable with the corresponding
    /// result_description. Completed actions are omitted from the array
    pub action_states: rosidl_runtime_rs::Sequence<super::super::msg::rmw::CurrentAction>,

    /// Contains all batteryrelated information.
    pub battery_state: super::super::msg::rmw::BatteryState,

    /// Enum {AUTOMATIC, SEMIAUTOMATIC, MANUAL, SERVICE, TEACHIN}
    /// For additional information see chapter 6.2
    pub operating_mode: rosidl_runtime_rs::String,

    /// Array of errorobjects. Empty array if there are no errors.
    pub errors: rosidl_runtime_rs::Sequence<super::super::msg::rmw::Error>,

    /// Array of info-objects. An empty array indicates that the AGV has no information.
    /// This should only be used for visualization or debugging – it must not be used for logic in master control
    pub informations: rosidl_runtime_rs::Sequence<super::super::msg::rmw::Info>,

    /// Contains all safetyrelated information.
    /// Enums for operatingMode
    pub safety_state: super::super::msg::rmw::SafetyState,

}

impl OrderState {
    /// AGV is under full control of the supervisor. AGV drives and executes actions based on orders from the supervisor
    pub const AUTOMATIC: &'static str = "AUTOMATIC";

    /// AGV is under control of the supervisor. AGV drives and executes actions based on orders from the supervisor. The driving speeds is controlled by the HMI. (speed can’t exceed the speed of automatic mode) The steering is under automatic control. (non-safe HMI possible)
    pub const SEMIAUTOMATIC: &'static str = "SEMIAUTOMATIC";

    /// Supervisor is not in control of the AGV. Supervisor doesn’t send driving order or actions to the AGV. HMI can be used the control the steering and velocity and handling device of the AGV. Location of the AGV is send to the supervisor. When AGV enters or leaves this mode, it immediately clears all the orders. (safe HMI required)
    /// Supervisor is not in control of the AGV. Supervisor doesn’t send driving order or actions to the AGV. Authorized personal can reconfigure the AGV.
    pub const MANUAL: &'static str = "MANUAL";

    /// Supervisor is not in control of the AGV. Supervisor doesn’t send driving order or actions to the AGV. The AGV is being taught, e.g. mapping is done by a supervisor
    pub const SERVICE: &'static str = "SERVICE";


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const TEACHIN: &'static str = "TEACHIN";

}


impl Default for OrderState {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !vda5050_msgs__msg__OrderState__init(&mut msg as *mut _) {
        panic!("Call to vda5050_msgs__msg__OrderState__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for OrderState {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__OrderState__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__OrderState__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__OrderState__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for OrderState {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for OrderState where Self: Sized {
  const TYPE_NAME: &'static str = "vda5050_msgs/msg/OrderState";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__OrderState() }
  }
}


#[link(name = "vda5050_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__PhysicalParameters() -> *const std::ffi::c_void;
}

#[link(name = "vda5050_msgs__rosidl_generator_c")]
extern "C" {
    fn vda5050_msgs__msg__PhysicalParameters__init(msg: *mut PhysicalParameters) -> bool;
    fn vda5050_msgs__msg__PhysicalParameters__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<PhysicalParameters>, size: usize) -> bool;
    fn vda5050_msgs__msg__PhysicalParameters__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<PhysicalParameters>);
    fn vda5050_msgs__msg__PhysicalParameters__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<PhysicalParameters>, out_seq: *mut rosidl_runtime_rs::Sequence<PhysicalParameters>) -> bool;
}

// Corresponds to vda5050_msgs__msg__PhysicalParameters
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct PhysicalParameters {
    /// Minimal controlled continuous speed of the AGV
    pub speed_min: f64,

    /// Maximum speed of the AGV
    pub speed_max: f64,

    /// Maximum acceleration with maximum load
    pub acceleration_max: f64,

    /// Maximum deceleration with maximum load
    pub deceleration_max: f64,

    /// Minimum height of the AGV
    pub height_min: f64,

    /// Maximum height of the AGV
    pub height_max: f64,

    /// Width of the AGV
    pub width: f64,

    /// Length of the AGV
    pub length: f64,

}



impl Default for PhysicalParameters {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !vda5050_msgs__msg__PhysicalParameters__init(&mut msg as *mut _) {
        panic!("Call to vda5050_msgs__msg__PhysicalParameters__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for PhysicalParameters {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__PhysicalParameters__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__PhysicalParameters__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__PhysicalParameters__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for PhysicalParameters {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for PhysicalParameters where Self: Sized {
  const TYPE_NAME: &'static str = "vda5050_msgs/msg/PhysicalParameters";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__PhysicalParameters() }
  }
}


#[link(name = "vda5050_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__PolygonPoint() -> *const std::ffi::c_void;
}

#[link(name = "vda5050_msgs__rosidl_generator_c")]
extern "C" {
    fn vda5050_msgs__msg__PolygonPoint__init(msg: *mut PolygonPoint) -> bool;
    fn vda5050_msgs__msg__PolygonPoint__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<PolygonPoint>, size: usize) -> bool;
    fn vda5050_msgs__msg__PolygonPoint__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<PolygonPoint>);
    fn vda5050_msgs__msg__PolygonPoint__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<PolygonPoint>, out_seq: *mut rosidl_runtime_rs::Sequence<PolygonPoint>) -> bool;
}

// Corresponds to vda5050_msgs__msg__PolygonPoint
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct PolygonPoint {
    /// x-position of polygon-point
    pub x: f64,

    /// y-position of polygon-point
    pub y: f64,

}



impl Default for PolygonPoint {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !vda5050_msgs__msg__PolygonPoint__init(&mut msg as *mut _) {
        panic!("Call to vda5050_msgs__msg__PolygonPoint__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for PolygonPoint {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__PolygonPoint__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__PolygonPoint__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__PolygonPoint__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for PolygonPoint {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for PolygonPoint where Self: Sized {
  const TYPE_NAME: &'static str = "vda5050_msgs/msg/PolygonPoint";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__PolygonPoint() }
  }
}


#[link(name = "vda5050_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__Position() -> *const std::ffi::c_void;
}

#[link(name = "vda5050_msgs__rosidl_generator_c")]
extern "C" {
    fn vda5050_msgs__msg__Position__init(msg: *mut Position) -> bool;
    fn vda5050_msgs__msg__Position__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Position>, size: usize) -> bool;
    fn vda5050_msgs__msg__Position__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Position>);
    fn vda5050_msgs__msg__Position__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Position>, out_seq: *mut rosidl_runtime_rs::Sequence<Position>) -> bool;
}

// Corresponds to vda5050_msgs__msg__Position
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Position {
    /// x-position in AGV-coordinate system
    pub x: f64,

    /// y-position in AGV-coordinate system
    pub y: f64,

    /// orientation of wheel in AGV-coordinate system - necessary for fixed wheels
    pub theta: f64,

}



impl Default for Position {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !vda5050_msgs__msg__Position__init(&mut msg as *mut _) {
        panic!("Call to vda5050_msgs__msg__Position__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Position {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__Position__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__Position__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__Position__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Position {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Position where Self: Sized {
  const TYPE_NAME: &'static str = "vda5050_msgs/msg/Position";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__Position() }
  }
}


#[link(name = "vda5050_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__ProtocolFeatures() -> *const std::ffi::c_void;
}

#[link(name = "vda5050_msgs__rosidl_generator_c")]
extern "C" {
    fn vda5050_msgs__msg__ProtocolFeatures__init(msg: *mut ProtocolFeatures) -> bool;
    fn vda5050_msgs__msg__ProtocolFeatures__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ProtocolFeatures>, size: usize) -> bool;
    fn vda5050_msgs__msg__ProtocolFeatures__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ProtocolFeatures>);
    fn vda5050_msgs__msg__ProtocolFeatures__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ProtocolFeatures>, out_seq: *mut rosidl_runtime_rs::Sequence<ProtocolFeatures>) -> bool;
}

// Corresponds to vda5050_msgs__msg__ProtocolFeatures
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ProtocolFeatures {
    /// List of supported and/or required optional parameters
    pub optional_parameters: rosidl_runtime_rs::Sequence<super::super::msg::rmw::OptionalParameter>,

    /// List of all actions with parameters supported by this AGV
    pub agv_actions: rosidl_runtime_rs::Sequence<super::super::msg::rmw::AGVAction>,

}



impl Default for ProtocolFeatures {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !vda5050_msgs__msg__ProtocolFeatures__init(&mut msg as *mut _) {
        panic!("Call to vda5050_msgs__msg__ProtocolFeatures__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ProtocolFeatures {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__ProtocolFeatures__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__ProtocolFeatures__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__ProtocolFeatures__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ProtocolFeatures {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ProtocolFeatures where Self: Sized {
  const TYPE_NAME: &'static str = "vda5050_msgs/msg/ProtocolFeatures";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__ProtocolFeatures() }
  }
}


#[link(name = "vda5050_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__ProtocolLimits() -> *const std::ffi::c_void;
}

#[link(name = "vda5050_msgs__rosidl_generator_c")]
extern "C" {
    fn vda5050_msgs__msg__ProtocolLimits__init(msg: *mut ProtocolLimits) -> bool;
    fn vda5050_msgs__msg__ProtocolLimits__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ProtocolLimits>, size: usize) -> bool;
    fn vda5050_msgs__msg__ProtocolLimits__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ProtocolLimits>);
    fn vda5050_msgs__msg__ProtocolLimits__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ProtocolLimits>, out_seq: *mut rosidl_runtime_rs::Sequence<ProtocolLimits>) -> bool;
}

// Corresponds to vda5050_msgs__msg__ProtocolLimits
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ProtocolLimits {
    /// Maximum lengths of strings
    pub max_string_lens: super::super::msg::rmw::MaxStringLens,

    /// Maximum lengths of arrays
    pub max_array_lens: super::super::msg::rmw::MaxArrayLens,

    /// Timing information
    pub timing: super::super::msg::rmw::Timing,

}



impl Default for ProtocolLimits {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !vda5050_msgs__msg__ProtocolLimits__init(&mut msg as *mut _) {
        panic!("Call to vda5050_msgs__msg__ProtocolLimits__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ProtocolLimits {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__ProtocolLimits__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__ProtocolLimits__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__ProtocolLimits__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ProtocolLimits {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ProtocolLimits where Self: Sized {
  const TYPE_NAME: &'static str = "vda5050_msgs/msg/ProtocolLimits";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__ProtocolLimits() }
  }
}


#[link(name = "vda5050_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__SafetyState() -> *const std::ffi::c_void;
}

#[link(name = "vda5050_msgs__rosidl_generator_c")]
extern "C" {
    fn vda5050_msgs__msg__SafetyState__init(msg: *mut SafetyState) -> bool;
    fn vda5050_msgs__msg__SafetyState__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SafetyState>, size: usize) -> bool;
    fn vda5050_msgs__msg__SafetyState__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SafetyState>);
    fn vda5050_msgs__msg__SafetyState__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SafetyState>, out_seq: *mut rosidl_runtime_rs::Sequence<SafetyState>) -> bool;
}

// Corresponds to vda5050_msgs__msg__SafetyState
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SafetyState {
    /// Enum {autoAck, manual, remote, none} Acknowledge-Type of eStop:
    /// autoAck: autoacknowledgeable e-stop is activated e.g. by bumper or protective field
    /// manual: e-stop has to be acknowledged manually at the vehicle
    /// remote: facility estop has to be acknowledged remotely
    /// none: no e-stop activated
    pub e_stop: rosidl_runtime_rs::String,

    /// Protective field violation. True: field is violated False: field is not violated
    pub field_violation: bool,

}

impl SafetyState {
    /// Enums for eStop
    pub const AUTO_ACK: &'static str = "AUTOACK";


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const MANUAL: &'static str = "MANUAL";


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const REMOTE: &'static str = "REMOTE";


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const NONE: &'static str = "NONE";

}


impl Default for SafetyState {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !vda5050_msgs__msg__SafetyState__init(&mut msg as *mut _) {
        panic!("Call to vda5050_msgs__msg__SafetyState__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SafetyState {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__SafetyState__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__SafetyState__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__SafetyState__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SafetyState {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SafetyState where Self: Sized {
  const TYPE_NAME: &'static str = "vda5050_msgs/msg/SafetyState";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__SafetyState() }
  }
}


#[link(name = "vda5050_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__Timing() -> *const std::ffi::c_void;
}

#[link(name = "vda5050_msgs__rosidl_generator_c")]
extern "C" {
    fn vda5050_msgs__msg__Timing__init(msg: *mut Timing) -> bool;
    fn vda5050_msgs__msg__Timing__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Timing>, size: usize) -> bool;
    fn vda5050_msgs__msg__Timing__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Timing>);
    fn vda5050_msgs__msg__Timing__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Timing>, out_seq: *mut rosidl_runtime_rs::Sequence<Timing>) -> bool;
}

// Corresponds to vda5050_msgs__msg__Timing
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Timing {
    /// Minimum interval for sending order messages to the AGV
    pub min_order_interval: f32,

    /// Minimum interval for sending state messages to the AGV
    pub min_state_interval: f32,

    /// Default interval for sending state messages if not defined
    pub default_state_interval: f32,

    /// Default interval for sending on visualization topic
    pub visualization_interval: f32,

}



impl Default for Timing {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !vda5050_msgs__msg__Timing__init(&mut msg as *mut _) {
        panic!("Call to vda5050_msgs__msg__Timing__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Timing {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__Timing__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__Timing__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__Timing__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Timing {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Timing where Self: Sized {
  const TYPE_NAME: &'static str = "vda5050_msgs/msg/Timing";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__Timing() }
  }
}


#[link(name = "vda5050_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__Trajectory() -> *const std::ffi::c_void;
}

#[link(name = "vda5050_msgs__rosidl_generator_c")]
extern "C" {
    fn vda5050_msgs__msg__Trajectory__init(msg: *mut Trajectory) -> bool;
    fn vda5050_msgs__msg__Trajectory__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Trajectory>, size: usize) -> bool;
    fn vda5050_msgs__msg__Trajectory__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Trajectory>);
    fn vda5050_msgs__msg__Trajectory__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Trajectory>, out_seq: *mut rosidl_runtime_rs::Sequence<Trajectory>) -> bool;
}

// Corresponds to vda5050_msgs__msg__Trajectory
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// Points defining a spline. Theta allows holonomic vehicles to rotate along the trajecotry.

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Trajectory {
    /// Range: [1 … infinity) Defines the number of control points that influence
    /// any given point on the curve. Increasing the degree increases continuity.
    /// If not defined, the default value is 1.
    pub degree: f64,

    /// Range: Sequence of parameter values that determines where and
    /// how the control points affect the NURBS curve. knot_vector has size of number
    /// of control points + degree + 1.
    pub knot_vector: rosidl_runtime_rs::Sequence<f64>,

    /// List of JSON control_point objects defining the control points of the nurbs,
    /// which includes the beginning and end point.
    pub control_points: rosidl_runtime_rs::Sequence<super::super::msg::rmw::ControlPoint>,

}



impl Default for Trajectory {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !vda5050_msgs__msg__Trajectory__init(&mut msg as *mut _) {
        panic!("Call to vda5050_msgs__msg__Trajectory__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Trajectory {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__Trajectory__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__Trajectory__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__Trajectory__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Trajectory {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Trajectory where Self: Sized {
  const TYPE_NAME: &'static str = "vda5050_msgs/msg/Trajectory";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__Trajectory() }
  }
}


#[link(name = "vda5050_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__TypeSpecification() -> *const std::ffi::c_void;
}

#[link(name = "vda5050_msgs__rosidl_generator_c")]
extern "C" {
    fn vda5050_msgs__msg__TypeSpecification__init(msg: *mut TypeSpecification) -> bool;
    fn vda5050_msgs__msg__TypeSpecification__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<TypeSpecification>, size: usize) -> bool;
    fn vda5050_msgs__msg__TypeSpecification__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<TypeSpecification>);
    fn vda5050_msgs__msg__TypeSpecification__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<TypeSpecification>, out_seq: *mut rosidl_runtime_rs::Sequence<TypeSpecification>) -> bool;
}

// Corresponds to vda5050_msgs__msg__TypeSpecification
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct TypeSpecification {
    /// Generalized series name as specified by manufacturer
    pub series_name: rosidl_runtime_rs::String,

    /// Human readable description of the AGV type series
    pub series_description: rosidl_runtime_rs::String,

    /// Simplified description of AGV kinematics-type
    pub agv_kinematic: rosidl_runtime_rs::String,

    /// Simplified description of AGV class
    pub agv_class: rosidl_runtime_rs::String,

    /// Maximum loadable mass
    pub max_load_mass: f64,

    /// Simplified description of localization type
    pub localization_types: rosidl_runtime_rs::Sequence<rosidl_runtime_rs::String>,

    /// Path planning types supported by the AGV, sorted by priority
    pub navigation_types: rosidl_runtime_rs::Sequence<rosidl_runtime_rs::String>,

}

impl TypeSpecification {
    /// Enums for agv_kinematic
    pub const DIFF: &'static str = "DIFF";


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const OMNI: &'static str = "OMNI";


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const THREEWHEEL: &'static str = "THREEWHEEL";

    /// Enums for agv_class
    pub const FORKLIFT: &'static str = "FORKLIFT";


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const CONVEYOR: &'static str = "CONVEYOR";


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const TUGGER: &'static str = "TUGGER";


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const CARRIER: &'static str = "CARRIER";

    /// Enums for localization_types
    pub const NATURAL: &'static str = "NATURAL";


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const REFLECTOR: &'static str = "REFLECTOR";


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const RFID: &'static str = "RFID";


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const DMC: &'static str = "DMC";


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const SPOT: &'static str = "SPOT";


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const GRID: &'static str = "GRID";

    /// Enums for navigation_types
    pub const PHYSICAL_LINE_GUIDED: &'static str = "PHYSICAL_LINE_GUIDED";


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const VIRTUAL_LINE_GUIDED: &'static str = "VIRTUAL_LINE_GUIDED";


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const AUTONOMOUS: &'static str = "AUTONOMOUS";

}


impl Default for TypeSpecification {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !vda5050_msgs__msg__TypeSpecification__init(&mut msg as *mut _) {
        panic!("Call to vda5050_msgs__msg__TypeSpecification__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for TypeSpecification {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__TypeSpecification__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__TypeSpecification__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__TypeSpecification__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for TypeSpecification {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for TypeSpecification where Self: Sized {
  const TYPE_NAME: &'static str = "vda5050_msgs/msg/TypeSpecification";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__TypeSpecification() }
  }
}


#[link(name = "vda5050_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__Velocity() -> *const std::ffi::c_void;
}

#[link(name = "vda5050_msgs__rosidl_generator_c")]
extern "C" {
    fn vda5050_msgs__msg__Velocity__init(msg: *mut Velocity) -> bool;
    fn vda5050_msgs__msg__Velocity__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Velocity>, size: usize) -> bool;
    fn vda5050_msgs__msg__Velocity__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Velocity>);
    fn vda5050_msgs__msg__Velocity__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Velocity>, out_seq: *mut rosidl_runtime_rs::Sequence<Velocity>) -> bool;
}

// Corresponds to vda5050_msgs__msg__Velocity
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Velocity {
    /// forward velocity
    pub vx: f64,

    /// sideways velocity
    pub vy: f64,

    /// rotational velocity
    pub omega: f64,

}



impl Default for Velocity {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !vda5050_msgs__msg__Velocity__init(&mut msg as *mut _) {
        panic!("Call to vda5050_msgs__msg__Velocity__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Velocity {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__Velocity__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__Velocity__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__Velocity__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Velocity {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Velocity where Self: Sized {
  const TYPE_NAME: &'static str = "vda5050_msgs/msg/Velocity";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__Velocity() }
  }
}


#[link(name = "vda5050_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__Visualization() -> *const std::ffi::c_void;
}

#[link(name = "vda5050_msgs__rosidl_generator_c")]
extern "C" {
    fn vda5050_msgs__msg__Visualization__init(msg: *mut Visualization) -> bool;
    fn vda5050_msgs__msg__Visualization__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Visualization>, size: usize) -> bool;
    fn vda5050_msgs__msg__Visualization__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Visualization>);
    fn vda5050_msgs__msg__Visualization__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Visualization>, out_seq: *mut rosidl_runtime_rs::Sequence<Visualization>) -> bool;
}

// Corresponds to vda5050_msgs__msg__Visualization
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// HEADER

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Visualization {
    /// header ID of the message. The headerId is defined per topic and incremented by 1 with each sent
    /// (but not necessarily received) message.
    pub header_id: u32,

    /// Timestamp after ISO8601 in the format YYYY-MM-DDTHH:mm:ss.ssZ (e.g.“2017-04-15T11:40:03.12Z”)
    pub timestamp: rosidl_runtime_rs::String,

    /// Version of the protocol [Major].[Minor].[Patch] (e.g. 1.3.2)
    pub version: rosidl_runtime_rs::String,

    /// Manufacturer of the AGV
    pub manufacturer: rosidl_runtime_rs::String,

    /// Serial Number of the AGV
    pub serial_number: rosidl_runtime_rs::String,

    /// CONTENTS
    /// The AGV's position
    pub agv_position: super::super::msg::rmw::AGVPosition,

    /// The AGV's velocity in vehicle coordinates
    pub velocity: super::super::msg::rmw::Velocity,

}



impl Default for Visualization {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !vda5050_msgs__msg__Visualization__init(&mut msg as *mut _) {
        panic!("Call to vda5050_msgs__msg__Visualization__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Visualization {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__Visualization__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__Visualization__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__Visualization__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Visualization {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Visualization where Self: Sized {
  const TYPE_NAME: &'static str = "vda5050_msgs/msg/Visualization";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__Visualization() }
  }
}


#[link(name = "vda5050_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__WheelDefinition() -> *const std::ffi::c_void;
}

#[link(name = "vda5050_msgs__rosidl_generator_c")]
extern "C" {
    fn vda5050_msgs__msg__WheelDefinition__init(msg: *mut WheelDefinition) -> bool;
    fn vda5050_msgs__msg__WheelDefinition__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<WheelDefinition>, size: usize) -> bool;
    fn vda5050_msgs__msg__WheelDefinition__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<WheelDefinition>);
    fn vda5050_msgs__msg__WheelDefinition__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<WheelDefinition>, out_seq: *mut rosidl_runtime_rs::Sequence<WheelDefinition>) -> bool;
}

// Corresponds to vda5050_msgs__msg__WheelDefinition
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct WheelDefinition {
    /// Wheel type
    pub type_: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub is_active_driven: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub is_active_steered: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub position: super::super::msg::rmw::Position,

    /// Nominal diameter of the wheel
    pub diameter: f64,

    /// Nominal width of the wheel
    pub width: f64,

    /// Nominal displacement of the wheel’s center to the rotation point
    pub center_displacement: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub constraints: rosidl_runtime_rs::String,

}

impl WheelDefinition {
    /// Enums for wheel type
    pub const DRIVE: &'static str = "DRIVE";


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const CASTER: &'static str = "CASTER";


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIXED: &'static str = "FIXED";


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const MECANUM: &'static str = "MECANUM";

}


impl Default for WheelDefinition {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !vda5050_msgs__msg__WheelDefinition__init(&mut msg as *mut _) {
        panic!("Call to vda5050_msgs__msg__WheelDefinition__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for WheelDefinition {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__WheelDefinition__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__WheelDefinition__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_msgs__msg__WheelDefinition__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for WheelDefinition {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for WheelDefinition where Self: Sized {
  const TYPE_NAME: &'static str = "vda5050_msgs/msg/WheelDefinition";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__vda5050_msgs__msg__WheelDefinition() }
  }
}


