# ---
# unlike to use the logging module you could also
# handle the log files by yourself
#
# this is rarley used, but this also works
# ---

from logger import Logger
from log_level import LogLevel

if __name__ == "__main__":
	# create a new logger instance for:
	# - log file to use
	# - log level to use (for all log output)
	# - maxmimum log lifetime in days
	log = Logger(log_file="logging.log", log_level=LogLevel.DEBUG, max_log_lifetime=90)

	for _ in range(50000):
		log.write_to_log("This is a message.")
	#end for
#end entry point