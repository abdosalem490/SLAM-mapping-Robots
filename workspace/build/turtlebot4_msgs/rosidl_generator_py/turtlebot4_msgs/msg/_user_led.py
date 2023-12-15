# generated from rosidl_generator_py/resource/_idl.py.em
# with input from turtlebot4_msgs:msg/UserLed.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_UserLed(type):
    """Metaclass of message 'UserLed'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'USER_LED_1': 0,
        'USER_LED_2': 1,
        'COLOR_OFF': 0,
        'COLOR_GREEN': 1,
        'COLOR_RED': 2,
        'COLOR_YELLOW': 3,
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('turtlebot4_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'turtlebot4_msgs.msg.UserLed')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__user_led
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__user_led
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__user_led
            cls._TYPE_SUPPORT = module.type_support_msg__msg__user_led
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__user_led

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'USER_LED_1': cls.__constants['USER_LED_1'],
            'USER_LED_2': cls.__constants['USER_LED_2'],
            'COLOR_OFF': cls.__constants['COLOR_OFF'],
            'COLOR_GREEN': cls.__constants['COLOR_GREEN'],
            'COLOR_RED': cls.__constants['COLOR_RED'],
            'COLOR_YELLOW': cls.__constants['COLOR_YELLOW'],
        }

    @property
    def USER_LED_1(self):
        """Message constant 'USER_LED_1'."""
        return Metaclass_UserLed.__constants['USER_LED_1']

    @property
    def USER_LED_2(self):
        """Message constant 'USER_LED_2'."""
        return Metaclass_UserLed.__constants['USER_LED_2']

    @property
    def COLOR_OFF(self):
        """Message constant 'COLOR_OFF'."""
        return Metaclass_UserLed.__constants['COLOR_OFF']

    @property
    def COLOR_GREEN(self):
        """Message constant 'COLOR_GREEN'."""
        return Metaclass_UserLed.__constants['COLOR_GREEN']

    @property
    def COLOR_RED(self):
        """Message constant 'COLOR_RED'."""
        return Metaclass_UserLed.__constants['COLOR_RED']

    @property
    def COLOR_YELLOW(self):
        """Message constant 'COLOR_YELLOW'."""
        return Metaclass_UserLed.__constants['COLOR_YELLOW']


class UserLed(metaclass=Metaclass_UserLed):
    """
    Message class 'UserLed'.

    Constants:
      USER_LED_1
      USER_LED_2
      COLOR_OFF
      COLOR_GREEN
      COLOR_RED
      COLOR_YELLOW
    """

    __slots__ = [
        '_led',
        '_color',
        '_blink_period',
        '_duty_cycle',
    ]

    _fields_and_field_types = {
        'led': 'uint8',
        'color': 'uint8',
        'blink_period': 'uint32',
        'duty_cycle': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.led = kwargs.get('led', int())
        self.color = kwargs.get('color', int())
        self.blink_period = kwargs.get('blink_period', int())
        self.duty_cycle = kwargs.get('duty_cycle', float())

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
        if self.led != other.led:
            return False
        if self.color != other.color:
            return False
        if self.blink_period != other.blink_period:
            return False
        if self.duty_cycle != other.duty_cycle:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def led(self):
        """Message field 'led'."""
        return self._led

    @led.setter
    def led(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'led' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'led' field must be an unsigned integer in [0, 255]"
        self._led = value

    @builtins.property
    def color(self):
        """Message field 'color'."""
        return self._color

    @color.setter
    def color(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'color' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'color' field must be an unsigned integer in [0, 255]"
        self._color = value

    @builtins.property
    def blink_period(self):
        """Message field 'blink_period'."""
        return self._blink_period

    @blink_period.setter
    def blink_period(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'blink_period' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'blink_period' field must be an unsigned integer in [0, 4294967295]"
        self._blink_period = value

    @builtins.property
    def duty_cycle(self):
        """Message field 'duty_cycle'."""
        return self._duty_cycle

    @duty_cycle.setter
    def duty_cycle(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'duty_cycle' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'duty_cycle' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._duty_cycle = value
