# ---
# A background thread can be used to do tasks,
# where the main thread does not need to wait for
# those threads.
#
# Attention:
# A background thread is not a solution for every
# situation. This should only be done for small
# operations.
#
# Since a thread is marked as daemon, this runs
# in the background and does no longer affect
# the main thread, however, this makes no
# guarantee, that all background threads stops
# their activities, when the application has been
# terminated!
# ---

from time import sleep
from random import random
from threading import Thread
from signal import SIGINT, SIGTERM, signal, raise_signal

# ---
# global values
# ---
global_value: int = 0
on_continue: bool = True

# ---
# signal handler (Ctrl + C, kill <process id>)
# ---
def handler_function(signal, frame) -> None:
	global on_continue
	on_continue = False
#end function

# ---
# outsourced thread function
# ---
def thread_task():
	global global_value
	internal_value = global_value

	while on_continue:
		if global_value != internal_value:
			print(f"[sub thread] new value: {global_value}")
			internal_value = global_value
		#end if

		# ---
		# wait 100ms for
		# the next turn
		# ---
		sleep(0.1)
	#end while

	# ---
	# Is that ever
	# be able to reach?
	# ---
	print("[sub thread] the end")
#end function

def main() -> None:
	signal(SIGINT, handler_function)
	signal(SIGTERM, handler_function)

	print("[main thread] Starting...")

	# Since t is now a background thread,
	# this won't longer block the main thread
	# at the end, however, t may still running
	# when the main application has been terminated.
	#
	# Try to run that sample without the daemon argument
	# or daemon = False. :o)
	
	t = Thread(target=thread_task, daemon=True)
	t.start()

	global global_value

	for _ in range(5):
		v = random() * 3
		sleep(v)

		global_value = v
	#end for

	print("[main thread] Main thread done.")

	# waiting up to 3 seconds
	# for the next instruction(s)
	t.join(timeout=3)
	print(f"[main thread] Everything worked well, right? By the way, is t still alive? {t.is_alive()}")

	# to make sure, that also the thread is now finished
	# this can be done by setting on_continue = False
	# or raise an expected signal

	# global on_continue
	# on_continue = False

	raise_signal(SIGINT)

	#	finally, wait 1s => "the end" must be shown on the console
	sleep(1)
	print(f"[main thread] Checking again: Is t still alive? {t.is_alive()}")
#end main

if __name__ == "__main__":
	main()
#end entry point