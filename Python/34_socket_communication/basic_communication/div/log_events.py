from enum import Enum

class LogType(Enum):
	NORMAL_TYPE = 0
	WARNING_TYPE = 1
	ERROR_TYPE = 2
#end enum class

class LogEvent:
	"""
	Allow an isoloated log for every event for server or client.
	"""
	def __init__(self, log_file_name: str):
		from os.path import dirname, abspath, exists, join
		from os import makedirs

		folder_path: str = dirname(abspath(log_file_name))
		full_log_path: str = join(folder_path, "logs")

		# check, if the folder doesn't exist yet
		if not exists(full_log_path):
			makedirs(full_log_path)
		#end if

		absolute_path: str = join(full_log_path, log_file_name)
		self._init_logging(absolute_path)
	#end constructor

	def _init_logging(self, log_file_name: str) -> None:
		from logging import basicConfig, INFO

		basicConfig(
			filename=log_file_name,
			filemode="a",
			level=INFO,
			format="%(asctime)s - %(levelname)s - %(message)s"
		)

		self.log_into_file(message="New session started.")
	#end method

	def log_into_file(self, message: str, log_type: LogType = LogType.NORMAL_TYPE) -> None:
		from logging import info, warning, error

		match log_type:
			case LogType.WARNING_TYPE:
				warning(message)
			case LogType.ERROR_TYPE:
				error(message)
			case _:
				# defaults to NORMAL_TYPE
				info(message)
			#end cases
		#end match
	#end method
#end class