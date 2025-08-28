# ---
# a list is a dynamic collection, which holds any type
# it can easily being used to iterate trough the collection,
# adding new elements, removing elements, etc.
#
# in contrast to other languages, don't be confused,
# because this [] is usual an array, but in Python
# this is a list
# ---

# create a list with n elements
a_simple_list = [1, 2, 3, "A", "B", "C", True, False, 7, 5, 3]

# let create an empty list (easier to read that)
empty_list_0 = list()

# this can also be used (pythonic way)
empty_list_1 = []

# can be used, but this is also much harder to
# read that in a correct form, thus avoid this one
# list = list()

# ---
# accessing
# ---

# print the whole list
print(a_simple_list)															

# loop trough each element
for element in a_simple_list:
	print(element)
# end for

# get element on position n (n = 0, 1, 2, ..., k-1)
print(a_simple_list[3])

# print an interval between [n,k], where n is the position
# and k is the current element to use
print(a_simple_list[4:9])

# start backwards from the list and get the last
# element instead
print(a_simple_list[-1])

# ---
# modifiying
# ---

# appending an element to the end of the list
a_simple_list.append(True)

# insert a new element on position n
a_simple_list.insert(5, None)

# add a sub list
a_simple_list.extend([951,"ABC"])

# same as above
a_simple_list += [True, False, None]

# remove an element, which must be in the list
a_simple_list.remove(None)

# remove the last element, which can be used for other stuff
print(a_simple_list.pop())

# remove element on position n, which can be used for other stuff
print(a_simple_list.pop(6))

# does not work for a list
#aSimpleList -= [7,5,3]

print(a_simple_list)