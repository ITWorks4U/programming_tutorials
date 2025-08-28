# ---
# How to understand the datatype None in Python.
# ---
undefined = None
print("You will see this:", undefined)
print("-------------")

string_object: str = "Test string"

# ---
# What will happen? Do we receive an error?
# ---
print(f"#1: Are \"{undefined}\" and \"{string_object}\" equal? {undefined.__eq__(string_object)}")
print(f"#2: Are \"{undefined}\" and \"{string_object}\" equal? {string_object.__eq__(undefined)}")
print(f"#3: Are \"{undefined}\" and \"{string_object}\" equal? {string_object == undefined}")
print(f"#4: Are \"{undefined}\" and \"{string_object}\" equal? {undefined is string_object}")
print(f"#5: Are \"{undefined}\" and \"{string_object}\" equal? {string_object is undefined}")