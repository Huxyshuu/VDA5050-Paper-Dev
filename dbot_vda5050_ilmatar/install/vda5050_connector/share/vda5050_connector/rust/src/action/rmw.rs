
#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "vda5050_connector__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__vda5050_connector__action__NavigateToNode_Goal() -> *const std::ffi::c_void;
}

#[link(name = "vda5050_connector__rosidl_generator_c")]
extern "C" {
    fn vda5050_connector__action__NavigateToNode_Goal__init(msg: *mut NavigateToNode_Goal) -> bool;
    fn vda5050_connector__action__NavigateToNode_Goal__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<NavigateToNode_Goal>, size: usize) -> bool;
    fn vda5050_connector__action__NavigateToNode_Goal__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<NavigateToNode_Goal>);
    fn vda5050_connector__action__NavigateToNode_Goal__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<NavigateToNode_Goal>, out_seq: *mut rosidl_runtime_rs::Sequence<NavigateToNode_Goal>) -> bool;
}

// Corresponds to vda5050_connector__action__NavigateToNode_Goal
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct NavigateToNode_Goal {

    // This member is not documented.
    #[allow(missing_docs)]
    pub edge: vda5050_msgs::msg::rmw::Edge,


    // This member is not documented.
    #[allow(missing_docs)]
    pub node: vda5050_msgs::msg::rmw::Node,

}



impl Default for NavigateToNode_Goal {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !vda5050_connector__action__NavigateToNode_Goal__init(&mut msg as *mut _) {
        panic!("Call to vda5050_connector__action__NavigateToNode_Goal__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for NavigateToNode_Goal {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_connector__action__NavigateToNode_Goal__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_connector__action__NavigateToNode_Goal__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_connector__action__NavigateToNode_Goal__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for NavigateToNode_Goal {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for NavigateToNode_Goal where Self: Sized {
  const TYPE_NAME: &'static str = "vda5050_connector/action/NavigateToNode_Goal";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__vda5050_connector__action__NavigateToNode_Goal() }
  }
}


#[link(name = "vda5050_connector__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__vda5050_connector__action__NavigateToNode_Result() -> *const std::ffi::c_void;
}

#[link(name = "vda5050_connector__rosidl_generator_c")]
extern "C" {
    fn vda5050_connector__action__NavigateToNode_Result__init(msg: *mut NavigateToNode_Result) -> bool;
    fn vda5050_connector__action__NavigateToNode_Result__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<NavigateToNode_Result>, size: usize) -> bool;
    fn vda5050_connector__action__NavigateToNode_Result__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<NavigateToNode_Result>);
    fn vda5050_connector__action__NavigateToNode_Result__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<NavigateToNode_Result>, out_seq: *mut rosidl_runtime_rs::Sequence<NavigateToNode_Result>) -> bool;
}

// Corresponds to vda5050_connector__action__NavigateToNode_Result
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct NavigateToNode_Result {

    // This member is not documented.
    #[allow(missing_docs)]
    pub result: std_msgs::msg::rmw::Empty,

}



impl Default for NavigateToNode_Result {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !vda5050_connector__action__NavigateToNode_Result__init(&mut msg as *mut _) {
        panic!("Call to vda5050_connector__action__NavigateToNode_Result__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for NavigateToNode_Result {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_connector__action__NavigateToNode_Result__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_connector__action__NavigateToNode_Result__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_connector__action__NavigateToNode_Result__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for NavigateToNode_Result {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for NavigateToNode_Result where Self: Sized {
  const TYPE_NAME: &'static str = "vda5050_connector/action/NavigateToNode_Result";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__vda5050_connector__action__NavigateToNode_Result() }
  }
}


#[link(name = "vda5050_connector__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__vda5050_connector__action__NavigateToNode_Feedback() -> *const std::ffi::c_void;
}

