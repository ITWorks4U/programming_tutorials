from math_test.math_exception import MathException

def addition(a: int, b: int) -> None:
	if not (isinstance(a, int) and isinstance(b, int)):
		raise ValueError("a or b is not an integer")
	#end if

	return a + b
#end function

def subtraction(a: int, b: int) -> None:
	if not (isinstance(a, int) and isinstance(b, int)):
		raise ValueError("a or b is not an integer")
	#end if

	return a - b
#end function

def multiplication(a: int, b: int) -> None:
	if not (isinstance(a, int) and isinstance(b, int)):
		raise ValueError("a or b is not an integer")
	#end if

	return a * b
#end function

def division(a: int, b: int) -> None:
	if not (isinstance(a, int) and isinstance(b, int)):
		raise ValueError("a or b is not an integer")
	#end if

	if b == 0:
		raise MathException("denominator must not be 0")
	#end if

	return a // b
#end function