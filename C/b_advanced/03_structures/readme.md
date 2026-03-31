#   Structures, Unions, Enumerations

-   allows you to store data (almost of any kind) into a storage "class" to work with
-   in C only ```struct```, ```union``` and ```enum``` exists
    -   C++ also comes with ```class```, ```enum class``` (are not fully handled here)

### struct

-   storage holder for any kind of datatypes
-   each member has its own memory to work with
-   commonly used for any storage attempt
-   a struct can also hold its own functions, like C++, however, this is a hard piece of code
    -   for more details check chapter 36

### union
-   storage holder for any kind of datatypes
-   in contrast to a struct each member shares their memory with the biggest data type
-   hardly used, except for embedded systems or in combination with a struct

### enum
-   contains an enumeration of integers only
-   often used to represent a state
    -   logging
    -   system status
    -   ...
-   **must not** contain multiple states
    -   even when more than one enum exists, an another enumeration **must not** have an identical expression
    -   in contrast to C++, which comes with ```enum class``` there's possible to define multiple expressions
    -   in contrast to C++, you can do operations in C, which are invalid in C++