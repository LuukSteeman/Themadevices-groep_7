#ifndef GUI_HPP
#define GUI_HPP

#include <hwlib.hpp>
#include "../controllers/oled_controller.hpp"

class GUI {
public:
	virtual void draw() = 0;
};

#endif // GUI_HPP