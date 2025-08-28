# ---
# a tuple is a static collection, which holds any type.
#
# in contrast to a list or set, no elements can be added
# or removed after creation
# ---

# define a tuple with fixed elements
a_simple_tuple = (7,5,3, True, False, "Hello World!")

# define an empty tuple
empty_tuple_0 = tuple()

# same as above, but harder to interpret it correctly
# => pythonic style
empty_tuple_1 = ()

# ---
# accessing
# ---

# print the whole tuple
print(a_simple_tuple)

# loop trough each element
for element in a_simple_tuple:
	print(element)
# end for

# count how often an element exists in our tuple
print(a_simple_tuple.count(True))

# get the position of an element
print(a_simple_tuple.index(True))

# ---
# modifiying
# ---
# A tuple is a fixed structure.
# It won't allows us to modify the elements.

# ---
# have some fun with tuples
# ---

# define a new tuple
t = (1,2,3)

# refering a tuple of variables to tuple t
(a, b, c) = t

# let's compare (a,b,c) with (1,2,3)
if (a,b,c) == (1,2,3):
	print("Hooray, both tuples contains the identical data!")
else:
	print("Wait a second...?!")
# end if