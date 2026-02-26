def _handle_signal(sig_nbr, frame) -> None:
	exit(0)
#end function

def register_signal() -> None:
	from signal import signal, SIGINT

	signal(SIGINT, _handle_signal)
#end function