#include <Arduino.h>

#include "webserver.h"
#include "pins.h"
#include "functions.h"
#include "lcd.h"

int question = 1;

bool next = 0;
bool prev = 0;

void setup(){
    Serial.begin(115200); //Start Serial-Monitor for debugging

    setupWebserver();
    setupPins();
    setupLCD();

    ledTest();
}

void loop(){
    // for (int i = 1; i < 6; i++){
    //     handleQuestion(i);
    //     delay(1000);

    //     if(i % 2 == 0)
    //         lcd.noBacklight();
    //     else
    //         lcd.backlight();
    // }

    if(buttonPressed(startNextButton)){
            Serial.println("next");
    } 

    if(buttonPressed(previousButton)){
            Serial.println("prev");
    }
    // if(startNextButton.update()){
    //     if (startNextButton.rose())
    //         Serial.println("next");
    // } 

    // if(previousButton.update()){
    //     if (previousButton.rose())
    //         Serial.println("prev");
    // }
}