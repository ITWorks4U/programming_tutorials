# ---
# using a "switch-case" for
# Python version 3.10+
# ---

def switch_case(number: int) -> str:
	match number:
		case 0:
			return "zero"
		case 1:
			return "one"
		case 2:
			return "two"
		case 3:
			return "three"
		case 4:
			return "four"
		#... and so on

		# default block
		case _:
			return 'unknown number'
		#end cases
	#end match
# end function

for i in range(10):
	print(f"Give me the the number {i}: {switch_case(i)}")
#end for