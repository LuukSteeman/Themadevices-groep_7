///Copyright Robert Bezem, Ricardo Bouwman, Jeroen van Hattem, Luuk Steeman

#include "keypadHandler.hpp"

KeypadHandler::KeypadHandler(Keypad& keypad):keypad(keypad){};

void KeypadHandler::main()
{
    while (1)
    {
        keypad.update();
        sleep(pollTimeout);
    }
}
