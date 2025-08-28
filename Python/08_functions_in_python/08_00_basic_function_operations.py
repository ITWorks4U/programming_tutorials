# ---
# before a function can be called,
# it must be defined first, otherwise it's
# an error on runtime (similar to C++)
# ---
#a_simple_function()

# definition of a function
def a_simple_function():
	print("I was called!")
# end function

print("--------------")
#	calling this function 10 times
for i in range(10):
	a_simple_function()
# end for

#	--------------
#	In C this works, however,
#	in python it won't, because
#	our function requires no arguments
#	--------------
#a_simple_function(1,2,3,4)

#	--------------
#	function with a single argument
#	to call -> causes an error, if
#	no argument is given
#	--------------

print("--------------")
# A function in python may have more than
# one different return type.

def pythonic_function(value):
	if value == 0:
		return bool(value)
	# end if

	if value == 1:
		return int(value)
	# end if

	if value == 2:
		return float(value)
	# end if

	if value == 3:
		return str(value)
	# end if

	return None
# end function

for i in range(5):
	retVal = pythonic_function(i)
	print(f"calling function for {i} and I receive that type: {retVal}")
# end for