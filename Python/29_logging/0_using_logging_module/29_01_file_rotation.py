# ---
# Unlike to the previous example a file rotation shall be used,
# when a file size has been reached or shortly exceeded an upper
# limit. A rotation to the next file is going to start.
#
# When the number of maximum supported files has been reached,
# then the first file will be used again.
# ---

import logging
from logging.handlers import RotatingFileHandler

from function_time_amount import *

@time_measurment
def log_to_file() -> None:
	# NOTE: By using this example, up to 10 log files with max
	# 128 MB are going to create and hold. By writing 100,000,000
	# times those three instructions below into the file, the time
	# amount could take some hours.

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
	# create a rotating file handler with:
	# - file name
	# - mode
	# - max allowed size (here: 128 MB)
	# - keep up to 100 files only
	log_handler = RotatingFileHandler(
		filename="logging.log",
		mode="w",
		maxBytes=(1 << 27),            # 134,217,728 Bytes <=> 128 MB (alternative: 128 * 1024 * 1024)
		backupCount=100
	)

	# add a formatter style for logging
	formatter = logging.Formatter("%(asctime)s - %(levelname)s - %(message)s")
	log_handler.setFormatter(formatter)

	logging.basicConfig(level=logging.DEBUG, handlers=[log_handler])

	log_to_file()
#end entry point