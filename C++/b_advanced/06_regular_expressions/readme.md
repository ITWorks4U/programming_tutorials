#   Regular expressions in C++

-   allows you to filter any expression for a certain purpose:
    -   check, if an input is a number (before using it and causes an undefined behavior)
    -   check, if an e-mail-address is valid
    -   ...

##  C++ only
-   depending on, if you're using C or C++ (e. g.: Visual Studio), you may work on a similar way with regular expressions:
    -   ```<regex>```
    -   ```<boost/regex.h>```

##  difference to C programming
-   in C programming regular expressions are used with **POSIX** style
    -   most used for **UNIX**, like Linux, macOS, ...
    -   Windows may not support this
-   for **Windows**:
    -   use an external library, like: **PCRE2** (https://www.pcre.org/) => ```<pcre2.h>```
    -   mingw does not support this library by default

-   => [C programming chapter b:11](https://github.com/ITWorks4U/programming-tutorials/tree/main/C/b_advanced/11_regular_expressions)

