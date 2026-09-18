// this is the complete code of the mini project 1 
// othe code are made for the testing and understanding purpose 
// but here some extra things are things i can't make code which understand only in one code like for loop

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

// Buzzer
int buzzer = 8;

// LEDs
int led1 = 9;
int led2 = 10;
int led3 = 11;
int led4 = 12;
int led5 = 13;

// Birthday melody
int melody[] = {
  262, 262, 294, 262, 349, 330,
  262, 262, 294, 262, 392, 349,
  262, 262, 523, 440, 349, 330, 294,
  466, 466, 440, 349, 392, 349
};

// Note duration
int duration[] = {
  300, 300, 600, 600, 600, 1200,
  300, 300, 600, 600, 600, 1200,
  300, 300, 600, 600, 600, 600, 1200,
  300, 300, 600, 600, 600, 1200
};

int numberOfNotes = 26;

void setup()
{
  lcd.init();
  lcd.backlight();

  pinMode(buzzer, OUTPUT);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
}

void loop()
{
  // Turn all LEDs OFF
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);


  // INTRODUCTION


  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("It's me");

  lcd.setCursor(0, 1);
  lcd.print("Ravi");

  delay(2000);



  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Are you ready?");

  delay(2000);


  
  // 10 SECOND COUNTDOWN


  for (int count = 10; count >= 1; count--)
  {
    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("Get Ready!");

    lcd.setCursor(7, 1);
    lcd.print(count);

    
    tone(buzzer, 1000);
    delay(200);
    noTone(buzzer);

    delay(800);
  }


  
  // HAPPY BIRTHDAY
  

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Happy Birthday!");

  lcd.setCursor(0, 1);
  lcd.print("Ravi!");


  
  
  

  for (int i = 0; i < numberOfNotes; i++)
  {
    tone(buzzer, melody[i]);


    // LED 1
    if (i % 5 == 0)
    {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
      digitalWrite(led5, LOW);
    }

    // LED 2
    else if (i % 5 == 1)
    {
      digitalWrite(led1, LOW);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
      digitalWrite(led5, LOW);
    }

    // LED 3
    else if (i % 5 == 2)
    {
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, LOW);
      digitalWrite(led5, LOW);
    }

    // LED 4
    else if (i % 5 == 3)
    {
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led4, HIGH);
      digitalWrite(led5, LOW);
    }

    // LED 5
    else
    {
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
      digitalWrite(led5, HIGH);
    }

    delay(duration[i]);

    noTone(buzzer);

    delay(80);
  }



  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);

  delay(1000);


  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Have a Great");

  lcd.setCursor(0, 1);
  lcd.print("Day!");

  delay(3000);


  
  


  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Enjoy Your Day!");

  delay(3000);
}