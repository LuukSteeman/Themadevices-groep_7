#ifndef GUI_HPP
#define GUI_HPP

#include <hwlib.hpp>
#include "../controllers/oled_controller.hpp"

class GUI {
private:
	auto & w;
	hwlib::location location;
public:
	oled_controller oled;
	GUI(auto & w, const hwlib::location & location ):
		w( w ),
		location( location )
	{}

	virtual void draw() = 0;
	virtual void update(){}
};

#endif // GUI_HPP