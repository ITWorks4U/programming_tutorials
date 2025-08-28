# ---
# signals can also be ignored, whereas this is NOT a good idea to do this,
# unless YOU know what you do
# ---

from signal import signal, SIGINT, SIGTERM, SIGABRT, Signals, SIG_IGN
from sys import exit

# similar to C/C++ with volatile keyword
global_state: bool = True

# Who says, that only one signal handler function may exist?

# a signal handler function must have two arguments, often used "signal" and "frame"
# - "signlal" <=> signal number
# - "frame"   <=> address on memory, where this signal has been detected
def handle_critical_signal(signal, frame) -> None:
	summary = f"""
	critial signal ID {signal} ({Signals(signal)}) detected
	in address section {frame}

	Terminating the application...
	"""

	print(summary)
	exit(1)
#end function

def handle_signal(signal, frame) -> None:
	summary = f"""
	detected signal: {signal} ({Signals(signal)})
	in address section {frame}
	"""

	print(summary)

	global global_state
	global_state = False
#end function

def main() -> None:
	# register possible signals

	# at this point no SIGINT can be handled
	# you can hit Ctrl + C as much as you can, but nothing happens
	#
	# the only way is to terminate the application (on the hard way)
	#
	# Windows:
	# tasklist (to figure out which PID python.exe has)
	# taskkill /pid PID /F
	#
	# Linux (and possible available for macOS, too):
	# ps -efl | grep 18_03_ignoring_signals | grep -v grep
	# kill (-9) <pid>
	signal(SIGINT, SIG_IGN)

	# hint: not everytime the SIGTERM can be handled as usual
	signal(SIGTERM, handle_signal)

	# triggers only, if a SIGABRT has been detected at any time
	signal(SIGABRT, handle_critical_signal)

	print("Waiting patiently...")

	# ---
	# Usually, by pressing CTRL + C
	# a KeyboardError results and you
	# assumed to handle this "exception"
	# with an exception handling.
	# ---
	# global_state is set to True at the beginning
	# and will be switched to False in
	# signal handling function
	# ---
	while global_state:
		pass
	#end while

	print("Unable to see this text, right?")
#end main

if __name__ == "__main__":
	main()
#end entry point