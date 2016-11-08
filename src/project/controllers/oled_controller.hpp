#ifndef OLED_CONTROLLER_HPP
#define OLED_CONTROLLER_HPP

#include <rtos.hpp>
#include <hwlib.hpp>
#include "../boundary/oled.hpp"
// #include "../interface/gui.hpp"
#include "../drawables/string.hpp"

class oled_controller : public rtos::task<> {
private:
	oled oled_screen;
	rtos::channel<int, 5> oled_channel;
	void main();
public:
	void add(string object);

	oled_controller(char * name, oled & oled_screen) : 
		task(name), 
		oled_screen(oled_screen), 
		oled_channel(this, "OLED Channel")
	{}
};

#endif