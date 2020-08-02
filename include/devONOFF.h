#pragma once


void onoffDevice(byte selectedMenuItem);


static const char* ONOFF_MENU_ITEMS[] = {"<-Back | D3",  "Delay : ", "Cycle: ", "RUN",  " "};
static int ONOFF_PARAMS[] = {500, 1};
static Limits_t ONOFF_LIMITS[] = {{0, 30000, 10}, {0, 1, 1}};

static Menu_t ONOFF_MENU = {
  ONOFF_MENU_ITEMS,
  4,
  ONOFF_PARAMS,
  2,
  ONOFF_LIMITS,
  &onoffDevice
};
