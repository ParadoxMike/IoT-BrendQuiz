#include <Arduino.h>

#include "webserver.h"
#include "pins.h"
#include "functions.h"

void setup(){
    Serial.begin(115200); //Start Serial-Monitor for debugging

    setupWebserver();
    setupPins();
}

void loop(){
    
}