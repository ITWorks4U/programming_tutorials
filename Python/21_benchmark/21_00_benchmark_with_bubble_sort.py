# ---
# easy to implement, not recommended to use for a huge amount
# of numbers, because the bubble sort has a time complexitiy of O(n²),
# but in that case this is "good" enough
# ---

from random import randint
from datetime import timedelta
from timeit import timeit

_MAX_NUMBERS = 50000

# contains 50,000 random numbers between [1;50,000]
data: list[int] = [randint(1,_MAX_NUMBERS) for _ in range(_MAX_NUMBERS)]

def bubble_sort():
	nbr_of_elements: int = len(data)

	# this bubble sort algorithm can be left earlier,
	# if the list elements are already sorted
	for i in range(nbr_of_elements):
		swapped: bool = False

		for j in range((nbr_of_elements - 1) - i):
			if data[j] > data[j+1]:
				data[j], data[j+1] = data[j+1], data[j]
				swapped = True
			#end if

		if not swapped:
			# list is already sorted
			break
		#end if
	#end for
#end function

print(f"start to sort {len(data)} elements with bubble sort: ", end="")
print(f"time amount: {timedelta(seconds=timeit(stmt=bubble_sort, number=1))}")