#[link(name = "vda5050_connector__rosidl_generator_c")]
extern "C" {
    fn vda5050_connector__action__NavigateToNode_Feedback__init(msg: *mut NavigateToNode_Feedback) -> bool;
    fn vda5050_connector__action__NavigateToNode_Feedback__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<NavigateToNode_Feedback>, size: usize) -> bool;
    fn vda5050_connector__action__NavigateToNode_Feedback__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<NavigateToNode_Feedback>);
    fn vda5050_connector__action__NavigateToNode_Feedback__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<NavigateToNode_Feedback>, out_seq: *mut rosidl_runtime_rs::Sequence<NavigateToNode_Feedback>) -> bool;
}

// Corresponds to vda5050_connector__action__NavigateToNode_Feedback
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct NavigateToNode_Feedback {

    // This member is not documented.
    #[allow(missing_docs)]
    pub position: vda5050_msgs::msg::rmw::AGVPosition,


    // This member is not documented.
    #[allow(missing_docs)]
    pub velocity: vda5050_msgs::msg::rmw::Velocity,

}



impl Default for NavigateToNode_Feedback {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !vda5050_connector__action__NavigateToNode_Feedback__init(&mut msg as *mut _) {
        panic!("Call to vda5050_connector__action__NavigateToNode_Feedback__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for NavigateToNode_Feedback {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_connector__action__NavigateToNode_Feedback__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_connector__action__NavigateToNode_Feedback__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_connector__action__NavigateToNode_Feedback__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for NavigateToNode_Feedback {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for NavigateToNode_Feedback where Self: Sized {
  const TYPE_NAME: &'static str = "vda5050_connector/action/NavigateToNode_Feedback";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__vda5050_connector__action__NavigateToNode_Feedback() }
  }
}


#[link(name = "vda5050_connector__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__vda5050_connector__action__NavigateToNode_FeedbackMessage() -> *const std::ffi::c_void;
}

#[link(name = "vda5050_connector__rosidl_generator_c")]
extern "C" {
    fn vda5050_connector__action__NavigateToNode_FeedbackMessage__init(msg: *mut NavigateToNode_FeedbackMessage) -> bool;
    fn vda5050_connector__action__NavigateToNode_FeedbackMessage__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<NavigateToNode_FeedbackMessage>, size: usize) -> bool;
    fn vda5050_connector__action__NavigateToNode_FeedbackMessage__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<NavigateToNode_FeedbackMessage>);
    fn vda5050_connector__action__NavigateToNode_FeedbackMessage__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<NavigateToNode_FeedbackMessage>, out_seq: *mut rosidl_runtime_rs::Sequence<NavigateToNode_FeedbackMessage>) -> bool;
}

// Corresponds to vda5050_connector__action__NavigateToNode_FeedbackMessage
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct NavigateToNode_FeedbackMessage {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub feedback: super::super::action::rmw::NavigateToNode_Feedback,

}



impl Default for NavigateToNode_FeedbackMessage {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !vda5050_connector__action__NavigateToNode_FeedbackMessage__init(&mut msg as *mut _) {
        panic!("Call to vda5050_connector__action__NavigateToNode_FeedbackMessage__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for NavigateToNode_FeedbackMessage {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_connector__action__NavigateToNode_FeedbackMessage__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_connector__action__NavigateToNode_FeedbackMessage__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_connector__action__NavigateToNode_FeedbackMessage__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for NavigateToNode_FeedbackMessage {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for NavigateToNode_FeedbackMessage where Self: Sized {
  const TYPE_NAME: &'static str = "vda5050_connector/action/NavigateToNode_FeedbackMessage";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__vda5050_connector__action__NavigateToNode_FeedbackMessage() }
  }
}


#[link(name = "vda5050_connector__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__vda5050_connector__action__ProcessVDAAction_Goal() -> *const std::ffi::c_void;
}

