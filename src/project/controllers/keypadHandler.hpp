#pragma once

#include <rtos.hpp>
#include "../boundary/keypad.hpp"
class KeypadHandler : public rtos::task<>{
    private:
        Keypad& keypad;
        void main();
        
        static const int pollTimeout = 100 * rtos::us;
    public:
        KeypadHandler(Keypad& keypad);
};