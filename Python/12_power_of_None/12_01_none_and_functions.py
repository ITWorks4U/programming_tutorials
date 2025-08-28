# ---
# define None for functions
# ---
def nothing_to_see_here() -> None:
	# "-> None" is not required here
	pass
# end function

for i in range(10):
	print(f"{i}: {nothing_to_see_here()}")
#end for
print("-------------")

# ---
# returning any type depending on value
# ---
def receive_any_value_0(v: int):
	if v == 1 or v == 2 or v == 3:
		return float(v)
	elif v == []:
		return tuple(v)
	elif v == {} or v == ():
		return None
	#end if

	return False
# end function

def receive_any_value_1(v: int):
	# looks similar, but this returns you different
	# results
	match v:
		case (1|2|3):
			return float(v)
		case []:
			return tuple(v)
		case ({},()):
			return None
		case _:
			return False
		#end cases
	#end match
# end function

collection = (1,2,3,[],{},(),True,"ABC")

for c in collection:
	print("======")
	ret = receive_any_value_0(c)
	print(f"[{c}, {type(c)}] => [{ret}, {type(ret)}]")
	print("------")
	ret = receive_any_value_1(c)
	print(f"[{c}, {type(c)}] => [{ret}, {type(ret)}]")
#end for