#ifndef OLED_CONTROLLER_HPP
#define OLED_CONTROLLER_HPP

#include <rtos.hpp>
#include <hwlib.hpp>
#include "../boundary/oled.hpp"
#include "../interface/gui.hpp"
#include "../drawables/text.hpp"

/// OLED_Controller
//
/// The OLED_Controller class is a RTOS-task
class oled_controller : public rtos::task<>
{
  public:
  	/// Create an OLED object, which will be used to write object to the screen
    oled oled_screen;

    /// Create a channel, which will be used to store the GUI objects
    rtos::channel<gui *, 5> oled_channel;

    /// Declare a Main() function
    void main();

    /// OLED_Controller()
    //
    /// The OLED_Controller Constructor, it needs an OLED object, the use of this is explained above
    oled_controller(oled &oled_screen) : 
	    task((char *)"OLED_Controller"), 
	    oled_screen(oled_screen), 
	    oled_channel(this, (char *)"GUI channel")
    {};

    /// Declare Add() function
    void add(gui *object);

    /// Declare Flush() function
    void flush();
};

#endif