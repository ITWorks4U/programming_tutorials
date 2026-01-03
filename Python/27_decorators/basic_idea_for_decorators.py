# ---
# A decorator is a function, which wraps other functions,
# class methods or classes itself.
#
# Applying functions to call a function and use the arguments
# can be used, but this is also results to pitfalls. Moreover
# this works for a limited function type.
# ---

def general_function(f, a):
	# do something with function f and argument a
	return f(a)
#end function

# ---
# functions to pass
# ---

def square_root(x):
	return x * x
#end function

def add_0(a):
	return a + a
#end function

def add_1(a, b):
	return a + b
#end function

if __name__ == "__main__":
	# using the "general_function"
	# to apply the other functions
	#
	# syntax: general_function(function_to_let_call, single_argument_for_function_left)
	print(f"9 + 9 = {general_function(add_0, 9)}")
	print(f"5 x 5 = {general_function(square_root, 5)}")
	print(f"(25-56)² = {general_function(square_root, 25 - 56)}")

	# this, however, won't work:
	# reason: general_function only takes one argument after function argument
	# => TypeError: "general_function() takes 2 positional arguments but 3 were given"
	# print(f"3 + 6 = {general_function(add_1, 3, 6)}")
#end entry point