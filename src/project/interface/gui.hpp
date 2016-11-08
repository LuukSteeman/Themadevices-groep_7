#ifndef GUI_HPP
#define GUI_HPP

#include <hwlib.hpp>
#include "../controllers/oled_controller.hpp"

class GUI {
public:
	oled_controller * oled;
	int screen;
	char * t;
	
	GUI(oled_controller * oled, int screen, char * t):
		oled(oled),
		screen(screen),
		t(t)
	{}

	virtual void draw() = 0;
	virtual void update(){}
};

#endif // GUI_HPP