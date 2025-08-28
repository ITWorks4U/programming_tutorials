# ---
# class attributes can be used to work within the class,
# but remember: by default all attributes are public by default
# ---
# the attributes can be defined anywhere in your class:
# - class body      typically, if you know other languages, like C, C++, C#, Java, ...
# - constructor     very often
# - in any method   hardly and this should not be done there
# ---

class Person:
	def __init__(self) -> None:
		# public
		self.person_id: int = 0
		self.f_name: str = ""
		self.l_name: str = ""
		self.birth_date: str = ""

		# "protected" and "private"
		# -> usually, this is the mark for
		#    internal usgage only, even those
		#    can also be accessed from outside

		self._protected_value: int = 100
		
		# "private only"
		# -> this can be marked as a "private" attribute,
		#    but such elements are designed for an another
		#    purpose
		self.__private_value: str = "top secret"
	#end constructor
#end class

p: Person = Person()
print(f"[{p.person_id}, {p.f_name}, {p.l_name}, {p.birth_date}]")

p.person_id = 3
p.f_name = "John"
p.l_name = "Cena"
p.birth_date = "1977-04-23"

print(f"[{p.person_id}, {p.f_name}, {p.l_name}, {p.birth_date}]")

print("------------------")
# an access is still available, but this is not mentioned to do
print(f"\"protected value:\" {p._protected_value}")

# this can also be modified
p._protected_value = 101
print(f"\"protected value:\" {p._protected_value}")

# an access to a "private" element is not able to use here
# -> causes an error on runtime
# print(f"\"private\" value: {p.__private_value}")