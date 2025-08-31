# ---
# a decorator can also use the arguments of the
# function argument itself
# ---

from time import perf_counter
from datetime import timedelta

def decorator_for_different_functions(func):
	def wrapper(*args, **kwargs):
		start = perf_counter()
		result = func(*args, **kwargs)
		end = perf_counter()

		print(f">> total time amount for function {func.__name__}: {timedelta(seconds=(end-start))}")

		# in that case this argument function
		# returns the result, which can be used
		# elsewhere
		return result
	#end function

	return wrapper
#end function

@decorator_for_different_functions
def add_numbers(a: int = 1, b: int = 1, *args):
	result = a + b

	for arg in args:
		result += arg
	#end for

	return result
#end function

@decorator_for_different_functions
def subtract_numbers(*args):
	result = 0

	# the arbitrary arguments
	args_as_list = list(args)

	for a in args_as_list:
		result -= a
	#end for
	
	return result
#end function

@decorator_for_different_functions
def handle_kwargs(**kwargs):
	for key in kwargs.keys():
		print(f"{kwargs[key]}")
	# end for
# end function

if __name__ == "__main__":
	print(add_numbers(5, 3))
	print(add_numbers(1,2,3,4,5,6,7,8,9))

	print(subtract_numbers(*[i for i in range(100)]))

	handle_kwargs(user = "ITWorks4U", location = "YouTube / github", youtube = "https://github.com/ITWorks4U", github = "https://github.com/ITWorks4U/")
#end entry point