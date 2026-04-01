#include <LiquidCrystal_I2C.h>

#define LCD_COLUMNS 16
#define LCD_ROWS    2
#define LCD_ADDRESS 0x27
#define WAIT_TIME_IN_MS 500

LiquidCrystal_I2C lcd(LCD_ADDRESS, LCD_COLUMNS, LCD_ADDRESS);
int global_counter = 0;

void setup() {
  lcd.init();
  lcd.backlight();
}

void loop() {
  global_counter++;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(global_counter);
  delay(WAIT_TIME_IN_MS);
}
