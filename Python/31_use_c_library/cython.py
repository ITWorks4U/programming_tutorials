# ---
# How to use functions in python, which were written
# in C/C++? It contains simple function calls without
# typical C structures (not tested for macros, pointers, struct/union).
#
# C# libraries might work on the same way, but this has not been tested yet.
#
# NOTE: Before you start make sure you've built your library first.
# NOTE: Never use those functions / algorithms in raw Python, unless you have enough time to waste. ;-)
# ---

from ctypes import CDLL, c_double
from os.path import dirname, abspath, join, isfile
from time_measurment import measure_time_amount

@measure_time_amount
def square_multiplication(cdll_instance: CDLL, upper_boundary: int = 100000000) -> None:
	"""
	Do a square multiplication from 0..99,999,999.
	
	:param cdll_instance: instance of the CDLL class
	:type cdll_instance: CDLL
	:param upper_boundary: upper boundary for square multiplication
	:type upper_boundary: int
	"""

	print("... square multiplication")
	list_in = [i for i in range(upper_boundary)]

	# NOTE:   list_in MUST come with an asterisk,
	#         otherwise you'll get an error on runtime
	#
	#         the CDLL class instance can use this
	#         list as a double pointer in C
	c_arr_in = (c_double * upper_boundary)(*list_in)
	c_arr_out = (c_double * upper_boundary)()

	python_c_square = cdll_instance.square_multiplication
	python_c_square.restype = None

	python_c_square(upper_boundary, c_arr_in, c_arr_out)

	# print the last 5 values only
	print(c_arr_out[-5:])
#end function

@measure_time_amount
def bubble_sort(cdll_instance: CDLL, upper_boundary: int = 250000) -> None:
	"""
	Delegate the bubble sort attempt to the C-library to let figure out how fast
	a list with 250,000 random data elements can be sorted.
	
	:param cdll_instance: instance of the CDLL class
	:type cdll_instance: CDLL
	:param upper_boundary: given upper boundary for the bubble sort algorithm
	:type upper_boundary: int
	"""

	# NOTE: Sort a list of 250,000 random numbers with bubble sort in
	#       raw Python is a really dumb idea. Luckily, we're using the
	#       C library instead, which is more efficient.
	from random import shuffle #,randint

	print("bubble sort ;-)")

	# NOTE: You could also use the randint function to create a random number
	#       between [1..250,000] 250,000 times.
	# data: list[int] = [randint(1,upper_boundary) for _ in range(upper_boundary)]

	#                                   start: 1, stop: 250,001
	data: list[int] = [i for i in range(1, upper_boundary+1)]
	shuffle(data)

	c_arr_in = (c_double * upper_boundary)(*data)
	c_arr_out = (c_double * upper_boundary)()

	python_c_bubble_sort = cdll_instance.bubble_sort
	python_c_bubble_sort.restype = None

	python_c_bubble_sort(upper_boundary, c_arr_in, c_arr_out)

	# print the first 10 elements...
	print(c_arr_out[:10])
#end function

def main(used_library: str) -> None:
	from sys import argv

	script_location: str = dirname(abspath(argv[0]))
	library_path: str = join(script_location, used_library)

	try:
		# load the library
		library_instance = CDLL(library_path)

		###
		# direct access
		###

		# ---
		# load void function from C library
		# ---

		# attempting to call the certain function
		# => might not be found on your IDE
		#    if so, then type your function to call by hand
		lib_hello_function = library_instance.say_hello_from_C

		# define the result type of your function
		# => for void it's None
		lib_hello_function.restype = None

		# call the C function
		lib_hello_function()
		# ---

		###
		# function access
		###

		# NOTE: Depending on your used system it may happen, that the application
		#       may terminate earlier. Make sure to have enough RAM.
		#       This is the most caused error.
		#
		#       Also depending on your current system, the application(s), which
		#       is/are running at this monent, free RAM left, ... the time amount differs.

		print("----------")
		square_multiplication(cdll_instance=library_instance)  # ~14s

		print("----------")
		bubble_sort(cdll_instance=library_instance)            # ~3 minutes
	except Exception as e:
		print(f"general error for library {used_library} detected: {e.args}")
	#end try
#end main

if __name__ == "__main__":
	from platform import system

	detected_system = system()
	library_name = {
		"Windows" : "lib.dll",
		"Linux" : "lib.so",
		"Darwin" : "lib.dylib"
	}.get(detected_system)

	if not library_name:
		raise Exception(f"unsupported OS detected: {detected_system}")
	#end if

	# the certain library must exist
	if not isfile(library_name):
		if detected_system == "Windows":
			command: str = "makefile.bat build"
		else:
			command: str = "make"
		#end if

		raise RuntimeError(f"\n Missing library file \"{library_name}\".\n Please build that library in the library_creation/ folder with the command '{command}' first.")
	#end if

	main(used_library=library_name)
#end entry point