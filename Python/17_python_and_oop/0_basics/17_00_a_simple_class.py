# ---
# A class is a container to store multiple variables / attributes,
# functions, here: class methods in a single cluster to work with.
#
# Unlike to other languages, like C/C++/C# no struct or union or
# interface exists. But this doesn't matter.
#
# NOTE: There'e three ways to define a class, which has
#       the same effect:
#       1)   class <name>:
#       2)   class <name>():
#       3)   class <name>(object):
#
#       It doesn't matter, which one of these three types
#       you're using.
# ---
class Point:
	# define class attributes,
	# which is public by default
	x = 0
	y = 0
#end class

def main() -> None:
	# create an object of this class
	p = Point()

	# accessing to its member(s)
	print(f"p = [{p.x}, {p.y}]")

	# also be able to modify the members
	p.x = 100
	p.y = -4

	print(f"p = [{p.x}, {p.y}]")

	# delete the instance of the class,
	# but this does NOT really delete
	# the instance itself; this has an
	# another effect
	#
	# NOTE: Never use "del" here.
	del p

	# well, at this point "p" has been deleted,
	# and p.x, p.y are now unable to access...
	# print(f"p = [{p.x}, {p.y}]")

	# NOTE: When the end of a function / application
	#       has been reached, then the instance of this
	#       class has automatically been deleted by the
	#       python garbage collector.
#end main

if __name__ == "__main__":
	main()
#end entry point