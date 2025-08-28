# import the pdb module for debugging
import pdb

# start the debugger
#
# attention:
# when we're terminating the debugger
# with 'quit' or 'q' an unhandled
# error during process time (BdbQuit) may occur

try:
	pdb.set_trace()

	# using a snipped for debugging
	counter: int = 0

	while counter < 100:
		pass
	#end while
except Exception as e:
	# Surprised? No Information exists here.
	print(f"==> {e.args}")
#end try