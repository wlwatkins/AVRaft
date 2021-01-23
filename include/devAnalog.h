#pragma once


void analogDevice(byte selectedMenuItem);


static const char* ANALOG_MENU_ITEMS[] = {"<-Back | A0",  "Max: ",  "Min: ", "Inv: ", "MEASURE",  " "};
static int ANALOG_PARAMS[] = {1015,  20, 0};
static Limits_t ANALOG_LIMITS[] = {{0, 2000, 5}, {0, 2000, 5}, {0, 1, 1}};

static Menu_t ANALOG_MENU = {
  ANALOG_MENU_ITEMS,
  5,
  ANALOG_PARAMS,
  3,
  ANALOG_LIMITS,
  &analogDevice
};
