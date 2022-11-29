#include <Wire.h>                   // Library for I2C operation
#include "TroykaRTC.h"              // Library for working with real-time clocks
#include <LiquidCrystal_I2C.h>      // library for working with LiquidCrystal_I2C
#include "Settings.h"
#include "Var.h"

 
void setup()
{
  clock.begin();                              // Initializing the clock
  //clock.set(10,25,45,27,07,2005,THURSDAY);  // The method of setting the time and date in the module manually
  clock.set(__TIMESTAMP__);                   // The method of setting the time and date automatically when compiling

  lcd.init();
  lcd.backlight();
}
 
void loop()
{
  clock.read();                         // Requesting data from the watch
  // I read the readings of hours and minutes into variables
  hour = clock.getHour();
  minute = clock.getMinute();
  // Reading the pin status
  buttonState1 = digitalRead(BUTTON_PIN_1);
  buttonState2 = digitalRead(BUTTON_PIN_2);
  buttonState3 = digitalRead(BUTTON_PIN_3);
  buttonState4 = digitalRead(BUTTON_PIN_4);

   lcd.setCursor(0, 0);
   lcd.print(hour);
   lcd.print(" : ");
   lcd.print(minute);
  // Depending on the state of the buttons, we increase / decrease the hours and minutes
  if(!buttonState1)
  {
    clock.setHour(hour + 1);
    delay(300);
  }
  else if(!buttonState2)
  {
    clock.setHour(hour - 1);
    delay(300);
  }
  else if(!buttonState3)
  {
    clock.setMinute(minute - 1);
    delay(300);
  }
  else if(!buttonState4)
  {
    clock.setMinute(minute + 1);
    delay(300);
  }
}
