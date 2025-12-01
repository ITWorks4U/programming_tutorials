# ---
# run with:
# - pytest[.exe] 24_01_pytest.py [-v]
# - py.test.exe 24_00_unit_test.py [-v]
#
# -v: verbose <=> show additional informations
# -V: version <=> display the version instead
# ---

# important: pytest is a third party module, which must
# be installed by:
# pip[3|.exe] install pytest
#
# on some Linux systems use this instead:
# sudo apt install python-pytest, if pip command failed
import pytest

# use all required functions and custom exception
# class from math_test folder
from math_test.math_test_functions import *
from math_test.math_exception import MathException

def test_pass():
	assert addition(2, 3) == 5
#end test

def test_fail():
	assert subtraction(2, 2) == 1
#end test

def test_error():
	raise RuntimeError("oops")
#end test

def test_division_by_zero():
	with pytest.raises(MathException):
		division(5,0)
	#end with
#end test

@pytest.mark.skip(reason="Not implemented yet")
def test_skipped():
	assert multiplication(5, 0) == 0

@pytest.mark.xfail(reason="expected failure here")
def test_xfail():
	assert subtraction(-1, -1) == 1
#end test

@pytest.mark.xfail(reason="Should fail but doesn't")
def test_unexpected_success():
	assert addition(2, 2) == 4
#end test