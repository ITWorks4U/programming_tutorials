# ---
# contains functions and objects
# to work with arguments
# ---
import sys

if __name__ == '__main__':

	# argv := argument vector
	# contains each argument...
	print(f'arguments passed: {len(sys.argv)}')

	# ...including your own python script (similar to C/C++)
	for i,a in enumerate(sys.argv):
		print(f'argument {i}: {a}')
	#end for
#end main