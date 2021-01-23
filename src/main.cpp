#include "Arduino.h"
#include <Wire.h> 
#include <Servo.h>
#include <LiquidCrystal_I2C.h>
#include "pinConfig.h"
#include "display.h"
#include "structs.h"
#include "devices.h"




void setup() {
 
  // initialise pins.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(PinBTN_DOWN, INPUT);
  pinMode(PinBTN_SELECT, INPUT);
  pinMode(PinBTN_UP, INPUT);

  lcd.init();  // initialize the lcd 

  // Creating hex array for each special characters
  uint8_t cursorRight[8]  = {0x00,0x08,0x04,0x02,0x04,0x08,0x00,0x00};
  uint8_t cursorUp[8] = {0x00,0x00,0x00,0x00,0x04,0x0E,0x1F,0x00};
  uint8_t cursorDown[8] = {0x00,0x1F,0x0E,0x04,0x00,0x00,0x00,0x00};

  uint8_t boxEmpty[8] = {0x1B,0x11,0x00,0x00,0x00,0x00,0x11,0x1B};
  uint8_t boxFill[8] = {0x1B,0x15,0x0E,0x1F,0x1F,0x0E,0x15,0x1B};

  // Creating special characters
  lcd.createChar(CURSOR_RIGHT, cursorRight);
  lcd.createChar(CURSOR_UP, cursorUp);
  lcd.createChar(CURSOR_DOWN, cursorDown);
  lcd.createChar(CURSOR_EMPTY, boxEmpty);
  lcd.createChar(CURSOR_FILL, boxFill);

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