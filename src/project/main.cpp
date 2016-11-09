#include <hwlib.hpp>
#include <rtos.hpp>
#include "drawables/text.hpp"
#include "boundary/oled.hpp"
#include "controllers/oled_controller.hpp"

class Main : rtos::task<>
{
  private:
    oled_controller &oled_contol;
    void main()
    {
        hwlib::cout << "started main controller\n";
        while (1)
        {
            text t;
            oled_contol.add(&t);
            sleep(1 * rtos::s);
        }
    };

  public:
    Main(oled_controller &oled_contol) : 
      task((char *)"Maintask"), 
      oled_contol(oled_contol)
    {};
};

int main()
{
    WDT->WDT_MR = WDT_MR_WDDIS;
    hwlib::wait_ms(500);

    oled oled_screen;

    oled_controller oled_contol(oled_screen);
    Main m(oled_contol);

    rtos::run();
    hwlib::cout << "written";
    return 0;
}