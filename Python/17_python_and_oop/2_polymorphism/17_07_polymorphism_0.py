# ---
# compile-time polymorphism
# ---

class Calculator:
	def multiply(self, a: float = 1, b: float = 1, *args) -> float:
		result: float = a * b

		for a in args:
			result *= a
		#end for

		return result
	#end method
#end class

# ---
# usage...
# ---

c: Calculator = Calculator()

print(f"multiply #0: {c.multiply()}")
print(f"multiply #1: {c.multiply(3)}")
print(f"multiply #2: {c.multiply(1,2,3)}")
print(f"multiply #3: {c.multiply(1,2,3,4,5,6,7,8,9)}")