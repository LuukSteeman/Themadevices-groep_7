#pragma once

#include <rtos.hpp>
#include "../boundary/receiver.hpp"


/**
  ReceiverHandler Task.
  polls the receiver and updates it when there is a message
*/
class ReceiverHandler : public rtos::task<256>
{
  private:
        Receiver &rec;
        void main();
        void listenForMessage();

        static const int pollTimeout = 200 * rtos::us;
        static const int bits = 16;
        static const int samplesPerBit = 16;
        static const int sampleTime = 2400 * rtos::us;
        static const int sampleSleepTime = (sampleTime/samplesPerBit)+50;
        static const int failTimeout = 5*rtos::ms;
        static const int maxWaits = failTimeout/pollTimeout;

      public:
        /**
          Creates a ReceiverHandler
          @param Receiver to update and poll
        */
        ReceiverHandler(Receiver &rec) : task(1,(char*)"Receiver Handler"),rec(rec){};
};