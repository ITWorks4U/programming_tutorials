# ---
# the code of bubble_sort for Cython
# ---

def bubble_sort(double[:] arr):
	cdef int n = arr.shape[0]
	cdef int i, j
	cdef double tmp
	for i in range(n):
		for j in range(0, n - i - 1):
			if arr[j] > arr[j + 1]:
				tmp = arr[j]
				arr[j] = arr[j + 1]
				arr[j + 1] = tmp
			#end if
		#end for
	#end for
#end function
