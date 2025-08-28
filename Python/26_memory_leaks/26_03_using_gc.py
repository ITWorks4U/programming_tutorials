import gc
gc.set_debug(gc.DEBUG_LEAK)

leaky_list = []

def leaky_func():
	# 1MB
	big_data = "X" * 10**6
	leaky_list.append(big_data)

if __name__ == "__main__":
	for _ in range(100000):
		leaky_func()
	#end for

	gc.collect()
	print(f"Uncollectable objects: {len(gc.garbage)}")
#end entry point