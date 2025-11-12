#   Socket communication in C++
-   allows to communicate with other systems, like PC, embedded systems, ... over TCP / UDP
    -   comes with a server and a client
    -   the server can listen to any client
        -   even the client has been written in an another language
    -   the client can connect to any server
        -   even the server has been written in an another language
    -   a connection config file contains basic settings for the socket communication

>   **NOTE**:   These code examples were written in **C++** only. No raw C code is in use here to prevent undefined behavior.

>   **NOTE**:   In case of any exception no exception handling has been implemented.

####    required library
-   `asio` header: https://think-async.com/Asio/
    -   this header file is required to work with the socket communication
    -   use `<asio.hpp>` or `"asio.hpp"` to work with the library
    -   on compile time, the header file must be linked to that project
        -   assuming, that the downloaded zip archive is located in `Downloads` folder, use:
            -   Windows: `-I"C:/Users/<user_name>/Downloads/asio-x.y.z/include"`
            -   UNIX: `-I"/home/<user_name>/Downloads/asio-x.y.z/include"`

>   **NOTE**: It may happen, that the library file is unable to find in the IDE. This can be ignored, since the compiler starts to complain, when something is wrong.


####    compilation

| operating system | full command | additional information |
| - | - | - | 
| Windows | ```g++.exe -g3 -Wall socket_server.cpp config/config_reader.cpp -std=c++17 -I"C:/Users/<user_name>/Downloads/asio-x.y.z/include" -Iconfig -lws2_32 -lmswsock -ladvapi32 -o server.exe``` | at least C++ v17 shall be used (not tested for older C++ versions); the config folder must also be included to be able to read the config file itself |
| UNIX | ```g++ -g3 -Wall socket_server.cpp config/config_reader.cpp -std=c++17 -I"/home/<user_name>/Downloads/asio-x.y.z/include" -Iconfig -o server -pthread``` | For a UNIX system the posix thread library is required to link. |

####    works on:
-   Windows : Windows (e.g. `127.0.0.1`, `::1`)
-   UNIX : UNIX (same local IPv4 address)
-   Windows : UNIX (IPv4 address of the server side in both config files)
-   Windows : UNIX (Windows: client in C++, UNIX: server in Python)