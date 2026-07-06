# generated from rosidl_generator_py/resource/_idl.py.em
# with input from vda5050_msgs:msg/AGVAction.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_AGVAction(type):
    """Metaclass of message 'AGVAction'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'INSTANT': 'INSTANT',
        'NODE': 'NODE',
        'EDGE': 'EDGE',
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
                'vda5050_msgs.msg.AGVAction')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__agv_action
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__agv_action
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__agv_action
            cls._TYPE_SUPPORT = module.type_support_msg__msg__agv_action
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__agv_action

            from vda5050_msgs.msg import ActionParameterDefinition
            if ActionParameterDefinition.__class__._TYPE_SUPPORT is None:
                ActionParameterDefinition.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'INSTANT': cls.__constants['INSTANT'],
            'NODE': cls.__constants['NODE'],
            'EDGE': cls.__constants['EDGE'],
        }

    @property
    def INSTANT(self):
        """Message constant 'INSTANT'."""
        return Metaclass_AGVAction.__constants['INSTANT']

    @property
    def NODE(self):
        """Message constant 'NODE'."""
        return Metaclass_AGVAction.__constants['NODE']

    @property
    def EDGE(self):
        """Message constant 'EDGE'."""
        return Metaclass_AGVAction.__constants['EDGE']


class AGVAction(metaclass=Metaclass_AGVAction):
    """
    Message class 'AGVAction'.

    Constants:
      INSTANT
      NODE
      EDGE
    """

    __slots__ = [
        '_action_type',
        '_action_description',
        '_action_scopes',
        '_action_parameters',
        '_result_description',
    ]

    _fields_and_field_types = {
        'action_type': 'string',
        'action_description': 'string',
        'action_scopes': 'sequence<string>',
        'action_parameters': 'sequence<vda5050_msgs/ActionParameterDefinition>',
        'result_description': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.UnboundedString()),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['vda5050_msgs', 'msg'], 'ActionParameterDefinition')),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.action_type = kwargs.get('action_type', str())
        self.action_description = kwargs.get('action_description', str())
        self.action_scopes = kwargs.get('action_scopes', [])
        self.action_parameters = kwargs.get('action_parameters', [])
        self.result_description = kwargs.get('result_description', str())

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
        if self.action_type != other.action_type:
            return False
        if self.action_description != other.action_description:
            return False
        if self.action_scopes != other.action_scopes:
            return False
        if self.action_parameters != other.action_parameters:
            return False
        if self.result_description != other.result_description:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def action_type(self):
        """Message field 'action_type'."""
        return self._action_type

    @action_type.setter
    def action_type(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'action_type' field must be of type 'str'"
        self._action_type = value

    @builtins.property
    def action_description(self):
        """Message field 'action_description'."""
        return self._action_description

    @action_description.setter
    def action_description(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'action_description' field must be of type 'str'"
        self._action_description = value

    @builtins.property
    def action_scopes(self):
        """Message field 'action_scopes'."""
        return self._action_scopes

    @action_scopes.setter
    def action_scopes(self, value):
        if __debug__:
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
                 all(isinstance(v, str) for v in value) and
                 True), \
                "The 'action_scopes' field must be a set or sequence and each value of type 'str'"
        self._action_scopes = value

    @builtins.property
    def action_parameters(self):
        """Message field 'action_parameters'."""
        return self._action_parameters

    @action_parameters.setter
    def action_parameters(self, value):
        if __debug__:
            from vda5050_msgs.msg import ActionParameterDefinition
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
                 all(isinstance(v, ActionParameterDefinition) for v in value) and
                 True), \
                "The 'action_parameters' field must be a set or sequence and each value of type 'ActionParameterDefinition'"
        self._action_parameters = value

    @builtins.property
    def result_description(self):
        """Message field 'result_description'."""
        return self._result_description

    @result_description.setter
    def result_description(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'result_description' field must be of type 'str'"
        self._result_description = value
