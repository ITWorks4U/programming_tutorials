#   multi processing
-   allows to run multiple processes at the same time
    -   depending on which operating system(**OS**) is in use the creation for sub processes is also different

>   **NOTE**:   Don't mix sub processing with threads. Those have similar effects, but are quite different.

### basic informations
-   on a successful creation:
    -   a new memory loadout for the new process has been created
    -   depends on its super process
        -   if the super process terminates, usually the sub process may also be terminated
    -   a process can be set up to an indepented process
        -   depends on the used OS
    -   the main process can wait for the sub processes termination

### examples
-   often in use for critical resources
    -   take care not to have a softlock
-   I/O handling
-   serial communuication, e. g.: UART
-   network communication
-   pipes
-   ...

##  difference between Windows and UNIX
### Windows
-   `CreateProcess()` to create a new process
-   `CloseHandle()` closes the allocated memory for the already terminated sub process

### UNIX
-   `fork()` to create a new sub process
    -   return a number between `<0,0,>0`, where:
        -   `<0`:   any error
        -   `0`:    successfully child process
        -   `>0`:   parent process
>   **NOTE**: `fork()` should **never** be called multiple times, because every fork can create a new sub process and this causes a horrible "snowball effect".
-   unlike to Windows there's no need to release the memory from the sub process