#ifndef GUI_HPP
#define GUI_HPP

#include <hwlib.hpp>
#include "../controllers/oled_controller.hpp"

class GUI {
protected:
	oled_controller oled;
	int screen;
public:
	GUI(auto & oled, int screen):
		oled(oled),
		screen(screen)
	{}

	virtual void draw() = 0;
	virtual void update(){}
};

#endif // GUI_HPP