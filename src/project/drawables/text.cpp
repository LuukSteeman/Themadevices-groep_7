#include "text.hpp"

/// Text::Draw()
//
/// The Draw() function will write the Text-Object to the OLED screen given in the parameter
void text::draw(oled &oled_screen){
    /// Create an oled object from the OLED_Buffered type from OLED, this is used to create the Window_Parts
    auto & oled = oled_screen.oled_buffered;

    /// Create Window_Parts, these Window_Parts are used to display different parts on the screen
    /// 1: Left upper
    /// 2: Left bottom
    /// 3: Entire right flank
    /// The first parameter is the OLED to be displayed on, the second parameter is the upper-left-corner, the third parameter is the bottom-right-corner
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
        hwlib::location( 96, 0   ),
        hwlib::location( 128, 64));
     
    /// Create different fotns to display text with, big or small
    auto font_small = hwlib::font_default_8x8();
    auto font_big = hwlib::font_default_16x16();

    /// 3 outstreams, the first one displays on Window1 with a big font, the second one displays on Window2 with a small font, the third one display on Window3 with a big font
    /// You can use these Outstream by writing to them with a "<<" parameter
    auto outstream1 = hwlib::window_ostream( window1, font_big );
    auto outstream2 = hwlib::window_ostream( window2, font_small );
    auto outstream3 = hwlib::window_ostream( window3, font_big );

    /// Get the Screen_Number given to the Text-Object as parameter, this number is used to determine on which Outstream the text from the object is being written to
    if(getScreenNumber() == 1){
    	outstream1 	<< "\f"
    				<< (int)given_text << "HI" << "\n";  
	}
    else if(getScreenNumber() == 2){
	    outstream2 	<< "\f"
	        		<< given_text << "Hi" << "\n";
    }
    else if(getScreenNumber() == 3){
	    outstream3 	<< "\f"
	        		<< given_text << "\n";
    }
    /// If the number is not legit, give an error
    else {
		outstream1 	<< "\f"
    				<< "Error 1" << "\n";  // Outstream bestaat niet
    }

    // oled.flush();
}

/// Text::Flush()
//
/// Write a single object to the screen
void text::flush(oled &oled_screen){
    auto & oled = oled_screen.oled_buffered;

    oled.flush();
}

/// Text::Update()
//
/// Update the text in a Text-Object
void text::update(char * update_text){
    given_text = update_text;
}