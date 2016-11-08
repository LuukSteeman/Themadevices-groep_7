#include "oled_controller.hpp"

void oled_controller::main(){
	auto x = oled_channel.read();

	x.draw(oled_screen, 2);
	while(1){

	};
}

void oled_controller::add(string object){
	oled_channel.write((int)object);
}