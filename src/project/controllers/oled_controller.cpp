#include "oled_controller.hpp"

void oled_controller::main(){
	while(true){
		auto x = oled_channel.read();		
		x.draw(oled_screen, 2);
		sleep(1 * rtos::s);
	}

}

void oled_controller::add(string object){
	oled_channel.write(object);
}