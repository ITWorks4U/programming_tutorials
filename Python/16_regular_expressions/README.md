#   Regular expressions

-   allows you to filter any expression for a certain purpose:
    -   check, if an input is a number (before using it and causes an undefined behavior)
    -   check, if an e-mail-address is valid
    -   ...

### Are regular expressions hard to use?

-   yes, but actually, no
    -   when you know how to use them, then these are helping you to handle situations much more easier for you

### use regular expressions

-   `re` module
-   match function returns a `Match` object to work with or `None` for mismatch
    -   since a simple check, if this `Match`object exists is in use, this proves, that an expression has passed trough the filter

-   example:
```
from re import match

filter = r"^(-|\+)?[0-9]+$"

expressions = ("123", "Is mayonnaise also an instrument?", 2390472397492984927429648236, "0", "-10", "+73", [], True, "Hello regular expression in python 3!")

for e in expressions:
    try:
        if match(filter, e):
            print(f"{e}: is a number")
        else:
            print(f"{e} is a not number")
    except TypeError as te:
        print(f"error ({e}) detected: {te.args[0]}")
```