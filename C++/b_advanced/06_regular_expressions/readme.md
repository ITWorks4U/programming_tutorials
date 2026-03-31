#   Regular expressions in C++

-   allows you to filter any expression for a certain purpose:
    -   check, if an input is a number (before using it and causes an undefined behavior)
    -   check, if an e-mail-address is valid
    -   ...

### difference to POSIX regular expression
-   POSIX regex are available on an **UNIX** system only
    -   maybe you've luck and can also use those POSIX regular expressions on a Windows machine

### other external libraries
- PCRE2 (https://www.pcre.org/) => ```<pcre2.h>``` (implemented examples, but not tested)
        - ...

##  working on Windows
-   depending on, if you're using C or C++ (e. g.: Visual Studio), you may work on a similar way with regular expressions:
    -   ```<regex>```
    -   ```<boost/regex.h>```
-   outside of Visual Studio (e. g.: **mingw**) you might use a library to work with regular expressions, like **PCRE2**
    -   or you redirect an expression check into a **python** file and figure out that result instead