#[link(name = "vda5050_connector__rosidl_generator_c")]
extern "C" {
    fn vda5050_connector__action__ProcessVDAAction_Goal__init(msg: *mut ProcessVDAAction_Goal) -> bool;
    fn vda5050_connector__action__ProcessVDAAction_Goal__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ProcessVDAAction_Goal>, size: usize) -> bool;
    fn vda5050_connector__action__ProcessVDAAction_Goal__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ProcessVDAAction_Goal>);
    fn vda5050_connector__action__ProcessVDAAction_Goal__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ProcessVDAAction_Goal>, out_seq: *mut rosidl_runtime_rs::Sequence<ProcessVDAAction_Goal>) -> bool;
}

// Corresponds to vda5050_connector__action__ProcessVDAAction_Goal
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ProcessVDAAction_Goal {

    // This member is not documented.
    #[allow(missing_docs)]
    pub action: vda5050_msgs::msg::rmw::Action,

}



impl Default for ProcessVDAAction_Goal {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !vda5050_connector__action__ProcessVDAAction_Goal__init(&mut msg as *mut _) {
        panic!("Call to vda5050_connector__action__ProcessVDAAction_Goal__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ProcessVDAAction_Goal {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_connector__action__ProcessVDAAction_Goal__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_connector__action__ProcessVDAAction_Goal__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_connector__action__ProcessVDAAction_Goal__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ProcessVDAAction_Goal {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ProcessVDAAction_Goal where Self: Sized {
  const TYPE_NAME: &'static str = "vda5050_connector/action/ProcessVDAAction_Goal";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__vda5050_connector__action__ProcessVDAAction_Goal() }
  }
}


#[link(name = "vda5050_connector__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__vda5050_connector__action__ProcessVDAAction_Result() -> *const std::ffi::c_void;
}

#[link(name = "vda5050_connector__rosidl_generator_c")]
extern "C" {
    fn vda5050_connector__action__ProcessVDAAction_Result__init(msg: *mut ProcessVDAAction_Result) -> bool;
    fn vda5050_connector__action__ProcessVDAAction_Result__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ProcessVDAAction_Result>, size: usize) -> bool;
    fn vda5050_connector__action__ProcessVDAAction_Result__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ProcessVDAAction_Result>);
    fn vda5050_connector__action__ProcessVDAAction_Result__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ProcessVDAAction_Result>, out_seq: *mut rosidl_runtime_rs::Sequence<ProcessVDAAction_Result>) -> bool;
}

// Corresponds to vda5050_connector__action__ProcessVDAAction_Result
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ProcessVDAAction_Result {

    // This member is not documented.
    #[allow(missing_docs)]
    pub result: vda5050_msgs::msg::rmw::CurrentAction,

}



impl Default for ProcessVDAAction_Result {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !vda5050_connector__action__ProcessVDAAction_Result__init(&mut msg as *mut _) {
        panic!("Call to vda5050_connector__action__ProcessVDAAction_Result__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ProcessVDAAction_Result {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_connector__action__ProcessVDAAction_Result__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_connector__action__ProcessVDAAction_Result__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_connector__action__ProcessVDAAction_Result__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ProcessVDAAction_Result {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ProcessVDAAction_Result where Self: Sized {
  const TYPE_NAME: &'static str = "vda5050_connector/action/ProcessVDAAction_Result";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__vda5050_connector__action__ProcessVDAAction_Result() }
  }
}


#[link(name = "vda5050_connector__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__vda5050_connector__action__ProcessVDAAction_Feedback() -> *const std::ffi::c_void;
}

#[link(name = "vda5050_connector__rosidl_generator_c")]
extern "C" {
    fn vda5050_connector__action__ProcessVDAAction_Feedback__init(msg: *mut ProcessVDAAction_Feedback) -> bool;
    fn vda5050_connector__action__ProcessVDAAction_Feedback__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ProcessVDAAction_Feedback>, size: usize) -> bool;
    fn vda5050_connector__action__ProcessVDAAction_Feedback__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ProcessVDAAction_Feedback>);
    fn vda5050_connector__action__ProcessVDAAction_Feedback__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ProcessVDAAction_Feedback>, out_seq: *mut rosidl_runtime_rs::Sequence<ProcessVDAAction_Feedback>) -> bool;
}

