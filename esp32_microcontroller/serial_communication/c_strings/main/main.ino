/*
* This setting shows a simple example by receiving and sending
* commands by UART connection. The incoming and outgoing messages
* are raw strings. Usually, a communication runs with a hashed
* comparison or by using raw data only.
*
* NOTE: By handling the messages with C-strings this is much faster
*       than by using the horrible slow C++ implementation, however,
*       using C-strings doesn't makes this better, if you don't mind.
*
*       Since C-strings are in use, YOU must know how many characters
*       can be used to avoid an undefined behavior.
*
* This setup requires:
* - 3 leds to turn on/off (red, yellow, green)
* - 3 220 ohms resistor
* - 1 ESP32 microcontroller (for certain ESP methods)
*/

#include "commands.h"
#include "settings.h"

void setup() {
  Serial.begin(SERIAL_BAUD_RATE);
  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_YELLOW, OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
  clear_input_buffer();             //  see:  settings.ino
}

void loop() {
  //  functions are in settings.ino file

  collect_incoming_data();
  handle_incoming_signals();
}
