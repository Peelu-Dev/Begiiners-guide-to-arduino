#include <LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0,0); // column first then row
  String msg1 = "Raghuwanshi Tyres";
  lcd.print(msg1);
  delay(500);
  for(int pos = 0; pos < msg1.length(); pos++){
    lcd.scrollDisplayLeft();
    delay(200);
    }
  lcd.clear();
  lcd.setCursor(0,1); // column first then row
  String msg2 = "Raghuwanshi Collection";
  lcd.print(msg2);
  delay(500);
  for(int pos = 0; pos < msg2.length(); pos++){
    lcd.scrollDisplayLeft();
    delay(200);
    }
  lcd.clear();
  }
