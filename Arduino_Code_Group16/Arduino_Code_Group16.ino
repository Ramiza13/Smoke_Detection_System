#include<LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int Smoke = 9;
int greenLED = 6;
int redLED = 7;

int speaker = 13;

int read_input;

void setup() {

  pinMode(Smoke, INPUT);

  pinMode(greenLED,OUTPUT);
  pinMode(redLED,OUTPUT);
  pinMode(speaker,OUTPUT);
  
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(" SMOKE DETECTION ");
  lcd.setCursor(0,1);
  lcd.print("     SYSTEM  ");
  delay(1000);
  lcd.clear();
}

void loop() {
read_input = digitalRead(Smoke);
  if(read_input == HIGH)
  {
    lcd.setCursor(0,0);
    lcd.print(" Smoke Detected! ");
    lcd.setCursor(0, 1);
    lcd.print("   Alert....!!!  ");
    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, LOW);
    tone(speaker, 250);
    delay(500);
    noTone(speaker);
    
  }
  else
  {
    digitalWrite(greenLED, HIGH);
    digitalWrite(redLED, LOW);
    lcd.setCursor(0,0);
    lcd.print("    No Smoke    ");
    lcd.setCursor(0, 1);
    lcd.print("    Detected.   ");
    delay(500);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("      SAFE!     ");
  }
  delay(500);
  lcd.clear();

}
