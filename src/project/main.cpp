#include <hwlib.hpp>
#include <rtos.hpp>
#include "drawables/text.hpp"
#include "boundary/oled.hpp"
#include "controllers/oled_controller.hpp"

class Main : rtos::task<> {
private:
    oled_controller & oled_control;
    oled & oled_screen;


    void main() {
        int i = 0; 
        text s((char *)i, 1);
        text t((char *)"2", 2);
        text u((char *)"3", 3);

        oled_control.add(&s);
        oled_control.add(&t);
        oled_control.add(&u);


        hwlib::cout << "started main controller\n";
        while (1) {

            i++;
            s.update((char*) i);

            oled_control.add(&s);
            oled_control.add(&t);
            oled_control.add(&u);

            sleep(1 * rtos::s);
            oled_control.flush();

        }
    };

public:
    Main(oled_controller & oled_control, oled & oled_screen) : 
        task((char *)"Maintask"), 
        oled_control(oled_control),
        oled_screen(oled_screen)
    {};
};



int main()
{
    WDT->WDT_MR = WDT_MR_WDDIS;
    hwlib::wait_ms(500);

    oled oled_screen = oled();

    oled_controller oled_control(oled_screen);
    Main m(oled_control, oled_screen);

    Player player;
    oled_controller oled_control(player);
    rtos::run();
    hwlib::cout << "Written";
    return 0;
}