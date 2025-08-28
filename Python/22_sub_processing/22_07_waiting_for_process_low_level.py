# ---
# Waiting for the sub process in low level by using waitpid()
# function. This works only for UNIX-like systems, like Linux, macOS.
# ---

from platform import system
from os import getpid, getppid

def create_child_process() -> None:
	from os import fork, wait, waitpid
	from time import sleep

	pid = fork()
	if pid == 0:
		# child process here
		print(f"child process has been created: [PID; PPID] = [{getpid()}; {getppid()}]")
		print("[child]: Doing a long process here...")

		for _ in range(10):
			print("[child]: ...")
			sleep(1)
		#end for

		print("[child]: Done!")
	elif pid > 0:
		# parent process here
		print(f"parent process running: [PID; PPID] = [{getpid()}; {getppid()}]")
		print("[parent]: nap time...")
		sleep(5)

		print("[parent]: Yeah, my child takes a long time...")

		# wait() waits for >>any<< created child process
		wait()

		# waitpid() waits for a specific child process instead
		# waitpid(pid, 0)

		print("[parent]: Ah, there you are!")
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
