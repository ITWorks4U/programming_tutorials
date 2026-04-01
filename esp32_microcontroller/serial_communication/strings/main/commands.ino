#include "commands.h"

void collect_system_informations(void) {
  uint32_t max_heap_size = ESP.getHeapSize();
  uint32_t free_space_left = ESP.getFreeHeap();

  double percent = 0.0;
  if (max_heap_size > 0) {
    percent = static_cast<double>(free_space_left) / static_cast<double>(max_heap_size) * 100.0;
  }

  String outgoing =
    "#cores: " + String(ESP.getChipCores()) + "\n"+
    "core frequency: " + String(ESP.getCpuFreqMHz()) + " MHz\n" +
    "core version: " + String(ESP.getCoreVersion()) + "\n" +
    "chip model: " + String(ESP.getChipModel()) + "\n" +
    "heap size: " + String(max_heap_size / 1024) + "KB\n" +
    "free space left: " + String(free_space_left / 1024) + "KB (" + String(percent) + "%)";

  Serial.println(outgoing);
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