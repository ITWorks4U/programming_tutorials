# ---
# Check, if a word is a palindrome.
# A word is a palindrome only, if it can be
# read from left to right and also from
# right to left.
# ---

def on_palindrome(input_buffer: str) -> bool:
	# ---
	# if the buffer has 0 or 1 character(s),
	# then it's already a palindrome
	# ---
	if len(input_buffer) > 1:
		# ---
		# limit to work with
		# ---
		limit: int = 0

		if len(input_buffer) % 2 == 0:
			# the word has an even number of characters
			limit = len(input_buffer) // 2
		else:
			# otherwise the given word has an odd number of characters
			limit = (len(input_buffer) - 1) // 2
		#end if

		# ---
		# check for palindrome
		# ---
		posLeft = 0
		posRight = len(input_buffer) - 1

		# ---
		# continuing checking, until a palindrome is not given
		# or the limit has been reached from right
		# ---
		while True:
			lChar: str = input_buffer[posLeft]
			rChar: str = input_buffer[posRight]

			# check, if these characters are unequal
			if lChar != rChar:
				return False
			#end if

			if posRight == limit:
				# leave loop
				break
			else:
				posLeft += 1
				posRight -= 1
			#end if
		#end while
	#end if

	return True
#end function

if __name__ == "__main__":
	buffer:str = input("enter a word, which might be a palindrome: ").lower()
	print(f"{buffer} is a palindrome: {"True" if on_palindrome(buffer) else "False"}")
#end entry point