# ---
# The function fork() is not available on Windows, so an alternative
# way is required here. This also works on other systems.
# ---

from platform import system
from multiprocessing import Process
from os import getpid, getppid

# getpid  => returns the current process ID
# getppid => returns the parent process ID

def create_child_process() -> None:
	print(f"child process: [PID; PPID] = [{getpid()}; {getppid()}]")
#end function

def main():
	print(f"Running this sample on... {system()}")

	# this PPID is the parent process ID of python.exe
	print(f"main process: [PID; PPID] = [{getpid()}; {getppid()}]")

	p: Process = Process(target=create_child_process)

	# start the new process
	p.start()

	# wait for finish
	p.join()
#end main

if __name__ == "__main__":
	main()
#end entry point