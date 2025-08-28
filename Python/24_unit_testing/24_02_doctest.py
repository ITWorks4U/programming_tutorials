# ---
# run with:
# - python[3|.exe] 24_02_docest.py
#
# in contrast to unittest or pytest the tests
# are realized in the documentations instead
#
# to see the results use:
# doctest.testmod(verbose=True)
# ---

import doctest

def add(a, b):
	"""
	Returns the sum of a and b.

	>>> add(2, 3)
	5
	>>> add(-1, 1)
	0
	>>> add(0, 0)
	0
	"""

	return a + b
#end test

def divide(a, b):
	"""
	Performs integer division of a by b.

	>>> divide(10, 2)
	5
	>>> divide(9, 3)
	3
	>>> divide(1, 0)
	Traceback (most recent call last):
		...
	ZeroDivisionError: integer division or modulo by zero
	"""
	return a // b
#end test

if __name__ == "__main__":
	import doctest
	doctest.testmod(verbose=True)
#end entry point