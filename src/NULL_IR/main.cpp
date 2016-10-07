#include "hwlib.hpp"
#include "rtos.hpp"
#include "IRReceiver.hpp"
int main()
{
    WDT->WDT_MR = WDT_MR_WDDIS;

    hwlib::wait_ms(500);
    auto x = IRReceiver();
    rtos::run();
    return 0;
}