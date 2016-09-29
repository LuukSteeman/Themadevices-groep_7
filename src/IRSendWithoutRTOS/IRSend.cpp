#include "IRSend.hpp"

bool getBit2(int position, short data)
{
    return (data >> (15 - position)) & 1;
}

IRSend::IRSend()
{
    ir = hwlib::target::d2_36kHz();
}

void IRSend::sendBit(bool bit)
{
    ir.set(true);
    hwlib::wait_us((bit ? 1600 : 800));
    ir.set(false);
    hwlib::wait_us((bit ? 800 : 1600));
};

// void IRSend::main()
// {
//     // auto trigger = hwlib::target::pin_out(hwlib::target::pins::d3);
//     // trigger.set(0);
//     while (true)
//     {
//         auto m = messages.read();
//         short data = m.encode();
//         // trigger.set(1);
//         // hwlib::wait_us(10);
//         // trigger.set(0);
//         for (int i = 0; i < 16; i++)
//         {
//             // hwlib::cout << "Get Bit " << i << " returns: "<< getBit2(i, data) << "\n";
//             sendBit(getBit2(i, data));
//         }
//     }
// };

void IRSend::send(IRMessage m)
{
    auto trigger = hwlib::target::pin_out(hwlib::target::pins::d3);
    short data = m.encode();
    trigger.set(1);
    hwlib::wait_us(10);
    trigger.set(0);
    for (int i = 0; i < 16; i++)
    {
        sendBit(getBit2(i, data));
    }
};