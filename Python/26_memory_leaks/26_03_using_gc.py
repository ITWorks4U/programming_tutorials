from gc import set_debug, collect, DEBUG_SAVEALL, DEBUG_UNCOLLECTABLE, garbage

class LeakOfLegends:
	def __init__(self) -> None:
		self.obj = self
		self.data = "X" * 10**6
	#end constructor

	def __del__(self) -> None:
		pass
	#end destructor
#end class

if __name__ == "__main__":
	from sys import stderr

	try:
		print("Warning: This code may cause a memory error!", file=stderr)
		set_debug(DEBUG_SAVEALL | DEBUG_UNCOLLECTABLE)

		objects: list[LeakOfLegends] = [LeakOfLegends() for _ in range(100000)]
		del objects

		collect()
		print(f"Uncollectable objects: {len(garbage)}")
	except Exception as e:
		print(f"general error: {type(e)}; Does this contain any information? {e.args if len(e.args) > 0 else "No"}")
	#end try
#end entry point