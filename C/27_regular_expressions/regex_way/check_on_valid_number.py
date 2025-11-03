# ---
# Help script for regular expressions.
# An alternative way, if no POSIX regex or external
# library, like PCRE2 was found on the system.
# ---

from sys import exit, argv
from re import match

def on_valid_input(current_filter: str, current_input: str) -> bool:
	"""
	Check, if the input is valid. The given filter is
	the regular expression filter from the C application, whereas
	the current input is the input to compare with the regular expression filter.

	It returns True, if a match object exists, otherwise False.
	Furthermore, current_filter, as well as, current_input must be a string
	and also those must contain at least one character to work with.

	current_filter:

	-	the current regex filter

	current_input:

	-	the current input to compare

	returns:

	-	True on match, False otherwise
	"""
	if not (isinstance(current_filter, str) and isinstance(current_input, str)):
		return False
	#end if

	if len(current_filter) == 0 or len(current_input) == 0:
		return False
	#end if

	return match(pattern=current_filter, string=current_input)
#end function

if __name__ == "__main__":
	# assuming, that 3 arguments are given
	# #0: the script name itself (default)
	# #1: regex filter
	# #2: string to compare
	if len(argv) != 3:
		exit(1)
	#end if

	result: bool = on_valid_input(current_filter=argv[1], current_input=argv[2])
	exit(0) if result else exit(1)
#end entry point