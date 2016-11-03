#include "receiverHandler.hpp"

void ReceiverHandler::main()
{
    while (1)
    {
        listenForMessage();
    }
}

void ReceiverHandler::listenForMessage()
{
    //create data short and bit counter
    unsigned short data = 0;
    int bit = 0;
    while (bit != bits) //while amount of bits is not reached
    {
        int waits = 0;    // hold amount of waits
        while (rec.get()) // wait as long as ir pin is not low
        {
            sleep(pollTimeout * rtos::us);
            waits++;
            if ((failTimeout / pollTimeout) > waits) // if fail timeout is reached fail
            {
                return;
            }
        }

        //sample the pin x times and calculate if it was a 1 or 0
        int highs = 0;
        for (int i = 0; i < samplesPerBit; i++)
        {
            if (!ir_pin.get())
            {
                highs++;
            }
            sleep((sampleTime / samplesPerBit) * rtos::us);
        };

        //store 1 or 0 in data
        bit++;
        if (highs > (samplesPerBit / 2))
        {
            data |= (1 << (bits - bit));
        }
    }
    rec.update(data);
}