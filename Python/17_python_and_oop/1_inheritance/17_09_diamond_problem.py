# ---
# A diamond problem appears, when a class inherits from
# two ore more classes, where those classes may also
# inherit from the same base class.
#
# This may looks like:
#
#          A
#        /   \
#       B     C
#        \   /
#          D
#
# In contrast to C++, see chapter 21/21_08 Python automatically
# solves that problem MRO (method resolution order).
# This avoids ambigious methods from B, C, when D calls a derived
# method.
# ---

# "A"
class Base:
	def identify_class(self) -> None:
		print(f"called method {self.identify_class.__name__}() from {self.__class__.__name__}")
	#end method
#end class

# "B"
class Derived0(Base):
	def identify_class(self) -> None:
		print(f"called method {self.identify_class.__name__}() from {self.__class__.__name__}")
	#end method
#end class

# "C"
class Derived1(Base):
	def identify_class(self) -> None:
		print(f"called method {self.identify_class.__name__}() from {self.__class__.__name__}")
	#end method
#end class

# "D"
class Bottom(Derived0, Derived1):
	def identify_class(self) -> None:
		print(f"called method {self.identify_class.__name__}() from {self.__class__.__name__}")

		# call the super method and be surprised
		super().identify_class()
	#end method
#end class

if __name__ == "__main__":
	d: Bottom = Bottom()
	d.identify_class()

	# print MRO for Bottom class
	print(f"MRO hierarchy for d: {Bottom.__mro__}")
#end entry point