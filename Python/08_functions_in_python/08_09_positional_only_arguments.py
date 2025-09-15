# ---
# Positional only arguments are in use to prevent
# overriding parameter names.
#
# Those functions are often in use for C function
# implementations.
# ---
def add_0(a: int, b: int, /) -> int:
	return a + b
#end function

def add_1(a: int, b: int, /, c: int = 0) -> int:
	return a + b + c
#end function

def add_2(a: int, b: int = 0, /) -> int:
	return a + b
#end function

# able to call
print(add_0(5,7))

# c is able to modify, because this stands behind / argument
print(add_1(9,8,c=81))

print(add_2(1,2))
print(add_2(4))

# unable to call
# => the python interpreter compains about, that the
# arguments are named, which are not allowed
# => "TypeError: add_0() got some positional positional-only arguments
# passed aas keyword arguments: 'a, b'"
# print(add_0(a=1,b=2))