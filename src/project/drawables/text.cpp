    #include "text.hpp"

void text::draw(oled &oled_screen){
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
        hwlib::location( 96, 64 ),
        hwlib::location( 32, 64));
     

    auto font_small = hwlib::font_default_8x8();
    auto font_big = hwlib::font_default_16x16();


    auto outstream1 = hwlib::window_ostream( window1, font_big );
    auto outstream2 = hwlib::window_ostream( window2, font_small );
    auto outstream3 = hwlib::window_ostream( window3, font_small );

    if(getScreenNumber() == 1){
    	outstream1 	<< "\f"
    				<< given_text << "HI" << "\n";  
	}
    else if(getScreenNumber() == 2){
	    outstream2 	<< "\f"
	        		<< given_text << "Hi" << "\n";
    }
    else if(getScreenNumber() == 3){
	    outstream3 	<< "\f"
	        		<< given_text << "hi" << "\n";
    }
    else {
		outstream1 	<< "\f"
    				<< "Error 1" << "\n";  // Outstream bestaat niet
    }

    // oled.flush();
}

void text::flush(oled &oled_screen){
    auto & oled = oled_screen.oled_buffered;

    oled.flush();

}