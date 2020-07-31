#include "Arduino.h"
#include <Servo.h>
#include <LiquidCrystal_I2C.h>
#include "structs.h"
#include "main.h"
#include "utils.h"
#include "servos.h"


void servoDevice(byte selectedMenuItem) {
    Button_t buttonPressed;      // Contient le bouton appuyé
    bool scroll = false;
 

    if (selectedMenuItem == 0) {
    
        displayMenu(MAIN_MENU);
    }
    else if (selectedMenuItem <= SERVO_MENU.nbParams){
        lcd.setCursor(8, 0);
        lcd.blink_on();	
        lcd.cursor_on();
        /* Attend le relâchement du bouton */


        while (1) {
            lcd.setCursor(8, 0);
            lcd.print("       ");
            lcd.setCursor(8, 0);
            lcd.print(SERVO_PARAMS[selectedMenuItem-1]);

            if (!scroll){
                while(readPushButton() != BP_NONE);
            
                /* Attend l'appui sur un bouton */
                
                while((buttonPressed = readPushButton()) == BP_NONE);

                
                /* Anti rebond pour le bouton */
                delay(30);
                
                /* Attend le relâchement du bouton */
                unsigned long start = millis();
                while(readPushButton() != BP_NONE){
                    if (millis() - start > 500) {
                        scroll = true;
                        break;
                    }
                };



            } else if (readPushButton() == BP_NONE && scroll == true) {
                    scroll = false;
            } else {
                delay(40);
            }
        
        
            /* Gére l'appui sur le bouton */
            switch(buttonPressed) {
                case BP_UP: 
                    if (SERVO_PARAMS[selectedMenuItem-1] < SERVO_LIMITS[selectedMenuItem-1].max) {
                        SERVO_PARAMS[selectedMenuItem-1] = SERVO_PARAMS[selectedMenuItem-1] + SERVO_LIMITS[selectedMenuItem-1].step;
                    }
                    break;

                case BP_DOWN: // Bouton bas = choix suivant
                    if (SERVO_PARAMS[selectedMenuItem-1] > SERVO_LIMITS[selectedMenuItem-1].min) {
                        SERVO_PARAMS[selectedMenuItem-1] = SERVO_PARAMS[selectedMenuItem-1] - SERVO_LIMITS[selectedMenuItem-1].step;
                    }
                    break;
                break;
            
                case BP_SELECT:
                lcd.blink_off();	
                lcd.cursor_off();
                return; 
            }
            
            
        }

    
    }
    else {

        lcd.setCursor(1, 1);
        lcd.print("<<< MOVING >>>");

        Servo myservo;
        int pos = 0; //SERVO_PARAMS[0];
        myservo.attach(3);

        if (SERVO_PARAMS[2]){
            lcd.setCursor(1, 0);
            lcd.print("CANCEL ANY KEY");
            myservo.write(pos);
            for (pos = 0; pos <= SERVO_PARAMS[0]; pos += 1) { // goes from 0 degrees to 180 degrees
                if ((buttonPressed = readPushButton()) == BP_NONE){
                    myservo.write(pos);              // tell servo to go to position in variable 'pos'
                    delay(SERVO_PARAMS[1]);    
                }
                else{
                    break;
                }
            }
        }else{
            lcd.setCursor(1, 0);
            lcd.print("Wait!");
            myservo.write(SERVO_PARAMS[0]);
            delay(1000);
        }
      
        myservo.detach();
        
    }

}