# usually, you don't need to define a datatype elsewhere,
# because the python interpreter does this job, however,
# it may also be a good advise to know, which type is expected

# typical way:
data_0 = "Hello World!"

# you can also use:
data_1: str = "Hello World!"

# the python interpreter usually don't care about this given
# datatype, unless you're using specific modules, which watchs
# for the correct or expected type
#
# these are typical used data types:
# int                := integer
# float              := floating point
# str                := string
# bool               := boolean expression
# list[type]         := list with an expected type, can also be defined as a "nacked" list
# tuple[type]        := tuple
# set[type]          := set
# dict[type, type]   := dictionary with key and value
#
# class              := more in use, if you declare a specific class, where "class" is not in use here
#
# example:
# class Test:
#    # any content here
#
# Test               := marks to use an object for that class "Test"
#
# finally, if you're using a type, which does not match, no error appears
# - unless the python interpreter runs into a real error on runtime

# data_2 shall be interpreted as an integer, but a string is given
# since this string is not mentioned to work with integer operations,
# everything works fine, but it causes confusions
data_2: int = "Hello World"