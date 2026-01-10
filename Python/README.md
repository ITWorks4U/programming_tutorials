# Python 3 tutorial

-   Python 3 is really easy to learn
-   it allows you to start to programm without any deep knowledge
-   Python is an interpreter language, which means, you don't have to do any datatype definitions
    -   every variable, here an object, can easy be defined and also reinterpreted by any other value

##  table of contents
####    1.  How to run?
####    2.  important notes
####    3.  Can these scripts run with Python 2?
####    4.  Which python 3 version is in use?
####    5.  On which operating system are these scripts runable?
####    6.  On which systems are those examples shown?
####    7.  Are additional modules (packages, libraries, ...) required?

### 1.  How to run?

-   run your python script by using the python interpreter, like:

```
    python[3.|exe] <your_python_file.py>
```
-   it depends on which OS you're working
    -   Windows usually uses `python`as a standalone expression for `python.exe`
    -   UNIX, like Linux / macOS usually differs between Python **2** and Python **3**, what Windows doesn't
        -   depending on which python **interpreter version** you're using 

-   if you want to run your python script as a standalone application, moreover for UNIX systems (Linux, macOS, ...) insert the command in the first line: `#!/usr/bin/python3`
    -   Windows don't care about this command

-   *usually, you don't need that command everytime*

### 2.  important notes
-   expressions, like condidtions, loops, functions, ... **must** be placed into a common block, otherwise on runtime the Python interpreter is going to complain
    -   furthermore, use spaces or tabs only for this certain block(s)
    -   you can also "mix" them, if those are separated into an own block

###### NOTE:
-   you also can display whitespace(s) and tab(s) (almost any editor):
    -   `Menu bar -> view -> display whitespaces (or similar expression)`

-   in Visual Studio Code (used here), go to the gear symbol (left corner)
    -   settings => in the search bar, hit "whitespace", be default the second entry `render whitespace` shall appear and set the setting to `all`
    -   bonus: hit `insert spaces` in the search bar to decide, if a tab will automatically be converted into **space(s)**, if you like
-   in this tutuoral all blocks are used with tab (4 spaces)

### 3.  Can these scripts run with Python 2?
-   short answer: **nope**

### 4.  Which python 3 version is in use?
-   used version: **3.13.7**
    -   ususally, with a lower Python version the scripts shall run fine

### 5.  On which operating system are these scripts runable?
-   Linux
-   Windows
-   macOS
-   ...

### 6.  On which systems are those examples shown?
-   Windows 11 Professional (main)
-   Raspberry Pi (pendant for "any" UNIX system)
-   some virtual machines with Lubuntu or other operating systems

### 7.  Are additional modules (packages, libraries, ...) required?
-   part 01..29: hardly, unless system modules, like random, signal, dataclass, ...
-   part 30+: yes
    -   moreover some sub projects won't run on every system
        -   those are separated for their desired operating system

-   *Finally, have fun with **Python 3**!*