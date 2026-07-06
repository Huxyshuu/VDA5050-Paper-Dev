// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from vda5050_msgs:msg/LoadSet.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "vda5050_msgs/msg/detail/load_set__struct.h"
#include "vda5050_msgs/msg/detail/load_set__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"

#include "rosidl_runtime_c/primitives_sequence.h"
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool vda5050_msgs__msg__bounding_box_reference__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * vda5050_msgs__msg__bounding_box_reference__convert_to_py(void * raw_ros_message);
bool vda5050_msgs__msg__load_dimensions__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * vda5050_msgs__msg__load_dimensions__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool vda5050_msgs__msg__load_set__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[35];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("vda5050_msgs.msg._load_set.LoadSet", full_classname_dest, 34) == 0);
  }
  vda5050_msgs__msg__LoadSet * ros_message = _ros_message;
  {  // set_name
    PyObject * field = PyObject_GetAttrString(_pymsg, "set_name");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->set_name, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // load_type
    PyObject * field = PyObject_GetAttrString(_pymsg, "load_type");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->load_type, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // load_positions
    PyObject * field = PyObject_GetAttrString(_pymsg, "load_positions");
    if (!field) {
      return false;
    }
    {
      PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'load_positions'");
      if (!seq_field) {
        Py_DECREF(field);
        return false;
      }
      Py_ssize_t size = PySequence_Size(field);
      if (-1 == size) {
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
      if (!rosidl_runtime_c__String__Sequence__init(&(ros_message->load_positions), size)) {
        PyErr_SetString(PyExc_RuntimeError, "unable to create String__Sequence ros_message");
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
      rosidl_runtime_c__String * dest = ros_message->load_positions.data;
      for (Py_ssize_t i = 0; i < size; ++i) {
        PyObject * item = PySequence_Fast_GET_ITEM(seq_field, i);
        if (!item) {
          Py_DECREF(seq_field);
          Py_DECREF(field);
          return false;
        }
        assert(PyUnicode_Check(item));
        PyObject * encoded_item = PyUnicode_AsUTF8String(item);
        if (!encoded_item) {
          Py_DECREF(seq_field);
          Py_DECREF(field);
          return false;
        }
        rosidl_runtime_c__String__assign(&dest[i], PyBytes_AS_STRING(encoded_item));
        Py_DECREF(encoded_item);
      }
      Py_DECREF(seq_field);
    }
    Py_DECREF(field);
  }
  {  // bounding_box_reference
    PyObject * field = PyObject_GetAttrString(_pymsg, "bounding_box_reference");
    if (!field) {
      return false;
    }
    if (!vda5050_msgs__msg__bounding_box_reference__convert_from_py(field, &ros_message->bounding_box_reference)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // load_dimensions
    PyObject * field = PyObject_GetAttrString(_pymsg, "load_dimensions");
    if (!field) {
      return false;
    }
    if (!vda5050_msgs__msg__load_dimensions__convert_from_py(field, &ros_message->load_dimensions)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // max_weight
    PyObject * field = PyObject_GetAttrString(_pymsg, "max_weight");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->max_weight = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // min_loadhandling_height
    PyObject * field = PyObject_GetAttrString(_pymsg, "min_loadhandling_height");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->min_loadhandling_height = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // max_loadhandling_height
    PyObject * field = PyObject_GetAttrString(_pymsg, "max_loadhandling_height");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->max_loadhandling_height = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // min_loadhandling_depth
    PyObject * field = PyObject_GetAttrString(_pymsg, "min_loadhandling_depth");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->min_loadhandling_depth = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // max_loadhandling_depth
    PyObject * field = PyObject_GetAttrString(_pymsg, "max_loadhandling_depth");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->max_loadhandling_depth = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // min_loadhandling_tilt
    PyObject * field = PyObject_GetAttrString(_pymsg, "min_loadhandling_tilt");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->min_loadhandling_tilt = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // max_loadhandling_tilt
    PyObject * field = PyObject_GetAttrString(_pymsg, "max_loadhandling_tilt");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->max_loadhandling_tilt = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // agv_speed_limit
    PyObject * field = PyObject_GetAttrString(_pymsg, "agv_speed_limit");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->agv_speed_limit = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // agv_acceleration_limit
    PyObject * field = PyObject_GetAttrString(_pymsg, "agv_acceleration_limit");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->agv_acceleration_limit = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // agv_deceleration_limit
    PyObject * field = PyObject_GetAttrString(_pymsg, "agv_deceleration_limit");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->agv_deceleration_limit = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // pick_time
    PyObject * field = PyObject_GetAttrString(_pymsg, "pick_time");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->pick_time = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // drop_time
    PyObject * field = PyObject_GetAttrString(_pymsg, "drop_time");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->drop_time = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // description
    PyObject * field = PyObject_GetAttrString(_pymsg, "description");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->description, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * vda5050_msgs__msg__load_set__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of LoadSet */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("vda5050_msgs.msg._load_set");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "LoadSet");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  vda5050_msgs__msg__LoadSet * ros_message = (vda5050_msgs__msg__LoadSet *)raw_ros_message;
  {  // set_name
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->set_name.data,
      strlen(ros_message->set_name.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "set_name", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // load_type
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->load_type.data,
      strlen(ros_message->load_type.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "load_type", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // load_positions
    PyObject * field = NULL;
    size_t size = ros_message->load_positions.size;
    rosidl_runtime_c__String * src = ros_message->load_positions.data;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    for (size_t i = 0; i < size; ++i) {
      PyObject * decoded_item = PyUnicode_DecodeUTF8(src[i].data, strlen(src[i].data), "replace");
      if (!decoded_item) {
        return NULL;
      }
      int rc = PyList_SetItem(field, i, decoded_item);
      (void)rc;
      assert(rc == 0);
    }
    assert(PySequence_Check(field));
    {
      int rc = PyObject_SetAttrString(_pymessage, "load_positions", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // bounding_box_reference
    PyObject * field = NULL;
    field = vda5050_msgs__msg__bounding_box_reference__convert_to_py(&ros_message->bounding_box_reference);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "bounding_box_reference", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // load_dimensions
    PyObject * field = NULL;
    field = vda5050_msgs__msg__load_dimensions__convert_to_py(&ros_message->load_dimensions);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "load_dimensions", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // max_weight
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->max_weight);
    {
      int rc = PyObject_SetAttrString(_pymessage, "max_weight", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // min_loadhandling_height
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->min_loadhandling_height);
    {
      int rc = PyObject_SetAttrString(_pymessage, "min_loadhandling_height", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // max_loadhandling_height
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->max_loadhandling_height);
    {
      int rc = PyObject_SetAttrString(_pymessage, "max_loadhandling_height", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // min_loadhandling_depth
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->min_loadhandling_depth);
    {
      int rc = PyObject_SetAttrString(_pymessage, "min_loadhandling_depth", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // max_loadhandling_depth
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->max_loadhandling_depth);
    {
      int rc = PyObject_SetAttrString(_pymessage, "max_loadhandling_depth", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // min_loadhandling_tilt
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->min_loadhandling_tilt);
    {
      int rc = PyObject_SetAttrString(_pymessage, "min_loadhandling_tilt", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // max_loadhandling_tilt
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->max_loadhandling_tilt);
    {
      int rc = PyObject_SetAttrString(_pymessage, "max_loadhandling_tilt", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // agv_speed_limit
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->agv_speed_limit);
    {
      int rc = PyObject_SetAttrString(_pymessage, "agv_speed_limit", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // agv_acceleration_limit
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->agv_acceleration_limit);
    {
      int rc = PyObject_SetAttrString(_pymessage, "agv_acceleration_limit", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // agv_deceleration_limit
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->agv_deceleration_limit);
    {
      int rc = PyObject_SetAttrString(_pymessage, "agv_deceleration_limit", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // pick_time
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->pick_time);
    {
      int rc = PyObject_SetAttrString(_pymessage, "pick_time", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // drop_time
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->drop_time);
    {
      int rc = PyObject_SetAttrString(_pymessage, "drop_time", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // description
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->description.data,
      strlen(ros_message->description.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "description", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
