# ---
# checks, if the expression is in hexadecimal form:
#
# ^(0x|0X)?([A-Fa-f0-9]+)(H|h)?$
#  - may start with 0x or 0X
#  - contains A-F, a-f or 0-9 at least once
#  - may end with h or H
#
# will pass:
#  - 0x1h
#  - 0xFdaaH
#  - 0xface
#  - Affe
# ---

from re import match

filter_hex_expression = r"^(0x|0X)?([A-Fa-f0-9]+)(H|h)?$"
buffer = input("enter a hexadecimal expression of any length: ")

if match(filter_hex_expression, buffer):
	print(f"Your input is hexadecimal. Trying to convert it to decimal, octal and binary... Just for fun. :)")

	try:
		# In python this preinitialization isn't necessary,
		# however, it may be a good guideline for your
		# processing.
		new_hex: str = ""

		#	disposing h or H at the end, if existing, because it will
		#	cause an error on converting
		if buffer.endswith("H") or buffer.endswith("h"):
			new_hex = buffer[:-1]
		else:
			new_hex = buffer
		#end if
		
		print(f"decimal form: {int(new_hex, 16)}, octal form: {oct(int(new_hex, 16))}, binary form: {bin(int(new_hex, 16))}")
	except Exception as e:
		print(f"error: {e.args}")
	#end try
else:
	print(f"Sorry, but {buffer} is not a hexadecimal expression.")
#end if