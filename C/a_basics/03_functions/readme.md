#   functions
-   allows to move code into an own block, which can be called over and over again
-   similar to loops (see: chapter 7)

>   **NOTE**:   Functions in C have a different behavior than in C++.
>>  -   you can call a function, before the function has been defined
>>  -   you can use any amount of arguments, even no arguments are given
>>      -   will be handled in **section 25**
>>  -   a function must have a return statement, when the datatype is **not** *void*

### definition of a function
`<datatype> <function_name>(<any arguments with a certain data type>) {}`
-   like:
```
void do_something() {

}

int add_numbers(int a, int b) {
    return a + b;
}

//  calling:
do_something();
do_something();
do_something();
do_something();
do_something();

printf("%d\n, add_numbers(10,20));
``` 