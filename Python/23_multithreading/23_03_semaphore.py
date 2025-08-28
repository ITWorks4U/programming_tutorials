# A semaphore is a special case
# for multithreading. It's like a critical
# area, which allows up to n threads works
# with it at the same time.
#
# Imagine, you're with your car in front of a bridge.
# There's only space for one car. On the other side
# there're also cars. The semaphore might be a traffic
# light, which controls, on which side the cars may
# use the bridge, where the cars on the other side
# must wait before the traffic light turns from red to green.
#
# Typically, a semaphore allows only one
# thread at the certain time amount to work
# with anything. Since this thread is using
# this semaphore, every other thread must
# wait until the current thread has finished
# the job.
#
# The semaphore class requires an argument
# of 0 or higher. Don't use 0, because on runtime
# the first thread is waiting for eterinity
# to use the semaphore. Similar to the other threads.
#
# Unlike to the regular thread using, where's no guarantee,
# which thread is now running, with the semaphore the threads
# are running in the expected order.
#
# A semaphore must start to aquire the next free block to
# block that for other threads. When this is done, this must
# also be released. At any time an error may appear, so it's
# much better to use the >>with<< keyword to release the lock
# automatically.

from time import sleep
from random import random
from threading import Thread, Semaphore

def critical_area_0(sem: Semaphore, thread_id: int) -> None:
	# blocks the workflow for other threads
	# sem.acquire()
	#
	# #code behind...
	#
	# releases the lock
	# sem.release()

	with sem:
		print("----------")
		value = random()
		sleep(value)

		print(f"thread #{thread_id} has got the value {value}")
	#end with
#end function

if __name__ == '__main__':
	msg_main_thread: str = f"""
-----------------
[main thread] accessing {critical_area_0.__name__} 10 times with only one semaphore...
-----------------
	"""

	# define, how much threads are allowed
	# to use the critical object
	s: Semaphore = Semaphore(value=1)

	for ctr in range(10):
		worker = Thread(target=critical_area_0, kwargs={"sem" : s, "thread_id" : ctr})
		worker.start()
	#end for
#end main