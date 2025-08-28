from sys import argv

fp = None

def read_a_file():
	global fp
	print("opening file...")

	# Usually, open should be do with
	# the with block to release the
	# allocated memory automatically.
	# No matter, if an exception ocurrs or not.
	fp = open(argv[0])

	raise Exception("oops")

	# since an exception raises, these instructions
	# below are now unavailable => the allocated
	# memory is now lost while the application is still running
	print("closing file...")
	fp.close()
#end function

def main():
	try:
		read_a_file()
	except Exception as e:
		print(f"error: {e.args}")
	finally:
		if fp is not None:
			print(f"file pointer has been closed: {"True" if fp.closed else "False"}")
		#end if
	#end try
#end main

if __name__ == "__main__":
	main()
#end entry point