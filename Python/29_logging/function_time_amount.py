from time import perf_counter
from datetime import timedelta

MAX_COUNTER = 100000000
STEP_COUNTER = 1000000

def time_measurment(func) -> None:
	def wrapper():
		start = perf_counter()
		func()
		end = perf_counter()

		print(f"total time amount for function {func.__name__}: {timedelta(seconds=(end-start))}")
	#end function

	return wrapper
#end function