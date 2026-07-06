# generated from rosidl_generator_py/resource/_idl.py.em
# with input from vda5050_msgs:msg/Node.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Node(type):
    """Metaclass of message 'Node'."""

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
                'vda5050_msgs.msg.Node')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__node
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__node
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__node
            cls._TYPE_SUPPORT = module.type_support_msg__msg__node
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__node

            from vda5050_msgs.msg import Action
            if Action.__class__._TYPE_SUPPORT is None:
                Action.__class__.__import_type_support__()

            from vda5050_msgs.msg import NodePosition
            if NodePosition.__class__._TYPE_SUPPORT is None:
                NodePosition.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Node(metaclass=Metaclass_Node):
    """Message class 'Node'."""

    __slots__ = [
        '_node_id',
        '_sequence_id',
        '_node_description',
        '_released',
        '_node_position',
        '_actions',
    ]

    _fields_and_field_types = {
        'node_id': 'string',
        'sequence_id': 'uint32',
        'node_description': 'string',
        'released': 'boolean',
        'node_position': 'vda5050_msgs/NodePosition',
        'actions': 'sequence<vda5050_msgs/Action>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['vda5050_msgs', 'msg'], 'NodePosition'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['vda5050_msgs', 'msg'], 'Action')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.node_id = kwargs.get('node_id', str())
        self.sequence_id = kwargs.get('sequence_id', int())
        self.node_description = kwargs.get('node_description', str())
        self.released = kwargs.get('released', bool())
        from vda5050_msgs.msg import NodePosition
        self.node_position = kwargs.get('node_position', NodePosition())
        self.actions = kwargs.get('actions', [])

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
        if self.node_id != other.node_id:
            return False
        if self.sequence_id != other.sequence_id:
            return False
        if self.node_description != other.node_description:
            return False
        if self.released != other.released:
            return False
        if self.node_position != other.node_position:
            return False
        if self.actions != other.actions:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def node_id(self):
        """Message field 'node_id'."""
        return self._node_id

    @node_id.setter
    def node_id(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'node_id' field must be of type 'str'"
        self._node_id = value

    @builtins.property
    def sequence_id(self):
        """Message field 'sequence_id'."""
        return self._sequence_id

    @sequence_id.setter
    def sequence_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'sequence_id' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'sequence_id' field must be an unsigned integer in [0, 4294967295]"
        self._sequence_id = value

    @builtins.property
    def node_description(self):
        """Message field 'node_description'."""
        return self._node_description

    @node_description.setter
    def node_description(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'node_description' field must be of type 'str'"
        self._node_description = value

    @builtins.property
    def released(self):
        """Message field 'released'."""
        return self._released

    @released.setter
    def released(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'released' field must be of type 'bool'"
        self._released = value

    @builtins.property
    def node_position(self):
        """Message field 'node_position'."""
        return self._node_position

    @node_position.setter
    def node_position(self, value):
        if __debug__:
            from vda5050_msgs.msg import NodePosition
            assert \
                isinstance(value, NodePosition), \
                "The 'node_position' field must be a sub message of type 'NodePosition'"
        self._node_position = value

    @builtins.property
    def actions(self):
        """Message field 'actions'."""
        return self._actions

    @actions.setter
    def actions(self, value):
        if __debug__:
            from vda5050_msgs.msg import Action
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, Action) for v in value) and
                 True), \
                "The 'actions' field must be a set or sequence and each value of type 'Action'"
        self._actions = value
