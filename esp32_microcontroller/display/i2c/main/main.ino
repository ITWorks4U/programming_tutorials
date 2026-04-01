/*
* This setting shows how to use a 16x2 liquid crystal display
* with I2C connection. In contrast to the serial connection you
* don't need up to 16 pins, you don't need an external
* potentiometer for the contrast and you also don't need
* resistors for the background, which are directly connected
* to 5V and GND.
*
* This setup requires:
* - 1 I2C LCD
* - 4 wires
* - 1 ESP32 microcontroller (SDA: pin 21, SDC: pin 22)
*/

#include <LiquidCrystal_I2C.h>                     // this must be installed by the Arduino library manager

#define LCD_COLUMNS 16                             // number of columns
#define LCD_ROWS    2                              // number of rows
#define LCD_ADDRESS 0x27                           // I2C-address
#define WAIT_TIME_IN_MS 500                        // delay for the next turn

LiquidCrystal_I2C lcd(LCD_ADDRESS, LCD_COLUMNS, LCD_ADDRESS);
int global_counter = 0;

void setup() {
  lcd.init();
  lcd.backlight();                                 // turns on the LCD background
}

void loop() {
  global_counter++;
  lcd.clear();                                     // clear the previously displayed message
  lcd.print(global_counter);

  delay(WAIT_TIME_IN_MS);
}
