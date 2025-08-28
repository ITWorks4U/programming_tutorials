# ---
# ususally, you're allowed to use space(s) or tab(s) for
# a block, which can be used for a condition check, a loop,
# a function, ...
#
# this block must not contain both intendentions, but you can
# create two different blocks, which contains each single
# intendention type
#
# NOTE:
# to be able to see the differences, activate the view for space(s)
# and tab(s)

a = 3.141
b = 2.00

# using intendention with space(s)
if a == b:
    print("a == b, right?")
else:
    print("No, a is not equal to b!")
#end if

# using intendention with tab(s)
if a != b:
	print("a is still unequal to b...")
else:
	print("Wait, since when is a == b?")
#end if