// sketch to print onto lcd
// see: https://billwaa.wordpress.com/2012/03/05/arduino-lcd-display-hj1602a/

#include <LiquidCrystal.h>
 
//Initialize LCD 
LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);
 
void setup()
{
//Set LCD Display Size
lcd.begin(16,2);
lcd.clear();
}
 
 
void loop()
{ 
  //Set Cursor and Display 
  delay(1000); 
  lcd.setCursor(0,0);
  lcd.print("Hello Beautiful");
  delay(1000); 
  lcd.setCursor(0,1);
  lcd.print("I miss YOU...");
  delay(1000);

  lcd.clear();
}
