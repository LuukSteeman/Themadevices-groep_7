#include <hwlib.hpp>
#include "boundary/idJumper.hpp"
int main()
{
    WDT->WDT_MR = WDT_MR_WDDIS;
    hwlib::wait_ms(500);
    auto id = idJumper::getID();
    hwlib::cout << "ID: " << id << "\n";
    // auto pinin = hwlib::target::pin_in(hwlib::target::pins::d3);
    // auto pinout = hwlib::target::pin_out(hwlib::target::pins::d2);
    // pinout.set(1);
    // hwlib::cout << pinin.get()<<"\n";
}