#ifndef OLED_CONTROLLER_HPP
#define OLED_CONTROLLER_HPP

#include "../boundary/oled.hpp"
#include <hwlib.hpp>
#include <rtos.hpp>
// #include ""

class oled_controller : public rtos::task<>{
public:	
	char * name;
	hwlib::window_ostream outstream1;
	hwlib::window_ostream outstream2;
	hwlib::window_ostream outstream3;
	void count_down(auto & oled, int N);
	void init();
	void init(int health);
	void main();
	oled_controller(char * name, auto outstream1, auto outstream2, auto outstream3) : 
		task(name),
		outstream1(outstream1),
		outstream2(outstream2),
		outstream3(outstream3)
	{}
};


#endif