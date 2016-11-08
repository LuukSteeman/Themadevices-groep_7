#ifndef GUI_HPP
#define GUI_HPP

#include <hwlib.hpp>
#include "../boundary/oled.hpp"

class gui {
	virtual void draw(oled oled_screen, int screen) = 0;
};


#endif