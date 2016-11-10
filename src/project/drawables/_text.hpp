#ifndef TEXT_HPP
#define TEXT_HPP

#include "../interface/gui.hpp"
#include "../controllers/oled_controller.hpp"

class text : public GUI {
public:
	oled_controller oled;
	int screen;
	char * t;

	text(oled_controller & oled, int screen, char * t):
		oled(oled),
		screen(screen),
		t(t)
	{}

	void draw() override;
};

#endif