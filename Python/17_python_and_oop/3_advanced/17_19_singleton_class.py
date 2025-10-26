# ---
# A singleton class is a design pattern to ensure to
# have only one instance of a class.
#
# When to use a singleton class:
# - to prevent multiple instances of a class
# - offer a clean way to work for a specific case, like
#   - managing shared resources
#   - when the class shall become immutable or stateless
#
# When not to use a singleton class:
# - by using multiprocessing/ -threading, because multiple
#   processes / threads may create their own "unique" singleton class
# - unit testing 
# ---

def singleton_instance(cls):
	instances = {}

	def get_instance(*args, **kwargs):
		if cls not in instances:
			instances[cls] = cls(*args, **kwargs)
		#end if

		return instances[cls]
	#end function

	#NOTE: get_instance must not contain (), otherwise
	# the error of: "'Singleton' object is not callable"
	# will be printed to the console 
	return get_instance
#end function

@singleton_instance
class Singleton:
	def __init__(self, *args) -> None:
		self.collection = args
	#end constructor

	@property
	def args(self):
		return self.collection
	#end property
#end class

if __name__ == "__main__":
	a = Singleton(0,1,2,3,4,5,6,7,8,9)
	b = Singleton("abcdefghijklmnopqrstuvwxyz")

	print(a.args)
	print(b.args)

	print(a is b)
#end entry point