// Corresponds to vda5050_connector__action__ProcessVDAAction_Feedback
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ProcessVDAAction_Feedback {

    // This member is not documented.
    #[allow(missing_docs)]
    pub current_action: vda5050_msgs::msg::rmw::CurrentAction,

}



impl Default for ProcessVDAAction_Feedback {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !vda5050_connector__action__ProcessVDAAction_Feedback__init(&mut msg as *mut _) {
        panic!("Call to vda5050_connector__action__ProcessVDAAction_Feedback__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ProcessVDAAction_Feedback {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_connector__action__ProcessVDAAction_Feedback__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_connector__action__ProcessVDAAction_Feedback__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_connector__action__ProcessVDAAction_Feedback__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ProcessVDAAction_Feedback {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ProcessVDAAction_Feedback where Self: Sized {
  const TYPE_NAME: &'static str = "vda5050_connector/action/ProcessVDAAction_Feedback";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__vda5050_connector__action__ProcessVDAAction_Feedback() }
  }
}


#[link(name = "vda5050_connector__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__vda5050_connector__action__ProcessVDAAction_FeedbackMessage() -> *const std::ffi::c_void;
}

#[link(name = "vda5050_connector__rosidl_generator_c")]
extern "C" {
    fn vda5050_connector__action__ProcessVDAAction_FeedbackMessage__init(msg: *mut ProcessVDAAction_FeedbackMessage) -> bool;
    fn vda5050_connector__action__ProcessVDAAction_FeedbackMessage__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ProcessVDAAction_FeedbackMessage>, size: usize) -> bool;
    fn vda5050_connector__action__ProcessVDAAction_FeedbackMessage__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ProcessVDAAction_FeedbackMessage>);
    fn vda5050_connector__action__ProcessVDAAction_FeedbackMessage__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ProcessVDAAction_FeedbackMessage>, out_seq: *mut rosidl_runtime_rs::Sequence<ProcessVDAAction_FeedbackMessage>) -> bool;
}

// Corresponds to vda5050_connector__action__ProcessVDAAction_FeedbackMessage
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ProcessVDAAction_FeedbackMessage {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub feedback: super::super::action::rmw::ProcessVDAAction_Feedback,

}



impl Default for ProcessVDAAction_FeedbackMessage {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !vda5050_connector__action__ProcessVDAAction_FeedbackMessage__init(&mut msg as *mut _) {
        panic!("Call to vda5050_connector__action__ProcessVDAAction_FeedbackMessage__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ProcessVDAAction_FeedbackMessage {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_connector__action__ProcessVDAAction_FeedbackMessage__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_connector__action__ProcessVDAAction_FeedbackMessage__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_connector__action__ProcessVDAAction_FeedbackMessage__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ProcessVDAAction_FeedbackMessage {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ProcessVDAAction_FeedbackMessage where Self: Sized {
  const TYPE_NAME: &'static str = "vda5050_connector/action/ProcessVDAAction_FeedbackMessage";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__vda5050_connector__action__ProcessVDAAction_FeedbackMessage() }
  }
}




#[link(name = "vda5050_connector__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__vda5050_connector__action__NavigateToNode_SendGoal_Request() -> *const std::ffi::c_void;
}

#[link(name = "vda5050_connector__rosidl_generator_c")]
extern "C" {
    fn vda5050_connector__action__NavigateToNode_SendGoal_Request__init(msg: *mut NavigateToNode_SendGoal_Request) -> bool;
    fn vda5050_connector__action__NavigateToNode_SendGoal_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<NavigateToNode_SendGoal_Request>, size: usize) -> bool;
    fn vda5050_connector__action__NavigateToNode_SendGoal_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<NavigateToNode_SendGoal_Request>);
    fn vda5050_connector__action__NavigateToNode_SendGoal_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<NavigateToNode_SendGoal_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<NavigateToNode_SendGoal_Request>) -> bool;
}

