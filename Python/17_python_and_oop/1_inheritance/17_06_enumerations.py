# ---
# enumerations are similar to enum class in C++
# ---

# required module to load
from enum import Enum

class Food(Enum):
	Apple = 1
	Bulb = 2
	Banana = 3
	Burger = 4
	Toast = 5
#end enumeration

# ---
# A normal usage is now impossible.
# ---
# f = Food()
# print(f"{f.Apple}, {f.Banana}, {f.Toast}")
# print(f"{f.name}", {f.value})

# ---
# Similar to enum class in C++
# an access can be used only ba
# <enum_class>.<element>
# ---
print(f'{Food.Apple}, {Food.Banana}, {Food.Toast}')

# however, this can be done in Python, what is impossible in C++
elements = [Food.Apple, Food.Bulb, Food.Banana, Food.Burger, Food.Toast]

for e in elements:
	print(f"[{e.name}, {e.value}]")
#end for