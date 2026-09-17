#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int buzzer = 8;

void setup() {

  // Initialize LCD
  lcd.init();
  lcd.backlight();

  // Initialize buzzer
  pinMode(buzzer, OUTPUT);

  // LCD test message
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("LCD + BUZZER");
  lcd.setCursor(0, 1);
  lcd.print("TEST START");

  delay(2000);

  // Buzzer test
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("BUZZER TEST");
  lcd.setCursor(0, 1);
  lcd.print("BEEP 10 SEC");

  tone(buzzer, 1000);
  delay(10000);
  noTone(buzzer);

  // Test completed
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("TEST COMPLETE");
  lcd.setCursor(0, 1);
  lcd.print("LCD + BUZZER OK");
}

void loop() {
}