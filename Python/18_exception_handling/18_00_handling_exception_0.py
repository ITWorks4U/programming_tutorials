# ---
# trying to read a file,´which doesn't exist or
# no access rights are given, or file is corrupted or else
#
# Traceback (most recent call last):
# File "17_00_handling_exception_0", line 10, in <module>
# 	with open(file="Non existing file here", mode="r") as f:
# 	FileNotFoundError: [Errno 2] No such file or directory: 'Non existing file here'
# ---
# with open(file="Non existing file here", mode="r") as f:
# 	print(f.read())
# #end with

# ---
# again by handling the exception
# ---

try:
	# critical area; inside of this area
	# any error may appear and is possible to handle,
	# if the current exception can be catched...

	with open(file="Non existing file here", mode="r") as f:
		print(f.read())
	#end with
except FileNotFoundError as fnff:
	# ---
	# handes IO errors, like file not found
	# and prints the error message to the console
	# ---

	print(f"got an error: {fnff.strerror}")
except Exception as e:
	# ---
	# handler for common exceptions, which
	# hasn't been handled before
	#
	# basic exception is not required;
	# works also: except:
	#
	# prints error number and error message
	# to the console
	#
	# since this is the super class, every
	# child exception behind that block will
	# never been triggered
	# ---

	# e.args is a list, which usually contains only one element
	# so e.args[0] can be used as well
	print(f'critical error detected: {e.args}')
except NotImplementedError as nie:
	# ---
	# is never be able to trigger
	# ---

	pass
else:
	# ---
	# - old python implementation
	# - runs only, if no exception has been triggered
	# - is obsolete
	# ---

	print("...else block, if no error has been detected...")
finally:
	# ---
	# - optional
	# - runs always, no matter, if an exception
	#   has been triggered or not
	#
	# if used, this is always as the last instruction
	# ---

	print("...finally block...")
#end try-catch