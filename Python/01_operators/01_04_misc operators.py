# values to use
a = 10
b = 20
tuple_of_numbers = (1, 2, 3, 4, 5, 6, 7, 8, 9, 10)

# membership operations (often used to check, if
# a number is in a collection or not)
print("--- membership operations ---")

# assume, that a is a part ot the tuple: True
print(a in tuple_of_numbers)

# assume, that b is a part of the tuple: False
print(b in tuple_of_numbers)

# negation
print(a not in tuple_of_numbers)
print(b not in tuple_of_numbers)

# identity operations (often used for object comparising,
# e. g. if two objects refers to the exactly memory,
# check, if a sub class is a part of a super class, etc.)
print("--- identity operations ---")

# assume, that a is identical to b: False
# => in that case it does NOT mean, if a == b
# => it means, if a points to the identical memory address of b
print(a is b)
print(a is not b)