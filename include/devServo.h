#pragma once


void servoDevice(byte selectedMenuItem);


static const char* SERVO_MENU_ITEMS[] = {"<-Back | D3",  "Angle: ",  "Delay: ", "w/ rst: ", "MOVE",  " "};
static int SERVO_PARAMS[] = {90,  5, 1};
static Limits_t SERVO_LIMITS[] = {{0, 180, 1}, {0, 50, 1}, {0, 1, 1}};

static Menu_t SERVO_MENU = {
  SERVO_MENU_ITEMS,
  5,
  SERVO_PARAMS,
  3,
  SERVO_LIMITS,
  &servoDevice
};
