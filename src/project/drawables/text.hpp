#ifndef TEXT_HPP
#define TEXT_HPP

#include <hwlib.hpp>
#include "../interface/gui.hpp"

class text : public gui{
public:
	char * given_text;
	int screen_number;

	text(char * given_text, int screen_number):
		given_text(given_text),
		screen_number(screen_number)
	{};
	

	void draw(oled &oled_screen);

	void flush(oled &oled_screen);
	// auto getOled(oled oled_screen){
 //    	auto & oled = oled_screen.oled_buffered;
	// 	return & oled;
	// }

	int getScreenNumber(){
		return screen_number;
	}

	void update(char * update_text);
};

#endif