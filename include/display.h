#pragma once


// Defining special characters for LCD
#define CURSOR_RIGHT 0x00
#define CURSOR_UP 0x01
#define CURSOR_DOWN 0x02

#define CURSOR_EMPTY 0x03
#define CURSOR_FILL 0x04

extern LiquidCrystal_I2C lcd; 
void todoDevice(byte selectedMenuItem);
void loadDevice(byte selectedMenuItem);
void displayMenu(const Menu_t &menu);
Button_t readPushButton(void);

/* Menu principal */
static const char* MAIN_MENU_ITEMS[] = {"Servo",  
                                        "Stepper",  
                                        "Ultrasound",  
                                        "Humidity", 
                                        "On/Off",
                                        "DHTXX",  
                                        "Analog",  
                                        // "Potentiometer",  
                                        // "Button", 
                                        // "LED",  
                                        " "};
static int EMPTY_PARAMS[0];
static Limits_t EMPTY_LIMITS[0];

static Menu_t MAIN_MENU = {
  MAIN_MENU_ITEMS,
  7,
  EMPTY_PARAMS, 
  0,
  EMPTY_LIMITS,
  &loadDevice
};



static const char* TODO_MENU_ITEMS[] = {"<- Back", "TODO",  " "};

static Menu_t TODO_MENU = {
  TODO_MENU_ITEMS,
  2,
  EMPTY_PARAMS, 
  0,
  EMPTY_LIMITS,
  &todoDevice
};



