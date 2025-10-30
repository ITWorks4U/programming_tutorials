#   creating your own library
-   allows you to use your own library for your projects without rewriting objects, functions, data container, ...
-   loading functions, ... dynamically and on every operating system

##  contents
-   library_maker/
    -   an example to build and offer a library
    -   using `makefile`(UNIX) or a Windows builder
        -   the library will be copied into run_example/ folder  
-   run_example/
    -   contains a main only, which dynamically loads certain functions from the library itself
        -   without using the header file(s), even when these is/are known

### important notes
-   on a Windows system a `*.dll` file will be used
    -   on an another operating system this `*.dll` file may unable be in use
-   on an UNIX system it may be:
    -   `*.so` (Linux)
    -   `*.dylib` (macOS)
-   to make sure to build the library correctly, use the build script, like `makefile` or `makefile.bat` or `makefile.ps1` 