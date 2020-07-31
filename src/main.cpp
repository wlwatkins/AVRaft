/* Inclut la librairie LiquidCrystal pour le LCD */
#include "Arduino.h"
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include "structs.h"
#include "main.h"
#include "menus.h"

 
/* Objet LCD sur les broches utilisées par la shield LCD DFrobots */
LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

#define CURSOR_RIGHT 0x00
#define CURSOR_UP 0x01
#define CURSOR_DOWN 0x02

#define BTN_SELECT 11
#define BTN_UP 12
#define BTN_DOWN 10
uint8_t cursorRight[8]  = {0x00,0x08,0x04,0x02,0x04,0x08,0x00,0x00};
uint8_t cursorUp[8] = {0x00,0x00,0x00,0x00,0x04,0x0E,0x1F,0x00};
uint8_t cursorDown[8] = {0x00,0x1F,0x0E,0x04,0x00,0x00,0x00,0x00};


/** Fonction retournant le bouton appuyé (s’il y en a un). */
Button_t readPushButton(void) {

  if (digitalRead(BTN_DOWN)){
      return BP_DOWN;
  }else if (digitalRead(BTN_SELECT)){
      return BP_SELECT;
  }else if (digitalRead(BTN_UP)){
      return BP_UP;
  }else
  {
      return BP_NONE;
  }
  
}
 
/** Affiche le menu passé en argument */
void displayMenu(const Menu_t &menu) {
 
  /* Variable pour le menu */
  byte selectedMenuItem = 0;   // Choix selectionné
  Button_t buttonPressed;      // Contient le bouton appuyé
 
  /* Tant que l'utilisateur ne veut pas quitter pas le menu */
  while(1) {
 
    /* Affiche le menu */
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.write(CURSOR_RIGHT);
    if (selectedMenuItem > 0){
      lcd.setCursor(15,0);
		  lcd.write(CURSOR_UP);
    }
    if (selectedMenuItem < menu.nbItems-1){
      lcd.setCursor(15,1);
		  lcd.write(CURSOR_DOWN);
    }

    lcd.setCursor(1, 0);
    lcd.print(menu.items[selectedMenuItem]);
    lcd.setCursor(1, 1);
    lcd.print(menu.items[selectedMenuItem+1]);


    switch (menu.nbParams) {
      case 0:
        break;
      default:
        if (selectedMenuItem == 0 && menu.nbParams > 0){
          lcd.setCursor(8, 1);
          lcd.print(menu.params[selectedMenuItem]);
        } 
        else if (selectedMenuItem > 0 && selectedMenuItem < menu.nbParams && menu.nbParams > 0) {
          lcd.setCursor(8, 0);
          lcd.print(menu.params[selectedMenuItem-1]);
          lcd.setCursor(8, 1);
          lcd.print(menu.params[selectedMenuItem]);
        }
        else if (selectedMenuItem == menu.nbParams &&  menu.nbParams > 0) {
    
          lcd.setCursor(8, 0);
          lcd.print(menu.params[selectedMenuItem-1]);
        }
    }
    
 
    /* Attend le relâchement du bouton */
    while(readPushButton() != BP_NONE);
 
    /* Attend l'appui sur un bouton */
    while((buttonPressed = readPushButton()) == BP_NONE);
 
    /* Anti rebond pour le bouton */
    delay(30);
 
    /* Attend le relâchement du bouton */
    while(readPushButton() != BP_NONE);
 
    /* Gére l'appui sur le bouton */
    switch(buttonPressed) {
    case BP_UP: // Bouton haut = choix précédent
 
      /* Si il existe un choix précédent */
      if(selectedMenuItem > 0) {
 
        /* Passe au choix précédent */
        selectedMenuItem--;
      }
      break;
 
    case BP_DOWN: // Bouton bas = choix suivant
 
      /* Si il existe un choix suivant */
      if(selectedMenuItem < (menu.nbItems - 1)) {
 
        /* Passe au choix suivant */
        selectedMenuItem++;
      }
      break;
  
    case BP_SELECT:
      menu.callbackFnct(selectedMenuItem);
      break;   
    }
  }
}

 
/** Setup */
void setup() {
 
  // initialize LED digital pin as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(BTN_SELECT, INPUT);
  pinMode(BTN_UP, INPUT);
  pinMode(BTN_DOWN, INPUT);

  lcd.init();                      // initialize the lcd 
  lcd.createChar(CURSOR_RIGHT, cursorRight);
  lcd.createChar(CURSOR_UP, cursorUp);
  lcd.createChar(CURSOR_DOWN, cursorDown);
  lcd.backlight();


}
 
/** Programme principal */
void loop() {
 
  /* Affiche le menu principal */
  displayMenu(MAIN_MENU);
 
}