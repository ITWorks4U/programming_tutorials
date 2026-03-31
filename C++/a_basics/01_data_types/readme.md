#   data types in C (and also in C++)

-   numerical types
    -   integer
    -   floating point

>   **NOTE:** Both also comes with a signed and unsigned variant, where unsigned only represents the positive numbers from 0..n and holds a higher value than signed numbers.

-   character types
    -   single character
    -   C-string
        -   in raw **C++** rarely in use
        -   don't mix them with a regular string
    -   String
        -   an own datatype, which is similar to a C-String, nut comes with own features
>   **NOTE**: Be careful, when you convert a string into a C-string. It comes with a different behavior and you will waste time in debugging.

    -   boolean type
        -   contains true or false only
        -   similar to 1 (or any other number except 0) and 0 (for false only)