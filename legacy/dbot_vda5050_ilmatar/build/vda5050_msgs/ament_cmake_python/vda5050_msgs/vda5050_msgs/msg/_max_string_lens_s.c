// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from vda5050_msgs:msg/MaxStringLens.idl
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
#include "vda5050_msgs/msg/detail/max_string_lens__struct.h"
#include "vda5050_msgs/msg/detail/max_string_lens__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool vda5050_msgs__msg__max_string_lens__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[48];
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
    assert(strncmp("vda5050_msgs.msg._max_string_lens.MaxStringLens", full_classname_dest, 47) == 0);
  }
  vda5050_msgs__msg__MaxStringLens * ros_message = _ros_message;
  {  // msg_len
    PyObject * field = PyObject_GetAttrString(_pymsg, "msg_len");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->msg_len = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // topic_serial_len
    PyObject * field = PyObject_GetAttrString(_pymsg, "topic_serial_len");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->topic_serial_len = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // topic_elem_len
    PyObject * field = PyObject_GetAttrString(_pymsg, "topic_elem_len");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->topic_elem_len = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // id_len
    PyObject * field = PyObject_GetAttrString(_pymsg, "id_len");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->id_len = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // id_numerical_only
    PyObject * field = PyObject_GetAttrString(_pymsg, "id_numerical_only");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->id_numerical_only = (Py_True == field);
    Py_DECREF(field);
  }
  {  // enum_len
    PyObject * field = PyObject_GetAttrString(_pymsg, "enum_len");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->enum_len = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // load_id_len
    PyObject * field = PyObject_GetAttrString(_pymsg, "load_id_len");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->load_id_len = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * vda5050_msgs__msg__max_string_lens__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of MaxStringLens */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("vda5050_msgs.msg._max_string_lens");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "MaxStringLens");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  vda5050_msgs__msg__MaxStringLens * ros_message = (vda5050_msgs__msg__MaxStringLens *)raw_ros_message;
  {  // msg_len
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->msg_len);
    {
      int rc = PyObject_SetAttrString(_pymessage, "msg_len", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // topic_serial_len
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->topic_serial_len);
    {
      int rc = PyObject_SetAttrString(_pymessage, "topic_serial_len", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // topic_elem_len
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->topic_elem_len);
    {
      int rc = PyObject_SetAttrString(_pymessage, "topic_elem_len", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // id_len
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->id_len);
    {
      int rc = PyObject_SetAttrString(_pymessage, "id_len", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // id_numerical_only
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->id_numerical_only ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "id_numerical_only", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // enum_len
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->enum_len);
    {
      int rc = PyObject_SetAttrString(_pymessage, "enum_len", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // load_id_len
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->load_id_len);
    {
      int rc = PyObject_SetAttrString(_pymessage, "load_id_len", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
