// C++ code
//

#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 7, 6, 4, 2, 13);

int captTemp = A0;
int captForce = A1;

float captTempValue = 0;
float captForceValue = 0;

int ledTempRed = 3;
int ledTempBlue = 5;
int ledForceRed = 9;
int ledForceBlue = 11;

void setup()
{
  
  lcd.begin(16, 2);
  lcd.print("Temperature :");
  
  pinMode(captTemp, INPUT);
  pinMode(captForce, INPUT);
  
  pinMode(ledTempRed, OUTPUT);
  pinMode(ledTempBlue, OUTPUT);
  pinMode(ledForceRed, OUTPUT);
  pinMode(ledForceBlue, OUTPUT);
  
  Serial.begin(9600);
  
}

void loop()
{
  captTempValue = ((analogRead(captTemp) * (5.0/1024))-0.5)/0.01;
  captForceValue = analogRead(captForce);
  
  lcd.setCursor(0, 1);
  lcd.print("                ");
  lcd.setCursor(0, 1);
  lcd.print(captTempValue);
  
  if (captTempValue<10){
    digitalWrite(ledTempBlue, HIGH);
  }
  else {
    digitalWrite(ledTempBlue, LOW);
  }
  if (captTempValue>20){
    digitalWrite(ledTempRed, HIGH);
  }
  else {
    digitalWrite(ledTempRed, LOW);
  }
  
  if (captForceValue>5 & captForceValue<20){
    digitalWrite(ledForceBlue, HIGH);
  }
  else {
    digitalWrite(ledForceBlue, LOW);
  }
  if (captForceValue>220){
    digitalWrite(ledForceRed, HIGH);
  }
  else {
    digitalWrite(ledForceRed, LOW);
  }
  
  delay(1000);
}