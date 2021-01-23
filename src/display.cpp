#include "Arduino.h"
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

#include "structs.h"
#include "pinConfig.h"
#include "display.h"
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

// readPushButton reads which button is pressed and returns the enum.
// If no button is pressed, it returns BP_NONE.
Button_t readPushButton(void) {
  if (digitalRead(PinBTN_DOWN)) {return BP_DOWN;}
  else if (digitalRead(PinBTN_SELECT)) {return BP_SELECT;}
  else if (digitalRead(PinBTN_UP)) {return BP_UP;}
  else {return BP_NONE;}
}


// displayMenu prints the menu parsed in argument to the LCD screen.
// If the menu has parameters, it will print them also.
void displayMenu(const Menu_t &menu) {
 
  byte selectedMenuItem = 0;   // determined which item is selected
  Button_t buttonPressed;      // contains which but is pressed
 
  // Inifite loop whilst the menu is idle
  while(1) {
 
    // Prints the different cursors on the screen
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.write(CURSOR_RIGHT); // prints ">" cursor.

    if (selectedMenuItem > 0){ // prints up cursor on the far right only if not at top
        lcd.setCursor(15,0);
		lcd.write(CURSOR_UP);
    }
    if (selectedMenuItem < menu.nbItems-1){ // prints down cursor on the far right only if not at bottom
        lcd.setCursor(15,1);
		lcd.write(CURSOR_DOWN);
    }

    // Prints the nth and nth+1 items from the given menu
    lcd.setCursor(1, 0);
    lcd.print(menu.items[selectedMenuItem]);
    lcd.setCursor(1, 1);
    lcd.print(menu.items[selectedMenuItem+1]);

    // Checks if there are parameters
    switch (menu.nbParams) {
      case 0: // if not, breaks the switch (case of main menu)
        break;
      default:
        // If there are paramaters, make sure to only print the paramters on the correct lines
        if (selectedMenuItem == 0){ 
          lcd.setCursor(8, 1);
          lcd.print(menu.params[selectedMenuItem]);
        } 
        else if (selectedMenuItem > 0 && selectedMenuItem < menu.nbParams) { 
          lcd.setCursor(8, 0);
          lcd.print(menu.params[selectedMenuItem-1]);
          lcd.setCursor(8, 1);
          lcd.print(menu.params[selectedMenuItem]);
        }
        else if (selectedMenuItem == menu.nbParams) {     
          lcd.setCursor(8, 0);
          lcd.print(menu.params[selectedMenuItem-1]);
        }
    }
    
 
    // Check which button pressed (This method allows to activate on release)
    while(readPushButton() != BP_NONE);
    while((buttonPressed = readPushButton()) == BP_NONE);
    delay(30); // For debouncing
    while(readPushButton() != BP_NONE);
 
    // Process which button is pressed
    switch(buttonPressed) {
    case BP_UP:
      if(selectedMenuItem > 0) {
        selectedMenuItem--; // decrement variable if not at top of list
      }else { // if reach top, round back to bottom
        selectedMenuItem = menu.nbItems-1;
      }
      break;

    case BP_DOWN: 
      if(selectedMenuItem < (menu.nbItems - 1)) {
        selectedMenuItem++; // increment variable unless at bottom of list
      } else { // if reach bottom, round back to top
        selectedMenuItem = 0;
      }
      break;
  
    case BP_SELECT:
      menu.callbackFnct(selectedMenuItem); // trigger function from struct 
      break;   
    }
  }
}
