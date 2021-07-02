#include <Bounce2.h>

//updates the given button and returns true if transitioned from low to high
bool buttonPressed(Bounce button){
    button.update();
    if (button.rose())
        return true;
    else
        return false;
    
}