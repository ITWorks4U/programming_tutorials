#   math operations with C++

>   **NOTE**:   The math operations are made with C-libraries, like `math.h`, `float.h`, ...
>>  -   It may happen, that your application might be handled like a **threat**, because these are old functions with backdoors and C++ may handle the usage a bit different rather than C.
>>  -   On an UNIX system by using any math function the compiler must be combined with `-lm`, otherwise the application can't be build. On a Windows machine this is not required to do.

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
-   `cfloat` (C++ only for using math functions with floating point values)