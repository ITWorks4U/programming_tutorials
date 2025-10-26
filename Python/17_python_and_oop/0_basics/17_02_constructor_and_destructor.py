# ---
# Constructors allows you to let create an instance
# of the class itself.
# 
# there are multiple ways to use a constructor:
# - empty default constructor (exists by default)
# - custom default constructor (without arguments by yourself)
# - custom parameterized constructor (any arguments by yourself)
# 
# In Python only ONE constructor can exist!
#
# in contrast to C++, Java, C#:
# - Python does not support multiple constructors
# - Python does not support method overload (even for constructors)
#   - unless a module, like singledispatch or multipledispatch may help out
#
#   The last defined constructor / method dominates and the Python interpreter
#   starts to complain, when a constructor / method with the wrong number of
#   arguments is/are given.
# - a constructor is defined with __init__(self, ...)
#
# a destructor is also different rather to C++, Java, C#
# - defined with __del__(self)
# - hardly used; only in use, for:
#   - critical operations, e. g.: memory management
#   - if the context manager (with) can't be used
#   - when Python's garbage collector can't safety handle this
#
# a destructor should also NOT used in every situation, like:
# - unpredictable timing: when you don’t know when __del__() will be called
# - unpredictable application run:
#   - program exits abruptly
#   - a circular reference may exist
# - can be interfere with garbage collection
# - exceptions in a __del__ are hard to debug and ignored by default

class Point:
	def __init__(self) -> None:
		"""
		Default constructor. If no other
		constructor is defined,
		this is used automatically.
		"""
		self.x = 0
		self.y = 0
		print("Basic constructor.")
	#end constructor #1

	def __init__(self, *args, **kwargs) -> None:
		"""
		An extended constructor.
		A class may also be able to initialized
		by arbitrary arguments or keyword arguments.

		By the way, *args / **kwargs are automatically
		given in the default constructor, which means,
		that this is "identical" to the default constructor.

		Since this constructor is defined,
		this will override the constructor(s) above!
		"""
		self.x = 0
		self.y = 0
		print("Extended constructor #1")
	#end extended constructor #2

	def __init__(self, x: int = 0, y: int = 0) -> None:
		"""
		Similar to the "extended constructor #2":
		Define a constructor with a fixed amount of arguments,
		where the arguments itself are initialized with a
		default value.

		In summary, this constructor can be called without
		any argument, as well as, by specifying a and / or b.

		Remeber: If your class comes with previously defined
		constructor(s), then this one is the "newest" constructor.
		"""
		self.x = x
		self.y = y
		print("Extended constructor #2")
	#end extended constructor #3

	def __init__(self, coords: tuple[int]) -> None:
		"""
		An another extended constructor. Comes with
		a single argument. In contrast to the
		3rd "extended" constructor, the argument(s)
		MUST be used to work with.

		Since this constructor is defined,
		this will override the previous defined constructor(s)!
		"""
		self.x = coords[0]
		self.y = coords[1]
		print("Extended constructor #3")
	#end extended constructor #4
	
	def __del__(self):
		"""
		Destructor (in other languages: finalizer).
		By default this will be called,
		when this class object is no longer in use
		or deleted by yourself.

		Can be defined by yourself to do
		some cleanup options.

		Be careful: If any exception may appear during
		destructing, this >>could<< be able caught, but also
		causes undefined behaviors on runtime!
		"""
		print("Destructor is called.")
	#end destructor
#end class

def main() -> None:
	# won't more work here
	# p = Point()

	# now this works
	# NOTE: The arguments of the tuple itself MUST be
	#       covered into an additional bracket pair!
	# p = Point((1,2))

	# To make this a bit more clean, use this instead:
	coordinates: tuple[int] = (1,2)
	p = Point(coordinates)
	# NOTE: Unlike to arbitrary arguments, which MAY be
	#       assumed here, this tuple above must not be
	#       handled as an arbitrary argument!

	# accessing to its member(s)
	print(f"p = [{p.x}, {p.y}]")

	# also be able to modify the members
	p.x = -3
	p.y = -4

	print(f"p = [{p.x}, {p.y}]")
#end main

if __name__ == "__main__":
	main()
#end entry point