# ---
# Collatz conjecture:
# - take any natural number > 0
# - if the number is odd: multiply with 3, add 1
# - if the number is even: divide the number by 2
#
# usually, if 1 returns, then this number is odd as well, but
# the series of 1,4,2,1,4,2,1,... never ends, thus when 1 has
# been reached, the operation ends
# ---

from datetime import timedelta
from timeit import Timer

collatz_series: list[int] = []
_UPPER_LIMIT: int = 73

def collatz_recursive(number: int) -> int:
	collatz_series.append(number)

	if number == 1:
		return 1
	#end if

	# if number is even
	if number % 2 == 0:
		return collatz_recursive(number//2)
	#end if

	# otherwise number is odd
	return collatz_recursive(3 * number + 1)
#end function

def collatz_iteration(number: int) -> int:
	while number != 1:
		collatz_series.append(number)

		if number % 2 == 0:
			number = number // 2
		else:
			number = 3 * number + 1
		#end if
	#end while

	collatz_series.append(1)
	return 1
#end function

t = Timer(lambda: collatz_iteration(_UPPER_LIMIT))
print(f"time amount for loop: {timedelta(seconds=t.timeit(number=1))}")
print(f"series: {collatz_series}")
collatz_series.clear()

t = Timer(lambda: collatz_recursive(_UPPER_LIMIT))
print(f"time amount for recursion: {timedelta(seconds=t.timeit(number=1))}")
print(f"series: {collatz_series}")