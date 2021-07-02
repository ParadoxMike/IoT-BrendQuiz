#include <Arduino.h>
#include <Bounce2.h>

//updates the given button and returns true if transitioned from low to high
bool buttonPressed(Bounce button){
    button.update();
    if (button.rose())
        return true;
    else
        return false;
    
}

void updateQuestion(int question_num){
    switch (question_num)
    {
    case 1:
        if(digitalRead(question_1)){
            digitalWrite(question_1, LOW);
            digitalWrite(question_1, HIGH);
        }
        else{
            digitalWrite(question_1, HIGH);
            digitalWrite(question_1, LOW);
        }
        break;
    case 2:
        if(digitalRead(question_2)){
            digitalWrite(question_2, LOW);
            digitalWrite(question_2, HIGH);
        }
        else{
            digitalWrite(question_2, HIGH);
            digitalWrite(question_2, LOW);
        }
        break;
    case 3:
        if(digitalRead(question_3)){
            digitalWrite(question_3, LOW);
            digitalWrite(question_3, HIGH);
        }
        else{
            digitalWrite(question_3, HIGH);
            digitalWrite(question_3, LOW);
        }
        break;
    case 4:
        if(digitalRead(question_4)){
            digitalWrite(question_4, LOW);
            digitalWrite(question_4, HIGH);
        }
        else{
            digitalWrite(question_4, HIGH);
            digitalWrite(question_4, LOW);
        }
        break;
    case 5:
        if(digitalRead(question_5)){
            digitalWrite(question_5, LOW);
            digitalWrite(question_5, HIGH);
        }
        else{
            digitalWrite(question_5, HIGH);
            digitalWrite(question_5, LOW);
        }
        break;
    default:
        break;
    }
}

void updateAllQuestion(){
    int akt_question = 0;

    if(digitalRead(question_1))
        akt_question = 1;
    else if(digitalRead(question_2))
        akt_question = 2;
    else if(digitalRead(question_3))
        akt_question = 3;
    else if(digitalRead(question_4))
        akt_question = 4;
    else if(digitalRead(question_5))
        akt_question = 5;

    digitalWrite(question_1, LOW);
    digitalWrite(question_2, LOW);
    digitalWrite(question_3, LOW);
    digitalWrite(question_4, LOW);
    digitalWrite(question_5, LOW);

    digitalWrite(question_1, HIGH);
    digitalWrite(question_2, HIGH);
    digitalWrite(question_3, HIGH);
    digitalWrite(question_4, HIGH);
    digitalWrite(question_5, HIGH);

    switch (akt_question)
    {
    case 1:
        digitalWrite(question_2, LOW);
        digitalWrite(question_3, LOW);
        digitalWrite(question_4, LOW);
        digitalWrite(question_5, LOW);
        break;
    case 2:
        digitalWrite(question_1, LOW);
        digitalWrite(question_3, LOW);
        digitalWrite(question_4, LOW);
        digitalWrite(question_5, LOW);
        break;
    case 3:
        digitalWrite(question_1, LOW);
        digitalWrite(question_2, LOW);
        digitalWrite(question_4, LOW);
        digitalWrite(question_5, LOW);
        break;
    case 4:
        digitalWrite(question_1, LOW);
        digitalWrite(question_2, LOW);
        digitalWrite(question_3, LOW);
        digitalWrite(question_5, LOW);
        break;
    case 5:
        digitalWrite(question_1, LOW);
        digitalWrite(question_2, LOW);
        digitalWrite(question_3, LOW);
        digitalWrite(question_4, LOW);
        break;
    default:
        digitalWrite(question_1, LOW);
        digitalWrite(question_2, LOW);
        digitalWrite(question_3, LOW);
        digitalWrite(question_4, LOW);
        digitalWrite(question_5, LOW);
        break;
    }
}

void setQuestion(int question_num){
    switch (question_num)
    {
    case 1:
        digitalWrite(question_1, HIGH);
        digitalWrite(question_2, LOW);
        digitalWrite(question_3, LOW);
        digitalWrite(question_4, LOW);
        digitalWrite(question_5, LOW);

        digitalWrite(LED_data_4, LOW);
        updateAllQuestion();

        digitalWrite(LED_data_4, HIGH);
        updateQuestion(question_num);
        break;
    case 2:
        digitalWrite(question_1, LOW);
        digitalWrite(question_2, HIGH);
        digitalWrite(question_3, LOW);
        digitalWrite(question_4, LOW);
        digitalWrite(question_5, LOW);

        digitalWrite(LED_data_4, LOW);
        updateAllQuestion();

        digitalWrite(LED_data_4, HIGH);
        updateQuestion(question_num);
        break;
    case 3:
        digitalWrite(question_1, LOW);
        digitalWrite(question_2, LOW);
        digitalWrite(question_3, HIGH);
        digitalWrite(question_4, LOW);
        digitalWrite(question_5, LOW);

        digitalWrite(LED_data_4, LOW);
        updateAllQuestion();

        digitalWrite(LED_data_4, HIGH);
        updateQuestion(question_num);
        break;
    case 4:
        digitalWrite(question_1, LOW);
        digitalWrite(question_2, LOW);
        digitalWrite(question_3, LOW);
        digitalWrite(question_4, HIGH);
        digitalWrite(question_5, LOW);

        digitalWrite(LED_data_4, LOW);
        updateAllQuestion();

        digitalWrite(LED_data_4, HIGH);
        updateQuestion(question_num);
        break;
    case 5:
        digitalWrite(question_1, LOW);
        digitalWrite(question_2, LOW);
        digitalWrite(question_3, LOW);
        digitalWrite(question_4, LOW);
        digitalWrite(question_5, HIGH);

        digitalWrite(LED_data_4, LOW);
        updateAllQuestion();

        digitalWrite(LED_data_4, HIGH);
        updateQuestion(question_num);
        break;
    default:
        break;
    }
}

void handleQuestion(int question_num){
    switch (question_num)
    {
    case 1:
        setQuestion(question_num);
        Serial.println("Qest1");
        break;
    case 2:
        setQuestion(question_num);
        Serial.println("Qest2");
        break;
    case 3:
        setQuestion(question_num);
        Serial.println("Qest3");
        break;
    case 4:
        setQuestion(question_num);
        Serial.println("Qest4");
        break;
    case 5:
        setQuestion(question_num);
        Serial.println("Qest5");
        break;
    default:
        break;
    }
}

void ledTest(){
    digitalWrite(LED_data_1, HIGH);
    digitalWrite(LED_data_2, HIGH);
    digitalWrite(LED_data_3, HIGH);
    digitalWrite(LED_data_4, HIGH);
    updateAllQuestion();
    digitalWrite(LED_data_1, LOW);
    digitalWrite(LED_data_2, LOW);
    digitalWrite(LED_data_3, LOW);
    digitalWrite(LED_data_4, LOW);
    delay(150);
    updateAllQuestion();
}