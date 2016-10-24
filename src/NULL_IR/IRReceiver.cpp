/// @file
/// NULL_IR_RECEIVER
/// TODO FAIL AFTER 4MS
#include "IRReceiver.hpp"
#include "IRMessage.hpp"

const int pollTimeout = 200;
const int bits = 16;
const int samplesPerBit = 8;
const int sampleTime = 2300;
const int failTimeout = 40000;

void IRReceiver::detect()
{
    //create listening pin
    auto ir_pin = hwlib::target::pin_in(hwlib::target::pins::d3);

    //create data short and bit counter
    unsigned short data = 0;
    int bit = 0;
    while (bit != bits) //while amount of bits is not reached
    {
        int waits = 0; // hold amount of waits
        while (ir_pin.get()) // wait as long as ir pin is not low
        {
            sleep(pollTimeout * rtos::us);
            waits++;
            if ((failTimeout / pollTimeout) > waits) // if fail timeout is reached fail
            {
                // return;
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
        if (highs >= (samplesPerBit / 2))
        {
            data |= (1 << (bits - bit));
        }
        bit++;
        // hwlib::cout << highs << "\n";
    }
    hwlib::cout << "Received " << data << "\n";
    if (im.decode(data))
    {
        hwlib::cout << "Id: " << im.getId() << " data: " << im.getData() << "\n";
    }
    else
    {
        hwlib::cout << "Decode fail, startbit: " << (im.getError() & IRMessage::STARTBITERROR) << " checksumError: " << (im.getError() & IRMessage::CHECKSUMERROR) << "\n";
    }
    data = 0;
    bit = 0;
}

void IRReceiver::main()
{
    for (;;)
    {
        detect();
    }
}