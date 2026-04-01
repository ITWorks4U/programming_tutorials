#include "settings.h"
#include "commands.h"

static char input_buffer[MAX_BUFFER_SIZE_INPUT + 1];  //  14 characters + '\0'

void clear_input_buffer(void) {
  memset(input_buffer, '\0', sizeof(input_buffer));
}

void collect_incoming_data(void) {
  static int counter = 0;
  
  while (Serial.available()) {
    char c = (char) Serial.read();

    if (c == '\n' || c == '\r') {
      if (counter == 0) {                             //  no message received
        return;
      }

      input_buffer[counter] = '\0';                   //  replace '\n' or '\r' with '\0'
      counter = 0;
    } else {
      if (counter < MAX_BUFFER_SIZE_INPUT) {          //  no more than the upper buffer size of characters can be stored
        input_buffer[counter++] = c;                  //  every remaining character is going to ignore
      }
    }
  }
}

void handle_incoming_signals(void) {
  /*  check, if the full command does match
  *   with one of the defined commands
  *
  * NOTE: This is only for C-Strings in C.
  */
  if (strcmp(input_buffer, CMD_GREEN_ON) == 0) {
    handler_led_green_on();
  } else if (strcmp(input_buffer, CMD_GREEN_OFF) == 0) {
    handler_led_green_off();
  } else if (strcmp(input_buffer, CMD_YELLOW_ON) == 0) {
    handler_led_yellow_on();
  } else if (strcmp(input_buffer, CMD_YELLOW_OFF) == 0) {
    handler_led_yellow_off();
  } else if (strcmp(input_buffer, CMD_RED_ON) == 0) {
    handler_led_red_on();
  } else if (strcmp(input_buffer, CMD_RED_OFF) == 0) {
    handler_led_red_off();
  } else if (strcmp(input_buffer, CMD_SYSTEM_INFO) == 0) {
    collect_system_informations();
  }

  //  NOTE: By using C-strings in C a nasty side effect may appear:
  //        The last used command may still exist, thus the previous command
  //        runs over and over again. To "handle" this side effect
  //        a bit better, a delay of 10ms, followed by clean up the
  //        input buffer ensures a "stable" run. Without the delay, it may
  //        happen, that no one of the commands above runs.

  delay(10);
  clear_input_buffer();
}