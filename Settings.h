// Pins to which the buttons are connected
#define BUTTON_PIN_1 0
#define BUTTON_PIN_2 1
#define BUTTON_PIN_3 4
#define BUTTON_PIN_4 5

RTC clock;                          // Creating an object for working with a real-time clock
LiquidCrystal_I2C lcd(0x3F, 16, 2); // Creating a screen object, passing the address used and the screen resolution
