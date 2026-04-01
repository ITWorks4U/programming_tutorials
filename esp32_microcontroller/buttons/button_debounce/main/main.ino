/*
* This simple setting shows up a button press and when this
* button has been pressed, then any actor, like a LED turns on,
* when the button has been pressed once or more.
*
* NOTE: Usually, the certain actor(s) is/are active only, as long as,
*       the button has been pressed. Since a single button press the
*       responding signal toggles many times within 50ms between LOW and HIGH,
*       thus you don't have physically a chance to press the button really once.
*
*       This can be done by a button debounce algorithm. The real signal will be
*       handled, when the button has been pressed at least 50ms.
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

#include "settings.h"

int actor_state = LOW;                             // start with basic setting for the actor(s) => no actor turns on at the beginning
int current_button_state = LOW;                    // use the current button state => this button is usually not pressed
int last_button_state = LOW;                       // in use to compare with the last button state, if a button press has really been detected
unsigned long last_debounce_time = 0;              // stores the last used debounce time for the next turn

void check_pressed_button_primitive() {            // spoiler alert: this primitive function won't work
  static int button_counter = 0;                   // with an estimated possibility of 100%
  button_counter += digitalRead(PIN_BUTTON);

  if (button_counter % 2 == 1) {
    digitalWrite(PIN_LED, HIGH);
  } else {
    digitalWrite(PIN_LED, LOW);
  }
}

void check_pressed_button_correct() {
  int reading = digitalRead(PIN_BUTTON);

  if (reading != last_button_state) {
    last_debounce_time = millis();
  }

  if ((millis() - last_debounce_time) > DEBOUNCE_DELAY) {
    if (reading != current_button_state) {
      current_button_state = reading;

      if (current_button_state == HIGH) {
        actor_state = !actor_state;
      }
    }
  }

  digitalWrite(PIN_LED, actor_state);
  last_button_state = reading;
}

void setup() {
  pinMode(PIN_BUTTON, INPUT);
  pinMode(PIN_LED, OUTPUT);
}

void loop() {
  // check_pressed_button_primitive();
  check_pressed_button_correct();
}