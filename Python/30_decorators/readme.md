#   Using decorators
-   allows you to use functions / class methods for a specific purpose
-   imagine, you want to check, how long procedure A takes, same for procedure B, C, ...
    -   instead of writing a time measurment for each procedure, this can be wrapped into a decorator
    -   a decorator is just like a function in C/C++, which takes a function as an argument to call that general function
        -   for more details, take a look to C programming, chapter 25: `25_02_function_behavior.c`
-   decorators are well used for:
    -   logging
    -   benchmark
    -   authentification
    -   ...

### What to use
-   `@decorator`expressin on top of a function / class method
    -   where "decorator" is not a fixed expression
    -   you can also use any expression
-   the general function / class method with a nested function called `wrapper`
-   the function / class method, which is marked with the `@decorator` expression will be used as an argument to the decorator function / class method itself to let say:
    -   "Hey, use the `greet()` function as func argument to do stuff."
    -   "By the way, there's also the `how_are_you()` function, which does the same thing."

```
# origin source: https://www.geeksforgeeks.org/python/decorators-in-python/

def decorator(func):
    def wrapper():
        print("Before calling the function.")
        func()
        print("After calling the function.")
    return wrapper

@decorator # Applying the decorator to a function
def greet():
    print("Hello, World!")

@decorator # same here
def how_are_you():
    print("How are you?")

greet()
how_are_you()
```

-   time measurment example:
```
from time import perf_counter
from datetime import timedelta

_MAX_COUNTER = 100000000

def time_measurment(func) -> None:
    def wrapper():
        start = perf_counter()
        func()
        end = perf_counter()

        print(f"total time amount for function {func.__name__}: {timedelta(seconds=(end-start))}")
    #end function

    return wrapper
#end function

@time_measurment
def func_0() -> None:
    ctr: int = 0

    while ctr != _MAX_COUNTER:
        ctr += 1
    #end while
#end function

@time_measurment
def func_1() -> None:
    for _ in range(_MAX_COUNTER):
        pass
    #end for
#end function

if __name__ == "__main__":
    func_0()
    func_1()
#end entry point
```

### decorator function with arguments
-   to realize that with any arguments, use:
```
def decorator_name(func):
    def wrapper(*args, **kwargs):
        print("Before execution")
        result = func(*args, **kwargs)
        print("After execution")
        return result
    return wrapper

@decorator_name
def add(a, b):
    return a + b

print(add(5, 3))
```