#	Memory management in C/C++

-   by using memory management, you don't often have a chance to avoid raw pointers
    -   in C this is fundamental
    -   in C++ you should use **smart_pointers** instead

-   with pointers you're able to access to addresses instead of the values, thus your workflow can be much more faster than expeced, however, by using pointers it also results a *huge risk*. You can also run to the next wall if you don't mind

###	Are pointers works fine in C, as well as, in C++?
-   not really
-	pointers should be used in **C** only! **C++** may also work with raw pointers, but this is **NOT** recommended
    -   C++ wasn't designed for working with pointers and it may result different a behavior in contrast to C
    -   so it's not clearly known, if C++ can also work with C pointers 
        -   except for some instructions => syntax error in C++

### Purpose of using pointers
-   in contrast to an array, which defines a fixed size for a certain data type and this is **static** a pointer can be used **dynamically**, however, **YOU** must care of the created memory, because it's also **YOUR** job to release the allocated memory, when this is no longer required

### create pointer
-   in C / C++ use a function ,like ```malloc(), calloc(), realloc(), [valloc(), ...]```
    -   usually ```malloc()``` and ```calloc()``` are often in use
    -   ```realloc()``` is in use only to add additionaly free memory
    -   all those functions return void*
        -   in C++ you **must** cast them to the desired data type
-   in C++ you can also use: ```new```

### remove allocated memory
-   in C / C++ use the function ```free()```
-   in C++ only, you can also use ```delete```

###	Are arrays and pointers the same?
*No. Arrays and pointers have a similar usage and/or behavior, but arrays and pointers are **never** the same!*

###	Is the pointer handling still the same on different machines?
*No. When you're using pointers on a 64 bit machiche (no matter which OS you're working with), the results may differ to a 32 bit machine as well as for a 16 bit machine etc.*

### size of a pointer
|  OS architecture  |  size of a pointer  |
|-------------------|---------------------|
|  64 bit           |  8 bytes            |
|  32 bit           |  4 bytes            |
|  16 bit           |  2 bytes            |
|  8 bit            |  1 byte             |

###	content to see
-	basic concept of memory management
    -   simple memory management examples
    -	undefined behavior examples
    -   memory leak
-   pointer arithmetic
    -   may have a similar usage like the variable's content arithmetic, but the results differs
-   smart pointers
    -   *shall be used for C++ only*
    -   autmatically releasing allocated memory, when this is no longer required
        -   even in case of any error => with raw pointer(s), this is very hard or impossible
-   advanced usage
    -   different ways to allocate memory
    -   overloading your current RAM => **only for educational purpose**
    -   check, if a pointer is located on the stack or the heap