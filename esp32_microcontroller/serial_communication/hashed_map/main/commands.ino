#include "commands.h"

const CommandHandler command_table[] = {
  {CMD_RED_ON, handler_led_red_on},
  {CMD_RED_OFF, handler_led_red_off},
  {CMD_YELLOW_ON, handler_led_yellow_on},
  {CMD_YELLOW_OFF, handler_led_yellow_off},
  {CMD_GREEN_ON, handler_led_green_on},
  {CMD_GREEN_OFF, handler_led_green_off},
  {CMD_SYSTEM_INFO, collect_system_informations}
};

#define NBR_CMDS  (sizeof(command_table) / sizeof(command_table[0]))

void collect_system_informations(void) {
  static char output_buffer[MAX_BUFFER_SIZE_OUTPUT + 1];   //  up to 140 characters + '\0'

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

  //  also possible:  Serial.println(output_buffer);
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

/*
static void _test_commands_to_hash(void) {
  //NOTE: Make sure to use (C)-Strings for the given expressions.
  //NOTE: On compile time the defined commands are already hashed values,
  //      thus this results to errors. Use the (C)-String expression instead
  //      or disbale this whole function.

  Serial.println();
  Serial.printf("red on: 0x%lx\n", convert_to_hash_string(CMD_RED_ON));
  Serial.printf("red off: 0x%lx\n", convert_to_hash_string(CMD_RED_OFF));
  Serial.printf("yellow on: 0x%lx\n", convert_to_hash_string(CMD_YELLOW_ON));
  Serial.printf("yellow off: 0x%lx\n", convert_to_hash_string(CMD_YELLOW_OFF));
  Serial.printf("green on: 0x%lx\n", convert_to_hash_string(CMD_GREEN_ON));
  Serial.printf("green off: 0x%lx\n", convert_to_hash_string(CMD_GREEN_OFF));
  Serial.printf("system info: 0x%lx\n", convert_to_hash_string(CMD_SYSTEM_INFO));

  while(true) {
    delay(1);
  }
}
*/

uint32_t convert_to_hash_string(const char *expr) {
  uint32_t hash_value = 5381;
  int c = 0;

  while((c = *expr++)) {
    //  hash_value * 33 + c
    hash_value = ((hash_value << 5) + hash_value) + c;
  }

  return hash_value;
}