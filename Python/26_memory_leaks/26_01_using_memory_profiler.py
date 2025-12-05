# ---
# The module memory_profile allows us to take
# a more detailed look about allocated and
# released memory.
#
# However, when an exception appears,
# this profile is not completed, which means,
# we're not able to receive a detailed information.
#
# By default memory_profiler is not installed.
# => pip[3.exe] install memory_profiler
#
# In combination with debugging a memory leak can easily be detected.
#
# to see a memory summary, use @profile
# to see the memory consumption many times, use memory_usage
# ---

from sys import argv
from memory_profiler import profile, memory_usage

fp = None

# @profile
def memory_consumption(nbr_of_elements: int = 100000):
	obj_list: list[int] = [i for i in range(nbr_of_elements)]

	# do something with that list

	# no need to delete the list, because this memory is going
	# to freed when the function is left, but this may also
	# cause a different behavior
	del obj_list
#end function

# @profile
def read_a_file():
	global fp
	print("opening file...")
	fp = open(argv[0])

	raise Exception("oops")

	print("closing file...")
	fp.close()
	fp = None
#end function

# @profile
def main():
	try:
		# with @profile

		# read_a_file()
		# memory_consumption()

		###
		# with memory_usage
		###

		# also works:
		#  - memory_usage((memory_consumption, ()))
		#  - memory_usage(memory_consumption)

		# summary: list[float] = memory_usage((memory_consumption, (), {"nbr_of_elements" : 123456}), timestamps=True)
		# print(f"memory consumptions: {len(summary)}, minimal memory amount: {min(summary)}, max memory amount: {max(summary)}")

		pass
	except Exception as e:
		print(f"error: {e.args}")
	finally:
		if fp is not None:
			print(f"Has this file pointer been closed? {"True" if fp.closed else "False"}")
		#end if
	#end try
#end main

if __name__ == "__main__":
	main()
#end entry point