#ifndef HIT_CONTROLLER_HPP
#define HIT_CONTROLLER_HPP

#include "oled_controller.hpp"
#include "speakercontroller.hpp"
#include "boundary/speaker.hpp"
// #include "../applicationLogic/msgLogic.hpp"
// #include "../applicationLogic/gunLogic.hpp"
// #include "../applicationLogic/dmgstorage.hpp"

class hit_controller : public rtos::task<>{
public:
	void init();
	void hit();
	hit_controller(char * name) : task(name){};
};


#endif