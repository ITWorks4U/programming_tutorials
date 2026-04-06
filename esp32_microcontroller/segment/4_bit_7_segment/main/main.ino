/*
* Using a 4x7-segment-display. This display also exists with I²C connection, however, in that case
* a parallel connection is in use instead. Like the 7-segment-display this also comes with a common cathode or common anode
* Which one you might have, can easily be determined by using one of the following constant expressions:
* COMMON_CATHODE ( = 0), COMMON_ANODE ( = 1)
*
* This also needs an external library SevSeg.h, usually by Dean Reading.
*
* This sample below shows a counter in the range [0..9999] with a delay of 500ms.
*/

#include <SevSeg.h>   // this library must be installed first => library manager and type in: sevseg
#include "settings.h"

SevSeg s;             // instance of the SevSeg class

void setup() {
  const int number_of_digits = 4;
  uint8_t digital_pins[] = {PIN_DIG_1, PIN_DIG_2, PIN_DIG_3, PIN_DIG_4};
  uint8_t segment_pins[] = {PIN_A, PIN_B, PIN_C, PIN_D, PIN_E, PIN_F, PIN_G, PIN_DP};

  s.begin(COMMON_CATHODE, number_of_digits, digital_pins, segment_pins);
  s.setBrightness(90);
}

void loop() {
  static int ctr = 0;
  static unsigned long last_update = 0;

  if (millis() - last_update >= TIMEOUT_MS) {
    last_update = millis();
    s.setNumber(ctr);
    s.refreshDisplay();
    ctr = (ctr + 1) % UPPER_BOUNDARY;
  }

  //NOTE: Don't use the delay() function, otherwise
  //      the multiplexer is going to corrupt on runtime,
  //      thus your result may display any garbage each
  //      time event. Luckily, this does not really damage the
  //      hardware component.
  // delay(TIMEOUT_MS);
}
