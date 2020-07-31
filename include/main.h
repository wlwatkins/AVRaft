#pragma once
#ifndef _MAIN_H_
#define _MAIN_H_
#include <LiquidCrystal_I2C.h>
#include "menus.h"
#include "main.h"
#include "structs.h"

void displayMenu(const Menu_t &menu);
Button_t readPushButton(void);

extern LiquidCrystal_I2C lcd; 

#endif /* _MAIN_H_ */