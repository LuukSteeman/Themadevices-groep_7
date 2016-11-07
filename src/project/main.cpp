#include <hwlib.hpp>
#include "controllers/oled_controller.hpp"
#include "drawables/text.hpp"

int main()
{
    WDT->WDT_MR = WDT_MR_WDDIS;
    hwlib::wait_ms(500);

    oled_controller oled;
    oled.init();

    text t(&window1, "Hi");
    t.draw();

    // auto pinin = hwlib::target::pin_in(hwlib::target::pins::d3);
    // auto pinout = hwlib::target::pin_out(hwlib::target::pins::d2);
    // pinout.set(1);
    // hwlib::cout << pinin.get()<<"\n";
}