# ---
# What about with famous examples, like the fibonacci series?
# there're some limitations given:
# - upper limit is set to 40 only
# - no optimization is in use here (intented)
# - compared with recursion as well as with iteration
# ---

from datetime import timedelta
from timeit import timeit, Timer

_UPPER_LIMIT = 40

def fibonacci_loop() -> None:
	fib_series: list[int] = []
	ctr: int = 0

	while ctr < _UPPER_LIMIT:
		match ctr:
			case (0 | 1):
				fib_series.append(ctr)
			case _:
				fn: int = fib_series[ctr - 1] + fib_series[ctr - 2]
				fib_series.append(fn)
			#end cases
		#end match

		ctr += 1
	#end while
#end function

def fibonacci_recursion(nbr: int) -> int:
	match nbr:
		case (0 | 1):
			return nbr
		case _:
			return fibonacci_recursion(nbr-1) + fibonacci_recursion(nbr-2)
		#end cases
	#end match
#end function

print(f"time amount for loop: {timedelta(seconds=timeit(stmt=fibonacci_loop, number=1))}")

t = Timer(lambda: fibonacci_recursion(_UPPER_LIMIT))
print(f"time amount for recursion: {timedelta(seconds=t.timeit(number=1))}")