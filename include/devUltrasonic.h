#pragma once


void usDevice(byte selectedMenuItem);


static const char* US_MENU_ITEMS[] = {"<-Back | D T3E4",  "Max: ", "MEASURE",  " "};
static int US_PARAMS[] = {200};
static Limits_t US_LIMITS[] = {{0, 500, 1}};

static Menu_t US_MENU = {
  US_MENU_ITEMS,
  3,
  US_PARAMS,
  1,
  US_LIMITS,
  &usDevice
};
