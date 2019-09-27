#include <Wire.h>
#include <LiquidCrystal.h>
int c ,c3 ,c5;
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
void setup() {
  Wire.begin(8);
  Wire.onReceive(rE);
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(5,0);
  lcd.print("S_BGH99");
  
  delay(3000);
  for (int positionCounter = 0; positionCounter < 13; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayLeft();
    delay(200);
  }
  lcd.clear();
}

void loop() {
  lcd.clear();
  
  Serial.print("this is time loop");
  Serial.print(c);
  Serial.print(":");
  Serial.print(c3);
  Serial.print(":");
  Serial.println(c5);
  lcd.setCursor(4, 1);
  lcd.print(c);
  lcd.print(":");
  lcd.print(c3);
  lcd.print(":");
  lcd.print(c5);
  delay(1000);
}
void rE(){
  while(Wire.available()>1){
    c = Wire.read();
    char c2 = Wire.read();
    c3 = Wire.read();
    char c4 = Wire.read();
    c5 = Wire.read();
    char c6 = Wire.read();
    char c7 = Wire.read();
    //Serial.print(c);

    //Serial.print(c6);
    //Serial.println(c7);
    }
  }
