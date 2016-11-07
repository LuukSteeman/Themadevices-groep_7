#include <hwlib.hpp>
#include "IRMessage.hpp"
#include "transmitterctrl.hpp"
#include "IRMessage.hpp"
#include "Transmitter.hpp"
#include <rtos.hpp>

class Maintask : public rtos::task<>
{
private:
    Transmitterctrl & transctrl;
    IRMessage msg;
    void main()
    {
        transctrl.add(msg);
    }
public:
    Maintask(Transmitterctrl & transctrl, IRMessage msg) :
    transctrl(transctrl),
    msg(msg)
    {}
};

int main()
{
    WDT->WDT_MR = WDT_MR_WDDIS;
    hwlib::wait_ms(500);

    Transmitter trans;
    Transmitterctrl transctrl((char *) "Transmittercontroller and task", trans);
    IRMessage message(10,5);
    Maintask main(transctrl, message);
    rtos::run();
}