# ---
# creating child process(es)
# by using fork
#
# a child process runs parallel
# to the main process
#
# on every time a new child process
# has been successfully created, this
# gets a new process-ID, uses the same
# program counter, CPU registers, open files, ...
#
# fork() returns an integer value of:
# - 0 := child process was sucessfully and is now running
# - >0 := parent process is still running and is doing tasks
# - <0 := fork() returned into an error; just the main process only runs
# ---

from platform import system
from os import getpid, getppid

def create_child_process() -> None:
	from os import fork

	pid = fork()
	if pid == 0:
		# child process here
		print(f"child process has been created: [PID; PPID] = [{getpid()}; {getppid()}]")
	elif pid > 0:
		# parent process here
		print(f"parent process running: [PID; PPID] = [{getpid()}; {getppid()}]")
	else:
		# any error during runtime with fork
		print("error: fork() was unable to use...")
	#end if
#end function

if __name__ == "__main__":
	if system() == "Windows":
		print("This script can't be run under Windows.")
	else:
		print(f"Running this script on {system()}...")
		print(f"main process: [PID; PPID] = [{getpid()}; {getppid()}]")
		create_child_process()
	#end if
#end entry point