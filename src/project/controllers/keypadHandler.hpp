/*

/home/Robert/SCHOOL/2015-2016/Themadevices-groep_7/src/project/controllers/keypadHandler.hpp:18: warning: argument 'Keypad' of command @param is not found in the argument list of KeypadHandler::KeypadHandler(Keypad &keypad)
/home/Robert/SCHOOL/2015-2016/Themadevices-groep_7/src/project/controllers/keypadHandler.hpp:22: warning: The following parameters of KeypadHandler::KeypadHandler(Keypad &keypad) are not documented:
  parameter 'keypad'
*/

#pragma once

#include <rtos.hpp>
#include "../boundary/keypad.hpp"

/**
    KeypadHandler task.

    Updates the keypad periodicly.
*/
class KeypadHandler : public rtos::task<>{
    private:
        Keypad& keypad;
        void main();
        static const int pollTimeout = 100 * rtos::us;
    public:
        /**
            Create KeypadHandler

            @param keypad @see Keypad to be handled.
        */
        KeypadHandler(Keypad& keypad);
};