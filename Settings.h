// пины к которым подключены кнопки
#define BUTTON_PIN_1 0
#define BUTTON_PIN_2 1
#define BUTTON_PIN_3 4
#define BUTTON_PIN_4 5

RTC clock;                          // Создаю объект для работы с часами реального времени
LiquidCrystal_I2C lcd(0x3F, 16, 2); // Создаю объект-экран, передаю используемый адрес и разрешение экрана
