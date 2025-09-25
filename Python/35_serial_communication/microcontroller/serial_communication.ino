#define BAUD_RATE   115200
#include "led_control.h"
#include "system_control.h"

void setup() {
  Serial.begin(BAUD_RATE);
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_YELLOW, OUTPUT);
  pinMode(PIN_RED, OUTPUT);
}

void loop() {
  if (Serial.available()) {
    String command = Serial.readStringUntil('\n');

    if (command.startsWith(FLAG_LED)) {
      trigger_led(command);
    } else if (command.startsWith(COMMAND_SYSTEM_INFO)) {
      collect_system_information();
    }
  }
}

void trigger_led(String command) {
  bool on_success = true;

  if (command.equals(GREEN_ON)) {
    digitalWrite(PIN_GREEN, HIGH);
  } else if (command.equals(GREEN_OFF)) {
    digitalWrite(PIN_GREEN, LOW);
  } else if (command.equals(YELLOW_ON)) {
    digitalWrite(PIN_YELLOW, HIGH);
  } else if (command.equals(YELLOW_OFF)) {
    digitalWrite(PIN_YELLOW, LOW);
  } else if (command.equals(RED_ON)) {
    digitalWrite(PIN_RED, HIGH);
  } else if (command.equals(RED_OFF)) {
    digitalWrite(PIN_RED, LOW);
  } else {
    on_success = false;
  }

  if (on_success) {
    Serial.println("command successfully executed");
  } else {
    Serial.println("unknown command...");
  }
}

void collect_system_information() {
  uint32_t max_heap_size = ESP.getHeapSize();
  uint32_t free_space_left = ESP.getFreeHeap();

  String summary = "#cores: " + String(ESP.getChipCores()) + "\n" +
  "core frequency: " + String(ESP.getCpuFreqMHz()) + " MHz \n" +
  "core version: " + String(ESP.getChipModel()) + "\n" +
  "model: " + String(ESP.getCoreVersion()) + "\n" +
  "heap size: " + String(max_heap_size / 1024) + " KB\n" +
  "free space left: " + String(free_space_left / 1024) + " KB " +
  "(" + (static_cast<double>(free_space_left) / static_cast<double>(max_heap_size)) * 100 + "%)";

  Serial.println(summary);
}