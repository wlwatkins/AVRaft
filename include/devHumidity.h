#pragma once


void humidityDevice(byte selectedMenuItem);


static const char* HUMIDITY_MENU_ITEMS[] = {"<-Back | A0",  "Dry V: ",  "Wet V: ", "MEASURE",  " "};
static int HUMIDITY_PARAMS[] = {600,  250};
static Limits_t HUMIDITY_LIMITS[] = {{0, 1000, 5}, {0, 1000, 5}};

static Menu_t HUMIDITY_MENU = {
  HUMIDITY_MENU_ITEMS,
  4,
  HUMIDITY_PARAMS,
  2,
  HUMIDITY_LIMITS,
  &humidityDevice
};
