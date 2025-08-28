# ---
# using recursion
# ---
# most popular examples with recursion:
# - fibonacci series
# - factorial series
# - great common divisor
# - some sorting algorithms
# - ...
# ---

# calculating the fibonacci series
# attention: if you have ENOUGH time in your life, or if you
# want to see the death of the sun,
# then you also >could< try to use a value of 50 or higher o.O
#
# without using a last recently cache... don't do this :o)
#
# fib(n) = fib(n-1) + fib(n-2)

def fibonacci_recursion(nbr: int):
	if nbr == 0:
		return 0
	#end if

	if nbr == 1:
		return 1
	#end if

	return fibonacci_recursion(nbr-1) + fibonacci_recursion(nbr-2)
#end function

def fibonacci_loop(nbr: int):
	n1, n2 = 0, 1
	count = 0

	# check if the number of terms is valid
	while count < nbr:
		print(f"fib({count}) = {n1}")
		nth = n1 + n2

		# update values
		n1 = n2
		n2 = nth
		count += 1
	#end while
#end function

nbr: int = 30

print(f"fib({nbr}) = {fibonacci_recursion(nbr)}")

print("---	using nbr loop in combination	---")

#	print function can also be used with special formatting
for i in range(nbr):
	print(f"fib({i}) = {fibonacci_recursion(i)}")
#end for

print("---	using nbr loop instead	---")
fibonacci_loop(nbr)