# ---
# With fork a new sub process is going to create, however,
# it's a bad idea to do a mess like this:
# ---

from platform import system

def create_child_process() -> None:
	from os import fork

	_ = fork()
	_ = fork()
	_ = fork()
	_ = fork()

	print("What shall be happen here?")

	# each fork allows you to create a new child process,
	# however, the number of new processes exceeds drastically,
	# if you don't mind
	#
	# in that case 16 processes are running
	# 1 main process and 15 child processes
	#
	# It's unclear, when the main process
	# may end. This could be after the first
	# output or sometimes later
	#
	# every child process, which is "still alive"
	# after main termination becomes orphan and will
	# be collected and handled by the init process
	# (process-ID: 1)

#end function

if __name__ == "__main__":
	if system() == "Windows":
		print("This script can't be run under Windows.")
	else:
		print(f"Running this script on {system()}...")
		print("Just create only one sub process, right?")
		create_child_process()

		print("What have you done?!?")
	#end if
#end entry point