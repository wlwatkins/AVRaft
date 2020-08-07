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
        case 2:
            usDevice(255) ;
        case 3:
            humidityDevice(255) ;
        case 4:
            onoffDevice(255) ;
        case 5:
            dhtxxDevice(255) ;
        case 6:
            analogDevice(255) ;
        default:
            displayMenu(TODO_MENU);
    }

}
