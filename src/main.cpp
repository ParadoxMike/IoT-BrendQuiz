#include <Arduino.h>
//globals
int question = 1;
int question_brfore = 1;
bool question_state[5][3] = {{false, false, false}, {false, false, false}, {false, false, false}, {false, false, false}, {false, false, false}};
bool answers[5][3] = {{true, false, false}, {false, false, true}, {false, true, false}, {true, false, false}, {false, false, true}};
unsigned long counter;
unsigned long counter_sleep;
bool finish_press = 0;

#include "webserver.h"
#include "pins.h"
#include "functions.h"
#include "lcd.h"

void setup(){
    Serial.begin(115200); //Start Serial-Monitor for debugging

    setupWebserver();
    setupPins();
    setupLCD();
    esp_sleep_enable_ext0_wakeup(GPIO_NUM_25,1);

    ledTest();
    delay(250);
    counter_sleep = millis();
}

void loop(){
    //handle all stuff to do with a question
    setQuestion(question, question_brfore, question_state);

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

    previousButton.update();
    if(previousButton.rose()){ //check for "prev" button to be presset and decrement qestion
        counter_sleep = millis();

        if(question > 1 && question < 6)
            question--;
    }

    if(millis()-counter_sleep > 40000){
        esp_deep_sleep_start();
    }
}