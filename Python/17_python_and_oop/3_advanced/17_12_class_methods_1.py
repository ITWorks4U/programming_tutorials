# ---
# a class may have the built-in decorator @classmethod and @staticmethod
#
# When to use?
# - instance method (by default):
#   - reading / writing instance attributes
#
# - @classmethod
#   - access to the class, but not to the instance itself
#   - can be used for alternative constructors, factory methods, ...
#
# - @staticmethod
#   - the method doesn't need access to an instance or class access
#   - just like "static" keyword from other languages
#   - this is logically related to the class, but independent
# ---

class Point:
	def __init__(self, x: int, y: int) -> None:
		self.x: int = x
		self.y: int = y
	#end constructor

	def add_two_points(self, p: "Point") -> None:
		self.x += p.x
		self.y += p.y
	#end method

	def subtract_two_points(self, p: "Point") -> None:
		self.x -= p.x
		self.y -= p.y
	#end method

	# for a @classmethod instead of "self", the expression "cls" is
	# used here; "cls" is not required, so you can use any other name, too
	@classmethod
	def get_coordinate_by_classmethod(cls, coords: tuple[int, int]) -> "Point":
		return cls(coords[0], coords[1])
	#end method

	# sometimes an access to a method from outside is required without
	# using an instance of the class itself, so "self" or "cls" is not
	# in use here
	@staticmethod
	def calculate_distance_of_two_points(p1: "Point", p2: "Point") -> float:
		return ((p1.x - p2.x)**2 + (p1.y - p2.y)**2) ** 0.5
#end class

p0: Point = Point(-3,-1)
print(f"p0: [{p0.x},{p0.y}]")

print("----------------------------")

print("with @classmethod")
p1: Point = Point.get_coordinate_by_classmethod((5, 7))
print(f"p1: [{p1.x},{p1.y}]")
print(f"Are p0 and p1 equal? {p0 is p1}")

print("----------------------------")
print("with @staticmethod")
distance: float = Point.calculate_distance_of_two_points(p0, p1)
print(f"distance of p0 and p1: {distance}")