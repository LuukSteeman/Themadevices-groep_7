#ifndef TEXT_HPP
#define TEXT_HPP

#include "../interface/gui.hpp"
#include "../controllers/oled_controller.hpp"

class text : public GUI {
protected:	
	char * t;
	int screen;
public:
	oled_controller oled;

	text(auto & oled, int screen, char * t):
		GUI(oled, screen),
		t(t)
	{}

	oled_controller getController(){
		return *oled;
	}

	void draw() override;

	void update() override;
};

#endif