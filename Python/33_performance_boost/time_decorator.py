# ---
# NOTE: This wrapper is more in use for recursive functions. To avoid to receive
# thousands, millions, ... outputs to the console, only the recursion top level
# is using this wrapper.
#
# Otherwise the decorator will also wrap every sub
# recursion level, which slows the program down immensely,
# potentially causing a hang or apparent infinite loop.
# ---

from time import perf_counter
from datetime import timedelta
from functools import wraps

def time_measurment(func) -> None:
	@wraps(func)
	def wrapper(*args, **kwargs):
		if wrapper._is_running:
			return func(*args, **kwargs)
		#end if

		wrapper._is_running = True
		try:
			start = perf_counter()
			result = func(*args, **kwargs)
			end = perf_counter()

			print(f"total time amount for function {func.__name__}: {timedelta(seconds=(end-start))}")

			return result
		finally:
			wrapper._is_running = False
	#end function

	wrapper._is_running = False
	return wrapper
#end function