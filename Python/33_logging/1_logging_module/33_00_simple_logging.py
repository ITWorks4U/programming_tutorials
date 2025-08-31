# ---
# create a simple logging example
# without a limitation of the log files, the size,
# rotation, ...
# ---

import logging
from function_time_amount import *

@time_measurment
def log_to_file() -> None:
	# NOTE: it's a dumb idea to write 300,000,000 lines
	# into a single file... => size of the file >16GB

	for i in range(MAX_COUNTER):
		logging.info("This is a simple log message.")
		logging.warning("This is a warning.")
		logging.error("This is an error.")

		if i % STEP_COUNTER == 0:
			print(i)
		#end if
	#end for
#end function

if __name__ == "__main__":
	# log file to use without specific configurations
	# logging.getLogger("logging.log")

	# log to a file with a basic setup for logging, e. g.:
	# - name of the log file
	# - the previous content shall be overwritten
	# - minimal a debug information is going to write into that log file
	#   - if the level starts with an another level, like warning, then
	#     messages of type of debug and info ware not written into the file
	# - how the format of the log file should be displayed
	#   - timestamp - level - message
	logging.basicConfig(
		filename="logging.log",
		filemode="w",
		level=logging.DEBUG,
		format="%(asctime)s - %(levelname)s - %(message)s"
	)

	log_to_file()
#end entry point