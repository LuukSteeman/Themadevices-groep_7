#include "IRSend.hpp"

bool getBit2(int position, short data)
{
    return (data >> (15 - position)) & 1;
}

IRSend::IRSend(char * name):
task(name),
messages(this, "IR Message Channel")
{
    ir = hwlib::target::d2_36kHz();
}

void IRSend::sendBit(bool bit)
{
    // hwlib::cout << "sendBit called with: " << bit << "\n";
    ir.set(true);
    // sleep((bit ? 1600 : 800) * rtos::us);
    hwlib::wait_us((bit ? 1600 : 800));
    ir.set(false);
    // sleep((bit ? 800 : 1600) * rtos::us);
    hwlib::wait_us((bit ? 800 : 1600));

    // if(bit){
    //     ir.set(true);
    //     sleep(1600 *  rtos::us);
    //     ir.set(false);
    //     sleep(800 * rtos::us);
    // }else{
    //     ir.set(true);
    //     sleep(800 *  rtos::us);
    //     ir.set(false);
    //     sleep(1600 * rtos::us);
    // }
};

void IRSend::main()
{
    // auto trigger = hwlib::target::pin_out(hwlib::target::pins::d3);
    // trigger.set(0);
    while (true)
    {
        auto m = messages.read();
        short data = m.encode();
        // trigger.set(1);
        // hwlib::wait_us(10);
        // trigger.set(0);
        for (int i = 0; i < 16; i++)
        {
            // hwlib::cout << "Get Bit " << i << " returns: "<< getBit2(i, data) << "\n";
            sendBit(getBit2(i, data));
        }
    }
};

void IRSend::add(IRMessage m)
{
    messages.write(m);
};