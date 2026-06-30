# generated from rosidl_generator_py/resource/_idl.py.em
# with input from vda5050_msgs:msg/AGVGeometry.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_AGVGeometry(type):
    """Metaclass of message 'AGVGeometry'."""

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
                'vda5050_msgs.msg.AGVGeometry')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__agv_geometry
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__agv_geometry
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__agv_geometry
            cls._TYPE_SUPPORT = module.type_support_msg__msg__agv_geometry
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__agv_geometry

            from vda5050_msgs.msg import Envelope2D
            if Envelope2D.__class__._TYPE_SUPPORT is None:
                Envelope2D.__class__.__import_type_support__()

            from vda5050_msgs.msg import Envelope3D
            if Envelope3D.__class__._TYPE_SUPPORT is None:
                Envelope3D.__class__.__import_type_support__()

            from vda5050_msgs.msg import WheelDefinition
            if WheelDefinition.__class__._TYPE_SUPPORT is None:
                WheelDefinition.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class AGVGeometry(metaclass=Metaclass_AGVGeometry):
    """Message class 'AGVGeometry'."""

    __slots__ = [
        '_wheel_definitions',
        '_envelopes2d',
        '_envelopes3d',
    ]

    _fields_and_field_types = {
        'wheel_definitions': 'sequence<vda5050_msgs/WheelDefinition>',
        'envelopes2d': 'sequence<vda5050_msgs/Envelope2D>',
        'envelopes3d': 'sequence<vda5050_msgs/Envelope3D>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['vda5050_msgs', 'msg'], 'WheelDefinition')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['vda5050_msgs', 'msg'], 'Envelope2D')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['vda5050_msgs', 'msg'], 'Envelope3D')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.wheel_definitions = kwargs.get('wheel_definitions', [])
        self.envelopes2d = kwargs.get('envelopes2d', [])
        self.envelopes3d = kwargs.get('envelopes3d', [])

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
        if self.wheel_definitions != other.wheel_definitions:
            return False
        if self.envelopes2d != other.envelopes2d:
            return False
        if self.envelopes3d != other.envelopes3d:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def wheel_definitions(self):
        """Message field 'wheel_definitions'."""
        return self._wheel_definitions

    @wheel_definitions.setter
    def wheel_definitions(self, value):
        if __debug__:
            from vda5050_msgs.msg import WheelDefinition
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
                 all(isinstance(v, WheelDefinition) for v in value) and
                 True), \
                "The 'wheel_definitions' field must be a set or sequence and each value of type 'WheelDefinition'"
        self._wheel_definitions = value

    @builtins.property
    def envelopes2d(self):
        """Message field 'envelopes2d'."""
        return self._envelopes2d

    @envelopes2d.setter
    def envelopes2d(self, value):
        if __debug__:
            from vda5050_msgs.msg import Envelope2D
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
                 all(isinstance(v, Envelope2D) for v in value) and
                 True), \
                "The 'envelopes2d' field must be a set or sequence and each value of type 'Envelope2D'"
        self._envelopes2d = value

    @builtins.property
    def envelopes3d(self):
        """Message field 'envelopes3d'."""
        return self._envelopes3d

    @envelopes3d.setter
    def envelopes3d(self, value):
        if __debug__:
            from vda5050_msgs.msg import Envelope3D
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
                 all(isinstance(v, Envelope3D) for v in value) and
                 True), \
                "The 'envelopes3d' field must be a set or sequence and each value of type 'Envelope3D'"
        self._envelopes3d = value
