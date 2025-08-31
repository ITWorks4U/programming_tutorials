# ---
# A decorator is a general function / class method,
# which allows you to use other functions / class methods for a specific purpose.
#
# By default a @decorator instruction is in use, where "@decorator"
# is not required. This is the function / class method name itself.
# ---

def decorator(func):
	# a decorator requires a nested wrapper function
	# to let call the func argument itself
	def wrapper():
		print("Before calling the function.")
		func()
		print("After calling the function.")
	#end function

	# required to let tell the python interpreter,
	# that the nested func is no longer required
	#
	# if you omit that return statement, then the error appears:
	# 'NoneType' object is not callable
	return wrapper
#end function

# Applying the decorator to a function
@decorator
def greet():
	print("Hello, World!")
#end function

# same here
@decorator
def how_are_you():
	print("How are you?")
#end function

greet()
how_are_you()