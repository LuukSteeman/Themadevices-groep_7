#pragma once

#include <hwlib.hpp>
#include "../interfaces/keypadListener.hpp"
class Keypad
{
  private:
    hwlib::target::pin_oc out0;
    hwlib::target::pin_oc out1;
    hwlib::target::pin_oc out2;
    hwlib::target::pin_oc out3;

    hwlib::target::pin_in in0;
    hwlib::target::pin_in in1;
    hwlib::target::pin_in in2;
    hwlib::target::pin_in in3;

    hwlib::port_oc_from_pins out_port;
    hwlib::port_in_from_pins in_port;
    hwlib::matrix_of_switches matrix;
    hwlib::keypad<16> keyz;

    static const int maxListeners = 10;
    KeypadListener *listeners[maxListeners];
    int listenerCount = 0;

  public:
    Keypad();
    void update();
    void addKeypadListener(KeypadListener *listener);
};