#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

#define PIN_COUNT 54
#define EXCLUDE_COUNT 3

int state[PIN_COUNT];
int exclude[EXCLUDE_COUNT] = { 13, 20, 21 };

void setup() {
  pinMode(13, OUTPUT);

  for (int i = 0; i < PIN_COUNT; i++) {
    bool isInputPin = true;
    for (int j = 0; j < EXCLUDE_COUNT; j++) {
      if (i == j) {
        isInputPin = false;
        break;
      }
    }
    if (isInputPin) {
      pinMode(i, INPUT);
    }
  }

  lcd.init();
  lcd.backlight();
}

void loop() {

  int currentDisplayLineNumber = -1;

  for (int i = 0; i < PIN_COUNT; i++) {
    bool isInputPin = true;
    for (int j = 0; j < EXCLUDE_COUNT; j++) {
      if (i == j) {
        isInputPin = false;
        break;
      }
    }
    if (isInputPin) {
      int currentState = digitalRead(i);
      if (state[i] != currentState) {

        if (currentDisplayLineNumber < 0) {
          lcd.clear();
          currentDisplayLineNumber++;
        }

        lcd.setCursor(0, currentDisplayLineNumber);
        currentDisplayLineNumber++;

        String info = String(i);
        if (currentState == HIGH) {
          lcd.print(info + " = ON");
        } else {
          lcd.print(info + " = OFF");
        }
        state[i] = currentState;

        if (currentDisplayLineNumber >= 2) {
          break;
        }
      }
    }
  }

}
