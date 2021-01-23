#include "Arduino.h"
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include "structs.h"
#include "main.h"
#include "utils.h"
#include "devices.h"

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

// Defining special characters for LCD
#define CURSOR_RIGHT 0x00
#define CURSOR_UP 0x01
#define CURSOR_DOWN 0x02

// Creating hex array for each special characters
uint8_t cursorRight[8]  = {0x00,0x08,0x04,0x02,0x04,0x08,0x00,0x00};
uint8_t cursorUp[8] = {0x00,0x00,0x00,0x00,0x04,0x0E,0x1F,0x00};
uint8_t cursorDown[8] = {0x00,0x1F,0x0E,0x04,0x00,0x00,0x00,0x00};

uint8_t boxEmpty[8] = {0x1B,0x11,0x00,0x00,0x00,0x00,0x11,0x1B};
uint8_t boxFill[8] = {0x1B,0x15,0x0E,0x1F,0x1F,0x0E,0x15,0x1B};

// // Defining pins for buttons ENUM
enum PinBTN {
  PinBTN_DOWN = 10, PinBTN_SELECT, PinBTN_UP
};

/* Listes des touches de la shield lcd DFrobots */
typedef enum {
  BP_NONE,   // Aucun bouton appuyé
  BP_DOWN,     // Bouton bas
  BP_SELECT, // Bouton SELECT
  BP_UP,     // Bouton haut
} Button_t;

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

 
void setup() {
 
  // initialise pins.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(BTN_SELECT, INPUT);
  pinMode(BTN_UP, INPUT);
  pinMode(BTN_DOWN, INPUT);

  lcd.init();  // initialize the lcd 

  // Creating special characters
  lcd.createChar(CURSOR_RIGHT, cursorRight);
  lcd.createChar(CURSOR_UP, cursorUp);
  lcd.createChar(CURSOR_DOWN, cursorDown);

  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("AVRaft v0.1");
  lcd.setCursor(0, 1);
  lcd.print("   by willmendil");
  //Turning LCD backligth on
  delay(2500);

}
 

void loop() {
 
  displayMenu(MAIN_MENU); //This actually launches the whole system by first showing the main menu
 
}