// Corresponds to vda5050_connector__action__NavigateToNode_SendGoal_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct NavigateToNode_SendGoal_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub goal: super::super::action::rmw::NavigateToNode_Goal,

}



impl Default for NavigateToNode_SendGoal_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !vda5050_connector__action__NavigateToNode_SendGoal_Request__init(&mut msg as *mut _) {
        panic!("Call to vda5050_connector__action__NavigateToNode_SendGoal_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for NavigateToNode_SendGoal_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_connector__action__NavigateToNode_SendGoal_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_connector__action__NavigateToNode_SendGoal_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_connector__action__NavigateToNode_SendGoal_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for NavigateToNode_SendGoal_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for NavigateToNode_SendGoal_Request where Self: Sized {
  const TYPE_NAME: &'static str = "vda5050_connector/action/NavigateToNode_SendGoal_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__vda5050_connector__action__NavigateToNode_SendGoal_Request() }
  }
}


#[link(name = "vda5050_connector__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__vda5050_connector__action__NavigateToNode_SendGoal_Response() -> *const std::ffi::c_void;
}

#[link(name = "vda5050_connector__rosidl_generator_c")]
extern "C" {
    fn vda5050_connector__action__NavigateToNode_SendGoal_Response__init(msg: *mut NavigateToNode_SendGoal_Response) -> bool;
    fn vda5050_connector__action__NavigateToNode_SendGoal_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<NavigateToNode_SendGoal_Response>, size: usize) -> bool;
    fn vda5050_connector__action__NavigateToNode_SendGoal_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<NavigateToNode_SendGoal_Response>);
    fn vda5050_connector__action__NavigateToNode_SendGoal_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<NavigateToNode_SendGoal_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<NavigateToNode_SendGoal_Response>) -> bool;
}

// Corresponds to vda5050_connector__action__NavigateToNode_SendGoal_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct NavigateToNode_SendGoal_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub accepted: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub stamp: builtin_interfaces::msg::rmw::Time,

}



impl Default for NavigateToNode_SendGoal_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !vda5050_connector__action__NavigateToNode_SendGoal_Response__init(&mut msg as *mut _) {
        panic!("Call to vda5050_connector__action__NavigateToNode_SendGoal_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for NavigateToNode_SendGoal_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_connector__action__NavigateToNode_SendGoal_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_connector__action__NavigateToNode_SendGoal_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_connector__action__NavigateToNode_SendGoal_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for NavigateToNode_SendGoal_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for NavigateToNode_SendGoal_Response where Self: Sized {
  const TYPE_NAME: &'static str = "vda5050_connector/action/NavigateToNode_SendGoal_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__vda5050_connector__action__NavigateToNode_SendGoal_Response() }
  }
}


#[link(name = "vda5050_connector__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__vda5050_connector__action__NavigateToNode_GetResult_Request() -> *const std::ffi::c_void;
}

#[link(name = "vda5050_connector__rosidl_generator_c")]
extern "C" {
    fn vda5050_connector__action__NavigateToNode_GetResult_Request__init(msg: *mut NavigateToNode_GetResult_Request) -> bool;
    fn vda5050_connector__action__NavigateToNode_GetResult_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<NavigateToNode_GetResult_Request>, size: usize) -> bool;
    fn vda5050_connector__action__NavigateToNode_GetResult_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<NavigateToNode_GetResult_Request>);
    fn vda5050_connector__action__NavigateToNode_GetResult_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<NavigateToNode_GetResult_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<NavigateToNode_GetResult_Request>) -> bool;
}

// Corresponds to vda5050_connector__action__NavigateToNode_GetResult_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct NavigateToNode_GetResult_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,

}



