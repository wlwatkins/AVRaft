#pragma once

void todoDevice(byte selectedMenuItem);

void loadDevice(byte selectedMenuItem) ;

/* Menu principal */
static const char* MAIN_MENU_ITEMS[] = {"Servo",  "Stepper",  "DC motor",  "Relay",  "Ultrasound",  "Potentiometer",  "Button",   " "};
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

