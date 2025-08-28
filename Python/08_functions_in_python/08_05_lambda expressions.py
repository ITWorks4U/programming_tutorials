# Lambda expressions are anonymous functions,
# which can be called at any time everywhere
# without defining a function.

result = lambda r: r+r
print(result(10))

# explanation:
# - lambda is an anonymous function, which allows
#   us to call a function without defining a function
#   by our own
#
# lambda r:
# - r = argument to work with (has any type)
# : r+r:
# What shall be do with argument r?
# => returns the sum of r+r
#
# the result will be moved to our result object

# attention:
# when more than one argument is defined,
# this must be used as well when calling
# the lambda function
meme = lambda a, b: f'This function goes {a}{b}{b}{b}{b}{b}{b}!'
print(meme(a='b', b='r'))

# doesn't work, because b argument is missing:
# print(meme(a='b'))

# ...unless you're defining the arguments
# with a value
meme = lambda a='b', b='r': f'This function goes {a}{b}{b}{b}{b}{b}{b}!'
print(meme())