impl Default for NavigateToNode_GetResult_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !vda5050_connector__action__NavigateToNode_GetResult_Request__init(&mut msg as *mut _) {
        panic!("Call to vda5050_connector__action__NavigateToNode_GetResult_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for NavigateToNode_GetResult_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_connector__action__NavigateToNode_GetResult_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_connector__action__NavigateToNode_GetResult_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_connector__action__NavigateToNode_GetResult_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for NavigateToNode_GetResult_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for NavigateToNode_GetResult_Request where Self: Sized {
  const TYPE_NAME: &'static str = "vda5050_connector/action/NavigateToNode_GetResult_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__vda5050_connector__action__NavigateToNode_GetResult_Request() }
  }
}


#[link(name = "vda5050_connector__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__vda5050_connector__action__NavigateToNode_GetResult_Response() -> *const std::ffi::c_void;
}

#[link(name = "vda5050_connector__rosidl_generator_c")]
extern "C" {
    fn vda5050_connector__action__NavigateToNode_GetResult_Response__init(msg: *mut NavigateToNode_GetResult_Response) -> bool;
    fn vda5050_connector__action__NavigateToNode_GetResult_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<NavigateToNode_GetResult_Response>, size: usize) -> bool;
    fn vda5050_connector__action__NavigateToNode_GetResult_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<NavigateToNode_GetResult_Response>);
    fn vda5050_connector__action__NavigateToNode_GetResult_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<NavigateToNode_GetResult_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<NavigateToNode_GetResult_Response>) -> bool;
}

// Corresponds to vda5050_connector__action__NavigateToNode_GetResult_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct NavigateToNode_GetResult_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub status: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub result: super::super::action::rmw::NavigateToNode_Result,

}



impl Default for NavigateToNode_GetResult_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !vda5050_connector__action__NavigateToNode_GetResult_Response__init(&mut msg as *mut _) {
        panic!("Call to vda5050_connector__action__NavigateToNode_GetResult_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for NavigateToNode_GetResult_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_connector__action__NavigateToNode_GetResult_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_connector__action__NavigateToNode_GetResult_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_connector__action__NavigateToNode_GetResult_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for NavigateToNode_GetResult_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for NavigateToNode_GetResult_Response where Self: Sized {
  const TYPE_NAME: &'static str = "vda5050_connector/action/NavigateToNode_GetResult_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__vda5050_connector__action__NavigateToNode_GetResult_Response() }
  }
}


#[link(name = "vda5050_connector__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__vda5050_connector__action__ProcessVDAAction_SendGoal_Request() -> *const std::ffi::c_void;
}

#[link(name = "vda5050_connector__rosidl_generator_c")]
extern "C" {
    fn vda5050_connector__action__ProcessVDAAction_SendGoal_Request__init(msg: *mut ProcessVDAAction_SendGoal_Request) -> bool;
    fn vda5050_connector__action__ProcessVDAAction_SendGoal_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ProcessVDAAction_SendGoal_Request>, size: usize) -> bool;
    fn vda5050_connector__action__ProcessVDAAction_SendGoal_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ProcessVDAAction_SendGoal_Request>);
    fn vda5050_connector__action__ProcessVDAAction_SendGoal_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ProcessVDAAction_SendGoal_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<ProcessVDAAction_SendGoal_Request>) -> bool;
}

// Corresponds to vda5050_connector__action__ProcessVDAAction_SendGoal_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ProcessVDAAction_SendGoal_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub goal: super::super::action::rmw::ProcessVDAAction_Goal,

}



impl Default for ProcessVDAAction_SendGoal_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !vda5050_connector__action__ProcessVDAAction_SendGoal_Request__init(&mut msg as *mut _) {
        panic!("Call to vda5050_connector__action__ProcessVDAAction_SendGoal_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ProcessVDAAction_SendGoal_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_connector__action__ProcessVDAAction_SendGoal_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_connector__action__ProcessVDAAction_SendGoal_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_connector__action__ProcessVDAAction_SendGoal_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ProcessVDAAction_SendGoal_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ProcessVDAAction_SendGoal_Request where Self: Sized {
  const TYPE_NAME: &'static str = "vda5050_connector/action/ProcessVDAAction_SendGoal_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__vda5050_connector__action__ProcessVDAAction_SendGoal_Request() }
  }
}


