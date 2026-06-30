// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from vda5050_msgs:msg/Factsheet.idl
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
#include "vda5050_msgs/msg/detail/factsheet__struct.h"
#include "vda5050_msgs/msg/detail/factsheet__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"

bool vda5050_msgs__msg__type_specification__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * vda5050_msgs__msg__type_specification__convert_to_py(void * raw_ros_message);
bool vda5050_msgs__msg__physical_parameters__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * vda5050_msgs__msg__physical_parameters__convert_to_py(void * raw_ros_message);
bool vda5050_msgs__msg__protocol_limits__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * vda5050_msgs__msg__protocol_limits__convert_to_py(void * raw_ros_message);
bool vda5050_msgs__msg__protocol_features__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * vda5050_msgs__msg__protocol_features__convert_to_py(void * raw_ros_message);
bool vda5050_msgs__msg__agv_geometry__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * vda5050_msgs__msg__agv_geometry__convert_to_py(void * raw_ros_message);
bool vda5050_msgs__msg__load_specification__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * vda5050_msgs__msg__load_specification__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool vda5050_msgs__msg__factsheet__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[38];
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
    assert(strncmp("vda5050_msgs.msg._factsheet.Factsheet", full_classname_dest, 37) == 0);
  }
  vda5050_msgs__msg__Factsheet * ros_message = _ros_message;
  {  // header_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "header_id");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->header_id = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // timestamp
    PyObject * field = PyObject_GetAttrString(_pymsg, "timestamp");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->timestamp, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // version
    PyObject * field = PyObject_GetAttrString(_pymsg, "version");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->version, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // manufacturer
    PyObject * field = PyObject_GetAttrString(_pymsg, "manufacturer");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->manufacturer, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // serial_number
    PyObject * field = PyObject_GetAttrString(_pymsg, "serial_number");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->serial_number, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // type_specification
    PyObject * field = PyObject_GetAttrString(_pymsg, "type_specification");
    if (!field) {
      return false;
    }
    if (!vda5050_msgs__msg__type_specification__convert_from_py(field, &ros_message->type_specification)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // physical_parameters
    PyObject * field = PyObject_GetAttrString(_pymsg, "physical_parameters");
    if (!field) {
      return false;
    }
    if (!vda5050_msgs__msg__physical_parameters__convert_from_py(field, &ros_message->physical_parameters)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // protocol_limits
    PyObject * field = PyObject_GetAttrString(_pymsg, "protocol_limits");
    if (!field) {
      return false;
    }
    if (!vda5050_msgs__msg__protocol_limits__convert_from_py(field, &ros_message->protocol_limits)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // protocol_features
    PyObject * field = PyObject_GetAttrString(_pymsg, "protocol_features");
    if (!field) {
      return false;
    }
    if (!vda5050_msgs__msg__protocol_features__convert_from_py(field, &ros_message->protocol_features)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // agv_geometry
    PyObject * field = PyObject_GetAttrString(_pymsg, "agv_geometry");
    if (!field) {
      return false;
    }
    if (!vda5050_msgs__msg__agv_geometry__convert_from_py(field, &ros_message->agv_geometry)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // load_specification
    PyObject * field = PyObject_GetAttrString(_pymsg, "load_specification");
    if (!field) {
      return false;
    }
    if (!vda5050_msgs__msg__load_specification__convert_from_py(field, &ros_message->load_specification)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // localization_parameters
    PyObject * field = PyObject_GetAttrString(_pymsg, "localization_parameters");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->localization_parameters = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * vda5050_msgs__msg__factsheet__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of Factsheet */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("vda5050_msgs.msg._factsheet");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "Factsheet");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  vda5050_msgs__msg__Factsheet * ros_message = (vda5050_msgs__msg__Factsheet *)raw_ros_message;
  {  // header_id
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->header_id);
    {
      int rc = PyObject_SetAttrString(_pymessage, "header_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // timestamp
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->timestamp.data,
      strlen(ros_message->timestamp.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "timestamp", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // version
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->version.data,
      strlen(ros_message->version.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "version", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // manufacturer
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->manufacturer.data,
      strlen(ros_message->manufacturer.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "manufacturer", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // serial_number
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->serial_number.data,
      strlen(ros_message->serial_number.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "serial_number", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // type_specification
    PyObject * field = NULL;
    field = vda5050_msgs__msg__type_specification__convert_to_py(&ros_message->type_specification);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "type_specification", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // physical_parameters
    PyObject * field = NULL;
    field = vda5050_msgs__msg__physical_parameters__convert_to_py(&ros_message->physical_parameters);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "physical_parameters", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // protocol_limits
    PyObject * field = NULL;
    field = vda5050_msgs__msg__protocol_limits__convert_to_py(&ros_message->protocol_limits);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "protocol_limits", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // protocol_features
    PyObject * field = NULL;
    field = vda5050_msgs__msg__protocol_features__convert_to_py(&ros_message->protocol_features);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "protocol_features", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // agv_geometry
    PyObject * field = NULL;
    field = vda5050_msgs__msg__agv_geometry__convert_to_py(&ros_message->agv_geometry);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "agv_geometry", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // load_specification
    PyObject * field = NULL;
    field = vda5050_msgs__msg__load_specification__convert_to_py(&ros_message->load_specification);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "load_specification", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // localization_parameters
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->localization_parameters);
    {
      int rc = PyObject_SetAttrString(_pymessage, "localization_parameters", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
