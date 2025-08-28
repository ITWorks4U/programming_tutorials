# ---
# class properties, similar to C++, Java, C#, ... allows you to
# use getter and setter similar to C#:
# - string Data {get; set;}
# ---

from dataclasses import dataclass

@dataclass
class Person:
	person_id: int
	f_name: str
	l_name: str
	birth_date: str

	# - by default, the properties are read only
	# - usually, the name of a property is (almost) identical
	#   to the class attribute, but this may also cause confusion
	#   or errors on runtime
	@property
	def first_name(self):
		return self.f_name
	#end property

	# to make a setter-property, use:
	@first_name.setter
	def first_name(self, value):
		self.f_name = value
	#end property
#end class

p: Person = Person(
	person_id=1,
	f_name="John",
	l_name="Cena",
	birth_date="1977-04-23"
)
print(f"[{p.person_id}, {p.f_name}, {p.l_name}, {p.birth_date}]")

p.first_name = "Abraham"
print(f"[{p.person_id}, {p.f_name}, {p.l_name}, {p.birth_date}]")
print(f"[{p.person_id}, {p.first_name}, {p.l_name}, {p.birth_date}]")