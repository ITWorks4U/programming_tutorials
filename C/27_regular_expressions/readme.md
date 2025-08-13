#   Regular expressions

-   allows you to filter any expression for a certain purpose:
    -   check, if an input is a number (before using it and causes an undefined behavior)
    -   check, if an e-mail-address is valid
    -   ...

##  working on Windows
-   usually, POSIX regex is **not** available on Windows by default
-   depending on, if you're using C or C++ (e. g.: Visual Studio), you may work on a similar way with regular expressions:
    -   ```<regex>```
    -   ```<boost/regex.h>```
-   outside of Visual Studio (e. g.: **mingw**) you might use a library to work with regular expressions
    - use an alternative, like:
        - PCRE2 (https://www.pcre.org/) => ```<pcre2.h>``` (implemented examples, but not tested)
        - ... 

##  working on UNIX/Linux/macOS
-   using **POISX** regex
    -   shall also work with macOS (never tested)

#### NOTE:
> The following examples are written with POSIX regex. PCRE2 is implemented as well, however, this has not been tested.