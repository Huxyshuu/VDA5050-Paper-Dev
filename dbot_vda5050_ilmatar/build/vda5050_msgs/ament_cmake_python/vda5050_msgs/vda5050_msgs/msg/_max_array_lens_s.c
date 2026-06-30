// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from vda5050_msgs:msg/MaxArrayLens.idl
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
#include "vda5050_msgs/msg/detail/max_array_lens__struct.h"
#include "vda5050_msgs/msg/detail/max_array_lens__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool vda5050_msgs__msg__max_array_lens__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[46];
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
    assert(strncmp("vda5050_msgs.msg._max_array_lens.MaxArrayLens", full_classname_dest, 45) == 0);
  }
  vda5050_msgs__msg__MaxArrayLens * ros_message = _ros_message;
  {  // order_nodes
    PyObject * field = PyObject_GetAttrString(_pymsg, "order_nodes");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->order_nodes = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // order_edges
    PyObject * field = PyObject_GetAttrString(_pymsg, "order_edges");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->order_edges = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // node_actions
    PyObject * field = PyObject_GetAttrString(_pymsg, "node_actions");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->node_actions = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // edge_actions
    PyObject * field = PyObject_GetAttrString(_pymsg, "edge_actions");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->edge_actions = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // actions_parameters
    PyObject * field = PyObject_GetAttrString(_pymsg, "actions_parameters");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->actions_parameters = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // instant_actions
    PyObject * field = PyObject_GetAttrString(_pymsg, "instant_actions");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->instant_actions = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // trajectory_knot_vector
    PyObject * field = PyObject_GetAttrString(_pymsg, "trajectory_knot_vector");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->trajectory_knot_vector = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // trajectory_control_points
    PyObject * field = PyObject_GetAttrString(_pymsg, "trajectory_control_points");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->trajectory_control_points = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // state_node_states
    PyObject * field = PyObject_GetAttrString(_pymsg, "state_node_states");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->state_node_states = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // state_edge_states
    PyObject * field = PyObject_GetAttrString(_pymsg, "state_edge_states");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->state_edge_states = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // state_loads
    PyObject * field = PyObject_GetAttrString(_pymsg, "state_loads");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->state_loads = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // state_action_states
    PyObject * field = PyObject_GetAttrString(_pymsg, "state_action_states");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->state_action_states = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // state_errors
    PyObject * field = PyObject_GetAttrString(_pymsg, "state_errors");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->state_errors = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // state_information
    PyObject * field = PyObject_GetAttrString(_pymsg, "state_information");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->state_information = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // error_references
    PyObject * field = PyObject_GetAttrString(_pymsg, "error_references");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->error_references = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // info_references
    PyObject * field = PyObject_GetAttrString(_pymsg, "info_references");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->info_references = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * vda5050_msgs__msg__max_array_lens__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of MaxArrayLens */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("vda5050_msgs.msg._max_array_lens");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "MaxArrayLens");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  vda5050_msgs__msg__MaxArrayLens * ros_message = (vda5050_msgs__msg__MaxArrayLens *)raw_ros_message;
  {  // order_nodes
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->order_nodes);
    {
      int rc = PyObject_SetAttrString(_pymessage, "order_nodes", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // order_edges
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->order_edges);
    {
      int rc = PyObject_SetAttrString(_pymessage, "order_edges", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // node_actions
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->node_actions);
    {
      int rc = PyObject_SetAttrString(_pymessage, "node_actions", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // edge_actions
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->edge_actions);
    {
      int rc = PyObject_SetAttrString(_pymessage, "edge_actions", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // actions_parameters
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->actions_parameters);
    {
      int rc = PyObject_SetAttrString(_pymessage, "actions_parameters", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // instant_actions
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->instant_actions);
    {
      int rc = PyObject_SetAttrString(_pymessage, "instant_actions", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // trajectory_knot_vector
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->trajectory_knot_vector);
    {
      int rc = PyObject_SetAttrString(_pymessage, "trajectory_knot_vector", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // trajectory_control_points
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->trajectory_control_points);
    {
      int rc = PyObject_SetAttrString(_pymessage, "trajectory_control_points", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // state_node_states
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->state_node_states);
    {
      int rc = PyObject_SetAttrString(_pymessage, "state_node_states", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // state_edge_states
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->state_edge_states);
    {
      int rc = PyObject_SetAttrString(_pymessage, "state_edge_states", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // state_loads
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->state_loads);
    {
      int rc = PyObject_SetAttrString(_pymessage, "state_loads", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // state_action_states
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->state_action_states);
    {
      int rc = PyObject_SetAttrString(_pymessage, "state_action_states", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // state_errors
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->state_errors);
    {
      int rc = PyObject_SetAttrString(_pymessage, "state_errors", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // state_information
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->state_information);
    {
      int rc = PyObject_SetAttrString(_pymessage, "state_information", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // error_references
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->error_references);
    {
      int rc = PyObject_SetAttrString(_pymessage, "error_references", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // info_references
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->info_references);
    {
      int rc = PyObject_SetAttrString(_pymessage, "info_references", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
