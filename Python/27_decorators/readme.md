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

### How to use
-   `@decorator`expression on top of a function / class method
    -   where "decorator" is not a fixed expression
    -   you can also use any expression
    -   comes with a nested function, often called `wrapper`

-   this allows you write a code once and use this multiple times

####    example
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