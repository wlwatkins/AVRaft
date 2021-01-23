#include "Arduino.h"
#include <LiquidCrystal_I2C.h>
#include "structs.h"
#include "display.h"
#include "devices.h"

void humidityDevice(byte selectedMenuItem) {
    Button_t buttonPressed;      // Contient le bouton appuyé
    bool scroll = false;

    Menu_t MENU = HUMIDITY_MENU;

 
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


        int soilMoistureValue;
        int oldSoilMoistureValue = 0;
        int soilmoisturepercent;

        while ((buttonPressed = readPushButton()) == BP_NONE){
            soilMoistureValue = analogRead(A0);  //put Sensor insert into soil
            soilmoisturepercent = map(soilMoistureValue, MENU.params[0], MENU.params[1], 0, 100);

            if (oldSoilMoistureValue != soilMoistureValue){
                oldSoilMoistureValue = soilMoistureValue;
                lcd.setCursor(0, 1);
                lcd.print("V:               ");
                lcd.setCursor(3, 1);
                lcd.print(soilMoistureValue);

                if(soilmoisturepercent > 100) {
                    soilmoisturepercent = 100;
                }
                else if(soilmoisturepercent <0){
                    soilmoisturepercent = 0;
                }

                lcd.setCursor(7, 1);
                lcd.print("<=> ");
                lcd.print(soilmoisturepercent);
                lcd.print("%");
            }
            delay(100);

             
           
        }

        digitalWrite(LED_BUILTIN, LOW);
        
    }


}

