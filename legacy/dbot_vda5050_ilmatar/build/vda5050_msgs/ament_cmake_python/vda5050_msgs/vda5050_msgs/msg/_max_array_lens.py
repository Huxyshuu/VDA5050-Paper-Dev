# generated from rosidl_generator_py/resource/_idl.py.em
# with input from vda5050_msgs:msg/MaxArrayLens.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_MaxArrayLens(type):
    """Metaclass of message 'MaxArrayLens'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('vda5050_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'vda5050_msgs.msg.MaxArrayLens')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__max_array_lens
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__max_array_lens
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__max_array_lens
            cls._TYPE_SUPPORT = module.type_support_msg__msg__max_array_lens
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__max_array_lens

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class MaxArrayLens(metaclass=Metaclass_MaxArrayLens):
    """Message class 'MaxArrayLens'."""

    __slots__ = [
        '_order_nodes',
        '_order_edges',
        '_node_actions',
        '_edge_actions',
        '_actions_parameters',
        '_instant_actions',
        '_trajectory_knot_vector',
        '_trajectory_control_points',
        '_state_node_states',
        '_state_edge_states',
        '_state_loads',
        '_state_action_states',
        '_state_errors',
        '_state_information',
        '_error_references',
        '_info_references',
    ]

    _fields_and_field_types = {
        'order_nodes': 'uint32',
        'order_edges': 'uint32',
        'node_actions': 'uint32',
        'edge_actions': 'uint32',
        'actions_parameters': 'uint32',
        'instant_actions': 'uint32',
        'trajectory_knot_vector': 'uint32',
        'trajectory_control_points': 'uint32',
        'state_node_states': 'uint32',
        'state_edge_states': 'uint32',
        'state_loads': 'uint32',
        'state_action_states': 'uint32',
        'state_errors': 'uint32',
        'state_information': 'uint32',
        'error_references': 'uint32',
        'info_references': 'uint32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.order_nodes = kwargs.get('order_nodes', int())
        self.order_edges = kwargs.get('order_edges', int())
        self.node_actions = kwargs.get('node_actions', int())
        self.edge_actions = kwargs.get('edge_actions', int())
        self.actions_parameters = kwargs.get('actions_parameters', int())
        self.instant_actions = kwargs.get('instant_actions', int())
        self.trajectory_knot_vector = kwargs.get('trajectory_knot_vector', int())
        self.trajectory_control_points = kwargs.get('trajectory_control_points', int())
        self.state_node_states = kwargs.get('state_node_states', int())
        self.state_edge_states = kwargs.get('state_edge_states', int())
        self.state_loads = kwargs.get('state_loads', int())
        self.state_action_states = kwargs.get('state_action_states', int())
        self.state_errors = kwargs.get('state_errors', int())
        self.state_information = kwargs.get('state_information', int())
        self.error_references = kwargs.get('error_references', int())
        self.info_references = kwargs.get('info_references', int())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.order_nodes != other.order_nodes:
            return False
        if self.order_edges != other.order_edges:
            return False
        if self.node_actions != other.node_actions:
            return False
        if self.edge_actions != other.edge_actions:
            return False
        if self.actions_parameters != other.actions_parameters:
            return False
        if self.instant_actions != other.instant_actions:
            return False
        if self.trajectory_knot_vector != other.trajectory_knot_vector:
            return False
        if self.trajectory_control_points != other.trajectory_control_points:
            return False
        if self.state_node_states != other.state_node_states:
            return False
        if self.state_edge_states != other.state_edge_states:
            return False
        if self.state_loads != other.state_loads:
            return False
        if self.state_action_states != other.state_action_states:
            return False
        if self.state_errors != other.state_errors:
            return False
        if self.state_information != other.state_information:
            return False
        if self.error_references != other.error_references:
            return False
        if self.info_references != other.info_references:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def order_nodes(self):
        """Message field 'order_nodes'."""
        return self._order_nodes

    @order_nodes.setter
    def order_nodes(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'order_nodes' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'order_nodes' field must be an unsigned integer in [0, 4294967295]"
        self._order_nodes = value

    @builtins.property
    def order_edges(self):
        """Message field 'order_edges'."""
        return self._order_edges

    @order_edges.setter
    def order_edges(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'order_edges' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'order_edges' field must be an unsigned integer in [0, 4294967295]"
        self._order_edges = value

    @builtins.property
    def node_actions(self):
        """Message field 'node_actions'."""
        return self._node_actions

    @node_actions.setter
    def node_actions(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'node_actions' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'node_actions' field must be an unsigned integer in [0, 4294967295]"
        self._node_actions = value

    @builtins.property
    def edge_actions(self):
        """Message field 'edge_actions'."""
        return self._edge_actions

    @edge_actions.setter
    def edge_actions(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'edge_actions' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'edge_actions' field must be an unsigned integer in [0, 4294967295]"
        self._edge_actions = value

    @builtins.property
    def actions_parameters(self):
        """Message field 'actions_parameters'."""
        return self._actions_parameters

    @actions_parameters.setter
    def actions_parameters(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'actions_parameters' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'actions_parameters' field must be an unsigned integer in [0, 4294967295]"
        self._actions_parameters = value

    @builtins.property
    def instant_actions(self):
        """Message field 'instant_actions'."""
        return self._instant_actions

    @instant_actions.setter
    def instant_actions(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'instant_actions' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'instant_actions' field must be an unsigned integer in [0, 4294967295]"
        self._instant_actions = value

    @builtins.property
    def trajectory_knot_vector(self):
        """Message field 'trajectory_knot_vector'."""
        return self._trajectory_knot_vector

    @trajectory_knot_vector.setter
    def trajectory_knot_vector(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'trajectory_knot_vector' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'trajectory_knot_vector' field must be an unsigned integer in [0, 4294967295]"
        self._trajectory_knot_vector = value

    @builtins.property
    def trajectory_control_points(self):
        """Message field 'trajectory_control_points'."""
        return self._trajectory_control_points

    @trajectory_control_points.setter
    def trajectory_control_points(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'trajectory_control_points' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'trajectory_control_points' field must be an unsigned integer in [0, 4294967295]"
        self._trajectory_control_points = value

    @builtins.property
    def state_node_states(self):
        """Message field 'state_node_states'."""
        return self._state_node_states

    @state_node_states.setter
    def state_node_states(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'state_node_states' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'state_node_states' field must be an unsigned integer in [0, 4294967295]"
        self._state_node_states = value

    @builtins.property
    def state_edge_states(self):
        """Message field 'state_edge_states'."""
        return self._state_edge_states

    @state_edge_states.setter
    def state_edge_states(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'state_edge_states' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'state_edge_states' field must be an unsigned integer in [0, 4294967295]"
        self._state_edge_states = value

    @builtins.property
    def state_loads(self):
        """Message field 'state_loads'."""
        return self._state_loads

    @state_loads.setter
    def state_loads(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'state_loads' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'state_loads' field must be an unsigned integer in [0, 4294967295]"
        self._state_loads = value

    @builtins.property
    def state_action_states(self):
        """Message field 'state_action_states'."""
        return self._state_action_states

    @state_action_states.setter
    def state_action_states(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'state_action_states' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'state_action_states' field must be an unsigned integer in [0, 4294967295]"
        self._state_action_states = value

    @builtins.property
    def state_errors(self):
        """Message field 'state_errors'."""
        return self._state_errors

    @state_errors.setter
    def state_errors(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'state_errors' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'state_errors' field must be an unsigned integer in [0, 4294967295]"
        self._state_errors = value

    @builtins.property
    def state_information(self):
        """Message field 'state_information'."""
        return self._state_information

    @state_information.setter
    def state_information(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'state_information' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'state_information' field must be an unsigned integer in [0, 4294967295]"
        self._state_information = value

    @builtins.property
    def error_references(self):
        """Message field 'error_references'."""
        return self._error_references

    @error_references.setter
    def error_references(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'error_references' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'error_references' field must be an unsigned integer in [0, 4294967295]"
        self._error_references = value

    @builtins.property
    def info_references(self):
        """Message field 'info_references'."""
        return self._info_references

    @info_references.setter
    def info_references(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'info_references' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'info_references' field must be an unsigned integer in [0, 4294967295]"
        self._info_references = value
