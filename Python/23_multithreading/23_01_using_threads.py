# ---
# Using a new thread instead of a single thread.
#
# Each thread uses an own memory to do the task(s).
# The main thread has to wait until the sub threads has been
# finished, otherwise a runtime error or any undefined
# behavior may appear.
# ---

from threading import Thread
from datetime import timedelta
from timeit import Timer

import bubble_sort.bubble_sort as bs

def thread_function(thread_number: int) -> None:
	# sort 10,000 random numbers omly with threads
	t = Timer(lambda: bs.bubble_sort(custom_nbr=10000))
	print(f"thread #{thread_number} time amount for bubble sort: {timedelta(seconds=t.timeit(number=1))}")
#end function

# create new threads
t0: Thread = Thread(target=thread_function, kwargs={"thread_number" : 0})
t1: Thread = Thread(target=thread_function, kwargs={"thread_number" : 1})

# launching both threads
t0.start()
t1.start()

print("[main thread]: nothing to do here...")

# wait for both threads, because those are not marked
# for background services
#
# otherwise an error during runtime or any undefined behavior
# may appear

print("[main thread]: wating for the threads...")
t1.join()
t0.join()

print("[main thread]: done")