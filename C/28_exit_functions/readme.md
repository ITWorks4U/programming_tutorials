#   exit an application
-   usually, you don't need to exit an application by your own, however, sometimes this is required to do
    -   releasing allocated memory automatically before the application is going to terminate
        -   **if and only if** no abnormal termination is in use
-   depending on the used operating system (**OS**), some header files are addionally required to include

>   **NOTE**:   The return statement (in the main) automatically calls **exit()**, follows by **_exit()**.

####    different ways to terminate
| function | effect| additional informations |
| - | - | - |
| atexit | register a clean up sequence before termination | register up to 32 different instructions |
| exit(x) | terminate the application by given x value (same effect by return (main only)) | calls the clean up function(s) first, then **_exit(x)** is called |
| _exit(x) | real termination of the application | does **not** clean up any resources |
| abort()| abnormal termination of the process | does **not** clean up any resources |
| assert(x) | assuming, that condition x is true; if yes, then the next instruction can be reached; if false, the application terminates abormally | on failure **no clean up** of any resources is going to to; similar to **abort()** |
| at_quick_exit()  | same action like atexit() | - |
| quit_exit(x) | same action like exit() | calls the clean up function(s) first, which has been registered by  **at_quick_exit()** only; function(s) by used *atexit()* are **not** touched      |
| _Exit(x) | same action like _exit(x) | same behavior to _exit(x) |

### libraries to use
-   `stdlib.h`
-   `unistd.h`  (for UNIX only)
-   `assert.h`  (for assert() function only)   