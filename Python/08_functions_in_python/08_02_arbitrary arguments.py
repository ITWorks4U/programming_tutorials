# In Python it's also possible to add arbitrary arguments.
# It's usage might be a bit uncommon, but very often in use.
#
# Don't be confused with * and you're also knows C/C++.
# These aren't pointers in python.

# ---
# calling a function with
# any amount of arguments
# ---

'''
	Arbitrary arguments allows us to call a function
	with a different number of arguments.
	These are often shortened to *args in Python documentations.
'''
def arbitrary_arguments(*args):
	print("number of arguments: ", len(args))

	for a in args:
		print(f"argument {a} is type of {type(a)}", )
	# end for
# end function

arbitrary_arguments(1,2,3,'True',{},(),[],'Hi there!')
arbitrary_arguments(123)
arbitrary_arguments()

print("--------------")

# ---
# calling a function with
# a key-value-pair of
# arguments
# ---

'''
	Arbitrary keyword arguments are in use to
	handle with a dictionary. These are often
	shorened to *kwargs in Python documentations.
'''
def arbitrary_keyword_arguments(**kwargs):
	for key in kwargs.keys():
		print(f'key: {key}, value: {kwargs[key]}')
	# end for
# end function

arbitrary_keyword_arguments(user = "ITWorks4U", location = "YouTube / github", source = "https://github.com/ITWorks4U")

print("-------------")
# can also be used, but this is not the pythonic way, and also causes to a pitfall,
# because you're adding to kwargs's key a value named "kwargs" with the content
arbitrary_keyword_arguments(kwargs={"user": "ITWorks4U", "location" : "YouTube / github", "source" : "https://github.com/ITWorks4U"})
print("-------------")

# ---
# converting a list into a dictionary and calling
# the function to see the result
# ---

a_simple_list = [1, 2, 3, "A", "B", "C", False, 7, 5]
a_new_dictionary = dict()

for i,j in enumerate(a_simple_list):
	a_new_dictionary[str(i)] = j
#end for

#	important: a_new_dictionary must start with two stars
arbitrary_keyword_arguments(**a_new_dictionary)