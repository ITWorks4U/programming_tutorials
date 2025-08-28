# ---
# a function also may comes with a dynamic number of arguments
#
# defVal is marked as an optional argument,
# by assigning with any default value
#
# defVal starts with a default value, when
# the function is called without an argument
# and its value will be changed by calling
# the function with a single argument
#
# see: print() function
# ---
def function(defVal = "My own defined value!"):
	print(defVal)
# end function

function(123)
function("ABC")
function()

print("--------------")

# ---
# adding a+b+c, where b and c
# have default values by default
#
# hint: if you want to make sure, that
# 'a' shall be an integer on function call,
# then write: a: int
#
# for the interpreter a might still be any
# type, however, it helps you to read
# the parameter(s) correctly
#
# since default arguments are in use it's not
# allowed to add another arguments without
# a default value behind the optional arguments
#
# an optional argument can also be triggered by
# using name=value
# ---
def add(a: int, b = -10, c = 500):
	return a + b + c
#end function

print(add(999))

# Who says, that b must come before c? :o)
print(add(100,c=-147,b=158))

print("--------------")