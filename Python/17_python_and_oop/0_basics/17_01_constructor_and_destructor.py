# ---
# constructors allows you to let create an instance
# of the class itself
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
#   the last defined constructor / method dominates and the Python interpreter
#   starts to complain, when a constructor / method with the wrong number of
#   arguments is/are given
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
# - unpedictable application run:
#   - program exits abruptly
#   - a circular reference may exist
# - can be interfere with garbage collection
# - exceptions in a __del__ are hard to debug and ignored by default

class Simple:
	def __init__(self) -> None:
		"""
		Default constructor. If not given
		and no other constructor is defined,
		this is used automatically => basic class usage.py
		"""
		self.class_object = None
		print("Basic constructor.")
	#end constructor

	def __init__(self, arg = tuple()) -> None:
		"""
		Extended constructor. Comes with
		an argument. By default this argument
		is defined as a tuple.

		Since this constructor is defined,
		this will override the default constructor.
		"""
		self.class_object = arg
		print("Extended constructor #1")
	#end extended constructor #1

	def __init__(self, a: int, b: int) -> None:
		"""
		Extended constructor.
		Since this constructor is defined,
		this will override the constructor(s) above.

		An instance of this class can only
		be done, if two arguments are given.
		"""
		self.class_object = a + b
		print("Extended constructor #2")
	#end extended constructor #2
	
	def __del__(self):
		"""
		Destructor (in other languages: Finalizer).
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

# ---
# create an instance of the class
# be careful, because a class does not comes with
# multiple constructors
# ---
# s = Simple()                # won't work
# s = Simple((1,2,3,4,5))     # won't work
s = Simple(
	a=10,
	b=20
)
print(f"class_object = {s.class_object}, type: {type(s.class_object)}")