# values to use
a = 10
b = 20

# arithmetic operations
print("--- arithmetic operations ---")

# addition
print(a+b)

# subtraction
print(a-b)

# multiplication
print(a*b)

# ---
# division
# ---
# often results to a relational number (here: floating point)
print(a/b)

# results to a decimal number only (here: int)
print(a//b)

# modulo operation
print(a%b)

# power calculation (a^b)
print(a**b)

# ---
# assignments
# ---
print("--- assigning operations ---")
result = a + b
print(result)

# equal to: result = result + a
result += a
print(result)

# equal to: result = result - b
result -= b
print(result)

# attention:
# in Python there is no result++ or result--
result += 1
print(result)