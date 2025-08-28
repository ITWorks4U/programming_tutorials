##  The purpose of functions
-   write a code once only and let it execute again and again and again
-   for a better maintenance and code overview
-   basic function definition:
```
def function():
    # statement(s)
```

######  attention
-   before a function is able to call, it __MUST__ be defined before
    -   similar to **C++**

```
def function():
    # ...

# call that function
function()
```

-   a function may have arguments, which are required to call the function
    -   in that case it's required to call this function with the correct amount of arguments (1)
    -   only necessary, if the function arguments doesn't have a default value (2)

```
#(1)
def function(a, b, c):
    # ...


# call that function with the expected correct
# amount of arguments
function(1,2,3)
```

```
#(2)
def function(a = 10, b = "AAAA", c = True):
    # ...

# call the function without care the arguments
function()

# call the function with arguments (linear order only)
# for c = True => this is still "True"
function(100, "fff")

# call the function to modify the arguments
# no need to handle those arguments in the identical order
function(a = "FF", b = False, c = 99)
```

-   python does **not** comes with a function / class method overload
    -   if a function / class method is redefined, then this new function / class method will be used instead

```
def function(a = 10, b = 20):
    # ...


def function():
    # ...

# attempt to call the first function results to an error
# function(a = "Epic", b = "Fail")
```

-   since in Python no data types exists, you can use ANY kind of arguments
    -   be careful, because if you don't mind, this may cause an undefined behavior on runtime

-   in general a function may have a return value
    -   in Python you can also return an another type in contrast to the forced expectation

```
def function(a, b) -> int:
    if a < 0:
        return False

    if b > 10:
        return None


    return a + b
```