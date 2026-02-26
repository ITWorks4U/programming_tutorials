#include "settings.h"
#include "commands.h"

static char input_buffer[MAX_BUFFER_INPUT + 1];     //  14 characters + '\0'
static char output_buffer[MAX_BUFFER_OUTPUT + 1];   //  up to 140 characters + '\0'

#ifdef CURRENT_VERSION_V2                           //  only for V2
const CommandHandler command_table[] = {
  {cmd_green_on, green_on_handler},
  {cmd_green_off, green_off_handler},
  {cmd_yellow_on, yellow_on_handler},
  {cmd_yellow_off, yellow_off_handler},
  {cmd_red_on, red_on_handler},
  {cmd_red_off, red_off_handler},
  {cmd_system_info, collect_system_informations}
};

#define NBR_CMDS  (sizeof(command_table) / sizeof(command_table[0]))
#endif

void collect_incoming_data(void) {
  static int counter = 0;
  
  while (Serial.available()) {
    char c = (char) Serial.read();

    if (c == '\n' || c == '\r') {
      if (counter == 0) {                           //  no message received
        return;
      }

      input_buffer[counter] = '\0';                 //  replace '\n' or '\r' with '\0'
      counter = 0;
    } else {
      if (counter < MAX_BUFFER_INPUT) {
        input_buffer[counter++] = c;
      }
    }
  }
}

void clear_input_buffer() {
  memset(input_buffer, '\0', sizeof(input_buffer));
}

void setup() {
  Serial.begin(SERIAL_BAUD_RATE);
  pinMode(pin_green, OUTPUT);
  pinMode(pin_yellow, OUTPUT);
  pinMode(pin_red, OUTPUT);

  clear_input_buffer();
}

void loop() {
  #ifndef CURRENT_VERSION_V3                        //  listening to serial port (not in use for V3)
  collect_incoming_data();                          //  and convert the message into input_buffer
  #endif                                            //  for V3: read the raw data only

  #ifdef CURRENT_VERSION_V0
  handle_incoming_signals_v0();                     //  string comparison
  #endif

  #ifdef CURRENT_VERSION_V1
  handle_incoming_signals_v1();                     //  hash value comparison
  #endif

  #ifdef CURRENT_VERSION_V2
  handle_incoming_signals_v2();                     //  hash map
  #endif

  #ifdef CURRENT_VERSION_V3
  handle_incoming_signals_v3();                     //  handle with raw data
  #endif
}