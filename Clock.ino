#include <Wire.h>                   // библиотека для работы I²C
#include "TroykaRTC.h"              // библиотека для работы с часами реального времени
#include <LiquidCrystal_I2C.h>      // подключаем библиотеку LiquidCrystal_I2C
#include "Settings.h"
#include "Var.h"

 
void setup()
{
  clock.begin();                              // инициализация часов
  //clock.set(10,25,45,27,07,2005,THURSDAY);  // метод установки времени и даты в модуль вручную
  clock.set(__TIMESTAMP__);                   // метод установки времени и даты автоматически при компиляции

  lcd.init();
  lcd.backlight();
}
 
void loop()
{
  clock.read();                         // запрашиваем данные с часов
  // считываем показания часов и минут в переменные
  hour = clock.getHour();
  minute = clock.getMinute();
  // считываем состояние пина
  buttonState1 = digitalRead(BUTTON_PIN_1);
  buttonState2 = digitalRead(BUTTON_PIN_2);
  buttonState3 = digitalRead(BUTTON_PIN_3);
  buttonState4 = digitalRead(BUTTON_PIN_4);

   lcd.setCursor(0, 0);
   lcd.print(hour);
   lcd.print(" : ");
   lcd.print(minute);
  // в зависимости от состояние кнопок увеличиваем / уменьшаем часы и минуты
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
