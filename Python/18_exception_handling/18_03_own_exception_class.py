# ---
# custom exception class
# ---
class MathError(Exception):
	def __init__(self, message: str) -> None:
		self.message = message
	#end constructor

	# this method is obsolete, because MathError
	# has also access to args property
	def print_error(self):
		return self.message
	#end method
#end class

# ---
# function, which may throw (raise)
# an exception
# ---
def divide(n: int, k: int):
	if k == 0:
		# ---
		# must be done, otherwise the
		# custom exception is never been
		# triggered and maybe never been handled
		# e. g. no basic exception handling is given
		# ---
		raise MathError("k must not be 0!")
	#end if

	return n/k
#end function

# ---
# running
# ---
objects_to_use: list = [(10,5), (23,7), (7,0), (3, "3"), (True, True)]

for o in objects_to_use:
	try:
		print(f"trying to use [{o[0]}, {o[1]}] for division: ", end="")
		print(divide(o[0], o[1]))
	except MathError as me:
		print(f"MATH ERROR: {me.args[0]} <=> {me.print_error()}")
	except Exception as e:
		print(f"ERROR: {e.args[0]}")
	#end try
#end for