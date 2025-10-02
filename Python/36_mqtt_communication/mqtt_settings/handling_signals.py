# ---
# Just handling possible incoming signals.
# ---

from signal import signal, Signals, SIGINT, SIGTERM

def _handle_signal(signal, frame) -> None:
	"""
	Handle incoming signals, like SIGINT, SIGTERM and
	terminate the application with exit code 0.
	"""
	from sys import exit

	summary = f"""
	signal number: {signal}
	name: {Signals(signal).name}
	located from: {frame}
	"""

	print(summary)
	exit(0)
#end function

def register_sigals() -> None:
	"""
	Register possibly incoming signals, like
	SIGINT or SIGTERM. Those will be handled
	automatically.

	When one of these signals has been detected,
	a simple output to the console is going to use,
	followed by the normal application termination
	with exit code 0.
	"""
	signal(SIGINT, _handle_signal)
	signal(SIGTERM, _handle_signal)
#end function