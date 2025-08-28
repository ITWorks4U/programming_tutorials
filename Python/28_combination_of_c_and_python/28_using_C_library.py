# ---
# How to use functions in python, which were written
# in C. It contains simple function calls without
# typical C structures (not tested for macros, pointers, struct/union).
# C++ might work on the same way, but it's also not tested.
#
# Before you start make sure you've built your library first.
# ---

from ctypes import c_double, c_int, CDLL
from os.path import dirname, abspath, join, isfile

# ---
# global setups
# python_c_square, python_c_bubble_sort are a _NamedFuncPointer
python_c_square = None
python_c_bubble_sort = None
# ---

def square_multiplication(list_in: list) -> list:
	"""
	calling C function: "void square_multiplication(int n, double *array_in, double *array_out)";

	list_in:
		-	the number of elements for square multiplication
		-	must be of type range class to work with
	"""

	if not isinstance(list_in, range):
		raise ValueError("list_in argument is not type of range class")
	#end if

	n = len(list_in)

	if n == 0:
		raise ValueError("no number of elements were given")
	#end if

	topic: str = f"""
-----
using square multiplication
-----
	"""
	print(topic)

	# NOTE:
	# list_in must come with an asterisk,
	# otherwise you'll get an error on runtime
	c_arr_in = (c_double * n)(*list_in)
	c_arr_out = (c_double * n)()

	python_c_square(c_int(n), c_arr_in, c_arr_out)
	return c_arr_out
#end function

def bubble_sort_c_style() -> None:
	# Do you remember, that a sort of a huge number, e. g.: 250,000 of random elements
	# by using bubble sort in Python is a really bad idea?
	# Well, this is still true. Unless, this has been managed by the C library instead.
	from random import randint
	from time import time
	from datetime import timedelta

	topic: str = f"""
-----
using bubble sort
-----
	"""
	print(topic)

	upper_boundary: int = 250000

	# data may contain multiple elements
	data: list[int] = [randint(1,upper_boundary) for _ in range(upper_boundary)]
	c_arr_in = (c_double * upper_boundary)(*data)
	c_arr_out = (c_double * upper_boundary)()

	start: float = time()
	python_c_bubble_sort(upper_boundary, c_arr_in, c_arr_out)
	end: float = time()

	print(f"total time amount for {upper_boundary} random elements by using bubble sort: {timedelta(seconds=(end-start))}")
	return c_arr_out
#end function

def main() -> None:
	from platform import system
	from sys import argv

	detected_system = system()

	library_name = {
		"Windows" : "lib.dll",
		"Linux" : "lib.so",
		"Darwin" : "lib.dylib"
	}.get(detected_system, None)

	if not library_name:
		raise Exception(f"unsupported OS: {detected_system} detected...")
	#end if

	# check, if the certain library file migt not exists
	if not isfile(library_name):
		raise Exception(f"Missing library file \"{library_name}\". Please build that library in the library_creation/ folder first.")
	#end if

	script_location: str = dirname(abspath(argv[0]))
	library_path: str = join(script_location, library_name)

	try:
		# load the library
		basic_function_lib = CDLL(library_path)

		# ---
		# load void function from C library
		# ---

		# attempting to call the certain function
		# => might not be found on your IDE
		#    if so, then type your function to call by hand
		lib_hello_function = basic_function_lib.say_hello_from_C

		# define the result type of your function
		# => for void it's None
		lib_hello_function.restype = None

		# call the C function
		lib_hello_function()
		# ---

		print("----------")

		if not False:
			# ---
			# do a square multiplication with
			# 1,000,000 elements
			# ---
			global python_c_square

			python_c_square = basic_function_lib.square_multiplication
			python_c_square.restype = None
			squared_result = square_multiplication(range(1000000))

			for i, j in enumerate(squared_result):
				print(f"{i}: {j}")
			#end for
		#end if

		print("----------")

		if not False:
			# ---
			# bubble sort of 250,000 random numbers 
			# with C library
			# ---
			global python_c_bubble_sort

			python_c_bubble_sort = basic_function_lib.bubble_sort
			python_c_bubble_sort.restype = None
			sorted_elements = bubble_sort_c_style()

			print(f"first 10 sorted elements: {sorted_elements[:10]}")
		#end if
	except Exception as e:
		print(f"error: {e.args}")
	#end try
#end main

if __name__ == "__main__":
	main()
#end entry point