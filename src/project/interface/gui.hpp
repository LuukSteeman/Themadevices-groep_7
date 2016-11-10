#ifndef GUI_HPP
#define GUI_HPP

#include <hwlib.hpp>
#include "../boundary/oled.hpp"

/// GUI
//
/// The GUI class is an Interface class, or a Virtual Abstract class. The OLED_Channel is restricted to use only GUI objects. Drawables classes inherit the Draw() function from this class
class gui
{
  public:
  	/// GUI::Draw()
  	//
  	/// The Virtual Abstract Draw() function, this will be different for each class. But it will print the object to the screen
    virtual void draw(oled &oled_screen) = 0;
};


#endif