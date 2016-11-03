#pragma once

#include <hwlib.hpp>
#include "../interfaces/receiverListener.hpp"

class Receiver : public hwlib::target::pin_in
{
  private:
    static const int maxListeners = 10;
    ReceiverListener *listeners[maxListeners];
    int listenerCount = 0;
  public:
    Receiver(hwlib::target::pins sensorPin) : hwlib::target::pin_in(sensorPin){};
    void update(short msg);
    void addReceiverListener(ReceiverListener *listener);
};