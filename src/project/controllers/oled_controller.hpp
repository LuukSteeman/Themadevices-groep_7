#ifndef OLED_CONTROLLER_HPP
#define OLED_CONTROLLER_HPP

#include <rtos.hpp>
#include <hwlib.hpp>
#include "../boundary/oled.hpp"
#include "../interface/gui.hpp"
#include "../drawables/text.hpp"


class oled_controller : public rtos::task<>
{
  private:

  public:
    oled oled_screen;
    rtos::channel<gui *, 5> oled_channel;
    void main();

    oled_controller(oled &oled_screen) : 
	    task((char *)"guiTask"), 
	    oled_screen(oled_screen), 
	    oled_channel(this, (char *)"GUI channel")
    {};

    void add(gui *e);

    void flush();
};

#endif