#include <Arduino.h>

#include "webserver.h"
#include "pins.h"
#include "functions.h"

int question = 1;

void setup(){
    Serial.begin(115200); //Start Serial-Monitor for debugging

    setupWebserver();
    setupPins();

    ledTest();
}

void loop(){
    for (int i = 1; i < 6; i++){
        handleQuestion(i);
        delay(1000);
    }
}