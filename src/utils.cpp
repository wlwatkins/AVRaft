#include "Arduino.h"
#include "structs.h"
#include "main.h"
#include "menus.h"
#include "utils.h"

void listenBtn(bool scroll, Button_t buttonPressed) {
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
        delay(50);
    }
}