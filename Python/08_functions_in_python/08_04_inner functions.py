"""
	Python allows you to define a function in a function.
	Usually, this can be used to make sure to do an
	action, where some conditions are satisfied early.

	An inner function can't be accessed from outside.
	This is only available in the called function itself.

	Let's say, you want to write a factorial function.
	Only integers are valid and these must not be
	negative or to high, ect.

	A factorial if n means: n * n-1 * n-2 * ... * 1
	for n = 1, 2, 3, ...
"""

def factorial_way_0(n: int) -> int:
	# checking, if argument n is an integer
	# since n has any type, we want to make
	# sure to have an integer
	if not isinstance(n, int):
		return "n must be an integer"
	#end if

	# n shall also be located in an interval of {1,50}
	if n < 1 or n > 50:
		return "n must be in interval {1,50}"
	#end if

	"""
		Usually, an exception may be thrown, if
		one of the conditions above wasn't satisfied,
		however, at this moment, we don't know how
		to do this.
	"""
	if n == 1:
		return 1
	#end if

	return n * factorial_way_0(n-1)
#end function

def factorial_way_1(n: int) -> int:
	result: int = 1

	while n > 1:
		result *= n
		n -= 1
	#end while

	return result
#end function

def factorial_way_2(n: int) -> int:
	# this inner function can only be accessed
	# inside of the factorial function
	#
	# since n (or k) is an integer and in interval
	# of {1,50}, we can use a recursion function
	# to calculate the factorial
	def inner_factorial(k):
		if k == 1:
			return 1
		#end if

		return k * inner_factorial(k-1)
	#end function

	return inner_factorial(k=n)
#end function

"""
	here, you can only call factorial(n) function,
	because innerFactorial(k) is hidden for you

	You could also use the input function to read
	from your keyboard or reading from file to
	read an "integer", however, this input is still
	a word!

	This shall also be handled correctly by using an
	exception handling, or regular expression or
	(in that case) by using a fixed value
"""
n = 10
print(f'f({n}) = {factorial_way_0(n)}')
print(f'f({n}) = {factorial_way_1(n)}')
print(f'f({n}) = {factorial_way_2(n)}')