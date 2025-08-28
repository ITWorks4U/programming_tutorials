# ---
# When the child process ends too early,
# then this child process becomes to a zombie.
#
# Unlike to an orphan process, this is not going
# to collect by the init process. This zombie process
# still exists until the main process ends.
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
		print("[child]: I gotta go...")
		sleep(2)
	elif pid > 0:
		# parent process here
		print(f"parent process running: [PID; PPID] = [{getpid()}; {getppid()}]")
		print("[parent]: nap time...")
		sleep(5)

		print("[parent]: Hey, where's my child?")
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