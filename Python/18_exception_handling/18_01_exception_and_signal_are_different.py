# ---
# often misinterpreted:
# an exception and interrupt aren't equal
#
# exception:
# - appears for a critical piece of code
# - can be repeated
#
# signal:
# - may appear at any time anywhere
# - does not repeat every time
#   - hardly in the same code section
# ---

try:
	# endless loop
	print("Waiting patiently...")

	while True:
		pass
	#end while
except KeyboardInterrupt as k:
	# ---
	# this is wrongly interpreted
	# as an exception, where this
	# is an interruption
	#
	# k.args has no information for us
	# ---
	print(f"CTRL + C has been pressed: {k.args}... Wait? No informations for us?!?")
except Exception as e:
	# ---
	# fun fact: the basic exception class can't
	# handle this interrupt correctly
	#
	# you may see the that:
	# Waiting patiently...
	# ^CFinally!
	# Traceback (most recent call last):
	# File "17_01_exception_and_signal_are_different.py", line >LINE_NBR<, in <module>
	# pass
	# KeyboardInterrupt
	#
	# - depending on the Python version, OS, ... you may also see the default behavior
	# - similar to "you never have used an 'exception handling' before"
	# ---
	print(f'{e.args}')
finally:
	print("Finally!")
#end try-except