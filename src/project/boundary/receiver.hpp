/*
/home/Robert/SCHOOL/2015-2016/Themadevices-groep_7/src/project/boundary/receiver.hpp:18: warning: argument 'pin' of command @param is not found in the argument list of Receiver::Receiver(hwlib::target::pins sensorPin)
/home/Robert/SCHOOL/2015-2016/Themadevices-groep_7/src/project/boundary/receiver.hpp:21: warning: The following parameters of Receiver::Receiver(hwlib::target::pins sensorPin) are not documented:
  parameter 'sensorPin'
/home/Robert/SCHOOL/2015-2016/Themadevices-groep_7/src/project/boundary/receiver.hpp:28: warning: argument 'pointer' of command @param is not found in the argument list of Receiver::addReceiverListener(ReceiverListener *listener)
/home/Robert/SCHOOL/2015-2016/Themadevices-groep_7/src/project/boundary/receiver.hpp:31: warning: The following parameters of Receiver::addReceiverListener(ReceiverListener *listener) are not documented:
  parameter 'listener'
/home/Robert/SCHOOL/2015-2016/Themadevices-groep_7/src/project/boundary/receiver.hpp:23: warning: argument 'message' of command @param is not found in the argument list of Receiver::update(MessageLogic msg)
/home/Robert/SCHOOL/2015-2016/Themadevices-groep_7/src/project/boundary/receiver.hpp:26: warning: The following parameters of Receiver::update(MessageLogic msg) are not documented:
  parameter 'msg'
*/
#pragma once

#include <hwlib.hpp>
#include "../interfaces/receiverListener.hpp"
#include "../applicationLogic/messageLogic.hpp"

/**
  Receiver class. Contains functions to get status of the receiver pin and functions to notify listeners.
*/
class Receiver : public hwlib::target::pin_in
{
  private:
    static const int maxListeners = 10;
    ReceiverListener *listeners[maxListeners];
    int listenerCount = 0;
  public:
    /**
      Create a receiver.
      @param sensorPin Pin the sensor is connected on.
    */
    Receiver(hwlib::target::pins sensorPin) : hwlib::target::pin_in(sensorPin){};
    /**
      When a message is received broadcast to listeners
      @param msg message that is received. 
    */
    void update(MessageLogic msg);
    /**
      add Listener to list of listeners.
      @param listener pointer to the listener.
    */
    void addReceiverListener(ReceiverListener *listener);
};