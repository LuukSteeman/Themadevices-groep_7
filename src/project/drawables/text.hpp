#ifndef TEXT_HPP
#define TEXT_HPP

#include <hwlib.hpp>
#include "../interface/gui.hpp"

class text : gui{
private:
	char * t;
public:
	text(char * t):
		t(t)
	{}

	void draw(oled oled_screen, int screen);
};

#endif