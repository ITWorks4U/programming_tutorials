# ---
# first option to read a file:
# ---

file_to_use: str = "lorem_ipsum.txt"

source = open(file_to_use, "r")

# print line by line (can be done, but for a huge file,
# this is a really bad idea)
for line in source:
	print(line)
#end for

# closes the file stream
source.close()
print("Source is closed? ", source.closed)
print("---------------")

# ---
# second option to read a file
# => still a bad idea to read a huge file and
#    print each line
# ---
source = open(file_to_use, mode="r", encoding="latin-1")

# using read() function instead
print(source.read())
source.close()
print("Source is closed? ", source.closed)
print("---------------")

# ---------------
# third option to
# read a file:
# ---------------
# using with command => automatically closes the
# file stream after completing with your operations
with open(file_to_use, "r") as source:
	print(source.read())
# end with

print("Source is closed? ", source.closed)