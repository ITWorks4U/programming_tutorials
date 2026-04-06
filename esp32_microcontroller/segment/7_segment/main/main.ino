/*
* Using a single 7-segment-display. This does not need any additional library to work with.
* This 7-segment-display comes with a common cathode or common anode. Which one you might have,
* can easily be determined by using GND to the middle pin (no matter if the top or bottom pin is in use),
* connect any other segment pin by a 220 ohms resistor to 5V and if the certain segment shows up, then you've
* a common cathode. On a common anode, connect the middle pin with 5V, any other segment pin by a 220 ohms resistor
* back to GND. Your segment pin shall NOT be shown, whereas each other pin should.
*
* Make sure you're using a resistor, otherwise you'll damage the segments.
*
* This sample below shows a single number range [0..F] with a delay of 1,000ms.
* A common cathode is in use, too.
*/

/*
PIN A => 13
PIN B => 12
PIN C	=> 14
PIN D	=> 27
PIN E	=> 4
PIN F	=> 16
PIN G	=> 17

----
PIN DP => 5                not in use, but this can be used to control the DP pin
----
*/

#define TIMEOUT_MS       1000
#define NBR_SEGMENTS     7
#define UPPER_BOUNDARY   16

byte segment_pins[] = {13, 12, 14, 27, 4, 16, 17};

// NOTE: This belongs to a 7-segment-display with a common
//       cathode. If you're using a common anode instead,
//       then these settings must be switched. Each 1 becomes 0,
//       and each 0 becomes a 1.
const byte numbers[UPPER_BOUNDARY][NBR_SEGMENTS] = {
 /*A,B,C,D,E,F,G*/
  {1,1,1,1,1,1,0},  // 0
  {0,1,1,0,0,0,0},  // 1
  {1,1,0,1,1,0,1},  // 2
  {1,1,1,1,0,0,1},  // 3
  {0,1,1,0,0,1,1},  // 4
  {1,0,1,1,0,1,1},  // 5
  {1,0,1,1,1,1,1},  // 6
  {1,1,1,0,0,0,0},  // 7
  {1,1,1,1,1,1,1},  // 8
  {1,1,1,1,0,1,1},  // 9
  {1,1,1,0,1,1,1},  // A
  {0,0,1,1,1,1,1},  // B
  {1,0,0,1,1,1,0},  // C
  {0,1,1,1,1,0,1},  // D
  {1,0,0,1,1,1,1},  // E
  {1,0,0,0,1,1,1},  // F
};

void display_number(unsigned int nbr) {
  for (int i = 0; i < NBR_SEGMENTS; i++) {
    digitalWrite(segment_pins[i], numbers[nbr][i]);
  }
}

void setup() {
  // the lowest pin starts with 4 and the highest
  // pin ends with 27, whereas these pins only are
  // in use: 4,12,13,14,16,17,27

  for (int i = 4; i <= 27; i++) {
    switch(i) {
      case 4:
      case 12:
      case 13:
      case 14:
      case 16:
      case 17:
      case 27:
        pinMode(i, OUTPUT);
        break;
    }
  }
}

void loop() {
  static int counter = 0;                       // static counter for loop function
  display_number(counter);                      // display the current number
  counter = (counter + 1) % UPPER_BOUNDARY;     // the number can only reach a value [0..15]
  delay(TIMEOUT_MS);                            // timeout of 1 second
}