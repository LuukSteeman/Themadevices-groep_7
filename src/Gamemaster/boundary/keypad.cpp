#include "keypad.hpp"

Keypad::Keypad() : out0(hwlib::target::pins::a0),
                   out1(hwlib::target::pins::a1),
                   out2(hwlib::target::pins::a2),
                   out3(hwlib::target::pins::a3),

                   in0(hwlib::target::pins::a4),
                   in1(hwlib::target::pins::a5),
                   in2(hwlib::target::pins::a6),
                   in3(hwlib::target::pins::a7),

                   out_port(out0, out1, out2, out3),
                   in_port(in0, in1, in2, in3),
                   matrix(out_port, in_port),
                   keyz(matrix, "123A456B789C*0#D")
{
}

void Keypad::addKeypadListener(KeypadListener *listener)
{
    {
        if (listenerCount < maxListeners)
        {
            listeners[listenerCount] = listener;
            listenerCount++;
        }
    }
}

void Keypad::update()
{
    {
        if (keyz.char_available())
        {
            char key = keyz.getc();
            for (int i = 0; i < listenerCount; i++)
            {
                listeners[i]->keyPressed(key);
            }
        }
        // char key = keyz.pressed();
        // if (key != '\0')
        // {
        //     for (int i = 0; i < listenerCount; i++)
        //     {
        //         listeners[i]->keyPressed(key);
        //     }
        // }
    }
}