str_val: str = "This is a simple text."
nbr_val: int = 100
bool_val: bool = False

# ---
# automatically formatting
# by the system => the sequence
# will be processed 1 : 1
# ---
print("{}, {}, {}".format(str_val, nbr_val, bool_val))

# ---
# determine on which position
# which argument is going to
# print on the console
# ---
print("{2}, {0}, {1}".format(str_val, nbr_val, bool_val))

# ---
# using f literal at the beginning
# and using the object inside of
# the brackets
# ---
print(f"{str_val}, {nbr_val}, {bool_val}")

# ---
# replacing a certain expression
# with another one
# => https://docs.python.org/3/tutorial/inputoutput.html#the-string-format-method
# ---
print('This {food} is {adjective}.'.format(food='spam', adjective='absolutely horrible'))

# ---
# have some fun with loops
# ---
for x in range(1, 11):
	print('{0:2d} {1:3d} {2:4d}'.format(x, x*x, x*x*x))
#end for