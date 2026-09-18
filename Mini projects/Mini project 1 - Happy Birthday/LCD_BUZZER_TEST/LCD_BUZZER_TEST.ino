// In this code we are using LCD and buzzer.
// This code will display "it's me" and "Ravi",
// then display "Happy Birthday!" and beep the buzzer for 3 seconds.
// also point is that in my project software is tinkercad in that lcd is different so this code may not work on that
//because there is different model and different adress lcd
// After that it will display "Have a Great Day!"

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int buzzer = 8;

void setup()
{
  lcd.init();
  lcd.backlight();

  pinMode(buzzer, OUTPUT);
}

void loop()
{
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("it's me");

  lcd.setCursor(0, 1);
  lcd.print("Ravi");

  delay(2000);

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Happy Birthday!");

  digitalWrite(buzzer, HIGH);
  delay(3000);

  digitalWrite(buzzer, LOW);
  delay(2000);

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Have a Great Day!");

  delay(3000);
}