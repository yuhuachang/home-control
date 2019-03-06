#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

#define LEN 3

LiquidCrystal_I2C lcd(0x27, 16, 2);

String str[LEN] = {
  "Ryan",
  "Happy",
  "Birthday"
};

int inx = 0;

void setup() {
  lcd.init();

  lcd.backlight();
}

void loop() {

  int a = inx;
  int b = inx + 1;
  if (b >= LEN) {
    b = 0;
  }
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(str[a]);
  lcd.setCursor(0, 1);
  lcd.print(str[b]);
  delay(1000);

  inx++;
  if (inx >= LEN) {
    inx = 0;
  }
}
