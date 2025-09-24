# ---
# Boosting performance is often necessary, otherwise instructions will
# slow down your application (very) fast. Boosting up a recursion,
# like the fibonacci series for high numbers gives you the power of control.
# ---

from time_decorator import time_measurment

# default way to handle the fibonacci series
# NOTE: It's not a good idea to use this for high numbers, like n > 40,
# unless you've enough time to waste.
@time_measurment
def fibonacci_0(n: int) -> int:
	if n == 0 or n == 1:
		return n
	#end if

	return fibonacci_0(n=n-1) + fibonacci_0(n=n-2)
#end function

# create an internal buffer to figure out, if F(n) has
# already been calculated
@time_measurment
def fibonacci_1(n: int, already_handled: dict[int] = {}) -> int:
	if n in already_handled:
		return already_handled[n]
	#end if

	if n == 0 or n == 1:
		already_handled[n] = n
	else:
		already_handled[n] = fibonacci_1(n-1, already_handled) + fibonacci_1(n-2, already_handled)
	#end if

	return already_handled[n]
#end function

# use the cache decorator instead
@time_measurment
def fibonacci_2(n: int) -> int:
	from functools import cache

	@cache
	def fibonacci(k: int) -> int:
		if k == 0 or k == 1:
			return k
		#end if

		return fibonacci(k=k-1) + fibonacci(k=k-2)
	#end function

	return fibonacci(k=n)
#end function

# use lru_cache decorator instead
@time_measurment
def fibonacci_3(n: int) -> int:
	from functools import lru_cache

	@lru_cache
	def fibonacci(k: int) -> int:
		if k == 0 or k == 1:
			return k
		#end if

		return fibonacci(k=k-1) + fibonacci(k=k-2)
	#end function

	return fibonacci(k=n)
#end function

# use bottom_up implementation instead
@time_measurment
def fibonacci_4(n: int) -> int:
	if n == 0 or n == 1:
		return n
	#end if

	already_handled: list[int] = [0, 1]
	for _ in range(2, n + 1):
		already_handled.append(already_handled[-1] + already_handled[-2])
	#end for

	return already_handled[n]
#end function

if __name__ == "__main__":
	from sys import argv

	if len(argv) == 2:
		recursion_levels: tuple[str] = ("raw_recursion", "list_recursion", "cache_recursion", "lru_recursion", "bottom_up")

		if argv[1] in recursion_levels:
			upper_boundary: int = 40

			for i in range(upper_boundary + 1):
				print(f"Fib({i}) ... => ", end="")

				if argv[1] == recursion_levels[0]:
					# NOTE: F(40) took up to 2 minutes, 30 seconds
					fibonacci_0(i)
				elif argv[1] == recursion_levels[1]:
					# NOTE: F(40) took up to 22 µs
					fibonacci_1(i)
				elif argv[1] == recursion_levels[2]:
					# NOTE: F(40) took up to 40 µs
					fibonacci_2(i)
				elif argv[1] == recursion_levels[3]:
					# NOTE: F(40) took up to 47 µs
					fibonacci_3(i)
				elif argv[1] == recursion_levels[4]:
					# NOTE: F(40) took up to 6 µs
					fibonacci_4(i)
				#end if
			# #end for
		else:
			print(f"no match for {argv[1]}...")
		#end if
	else:
		how_to_use: str = f"""
Run the fibonacci series with an upper limit of 40, where the
<run_option> is required for which recursion is in use.

usage: {argv[0]} <run_option>

<run_option>:
raw_recursion
   - runs the basic recursion for fibonacci series
list_recursion
   - runs the recursion with a list buffer
cache_recursion:
   - runs the recursion with @cache from functools
lru_recursion:
   - runs the recursion with @lru from functools
bottom_up:
   - runs the fibonacci series with an internal list

examples:
{argv[0]} raw_recursion
{argv[0]} cache_recursion
"""

		print(how_to_use)
	#end if
#end entry point