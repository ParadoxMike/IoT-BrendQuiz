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
#define question_1 2
#define question_2 0
#define question_3 4
#define question_4 16
#define question_5 17

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
    digitalWrite(LED_data_1, LOW);
    pinMode(LED_data_2, OUTPUT);
    digitalWrite(LED_data_2, LOW);
    pinMode(LED_data_3, OUTPUT);
    digitalWrite(LED_data_3, LOW);
    pinMode(LED_data_4, OUTPUT);
    digitalWrite(LED_data_4, LOW);

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
    digitalWrite(question_1, HIGH);
    digitalWrite(question_1, LOW);
    pinMode(question_2, OUTPUT);
    digitalWrite(question_2, HIGH);
    digitalWrite(question_2, LOW);
    pinMode(question_3, OUTPUT);
    digitalWrite(question_3, HIGH);
    digitalWrite(question_3, LOW);
    pinMode(question_4, OUTPUT);
    digitalWrite(question_4, HIGH);
    digitalWrite(question_4, LOW);
    pinMode(question_5, OUTPUT);
    digitalWrite(question_5, HIGH);
    digitalWrite(question_5, LOW);

    pinMode(start_next_button_pin, INPUT_PULLDOWN);
    startNextButton.attach(start_next_button_pin);
    startNextButton.interval(debounceTime);
    pinMode(previous_button_pin, INPUT_PULLDOWN);
    previousButton.attach(previous_button_pin);
    previousButton.interval(debounceTime);

    pinMode(mosfet_pin, OUTPUT);
    digitalWrite(mosfet_pin, LOW);
}