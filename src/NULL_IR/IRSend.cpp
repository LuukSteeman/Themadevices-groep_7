#include "IRSend.hpp"
#include "bitTools.hpp"

IRSend::IRSend(char *name) : task(name),
                             messages(this, "IR Message Channel")
{
    ir = hwlib::target::d2_36kHz();
}

void IRSend::sendBit(bool bit)
{
    ir.set(true);
    sleep((bit ? 1600 : 800) * rtos::us);
    // hwlib::wait_us((bit ? 1600 : 800));
    ir.set(false);
    sleep((bit ? 800 : 1600) * rtos::us);
    // hwlib::wait_us((bit ? 800 : 1600));
};

void IRSend::main()
{
    auto sending = hwlib::target::pin_out(hwlib::target::pins::d48);
    auto bit = hwlib::target::pin_out(hwlib::target::pins::d47);
    auto bitclock = hwlib::target::pin_out(hwlib::target::pins::d46);
    while (true)
    {
        auto m = messages.read();
        short data = m.encode();
        hwlib::wait_us(1); // It's magic but it fixes issue #1
        sending.set(1);
        for (int ii = 0; ii < 2; ii++)
        {
            for (int i = 0; i < 16; i++)
            {
                bitclock.set(1);
                sendBit(getBit(i, data));
                bit.set(getBit(i, data));
                bitclock.set(0);
            }
            if (ii == 0)
            {
                sleep(3 * rtos::ms);
            }
        }
        sending.set(0);
    }
};

void IRSend::add(IRMessage m)
{
    messages.write(m);
};