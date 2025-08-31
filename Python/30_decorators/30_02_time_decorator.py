# ---
# measuring a time amount to loop 100,000,000 times
# by using a while and a for loop
# ---

from time import perf_counter
from datetime import timedelta

_MAX_COUNTER = 100000000

def time_measurment(func) -> None:
	def wrapper():
		start = perf_counter()
		func()
		end = perf_counter()

		print(f"total time amount for function {func.__name__}: {timedelta(seconds=(end-start))}")
	#end function

	return wrapper
#end function

@time_measurment
def func_0() -> None:
	ctr: int = 0

	while ctr != _MAX_COUNTER:
		ctr += 1
	#end while
#end function

@time_measurment
def func_1() -> None:
	for _ in range(_MAX_COUNTER):
		pass
	#end for
#end function

if __name__ == "__main__":
	func_0()
	func_1()
#end entry point