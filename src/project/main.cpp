#include <hwlib.hpp>
#include "IRMessage.hpp"
#include "transmitterctrl.hpp"
#include "IRMessage.hpp"
#include "transmitter.hpp"
#include <rtos.hpp>

class Maintask : public rtos::task<>
{
private:
    transmitterctrl & transctrl;
    IRMessage msg;
    void main()
    {
        transctrl.add(msg);
    }
public:
    Maintask(transmitterctrl & transctrl, IRMessage msg) :
    transctrl(transctrl),
    msg(msg)
    {}
};

int main()
{
    WDT->WDT_MR = WDT_MR_WDDIS;
    hwlib::wait_ms(500);

    transmitter trans;
    transmitterctrl transctrl((char *) "Transmittercontroller and task", trans);
    IRMessage message(10,5);
    Maintask main(transctrl, message);
    rtos::run();
}