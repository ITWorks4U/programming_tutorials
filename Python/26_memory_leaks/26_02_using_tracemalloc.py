# ---
# using tracemalloc
#
# no need to install that module
# ---

from sys import argv
import tracemalloc

fp = None

#	number of frames (similar to lines), which will be traced
tracemalloc.start(100)

def read_a_file():
	global fp
	print("opening file...")
	fp = open(argv[0])

	raise Exception("oops")

	print("closing file...")
	fp.close()
	fp = None
#end function

def main():
	try:
		read_a_file()
	except Exception as e:
		print(f"error: {e.args[0]}")
	finally:
		if fp is None:
			print("fp is None (again)")
		else:
			print(f"Has this file pointer been closed? {"True" if fp.closed else "False"}")
		#end if

		# We're taking the current snapshot and
		# try to figure out, which informations
		# can we get.

		print(".: traceback :.")

		snapshot = tracemalloc.take_snapshot()
		top_stats = snapshot.statistics("traceback")

		for stat in top_stats:
			print(f"# memory blocks: {stat.count}, size: {stat.size} bytes")

			for line in stat.traceback.format():
				print(line)
			#end for
		#end for
	#end try
#end main

if __name__ == "__main__":
	main()
#end entry point