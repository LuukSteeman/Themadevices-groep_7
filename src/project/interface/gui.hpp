#ifndef GUI_HPP
#define GUI_HPP

#include <hwlib.hpp>
#include "../boundary/oled.hpp"

class gui
{
  public:
    virtual void draw(oled &oled_screen) = 0;
};


#endif