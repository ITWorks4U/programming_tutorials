#   extended function behavior
-   typically a function comes with a strict function behavior
    -   in C a function has a different behavior than in C++
        -   calling a function before this function has been defined
        -   calling a function with any amount of arguments
        -   calling a function, which takes a function for any action

### calling a function with any amount of arguments
-   even a C function is defined without any arguments, like: `void do_something() {}`, you can call this function by:
    -   `do_something();`
    -   `do_something(1,2,3,4,5);`
    -   `do_something(NULL);`
    -   `do_something("abc", "def", 123,456);`
-   because a C function without arguments is internally defined as: `void do_something(...) {}`, this allows you to add **any** amount of **any** arguments
    -   to avoid this issue, add **void** inside the brackets: `void do_something(void) {}`
        -   then this function can be called only, if **no** arguments are given
        -   in C++ this is a default state
            -   to allow to call a function in C++ with any amount of arguments, just add "..." inside the brackets

### using a function as an argument for any other function
-   allows to wrap a function for a general function
    -   reducing redundant function calls, which are almost identical

```
int add_numbers(int a, int b) {
    return a + b;
}

void dynamic_function(int (*f)(int, int)) {
    (*f)(1,2);
}

int main(void) {
    dynamic_function(add_numbers);
    return 0;
}
```