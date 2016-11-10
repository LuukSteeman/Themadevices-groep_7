#pragma once

#include <hwlib.hpp>
#include "../interfaces/receiverListener.hpp"
#include "../applicationLogic/messageLogic.hpp"

/**
  Receiver class. Contains functions to get status of the receiver pin and functions to notify listeners
*/
class Receiver : public hwlib::target::pin_in
{
  private:
    static const int maxListeners = 10;
    ReceiverListener *listeners[maxListeners];
    int listenerCount = 0;
    MessageLogic lastReceived = MessageLogic();
    long long int lastReceivedTime = 0;
  public:
    /**
      Create a receiver
      @param pin the sensor is connected on
    */
    Receiver(hwlib::target::pins sensorPin) : hwlib::target::pin_in(sensorPin){};
    /**
      When a message is received broadcast to listeners
      @param message that is received 
    */
    void update(MessageLogic msg);
    /**
      add Listener to list of listeners
      @param pointer to the listener
    */
    void addReceiverListener(ReceiverListener *listener);
};