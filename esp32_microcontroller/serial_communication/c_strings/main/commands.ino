#include "commands.h"

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