# ---
# simple string usages...
# ---
word = "This is a simple text. 123,456,789, blah blah blah, ..."
print(word)

word = "overwritten..."
print(word)

print("-------------------")

# ---
# accessing each character
# ---
word = "Python3"

for c in word:
	print(c)
# end for

# ---
# playing with strings
# those are similar to a list
# ---
print("first element: ", word[0])
print("third element: ", word[2])
print("last element: ", word[-1])

# ---
# get characters between [n,k]
# ---

# [0:5]: "Pytho", because we start from position 0 to position 5
print(" word[0:5]: ", word[0:5])

# [0:-6]: "P"; you can also set a range from a positive number to a negative number
print(" word[0:-6]: ", word[0:-6])

# [0:-7]: "", because there is no character in front of "P"
print(" word[0:-7]: ", word[0:-7])

# ---
# since strings are immutable, this causes errors
# ---
# word[4] = "f"
# print(word)
# del word[3]
# print(word)

print("-------------------")

# ---
# some useful functions for strings
# ---

# How many characters contains "word"?
print("\"%s\" contains %d characters" % (word, len(word)))

# counts, how often a sub word exists in word
print(word.count("o"))

# check, if a word ends with a sub expression
print(f"{word} ends with \"ABC\"...? {word.endswith("ABC")}")

# prints the position of found sub expression, if exists
print(f"found \"on\" on position: {word.find("on")}")

# first character (A-Z) is in capital
print(word.capitalize())

# returns True, if all characters are printable
# => control characters, like \b, \r, \a, ... are not printable
print(word.isprintable())

# ---
# ...in contrast to...
# ---
word = "\0"
print(word.isprintable())
# ---

word = "Python3"

# prints all characters in upper case
print(word.upper())

# prints all characters in lower case
print(word.lower())

# appending a "->" between each character
joinString = "->".join(word)
print(joinString)

# split the string into a list of
# single words, where the "->" sign is
# interpreted as a separator
print(joinString.split("->"))

# concatenation of two or more strings
print(word + joinString)

# multiple times of a string
print(word * 5)

# check, if a character is somewhere in the string
print(f"y exists in string: {"y" in word}, f exists in string: {"f" in word}")