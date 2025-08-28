# ---
# runtime polymorphism (also known as "duck type polymorphism")
# ---

from abc import ABC, abstractmethod
from math import sqrt, pi

class GeometricObject(ABC):
	def __init__(self) -> None:
		print(f"Constructor for {self.__class__.__name__}")
	#end constructor

	def __del__(self) -> None:
		print(f"Destructor for {self.__class__.__name__}")
	#end destructor

	@classmethod
	@abstractmethod
	def area(self):
		pass
	#end method

	@classmethod
	@abstractmethod
	def perimeter(self):
		pass
	#end method
#end class

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

# ---
# usage...
# ---

# this function below uses the methods of the given class
# for polymorphism => the class instance itself MUST have
# those methods to use, otherwise an error during runtime
# appears
def use_geometric_object(go: GeometricObject = None) -> None:
	print(f"area for {go.__class__.__name__}: {go.area()}")
	print(f"perimeter for {go.__class__.__name__}: {go.perimeter()}")
	print("--------")
#end function

c: Circle = Circle(radius=2)
t: Triangle = Triangle(a=1, b=0.3, c=4)
print("--------")

use_geometric_object(c)
use_geometric_object(t)

# obviously, this won't work here
# use_geometric_object()