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
            sleep(pollTimeout);
            waits++;
            if (waits > maxWaits) // if fail timeout is reached fail
            {
                // hwlib::cout << "Fail";
                return;
            }
        }
        //sample the pin x times and calculate if it was a 1 or 0
        int highs = 0;
        for (int i = 0; i < samplesPerBit; i++)
        {
            if (!rec.get())
            {
                highs++;
            }
            sleep(sampleSleepTime);
        };

        //store 1 or 0 in data
        bit++;
        if (highs > (samplesPerBit / 2))
        {
            data |= (1 << (bits - bit));
        }
    }
    // hwlib::cout << data; //magicekrererererer cout dont touch
    MessageLogic m(data);
    hwlib::cout << "error data " << data << "\n";
    if (!m.getError())
    {
        rec.update(m);
    }
    else
    {
        // hwlib::cout << "error " << hwlib::boolalpha << (bool)(m.getError() & MessageLogic::CHECKSUMERROR) << " "
        // << hwlib::boolalpha << (bool)(m.getError() & MessageLogic::STARTBITERROR) << "\n";
    }
}