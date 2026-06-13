#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
const int tpin = 9;
const int epin = 10;
const int mbtn = 3;
const int rbtn = 2;
bool measured = false;
float getDistance() {
  digitalWrite(tpin, LOW);
  delayMicroseconds(2);
  digitalWrite(tpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(tpin, LOW);
  long tot = pulseIn(epin, HIGH, 30000);
  return (tot * 0.0343) / 2.0;
}
void setup() {
  pinMode(tpin, OUTPUT);
  pinMode(epin, INPUT);
  pinMode(mbtn, INPUT_PULLUP);
  pinMode(rbtn, INPUT_PULLUP);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("== Welcome to ==");
  lcd.setCursor(0, 1);
  lcd.print("=== EchoLock ===");
  delay(3000);
  lcd.clear();
  lcd.print("Measure The Dist");
}
void loop() {
  if (!measured && digitalRead(mbtn)==LOW) {
    float sum = 0;
    lcd.clear();
    lcd.print("Caluculating..");
    for (int i = 0; i < 10; i++) {
      sum += getDistance();
      delay(100);
    }
    float avgdist = sum/10.0;
    float cms = avgdist/1;
    float ins = avgdist/2.54;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Dist from obj:");
    lcd.setCursor(0, 1);
    lcd.print(cms);
    lcd.print("cm/");
    lcd.print(ins);
    lcd.print("in");
    measured = true;
    delay(300);
  }
  if (digitalRead(rbtn) == LOW) {
    measured = false;
    lcd.clear();
    lcd.print("Measure the Dist:");
    delay(300);
  }
}