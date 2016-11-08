#pragma once
#include "rtos.hpp"

class KeypadListener
{
public:
	virtual void keyPressed(char key) = 0;
};