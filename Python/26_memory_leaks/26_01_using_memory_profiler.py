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
# ---

from sys import argv
from memory_profiler import profile

fp = None

@profile
def read_a_file():
	global fp
	print("opening file...")
	fp = open(argv[0])

	raise Exception("oops")

	print("closing file...")
	fp.close()
	fp = None
#end function

@profile
def main():
	try:
		read_a_file()
	except Exception as e:
		print(f"error: {e.args}")
	finally:
		if fp is None:
			print("fp is None (again)")
		else:
			print(f"Has this file pointer been closed? {"True" if fp.closed else "False"}")
		#end if
	#end try
#end main

if __name__ == "__main__":
	main()
#end entry point