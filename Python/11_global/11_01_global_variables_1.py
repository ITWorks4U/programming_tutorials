expression = "global expression"

def surprise() -> None:
	# this causes an error, because >>this expression<<
	# is unequal to the >>external expression<<
	#
	# >>this expression<< has not been defined yet
	# print(f"in function call: {expression}")

	# >>this expression<< only exists in this function
	expression = 100
	print(f"in function call: {expression}")
#end function

print(f"before function call: {expression}")
surprise()
print(f"after function call: {expression}")