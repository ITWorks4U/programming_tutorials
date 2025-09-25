#   serial communication in Python

-   sending messages by a serial communication with a direct USB connection to a microcontroller to control something or receive a status
-   external hardware in use:
    -   simple microcontroller (here: ESP32 Wroom)
        -   to control two LED's (green, red)
        -   to receive the LED status
        -   ...

-   the python application is able to communicate with the micro controller by USB*
    -   sends commands to turn on or off a LED
    -   receives a status from the microcontroller

>   *an ESP32 can also have a connection by WiFi or Bluetooth, but this is not in use here

### required module
-   pyserial
    -   not installed by default
    -   must be installed with pip
        -   Windows: ```pip.exe install pyserial```
        -   UNIX: ```pip3 install pyserial```
            -   if pip3 was not successful, try to install the module by the software updater, like: ```sudo apt install python3-pyserial```

### need to know
-   Never use a thread or a sub process for a bidirectional communication, because a serial communication is a critical resource.
-   When this resource is in use for reading data, it can't be used for sending data at the same time.
    -   This causes a deadlock.
-   Make sure, that no other application blocks the COM port, therwise a serial communication is not available.
-   a delay of one second may be a standard reaction
    -   unlike to the Arduino IDE, which has a delay of less than 1ms, it's not clear why a delay may appear there

####    using command line
-   Windows:
    -   **NOTE:** The used COM port may be different on your system.
    -   ```mode COM6 BAUD=115200 PARITY=n DATA=8```
        -   configuring COM6 and list the status of the plugged in device on COM port 6
    -   ```set /p x="any text here" <nul >\\.\COM6```
        -   send a message to COM port 6
    -   **NOTE**: by default the command line does not comes with a feature to receive data by UART
        -   using powershell instead for both ways is more useful
-   UNIX, like Linux:
    -   **NOTE:** by using an USB cable for UART, make sure to use *ttyUSBx* (x for 0,1,2,...,n-1)
    -   ```stty -F /dev/ttyUSB0 115200 cs8 -cstopb -parenb -echo```
        -   configuring serial USB communication port
    -   ```echo "any text here" > /dev/ttyUSB0```
        -   send a message to UART
    -   ```cat /dev/ttyUSB0```
        -   receive a message by UART