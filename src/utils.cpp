#include "Arduino.h"
#include <Servo.h>
#include <LiquidCrystal_I2C.h>
#include "structs.h"
#include "main.h"
#include "utils.h"
#include "servos.h"






void todoDevice(byte selectedMenuItem) {
 
  /* Cas spécial pour Dr Freeman */
  switch (selectedMenuItem) {
    case 0:
      displayMenu(MAIN_MENU);
  }

}


void loadDevice(byte selectedMenuItem) {
 
  /* Cas spécial pour Dr Freeman */
  switch (selectedMenuItem) {
    case 0:
      displayMenu(SERVO_MENU);
    default:
      displayMenu(TODO_MENU);
  }

}