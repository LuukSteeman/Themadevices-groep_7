///Copyright Robert Bezem, Ricardo Bouwman, Jeroen van Hattem, Luuk Steeman

#pragma once

#include <rtos.hpp>
#include "../boundary/keypad.hpp"

/**
    KeypadHandler task

    Updates the keypad periodicly
*/
class KeypadHandler : public rtos::task<>
{
    private:
        Keypad& keypad;
        void main();
        static const int pollTimeout = 100 * rtos::us;
    public:
        /**
            Create KeypadHandler

            @param Keypad @see Keypad
        */
        KeypadHandler(Keypad& keypad);
};
