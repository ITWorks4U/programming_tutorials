#include "commands.h"
#include "settings.h"

void setup() {
  Serial.begin(SERIAL_BAUD_RATE);
  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_YELLOW, OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
}

void loop() {
  // test_crc_checksum();                       //  figure out which hexadecimal message
                                                //  buffer for each command results
                                                //  NOTE: When you power up your microcontroller, you may not see
                                                //        any result. Use the reset button (EN-button) on your microcontroller.

  //  NOTE: By using the serial monitor of the Arduino IDE
  //        your input message is never be able to handle,
  //        because your message is type of ASCII, where a
  //        hexadecimal input is required instead. Unlike to use
  //        the serial monitor use an external application, like
  //        Hammerterm. Available for Windows and UNIX systems.
  
  // handle_incoming_single_signal();           //  for a single signal only
  handle_incoming_signals();                    //  for a message collection
}
