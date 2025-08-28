expression = "global expression"

def surprise() -> None:
	# notification for the python interpreter, that
	# this expression already exists outside
	# and this shall be able to modify in this
	# function
	#
	# after modification, >>expression<< keeps the
	# new value
	#
	# after global <object> there"s no other instruction here
	global expression

	print(f"in function call #1: {expression}")
	expression = 100
	print(f"in function call #2: {expression}")
#end function

print(f"before function call: {expression}")
surprise()
print(f"after function call: {expression}")