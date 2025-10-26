# ---
# A class comes also with functions. Those are called "methods".
# Python determines three different class methods:
# - instance method
# - class method
# - static method
#
# An instance method is able to use only, if an instance
# of this class has been created before. By trying to
# call a class method without an instance object, this leads
# into an error on runtime.
# ---

class Point:
	def __init__(self, x: int = 0, y: int = 0) -> None:
		self.x = x
		self.y = y
	#end constructor

	###
	# instance method(s)
	###

	# to define a method to a class, the 'self' expression
	# must be used here, otherwise an access to this method
	# is usually not possible (except for the next sample)
	#
	# NOTE:   "self" can't be accessed from outside. This is
	#         just a mark for an instance method itself, where
	#         "self" is not required to use. Any other name can
	#         also be used here, but by default "self" is the
	#         way to go.
	def update_point(self, x: int, y: int) -> None:
		self.x = x
		self.y = y
	#end method

	# Copy a point to another point, but this one
	# has a nasty side effect. By copying the instance
	# self, a shallow copy is in use for an another
	# object.
	#
	# In other words: By modifiying p0, p1 is also
	# modified.
	#
	# NOTE: The class name itself can be used as a
	#       return value, but since the whole class
	#       has not been completely scanned by the
	#       python interpreter, the Point class is
	#       unknown. To fix that issue, the class name
	#       must be quoted.
	def copy_point_wrong(self) -> "Point":
		"""
		This won't copy the point class.
		It returns the instance of the class itself.
		"""
		return self
	#end method

	def copy_point_correct(self) -> "Point":
		"""
		Copy a point for an independent usage.
		"""
		return Point(x = self.x, y=self.y)
	#end method

	def add_two_points(self, p: "Point") -> None:
		self.x += p.x
		self.y += p.y
	#end method

	def subtract_two_points(self, p: "Point") -> None:
		self.x -= p.x
		self.y -= p.y
	#end method
#end class

def main() -> None:
	coords: dict[str, int] = {
		"x" : 5,
		"y" : 6
	}

	p0 = Point(**coords)
	print(f"p0 = [{p0.x}, {p0.y}]")

	# normal class method call
	p0.update_point(x = -2, y= 10)
	print(f"p0 = [{p0.x}, {p0.y}]")

	# This causes an error on runtime, when
	# only x and y are given.
	# Because "self" is now required to use,
	# which makes no sense, the method call
	# requires three arguments.
	#
	# self can refer to "p", but this is
	# not a clean way to do this
	# Point.update_point(self=p, x = 1, y = 9)
	# print(f"p = [{p.x}, {p.y}]")

	# use the wrong way and see, what happens here
	p1 = p0.copy_point_wrong()
	p1.x = 10
	p1.y = 20

	# oops :o)
	print(f"p0 = [{p0.x}, {p0.y}]")
	print(f"p1 = [{p1.x}, {p1.y}]")
	print(f"p0 and p1 are identical: {p0 is p1}")

	# use this instead
	p1 = p0.copy_point_correct()
	p1.x = -3
	p1.y = 99

	print(f"p0 = [{p0.x}, {p0.y}]")
	print(f"p1 = [{p1.x}, {p1.y}]")
	print(f"p0 and p1 are identical: {p0 is p1}")
#end main

if __name__ == "__main__":
	main()
#end entry point