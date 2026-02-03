#   Socket communication

-   allows to communicate between two or more remote computers
-   ideal for network communication
    -   also ideal to communicate between two systems, which are not written in the same language
        -   the server might be written in python, whereas the client might be written in C#

### What's to see:
-   local connection between a server and also a client
    -   the server is able to listen to the local address (127.0.0.1, "localhost") or to a desired IPv(4|6)-address
    -   the client (single client only) connects to the server
        -   multiple clients are not supported here
            -   can be managed by using an own background thread
        -   those will be blocked until the previous client(s) disconnected
    -   the client's message will be echoed back by the server

| file | location | description |
| - | - | - |
| server.py | main | server connection (run this first) |
| client.py | main | client connection |
| constants.py | config | contains connection settings for both applications |
| log_events.py | div | offers an isolated logging system for both applications |
| signal_handling.py | div | only in use for `Ctrl+C` (may also handle any other incoming signals)|

### How to use:
-   open two command line interfaces / terminals
    -   one for server
        -   launch `python[3|.exe] server.py`
    -   one for client
        -   launch `python[3|.exe] client.py`