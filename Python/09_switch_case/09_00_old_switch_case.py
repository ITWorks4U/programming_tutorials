# ---
# using an old "switch-case" for
# Python version up to 3.9
# ---

def switch_case(number: int) -> str:
	case = {
		0:	"zero",
		1:	"one",
		2:	"two",
		3:	"tree",
		4:	"four"
	}

	return case.get(number, "unknown number")
# end function

for i in range(10):
	print(f"Give me the the number {i}: {switch_case(i)}")
#end for