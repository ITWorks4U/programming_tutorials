expression = "global expression"

def surprise() -> None:
	# >>this<< expression can be read from everywhere
	print(f"in function call: {expression}")
#end function

print(f"before function call: {expression}")
surprise()
print(f"after function call: {expression}")