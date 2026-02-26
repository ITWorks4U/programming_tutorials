#   serial communication in Python

-   sending messages by a serial communication with a direct USB connection to a microcontroller to control something or receive a status
-   external hardware in use:
    -   simple microcontroller (here: ESP32 Wroom)
        -   to control two LED's (green, yellow, red)
        -   to receive a system status
        -   ...

-   the python application is able to communicate with the micro controller by USB*
    -   sends commands to turn on or off a LED
    -   receives a system status from the microcontroller

>   *an ESP32 can also have a connection by WiFi or Bluetooth, but this is not in use here

### valid commans
-   use:

| command | effect |
| - | - |
| *_on | turn on a LED |
| *_off |turn off a LED |
| system_status | receive a hardware scan from the ESP32 |

>   *use: green_on, green_off, yellow_on, yellow_off, red_on, red_off


### required module
-   pyserial
    -   not installed by default
    -   must be installed with pip
        -   Windows: ```pip.exe install pyserial```
        -   UNIX: ```pip3 install pyserial```
            -   if pip3 was not successful, try to install the module by the software updater, like: ```sudo apt install python3-pyserial```

### need to know
-   **Never** use a thread or a sub process for a bidirectional communication, because a serial communication is a **critical resource**.
    -   When this resource is in use for reading data, it can't be used for sending data at the same time. => *This may cause a **deadlock***.
-   Make sure, that no other application blocks the communication port**, otherwise a serial communication is not available.

>   **Windows: COMx (x = 1,2,...,256), UNIX: /dev/ttyUSBy or /dev/ttyACMy or /dev/ttySy (y = 0,1,2, ..., 63)

### used systems
-   Windows
    -   used port: COMx (x = 1,2,3,...,256)
    -   *fun fact*: for older Windows systems (up to Vista), the COM ports were limited between `[1,99]`
-   UNIX/Linux (Raspberry Pi 4 model B)
    -   used port: /dev/ttyUSBx (x = 0,1,2,3,...,63)
    -   typically: /dev/ttyUSB0
    -   alternatives: /dev/ttyACMx or /dev/ttySx (depending on which system has been detected)

>   **NOTE**:   Make sure to know on which operating system you're working on.

####    using command line
-   more in use, if you want to check a **serial communication** over powershell / terminal

#####   Windows
>   **NOTE:** The used COM port may be different on your system.

| command | description |
| - | - |
|```mode COM6 BAUD=115200 PARITY=n DATA=8``` | configuring COM6 and list the status of the plugged in device on COM port 6 |
|```set /p x="any text here" <nul >\\.\COM6``` | send a message trough COM port 6 |

>   **NOTE**: By default the command line does not comes with a feature to receive data by UART. Use powershell instead for both ways.

#####  UNIX, like Linux:

| command | description |
| - | - |
|```stty -F /dev/ttyUSB0 115200 cs8 -cstopb -parenb -echo``` | configuring serial USB communication port |
|```echo "any text here" > /dev/ttyUSB0``` | send a message trough UART |
|```cat /dev/ttyUSB0``` | receive a message by UART |