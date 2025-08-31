# ---
# sometimes a custom context manager class may not interrupt or
# stop the whole process, when an exception has been detected there
#
# this can be handled with the return statement of the __exit__ method
# ---

class SilentContextManager:
	def __init__(self, suppress_exception: bool = False) -> None:
		self.suppress_exception = suppress_exception

		# self.__class__.__name__ => returns the class name
		self.name = self.__class__.__name__
	#end constructor

	def __enter__(self) -> "SilentContextManager":
		print(f"[{self.name}] got into that the context manager area")

		return self
	#end method

	def __exit__(self, exception_type, exception_value, exception_traceback) -> bool:
		print(f"[{self.name}] leaving...")

		if exception_type is not None:
			summary = f"""
[{self.name}] exception: {exception_type.__name__} has been detected...
[{self.name}] value: {exception_value}
[{self.name}] traceback: {exception_traceback}

[{self.name}] Is this exception being suppressed? {"Yes." if self.suppress_exception else "No."}
"""
			print(summary)
		#end if

		return self.suppress_exception
	#end method
#end class

if __name__ == "__main__":

	# again: an instance of the class itself is not necessary
	with SilentContextManager(suppress_exception=True):
		print(f"[{__name__}] inside the block")
		raise RuntimeError("something was wrong here")
	#end with

	# other stuff here:
	#
	# in case of the not suppressed exception this code below
	# is unable to use unless the context manager has been moved
	# into an own try-except block
	print(f"[{__name__}]: {[i for i in range(100)]}")
	print(f"[{__name__}] program ends now")
#end entry point