# ---
# A class comes also with functions. Those are called "methods".
# Python determines three different class methods:
# - instance method
# - class method
# - static method
#
# A static method looks similar to a class method, but this
# will be handled like a regular function. Those methods
# are often in use to do something without creating an instance
# of the class itself, when this is not required.
#
# What will happen, if a static method is treated like
# an instance method itself...? Similar with a wrong class method
# access, this results to an undefined behavior. It may happen,
# that Python use the static method similar to a normal instance
# method or it may lead into an error during runtime.
# ---

class Point:
	def __init__(self, x: int = 0, y: int = 0) -> None:
		self.x = x
		self.y = y
	#end constructor

	@classmethod
	def copy_point(cls, coord: tuple[int]) -> "Point":
		return cls(x=coord[0], y=coord[1])
	#end method

	###
	# static method(s)
	###

	# to define a method in a class to a static method,
	# a @staticmethod decorator is required. Unlike to
	# an instance or class method, we don't use a special
	# word as the first argument.

	@staticmethod
	def calculate_distance_of_two_points(p0: "Point", p1: "Point") -> float:
		return ((p0.x - p1.x)**2 + (p0.y - p1.y)**2) ** 0.5
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

	# just use a static method, like:
	distance: float = Point.calculate_distance_of_two_points(p0, p1)
	print(f"distance between p0 and p1: {distance}")

	# What happens, if a static method will be handled like
	# an instance method? Even Python might handle this like
	# a "normal instance method", which shouldn't.
	distance = p0.calculate_distance_of_two_points(p0, p1)
	print(f"distance between p0 and p1: {distance}")
#end main

if __name__ == "__main__":
	main()
#end entry point