#ifndef TEXT_HPP
#define TEXT_HPP

#include <hwlib.hpp>
#include "../interface/gui.hpp"

/// Text
//
/// The Text-Class inherits the GUI class, making it a GUI-Class. This is used to determine whether it's allowed in the OLED_Channel
class text : public gui{
public:
	/// The given text is the text we get as parameter when creating a Text-Object
	char * given_text;
	
	/// This is the Outstream the object has to be written to
	int screen_number;

	/// Text()
	//
	/// The Text Constructor, it needs a Char Pointer, which is the text to be displayed, and a screen_number which determines to which Outstream the text has to be written to
	text(char * given_text, int screen_number):
		given_text(given_text),
		screen_number(screen_number)
	{};

	//// Declare Draw() Function
	void draw(oled &oled_screen);

	/// Declare Flush() Function
	void flush(oled &oled_screen);

	/// Text::getScreenNumber
	//
	/// This function returns the screen_number variable
	int getScreenNumber(){
		return screen_number;
	}

	/// Declare Update() function
	void update(char * update_text);
};

#endif