#   using global variables / objects

-   usually, the definition of a variable / an object on top of your code it's called a *"global variable"*
    -   on any time and on any situation your global statement can be read and also modified
-   Python 3 strictly differs global and local variables / objects
-   mostly you don't realize that, but sometimes this is really important to know when to modify a global object in an own section

### reading a global value
-   similar to other languages, you can access from anywhere to your global variable / object
    -   in Python this allows you to read that value only

```
expression = "global expression"

def surprise() -> None:
    print(f"in function call: {expression}")

print(f"before function call: {expression}")
surprise()
print(f"after function call: {expression}")
```

### update a global value
-   to update that value, you must use the `global` keyword

```
expression = "global expression"

def surprise() -> None:
    global expression
    expression = "abc"
    print(f"in function call: {expression}")

print(f"before function call: {expression}")
surprise()
print(f"after function call: {expression}")
```

-   useful, for:
    -   easily access to an object
    -   similar to C with `volatile`, but this also causes nasty surprises
    -   in combination with threads

### Why not to use global variables / objects?
-   this is hard to debug
-   offers new ways for pitfalls
-   in classes this is not necessary