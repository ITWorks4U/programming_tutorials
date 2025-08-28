#   That was not supposed!

-   Misakes happens. Often not intended, but sometimes these are on purpose.
-   Imagine, you're reading from the keyboard or from a file and want to interprete the current word as an integer.
-   Usually, you're using `int(string_expression)` to convert it into a correct type, however, when your __string_expression__ is not covered by numeric characters `[0-9]`, then an error is going to raise.
    -   this can be handled by using use regular expressions

### How to handle exeptions

```
try:
    # code you might think, that this could or will cause an error 
    # often called: CRITICAL AREA
except [Exception [as e]]:
    # catching your (specific) exception and receive a detailed error, if given, to see, what realyl happend
finally:
    # always executing code; no matter, if an exception has been raised before or not
    # this is the last instruction of your block
```

in some cases you might also see this:
```
try:
    #...
except:
    #...
else:
    # code, which executes only, if no exception has been raised
    # this style is deprecated in modern python versions and shall
    # no longer be used
```

###	An exception is like an interrupt, right?

-   no, an exception and an interrupt are never the same
    -   in some cases those might share similar properties, but these are still different
    -   signals must be handled in a different way
-   typical nooby "exception handling" for `SIGINT` (Ctrl + C):

```
try:
    while True:
        # something to do here, where Ctrl + C has been
        # pressed
    
except KeyboardError:
    # something to "handle" this "exception"
```

| kind of error | when to appear | can be repeated
| - | - | - |
| exception | on a specific piece of code, e.g.: reading a file, which does not exist | yes |
| signal | anywhere at any time | not always |