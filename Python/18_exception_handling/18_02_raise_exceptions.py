# ---
# - usually, exceptions are be thrown
# - in Python those will be raised
# ---

def divide(a: int, b: int) -> int:
	"""
	Divide a / b, where:

	-	a, b must be an integer
	-	b must not be 0
	
	If one of the conditions above fails, an exception is going
	to raise instead.

	a:

	-	nominator

	b:

	-	denominator

	returns:

	-	result of nominator / denominator
	"""

	if not (isinstance(a, int) and isinstance(b, int)):
		raise Exception("a or b is not detected as an integer")
	#end if

	if b == 0:
		raise Exception("b must not be 0")
	#end if

	return a // b
#end function

objects_to_use: list = [(10,5), (23,7), (7,0), (3, "3"), (True, True)]

for o in objects_to_use:
	try:
		print(f"trying to use [{o[0]}, {o[1]}] for division: ", end="")
		print(divide(o[0], o[1]))
	except Exception as e:
		# remeber: e.args is a list, which usually contains only one element
		# so e.args[0] gives us the information we want
		print(f"ERROR: {e.args[0]}")
	#end try
#end for