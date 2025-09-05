# ---
# overloading a function / class method is not
# identical to other OOP languages, like
# C++, Java, C#, ...
#
# In Python this can be done by different modules.
# ---

from functools import singledispatch

# with @singledispatch this function will be
# marked to be able to override
@singledispatch
def add_arguments(a, b) -> None:
	# this is a base function, which is handled as
	# a pattern; this can also be used for other
	# data types, which doesn't match with the
	# registered functions below
	print(f"argument a ({type(a)}) or b ({type(b)}) can't be used in a correct way: ", end="")
#end function

# this command allows to register the add_arguments function,
# and override this for integers only; the types behind
# a and b are optional and does not affect the
# registered function
@add_arguments.register
def _(a: int, b: int) -> int:
	print("function call for integers only: ", end="")
	return a + b
#end function

@add_arguments.register
def _(a: str, b: str) -> str:
	print("function call for strings only: ", end="")
	return a + b
#end function

# -----------

#NOTE: a, b must not be given in the function call
print(add_arguments(3,4))             # works for integers
print(add_arguments("123", "456"))    # works for strings
print(add_arguments(7.53,23))         # does not work, because float and integer
print(add_arguments([1,2,3],[4,5,6])) # does also not work for list and list