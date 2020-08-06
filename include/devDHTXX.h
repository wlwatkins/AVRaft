#pragma once


void dhtxxDevice(byte selectedMenuItem);


static const char* DHTXX_MENU_ITEMS[] = {"<-Back | D2", "Type: ", "MEASURE",  " "};
static int DHTXX_PARAMS[] = {3};
static Limits_t DHTXX_LIMITS[] = {{1, 3, 1}};

static Menu_t DHTXX_MENU = {
  DHTXX_MENU_ITEMS,
  3,
  DHTXX_PARAMS,
  1,
  DHTXX_LIMITS,
  &dhtxxDevice
};