#[link(name = "vda5050_connector__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__vda5050_connector__action__ProcessVDAAction_SendGoal_Response() -> *const std::ffi::c_void;
}

#[link(name = "vda5050_connector__rosidl_generator_c")]
extern "C" {
    fn vda5050_connector__action__ProcessVDAAction_SendGoal_Response__init(msg: *mut ProcessVDAAction_SendGoal_Response) -> bool;
    fn vda5050_connector__action__ProcessVDAAction_SendGoal_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ProcessVDAAction_SendGoal_Response>, size: usize) -> bool;
    fn vda5050_connector__action__ProcessVDAAction_SendGoal_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ProcessVDAAction_SendGoal_Response>);
    fn vda5050_connector__action__ProcessVDAAction_SendGoal_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ProcessVDAAction_SendGoal_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<ProcessVDAAction_SendGoal_Response>) -> bool;
}

// Corresponds to vda5050_connector__action__ProcessVDAAction_SendGoal_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ProcessVDAAction_SendGoal_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub accepted: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub stamp: builtin_interfaces::msg::rmw::Time,

}



impl Default for ProcessVDAAction_SendGoal_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !vda5050_connector__action__ProcessVDAAction_SendGoal_Response__init(&mut msg as *mut _) {
        panic!("Call to vda5050_connector__action__ProcessVDAAction_SendGoal_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ProcessVDAAction_SendGoal_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_connector__action__ProcessVDAAction_SendGoal_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_connector__action__ProcessVDAAction_SendGoal_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_connector__action__ProcessVDAAction_SendGoal_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ProcessVDAAction_SendGoal_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ProcessVDAAction_SendGoal_Response where Self: Sized {
  const TYPE_NAME: &'static str = "vda5050_connector/action/ProcessVDAAction_SendGoal_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__vda5050_connector__action__ProcessVDAAction_SendGoal_Response() }
  }
}


#[link(name = "vda5050_connector__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__vda5050_connector__action__ProcessVDAAction_GetResult_Request() -> *const std::ffi::c_void;
}

#[link(name = "vda5050_connector__rosidl_generator_c")]
extern "C" {
    fn vda5050_connector__action__ProcessVDAAction_GetResult_Request__init(msg: *mut ProcessVDAAction_GetResult_Request) -> bool;
    fn vda5050_connector__action__ProcessVDAAction_GetResult_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ProcessVDAAction_GetResult_Request>, size: usize) -> bool;
    fn vda5050_connector__action__ProcessVDAAction_GetResult_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ProcessVDAAction_GetResult_Request>);
    fn vda5050_connector__action__ProcessVDAAction_GetResult_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ProcessVDAAction_GetResult_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<ProcessVDAAction_GetResult_Request>) -> bool;
}

// Corresponds to vda5050_connector__action__ProcessVDAAction_GetResult_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ProcessVDAAction_GetResult_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,

}



impl Default for ProcessVDAAction_GetResult_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !vda5050_connector__action__ProcessVDAAction_GetResult_Request__init(&mut msg as *mut _) {
        panic!("Call to vda5050_connector__action__ProcessVDAAction_GetResult_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ProcessVDAAction_GetResult_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_connector__action__ProcessVDAAction_GetResult_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_connector__action__ProcessVDAAction_GetResult_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_connector__action__ProcessVDAAction_GetResult_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ProcessVDAAction_GetResult_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ProcessVDAAction_GetResult_Request where Self: Sized {
  const TYPE_NAME: &'static str = "vda5050_connector/action/ProcessVDAAction_GetResult_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__vda5050_connector__action__ProcessVDAAction_GetResult_Request() }
  }
}


#[link(name = "vda5050_connector__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__vda5050_connector__action__ProcessVDAAction_GetResult_Response() -> *const std::ffi::c_void;
}

