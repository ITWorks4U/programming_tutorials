# let's have two values
a = 10
b = 20

# multiple condition checks allows you to check "each possible state", whereas
# only one state can be True
#
# if a second condition check also results to True, then this will be ignored

if a == b:
	# nope...
	print("a is equal to b, right?")
elif a != b:
	# indeed
	print("a is unequal to b, I guess...")
elif a > b:
	# nope...
	print("a should be greater than b, right?")
elif a < b:
	# since a != b is True, this will be ignored
	print("a should be smaller than b...?")
else:
	# only in use, of all of the condition checks above won't pass
	print("I don't know what to do here...")
#end if

# ---
# combine more conditions into one condition expression
# ---
if a > 5 and b > 5:
	# only, if a > 5 and also b > 5
	print("This statement is true.")
else:
	print("Wait a minute...?")
#end if

if a > 10 or b > 10:
	# if at least one of the sub conditions result to True,
	# then this will be True
	print("This statement is true.")
else:
	print("Wait a minute...?")
#end if