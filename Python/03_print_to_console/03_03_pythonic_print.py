str_val: str = "This is a simple text."
nbr_val: int = 100
bool_val: bool = False

# ---
# use the pythonic way
# start with f => every object in the brackets {} reveal their value
# ---
print(f"{str_val}, {nbr_val}, {bool_val}")

# ---
# have more fun with print
# ---
# using additional arguments for print function
#
# full offer of print() function:
# print(*values: object, sep: str | None = " ", end: str | None = "\n", file: SupportsWrite[str] | None = None, flush: Literal[False] = False) -> None
#
# where:
# - *values   := any amount of arguments as a list
# - sep       := string inserted between values, space by default
# - end       := text to print after print(), new line by default
# - file      := a file-like object (stream); defaults to the current sys.stdout
# - flush     := whether to forcibly flush the stream
#
# this function returns nothing (None)

# ---
# overriding end => no new line for the next output
# ---
print(str_val, end=' Bazinga!')
print("Is that on the new line?")

# ---
# modifying separators
# ---
print("C", "C++", "Python", "C#", "Java", "...")
print("C", "C++", "Python", "C#", "Java", "...", sep="/")
print("C", "C++", "Python", "C#", "Java", "...", sep=" ~~~ ")

# ---
# print the output into a file instead
# => more in a later section
# ---
# with open('outsourced.txt', encoding="utf-8", mode='w') as f:
# 	print("C", "C++", "Python", "C#", "Java", "...", file=f)
# #end with

# ---
# flushing the output
# ---
from time import sleep

for i in range(10):
	# if flush=True, then the previous output
	# will be replaced with the new output
	#
	# \b tells the system to jump one position back
	print(f'{i}', end='\b', flush=True)

	# sleep every 250 milliseconds
	sleep(0.25)
#end for

print("---------")

# ---
# fun fact:
# What will happen, if you're using a higher number?
# ---
for i in range(40):
	print(f'{i}', end='\b', flush=True)
	sleep(0.25)
#end for
