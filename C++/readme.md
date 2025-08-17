#	C++ programming

- learn how to use C++
    - basic usage
    - decicion making
    - loops
    - debugging
    - ...
- can be used with UNIX/Linux, macOS, Windows
    - create files / directories
    - handling I/O
    - ...

### Requirements
-   you need a C++ compiler, like g++
    -   Windows: ```g++.exe```
        -   by default `mingw` helps you out
        -   *By using Visual Studio some samples does not work correctly!*
    -   UNIX/Linux/macOS: ```g++```
        -   by default g++ is installed on your system

### How to figure out, if g++[.exe] exists?
-   Windows: ```where g++.exe```
-   Linux: ```whereis g++```

### How to run
-   usually, your source file must be compiled first: ```g++[.exe] [additional flag(s)] <source file(s)> -o <output_file_name>```
    -   Windows is using `.exe` by default
    -   In Linux `*.run` is in use here

### Can C also used here?
-   even C and C++ shares a bunch of functionalities, it's not recommended to use a C compiler to run those samples
-   a C compiler **may** be able to compile a **C++** file, as long as, no **instructions for C++** were be found
    -   works only, if a C++ file only has raw C instructions