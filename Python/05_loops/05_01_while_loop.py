# ---
# simple examples for a 'while' loop
# ---

ctr_for_loop: int = 0

print("---	incrementation	---")
while ctr_for_loop < 10:
	print(ctr_for_loop)

	# make sure to modify ctr_for_loop, otherwise
	# this loop never ends
	ctr_for_loop += 1
#end while

print("---	decrementation	---")
while ctr_for_loop > 0:
	ctr_for_loop -= 1
	print(ctr_for_loop)
#end while

# you also can add brackets for your condition(s)
while (ctr_for_loop != 0):
	pass
#end while

# in Python a do-while-loop doesn't exist
print("--- skip steps ---")

while ctr_for_loop != 10:
	ctr_for_loop += 1

	if ctr_for_loop in [0,5,8]:
		# skip the values 0, 5 and 8
		continue
	#end if

	print(ctr_for_loop)
#end for

print ("--- leave loop earlier ---")
while ctr_for_loop != 0:
	ctr_for_loop -= 1

	if ctr_for_loop == 3:
		# leave the loop
		# every other value left is also skipped
		break
	#end if

	print(ctr_for_loop)
#end for