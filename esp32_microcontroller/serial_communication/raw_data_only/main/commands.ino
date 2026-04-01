#include "commands.h"

uint8_t message_buffer[LENGTH_INPUT_MSG];
static bool _on_full_message = false;             //  flag to check, if the full message has been transmitted

void collect_system_informations(void) {
  static char output_buffer[LENGTH_OUTPUT + 1];   //  up to 140 characters + '\0'

  uint32_t max_heap_size = ESP.getHeapSize();
  uint32_t free_space_left = ESP.getFreeHeap();

  double percent = 0.0;
  if (max_heap_size > 0) {
    percent = ((double)free_space_left / (double)max_heap_size) * 100.0;
  }

  //NOTE: s(n)printf() function automatically terminates the output buffer with \0
  snprintf(
    output_buffer, sizeof(output_buffer),
    " #cores: %u\n core frequency: %lu MHz\n core version: %s\n model: %s\n heap size: %lu KB\n free space left: %lu KB (%.2f%%)\n",
    ESP.getChipCores(), ESP.getCpuFreqMHz(), ESP.getCoreVersion(), ESP.getChipModel(),
    max_heap_size / 1024, free_space_left / 1024, percent
  );

  Serial.write(output_buffer);
}

void handler_led_green_on(void)  {
  digitalWrite(PIN_GREEN, HIGH);
}

void handler_led_green_off(void) {
  digitalWrite(PIN_GREEN, LOW);
}

void handler_led_yellow_on(void) {
  digitalWrite(PIN_YELLOW, HIGH);
}

void handler_led_yellow_off(void) {
  digitalWrite(PIN_YELLOW, LOW);
}

void handler_led_red_on(void) {
  digitalWrite(PIN_RED, HIGH);
}

void handler_led_red_off(void) {
  digitalWrite(PIN_RED, LOW);
}

void handle_incoming_single_signal(void) {
  if (Serial.available()) {
    switch(Serial.read()) {
      case CMD_RED_ON:
        handler_led_red_on();
        break;
      case CMD_RED_OFF:
        handler_led_red_off();
        break;
      case CMD_YELLOW_ON:
        handler_led_yellow_on();
        break;
      case CMD_YELLOW_OFF:
        handler_led_yellow_off();
        break;
      case CMD_GREEN_ON:
        handler_led_green_on();
        break;
      case CMD_GREEN_OFF:
        handler_led_green_off();
        break;
      case CMD_SYSTEM_INFO:
        collect_system_informations();
        break;
    }
  }
}

void handle_incoming_signals(void) {
  static int ctr_message = 0;

  while(Serial.available()) {
    message_buffer[ctr_message] = Serial.read();

    if (ctr_message == 2) {                   //  read only the first three data
      ctr_message = 0;
      _on_full_message = true;
      break;
    }

    ctr_message++;
  }
  
  if (_on_full_message) {
    _on_full_message = false;

    if (calculate_crc_checksum() == 0) {      //  only for a valid transmitted message
      switch(message_buffer[1]) {             //  contains the real command
        case CMD_RED_ON:
          handler_led_red_on();
          break;
        case CMD_RED_OFF:
          handler_led_red_off();
          break;
        case CMD_YELLOW_ON:
          handler_led_yellow_on();
          break;
        case CMD_YELLOW_OFF:
          handler_led_yellow_off();
          break;
        case CMD_GREEN_ON:
          handler_led_green_on();
          break;
        case CMD_GREEN_OFF:
          handler_led_green_off();
          break;
        case CMD_SYSTEM_INFO:
          collect_system_informations();
          break;
      }
    }
  }
}

void test_crc_checksum(void) {
  /*  only for testing which CRC value results, where the final result must be 0  */

  byte tmp[LENGTH_INPUT_MSG];   
  tmp[0] = CMD_ID_BEGIN;          //  0xB9

  for(uint32_t cmd_pos = CMD_RED_ON; cmd_pos <= CMD_SYSTEM_INFO; cmd_pos++) {
    switch(cmd_pos) {             //  CRC (0xB9 ^ COMMAND):
      case CMD_RED_ON:            //  0xB8
      case CMD_RED_OFF:           //  0xBB
      case CMD_YELLOW_ON:         //  0xBA
      case CMD_YELLOW_OFF:        //  0xBD
      case CMD_GREEN_ON:          //  0xBC
      case CMD_GREEN_OFF:         //  0xBF
      case CMD_SYSTEM_INFO:       //  0x19
        tmp[1] = cmd_pos;

        tmp[2] = tmp[0] ^ tmp[1]; //  0xb9 ^ COMMAND
        Serial.printf("0: %x, cmd_pos 0x%x => crc = 0x%x ==> %x\n", tmp[0], tmp[1], tmp[2], tmp[0] ^ tmp[1] ^ tmp[2]);
        break;
    }
  }
  
  while(true) {
    delay(1);
  }
}

uint calculate_crc_checksum() {
  uint32_t result = 0;

  for(int i = 0; i < LENGTH_INPUT_MSG; i++) {
    result ^= message_buffer[i];
  }

  return result;
}