#include "Arduino.h"
#include <Stepper.h>
#include <LiquidCrystal_I2C.h>
#include "structs.h"
#include "display.h"
#include "devices.h"


// STEPPER MOTOR
void stepperDevice(byte selectedMenuItem) {
    Button_t buttonPressed;      // Contient le bouton appuyé
    bool scroll = false;

    Menu_t MENU = STEPPER_MENU;

 
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
        lcd.setCursor(1, 1);
        lcd.print("<<< MOVING >>>");

        int stepsPerRevolution = MENU.params[3];

        Stepper myStepper(stepsPerRevolution, 3, 6, 5, 8);
        int stepCount = 0;  // number of steps the motor has taken
        myStepper.setSpeed(MENU.params[1]);
        // int motorSpeed = map(MENU.params[1], 0, 20, 0, 100);
        int step ;
        if (MENU.params[0] == 1) {
            step = 1;
        }
        else{
            step = -1;
        }

        while ((buttonPressed = readPushButton()) == BP_NONE){


                
                myStepper.step(step);
                stepCount++;
                delay(MENU.params[2]);
        }



        digitalWrite(LED_BUILTIN, LOW);
        
    }


}

