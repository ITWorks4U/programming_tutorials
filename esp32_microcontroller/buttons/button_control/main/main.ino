/*
* This simple setting shows up a button press and when this
* button has been pressed, then any actor, like a LED turns on,
* as long as, this button is still pressed.
*
* For the used ESP32, the button response pin (HIGH or LOW only)
* is connected to pin 12, whereas on pin 13 a digtial output pin
* to the LED has been set up.
*
* NOTE:
* any incoming signal, like a button, can be set up with:
* INPUT, INPUT_PULLUP and INPUT_PULLDOWN
*
* For this ESP32 these known pins can NOT handle INPUT_PULLUP | INPUT_PULLDOWN:
* 34, 35, 32, 33
* => These are toggle pins, which are usually in use for sensor data and those
*    pins may switch an incoming signal, even there's no device connected, many times
*    in a second randomly with a HIGH or LOW signal. Furthermore, if those pins are in use
*    with a button, then an external pullup or pulldown setup must be done by your own.
*
* this setup requires:
* - 1 actor, like a LED
* - 1 button (no matter, if this button has 2 or 4 pins)
* - 1 10k ohm resistor (recommended for the button)
* - 1 220 ohm resistor for the LED
*/

#define PIN_BUTTON        12
#define PIN_LED           13

void setup() {
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_BUTTON, INPUT);         // one of three ways
}

void loop() {
  digitalWrite(PIN_LED, digitalRead(PIN_BUTTON));
}