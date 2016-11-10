#pragma once

#include <rtos.hpp>
#include "../boundary/keypad.hpp"

/**
    KeypadHandler task

    Updates the keypad periodicly
*/
class KeypadHandler : public rtos::task<>{
    private:
        Keypad& keypad;
        void main();
        static const int pollTimeout = 40 * rtos::ms;
    public:
        /**
            Create KeypadHandler

            @param Keypad @see Keypad
        */
        KeypadHandler(Keypad& keypad);
};