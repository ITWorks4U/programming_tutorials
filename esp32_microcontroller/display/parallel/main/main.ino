#include <LiquidCrystal.h>
#define HOLD_TIME_IN_MS 500

LiquidCrystal lcd(13,  12, 25,   26,   27,  14);
                  // RS, E, DB4, DB5, DB6, DB7

int global_counter = 0;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
}

void loop() {
  // put your main code here, to run repeatedly:
  global_counter++;

  lcd.clear();
  lcd.print(global_counter);
  delay(HOLD_TIME_IN_MS);
}
