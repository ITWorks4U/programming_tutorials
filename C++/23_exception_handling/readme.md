# exception handling in C++

-   an exception may appear in a critical section, like:
    -   using file stream
    -   using network stream
    -   converting a string into an integer (without using a regular expression check before)
    -   ...

-   in contrast to C programming, which doesn't comes with a basic exception handling, C++ offers you to try a block of code instruction(s); if an error may appear, then this can be catched.

```
try {
    //  some code, which can throw an exception
} catch (exception &e) {
    cerr << e.what() << endl;
}
```

### What about the C-style "exception handling"?
-   Don't use this in C++. It **may** work, but you won't be happy with that, because you must figure out which specific error has really been thrown.

### Memory management
-   What happens, when you try to do something and you're using a dynamic allocated buffer?
-   Can you ensure to release that allocated memory for sure?
    -   unlike to manage memory by your own, you should use `smart_pointers` instead

### Different types of exceptions

| exception | derived from | additional informations | example |
| - | - | - | - |
| exception | - | default exception class | - |
| bad_alloc | exception | error for memory allocation | `int* arr = new int[-1];` |
| bad_cast | exception | error by casing a type | by using polymorphic, like: `Base b; Derived& d = dynamic_cast<Derived&>(b);` |
| bad_exception | exception | when the exception class was wrong | deprecated, but still a part of C++; using an old style of C++, like: `void foo() throw(std::runtime_error);` |
| bad_typeid | exception | type ID was wrong | using a typeid on a dereferenced null pointer to a polymorphic type; `Base* ptr = nullptr; std::cout << typeid(*ptr).name() << std::endl;` |
| ios_base::failure | exception | exception class for file streams | try to open a file stream, where: file does not exist, insufficient permissions, ... |
| runtime_error | exception | commonly exception class during runtime | division by 0 |
| range_error | runtime_error | value out of range | does not been thrown automatically; this must be handled by yourself, like: `throw std::range_error("...");` |
| overflow_error | runtime_error | overflow | when a mathematical overflow has been detected by **yourself**; e. g.: a valid range is over the upper boundary, then you can use: `throw std::overflow_error("...");` |
| underflow_error | runtime_error | underflow | similar above, but just for exceeding a lower boundary with: `throw std::underflow_error("...");` |
| logic_error | exception | commonly exception class for logic errors | It is thrown explicitly by the programmer or library code to signal an error in the program logic, e. g.: check, if vector v with a size of 10 elements shall have more than 10 elements, like: ```int get_element(int index) { if index >= v.size() {throw std::logic_error("...");}}``` |
| domain_error | logic_error | error for mathematical expressions | When a function receives an argument whose value is not within the set of values for which the function is defined. Typically used for mathematical or algorithmic functions where the input must satisfy certain constraints, e. g: ```double sqrt(int number) { if (number < 0) {throw std::domain_error("sqrt: input value is negative");}}``` |
| invalid_argument | logic_error | using an invalid argument | often used, when an argument of a function / class method does not match with set of expected arguments |
| length_error | logic_error | error with the length of a set | try to resize or create a container or string with a size larger than the maximum size supported by that container, like: ```s.reserve(s.max_size() + 1);  // Trying to reserve more than max size``` |
| out_of_range | logic_error | index out of the valid scope | accessing to an element of any set, vector, string, array, ..., which does not exist |