#include "commands.h"
#include "settings.h"

String incomingMessage;

void handle_incoming_signals(void) {
  /*  check, if the full command does match
  *   with one of the defined commands
  *
  * NOTE: This is only for Strings with C++.
  */
  if (incomingMessage.equals(CMD_RED_ON)) {
    handler_led_red_on();
  } else if (incomingMessage.equals(CMD_RED_OFF)) {
    handler_led_red_off();
  } else if (incomingMessage.equals(CMD_YELLOW_ON)) {
    handler_led_yellow_on();
  } else if (incomingMessage.equals(CMD_YELLOW_OFF)) {
    handler_led_yellow_off();
  } else if (incomingMessage.equals(CMD_GREEN_ON)) {
    handler_led_green_on();
  } else if (incomingMessage.equals(CMD_GREEN_OFF)) {
    handler_led_green_off();
  } else if (incomingMessage.equals(CMD_SYSTEM_INFO)) {
    collect_system_informations();
  }
}

void setup() {
  Serial.begin(SERIAL_BAUD_RATE);
  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_YELLOW, OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
}

void loop() {
  //  This command below may take up to one second before the
  //  action is going to act.
  incomingMessage = Serial.readStringUntil('\n');
  handle_incoming_signals();
}
