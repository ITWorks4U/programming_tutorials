# ---
# run with:
# - python[3|.exe] 24_00_unit_test.py
# - python[3|.exe] -m unittest 24_00_unit_test.py
# ---

import unittest as ut

# use all required functions and custom exception
# class from math_test folder
from math_test.math_test_functions import *
from math_test.math_exception import MathException

class TestAddFunction(ut.TestCase):
	# ---
	# can be used for create and terminate streams
	# ---
	def setUp(self):
		pass
	#end method
	
	def tearDown(self):
		pass
	#end method

	# ---
	# test cases
	# ---

	def test_addition(self):
		# assertEqual:
		# assuming, that 2 + 3 shall return 5
		# if this fails, then the third argument is going to
		# print on console
		self.assertEqual(addidion(2, 3), 5, "2 + 3 shall usually return 5...")
	#end test

	def test_subtraction(self):
		self.assertEqual(subtraction(-1, -1), 0, "-1 - -1 = 0....")
	#end test

	# expecting, that this test case fails
	# if true, everything is fine
	# otherwise an unexpected success returns
	@ut.expectedFailure
	def test_multiplication_fail(self):
		self.assertEqual(multiplication(5, 0), 50, "5 * 0  = 0")
	#end test

	# expecting, that the MathException will raise there
	def test_division_by_zero(self):
		with self.assertRaises(MathException):
			division(5,0)
		#end with
	#end test

	# this test throws an error
	# the other tests are still able to continue
	def test_raise_exception(self):
		raise RuntimeError("oops")
	#end test

	# skip that test
	@ut.skip
	def test_skip(self):
		pass
	#end test
#end class

if __name__ == '__main__':
	ut.main()
#end entry point