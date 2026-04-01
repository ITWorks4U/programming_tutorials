/*
PIN_A   16
PIN_B   17
PIN_C   5
PIN_D   18
PIN_E   19
PIN_F   26
PIN_G   25
PIN_DP  33

//  ---
//  with 200 ohms resistor
//  ---

PIN_DIG_1 27
PIN_DIG_2 14
PIN_DIG_3 12
PIN_DIG_4 13
*/

#include <SevSeg.h>
#define NBR_DIGITS        4
#define TIMEOUT_MS        500
#define UPPER_BOUNDARY    10000 

SevSeg s;
uint8_t digital_pins[] = {27, 14, 12, 13};
uint8_t segment_pins[] = {16, 17, 5, 18, 19, 26, 25, 33};

void setup() {
  s.begin(COMMON_CATHODE, NBR_DIGITS, digital_pins, segment_pins);
  s.setBrightness(90);
}

void loop() {
  static int ctr = 0;
  static unsigned long last_update = 0;

  s.refreshDisplay();

  if (millis() - last_update >= TIMEOUT_MS) {
    last_update = millis();
    s.setNumber(ctr);
    ctr = (ctr + 1) % UPPER_BOUNDARY;
  }

  //NOTE: Don't use the delay() function, otherwise
  //      the multiplexer is going to corrupt on runtime,
  //      thus your result may display any garbage each
  //      time event. Luckily, this does not really damage the
  //      hardware component.
  // delay(TIMEOUT_MS);
}
