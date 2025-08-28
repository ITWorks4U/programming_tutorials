# ---
# definition of a class
# ---
class Simple:
	# define a class attribute, which is public by default
	my_own_object = "this is a class attribute..."
#end class

# create an object of class Simple
s: Simple = Simple()
print(s.my_own_object)

# delete instance to the class,
# but this does NOT really delete
# the instance itself; this has an
# another effect
del s

# since s is deleted, there's no
# possible to access to the object
# by using s
# print(s.my_own_object)

# it's also possible to call
# that object directly;
# looks similar to a static object
# and there's no difference in Python
print(Simple.my_own_object)