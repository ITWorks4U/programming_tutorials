#   Socket communication

-   offers a communication of a server and a client
    -   can be a local communication
    -   can also be a communication over network
        -   tested with a local computer and a Raspberry Pi as a remote computer
            -   `server (Windows) <=> client (Windows)`
            -   `server (Windows) <=> client (Raspberry Pi)`
            -   `server (Raspberry Pi) <=> client (Raspberry Pi)`
            -   `server (Raspberry Pi) <=> client (Windows)`

-   works on Windows, as well as, on an UNIX system, like Linux
    -   not tested on a macOS, but shall also run fine

### important informations
-   this application has been written in C only and shall be build with a C compiler only
    -   a C++ compiler may work, too, but it may happen, that any functions could return an undefined behavior
-   this sample comes with a config file
    -   located on /config folder
        -   if the config file doesn't exist or an error may appear, then a default setting is in use instead
-   on unix/ folder the server and client has been written for any UNIX system
    -   build the server / client by using the `makefile` with the certain target
-   on windows/ folder the server and client has been written for a Windows system
    -   build the server / client by using the `build.bat` with the certain target

####    server
-   once started it runs until `Ctrl + C` has been pressed
    -   no signal handling is in use here
-   handles a single client connection only

####    client
-   runs once
    -   after sending and receiving a message, if no error has been dected before, the application terminates