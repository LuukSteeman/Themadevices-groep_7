/// @file
/// NULL_IR_RECEIVER
/// TODO FAIL AFTER 4MS
#include "IRReceiver.hpp"
#include "IRMessage.hpp"

const int pollTimeout = 200;
const int bits = 16;
const int samplesPerBit = 16;
const int sampleTime = 2390;
const int failTimeout = 4000;

void IRReceiver::detect()
{
    auto ir_pin = hwlib::target::pin_in(hwlib::target::pins::d3);
    unsigned short data = 0;
    int bit = 0;
    int highs = 0;
    int waits = 0;
    bool fail = false;
    while (bit != bits && !fail)
    {
        while (ir_pin.get())
        {
            sleep(pollTimeout * rtos::us);
        }

        for (int i = 0; i < samplesPerBit; i++)
        {
            if (!ir_pin.get())
            {
                highs++;
            }
            sleep((sampleTime / samplesPerBit) * rtos::us);
        };
        bit++;
        if (highs > (samplesPerBit / 2))
        {
            data |= (1 << (bits - bit));
        }
        highs = 0;
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