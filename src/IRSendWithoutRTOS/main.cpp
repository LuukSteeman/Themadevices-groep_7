#include "hwlib.hpp"
#include "IRSend.hpp"
#include "IRMessage.hpp"

int main()
{
    // kill the watchdog
    WDT->WDT_MR = WDT_MR_WDDIS;

    // wait for the PC console to start
    hwlib::wait_ms(5000);
    auto sender = IRSend();
    sender.send(IRMessage(0b11111,0b11111));
    return 0;
}