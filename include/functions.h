#include <Arduino.h>
#include <Bounce2.>

//updates the given button and returns true if transitioned from low to high
bool buttonPressed(Bounce button){
    button.update();
    if (button.rose())
        return true;
    else
        return false;
    
}

void setQuestion(int qestionNum){
    switch (question)
    {
    case 1:
        digitalWrite(question_1, HIGH);
        digitalWrite(question_2, LOW);
        digitalWrite(question_3, LOW);
        digitalWrite(question_4, LOW);
        digitalWrite(question_5, LOW);
        break;
    case 2:
        digitalWrite(question_1, LOW);
        digitalWrite(question_2, HIGH);
        digitalWrite(question_3, LOW);
        digitalWrite(question_4, LOW);
        digitalWrite(question_5, LOW);
        break;
    case 3:
        digitalWrite(question_1, LOW);
        digitalWrite(question_2, LOW);
        digitalWrite(question_3, HIGH);
        digitalWrite(question_4, LOW);
        digitalWrite(question_5, LOW);
        break;
    case 4:
        digitalWrite(question_1, LOW);
        digitalWrite(question_2, LOW);
        digitalWrite(question_3, LOW);
        digitalWrite(question_4, HIGH);
        digitalWrite(question_5, LOW);
        break;
    case 5:
        digitalWrite(question_1, LOW);
        digitalWrite(question_2, LOW);
        digitalWrite(question_3, LOW);
        digitalWrite(question_4, LOW);
        digitalWrite(question_5, HIGH);
        break;
    default:
        break;
    }
}

void handleQuestion(int question){
    switch (question)
    {
    case 1:
        digitalWrite(LED_data_4, LOW);
        setQuestion(question);
        digitalWrite(LED_data_4, HIGH);
        break;
    case 2:
        digitalWrite(LED_data_4, LOW);
        setQuestion(question);
        digitalWrite(LED_data_4, HIGH);
        break;
    case 3:
        digitalWrite(LED_data_4, LOW);
        setQuestion(question);
        digitalWrite(LED_data_4, HIGH);
        break;
    case 4:
        digitalWrite(LED_data_4, LOW);
        setQuestion(question);
        digitalWrite(LED_data_4, HIGH);
        break;
    case 5:
        digitalWrite(LED_data_4, LOW);
        setQuestion(question);
        digitalWrite(LED_data_4, HIGH);
        break;
    
    default:
        break;
    }
}