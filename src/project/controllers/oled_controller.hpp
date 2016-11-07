#ifndef OLED_CONTROLLER_HPP
#define OLED_CONTROLLER_HPP

#include "../boundary/oled.hpp"
#include <hwlib.hpp>
#include <rtos.hpp>
// #include ""

class OLED_Controller : public rtos::task<>{
public:
	void count_down(auto & oled, int N);
	void init();
	void init(int health);
	OLED_Controller(char * name) : task(name){};
};


#endif