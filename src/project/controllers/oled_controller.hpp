#ifndef OLED_CONTROLLER_HPP
#define OLED_CONTROLLER_HPP

#include "../boundary/oled.hpp"
#include <hwlib.hpp>
#include <rtos.hpp>
// #include ""

class oled_controller : public rtos::task<>{
public:
	
	void count_down(auto & oled, int N);
	void init();
	void init(int health);
	void main();
	oled_controller(char * name) : task(name){};
};


#endif