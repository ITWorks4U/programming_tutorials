def measure_time_amount(func):
	def wrapper(*args, **kwargs):
		from time import perf_counter
		from datetime import timedelta

		start = perf_counter()
		func(*args, **kwargs)
		end = perf_counter()

		print(f"total time amount for {func.__name__}: {timedelta(seconds=(end-start))}")
	#end function

	return wrapper
#end function