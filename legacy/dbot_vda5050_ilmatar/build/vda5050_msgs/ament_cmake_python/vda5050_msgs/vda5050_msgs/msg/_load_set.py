# generated from rosidl_generator_py/resource/_idl.py.em
# with input from vda5050_msgs:msg/LoadSet.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_LoadSet(type):
    """Metaclass of message 'LoadSet'."""

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
                'vda5050_msgs.msg.LoadSet')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__load_set
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__load_set
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__load_set
            cls._TYPE_SUPPORT = module.type_support_msg__msg__load_set
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__load_set

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


class LoadSet(metaclass=Metaclass_LoadSet):
    """Message class 'LoadSet'."""

    __slots__ = [
        '_set_name',
        '_load_type',
        '_load_positions',
        '_bounding_box_reference',
        '_load_dimensions',
        '_max_weight',
        '_min_loadhandling_height',
        '_max_loadhandling_height',
        '_min_loadhandling_depth',
        '_max_loadhandling_depth',
        '_min_loadhandling_tilt',
        '_max_loadhandling_tilt',
        '_agv_speed_limit',
        '_agv_acceleration_limit',
        '_agv_deceleration_limit',
        '_pick_time',
        '_drop_time',
        '_description',
    ]

    _fields_and_field_types = {
        'set_name': 'string',
        'load_type': 'string',
        'load_positions': 'sequence<string>',
        'bounding_box_reference': 'vda5050_msgs/BoundingBoxReference',
        'load_dimensions': 'vda5050_msgs/LoadDimensions',
        'max_weight': 'double',
        'min_loadhandling_height': 'double',
        'max_loadhandling_height': 'double',
        'min_loadhandling_depth': 'double',
        'max_loadhandling_depth': 'double',
        'min_loadhandling_tilt': 'double',
        'max_loadhandling_tilt': 'double',
        'agv_speed_limit': 'double',
        'agv_acceleration_limit': 'double',
        'agv_deceleration_limit': 'double',
        'pick_time': 'double',
        'drop_time': 'double',
        'description': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.UnboundedString()),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['vda5050_msgs', 'msg'], 'BoundingBoxReference'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['vda5050_msgs', 'msg'], 'LoadDimensions'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.set_name = kwargs.get('set_name', str())
        self.load_type = kwargs.get('load_type', str())
        self.load_positions = kwargs.get('load_positions', [])
        from vda5050_msgs.msg import BoundingBoxReference
        self.bounding_box_reference = kwargs.get('bounding_box_reference', BoundingBoxReference())
        from vda5050_msgs.msg import LoadDimensions
        self.load_dimensions = kwargs.get('load_dimensions', LoadDimensions())
        self.max_weight = kwargs.get('max_weight', float())
        self.min_loadhandling_height = kwargs.get('min_loadhandling_height', float())
        self.max_loadhandling_height = kwargs.get('max_loadhandling_height', float())
        self.min_loadhandling_depth = kwargs.get('min_loadhandling_depth', float())
        self.max_loadhandling_depth = kwargs.get('max_loadhandling_depth', float())
        self.min_loadhandling_tilt = kwargs.get('min_loadhandling_tilt', float())
        self.max_loadhandling_tilt = kwargs.get('max_loadhandling_tilt', float())
        self.agv_speed_limit = kwargs.get('agv_speed_limit', float())
        self.agv_acceleration_limit = kwargs.get('agv_acceleration_limit', float())
        self.agv_deceleration_limit = kwargs.get('agv_deceleration_limit', float())
        self.pick_time = kwargs.get('pick_time', float())
        self.drop_time = kwargs.get('drop_time', float())
        self.description = kwargs.get('description', str())

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
        if self.set_name != other.set_name:
            return False
        if self.load_type != other.load_type:
            return False
        if self.load_positions != other.load_positions:
            return False
        if self.bounding_box_reference != other.bounding_box_reference:
            return False
        if self.load_dimensions != other.load_dimensions:
            return False
        if self.max_weight != other.max_weight:
            return False
        if self.min_loadhandling_height != other.min_loadhandling_height:
            return False
        if self.max_loadhandling_height != other.max_loadhandling_height:
            return False
        if self.min_loadhandling_depth != other.min_loadhandling_depth:
            return False
        if self.max_loadhandling_depth != other.max_loadhandling_depth:
            return False
        if self.min_loadhandling_tilt != other.min_loadhandling_tilt:
            return False
        if self.max_loadhandling_tilt != other.max_loadhandling_tilt:
            return False
        if self.agv_speed_limit != other.agv_speed_limit:
            return False
        if self.agv_acceleration_limit != other.agv_acceleration_limit:
            return False
        if self.agv_deceleration_limit != other.agv_deceleration_limit:
            return False
        if self.pick_time != other.pick_time:
            return False
        if self.drop_time != other.drop_time:
            return False
        if self.description != other.description:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def set_name(self):
        """Message field 'set_name'."""
        return self._set_name

    @set_name.setter
    def set_name(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'set_name' field must be of type 'str'"
        self._set_name = value

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
    def load_positions(self):
        """Message field 'load_positions'."""
        return self._load_positions

    @load_positions.setter
    def load_positions(self, value):
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
                "The 'load_positions' field must be a set or sequence and each value of type 'str'"
        self._load_positions = value

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
    def max_weight(self):
        """Message field 'max_weight'."""
        return self._max_weight

    @max_weight.setter
    def max_weight(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'max_weight' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'max_weight' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._max_weight = value

    @builtins.property
    def min_loadhandling_height(self):
        """Message field 'min_loadhandling_height'."""
        return self._min_loadhandling_height

    @min_loadhandling_height.setter
    def min_loadhandling_height(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'min_loadhandling_height' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'min_loadhandling_height' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._min_loadhandling_height = value

    @builtins.property
    def max_loadhandling_height(self):
        """Message field 'max_loadhandling_height'."""
        return self._max_loadhandling_height

    @max_loadhandling_height.setter
    def max_loadhandling_height(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'max_loadhandling_height' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'max_loadhandling_height' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._max_loadhandling_height = value

    @builtins.property
    def min_loadhandling_depth(self):
        """Message field 'min_loadhandling_depth'."""
        return self._min_loadhandling_depth

    @min_loadhandling_depth.setter
    def min_loadhandling_depth(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'min_loadhandling_depth' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'min_loadhandling_depth' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._min_loadhandling_depth = value

    @builtins.property
    def max_loadhandling_depth(self):
        """Message field 'max_loadhandling_depth'."""
        return self._max_loadhandling_depth

    @max_loadhandling_depth.setter
    def max_loadhandling_depth(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'max_loadhandling_depth' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'max_loadhandling_depth' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._max_loadhandling_depth = value

    @builtins.property
    def min_loadhandling_tilt(self):
        """Message field 'min_loadhandling_tilt'."""
        return self._min_loadhandling_tilt

    @min_loadhandling_tilt.setter
    def min_loadhandling_tilt(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'min_loadhandling_tilt' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'min_loadhandling_tilt' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._min_loadhandling_tilt = value

    @builtins.property
    def max_loadhandling_tilt(self):
        """Message field 'max_loadhandling_tilt'."""
        return self._max_loadhandling_tilt

    @max_loadhandling_tilt.setter
    def max_loadhandling_tilt(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'max_loadhandling_tilt' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'max_loadhandling_tilt' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._max_loadhandling_tilt = value

    @builtins.property
    def agv_speed_limit(self):
        """Message field 'agv_speed_limit'."""
        return self._agv_speed_limit

    @agv_speed_limit.setter
    def agv_speed_limit(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'agv_speed_limit' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'agv_speed_limit' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._agv_speed_limit = value

    @builtins.property
    def agv_acceleration_limit(self):
        """Message field 'agv_acceleration_limit'."""
        return self._agv_acceleration_limit

    @agv_acceleration_limit.setter
    def agv_acceleration_limit(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'agv_acceleration_limit' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'agv_acceleration_limit' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._agv_acceleration_limit = value

    @builtins.property
    def agv_deceleration_limit(self):
        """Message field 'agv_deceleration_limit'."""
        return self._agv_deceleration_limit

    @agv_deceleration_limit.setter
    def agv_deceleration_limit(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'agv_deceleration_limit' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'agv_deceleration_limit' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._agv_deceleration_limit = value

    @builtins.property
    def pick_time(self):
        """Message field 'pick_time'."""
        return self._pick_time

    @pick_time.setter
    def pick_time(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'pick_time' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'pick_time' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._pick_time = value

    @builtins.property
    def drop_time(self):
        """Message field 'drop_time'."""
        return self._drop_time

    @drop_time.setter
    def drop_time(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'drop_time' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'drop_time' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._drop_time = value

    @builtins.property
    def description(self):
        """Message field 'description'."""
        return self._description

    @description.setter
    def description(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'description' field must be of type 'str'"
        self._description = value
