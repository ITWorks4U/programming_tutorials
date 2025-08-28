# ---
# using getch module
#
# may not be able to install or on Windows, because getch
# requires termios.h, which is unavailable on Windows
# ---

import getch

def hide_user_input(message: str) -> str:
	print(message, end="")

	hidden: list = []

	while True:
		symbol = getch.getch()

		if symbol == '\n' or symbol == '\r':
			break
		#end if

		# replace with an asterisk
		print('*', end='', flush=True)
		hidden.append(symbol)
	#end while

	return "".join(hidden)
#end function

user_name = input("enter username: ")
user_password = hide_user_input("enter password: ")

# any authentification here...
print(f"{user_name}, {user_password}")