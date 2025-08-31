from os import listdir, getcwd, remove, stat
from os.path import join
from time import time

from log_level import LogLevel

class Logger:
	def __init__(self, log_file: str, log_level: LogLevel = LogLevel.INFO, max_log_lifetime: int = 30) -> None:
		self.log_file = log_file
		self.log_level = log_level
		self.max_log_lifetime = max_log_lifetime

		self._clear_old_log_files()
	#end constructor

	def _clear_old_log_files(self) -> None:
		# scan all existing log files
		current_folder = getcwd()
		all_log_files = [f for f in listdir(current_folder) if f.startswith("log")]

		# remove all log files, which lifetime has been reached
		now = time()
		for log in all_log_files:
			if stat(join(current_folder, log)).st_mtime < now - self.max_log_lifetime * 86400:
				try:
					remove(log)
				except Exception as e:
					print(f"error: unable to remove the old log file: {e.args}")
				#end try
			#end if
		#end for
	#end method

	def write_to_log(self, msg: str) -> None:
		log_message: str

		match self.log_level:
			case LogLevel.DEBUG:
				log_message = f"[{LogLevel.DEBUG.name}] {msg}"
			case LogLevel.INFO:
				log_message = f"[{LogLevel.INFO.name}] {msg}"
			case LogLevel.WARNING:
				log_message = f"[{LogLevel.WARNING.name}] {msg}"
			case LogLevel.ERROR:
				log_message = f"[{LogLevel.ERROR.name}] {msg}"
			case _:
				log_message = f"[{LogLevel.CRITICAL.name}] {msg}"
			#end cases
		#end match

		try:
			with open(self.log_file, mode="a") as dest:
				print(log_message, file=dest)
			#end with
		except Exception as e:
			print(f"ERROR: unable to write to the log file: {e.args}")
		#end try
	#end method
#end class