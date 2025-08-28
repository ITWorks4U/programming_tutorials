# ---
# every function in a class is called "method", because
# this is bounded to the class itself
# ---

class Point:
	def __init__(self) -> None:
		self.x: int = 0
		self.y: int = 0
	#end constructor

	# to define a method to a class, the 'self' expression
	# must be used here, otherwise an access to this method
	# is usually not possible (except for the next sample)
	#
	# 'self' can't be accessed from outside
	def update_point(self, x: int, y: int) -> None:
		self.x = x
		self.y = y
	#end method

	# sometimes the class name itself is not defined yet,
	# so in that case type the class name as a string
	#
	# the python interpreter marks this for the class Point
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
		p = Point()
		p.x = self.x
		p.y = self.y

		return p
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

p0: Point = Point()
print(f"p0: [{p0.x},{p0.y}]")

p0.update_point(x=13,y=20)
print(f"p0: [{p0.x},{p0.y}]")

p1: Point = p0.copy_point_wrong()
print(f"p1: [{p1.x},{p1.y}]")

print(f"Are p0 and p1 equal? {p0 is p1}")
print("----------------------------")

# even p1 updates the valeus x and y, p0 is also
# affected, because p0 and p1 are identical
p1.update_point(x=25,y=-4)
print(f"p0: [{p0.x},{p0.y}]")
print(f"p1: [{p1.x},{p1.y}]")

p0.add_two_points(p1)
print(f"p0: [{p0.x},{p0.y}]")

p1.subtract_two_points(p0)
print(f"p1: [{p0.x},{p0.y}]")

print("----------------------------")

p2: Point = p1.copy_point_correct()
print(f"p2: [{p2.x},{p2.y}]")
print(f"Are p0 and p2 equal? {p0 is p2}")

print("----------------------------")