# Playing lottery.
#
# 6 unique numbers of 49 available numbers can be chosen
# for a lottery game.
#
# Finally, a super number in the range of 0-9 can
# also be used.
#
# Have fun. (:

import random as rnd

def casual_way():
	init_collection = list()

	#	--------------
	#	generating lottery numbers 1-49
	#	--------------
	for i in range(49):
		init_collection.append(i+1)
	#end for

	#	--------------
	#	taking 6 unique numbers
	#	--------------
	lottery_collection = list()

	while len(lottery_collection) != 6:
		current = rnd.choice(init_collection)

		if current not in lottery_collection:
			lottery_collection.append(current)

			#	the alternate way is to remove
			#	the number from initCollection,
			#	thus it's no need to check, if
			#	the current number is not already
			#	in lottery list
		#end if
	#end while

	#	--------------
	#	also adding a super number at the end
	#	--------------
	super_number = list()
	for i in range(10):
		super_number.append(i)
	#end for

	#	--------------
	#	output
	#	--------------
	print(f'current lottery numbers: {lottery_collection} with super number: {rnd.choice(super_number)}')
#end function

def pythonic_way():
	init_collection = [(i+1) for i in range(49)]
	lottery_collection = set()

	while len(lottery_collection) != 6:
		lottery_collection.add(rnd.choice(init_collection))
	#end while

	super_number = [(i + 1) for i in range(10)]
	print(f'current lottery numbers: {lottery_collection} with super number: {rnd.choice(super_number)}')
#end function

print("-------------------")
casual_way()
print("-------------------")
pythonic_way()
print("-------------------")