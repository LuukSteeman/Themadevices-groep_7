#ifndef GUI_HPP
#define GUI_HPP

#include <hwlib.hpp>
#include "../controllers/oled_controller.hpp"

class gui {
	virtual void draw(oled oled_screen, int screen) = 0;
};


#endif