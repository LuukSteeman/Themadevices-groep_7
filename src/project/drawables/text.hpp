#ifndef TEXT_HPP
#define TEXT_HPP

#include <hwlib.hpp>
#include "../interface/gui.hpp"

class text : public gui{
public:
	text(){};
	void draw(oled oled_screen, int screen);
};

#endif