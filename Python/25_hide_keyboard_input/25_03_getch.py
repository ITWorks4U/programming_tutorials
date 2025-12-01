# ---
# using getch module
#
# may not be able to install or on Windows, because getch
# requires termios.h, which is unavailable on Windows
# ---

from platform import system
from sys import stderr

def hide_user_input() -> str:
	# NOTE: It may happen, that this module is unable to install
	#       on your system.
	from getch import getch

	print("enter password: ", end="")
	hidden: list = []

	while True:
		symbol = getch()

		if symbol == "\n" or symbol == "\r":
			break
		#end if

		# replace with an asterisk
		print("*", end="", flush=True)
		hidden.append(symbol)
	#end while

	return "".join(hidden)
#end function

if __name__ == "__main__":
	if system() == "Windows":
		print("This script can't be used on a Windows machine.", file=stderr)
	else:
		user_name = input("enter username: ")
		user_password = hide_user_input()

		# any authentification here...
		print(f"{user_name}, {user_password}")
	#end if
#end entry point