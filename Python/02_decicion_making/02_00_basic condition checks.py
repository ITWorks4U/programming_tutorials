# let's have two values
a = 10
b = 20

# the condition checks hardly required brackets ()

# checks, if a is equal to b => False
if a == b:
	print("a is equal to b")
# end if                               # optional: helps you to have an overview

# checks, if a is unequal to b => True
if a != b:
	print("a is not equal to b")
# end if

# skip the current block for a later purpose
if a != b:
	pass
# end if

# an else block defines the default way, if the
# condition(s) above is/are False
if a == b:
	print("both values are equal")
else:
	print("both values are not equal")
# end if