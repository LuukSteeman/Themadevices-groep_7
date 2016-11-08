#include "text.hpp"

void text::draw(){
	getController().init();
    getController().outstream1 << "\f"
        << "Hi";   
	getController().outstream1 << "\f"
        << "How are you?" << "\n";

    getController().flush();

    hwlib::wait_ms(100);
}