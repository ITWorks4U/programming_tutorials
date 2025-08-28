# ---
# A dictionary is a dynamic collection of a key and value pair for any type.
#
# It can easily being used to iterate trough the collection, adding new elements,
# removing elements, etc. When a new key is going to add, this key
# will overwrite an existing key. No matter, what this had any value before
# ---

# define a dictionary
a_simple_dictionary = {
	'red' : 0xFF0000,
	'yellow' : 0xFFFF00,
	'green' : 0xFF00,
	'blue' : 0xFF
}

# define an empty dictionary
empty_dictionary_0 = dict()
empty_dictionary_1 = {}

# ---
# accessing
# ---

# print the whole dictionary
print(a_simple_dictionary)

# accessing each value
for v in a_simple_dictionary.values():
	print(f"value: {v} <=> {hex(v)}")
#end for

print("---------------")

# accessing each key only
for k in a_simple_dictionary.keys():
	print(f"key: {k}")
#end for

print("---------------")

# ---
# modifiying
# ---

# add new elements to the dictionary
a_simple_dictionary.update({'white' : 0xFFFFFF, 'black' : 0})

# removing an element somewhere in the dictionary by given key
_ = a_simple_dictionary.pop('yellow')

# removing the last element from the dictionary
_ = a_simple_dictionary.popitem()

print(a_simple_dictionary)
print("---------------")

# ---
# have fun with dictionaries
# ---
print(f"all keys: {a_simple_dictionary.keys()}")
print(f"all values: {a_simple_dictionary.values()}")
print(f"print me all: {a_simple_dictionary.items()}")

print("---------------")

# ---
# converting a list to a dictionary
# ---

# first way to convert a list to a dictionary
# if the list contains an odd number of elements, the
# last element will be ignored here
a_simple_list = [1, 2, 3, "A", "B", "C", False, 7, 5]
iterator = iter(a_simple_list)
a_new_directory = dict(zip(iterator, iterator))
print(f"a simple list: {a_simple_list} <=> a new directory: {a_new_directory}")

# remove all elements
a_new_directory.clear()

# second way to convert a list to a dictionary
# all elements in the list will be added to the
# dictionary
for i in range(0, len(a_simple_list)):
	a_new_directory.update({i : a_simple_list[i]})
# end for

print(f"a simple list: {a_simple_list} <=> a new directory: {a_new_directory}")
a_new_directory.clear()

# again, but more pythonic like
for i,j in enumerate(a_simple_list):
	a_new_directory[i] = j
#end for

print(f"a simple list: {a_simple_list} <=> a new directory: {a_new_directory}")