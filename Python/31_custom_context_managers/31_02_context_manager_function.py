# ---
# unlike to a class a function itself can also be used for
# a custom context manager, which is very often in use
# ---

from time import perf_counter
from datetime import timedelta

from contextlib import contextmanager

@contextmanager
def custom_context_manager():
	start = perf_counter()

	try:
		# something, which shall be used outside,
		# e. g.: database connection to perform any command
		# => the yield expression can also return an object,
		#    which can be used outside of this "function"
		yield
	except Exception as e:
		print(f"error: {e.args}")

		# if this exception needs to be handled outside,
		# then reraise this => must be catched by an
		# another exception handler ;-)
		# raise
	finally:
		end = perf_counter()
		print(f"total time amount for this context manager function {custom_context_manager.__name__}: {timedelta(seconds=(end-start))}")
	#end try
#end function

if __name__ == "__main__":
	upper_boundary: int = 100000000

	with custom_context_manager():
		for _ in range(upper_boundary):
			pass
		#end for
	#end with

	print("--------------")

	with custom_context_manager():
		ctr: int = 0
		while ctr != upper_boundary:
			ctr += 1
		#end while
	#end with

	print("--------------")

	with custom_context_manager():
		for i in range(upper_boundary):
			if i == (upper_boundary // 2):
				raise RuntimeError("this is too much...")
			#end if
		#end for
	#end with
#end entry point