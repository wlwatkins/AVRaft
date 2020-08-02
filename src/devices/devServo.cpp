#include "Arduino.h"
#include <Servo.h>
#include <LiquidCrystal_I2C.h>
#include "structs.h"
#include "main.h"
#include "utils.h"
#include "devices.h"

// SERVO MOTOR
void servoDevice(byte selectedMenuItem) {
    Button_t buttonPressed;      // Contient le bouton appuyé
    bool scroll = false;

    Menu_t MENU = SERVO_MENU;

 
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
        lcd.setCursor(1, 1);
        lcd.print("<<< MOVING >>>");

        Servo myservo;
        int pos = 0; //SERVO_PARAMS[0];
        myservo.attach(3);

        if (MENU.params[2]){
            lcd.setCursor(1, 0);
            lcd.print("CANCEL ANY KEY");
            myservo.write(pos);
            for (pos = 0; pos <= MENU.params[0]; pos += 1) { // goes from 0 degrees to 180 degrees
                if ((buttonPressed = readPushButton()) == BP_NONE){
                    myservo.write(pos);              // tell servo to go to position in variable 'pos'
                    delay(MENU.params[1]);    
                }
                else {
                    break;
                } 
            }
        }else{
            lcd.setCursor(1, 0);
            lcd.print("Wait!");
            myservo.write(MENU.params[0]);
            delay(1000);
        }
      
        myservo.detach();
        digitalWrite(LED_BUILTIN, LOW);
        
    }


}

