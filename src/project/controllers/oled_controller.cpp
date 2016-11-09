#include "oled_controller.hpp"

void oled_controller::main(){
    hwlib::cout << "Started oled controller\n";
    while (1)
    {
        gui *x = oled_channel.read();
        x->draw(oled_screen, 2);
    }

}

void oled_controller::add(gui * object){
	oled_channel.write(object);
}