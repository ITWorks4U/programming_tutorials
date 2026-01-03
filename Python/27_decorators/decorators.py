# ---
# Offers some decorators to work with.
# ---

from time import perf_counter
from datetime import timedelta

# 100,000,000
MAX_COUNTER = 100000000

# basic decorator for functions without an argument
def time_measurment_0(func):
	def wrapper():
		start = perf_counter()
		func()
		end = perf_counter()

		print(f"total time amount for {func.__name__}: {timedelta(seconds=(end-start))}")
	#end wrapper

	#NOTE: The nested wrapper function must not contain
	#      a bracket pair, otherwise this leads into
	#      an error during runtime.
	return wrapper
#end function

# decorator for functions with any kind and any amount of arguments
def time_measurment_1(func):
	def wrapper(*args, **kwargs):
		start = perf_counter()
		func(*args, **kwargs)
		end = perf_counter()

		print(f"total time amount for {func.__name__}: {timedelta(seconds=(end-start))}")
	#end wrapper

	return wrapper
#end function

# decorator for classes, like a singleton class
def singleton_instance(cls):
	instances = {}

	def get_instance(*args, **kwargs):
		if cls not in instances:
			instances[cls] = cls(*args, **kwargs)
		#end if

		return instances
	#end function

	return get_instance
#end function