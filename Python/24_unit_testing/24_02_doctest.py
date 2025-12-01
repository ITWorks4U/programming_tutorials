# ---
# run with:
# - python[3|.exe] 24_02_docest.py
#
# in contrast to unittest or pytest the tests
# are realized in the documentations instead
#
# to see the results use:
# doctest.testmod(verbose=True)
#
# Similar to unittest, doctest is available
# by default, but this doesn't comes with
# powerful features.
#
# Within the documentation everything is going to test,
# which starts with >>> <command> (similar to python[3|.exe] without an additional python script)
#
# NOTE: A function / class method / ... can be tested only, if this instruction is available!
#---

# default test: check, if a + b returns the expected result
def addition_test(a: int, b: int) -> int:
	"""
	>>> addition_test(5,5)
	10

	>>> addition_test(-1,-1)
	-2
	"""
	return a + b
#end test

# ---
# - check, if the desired functions from math_test_functions are working
# - 2 ways to realize:
#   - import the modules as usual (on top of this script, but not inside the function itself)
#   - import the modules within the documentation itself
# ---
def module_test():
	"""
	>>> from math_test.math_test_functions import subtraction
	>>> subtraction(-1,-1)
	0

	>>> from math_test.math_test_functions import division
	>>> division(5,1)
	5

	>>> division(10,0)
	Traceback (most recent call last):
	...
	math_test.math_exception.MathException: denominator must not be 0
	"""
#end test

if __name__ == "__main__":
	from doctest import testmod

	# verbose flag MUST be set to true, otherwise
	# you don't see anything
	testmod(verbose=True)
#end entry point