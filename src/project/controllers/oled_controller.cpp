#include "oled_controller.hpp"

void oled_controller::main(){
    hwlib::cout << "Started oled controller\n";
    while (1)
    {
        gui *x = oled_channel.read();
        x->draw(oled_screen);
    }
}

void oled_controller::add(gui * object){
	oled_channel.write(object);
}

void oled_controller::flush(){
	oled_screen.flush();
}