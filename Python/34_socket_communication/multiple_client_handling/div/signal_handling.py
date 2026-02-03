from signal import signal, SIGINT, Signals
from div.log_events import LogEvent

class SignalHandler:
	def __init__(self, le: LogEvent):
		self.le = le
		self._register_signals()
	#end constructor

	def _signal_handler(self, sig_nbr, sig_location) -> None:
		sum_up: list[str] = [
			f"received signal number: {sig_nbr}",
			f"type: {Signals(sig_nbr).name}",
			f"located: {sig_location}"
		]

		for su in sum_up:
			self.le.log_into_file(su)
		#end for

		exit(0)
	#end method

	def _register_signals(self) -> None:
		signal(SIGINT, self._signal_handler)
	#end method
#end class