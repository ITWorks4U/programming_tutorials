# using formatters for output;
# similar to C programming
#
# this can be used to force to use a specific expression of that type
#
# in contrast to C an error on
# runtime appears, if a wrong formatter
# is in use
#
# typical formatters:
# -	%c	<=>	single character
# -	%s	<=>	any string (even boolean expression)
# -	%d	<=>	decimal expression (also valid for boolean expressions)
# ...
#
# for more informations, take a look there:
# -	https://docs.python.org/3/tutorial/inputoutput.html
# -	https://www.geeksforgeeks.org/string-formatting-in-python-using/

str_val: str = "This is a simple text."
nbr_val: int = 100
bool_val: bool = False

# ---
# using C-style formatters
# ---

# format argument as a word
print("%s" % str_val)
print("%d" % nbr_val)

# for a boolean expression
# you can use %d as well as %s
print("%d" % bool_val) # => will be converted into 0
print("%s" % bool_val)

# in C this 'works', but not here
#  => TypeError: %d format: a number is required, not str
# print("%d" % str_val)

# ---
# using linear C-style formatters
# important: the sequence must be identical with
# the formatters and the length of the arguments
# must be the number of used formatters
# ---
print("%s %d %s" % (str_val, nbr_val, bool_val))