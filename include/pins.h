#include <Arduino.h>
#include <Bounce2.h>

#define debounceTime 20

//LED-bus
#define LED_data_1 23
#define LED_data_2 19
#define LED_data_3 18
#define LED_data_4 5

//button-bus
#define button_pin_A 27
Bounce debouncedButtonA = Bounce();
#define button_pin_B 14
Bounce debouncedButtonB = Bounce();
#define button_pin_C 12
Bounce debouncedButtonC = Bounce();

//qeustion-select
#define question_1 17
#define question_2 16
#define question_3 4
#define question_4 0
#define question_5 2

//nav-buttons
#define start_next_button_pin 25
Bounce startNextButton = Bounce();
#define previous_button_pin 26
Bounce previousButton = Bounce();

//other
#define mosfet_pin 33

//setup function - define pinmodes and atattch debounce
void setupPins(){
    pinMode(LED_data_1, OUTPUT);
    pinMode(LED_data_2, OUTPUT);
    pinMode(LED_data_3, OUTPUT);
    pinMode(LED_data_4, OUTPUT);

    pinMode(button_pin_A, INPUT_PULLDOWN);
    debouncedButtonA.attach(button_pin_A);
    debouncedButtonA.interval(debounceTime);
    pinMode(button_pin_B, INPUT_PULLDOWN);
    debouncedButtonB.attach(button_pin_B);
    debouncedButtonB.interval(debounceTime);
    pinMode(button_pin_C, INPUT_PULLDOWN);
    debouncedButtonC.attach(button_pin_C);
    debouncedButtonC.interval(debounceTime);

    pinMode(question_1, OUTPUT);
    pinMode(question_2, OUTPUT);
    pinMode(question_3, OUTPUT);
    pinMode(question_4, OUTPUT);
    pinMode(question_5, OUTPUT);

    pinMode(start_next_button_pin, INPUT_PULLDOWN);
    startNextButton.attach(start_next_button_pin);
    startNextButton.interval(debounceTime);
    pinMode(previous_button_pin, INPUT_PULLDOWN);
    previousButton.attach(previous_button_pin);
    previousButton.interval(debounceTime);

    pinMode(mosfet_pin, OUTPUT);
}