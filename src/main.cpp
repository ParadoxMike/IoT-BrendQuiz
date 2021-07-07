//A programm for the module "The Fundamentals of IoT" at Furtwangen University
//written my Mike Blank OMB in C for an ESP 32 DevKit
// utilized libs (used versions included in /lib):
// AsyncTCP - https://github.com/me-no-dev/AsyncTCP
// Bounce2 - https://github.com/thomasfredericks/Bounce2
// ESPAsyncWebServer - https://github.com/me-no-dev/ESPAsyncWebServer
// LiquidCrystal_I2C - https://github.com/johnrickman/LiquidCrystal_I2C

//helper functions, pin setup, WiFi webserver and lcd setup are located in seperate headder files (/include)

//define global veriables
int question = 1; //safe current question
int question_brfore = 1; //safe last question
bool question_state[5][3] = {{false, false, false}, {false, false, false}, {false, false, false}, {false, false, false}, {false, false, false}}; //safe current state of every awnser given by the user
bool answers[5][3] = {{true, false, false}, {false, false, true}, {false, true, false}, {true, false, false}, {false, false, true}}; //safe the answerkey
unsigned long counter; //safe te value of millis() to give the user 1 sec. to double press to confirm awnsers
bool finish_press = 0; //safe if continiue as been pressed already for the doubble press
unsigned long counter_sleep; //safe te value of millis() to send the esp tp sleep afer 40 sec. without any interaction.

#include <Arduino.h>

// include helper stuff and other code
#include "webserver.h"
#include "pins.h"
#include "functions.h"
#include "lcd.h"

void setup(){
    Serial.begin(115200); //Start Serial-Monitor for debugging

    //call setup funcions of webserver.h, pins.h and lcd.h
    setupWebserver();
    setupPins();
    setupLCD();

    //setup sleep wakeup on the back button
    esp_sleep_enable_ext0_wakeup(GPIO_NUM_25,1);

    ledTest(); //test all leds
    counter_sleep = millis(); //initiallize the counter for esp sleep 
}

void loop(){
    setQuestion(question, question_brfore, question_state);

    //safe the qestion state according to the button pressed and reset sleep counter
    if(analogRead(button_pin_A) >= adc_on_level){
        question_state[question-1][0] = true;
        question_state[question-1][1] = false;
        question_state[question-1][2] = false;
        counter_sleep = millis();
    }
    if(analogRead(button_pin_B) >= adc_on_level){
        question_state[question-1][0] = false;
        question_state[question-1][1] = true;
        question_state[question-1][2] = false;
        counter_sleep = millis();
    }
    if(analogRead(button_pin_C) >= adc_on_level){
        question_state[question-1][0] = false;
        question_state[question-1][1] = false;
        question_state[question-1][2] = true;
        counter_sleep = millis();
    }
    
    //handle the lcd and other stuff according to witch question is active
    lcd.setCursor(0,0); 
    switch (question)
    {
    case 1:
        lcd.print("Frage 1");
        break;
    case 2:
        lcd.print("Frage 2");
        break;
    case 3:
        lcd.print("Frage 3");
        break;
    case 4:
        lcd.setCursor(0,1);
        lcd.print("                ");
        lcd.setCursor(0,0);
        lcd.print("Frage 4");
        break;
    case 5:
        lcd.print("Frage 5");
        lcd.setCursor(0,1);
        lcd.print("Fertig? 2xWeiter");
        break;
    case 6:
        digitalWrite(question_5, LOW);
        lcd.setCursor(0,0);
        lcd.print("Dein Score: ");
        lcd.print(getScore(question_state, answers));
        lcd.print("/5");
        lcd.setCursor(0,1);
        lcd.print("  Vielen Dank!  ");
        break;
    default:
        break;
    }

    question_brfore = question;

    //handle next being pressed
    startNextButton.update();
    if(startNextButton.rose()){ //check for "next" button to be presset and increment qestion
        counter_sleep = millis();

        if(question < 5){
            question++;
        }
        else if(question == 5 && !finish_press){
            counter = millis();
            finish_press = 1;
        }
        else if(question==5 && finish_press && millis()-counter <= 1000){
            question = 6;
        }
        else if(question==6){
            lcd.noBacklight();
            lcd.noDisplay();
            digitalWrite(LED_data_1, LOW);
            digitalWrite(LED_data_2, LOW);
            digitalWrite(LED_data_3, LOW);
            digitalWrite(LED_data_4, LOW);
            updateAllQuestion();
            esp_deep_sleep_start();
        }
    }
    if(question==5 && finish_press && millis()-counter > 1000) { //reset if not pressed in time a second time
        finish_press = 0;
    }

    //handle previous being pressed
    previousButton.update();
    if(previousButton.rose()){ //check for "prev" button to be presset and decrement qestion
        counter_sleep = millis();

        if(question > 1 && question < 6)
            question--;
    }

    //send esp to sleep aver 40sec. without interaction
    if(millis()-counter_sleep > 40000){
            lcd.noBacklight();
            lcd.noDisplay();
            digitalWrite(LED_data_1, LOW);
            digitalWrite(LED_data_2, LOW);
            digitalWrite(LED_data_3, LOW);
            digitalWrite(LED_data_4, LOW);
            updateAllQuestion();
            esp_deep_sleep_start();
    }
}