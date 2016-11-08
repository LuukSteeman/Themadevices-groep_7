#ifndef STRING_HPP
#define STRING_HPP

#include <hwlib.hpp>
#include "../interface/gui.hpp"

class string : public gui{
private:
	char * t;
public:
	string(char * t):
		t(t)
	{}
	string(){}

	void draw(oled oled_screen, int screen);
};

#endif