# generated from rosidl_generator_py/resource/_idl.py.em
# with input from vda5050_msgs:msg/Load.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Load(type):
    """Metaclass of message 'Load'."""

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
                'vda5050_msgs.msg.Load')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__load
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__load
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__load
            cls._TYPE_SUPPORT = module.type_support_msg__msg__load
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__load

            from vda5050_msgs.msg import BoundingBoxReference
            if BoundingBoxReference.__class__._TYPE_SUPPORT is None:
                BoundingBoxReference.__class__.__import_type_support__()

            from vda5050_msgs.msg import LoadDimensions
            if LoadDimensions.__class__._TYPE_SUPPORT is None:
                LoadDimensions.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Load(metaclass=Metaclass_Load):
    """Message class 'Load'."""

    __slots__ = [
        '_load_id',
        '_load_type',
        '_load_position',
        '_bounding_box_reference',
        '_load_dimensions',
        '_weight',
    ]

    _fields_and_field_types = {
        'load_id': 'string',
        'load_type': 'string',
        'load_position': 'string',
        'bounding_box_reference': 'vda5050_msgs/BoundingBoxReference',
        'load_dimensions': 'vda5050_msgs/LoadDimensions',
        'weight': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['vda5050_msgs', 'msg'], 'BoundingBoxReference'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['vda5050_msgs', 'msg'], 'LoadDimensions'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.load_id = kwargs.get('load_id', str())
        self.load_type = kwargs.get('load_type', str())
        self.load_position = kwargs.get('load_position', str())
        from vda5050_msgs.msg import BoundingBoxReference
        self.bounding_box_reference = kwargs.get('bounding_box_reference', BoundingBoxReference())
        from vda5050_msgs.msg import LoadDimensions
        self.load_dimensions = kwargs.get('load_dimensions', LoadDimensions())
        self.weight = kwargs.get('weight', float())

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
        if self.load_id != other.load_id:
            return False
        if self.load_type != other.load_type:
            return False
        if self.load_position != other.load_position:
            return False
        if self.bounding_box_reference != other.bounding_box_reference:
            return False
        if self.load_dimensions != other.load_dimensions:
            return False
        if self.weight != other.weight:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def load_id(self):
        """Message field 'load_id'."""
        return self._load_id

    @load_id.setter
    def load_id(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'load_id' field must be of type 'str'"
        self._load_id = value

    @builtins.property
    def load_type(self):
        """Message field 'load_type'."""
        return self._load_type

    @load_type.setter
    def load_type(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'load_type' field must be of type 'str'"
        self._load_type = value

    @builtins.property
    def load_position(self):
        """Message field 'load_position'."""
        return self._load_position

    @load_position.setter
    def load_position(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'load_position' field must be of type 'str'"
        self._load_position = value

    @builtins.property
    def bounding_box_reference(self):
        """Message field 'bounding_box_reference'."""
        return self._bounding_box_reference

    @bounding_box_reference.setter
    def bounding_box_reference(self, value):
        if __debug__:
            from vda5050_msgs.msg import BoundingBoxReference
            assert \
                isinstance(value, BoundingBoxReference), \
                "The 'bounding_box_reference' field must be a sub message of type 'BoundingBoxReference'"
        self._bounding_box_reference = value

    @builtins.property
    def load_dimensions(self):
        """Message field 'load_dimensions'."""
        return self._load_dimensions

    @load_dimensions.setter
    def load_dimensions(self, value):
        if __debug__:
            from vda5050_msgs.msg import LoadDimensions
            assert \
                isinstance(value, LoadDimensions), \
                "The 'load_dimensions' field must be a sub message of type 'LoadDimensions'"
        self._load_dimensions = value

    @builtins.property
    def weight(self):
        """Message field 'weight'."""
        return self._weight

    @weight.setter
    def weight(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'weight' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'weight' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._weight = value
