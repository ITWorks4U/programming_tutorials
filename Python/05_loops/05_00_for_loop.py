# ---
# simple examples for a 'for' loop
# ---

ctr_for_loop: int = 10

print("--- single steps ---")

# start from 0 to ctr_for_loop-1 --> [0,1,2,3,...,9]
for i in range(ctr_for_loop):
	print(i)
# end for

print("--- starting from ctr_for_loop certain position ---")

# start from 5 to ctr_for_loop-1 --> [5,6,7,8,9]
for i in range(5, ctr_for_loop):
	print(i)
#end for

print("--- modifying step range ---")

# start from 0 to ctr_for_loop-1, but take 2 steps instead --> [0,2,4,6,8]
for i in range(0, ctr_for_loop, 2):
	print(i)
#end for

print("--- ignoring counter value ---")

# using _ if you don't need an element
for _ in range(ctr_for_loop):
	print("...")
# end for

print("--- compressed in one line ---")

# press everything into one line
# => pythonic way:
#   easy to use a single line
#   a bit harder to understand, what's going on here
[print(i) for i in range(ctr_for_loop)]

print("--- using ctr_for_loop collection ('for each') ---")

# ...like ctr_for_loop tuple
for i in (3,6,9,12,15,18):
	print(i)
# end for

print("--- enumerating ---")

# using enumerate to handle with two variables
# to reveal on which position is which element
for pos,val in enumerate((3,6,9,12,15,18)):
	print(pos, ":", val)
# end for

print("--- skip steps ---")

# using continue to skip the current step
for i in range(ctr_for_loop):
	if i in [0,5,8]:
		# skip the values 0, 5 and 8
		continue
	#end if

	print(i)
#end for

print ("--- leave loop earlier ---")
for i in range(ctr_for_loop):
	if i == 7:
		# leave the loop
		# every other value left is also skipped
		break
	#end if

	print(i)
#end for