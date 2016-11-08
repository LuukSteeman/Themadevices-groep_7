#include "oled_controller.hpp"

void oled_controller::main(){
	auto x = oled_channel.read();

	x.draw(oled_screen, 2);
}

void oled_controler::add(text object){
	oled_channel.write(object);
}