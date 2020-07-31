#pragma once

#ifndef _MENU_H_
#define _MENU_H_



void servoDevice(byte selectedMenuItem);

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

static const char* SERVO_MENU_ITEMS[] = {"<-Back | D3",  "Angle: ",  "Delay: ", "w/ rst: ", "MOVE",  " "};
static int SERVO_PARAMS[] = {180,  5, 1};
static Limits_t SERVO_LIMITS[] = {{0, 180, 1}, {0, 50, 1}, {0, 1, 1}};

static Menu_t SERVO_MENU = {
  SERVO_MENU_ITEMS,
  5,
  SERVO_PARAMS,
  3,
  SERVO_LIMITS,
  &servoDevice
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

#endif /* _MENU_H_ */