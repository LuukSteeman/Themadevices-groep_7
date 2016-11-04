#include <hwlib.hpp>
#include "interfaces/keypadListener.hpp"
#include "controllers/keypadHandler.hpp"
#include "boundary/keypad.hpp"
#include <rtos.hpp>

class x : public KeypadListener
{
  private:
    void keyPressed(char key)
    {
        hwlib::cout << key << "\n";
    };
};

int main()
{
    WDT->WDT_MR = WDT_MR_WDDIS;
    hwlib::wait_ms(500);

    x X;
    Keypad k;
    k.addKeypadListener(&X);
    KeypadHandler kh(k);
    rtos::run();
}