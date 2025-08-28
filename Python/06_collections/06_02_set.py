# ---
# A set is a dynamic collection, which holds any type.
# Similar to a list, this can easily being used to iterate
# trough the collection, adding new elements, removing elements,
# however, a list contains unique data elements only, but
# those elements are NOT ordered in numeric and alphabetical order
# by default
# ---

# define a set
a_simple_set = {1, 2, 3, 7, 5, 3, None, "ABC", "DEF", "XYZ", "ABC"}

# an empty set
an_empty_set_0 = set()

# this is NOT a set
an_empty_set_1 = {}
print(type(an_empty_set_1))

# ---
# accessing
# ---

# prints the whole set
print(a_simple_set)

# go trough all elements
for element in a_simple_set:
	print(element)
# end for

# ---
# modifiying
# ---

# adds a new element to the set, if not already existing
a_simple_set.add(False)

# removes the last added element only
a_simple_set.pop()

# remvoes a given element, where this element MUST exist
a_simple_set.remove(7)

# try to remove a given element, if existing
a_simple_set.discard(False)

# won't work with sets
# print(a_simple_set[0])

print(a_simple_set)

# ---
# have some fun with sets
# ---
A = {1, 2, 3, False, None}
B = {"A", "B", "C", 1, 2, 3}

# union: A U B
print(f"union (A U B): {A.union(B)} <=> {A | B}")

# intersection: A ∩ B
print(f"intersection (A ∩ B): {A.intersection(B)} <=> {A & B}")

# difference: A - B
# => elements only in the first set, but not in the second
print(f"difference (A - B): {A.difference(B)} <=> {A - B}")

# symmetric difference: A ^ B
# => elements in either set, but not in both
print(f"symmetric difference (A ^ B): {A.symmetric_difference(B)} <=> {A ^ B}")

# subset: A <= B
print(f"subset (A <= B): {A.issubset(B)} <=> {A <= B}")

# upperset: A >= B
print(f"upperset (A => B): {A.issuperset(B)} <=> {A >= B}")

# disjoint:
# => two sets are disjoint, if they have no elements in common
print(f"disjoint: {A.isdisjoint(B)}")