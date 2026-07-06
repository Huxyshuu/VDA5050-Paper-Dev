#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



#[link(name = "vda5050_connector__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__vda5050_connector__srv__GetState_Request() -> *const std::ffi::c_void;
}

#[link(name = "vda5050_connector__rosidl_generator_c")]
extern "C" {
    fn vda5050_connector__srv__GetState_Request__init(msg: *mut GetState_Request) -> bool;
    fn vda5050_connector__srv__GetState_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GetState_Request>, size: usize) -> bool;
    fn vda5050_connector__srv__GetState_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GetState_Request>);
    fn vda5050_connector__srv__GetState_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GetState_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<GetState_Request>) -> bool;
}

// Corresponds to vda5050_connector__srv__GetState_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetState_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for GetState_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !vda5050_connector__srv__GetState_Request__init(&mut msg as *mut _) {
        panic!("Call to vda5050_connector__srv__GetState_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GetState_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_connector__srv__GetState_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_connector__srv__GetState_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_connector__srv__GetState_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GetState_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GetState_Request where Self: Sized {
  const TYPE_NAME: &'static str = "vda5050_connector/srv/GetState_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__vda5050_connector__srv__GetState_Request() }
  }
}


#[link(name = "vda5050_connector__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__vda5050_connector__srv__GetState_Response() -> *const std::ffi::c_void;
}

#[link(name = "vda5050_connector__rosidl_generator_c")]
extern "C" {
    fn vda5050_connector__srv__GetState_Response__init(msg: *mut GetState_Response) -> bool;
    fn vda5050_connector__srv__GetState_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GetState_Response>, size: usize) -> bool;
    fn vda5050_connector__srv__GetState_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GetState_Response>);
    fn vda5050_connector__srv__GetState_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GetState_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<GetState_Response>) -> bool;
}

// Corresponds to vda5050_connector__srv__GetState_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetState_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub state: vda5050_msgs::msg::rmw::OrderState,

}



impl Default for GetState_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !vda5050_connector__srv__GetState_Response__init(&mut msg as *mut _) {
        panic!("Call to vda5050_connector__srv__GetState_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GetState_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_connector__srv__GetState_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_connector__srv__GetState_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_connector__srv__GetState_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GetState_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GetState_Response where Self: Sized {
  const TYPE_NAME: &'static str = "vda5050_connector/srv/GetState_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__vda5050_connector__srv__GetState_Response() }
  }
}


#[link(name = "vda5050_connector__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__vda5050_connector__srv__SupportedActions_Request() -> *const std::ffi::c_void;
}

#[link(name = "vda5050_connector__rosidl_generator_c")]
extern "C" {
    fn vda5050_connector__srv__SupportedActions_Request__init(msg: *mut SupportedActions_Request) -> bool;
    fn vda5050_connector__srv__SupportedActions_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SupportedActions_Request>, size: usize) -> bool;
    fn vda5050_connector__srv__SupportedActions_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SupportedActions_Request>);
    fn vda5050_connector__srv__SupportedActions_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SupportedActions_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<SupportedActions_Request>) -> bool;
}

// Corresponds to vda5050_connector__srv__SupportedActions_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SupportedActions_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for SupportedActions_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !vda5050_connector__srv__SupportedActions_Request__init(&mut msg as *mut _) {
        panic!("Call to vda5050_connector__srv__SupportedActions_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SupportedActions_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_connector__srv__SupportedActions_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_connector__srv__SupportedActions_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_connector__srv__SupportedActions_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SupportedActions_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SupportedActions_Request where Self: Sized {
  const TYPE_NAME: &'static str = "vda5050_connector/srv/SupportedActions_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__vda5050_connector__srv__SupportedActions_Request() }
  }
}


#[link(name = "vda5050_connector__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__vda5050_connector__srv__SupportedActions_Response() -> *const std::ffi::c_void;
}

#[link(name = "vda5050_connector__rosidl_generator_c")]
extern "C" {
    fn vda5050_connector__srv__SupportedActions_Response__init(msg: *mut SupportedActions_Response) -> bool;
    fn vda5050_connector__srv__SupportedActions_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SupportedActions_Response>, size: usize) -> bool;
    fn vda5050_connector__srv__SupportedActions_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SupportedActions_Response>);
    fn vda5050_connector__srv__SupportedActions_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SupportedActions_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<SupportedActions_Response>) -> bool;
}

// Corresponds to vda5050_connector__srv__SupportedActions_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SupportedActions_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub agv_actions: rosidl_runtime_rs::Sequence<vda5050_msgs::msg::rmw::AGVAction>,

}



impl Default for SupportedActions_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !vda5050_connector__srv__SupportedActions_Response__init(&mut msg as *mut _) {
        panic!("Call to vda5050_connector__srv__SupportedActions_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SupportedActions_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_connector__srv__SupportedActions_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_connector__srv__SupportedActions_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { vda5050_connector__srv__SupportedActions_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SupportedActions_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SupportedActions_Response where Self: Sized {
  const TYPE_NAME: &'static str = "vda5050_connector/srv/SupportedActions_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__vda5050_connector__srv__SupportedActions_Response() }
  }
}






#[link(name = "vda5050_connector__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__vda5050_connector__srv__GetState() -> *const std::ffi::c_void;
}

// Corresponds to vda5050_connector__srv__GetState
#[allow(missing_docs, non_camel_case_types)]
pub struct GetState;

impl rosidl_runtime_rs::Service for GetState {
    type Request = GetState_Request;
    type Response = GetState_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__vda5050_connector__srv__GetState() }
    }
}




#[link(name = "vda5050_connector__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__vda5050_connector__srv__SupportedActions() -> *const std::ffi::c_void;
}

// Corresponds to vda5050_connector__srv__SupportedActions
#[allow(missing_docs, non_camel_case_types)]
pub struct SupportedActions;

impl rosidl_runtime_rs::Service for SupportedActions {
    type Request = SupportedActions_Request;
    type Response = SupportedActions_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__vda5050_connector__srv__SupportedActions() }
    }
}


