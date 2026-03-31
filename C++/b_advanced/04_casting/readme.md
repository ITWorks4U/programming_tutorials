#   Casting in C++
-   sometimes it's required or recommended to convert a data type into an another type to work with
-   you could use:
    -   casting with C-style (hardly recommended)
    -   casting with C++-style

### casting with C-style
-   assuming, you want to convert an integer value into a double value
```
int i_number = 100;
double d_number = (double) i_number;
```
-   on debugging this is harder to read and detect for a possible error

### casting with C++-style
-   same assument like above
```
int i_number = 100;
double d_number = static_cast<double>(i_number);
```
-   on debugging it's much easier to detect an error
    -   doesn't mean, that this makes your life easier for now ;-)


### different ways for casting

| casting | description | where uzsually to use |
| - | - | - |
| `static_cast` | convert a primitive data type, like `int`, `float`, `double` into an another primitive data type | convert a primitive data type into an another |
| `dynamic_cast` | convert a class instance for an another inherited or super class | by using polymorphism |
| `reinterpret_cast` | allows you always to cast a type into another type, where the compiler might not compile the program | often used for raw pointers, but use this with care |
| `const_cast` | allows you to cast a const* into another type and vice versa; hardly used | if really in use, then use this with care |

>   **NOTE**:   There're some more casts, depending on the C++ version, but those are not listed here.