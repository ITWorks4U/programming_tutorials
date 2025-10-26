# ---
# Create and use abstract classes. Similar to C++ Python does
# not come with a difference between an abstract class and an
# own interface. This is also the same.
# ---

# NOTE:
# depending on the python version you're using, abstractclassmethod
# may be marked as deprecated and shall be replaced with:
# @classmethod @abstractmethod

from abc import ABC, abstractmethod #, abstractclassmethod
from math import sqrt, pi

# To make this class abstract, this inherits ABC and at
# least ONE method is marked as abstact, too.
class GeometricObject(ABC):
	def __init__(self) -> None:
		print(f"Constructor for {self.__class__.__name__}")
	#end constructor

	def __del__(self) -> None:
		print(f"Destructor for {self.__class__.__name__}")
	#end destructor

	# area and perimeter should not be used outside
	# of the class => to realize this, we make those
	# abstract

	@classmethod
	@abstractmethod
	# @abstractclassmethod
	def area(self):
		pass
	#end method

	@classmethod
	@abstractmethod
	# @abstractclassmethod
	def perimeter(self):
		pass
	#end method
#end class

# ---
# derived classes
# ---
class Circle(GeometricObject):
	def __init__(self, radius: float) -> None:
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
		return sqrt(abs(s * (s - self.a) * (s - self.b) * (s - self.c)))
	#end method

	def perimeter(self):
		return self.a + self.b + self.c
	#end method
#end class

def main() -> None:
	# since GeometricObject is now abstract, this can't be
	# instanciated to use this
	# go: GeometricObject = GeometricObject()
	# print(f"(go) area: {go.area()}, perimeter: {go.perimeter()}")

	c: Circle = Circle(radius=2)
	print(f"(c) area: {c.area()}, perimeter: {c.perimeter()}")

	t: Triangle = Triangle(a=1, b=0.3, c=4)
	print(f"(t) area: {t.area()}, perimeter: {t.perimeter()}")
#end main

if __name__ == "__main__":
	main()
#end entry point