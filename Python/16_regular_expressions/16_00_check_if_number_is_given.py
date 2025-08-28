# ---
# Regular expressions are a well tool
# to check a certain expression.
#
# how to check, if an expression is a number:
#
# typically, you're using int(expression) to try to convert it into a number,
# however, it fails with an exception, if the expression doesn't contain
# numerical characters only.
# => This could be handled with an exception handling. (see: chapter 18)
#
# or you could use a regular expression, which checks, if a certain expression
# passes trough a defined filter or not
# => In that case no exception handling is necessary.
#
# A regular expression can only be used on words!
# Since a word with a length n characters (n = 0, 1, 2, ..., k-1)
# is given, a regular expression can be used to define a filter
# to check, if this certain word passes the filter or not.
#
# When you're trying to use other objects, like numbers, collections,
# or else, the regular expression check usually fails and must be
# covered with an exception handling.
#
# For more details, take a look to this video:
# https://www.youtube.com/watch?v=vvFPWHHto00
# (German commentary, English text)
# ---


# import regular expression module
from re import match

# define a filter, where each expression
# must satisfy this filter condition
#
# the expression with any length (0,1,2,...)
# must have characters in a range of 0 to 9
#
# NOTE:
# a regular expression filter often starts with "r" as
# prefix; this allows you to use the regex filter a bit easier
# instead of using specific escape characters
filter = r"^(-|\+)?[0-9]+$"

expressions = ("123", "Is mayonnaise also an instrument?", 2390472397492984927429648236, "0", "-10", "+73", [], True, "Hello regular expression in python 3!")

for e in expressions:
	try:
		if match(filter, e):
			print(f"{e}: is a number")
		else:
			print(f"{e} is a not number")
		#end if
	except TypeError as te:
		print(f"error ({e}) detected: {te.args[0]}")
#end for