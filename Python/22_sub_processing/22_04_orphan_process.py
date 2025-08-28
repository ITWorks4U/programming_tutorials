# ---
# When the main process ends too early,
# then the child process becomes orphan.
#
# The init process (process-ID 1) collects each
# orphan process to make sure to complete the tasks.
# ---

from platform import system
from os import getpid, getppid

def create_child_process() -> None:
	from os import fork
	from time import sleep

	pid = fork()
	if pid == 0:
		# child process here
		print(f"child process has been created: [PID; PPID] = [{getpid()}; {getppid()}]")
		print("[child]: the child process is going to sleep for a long time...")
		sleep(5)

		print("[child]: Mommy / Daddy...?")
	elif pid > 0:
		# parent process here
		print(f"parent process running: [PID; PPID] = [{getpid()}; {getppid()}]")
		print("[parent]: Time to go...")
		sleep(2)

		print("[parent]: Did I miss something? No, not really.")
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