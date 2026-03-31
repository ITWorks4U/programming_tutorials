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

### difference between the used operating systems

| operating system | file extension | additional informations |
| - | - | - |
| Windows | `*.dll` | On an another operating system, like UNIX, this `*.dll` file may unable be in use. |
| Linux | `*.so` | You can also build a `*.dll` file, however, this won't work for a Windows machine. Furthermore you also can use an archive file `*.a` |
| macOS | `*.dylib` | Not clear, if the same behavior with a `*.dll` file takes action. |

>   **NOTE**:   Make sure to build the library correctly. Use the build script, like `makefile` or `makefile.bat` or `makefile.ps1` 