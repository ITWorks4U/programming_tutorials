# ---
# methods can also be overloaded by using the
# @singledispatchmethod from functools module
# ---

class Printer:
	def display(self, a) -> None:
		print(f"displaying... {a}; type: {type(a)}")
	#end method
#end class

p: Printer = Printer()
p.display(a="123abc")
p.display(a=(5,6,7,8))
p.display(a=None)

# those examples above can be used as usual to use a method
# for anything, however, sometimes it might be better, if
# a specific type should do an independent way rather than
# an another type

# -----------------------------------------
print("-----------------------------------------")
# -----------------------------------------

from functools import singledispatchmethod

class PrinterOverride:
	# define a default method for any type, which is
	# not supposed to work with
	@singledispatchmethod
	def display(self, a) -> None:
		print(f"unsupported type for: {a} <=> {type(a)}")

	# to mark to work with specific types for an
	# own workflow, the method name above, here: display,
	# must be registered
	#
	# furthermore the method name is replaced with a single
	# underline "_"
	@display.register
	def _(self, a: int) -> None:
		print(f"this is only for integer: {a} <=> {type(a)}")
	#end method

	@display.register
	def _(self, a: float) -> None:
		print(f"this is only for floating point: {a} <=> {type(a)}")
	#end method

	# ...
#end class

p: PrinterOverride = PrinterOverride()
# now, "a" must not be called on the direct way, otherwise on runtime
# this error appears: raise TypeError(f'{funcname} requires at least 1 positional argument')
# p.display(a=100)

p.display(100)              # works, because int is registered
p.display(3.141)            # works
p.display("Hello World!")   # won't work, because string is not registered
p.display([])               # won't work