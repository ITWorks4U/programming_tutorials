# Python also comes with a yield keyword.
#
# It's similar to a return statement, however,
# it allows us to return a value or a set of
# values, while the function is not finished yet.
#
# yield returns the current value and this can
# be stored into a collection, where this collection
# is not a list, tuple, set or dictionary
#
# it's much more a >>Generator<<
#
# Their usage might be a bit strange...

def simple_yield_example():
	"""
	counts the numbers from 0 to
	100 and gives that information
	outside by using yield without
	leaving the loop or function
	"""
	start = 0

	while start <= 100:

		# allows us to return the current value while this
		# loop and also this function won't be leaved
		yield start

		start += 1
	#end while
#end function

# using yield in combination with a loop you can iterate with
# your function
#
# it's a bit uncommon...
print("[ ", end="")
for i in simple_yield_example():
	print(f"{i} ", end="")
#end for
print("]")

print("----------------")

# ...or use the longer way instead:
collection = simple_yield_example()

print("[ ", end="")
for c in collection:
	print(f"{c} ", end="")
#end for
print("]")

print("----------------")

# unlike your collection contents,
# it shows you the memory address,
# where this Generator is stored on runtime
print(f"Pffffaaaaah! Have you thought to read the generator's content here? Use this memory address instead: {collection}")