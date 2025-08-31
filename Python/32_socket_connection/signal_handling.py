from signal import signal, SIGINT, SIGTERM, Signals
from sys import exit

def signal_handler(signal, frame) -> None:
	sum_up: str = f"""
	received signal: {signal}
	type: {Signals(signal)}
	located: {frame}
	"""

	print(sum_up)
	exit(0)
#end function

def register_signals() -> None:
	signal(SIGINT, signal_handler)
	signal(SIGTERM, signal_handler)
#end function