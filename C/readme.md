#	C programming

- learn how to use C
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
-   you need a C compiler, like gcc
    -   Windows: ```gcc.exe```
        -   by default `mingw` helps you out
        -   *By using Visual Studio some samples does not work correctly!*
    -   UNIX/Linux/macOS: ```gcc```
        -   by default gcc is installed on your system

### How to figure out, if gcc[.exe] exists?
-   Windows: ```where gcc.exe```
-   Linux: ```whereis gcc```

### How to run
-   usually, your source file must be compiled first: ```gcc[.exe] [additional flag(s)] <source file(s)> -o <output_file_name>```
    -   Windows is using `.exe` by default
    -   In Linux `*.run` is in use here

### Can C++ also used here?
-  even C and C++ shares a bunch of functionalities, it's not recommended to use a C++ compiler to run those samples
    -  it may happen, that your application(s) may not work correctly or returns a different result rather than C

##### Attention:
-   Some samples does not work (correctly) on Windows, because all of those source files were written in Linux (Mint 21 Cinnamon).