#ifndef OLED_CONTROLLER_HPP
#define OLED_CONTROLLER_HPP

#include "../boundary/oled.hpp"
#include <hwlib.hpp>
#include <rtos.hpp>
// #include ""

class oled_controller : public rtos::task<>{
public:	

	char * name;
	int scherm;

	void count_down(auto & oled, int N);
	void init();
	void init(int health);
	void main();

	oled_controller(char * name) : 
		task(name)
	{
		oled_buffered_d18_d21 oled_class;
	    auto hw = oled_buffered_d18_d21();
	    auto & oled = hw.oled;


	    auto window1 = hwlib::window_part( 
	        oled, 
	        hwlib::location( 0, 0 ),
	        hwlib::location( 96, 32));
	    auto window2 = hwlib::window_part( 
	        oled, 
	        hwlib::location( 0, 32 ),
	        hwlib::location( 96, 32));
	    auto window3 = hwlib::window_part( 
	        oled, 
	        hwlib::location( 0, 64 ),
	        hwlib::location( 32, 64));
	     

	    auto font_small = hwlib::font_default_8x8();
	    auto font_big = hwlib::font_default_16x16();


	    auto outstream1 = hwlib::window_ostream( window1, font_big );
	    auto outstream2 = hwlib::window_ostream( window2, font_small );
	    auto outstream3 = hwlib::window_ostream( window3, font_small );

	    
        outstream1 	<< "\f"
            		<< "1" << "\n";   
        outstream2 	<< "\f"
            		<< "2" << "\n";
        outstream3 	<< "\f"
            		<< "3" << "\n";
	}

};


#endif