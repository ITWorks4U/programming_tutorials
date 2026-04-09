/*
* Using a 4bit 7-segment display with I²C connection. This allows to use only 4 wires,
* where an external library is required. In that case the Adafruit LED Backpack Library
* is in use. This allows to use a specified address between 0x70 and 0x79 to gain access
* to the segment display.
*/

#include <Adafruit_LEDBackpack.h>

#define SEGMENT_ADDRESS 0x70
#define TIMEOUT_IN_MS   1000
#define MAX_NUMBER      10000

Adafruit_7segment seg = Adafruit_7segment();

void setup() {
  seg.begin(SEGMENT_ADDRESS);
}

void loop() {
  static int ctr = 0;
  static unsigned long last_timer = 0;
  
  if (millis() - last_timer > TIMEOUT_IN_MS) {
    last_timer = millis();

    seg.print(ctr);
    seg.writeDisplay();

    ctr = (ctr + 1) % MAX_NUMBER;
  }
}