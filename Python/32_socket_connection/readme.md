#   Socket communication

-   allows to communicate between two or more remote computers
-   also ideal for network communication

### What's to see:
-   local connection between a server and also a client
    -   the server is listening to the local address (127.0.0.1)
    -   the client (single client only) connects to the server
        -   multiple clients are not supported here
        -   those will be blocked until the previous client(s) disconnected
    -   the client's message will be echoed by the server

| file | description |
| - | - |
| server.py | server connection (shall be run first) |
| client.py | client connection |
| constants.py | contains connection settings for both |
| signal_handling.py | for incoming signals |

### How to use:
-   open two command line interfaces / terminals
    -   one for server
        -   launch `python[3|.exe] server.py`
    -   one for client
        -   launch `python[3|.exe] client.py`