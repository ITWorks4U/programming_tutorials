#   Structures, Unions, Enumerations

-   allows you to store data (almost of any kind) into a storage "class" to work with
-   in C only ```struct```, ```union``` and ```enum``` exists
    -   C++ also comes with ```class```, ```enum class```

### struct

-   storage holder for any kind of datatypes
-   each member has its own memory to work with
-   commonly used for any storage attempt
-   a C-struct can also hold its own functions, like C++, however, this is a hard piece of code
    -   for more details check: [chapter 36 C Programming](https://github.com/ITWorks4U/programming_tutorials/tree/main/C/36_oop_in_C)
-   a C++-struct offers a bunch of different settings
    -   you can initialize up to one element in the structure
    -   are often used to store data without visibilit reasons or for inheritance
        -   every member, function is set to `public`
        -   member(s), function(s) can also set to `private` or `protected`

### union
-   storage holder for any kind of datatypes
-   in contrast to a struct each member shares their memory with the biggest data type
-   hardly used, except for embedded systems or in combination with a struct
-   C++ can also use an union block, but it's still a rarly used data structure
    -   you can also initialize up to one element in the structure

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

### enum class
-   C++ exclusive enumeration variant
-   offers to store a single state in different enumeration classes without triggering a compiler error

### class
-   for OOP
-   in contrast to a `struct` every member, method (class function), ... is set to `private` by default
    -   public access for outside: `public`
    -   for inheritance / polymorphic: `protected` (can also be `public`)
    -   more details in the section **20_oop**