#pragma once

#include <hwlib.hpp>
#include "../interfaces/keypadListener.hpp"

/**
  Class that creates the keypad pins and provides a way to update KeypadListeners
*/
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
    /**
      Initialise keypad and pins.
    */
    Keypad();
    /**
      check if key is pressed and update listeners.
    */
    void update();
    /**
      Add a listener class to list of listeners.

      @param listener Pointer to listener.
    */
    void addKeypadListener(KeypadListener *listener);
};