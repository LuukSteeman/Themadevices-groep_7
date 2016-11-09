#include <hwlib.hpp>
#include <rtos.hpp>
#include "drawables/text.hpp"
#include "boundary/oled.hpp"
#include "controllers/oled_controller.hpp"

class Main : rtos::task<> {
private:
    oled_controller &oled_contol;
    oled &oled_screen;

    void main() {
        hwlib::cout << "started main controller\n";
        while (1) {

            oled_screen.flush();

            sleep(1 * rtos::s);
        }
    };

public:
    Main(oled_controller &oled_contol, oled &oled_screen) : 
        task((char *)"Maintask"), 
        oled_contol(oled_contol),
        oled_screen(oled_screen)
    {};
};



int main()
{
    WDT->WDT_MR = WDT_MR_WDDIS;
    hwlib::wait_ms(500);

    oled oled_screen = oled();

    oled_controller oled_contol(oled_screen);
    Main m(oled_contol, oled_screen);

    text s((char *)"Text 1", 1);
    text t((char *)"Text 2", 2);
    text u((char *)"Text 3", 3);
    oled_contol.add(&s);
    oled_contol.add(&t);
    oled_contol.add(&u);

    rtos::run();
    hwlib::cout << "Written";
    return 0;
}