# ---
# Outside of Windows an another way is also possible
# to create a new sub process by using fork().
# ---

from platform import system
from os import getpid, getppid

def create_child_process() -> None:
	from os import fork

	_ = fork()
	print(f"child process: [PID; PPID] = [{getpid()}; {getppid()}]")
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