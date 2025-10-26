# ---
# A class comes also with functions. Those are called "methods".
# Python determines three different class methods:
# - instance method
# - class method
# - static method
#
# A class method is able to use only without using an
# instance to the class itself. This class method can
# be used to initialize a new instance from outside.
#
# Trying to call a class method with an instance leads
# to an undefined side effect. Python would use this
# class method like an instance method, but this may
# also lead into an error on runtime.
# ---

class Point:
	def __init__(self, x: int = 0, y: int = 0) -> None:
		self.x = x
		self.y = y
	#end constructor

	###
	# class method(s)
	###

	# to define a method in a class to a class method,
	# a @classmethod decorator is required, where the
	# arguments are also different to an instance method
	#
	# "cls" is often used for the "class" reference itself
	#
	# The second argument can be anything. It's not required
	# to use a tuple. Even the number of arguments can be
	# different.

	@classmethod
	def copy_point(cls, coord: tuple[int]) -> "Point":
		return cls(x=coord[0], y=coord[1])
	#end method
#end class

def main() -> None:
	coords: dict[str, int] = {
		"x" : 5,
		"y" : 6
	}

	p0 = Point(**coords)

	coord: tuple[int] = (1,2)
	p1 = Point.copy_point(coord)

	print(f"p0 = [{p0.x}, {p0.y}]")
	print(f"p1 = [{p1.x}, {p1.y}]")
	print(f"p0 and p1 are identical: {p0 is p1}")

	# what happens, when a class method is
	# handled like an instance method...?
	coord: tuple[int] = (-4,12)
	p2 = p0.copy_point(coord)
	print(f"p0 = [{p0.x}, {p0.y}]")
	print(f"p1 = [{p1.x}, {p1.y}]")
	print(f"p2 = [{p2.x}, {p2.y}]")
	print(f"p0 and p2 are identical: {p0 is p2}")
	print(f"p1 and p2 are identical: {p1 is p2}")
#end main

if __name__ == "__main__":
	main()
#end entry point