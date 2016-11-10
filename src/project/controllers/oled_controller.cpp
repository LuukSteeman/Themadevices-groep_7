#include "oled_controller.hpp"

/// OLED_Controller::Main()
//
///	Read a strictly GUI object from the oled_channel and save it in a GUI Pointer, afterwards we write this object to the screen
void oled_controller::main(){
    hwlib::cout << "Started oled controller\n";
    while (1)
    {
        gui *x = oled_channel.read();
        x->draw(oled_screen);
    }
}

/// OLED_Controller:Add()
//
/// Add a stricly GUI object to the oled_channel
void oled_controller::add(gui * object){
	oled_channel.write(object);
}

/// OLED_Controller:Flush()
//
/// Write the object to the OLED screen
void oled_controller::flush(){
	oled_screen.flush();
}