#   math operations with C
-   allows to use math functions, like:
    -   sine
    -   cosine
    -   power
    -   square root
    -   ...
-   accessing to constants, like pi, e, ...
    -   on a Windows machine `M_PI` doesn't exist and this must be defined by hand

####    required module(s)
-   `math.h`(C only)
-   `cmath` (C++ only)

>   **NOTE**:   On an UNIX system by using any math function the compiler must be combined with `-lm`, otherwise the application can't be build. On a Windows machine this is not required to do.