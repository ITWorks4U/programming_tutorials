# Python comes with a dynamic interpretation of types,
# however, it also contains data types for a
# special purpose
#
# with type(a_given_type) you can get the type

# classes are coming in a later section
class Test:
	pass


# let Python figure out which type is in use here

# basic types
print(type(10))                         # integer
print(type(12345.6789))                 # float (Python won't comes with a double type)
print(type("ABC"))                      # string
print(type(True))                       # boolean
print(type(None))                       # similar to NULL in C/C++, but not identical

# additional types
print(type([1,2,3]))                    # list
print(type({1,2,3}))                    # set
print(type({1:'A', 2:'B', 3:'C'}))      # dictionary
print(type((1,2,3)))                    # tuple

# special cases for the used class above
print(type(Test))                       # Surprised?

t = Test()
print(type(t))                          # Surprised?

# by using the class name itself, python can only detect
# a "type", whereas an instance of the class, here "t"
# results to "__main__.Test"
#
# more informations soon