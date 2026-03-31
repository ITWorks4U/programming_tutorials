#   first written application
-   simple to use without care of any side effects
    -   yeah, there're more side effects as you can count ;-)

-   `printf()`
    -   print a formatted text to the console
    -   the formatted output **must** be the correct one for the desired value, otherwise an undefined behavior appears
        -   often silently "handled", but this doesn't mean, that this won't release any (other) side effect
    -   make sure to add a newline character `\n` to be able to see the next instruction or the promt line to the next line

-   `puts()`
    -   put a string to the console, like printf()
    -   doesn't need the newline character, because this is a default behavior

##  requirements
-   a C compiler, e. g.:
    -   mingw (Windows)
    -   visual studio (comes more with a C++ compiler, but works also (often) with C code)
    -   a UNIX system usually comes with a C compiler, like **gcc**

### How to build
-   use:    `gcc[.exe] the_first_application.c`
    -   **gcc.exe** on a Windows system
    -   **gcc** regular on any UNIX system, like Linux, macOS, ...
-   by using `-o [name]` you can also determine how the application output has to be named
    -   Windows:    typically a **.exe** file is in use
    -   UNIX:       typically this is **.out**, **.run**, ...

>   NOTE:   Without using **-o** flag, the output is automatically named with **a.exe** (Windows) or **a.out** (UNIX)