#include "text.hpp"

void text::draw(){
    oled.d1 << "\f"
        << "Hi";   
	oled.d2 << "\f"
        << "How are you?" << "\n";

    oled.flush();

    hwlib::wait_ms(100);
}