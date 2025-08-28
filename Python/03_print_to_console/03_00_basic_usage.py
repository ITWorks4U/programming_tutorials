# ---
# basic usages
# ---

# prints a newline
print()

# using double quotas for a word...
print("123ABC")

# single qoutas works also well
# => on Python this is valid, in other languages, like
# C, C++, Java, C#, ... this is invalid, because this shall
# be used for a single character only
print('123ABC')

print("------------------")

# ---
# print more than one expression
# ---

str_val: str = "This is a simple text."
nbr_val: int = 100
bool_val: bool = False

# print every variable including comma in
# that linear order
print(str_val, nbr_val, bool_val)

# do a concatenation of two or more >>words<<
# will be converted to a 'single word'
print(str_val + str(nbr_val) + str(bool_val))