#include <Arduino.h>
#include <Bounce2.h>

#define debounceTime 10
#define adc_on_level 100

//LED-bus
#define LED_data_1 23
#define LED_data_2 19
#define LED_data_3 18
#define LED_data_4 5

//button-bus
#define button_pin_A 34
#define button_pin_B 35
#define button_pin_C 32

//qeustion-select
#define question_1 2
#define question_2 0
#define question_3 4
#define question_4 16
#define question_5 17

//nav-buttons
#define start_next_button_pin 26
Bounce startNextButton = Bounce(start_next_button_pin, debounceTime);
#define previous_button_pin 25
Bounce previousButton = Bounce(previous_button_pin, debounceTime);

//other
#define mosfet_pin 33

//setup function - define pinmodes and atattch debounce
void setupPins(){
    pinMode(LED_data_1, OUTPUT);
    digitalWrite(LED_data_1, LOW);
    pinMode(LED_data_2, OUTPUT);
    digitalWrite(LED_data_2, LOW);
    pinMode(LED_data_3, OUTPUT);
    digitalWrite(LED_data_3, LOW);
    pinMode(LED_data_4, OUTPUT);
    digitalWrite(LED_data_4, LOW);

    pinMode(button_pin_A, INPUT);
    pinMode(button_pin_B, INPUT);
    pinMode(button_pin_C, INPUT);

    pinMode(question_1, OUTPUT);
    digitalWrite(question_1, LOW);
    pinMode(question_2, OUTPUT);
    digitalWrite(question_2, LOW);
    pinMode(question_3, OUTPUT);
    digitalWrite(question_3, LOW);
    pinMode(question_4, OUTPUT);
    digitalWrite(question_4, LOW);
    pinMode(question_5, OUTPUT);
    digitalWrite(question_5, LOW);

    pinMode(start_next_button_pin, INPUT_PULLDOWN);
    pinMode(previous_button_pin, INPUT_PULLDOWN);

    pinMode(mosfet_pin, OUTPUT);
    digitalWrite(mosfet_pin, LOW);
}