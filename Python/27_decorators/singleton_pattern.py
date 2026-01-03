# ---
# Example for singleton classes.
# ---

from decorators import singleton_instance

# without singleton decorator
class A:
	def __init__(self, *args, **kwargs) -> None:
		self._args = args
		self._kwargs = kwargs
	#end constructor

	@property
	def args(self) -> tuple:
		return self._args
	#end property
	
	@property
	def kwargs(self) -> dict:
		return self._kwargs
	#end property
#end class

# with singleton decorator
@singleton_instance
class B:
	def __init__(self, *args, **kwargs) -> None:
		self._args = args
		self._kwargs = kwargs
	#end constructor

	@property
	def args(self) -> tuple:
		return self._args
	#end property
	
	@property
	def kwargs(self) -> dict:
		return self._kwargs
	#end property
#end class

def compare_classes(a, b, with_singleton: bool = False) -> None:
	print(f"({"with" if with_singleton else "without"} singleton) a and b are identical: {a is b}")
#end function

if __name__ == "__main__":
	# without singleton...
	a = A(1,2,3,4,5,a = 100, b = "Hello World!")
	b = A(6,7,8,9,0,c = 700, d = "How are you?")
	compare_classes(a,b)

	# with singleton
	a = B(1,2,3,4,5,a = 100, b = "Hello World!")
	b = B(6,7,8,9,0,c = 700, d = "How are you?")
	compare_classes(a,b, with_singleton=True)
#end entry point