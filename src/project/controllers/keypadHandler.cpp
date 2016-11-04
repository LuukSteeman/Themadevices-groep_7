#include "keypadHandler.hpp"

KeypadHandler::KeypadHandler(Keypad& keypad):keypad(keypad){};

void KeypadHandler::main(){
    while(1){
        keypad.update();
        sleep(pollTimeout);
    }
}