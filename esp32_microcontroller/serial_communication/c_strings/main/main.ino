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
