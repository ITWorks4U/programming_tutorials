#   Serial communication in C++
-   allows to communicate with other systems, like PC, embedded systems, ... over a serial communication, like:
    -   COMx (x = 1,2,...,256)
    -   /dev/ttyUSBx (x = 0,1,...,31,...,63)
    -   UART
    -   ...

>   **NOTE**:   These code examples were written in **C++** only. No raw C code is in use here to prevent undefined behavior.

>   **NOTE**:   In case of any exception no exception handling has been implemented.

####    required library
-   `asio` header: https://think-async.com/Asio/
    -   this header file is required to work with the serial communication
    -   use `<asio.hpp>` or `"asio.hpp"` to work with the library
    -   on compile time, the header file must be linked to that project
        -   assuming, that the downloaded zip archive is located in `Downloads` folder, use:
            -   Windows: `-I"C:/Users/<user_name>/Downloads/asio-x.y.z/include"`
            -   UNIX: `-I"/home/<user_name>/Downloads/asio-x.y.z/include"`

>   **NOTE**: It may happen, that the library file is unable to find in the IDE. This can be ignored, since the compiler starts to complain, when something is wrong.


####    compilation

| operating system | full command | additional information |
| - | - | - | 
| Windows | ```g++.exe -g3 -Wall main.cpp config/config_reader.cpp serial/serial_connection.cpp -std=c++17 -I"C:/Users/<user_name>/Downloads/asio-x.y.z/include" -Iconfig -Iserial -lws2_32 -lmswsock -ladvapi32 -o serial_communication.exe``` | at least C++ v17 shall be used (not tested for older C++ versions) |
| UNIX | ```g++ -g3 -Wall -std=c++17 main.cpp config/config_reader.cpp serial/serial_connection.cpp -I"/home/<user_name>/Downloads/asio-x.y.z/include" -Iconfig -Iserial -pthread -o serial_communication.run``` | For a UNIX system the posix thread library is required to link. |

####    used microcontroller:
-   ESP-32 ("ESP-32 Wroom")
    -   doesn't comes with WiFi, Bluetooth (not required)
    -   3 LEDs (red, yellow, green)
    -   commands to communicate: `"system_info", "led_green_on", "led_green_off", "led_yellow_on", "led_yellow_off", "led_red_on", "led_red_off"`