# ---
# Waiting for a child is very useful to make sure to collect
# each sub process before the main process ends.
#
# This is only useful, if the sub process is doing tasks,
# which may take more time than the main process is in use.
#
# A zombie process can't be handled in that way, because this
# will be terminated, when the main process ends here.
# ---

from platform import system
from multiprocessing import Process
from os import getpid, getppid
from time import sleep

def create_child_process() -> None:
	print(f"child process: [PID; PPID] = [{getpid()}; {getppid()}]")
	print("[child]: time to sleep for 5 seconds...")

	for _ in range(5):
		print("[child]: ZzZ ZzZ ZzZ")
		sleep(1)
	#end for

	# in case, if the sub process ends erlier than the main process
	# print("[child]: Hey, are you finished yet?!?")
#end function

def main():
	print(f"Running this sample on... {system()}")

	# this PPID is the parent process ID of python.exe
	print(f"main process: [PID; PPID] = [{getpid()}; {getppid()}]")

	p: Process = Process(target=create_child_process)

	# start the new process
	p.start()

	# wait for finish
	print("[parent]: Waiting patiently...")

	# in case, if the main process takes more time than the sub process
	# sleep(6)
	p.join()
#end main

if __name__ == "__main__":
	main()
#end entry point