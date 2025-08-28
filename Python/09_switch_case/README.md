#   switch-case in Python

-   usually, when a certain condition case is going to use, you're using multiple condidition checks:
```
    if condition [and condition | or condition, ...]:
        # code
    elif condition [and condition | or condition, ...]:
        # code
    elif ...
        # ...
    else:
        #...
```

-   Python also comes with a switch-case statement since version `3.10+`
    -   all previous versions up to `3.9` had to use a dictionary

###	Python <= 3.9
```
def switch_case(number):
    case = {
        0:  "zero",
        1:  "one",
        2:  "two",
        3:  "tree",
        4:  "four"
    }

    return case.get(number, "unknown number")

switch_case(2)
switch_case(9)
#...
```

###	Python >= 3.10

-   comes with `match` followed by `case`
    -   unlike to other languages, there's **no** `break` statement
        -   using `break` may result to an error on runtime or an undefined behavior, especially in combination with loops
    -   by comparing multiple cases for one purpose, use a single "or" => `|`
        -   can also be surrounded with brackets `()`, but do **not** separate the elements with a comma `,`, otherwise this will be interpreted as a tuple
    -   the default case is just: `case _:`
-   examples:
```
def switch_case(number):
    match number:
        case 0:
            return 'zero'
        case 1:
            return 'one'
	    case 4:
            return 'four'
        case _:
            return 'unknown number'


switch_case(2)
switch_case(9)
#...
```

-   check, if a number is even or odd
    -   uncommonly way, but this fine here
```
match number:
    case 0 | 2 | 4 | 6 | 8:
        print(f"{number} is even")
    case 1 | 3 | 5 | 7 | 9:
        print(f"{number} is odd")
    case _:
        pass
```

-   wrong way to do this:
```
match number:
    case (0,2,4,6,8):
        print(f"{number} is even")
    case (1,3,5,7,9):
        print(f"{number} is odd")
    case _:
        print("Oops...")
```