# values to use
a = True
b = False

print("--- locical operations ---")

print(a)
print(b)

# combining True and False (in technical language: 1 and 0), where the result is always False (0)
# similar in other languages: a && b
# 
# hint:
# - in C++ the expressions "and", "or", "not" are also in use, but are more for bitwise operations
# - take a look to C++/11_bit_operations
print(a and b)

# combining True or False, where the result is False only,
# if all values are False, otherwise True
print(a or b)

# negation of their value(s)
print(not a)
print(not b)
print(not not a)

# !(a && b) = !a || !b
# !(True and False) = !True or !False = False or True = True
print(not(a and b))


print(not(a or b))
print(not(a and not b))
print(not(a or not b))
print(not(not a and b))
print(not(not a or b))