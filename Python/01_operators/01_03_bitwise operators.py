print("--- bitwise operations ---")

# values to use
a = 10
b = 20

# bitwise and
print(a & b)

# bitwise or
print(a | b)

# bitwise xor
print(a ^ b)

# negation
print(~a)

# combination...
print(~(a ^ b))

# shift rigt (the value of a will be smaller up to 0)
print(a >> 4)

# shift left (the value of a will be larger)
print(b << 4)

print("-------------------------------------")

# 73
a = 0b01001001
#	42
b = 0b00101010

print(a & b)
print(a | b)
print(a ^ b)
print(~a)
print(a >> 4)
print(b << 4)