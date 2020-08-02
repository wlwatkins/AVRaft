#include "Arduino.h"
#include <Servo.h>
#include <LiquidCrystal_I2C.h>
#include "structs.h"
#include "main.h"
#include "utils.h"
#include "devices.h"





void todoDevice(byte selectedMenuItem) {
 
  switch (selectedMenuItem) {
    case 0:
      displayMenu(MAIN_MENU);
  }

}


void loadDevice(byte selectedMenuItem) {
    // Case value is the possition of the device in the main menu (see utils.h)
    switch (selectedMenuItem) {
        case 0:
            servoDevice(255) ;
        case 1:
            stepperDevice(255) ;
        default:
            displayMenu(TODO_MENU);
    }

}
