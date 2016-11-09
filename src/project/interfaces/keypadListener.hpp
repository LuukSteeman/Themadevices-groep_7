///Copyright Robert Bezem, Ricardo Bouwman, Jeroen van Hattem, Luuk Steeman
#pragma once
#include "rtos.hpp"

class KeypadListener
{
  public:
    rtos::channel<char, 1> channel;
    void keyPressed(char key)
    {
        channel.write(key);
    }
    KeypadListener() : channel(this, "Listener channel");
};