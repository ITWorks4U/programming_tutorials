#   Speed up your code with Cython

-   Cython can be used to speed up code
    -   more in use, if a complex algorithm takes too much time for raw Python code
    -   the code will be converted into a C code, but this does not result into a C source file

### required modules
-   setuptools
    -   `pip[3|.exe] install setuptools`
    -   `pip[3|.exe] install Cython`
        -   on a UNIX system it may happen, that these modules can't be installed
        -   in that case use `sudo apt install python3-[module_name]` instead

### example
-   use bubble sort (time complexitiy of O(n²)) to sort 250,000 random numbers
    -   with raw Python code this is a **bad** and **dumb** idea
        -   this may takes many minutes or up to some hours
    -   with a C library, see chapter 28, this tooks few minutes
    -   with Cython, this also takes few minutes

### requirements
-   python-extendable file `*.pyx`
    -   contains code, which shall be converted into Cython code
-   setup.py
    -   required to let build the python-extendable file(s)
-   main.py
    -   load the cython file and have fun

####    command and results
1.  run that command:  `python[3|.exe] setup.py build_ext --inplace`
2.  in your folder path a build folder is going to create, followed by some `*.pyd` file(s) and C source file(s)
3.  import the cythonized module in a python file
4.  have fun