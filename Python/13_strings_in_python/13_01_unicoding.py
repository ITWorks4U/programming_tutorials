# Usually, we"ve used a small range of characters,
# however, it"s also necessary to know how to
# handle with characters, which are typically
# hardly used in the English expression, like:
# Ä, µ, @, €, ŧ, ¶, ...
#
# encodings are:
# ASCII# (American Standard Code for Information Interchange)
# - contains only 128 characters, like: A-Z, a-z, 0-9, some additional characters, like (,),{,},..., control characters (\t, \0, \b, ...)
#
# UTF-x (Unicode Transformation Format x bytes)
# - contains more characters, which can be handled for other languages
# - x := number of bits to use (7,8,16,32)
#
# latin1, ....
#
# for more informations take a look here:
# https://docs.python.org/3/howto/unicode.html
#
# or there:
# https://lynn-kwong.medium.com/understand-the-encoding-decoding-of-python-strings-unicode-utf-8-f6f97a909ee0
#
# or this:
# https://towardsdatascience.com/a-guide-to-unicode-utf-8-and-strings-in-python-757a232db95c
#
# or that:
# https://stackoverflow.com/questions/1728376/get-a-list-of-all-the-encodings-python-can-encode-to

# ---
# typically, the print function uses utf-8 by default
#
# These expressions are in hexadecimal form with a length of 8 bits!
# ---

# print a bee
print("bee: \U0001f41d")

# ...or a ladybug
print("ladybug: \U0001f41e")

# ...or a fish
print("fish: \U0001f41f")

# ...or a traffic light
print("traffic light: \U0001F6A6")

# ...make a hand wave instead (:
print("wave hand: \U0001F590")

# ...using a specific expression (starting with \N) and try to figure out,
# if these might work
print("mahjong red dragon: \N{MAHJONG TILE RED DRAGON}")
print("mahjong green dragon: \N{MAHJONG TILE GREEN DRAGON}")

# these are identical:
print("delta: \N{GREEK CAPITAL LETTER DELTA}")
print("delta: \U00000394")

# ...also these
print("latin capital... Ê")
print("latin capital... \N{LATIN CAPITAL LETTER e}\N{COMBINING CIRCUMFLEX ACCENT}")

# input any character and try to figure out,
# if this can be used in a certain encoding

encodings = ("ascii", "latin1", "utf-7", "utf-8", "utf-16", "utf-32")

anyChar = input("Enter any character: ")
print(f"your input: \"{anyChar}\"... ")

if len(anyChar) == 1:
	for e in encodings:
		try:
			print(f"with used encoding \"{e}\": {anyChar.encode(e)}")
		except Exception as ex:
			print(f"with used encoding \"{e}\": {ex.args}")
		#end try
	#end for
else:
	print(f"Your input (\"{anyChar}\") didn't contained exactly one character.")
#end if