#include <hwlib.hpp>
#include "boundary/idJumper.hpp"
int main()
{
    WDT->WDT_MR = WDT_MR_WDDIS;
    hwlib::wait_ms(500);
    auto id = idJumper::getID();
    hwlib::cout << "ID: " << id << "\n";
}