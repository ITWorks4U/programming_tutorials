#   functions
-   allows to move code into an own block, which can be called over and over again
-   similar to loops (see: chapter 7)

>   **NOTE**:   Functions in C++ have a different behavior than in C.
>>  -   in contrast to C you can't call a function, before the function has been defined
>>  -   a function in C++ can only be called depending on the number of given arguments
>>      -   it's also possible to call a function with any amount of arguments like in C
>>          -   will be handled in **section 31**
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

cout << add_numbers(10,20) << endl; 
``` 