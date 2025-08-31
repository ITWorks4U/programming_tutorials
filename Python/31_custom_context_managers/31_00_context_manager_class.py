# ---
# use a custom context manager class
# ---

from sys import argv

class FileManager:
	def __init__(self, file_name: str, file_mode: str) -> None:
		self.file_name = file_name
		self.file_mode = file_mode
		self.file_descriptor = None
	#end constructor

	def __enter__(self) -> "FileManager":
		# enter a possible critical section
		self.file_descriptor = open(file=self.file_name, mode=self.file_mode)

		# the instance itself must be returned to be able to use
		return self
	#end method

	def __exit__(self, exception_type, exception_value, exception_traceback) -> bool:
		# it doesn't matter, if an exception may appear or not,
		# it's time to release that allocated memory
		if self.file_descriptor is not None:
			self.file_descriptor.close()
		#end if

		if exception_type is not None:
			print(f"an error occurred: {exception_value}")
			print(f"traceback: {exception_traceback}")
		#end if

		# to suppress the thrown error, if there's any,
		# the return statement is True
		#
		# if the exception shall be propagated instead,
		# then the return statement is False
		return True
	#end method
#end class

def read_file_without_error() -> None:
	# basicly, it's not necessary to create an instance of the
	# class itself

	fm: FileManager = FileManager(file_name=argv[0], file_mode="r")

	try:
		with fm as src:
			print(src.file_descriptor.readlines())
		#end with
	except Exception as e:
		print(f"error: {e.args}")
	#end try
#end function

def read_file_with_error() -> None:
	fm: FileManager = FileManager(file_name=None, file_mode="w")

	try:
		with fm as dest:
			dest.file_descriptor.write("This is a simple text.")
		#end with
	except Exception as e:
		print(f"error: {e.args}")
	#end try
#end function

def main() -> None:
	print("------------")
	read_file_without_error()
	print("------------")
	read_file_with_error()
	print("------------")
#end main

if __name__ == "__main__":
	main()
#end entry point