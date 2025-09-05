# ---
# Overwriting a function / class method does also
# not work as expected. In contrast to other OOP
# languages, like C++, Java, C# in Python this
# must be handled with a dispatcher decorator.
#
# By default the last defined function dominates and the
# Python interpreter will complain about missing arguments.
#
# Similar to singledispatch, the multipledispatch allows
# to use functions / class methods with a different amount
# of arguments, where those arguments are also reserved
# for a certain data type.
#
# The multipledispatch module may be installed by pip first.
# ---

from multipledispatch import dispatch

@dispatch(int, int)
def add_elements(a: int, b: int) -> int:
	return a + b
#end function

@dispatch(int, int, int)
def add_elements(a: int, b: int, c: int) -> int:
	return a + b + c
#end function

@dispatch(float, float, float)
def add_elements(a: float, b: float, c: float) -> float:
	return a + b + c
#end function

# ---

#NOTE: a, b, c must not be given in the function call
print(add_elements(14, 24))                  # works for both integers
print(add_elements(14, 24, -12))             # works for all three integers
print(add_elements(1.4e0, 2.4e-5, -0.3e2))   # works for all three floating points
# print(add_elements("abc", "def"))          # causes an error, because no add_elements(str, str) is defined