#include "Arduino.h"
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include <LiquidCrystal_I2C.h>
#include "structs.h"
#include "main.h"
#include "utils.h"
#include "devices.h"




void dhtxxDevice(byte selectedMenuItem) {
    Button_t buttonPressed;      // Contient le bouton appuyé
    bool scroll = false;

    Menu_t MENU = DHTXX_MENU;

 
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

        int DHTTYPE;


        switch (MENU.params[0]) {
            case 1:
                DHTTYPE = 11;   // DHT 11
            case 2:
                DHTTYPE = 21;  // DHT 21 (AM2301)
            case 3:
                DHTTYPE = 22;  // DHT 22 (AM2302)
        }

        String error = "";
        unsigned long previousMillis = 0;

        DHT_Unified dht(2, DHTTYPE);

        uint32_t delayMS;

        dht.begin();

        sensor_t sensor;
        
        dht.humidity().getSensor(&sensor);

        // Set delay between sensor readings based on sensor details.
        delayMS = sensor.min_delay / 1000;


        int oldTemp;
        int newTemp;
        int oldHum;
        int newHum;

        while ((buttonPressed = readPushButton()) == BP_NONE){

            unsigned long currentMillis = millis();
            unsigned long delta = currentMillis - previousMillis;

            if (delta >= delayMS && delayMS > 0) {
                // save the last time you blinked the LED
                previousMillis = currentMillis;

                sensors_event_t event;
                dht.temperature().getEvent(&event);
                if (isnan(event.temperature)) {
                    error = "Error temp.";
                }
                else {
                    newTemp = event.temperature;
                    error = "";
                }
                // Get humidity event and print its value.
                dht.humidity().getEvent(&event);
                if (isnan(event.relative_humidity)) {
                    error = "Error hum.";
                }
                else {
                    newHum = event.relative_humidity;
                    error = "";
                }


            }

            if (error != "") {
                lcd.setCursor(0, 1);
                lcd.print("                ");
                lcd.setCursor(0, 1);
                lcd.print(error);
            }
            else if (oldTemp != newTemp || oldHum != newHum ) {
                oldTemp = newTemp;
                oldHum = newHum;
                lcd.setCursor(0, 1);
                lcd.print("                ");
                lcd.setCursor(0, 1);
                lcd.print("T: ");
                lcd.print(newTemp);
                lcd.print("C  H: ");
                lcd.print(newHum);
                lcd.print("%");
            }


        }

        digitalWrite(LED_BUILTIN, LOW);
    }

    
}

