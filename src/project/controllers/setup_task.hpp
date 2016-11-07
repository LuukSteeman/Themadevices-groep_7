#ifndef SETUP_TASK_HPP
#define SETUP_TASK_HPP

#include <rtos.hpp>
#include "timer_controller.hpp"
#include "receiver_controller.hpp"
#include "../interfaces/keypadListener.hpp"
// #include "../entity/player.hpp"
// #include "../__/id_jumper.hpp"

class setup_task : public keypadListener{
private:
	rtos::channel< char, 1024 > key_channel;
	char pressed_key;
public:
	keyPressed(char x){
		key_channel.write(x);
	}

	char read_channel(){
		pressed_key = key_channel.read();
	}

	char get_key(){
		return pressed_key;
	}


}