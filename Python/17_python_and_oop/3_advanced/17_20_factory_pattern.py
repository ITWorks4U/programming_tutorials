# ---
# A factory pattern class offers to let create a certain class
# object depending on a called expression, used type, etc.
# ---

from abc import ABC, abstractmethod
from enum import Enum

# abstract class
class GeometricObject(ABC):
	@classmethod
	@abstractmethod
	def identify_class(cls):
		pass
	#end method
#end class

# child classes Circle and Triangle
class Circle(GeometricObject):
	def identify_class(self):
		return f"{self.__class__.__name__}"
	#end method
#end class

class Triangle(GeometricObject):
	def identify_class(self):
		return f"{self.__class__.__name__}"
	#end method
#end class

# enumeration class
class GeometricSelector(Enum):
	Circle = 0
	Triangle = 1
#end enum class

# factory class
class GeometricObjectFactory:
	@staticmethod
	def get_object(geometric_type: GeometricSelector):
		match geometric_type:
			case GeometricSelector.Circle:
				return Circle()
			case GeometricSelector.Triangle:
				return Triangle()
			case _:
				print("ERROR: unknown geometric type detected...")
			#end cases
		#end match
	#end method
#end class

if __name__ == "__main__":
	go_0: Circle = GeometricObjectFactory.get_object(GeometricSelector.Circle)
	
	if isinstance(go_0, Circle):
		print(go_0.identify_class())
	else:
		print("error: go_0 is not a circle...")
	#end if

	go_1: Triangle = GeometricObjectFactory.get_object(GeometricSelector.Triangle)

	if isinstance(go_1, Triangle):
		print(go_1.identify_class())
	else:
		print("error: go_1 is not a triangle...")
	#end if
#end entry point