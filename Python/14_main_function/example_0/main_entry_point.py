# Since you're using a main function, this is NOT
# the main entry point for python. It's "just"
# a normal function.
def main():
	print('This is our "main" function.')
#end "main"

# that's the real main entry point:
if	__name__ == '__main__':
	# this code might be a bit uncommon,
	# but it's often in use for larger projects
	#
	# the __main__ is a system command, which checks,
	# if >>this<< python script has been launched by
	# the python interpreter to identify this as
	# the main script
	#
	# for more details look to example_1
 
	# normal function call
	main()
#end "real main"