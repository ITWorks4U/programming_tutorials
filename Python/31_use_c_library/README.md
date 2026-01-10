#   The combination of Python and C

-   sometimes it's required to use a function, often written in C, for Python
    -   boosts up code, which are (horribly) too slow for Python itself
    -   often in use for hardware, which uses a C library
-   since Python does not comes with data types, it's hard to understand which type from a C library can be used correctly for python and vice versa

-   contains:
    1.  use a C function, which prints a text to the console
    2.  use a C function to calculate the square multiplication for 1,000,000 numbers
    3.  use a C function to sort 250,000 random numbers with bubble sort => O(n²)!

###	need to know

-   using ctypes module (shall already comes with Python)
-   before you start, make sure to let build your library
    -   go into `library_collection` folder and run `makefile` (for UNIX systems) or `makefile.bat` (for Windows)
    -   the certain library will be copied to the super folder and can be used there
-   not tested, if a library with C++ instructions can also be used