import random as r

# contains alphanumeric characters in capital and normal form, followed
# by numbers and some bonus characters
character_collection = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuwvxyz0123456789!"§$%&/()=?_:;-.,+*#`´µ<>|@~'

def create_random_password(length: int) -> str:
	# since a string is immutable, we're unable to modify
	# a temporary string directly; we're using a list
	# as a buffer instead
	holder: list = []

	for _ in range(length):
		holder.append(r.choice(character_collection))
	#end for

	# convert the list into a string
	return "".join(holder)
#end function

for i in range(1, 101):
	print(f"password with {i} characters: {create_random_password(i)}")
#end for