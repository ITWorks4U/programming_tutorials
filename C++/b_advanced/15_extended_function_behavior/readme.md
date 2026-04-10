#   Extended function behavior
-   usually in C++ you're unable to call a function / class method, when the number of arguments or the types won't match
    -   in C this works "fine"

#####   example:
```
void do_something() {
    // ...
}

do_something();             //  works fine
do_something(1,2,3,4,5);    //  nope
do_something(&vec);         //  Seriously?
```

## Why this works in C, but not in C++
-   a function / class method in C++, like in other languages, strictly defines how the arguments, if any, are in use
    -   in C this function above is internal defined as: `void do_something(...) {}`
    -   the three dots tells the C-compiler, that any amount of arguments can be used
    -   this "feature" has been removed in C++
        -   unless, you'll enable this, but this also causes nasty side effects

### using a function with any amount of arguments
-   sometimes this is required
-   more in C
    -   `int printf(const char *format, ...);`
    -   ...
-   uses macro expressions, like:
    -   `va_list`
    -   `va_arg`
    -   `va_end`

>   **NOTE**:   [Take a look to C programming chaper b:9](https://github.com/ITWorks4U/programming-tutorials/tree/main/C/b_advanced/09_strange_function_behavior)

### Using a function as an argument for an another function
-   more in use in C
    -   allows to use a function as an argument to call that pointed function to do an action

```
int add_numbers(int a, int b) {
    return a + b;
}

void dynamic_function(int (*f)(int, int)) {
    int a = 5;
    int b = -3;

    (*f)(a, b);
}

int main() {
    dynamic_function(add_numbers);

    return 0;
}
```