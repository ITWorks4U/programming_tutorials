# Python 3 tutorial

-   Python 3 is really easy to learn
-   it allows you to start to programm without any deep knowledge
-   Python is an interpreter language, which means, you don't have to do any datatype definitions
    -   every variable, here an object, can easy be defined and also reinterpreted by any other value

### How to run?

-   run your python script by using the python interpreter, like:

```
    python[3.|exe] <your_python_file.py>
```
-   it depends on which OS you're working
    -   Windows usually uses `python`as a standalone expression for `python.exe`
    -   Linux usually differs between Python **2** and Python **3**, what Windows doesn't
        -   depending on which python **interpreter version** you're using 
        
-   sometimes it may be important to run your script as a standalone "application"
-   in that case a shebang command in the first line is required: `#!/usr/bin/python3`
    -   moreover in use for Linux / macOS
    -   Windows won't use this

-   *usually, you don't need that command everytime*

### important notes
-   by using blocks, like conditions, loops, functions, ... it's required to know, which command/s is/are part of the block
    -   take a look in the certain section folders, like:
        -   decicion making
        -   loops
        -   functions
        -   ...
-   in contrast to any other language, it's neccessary to know what kind of **indention** you're using
    -   there're two of them:
        -   (1) using `space bar(s)`
        -   (2) using `tab(s)`

-   because Python won't agree a mix of both on one block, you must use one of them
    -   you can also "mix" them, if those are separated into an own block

###### note:
-   you also can display whitespace(s) and tab(s) (almost any editor):
    -   `Menu bar -> view -> display whitespaces (or similar expression)`

-   in Visual Studio (used here), go to the gear symbol (left corner)
    -   settings => in the search bar, hit "whitespace", be default the second entry `render whitespace` shall appear and set the setting to `all`
    -   bonus: hit `insert spaces` in the search bar to decide, if a tab will automatically be converted into **space(s)**, if you like
-   in this tutuoral all blocks are used with tab (4 spaces)


-   *Finally, have fun with **Python 3**!*

### Can these scripts run with Python 2?
-   nope

### Which python 3 version is in use?
-   these scripts were written with the current python version (3.13.7), but these shall also be working with a lower python version

### On which operating system are these scripts runable?
-   Linux
-   Windows
-   macOS
-   ...

### Are additional modules (packages, libraries, ...) required?
-   basicly, no
    -   some sections requires additional modules, but those are marked