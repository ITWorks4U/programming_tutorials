/*
* Using a 4bit 7-segment display, like a TM1637, which requires an IC connection
* and library. The library TM1637 by Avishay Orpaz will be used here.
*
* Unlike to use an address, this setup requires the clock and data pin.
*/

#include <TM1637Display.h>

#define TIMEOUT_IN_MS 1000
#define MAX_NUMBER    10000
#define CLOCK_PIN     19
#define DATA_PIN      18

TM1637Display seg(CLOCK_PIN, DATA_PIN);

void setup() {
  seg.setBrightness(/*brightness: */ 90, /*on: */true);
}

void loop() {
  static int ctr = 0;
  static unsigned long last_timer = 0;
  
  if (millis() - last_timer > TIMEOUT_IN_MS) {
    last_timer = millis();

    seg.showNumberDec(ctr);

    ctr = (ctr + 1) % MAX_NUMBER;
  }
}
