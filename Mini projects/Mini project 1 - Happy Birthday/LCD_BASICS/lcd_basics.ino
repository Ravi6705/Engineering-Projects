//here we understanded the lcd program with arduino 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
void setup()
{
  lcd.init();
  lcd.backlight();
  
}
void loop()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Hello world!");
  delay(3000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("happy birthday");
  delay(3000);
}