#!/usr/bin/python3

"""
	Inheritance allows you to extend
	a class with new functionalities.

	video tutorial:	https://youtu.be/AK44C_uZ9u4
	timestamp:		03:06:53
"""

class Simple:
	def myObject(self):
		return "base"
	#end method
#end class

class Derived1(Simple):
	def myObject(self):
		return 123
	#end method
#end class

class Derived2(Simple):
	def myObject(self):
		return tuple(list(set()))
	#end method
#end class

'''
	A class can inherit multuiple classes.
	In contrast to C++, a 'diamond problem'
	is solved automatically.
'''
class MultipleInheritance(Derived1, Derived2):

	#	Which value has this myObject()?
	def myObject(self):
		return super().myObject()
	#end method
#end class

m = MultipleInheritance()
print(f'{m.myObject()} <=> {type(m.myObject())}')