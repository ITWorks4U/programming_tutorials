###
# An external python script, which checks, if a given
# path from the current application is valid or not.
#
# If the path is valid, then the application terminates
# with 0, otherwise 1.
###

from sys import exit, argv
from re import match
from os.path import exists

def on_valid_path(current_path: str) -> bool:
	"""
	Check, if the path is valid. The path, by default a string (argv[1]),
	must have at least one character. If this was not satisfied,
	False returns.

	Based on the first condition was successful, the path must pass
	trough the regular expression filter. If true, then the path
	must finally exist, otherwise False returns.

	current_path:
	- the given path to check

	returns:
	- True, if the path satisfies all conditions including the path exists
	- False, otherwise
	"""

	if len(current_path) == 0:
		return False
	#end if

	filter_to_use: str = r"^[a-zA-Z0-9_\-/\\:.]+$"

	if match(filter_to_use, current_path):
		return exists(current_path)
	#end if

	return False
#end function

if __name__ == "__main__":
	# assuming, that argv contains at least one additional
	# argument

	if len(argv) < 2:
		exit(2)
	#end if

	used_path: str = argv[1]
	exit(0) if on_valid_path(used_path) else exit(1)
#end entry point