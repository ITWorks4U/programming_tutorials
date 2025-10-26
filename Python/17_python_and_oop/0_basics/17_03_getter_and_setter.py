# ---
# Getter and setter can be used to have an
# easy access to the class members, but this
# has also a nasty side twist.
# ---

class Point:
	def __init__(self, x: int = 0, y: int = 0) -> None:
		# NOTE: if x and / or y does not comes
		#       with a setter property, these value(s)
		#       is / are unable to set
		self.x = x
		self.y = y
	#end constructor

	###
	# to define a class getter / setter,
	# use @property decorator above
	# an instance method
	#
	# NOTE: By default a property has a really
	# short name. Often the identical names for
	# attributes in the class.
	###

	# getter property (set by default)
	@property
	def x(self) -> int:
		# imaging, you've named x and y like
		# always, then this x will be called
		# over and over again => recursion error
		return self._x
	#end property

	# to define a setter property, then use
	# the already defined property "x" and expand
	# this with "setter", otherwise it may happen,
	# that "x" is not able to modify
	@x.setter
	def x(self, value: int) -> None:
		self._x = value
	#end property

	# allow to delete this property value
	@x.deleter
	def x(self) -> None:
		# When "del" is in use here, then the property
		# value is able to delete. It depends on you,
		# what may happen here. Let's say, that x will
		# be set with None.
		self._x = None
	#end property

	###
	# same for y
	###
	@property
	def y(self) -> int:
		return self._y
	#end property

	@y.setter
	def y(self, value: int) -> None:
		self._y = value
	#end property
#end class

def main() -> None:
	# fun fact: a class can also be instanciated with
	# a dictionary, which contains the attributes / fields
	# as a key, followed by a certain value
	#
	# NOTE: The key's name MUST be identical with the
	#       field name of the class, otherwise an error appears!
	#
	# NOTE: If a key does not match with a field in the class,
	#       then an error also appears.
	#
	# NOTE: Since the constructor comes with _x and _y, you must
	#       use "x" and "y" here, because the Python interpreter
	#       automatically calls the setter properties, which are
	#       named with "x" and "y".
	coords: dict[str, int] = {
		"x" : 5,
		"y" : 6
	}

	p = Point(**coords)
	print(f"p = [{p.x}, {p.y}]")

	p.x = 6
	p.y = -4
	print(f"p = [{p.x}, {p.y}]")

	# allow to "delete" x
	del p.x
	print(f"p = [{p.x}, {p.y}]")
#end main

if __name__ == "__main__":
	main()
#end entry point