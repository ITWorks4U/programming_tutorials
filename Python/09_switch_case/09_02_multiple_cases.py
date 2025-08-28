# ---
# using multiple cases
# ---
def check_if_odd_or_even_correct(number: int) -> str:
	match number:
		# usually, no space is required and those
		# can also be surrounded with brackets
		case 0 | 2 | 4 | 6 | 8:
			return "even"
		case (1 | 3 | 5 | 7 | 9):
			return "odd"
		case _:
			return "???"
		#end cases
	#end match
#end function

# wrong way to use multiple cases
def check_if_odd_or_even_wrong(number: int) -> str:
	match number:
		# instead of using multiple cases, number
		# is going to compare with a tuple of
		# (0,2,4,6,8) or (1,3,5,7,9) and this
		# will fail
		case (0,2,4,6,8):
			return "even"
		case (1,3,5,7,9):
			return "odd"
		case _:
			return "???"
		#end cases
	#end match
#end function

for i in range(10):
	print(f"number {i} is {check_if_odd_or_even_correct(i)}")
	print(f"number {i} is {check_if_odd_or_even_wrong(i)}")
	print("--------------------")
#end for

