#include "text.hpp"

void draw(oled oled_screen, int screen){
    auto & oled = oled_screen.oled_buffered;


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

    switch(screen){
    	case 1:
    		outstream1 	<< "\f"
        				<< "1" << "\n";  
			break;
    	case 2:
		    outstream2 	<< "\f"
		        		<< "2" << "\n";
			break;
    	case 3:
		    outstream3 	<< "\f"
		        		<< "3" << "\n";
			break;
		default:
    		outstream1 	<< "\f"
        				<< "Error 1" << "\n";  // Outstream bestaat niet
    }
}