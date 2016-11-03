#pragma once

#include <rtos.hpp>
#include "../boundary/receiver.hpp"

class ReceiverHandler : public rtos::task<>
{
  private:
        Receiver &rec;
        void main();
        void listenForMessage();

        static const int pollTimeout = 200;
        static const int bits = 16;
        static const int samplesPerBit = 16;
        static const int sampleTime = 2390;
        static const int failTimeout = 40000;

      public:
        ReceiverHandler(Receiver &rec) : rec(rec){};
};