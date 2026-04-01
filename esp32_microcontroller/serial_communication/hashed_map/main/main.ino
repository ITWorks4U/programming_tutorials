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
  //  located: commands.ino
  // _test_commands_to_hash();      //  only in use, if you want to figure out which
                                    //  (C)-String expression results to which hexadecimal value
                                    //  NOTE: When you power up your microcontroller, you may not see
                                    //        any result. Use the reset button (EN-button) on your microcontroller.

  //  located:  settings.ino
  collect_incoming_data();
  handle_incoming_signals();
}
