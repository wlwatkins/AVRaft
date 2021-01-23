#include "Arduino.h"
#include <LiquidCrystal_I2C.h>
#include "structs.h"
#include "display.h"
#include "devices.h"


void onoffDevice(byte selectedMenuItem) {
    Button_t buttonPressed;      // Contient le bouton appuyé
    bool scroll = false;

    Menu_t MENU = ONOFF_MENU;

 
    if (selectedMenuItem == 0){
         displayMenu(MAIN_MENU);
    }
    else if (selectedMenuItem == 255){
         displayMenu(MENU);
    }
    else if (selectedMenuItem <= MENU.nbParams){
        lcd.setCursor(8, 0);
        lcd.blink_on();	
        lcd.cursor_on();


        while (1) {
            lcd.setCursor(8, 0);
            lcd.print("       ");
            lcd.setCursor(8, 0);
            lcd.print(MENU.params[selectedMenuItem-1]);

            if (!scroll){
                while(readPushButton() != BP_NONE);
                while((buttonPressed = readPushButton()) == BP_NONE);
                delay(30);
                
                unsigned long start = millis();
                while(readPushButton() != BP_NONE){
                    if (millis() - start > 500) {
                        scroll = true;
                        break;
                    }
                };

            } 
            else if (readPushButton() == BP_NONE && scroll == true) {
                scroll = false;
            }
            else {
                delay(40);
            }
        
            /* Gére l'appui sur le bouton */
            switch(buttonPressed) {
                case BP_UP: 
                    if (MENU.params[selectedMenuItem-1] < MENU.limits[selectedMenuItem-1].max) {
                        MENU.params[selectedMenuItem-1] = MENU.params[selectedMenuItem-1] + MENU.limits[selectedMenuItem-1].step;
                    }
                    break;

                case BP_DOWN: // Bouton bas = choix suivant
                    if (MENU.params[selectedMenuItem-1] > MENU.limits[selectedMenuItem-1].min) {
                        MENU.params[selectedMenuItem-1] = MENU.params[selectedMenuItem-1] - MENU.limits[selectedMenuItem-1].step;
                    }
                    break;
            
                case BP_SELECT:
                    lcd.blink_off();	
                    lcd.cursor_off();
                    return; 
            }
            
            
        }

    
    }
    else {


        digitalWrite(LED_BUILTIN, HIGH);
        lcd.clear();
        lcd.setCursor(1, 0);
        lcd.print("CANCEL ANY KEY");

        int state = LOW;
        unsigned long previousMillis = 0;
        const long interval = MENU.params[0];
        int pin = 3;

        pinMode(pin, OUTPUT);

        int oldState;

        while ((buttonPressed = readPushButton()) == BP_NONE){

            unsigned long currentMillis = millis();

            unsigned long delta = currentMillis - previousMillis;

            if (delta >= interval && interval > 0 && MENU.params[1] == 1) {
                // save the last time you blinked the LED
                previousMillis = currentMillis;

                // if the LED is off turn it on and vice-versa:
                if (state == LOW) {
                    state = HIGH;
                } else {
                    state = LOW;
                }

                // set the LED with the ledState of the variable:
                digitalWrite(pin, state);
            }
            else if (MENU.params[1] == 0){
                state = HIGH;
                digitalWrite(pin, state);
            }

            if (oldState != state) {
                oldState = state;
                lcd.setCursor(1, 1);
                lcd.print("               ");
                lcd.setCursor(1, 1);
                lcd.print("PIN STATE: ");
                if (state) {
                    lcd.print("HIGH");
                }
                else{
                    lcd.print("LOW");
                }
            }
        }

        digitalWrite(pin, LOW);
        digitalWrite(LED_BUILTIN, LOW);
    }

    
}

