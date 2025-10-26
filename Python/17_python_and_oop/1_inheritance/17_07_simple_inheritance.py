# ---
# Inheritance allows you to extend
# a class with new functionalities.
# ---

from math import sqrt, pi

# simple base class
class GeometricObject:
	def __init__(self) -> None:
		print(f"Constructor for {self.__class__.__name__}")
	#end constructor

	# a destructor is hardly required, but in that
	# case this is also given here
	def __del__(self) -> None:
		print(f"Destructor for {self.__class__.__name__}")
	#end destructor

	# area and perimeter for the "abstract" base class
	# are not supposed to use here
	def area(self):
		pass
	#end method

	def perimeter(self):
		pass
	#end method
#end class

# ---
# derived classes
# syntax: class <name>(<name_of_super_class>):
# ---
class Circle(GeometricObject):
	def __init__(self, radius: float) -> None:
		# this command will also initialize
		# the base class; this is not always
		# required to do
		# super().__init__()

		print(f"Constructor for {self.__class__.__name__}")

		self.radius = radius
	#end constructor

	def __del__(self) -> None:
		print(f"Destructor for {self.__class__.__name__}")
	#end destructor

	def area(self):
		return pi * self.radius * self.radius
	#end method

	def perimeter(self):
		return 2 * pi * self.radius
	#end method
#end class

class Triangle(GeometricObject):
	def __init__(self, a: float, b: float, c: float) -> None:
		print(f"Constructor for {self.__class__.__name__}")

		self.a = a
		self.b = b
		self.c = c
	#end constructor

	def __del__(self) -> None:
		print(f"Destructor for {self.__class__.__name__}")
	#end destructor

	def area(self):
		s: float = (self.a + self.b + self.c) / 2.0

		# Heron's formula
		# with abs(x) to use the positive number of x, if x may be negative
		return sqrt(abs(s * (s - self.a) * (s - self.b) * (s - self.c)))
	#end method

	def perimeter(self):
		return self.a + self.b + self.c
	#end method
#end class

# ---
# usage...
# ---

def main() -> None:
	go: GeometricObject = GeometricObject()
	print(f"(go) area: {go.area()}, perimeter: {go.perimeter()}")

	c: Circle = Circle(radius=2)
	print(f"(c) area: {c.area()}, perimeter: {c.perimeter()}")

	t: Triangle = Triangle(a=1, b=0.3, c=4)
	print(f"(t) area: {t.area()}, perimeter: {t.perimeter()}")
#end main

if __name__ == "__main__":
	main()
#end entry point