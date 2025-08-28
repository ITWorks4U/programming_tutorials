# ---
# A dataclass, from dataclasses module, allows you
# to create and use a class, where method overload can be
# used, but those can also be disabled.
# ---
# With @dataclass on top of the class itself, this comes
# automatically with __init__, to initialize your class attributes
# with any value, __repr__, __eq__, match_args, ...
# ---

from dataclasses import dataclass, fields

@dataclass
class Person:
	person_id: int
	f_name: str
	l_name: str
	birth_date: str

	# by using a dataclass, you don't need to define
	# your own __init__(); if you do this, then an error
	# appears on runtime, unless __init__ is set to False
	# in @dataclass(init = False)
	#
	# => in that case the constructor below
	# does not accept any arguments...
	# def __init__(self):
	# 	pass
#end class

# this, however, won't work, because your dataclass is expecting
# four arguments: person_id, f_name, l_name, birth_date
# p0: Person = Person()

p0: Person = Person(
	person_id=1,
	f_name="John",
	l_name="Cena",
	birth_date="1977-04-23"
)
print(f"[{p0.person_id}, {p0.f_name}, {p0.l_name}, {p0.birth_date}]")

# ---
# you can also use a dictionary and pass this trough
# the dataclass itself => the keys MUST be identical
# to the class attributes
# ---

d = {
	"person_id" : 1,
	"f_name" : "John",
	"l_name" : "Cena",
	"birth_date" : "1977-04-23"
}

p1: Person = Person(**d)
print(f"[{p1.person_id}, {p1.f_name}, {p1.l_name}, {p1.birth_date}]")

# ---
# if you try to use keys, which does not match in the certain
# dataclass, then an error on runtime appears
# ---

d = {
	"person_id" : 1,
	"f_name" : "John",
	"l_name" : "Cena",
	"birth_date" : "1977-04-23",
	"age" : 48
}

# p2: Person = Person(**d)
# => age is not defined in Person class, so this must be filtered out
# => this can be realized with fields from dataclasses

# receive all keys as a set, which exists in the Person class
detected_keys = {f.name for f in fields(Person)}

# compare each items from d and check, if this item is in the
# detected_keys set; if true, then the key value pair will be
# copied to d2; every kev value pair, which does not fit,
# will be skipped
d2 = {k : v for k, v in d.items() if k in detected_keys}

p2: Person = Person(**d2)
print(f"[{p2.person_id}, {p2.f_name}, {p2.l_name}, {p2.birth_date}]")

# ---
# What happens, if a dataclass contains more attributes, which are
# not in a dictionary? Error on runtime!
# ---

# person_id is missing here...
d = {
	"f_name" : "John",
	"l_name" : "Cena",
	"birth_date" : "1977-04-23",
}

# p3 can't be created, because person_id is missing here
# p3: Person = Person(**d)
# print(f"[{p3.person_id}, {p3.f_name}, {p3.l_name}, {p3.birth_date}]")