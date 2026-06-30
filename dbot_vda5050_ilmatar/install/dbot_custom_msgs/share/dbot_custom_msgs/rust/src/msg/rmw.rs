#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "dbot_custom_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__dbot_custom_msgs__msg__WheelEncoder() -> *const std::ffi::c_void;
}

#[link(name = "dbot_custom_msgs__rosidl_generator_c")]
extern "C" {
    fn dbot_custom_msgs__msg__WheelEncoder__init(msg: *mut WheelEncoder) -> bool;
    fn dbot_custom_msgs__msg__WheelEncoder__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<WheelEncoder>, size: usize) -> bool;
    fn dbot_custom_msgs__msg__WheelEncoder__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<WheelEncoder>);
    fn dbot_custom_msgs__msg__WheelEncoder__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<WheelEncoder>, out_seq: *mut rosidl_runtime_rs::Sequence<WheelEncoder>) -> bool;
}

// Corresponds to dbot_custom_msgs__msg__WheelEncoder
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct WheelEncoder {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::rmw::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub left: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub right: f64,

}



impl Default for WheelEncoder {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !dbot_custom_msgs__msg__WheelEncoder__init(&mut msg as *mut _) {
        panic!("Call to dbot_custom_msgs__msg__WheelEncoder__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for WheelEncoder {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { dbot_custom_msgs__msg__WheelEncoder__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { dbot_custom_msgs__msg__WheelEncoder__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { dbot_custom_msgs__msg__WheelEncoder__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for WheelEncoder {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for WheelEncoder where Self: Sized {
  const TYPE_NAME: &'static str = "dbot_custom_msgs/msg/WheelEncoder";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__dbot_custom_msgs__msg__WheelEncoder() }
  }
}


