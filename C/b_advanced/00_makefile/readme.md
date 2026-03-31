#   using a makefile for your project
-   allows you to build your application (almost) automatically without typing all required source files

####    how to use
-   usually a `makefile` can be used on Linux, macOS only
-   mingw (for Windows), **MAY** be able to use a `makefile`, too, but this is not a clean statement.

####    special operating systems
-   for Linux / macOS:
    -   by default, the command `make` is already installed
    -   if unsure, run ```whereis make```
        -   if this might not be installed on your machine, then install it within the update manager, like ```sudo apt install make```
-   for Windows:
    -   if you're able to use a `makefile` by mingw, be happy
    -   otherwise a `batch file` and also a `powershell file` exists for your own purpose