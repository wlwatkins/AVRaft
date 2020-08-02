#pragma once


void stepperDevice(byte selectedMenuItem);


static const char* STEPPER_MENU_ITEMS[] = {"<-Back | D3658",  "CW: ", "Speed: ",  "Delay: ", "S/rev: ", "MOVE",  " "};
static int STEPPER_PARAMS[] = {1,  5, 5, 2048};
static Limits_t STEPPER_LIMITS[] = {{0, 1, 1}, {1, 15, 1}, {0, 100, 1}, {0, 4096, 2}};

static Menu_t STEPPER_MENU = {
  STEPPER_MENU_ITEMS,
  6,
  STEPPER_PARAMS,
  4,
  STEPPER_LIMITS,
  &stepperDevice
};
