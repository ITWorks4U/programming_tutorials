# ---
# Who says, that a function has to
# return a single value only?
# ---
def swag():
	# by returning more than one element, all elements here
	# will automatically converted into a tuple
	return list(), dict(), tuple(), "123", 42, "Deal with it!"
#end function

s = swag()
print(f"full content of s: {s} <=> type: {type(s)}")

print("----------")

for s in swag():
	print(s)
#end for

print("----------")

# ---
# meme starts in 3... 2... 1...
# ---
def meme(a, b, c, d, e, f) -> None:
	print(f'This function goes {a}{b}{c}{d}{e}{f}.')
#end function

b = 'b'
r = 'r'
meme(b,r,r,r,r,r)