#[link(name = "vda5050_connector__rosidl_generator_c")]
extern "C" {
    fn vda5050_connector__action__ProcessVDAAction_GetResult_Response__init(msg: *mut ProcessVDAAction_GetResult_Response) -> bool;
    fn vda5050_connector__action__ProcessVDAAction_GetResult_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ProcessVDAAction_GetResult_Response>, size: usize) -> bool;
    fn vda5050_connector__action__ProcessVDAAction_GetResult_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ProcessVDAAction_GetResult_Response>);
    fn vda5050_connector__action__ProcessVDAAction_GetResult_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ProcessVDAAction_GetResult_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<ProcessVDAAction_GetResult_Response>) -> bool;
}

// Corresponds to vda5050_connector__action__ProcessVDAAction_GetResult_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ProcessVDAAction_GetResult_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub status: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub result: super::super::action::rmw::ProcessVDAAction_Result,

}



impl Default for ProcessVDAAction_GetResult_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !vda5050_connector__action__ProcessVDAAction_GetResult_Response__init(&mut msg as *mut _) {
        panic!("Call to vda5050_connector__action__ProcessVDAAction_GetResult_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ProcessVDAAction_GetResult_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_connector__action__ProcessVDAAction_GetResult_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_connector__action__ProcessVDAAction_GetResult_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_connector__action__ProcessVDAAction_GetResult_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ProcessVDAAction_GetResult_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ProcessVDAAction_GetResult_Response where Self: Sized {
  const TYPE_NAME: &'static str = "vda5050_connector/action/ProcessVDAAction_GetResult_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__vda5050_connector__action__ProcessVDAAction_GetResult_Response() }
  }
}






#[link(name = "vda5050_connector__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__vda5050_connector__action__NavigateToNode_SendGoal() -> *const std::ffi::c_void;
}

// Corresponds to vda5050_connector__action__NavigateToNode_SendGoal
#[allow(missing_docs, non_camel_case_types)]
pub struct NavigateToNode_SendGoal;

impl rosidl_runtime_rs::Service for NavigateToNode_SendGoal {
    type Request = NavigateToNode_SendGoal_Request;
    type Response = NavigateToNode_SendGoal_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__vda5050_connector__action__NavigateToNode_SendGoal() }
    }
}




#[link(name = "vda5050_connector__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__vda5050_connector__action__NavigateToNode_GetResult() -> *const std::ffi::c_void;
}

// Corresponds to vda5050_connector__action__NavigateToNode_GetResult
#[allow(missing_docs, non_camel_case_types)]
pub struct NavigateToNode_GetResult;

impl rosidl_runtime_rs::Service for NavigateToNode_GetResult {
    type Request = NavigateToNode_GetResult_Request;
    type Response = NavigateToNode_GetResult_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__vda5050_connector__action__NavigateToNode_GetResult() }
    }
}




#[link(name = "vda5050_connector__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__vda5050_connector__action__ProcessVDAAction_SendGoal() -> *const std::ffi::c_void;
}

// Corresponds to vda5050_connector__action__ProcessVDAAction_SendGoal
#[allow(missing_docs, non_camel_case_types)]
pub struct ProcessVDAAction_SendGoal;

impl rosidl_runtime_rs::Service for ProcessVDAAction_SendGoal {
    type Request = ProcessVDAAction_SendGoal_Request;
    type Response = ProcessVDAAction_SendGoal_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__vda5050_connector__action__ProcessVDAAction_SendGoal() }
    }
}




#[link(name = "vda5050_connector__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__vda5050_connector__action__ProcessVDAAction_GetResult() -> *const std::ffi::c_void;
}

// Corresponds to vda5050_connector__action__ProcessVDAAction_GetResult
#[allow(missing_docs, non_camel_case_types)]
pub struct ProcessVDAAction_GetResult;

impl rosidl_runtime_rs::Service for ProcessVDAAction_GetResult {
    type Request = ProcessVDAAction_GetResult_Request;
    type Response = ProcessVDAAction_GetResult_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__vda5050_connector__action__ProcessVDAAction_GetResult() }
    }
}


