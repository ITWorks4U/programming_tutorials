# ---
# similar to the constructors, Python also does not come
# with a method overload
#
# unlike to write:
# def func0(self, a, b):
#    pass
#
# def func0(self, a, b, c):
#    pass
#
# => where func0 with a,b,c only exists, a method overload
# can be emulated by using *args (see: 08_02_arbitrary arguments.py)
# ---

class Calculator:
	def add(self, *args) -> int:
		# check, if args contains at least
		# one element
		if len(args) > 0:
			# calculates the sum of n numbers
			return sum(args)
		#end if

		return 0
	#end method
#end class

c: Calculator = Calculator()
print(f"add(*args) #0: {c.add(1,2,3,4,5,6,7,8,9)}")
print(f"add(*args) #1: {c.add()}")
print(f"add(*args) #2: {c.add(-1,-2,-3,-4,-5)}")



# even built-in methods, like __eq__, __add__, __sub__, ...
# can be written here to overload those methods

class Simple():
	def __init__(self, a: int, b: int) -> None:
		self.a = a
		self.b = b
	#end constructor

	# auto implementation for __eq__
	#
	# Do you remeber to "12_00_none_basics.py" with "undefined.__eq__(string_object)",
	# which returned "NotImplemented"?
	# By implementing this method, we can declare, what will happen here.
	def __eq__(self, v) -> bool:
		return self.a == v.a and self.b == v.b
	#end method

	#	custom implementations
	def __add__(self, o):
		return self.a + o.a, self.b + o.b
	#end method

	def __sub__(self, o):
		return self.a - o.a, self.b - o.b
	#end method

#end class

s1 = Simple(10,20)
s2 = Simple(10,21)

print(f'Are s1 and s2 equal? {s1.__eq__(s2)}')
print(f's1 + s2: {s1.__add__(s2)}')
print(f's1 - s2: {s1.__sub__(s2)}')