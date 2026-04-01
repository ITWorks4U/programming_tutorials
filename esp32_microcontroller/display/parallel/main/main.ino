/*
* This setting shows how to use a 16x2 liquid crystal display
* with a parallel connection. In contrast to the I2C connection,
* you need up to 16 pins. Furthermore you need an external
* potentiometer, if this is not already built in, for the contrast
* and you also need resistors for the background, which are directly connected
* to 5V and GND. Typically, 100 ohm for both directions are quite enough.
*
* This setup requires:
* - 1 LCD (parallel connection)
* - up to 16 wires (at least "only" 10 wires are required)
* - 1 ESP32 microcontroller
*/

#include <LiquidCrystal.h>              // must be installed by the Arduino library manager
#define HOLD_TIME_IN_MS 500             // delay for the next turn
#define NBR_OF_COLUMNS  16
#define NBR_OF_ROWS     2

LiquidCrystal lcd(13,  12, 25,   26,   27,  14);
                  // RS, E, DB4, DB5, DB6, DB7

int global_counter = 0;

void setup() {
  lcd.begin(NBR_OF_COLUMNS, NBR_OF_ROWS);
}

void loop() {
  global_counter++;

  lcd.clear();
  lcd.print(global_counter);
  delay(HOLD_TIME_IN_MS);
}
