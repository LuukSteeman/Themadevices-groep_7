#ifndef OLED_CONTROLLER_HPP
#define OLED_CONTROLLER_HPP

#include <rtos.hpp>
#include <hwlib.hpp>
#include "../boundary/oled.hpp"
#include "../interface/gui.hpp"
#include "../drawables/text.hpp"

class oled_controller : public rtos::task<> {
protected:
	oled oled_screen;
	rtos::channel<text, 5> oled_channel;
	void main();
public:
	void add(text object);

	oled_controller(char * name, oled & oled_screen) : 
		task(name), 
		oled_screen(oled_screen), 
		oled_channel(this, "OLED Channel")
	{}
};

#endif