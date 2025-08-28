from random import randint

MAX_NUMBERS = 50000

def bubble_sort(custom_nbr: int = 0):
	"""
	Sort n elements by using bubble sort. Bubble sort has a time
	complexity of O(n²) and this should **NOT** be used for a high
	number.

	custom_nbr:
		-	custom number of elements for bubble sort
			if 0 or lower, then the max number of 50,000 elements are in use
	"""

	data: list[int]

	if custom_nbr <= 0:
		data = [randint(1,MAX_NUMBERS) for _ in range(MAX_NUMBERS)]
	else:
		data = [randint(1,custom_nbr) for _ in range(custom_nbr)]
	#end if

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