# MQTT communications

-   allows you to communicate between two systems on certain channels, where the programming language doesn't matter
    -   a publisher, e. g. written in C++, can communicate with a subsriber, like written in Java
    -   often in use for smart systems (micro controllers and any clinent, like a smartphone)

### versions
-   MQTT comes with the versions 3.1, 3.1.1 and 5.x
    -   can communicate between those versions

### required for python
-   paho-mqtt module
    -   ```pip[3|.exe] install paho-mqtt```
        -   on an UNIX system pip may be unable to install that module
        -   try to install that module by the update manager (console)

### neccessary settings
-   a MQTT connection can be handled as an anonymous communication, as well as, an authorized communication only
    -   *the samles here requires a valid user-password-management to work with*

### practical usage
-   using a MQTT connection with an ESP32 micro controller to control LEDs and also reading the temperature and humidity sensor data
-   a publisher sends the commands to change the LED states
-   a subscriber receives all incoming messages