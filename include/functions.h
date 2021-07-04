#include <Arduino.h>

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

void setLedBus(int question_num, bool active, bool saved_answer[5][3]){
    if(saved_answer[question_num-1][0])
        digitalWrite(LED_data_1, HIGH);
    else
        digitalWrite(LED_data_1, LOW);

    if(saved_answer[question_num-1][1])
        digitalWrite(LED_data_2, HIGH);
    else
        digitalWrite(LED_data_2, LOW);

    if(saved_answer[question_num-1][2])
        digitalWrite(LED_data_3, HIGH);
    else 
        digitalWrite(LED_data_3, LOW);

    if(active)
        digitalWrite(LED_data_4, HIGH);
    else
        digitalWrite(LED_data_4, LOW);
}

void setQuestion(int question_num, int old_question_num, bool saved_answer[5][3]){
    switch (question_num)
    {
    case 1:
        setLedBus(old_question_num, false, saved_answer);
        updateQuestion(old_question_num);
        digitalWrite(question_2, LOW);
        digitalWrite(question_3, LOW);
        digitalWrite(question_4, LOW);
        digitalWrite(question_5, LOW);
        
        setLedBus(question_num, true, saved_answer);
        digitalWrite(question_1, HIGH);
        updateQuestion(question_num);
        break;
    case 2:
        setLedBus(old_question_num, false, saved_answer);
        updateQuestion(old_question_num);
        digitalWrite(question_1, LOW);
        digitalWrite(question_3, LOW);
        digitalWrite(question_4, LOW);
        digitalWrite(question_5, LOW);
        
        setLedBus(question_num, true, saved_answer);
        digitalWrite(question_2, HIGH);
        updateQuestion(question_num);
        break;
    case 3:
        setLedBus(old_question_num, false, saved_answer);
        updateQuestion(old_question_num);
        digitalWrite(question_1, LOW);
        digitalWrite(question_2, LOW);
        digitalWrite(question_4, LOW);
        digitalWrite(question_5, LOW);
        
        setLedBus(question_num, true, saved_answer);
        digitalWrite(question_3, HIGH);
        updateQuestion(question_num);
        break;
    case 4:
        setLedBus(old_question_num, false, saved_answer);
        updateQuestion(old_question_num);
        digitalWrite(question_1, LOW);
        digitalWrite(question_2, LOW);
        digitalWrite(question_3, LOW);
        digitalWrite(question_5, LOW);
        
        setLedBus(question_num, true, saved_answer);
        digitalWrite(question_4, HIGH);
        updateQuestion(question_num);
        break;
    case 5:
        setLedBus(old_question_num, false, saved_answer);
        updateQuestion(old_question_num);
        digitalWrite(question_1, LOW);
        digitalWrite(question_2, LOW);
        digitalWrite(question_3, LOW);
        digitalWrite(question_4, LOW);
        
        setLedBus(question_num, true, saved_answer);
        digitalWrite(question_5, HIGH);
        updateQuestion(question_num);
        break;
    default:
        break;
    }
}

int getScore(bool saved_answer[5][3], bool answer[5][3]){
    int score = 0;

    for (int i = 0; i < 5; i++){
        if(saved_answer[i][0] == answer[i][0] && saved_answer[i][1] == answer[i][1] && saved_answer[i][2] == answer[i][2]){
            score++;
        }
    }
    return score;
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