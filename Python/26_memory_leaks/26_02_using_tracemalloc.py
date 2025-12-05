# ---
# using tracemalloc
#
# no need to install that module
# ---


from tracemalloc import start, take_snapshot

fp = None

# number of frames (similar to lines), which will be traced
start(100)

def read_a_file():
	from sys import argv

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

		snapshot = take_snapshot()
		top_stats = snapshot.statistics("traceback")
		memory_blocks = []

		for ctr, stat in enumerate(top_stats):
			memory_blocks.append({
				"ctr": ctr,
				"number of blocks" : stat.count,
				"size" : stat.size,
				"traceback" : stat.traceback.format()
			})
		#end for

		for mb in memory_blocks:
			for obj in mb.items():
				print(obj)
			#end for
		#end for
	#end try
#end main

if __name__ == "__main__":
	main()
#end entry point