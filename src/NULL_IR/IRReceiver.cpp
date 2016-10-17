/// @file
/// NULL_IR_RECEIVER
/// TODO FAIL AFTER 4MS
#include "IRReceiver.hpp"
#include "IRMessage.hpp"
#include "bitTools.hpp"

const int pollTimeout = 200;
const int bits = 16;
const int samplesPerBit = 16;
const int sampleTime = 2390;
// const int failTimeout = 4000000;

void IRReceiver::detect()
{
    auto ir_pin = hwlib::target::pin_in(hwlib::target::pins::d3);
    
    
    auto listening = hwlib::target::pin_out(hwlib::target::pins::d53);
    listening.set(ir_pin.get());
    auto sleeping = hwlib::target::pin_out(hwlib::target::pins::d52);
    sleeping.set(0);
    auto sampling = hwlib::target::pin_out(hwlib::target::pins::d51);
    sampling.set(0);
    auto bitOut = hwlib::target::pin_out(hwlib::target::pins::d50);
    bitOut.set(0);
    auto bitOutClock = hwlib::target::pin_out(hwlib::target::pins::d49);
    bitOutClock.set(0);

    unsigned short data = 0;
    int bit = 0;
    int highs = 0;
    int waits = 0;
    while (bit != bits)
    {
        listening.set(1);
        sleeping.set(1);
        while (ir_pin.get())
        {
            sleep(pollTimeout * rtos::us);
            waits++;
            // if ((failTimeout / pollTimeout) > waits)
            // {
            //     return;
            // }
        }
        sleeping.set(0);

        sampling.set(1);
        for (int i = 0; i < samplesPerBit; i++)
        {
            if (!ir_pin.get())
            {
                highs++;
            }
            sleep((sampleTime / samplesPerBit) * rtos::us);
        };
        sampling.set(0);
        bitOutClock.set(1);
        if (highs > (samplesPerBit / 2))
        {
            bitOut.set(1);
            data |= (1 << (bits - bit));
        }
        bitOut.set(0);
        bitOutClock.set(0);
        bit++;
        highs = 0;
        listening.set(0);
    }
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