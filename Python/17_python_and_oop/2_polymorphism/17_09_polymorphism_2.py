# ---
# iterate trough each class instance
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

shapes = [Circle(radius=2), Triangle(a=1, b=0.3, c=4)]

print("--------")
for s in shapes:
	print(f"area for {s.__class__.__name__}: {s.area()}")
	print(f"perimeter for {s.__class__.__name__}: {s.perimeter()}")
	print("--------")
#end for