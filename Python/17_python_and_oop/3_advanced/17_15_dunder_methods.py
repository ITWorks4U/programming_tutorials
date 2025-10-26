# ---
# "Dunder methods" exists since the first python application, which are
# hardly reconized yet. Now it's time to take a deeper look into.
#
# "Dunder methods" are named by __<name>__. Expressions, like:
# - __name__, __init__, __eq__, ... are dunder methods. ;-)
#
# Dunder methods can be used for special class methods itself,
# as well as, for operator overloading and may more.
#
# Thats why you should NOT name a variable, function, class field,
# class method, ... with __<name>, because this may be interpreted
# as a dunder method, which makes no sense. 
# ---

class Point:
	def __init__(self, x: int, y: int) -> None:
		self.x = x
		self.y = y
	#end constructor

	# additional dunder methods, like check for
	# equality
	def __eq__(self, value: "Point") -> bool:
		return self.x == value.x and self.y == value.y
	#end method

	# What about to add two points and return
	# a tuple as a result? => Overriding "+".
	def __add__(self, value: "Point") -> tuple[int]:
		return self.x + value.x, self.y + value.y
	#end operator override

	# And what about to return a new class instance
	# itself by subtracting two points? ;-)
	def __sub__(self, value: "Point") -> "Point":
		return Point(x=self.x - value.x, y=self.y - value.y)
	#end operator override
#end class

def main() -> None:
	p0: Point = Point(2,3)
	p1: Point = Point(6,-2)

	print(f"p0 = [{p0.x}, {p0.y}]")
	print(f"p1 = [{p1.x}, {p1.y}]")
	print(f"p0 and p1 are equal...? {p0.__eq__(p1)}")

	p2 = p0 + p1
	print(f"=> p2 is a type of {type(p2)} ==> {p2}")

	p3 = p0 - p1
	print(f"=> p3 is a type of {type(p3)} ==> {p3}")
#end main

if __name__ == "__main__":
	main()
#end if