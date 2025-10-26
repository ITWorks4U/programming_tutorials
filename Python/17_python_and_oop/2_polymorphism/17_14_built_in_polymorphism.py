# ---
# polymorphism in built-in functions
# -> len(), max(), ... are able to use for any kind
# list elements, like string, list, tuple, dictionary, set
# ---

s: str = "Hello World!"
l: list = [1,2,3,4,5,6,7,8,9]

print(f"length for {s}: {len(s)}")
print(f"{s} max element: {max(s)} ...?")
# not even a function, like max() can be used for a string
# without being confused => max() determines the highest
# element in the string, where "r" is the "highest" element
# => "r" <=> ASCII: 72

print(f"length for {l}: {len(l)}")
print(f"{l} max element: {max(l)}")