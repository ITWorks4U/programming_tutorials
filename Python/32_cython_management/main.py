# ---
# load and run the cythonized code to speed up
# your application
# ---
try:
	from bubble_sort import bubble_sort
except ModuleNotFoundError:
	from platform import system

	default_command: str = "python3"

	if system() == "Windows":
		default_command: str = "python.exe"
	#end if

	raise RuntimeError(f"run '{default_command} setup.py build_ext --inplace first'")
#end try

from datetime import timedelta
from time import perf_counter

from numpy import ndarray
from numpy.random import rand

def main() -> None:
	# bubble sort with 250,000 random numbers
	upper_boundary: int = 250000

	# create a random array with 250,000 elements
	random_collection: ndarray = rand(upper_boundary)

	# call the Cython-accelerated bubble sort
	start: float = perf_counter()
	bubble_sort(random_collection)
	end: float = perf_counter()

	print(f"total time amount to sort {upper_boundary} with bubble sort: {timedelta(seconds=(end-start))}")
#end main

if __name__ == "__main__":
	main()
#end entry point