# ---
# load and run the cythonized code to speed up
# your application
# ---

import numpy as np
from datetime import timedelta
from time import perf_counter

from bubble_sort import bubble_sort

def main() -> None:
	upper_boundary = 250000

	# create a random array with 250,000 elements
	random_collection = np.random.rand(250000)

	# call the Cython-accelerated bubble sort
	start = perf_counter()
	bubble_sort(random_collection)
	end = perf_counter()

	print(f"total time amount to sort {upper_boundary} with bubble sort: {timedelta(seconds=(end-start))}")

	# optional: check if sorted
	print(np.all(np.diff(random_collection) >= 0))
#end main

if __name__ == "__main__":
	main()
#end entry point